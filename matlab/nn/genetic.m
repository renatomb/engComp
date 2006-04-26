function retorno=genetic(limites,qi,tc,tm,f,qint,tol,graf)
%Use: genetic([Xmin Xmax],qi,tc,tm,f,qint,tol,g)
%[Xmin Xmax] = Espaco de busca
%qi = Quantidade de individuos
%tc = Tamanho do cromossomo em bits
%tm = Taxa de mutacao em %
%f = Funcao em funcao de X (deve ser informado como string)
%qint = Quantidade de iteracoes
%tol = Tolerancia
%g = 0 para nao plotar grafico e 1 para plotar grafico.
%
%
%(C) 2003 - RMB
try
    if (graf == 1)
        graf=1;
    else
        graf=0;
    end
catch
    graf=0;
end
v_min_ant=0;
if (ischar(f) == 0)
    disp('Erro, voce devera informar a funcao como string.');
    disp('Utilize help genetic para maiores informacoes.');
    break;
end    
disp(['O espaco de busca (' num2str(limites(1)) ' a ' num2str(limites(2)) ') foi subdividido em ' num2str(2^tc) ' individuos.']);
disp(['Em cada geracao sera trabalhado com ' num2str(qi) ' individuos e uma taxa de mutacao de ' num2str(tm) '%.']);
for itera=1:qint
    for con=1:qi
        if (itera == 1)
            for cnt=1:tc
                crom(con,cnt)=num2str(round(rand(1)));
            end
        end
        crint(con)=bin2dec(crom(con,:));
        eixo(con)=limites(1)+(((limites(2)-limites(1))*crint(con))/(2^tc-1));
        x=eixo(con);
        val_funcao(con)=eval(f);
    end
%    disp('Cromossomos:');disp(crom);
%    disp('Posicao na funcao:');disp(val_funcao);
    [val_min,pos_min]=min(val_funcao);
    x_min=eixo(pos_min);
    novapop(1,:)=crom(pos_min,:);
    crom=crom([1:pos_min-1 pos_min+1:qi],:);
    val_funcao=val_funcao(:,[1:pos_min-1 pos_min+1:qi]);
    eixo=eixo(:,[1:pos_min-1 pos_min+1:qi]);
    d=(1/qi)*sum((eixo(:)-x_min)'*(eixo(:)-x_min));
    if (graf == 1)
        x_espaco=linspace(limites(1),limites(2),1000);
        for t=1:1000
            x=x_espaco(t);
            y_espaco(t)=eval(f);
        end
        plot(x_espaco,y_espaco);hold on;
        plot(eixo,val_funcao,'+g');
        plot(x_min,val_min,'+r');hold off;
        pause(0.0001);
    end
    if (v_min_ant ~= val_min)
        disp(['Posicao do minimo: ' num2str(x_min) ' (' num2str(val_min) ') VD: ' num2str(d)]);
        v_min_ant=val_min;
    end
    if (d<tol)
        disp(['Atingida a tolerancia especificada em ' num2str(itera) ' iteracoes.' ]);
        break;
    end
    val_funcao=1./((val_funcao-min(val_funcao))+1);
    for ctd=1:qi-1
        sorteio=rand(1)*sum(val_funcao);
        p=1;
        soma=val_funcao(p);
        while (sorteio>soma)
            p=p+1;
            soma=soma+val_funcao(p);
        end
        p_cross=0;
        while(p_cross==0 | p_cross==tc) 
            p_cross=round(rand(1)*tc);
        end
        filho_do_crossover=round(rand(1));
        if (filho_do_crossover)
            novapop(1+ctd,:)=[novapop(1,1:p_cross) crom(p,p_cross+1:tc)];
        else
            novapop(1+ctd,:)=[crom(p,1:p_cross) novapop(1,p_cross+1:tc)];
        end
        if (tm >= rand(1)*100)
            p_muta=round(rand(1)*(tc-1))+1;
            if (novapop(1+ctd,p_muta) == '0')
                novapop(1+ctd,p_muta)='1';
            else
                novapop(1+ctd,p_muta)='0';
            end
        end
    end
    crom=novapop;
end
retorno=x_min;