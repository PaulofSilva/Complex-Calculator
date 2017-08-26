//---------------------------------------------------------------------------  
//-- ULP - Programação I
//-- Engenharia Informatica 1º ano
//-- Arquivo : main.c | complexo.c | complexo.h | calculadora.c
//-- Função : Manipulação de numeros complexos.
//-- Autor : Paulo Fonseca da Silva  
//-- paulosilva@biglevel.com  nº a21000662
//--------------------------------------------------------------------------- 

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "complexo.h"

void menu1()
{
	system("cls");
	printf("\n\n\t\t***** ULP - PROJECTO DE PROGRAMACAO I *****");  
	printf("\n\n\t\t*    N U M E R O S   C O M P L E X O S    *"); 
	printf("\n\n\t\t    \t1 - Modo calculadora.          "); 
	printf("\n  \t\t    \t2 - Teste de conhecimentos.    "); 
	printf("\n\n  \t\t    \t3 - AJUDA !    "); 
	printf("\n\n  \t\t    \t0 - SAIR.    "); 	
	printf("\n\n             \tDIGITE SUA OPCAO: ");     
}

void menu2(int op)
{ 
	printf("\n          \t1 - Soma.              \t2 - Subtracao.");  
	printf("\n          \t3 - Multiplicacao.     \t4 - Divisao.");  
	printf("\n          \t5 - Simetrico.         \t6 - Conjugado.");  
	printf("\n          \t7 - Inverso.           \t8 - Potenciacao.");  
	printf("\n\n           \t9 - Limpar visor.");  
	if (op == 1) // valida o tipo de operação escolhida 1- calculadora 2- teste de conhecimento, neste ultimo esta opção não surge
	{
		printf("\n\n          \t0 - Retroceder. ");	
	}	
	printf("\n  \t\t___________________________________________");
	printf("\n\n           \tDIGITE SUA OPCAO: ");    
}

/* função alimenta o visor lê do ficheiro resultados.txt,
tambem foi aproveitada para ajuda op=3 do menu1*/
void Imprimir(int op)
{
	FILE *leitura; char linha[80];

	if(op==1) // ler o ficheiro de resultados 
		leitura = fopen( "resultados.txt", "r" );

	if(op==3) // ler o ficheiro de ajuda 
		leitura = fopen( "ajuda.txt", "r" );  

	if( leitura == NULL ) // valida  
		printf("ERRO: não consigo abrir o ficheiro resultados.txt\n");

	while(fgets(linha,80,leitura)!=NULL)
	{                                                                        
		printf("\t\t %s", linha);
	}
	// fecha o canal de leitura
	fclose(leitura); 
}


int main()
{
	int opcao=-1, n=9;

	while(opcao != 0)
	{
		menu1();
		scanf("%d",&opcao);

		switch (opcao)
		{
		case 1:
			calculadora(opcao, n);
			break; 

		case 2:
			printf("\n\t\t Qual o numero de perguntas ?.: ");
			scanf("%d",&n);         
			calculadora(opcao, n);
			break;

		case 3:
			system("cls");
			Imprimir(opcao);
			system("pause");
			break;

		case 0:
			break;

		default:
			printf("Por favor escolha uma das opções do Menu!\n\n");
			system("PAUSE");            		
		}
	}
	printf("\n\n\t\tO B R I G A D O..!\n");
	system("pause");
	return 0;
}
