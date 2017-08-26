#include "complexo.h"

// Obtêm a parte real de um número compexo.
double getR(complexo x);

// Obtêm a parte imaginária de um número compexo.
double getI(complexo x);

// Implementação das funções para calculo do complexo (modo retangular)
complexo set(double x, double y)
{
	complexo z;
	z.r = x;
	z.i = y;
	return z;
}

double getR(complexo x)
{ 
	return x.r;
}

double getI(complexo x)
{ 
	return x.i;
}  

complexo add(complexo x, complexo y)
{
	complexo z;
	z.r = x.r + y.r;
	z.i = x.i + y.i;
	return (z);
}

complexo sub(complexo x, complexo y)
{
	complexo z;
	z.r = x.r - y.r;
	z.i = x.i - y.i;
	return (z);         
}

complexo mul(complexo x, complexo y)
{
	complexo z;
	z.r = x.r * y.r - x.i * y.i;
	z.i = x.r * y.i + y.r * x.i;	
	return (z);
}

complexo divi(complexo x, complexo y)
{
	complexo z;
	double k = pow(y.r,2) + pow(y.i,2); // denominador
	z.r = (x.r * y.r + x.i * y.i)/k;
	z.i = (x.i * y.r - y.i * x.r)/k;
	return (z);
}

complexo simetrico(complexo x)
{ 
	complexo z;
	z.r = -1*x.r;
	z.i = -1*x.i;
	return (z);
}  

complexo conjugado(complexo x)
{ 
	complexo z;
	z.r = x.r;
	z.i = -1*x.i;
	return (z);
}  

complexo inverso(complexo x)
{ 
	complexo z;
	double k = pow(x.r,2) + pow(x.i,2); // denominador
	if (x.r!=0) 
		z.r = x.r/k;
	if (x.i!=0)
		z.i = (-1*x.i)/k;
	return (z);
} 

double modulo(complexo x)
{ 
	double z;
	z = sqrt(pow(x.r,2)+pow(x.i,2));
	return (z);
} 

complexo potencia(complexo x, int pot)
{ 
	int i;
	complexo z;
	z = x;
	for(i=1; i<pot; i++)
	{
		z = mul(z, x);
	}
	return (z);
} 

// Função que devolve o complexo, na forma retangular em modo texto 
char * notation(complexo x)
{
	static char s[30];

	if (getR(x) !=0 && getI(x)>0) {sprintf(s, "%.2g + %.2gi", getR(x), getI(x));}     	
	if (getR(x) !=0 && getI(x)<0) {sprintf(s, "%.2g - %.2gi", getR(x), -1*getI(x));} 	
	if (getR(x) ==0 && getI(x)==0) {sprintf(s, "%.2g ", getR(x));}

	if (getR(x) !=0 && getI(x)==1) {sprintf(s, "%.2g + i", getR(x));}
	if (getR(x) !=0 && getI(x)==-1) {sprintf(s, "%.2g - i", getR(x));}

	if (getR(x) ==0 && getI(x)>0) {sprintf(s, "%.2gi", getI(x));}
	if (getR(x) ==0 && getI(x)<0) {sprintf(s, "-%.2gi", -1*getI(x));}

	if (getR(x) ==0 && getI(x)==1) {sprintf(s, "i");}
	if (getR(x) ==0 && getI(x)==-1) {sprintf(s, "-i");}

	if (getR(x) !=0 && getI(x)==0) {sprintf(s, "%.2g", getR(x));}   

	return s;
}
