#include <iostream.h>
#include <conio.h>
#include <iomanip.h>

float c_k(float tc);float c_f(float tc);float c_r(float tc);
float k_c(float tk);float k_f(float tk);float k_r(float tk);
float f_c(float tf);float f_k(float tf);float f_r(float tf);
float r_c(float tr);float r_k(float tr);float r_f(float tr);
float limites(float limS,float limI,float passo);

void main()
{
	float li,ls,p,c,k,f,r,i;
	int op;
	cout<<"\n ************************************************";
	cout<<"\n **ESCALAS TERMOMETRICAS - Converso de Unidades**";
	cout<<"\n ************************************************";
	cout<<"\n ** 1 - Celsius                                **";
	cout<<"\n ** 2 - Kelvin                                 **";
	cout<<"\n ** 3 - Fahrenheit                             **";
	cout<<"\n ** 4 - Rankine                                **";
	cout<<"\n ************************************************";
	cout<<"\nEscolha uma opcao: ";
	cin>>op;
	cout<<"\nInforme o limite superior:";cin>>li;
	cout<<"\nInforme o limite inferior:";cin>>ls;
	cout<<"\nInforme o passo .........:";cin>>p;
	switch(op){
	case 1:
		for(i=ls;i<=li;i=i+p)
		{
			f=c_f(i);
			k=c_k(i);
			r=c_r(i);
			cout<<"\n"<<i<<"ºC"<<"= "<<c_k(i)<<"K"<<"= "<<c_f(i)<<"ºF"<<"= "<<c_r(i)<<"ºR";
		}
		break;
	case 2:
		for (i=ls;i<=li;i=i+p)
		{
		 f=k_f(i);
		 c=k_c(i);
		 r=k_r(i);
		 cout<<"\n"<<i<<"K"<<"= "<<k_f(i)<<"ºF"<<"= "<<k_c(i)<<"ºC"<<"= "<<k_r(i)<<"ºR";
		}
		break;
	}
}

//FUNCOES DE CONVERSAO

//***********************************CELSIUS
//Celsius p/ Kelvin
float c_k(float tc)
{
	if (tc<-273.15)
	{
	 cout<<"\n Temperatura invalida!!!";
	 cout<<"\n Por favor digite outra opçao.";
	}
	float k;
	k=tc+273.15;
	return k;
}
//Celsius p/ Fahrenheit
float c_f(float tc)
{
	float f;
	f=5/9*tc+32;
	return f;
}
//*----------------------
//Celsius p/ Rankine
float c_r(float tc)
{
	float r;
	r=c_k(k_r(tc));
	return r;
}
//***********************************KELVIN
//*----------------------
//Kelvin p/ Celsius
float k_c(float tk)
{
	float c;
	c=tk-273.15;
	return c;
}
//Kelvin p/ Fahrenheit
float k_f(float tk)
{
	float f;
	f=k_c(c_f(tk));
	return f;
}
//Kelvin p/ Rankine
float k_r(float tk)
{
	float r;
	r=9/5*tk;
	return r;
}
//***********************************FAHRENHEIT
//Fahrenheit p/ Celsius
float f_c(float tf)
{
	float c;
	c=9/5*tf-32;
	return c;
}
//Fahrenheit p/ Kelvin
float f_k(float tf)
{
	float k;
	k=f_c(c_k(tf));
	return k;
}
//*----------------------
//Fahrenheit p/ Rankine
float f_r(float tf)
{
	float r;
	r=f_k(k_r(tf));
	return r;
}
//***********************************RANKINE
//*----------------------
//Rankine p/ Celsius
float r_c(float tr)
{
	float c;
	c=r_k(k_c(tr));
	return c;
}
//*----------------------
//Rankine p/ Kelvin
float r_k(float tr)
{
	float k;
	k=5/9*tr;
	return k;
}
//*----------------------
//Rankine p/ Fahrenheit
float r_f(float tr)
{
	float f;
	f=r_k(k_f(tr));
	return f;
}
//***********************************
