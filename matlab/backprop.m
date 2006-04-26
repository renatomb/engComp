function retorno=backprop(yref);
%RNA BackPropagation, ajuda ao usuario.
%
%Sintaxe backprop(yref);
%Onde:
%
%yref = Valor de referencia

nc_max=2;nn_max=2;nptr_max=1;
nciclos_max=50000;
threshold=-1;
er_max=0.0000000001;
tol=0.0001;
contconv=0;
lim=20;

y(1)=0;
u(1)=1;
k=1;

while(1){
	y(k+1)=planta(y(k),u(k)); %% Saida
	k=k+1; %Epocas
	if(abs(yref-y(k))<=tol)
      contconv=contconv+1;
      if(contconv>=lim)
         break;
      end
	else
		contconv=0;
	end
	[yestp, Jestp]=bkpr(y(k), u(k-1), yestp, Jestp);
	yest(k)=yestp;
	Jest(k)=Jestp;
	u(k)=controlador(yest(k), Jest(k), u(k-1));
end

%%CONTROLADOR
function omega1=controlador(yest, Jest, u)
  omega1=u+((yref-yest)/Jest);
end

%%APLICACAO DA REDE MA PLANTA
function omega2=planta(y, u)
  omega2=(0.4*y-0.6*u);
end

%%IMPLEMENTACAO DO BACKPROPAGATION
function [yestp, Jestp]=bkpr(y, u, yestp, Jestp)
	er_total=0; counter=0; nciclos=0; x1=0; x2=0;

	%%Especificacao da RNA
	nc=2;     %%Total de duas camadas
	nn(1)=2;  %%Camada escondida com dois neuronios
	1nn(2)=1;  %%Camada de saida com um neuronio
	fan(1)=1; %%Funcao de ativacao da primeira camada (linear)
   
   %%Contexto
	nptr=1; %%1 ponto de treinamento
	ptre(1,1)=y; ptre(2,1)=u; ptre(3,1)=threshold; de(1,1)=y;

	for s=1:nptr;
      for r=1:(nn(1)+1)
         ptr(r,s)=ptre(r,s);
      end
      clear r;
      for r=1:nn(nc);
         d(r,s)=de(r,s);
      end
   end
   
   for p=1:nptr;
   	for s=1:(nn(1)+1);
         no(1,s,p)=ptr(s,p);
      end
   end
   
   %% Informacoes de desempenho
	careta='s';
	eta=0.001;
	alfa=0.0;

	%%Inicializacao randomica dos pesos (valores entre -0.5 e 0.5)
   for r=1:nc;
      for s=1:nn[r+1];
         for t=1:(nn[r]+1);
            w(r,s,t)=rand-0.5;
         end
      end
   end
   
   continua_loop=1;
   while (continua_loop)
	   clc;
	   disp('RNA BackPropagation versao 1.1 beta');
	   disp(['Valor de referencia: ', num2str(yref)]);
      
      irparafrente(no);
      x2=calculaerro();
      
      er_total

      etadaptativo(x1, x2);
      if(er_total>er_max)
         retroagir();
      end
      
		x1=x2;
      nciclos++;
      
      if ((er_total<er_max) | (nciclos>nciclos_max))
         continua_loop=0;
      end
   end
   yestp=no(2,1,1);
   Jestp=w(1,1,2);
end

//REDE EVOLUI DA ENTRADA PARA A SAIDA
void irparafrente(long double no[nc_max][nn_max+1][nptr_max]){
  unsigned int s;
  long double nep, net[nc_max][nn_max+1][nptr_max];

  for(unsigned int r=1;r<nc;r++)
    for(s=1;s<=nn[r+1];s++)
      for(unsigned int t=1;t<=nptr;t++)
        net[r][s][t]=0;

  for(unsigned int r=1;r<nc;r++){
    for(unsigned int q=1;q<=nptr;q++)
      for(s=1;s<=nn[r+1];s++)
        for(unsigned int t=1;t<=(nn[r]+1);t++)
          net[r][s][q]=net[r][s][q]+w[r][s][t]*no[r][t][q];

    if(fan[r]==1)
      for(unsigned int q=1;q<=nptr;q++){
        for(s=1;s<=nn[r+1];s++)
          no[r+1][s][q]=net[r][s][q];
        if(r+1<nc)
          no[r+1][s][q]=threshold;
      }

    else if(fan[r]==2)
      for(unsigned int q=1;q<=nptr;q++){
        for(s=1;s<=nn[r+1];s++){
          nep=exp(-net[r][s][q]);
          no[r+1][s][q]=1.0/(1.0+nep);
        }
        if(r+1<nc)
          no[r+1][s][q]=threshold;
      }

    else
      for(unsigned int q=1;q<=nptr;q++){
        for(s=1;s<=nn[r+1];s++){
          nep=exp(-net[r][s][q]);
          no[r+1][s][q]=(1.0-nep)/(1.0+nep);
        }
        if(r+1<nc)
          no[r+1][s][q]=threshold;
      }
  }
}

//CALCULO DO ERRO
long double calculaerro(){
  long double er_p[nn_max+1][nptr_max];

  for(unsigned int q=1;q<=nptr;q++)
    for(unsigned int s=1;s<=nn[nc];s++)
      er_p[s][q]=0.5*pow((d[s][q]-no[nc][s][q]),2.0);

  er_total = 0;
  for(unsigned int q=1;q<=nptr;q++)
    for(unsigned int s=1;s<=nn[nc];s++)
      er_total=er_total+er_p[s][q];

  return er_total;
}

//CALCULA A SOMA DOS PRODUTOS (Delta*W)
void somadeltaw(unsigned int r, long double aux[nn_max+1][nptr_max]){

  for(unsigned int q=1;q<=nptr;q++)
    for(unsigned int s=1;s<=(nn[r]+1);s++)
      sdw[s][q] = 0;

  for(unsigned int q=1;q<=nptr;q++)
    for(unsigned int s=1;s<=(nn[r]+1);s++)
      for(unsigned int t=1;t<=nn[r+1];t++)
        sdw[s][q]=sdw[s][q]+aux[t][q]*w[r][t][s];
}

//INCREMENTA OS PESOS
void incpeso(unsigned int r, long double aux[nn_max+1][nptr_max]){
  long double dwatual[nc_max][nn_max+1][nn_max+1];

  for(unsigned int s=1;s<=nn[r+1];s++)
    for(unsigned int t=1;t<=(nn[r]+1);t++)
      for(unsigned int q=1;q<=nptr;q++){
        dwatual[r][s][t]=eta*aux[s][q]*no[r][t][q];
        w[r][s][t]=w[r][s][t]+(1.0-alfa)*dwatual[r][s][t]+(alfa*dwanterior[r][s][t]);
        dwanterior[r][s][t]=dwatual[r][s][t];
      }
}

//AJUSTE DOS PESOS ATRAVES DA RETROPROPAGACAO DO ERRO
void retroagir(){
  long double aux[nn_max+1][nptr_max];

  for(unsigned int r=1;r<nc;r++)
    for(unsigned int s=1;s<=nn[r+1];s++)
      for(unsigned int t=1;t<=(nn[r]+1);t++)
        dwanterior[r][s][t]=0;

  if(fan[nc-1]==1)
    for(unsigned int q=1;q<=nptr;q++)
      for(unsigned int s=1;s<=nn[nc];s++)
        aux[s][q]=d[s][q]-no[nc][s][q];

  else if(fan[nc-1]==2)
    for(unsigned int q=1;q<=nptr;q++)
      for(unsigned int s=1;s<=nn[nc];s++)
        aux[s][q]=(d[s][q]-no[nc][s][q])*no[nc][s][q]*(1-no[nc][s][q]);

  else
    for(unsigned int q=1;q<=nptr;q++)
      for(unsigned int s=1;s<=nn[nc];s++)
        aux[s][q]=0.5*(d[s][q]-no[nc][s][q])*(1.0-pow(no[nc][s][q],2.0));

  somadeltaw(nc-1,aux);
  incpeso(nc-1,aux);

  for(unsigned int r=nc-2;r>=1;r--){
    if(fan[r]==1)
      for(unsigned int q=1;q<=nptr;q++)
        for(unsigned int s=1;s<=nn[r+1];s++)
          aux[s][q]=sdw[s][q];

    else if(fan[r]==2)
      for(unsigned int q=1;q<=nptr;q++)
        for(unsigned int s=1;s<=nn[r+1];s++)
          aux[s][q]=no[r+1][s][q]*(1-no[r+1][s][q])*sdw[s][q];

    else
      for(unsigned int q=1;q<=nptr;q++)
        for(unsigned int s=1;s<=nn[r+1];s++)
          aux[s][q]=0.5*(1.0-pow(no[r+1][s][q],2.0))*sdw[s][q];

    if(r>1)
      somadeltaw(r, aux);
    incpeso(r, aux);
  }
}

//IMPLEMENTA ETA ADAPTATIVO
void etadaptativo(long double x1, long double x2){
  if(x2<=1.04*x1){
    if(x2>=x1)
      retroagir();
    else{
      retroagir();
      eta=1.05*eta;
    }
  }else
    eta=0.7*eta;
}


nc_max=4;
nn_max=30;
nptr_max=10;
threshold=-1;
er_max=0.000001;
nciclos_max=20000;
if (exist('nc','var') == 0 || exist('fan','var') == 0)
    disp('ERRO: Erro de sintaxe, parametros insuficientes.');
    help backprop
    chk=0;
else
    if (checkup(nc,fan,))
        disp('Programa pricipal inicializado');
    end
end

function chk=checkup(nc,fan,nn,);
chk=1;
if (nc <= 1) %%Verifica se o numero de camadas de nos eh maior do que um;
    disp('ERRO: O numero de camadas de nos deve ser maior do que um!');
    help backprop
    chk=0;
end
if (size(fan,2) ~= nc) %%Verifica se o tamanho da fan eh igual ao numero de camdas;
    disp('ERRO: O numero de funcoes de ativacao do vetor fan deve ser igual ao numero de camadas de nos!');
    help backprop
    chk=0;
end
if (sum(fan > 3) || sum(fan < 1)) %%Verifica se todos os valores da fan estao entre 1 e 3;
    disp('ERRO: Os valores da matriz fan deverao estar entre 1 e 3.');
    help backprop
    chk=0;
end

