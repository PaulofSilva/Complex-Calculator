#include <stdio.h>
#include <string.h> 
#include "complexo.h"

/*Função recebe tipo de operação menu1, complexoZ1, Nome utilizador no caso de teste conhecimentos
total de perguntas e numeros de respostas dadas*/

void visor(int op, complexo Z1, char nome[35], int nPerg, int nResp) 
{
	system("cls");
	printf("\n\n\t\t***** ULP - PROJECTO DE PROGRAMACAO I *****");
	if ( op != 2)                  
		printf("\n  \t\t            C A L C U L A D O R A          ");
	else
	{
		printf("\n  \t\t  T E S T E    C O N H E C I M E N T O S   ");
		printf("\n\n  \t\tBOA SORTE.: %s | pergunta.: %d de %d", nome, nResp, nPerg);	
	}
	printf("\n  \t\t___________________________________________\n");
	if ( op != 2)
		Imprimir(op);   
	printf("\n  \t\t___________________________________________");
	printf("\n                \t\tZ1 = %s",notation(Z1));		
	printf("\n  \t\t___________________________________________");     
}

/* Função para validar a introdução do nemero complexo por parte do utilizador
no caso da divisão, não permite introduzir valor zero, para controlar recebe o nº da operação, divisão = 4 */
complexo validaZ(int nOp)
{
	complexo Z;
	int op = -1;
	float re1, im1;
	char sinal, i; 

	while(op !=0)
	{    
		scanf("%f %c %f %c",&re1, &sinal, &im1, &i);
		if (nOp==4 && ((int)re1==0 || (int)im1==0)) // valida a divisão por zero
		{
			printf("\n \t\tDESCULPE não pode dividir por zero!!!\n");
			printf("\n\n \t\t Digite novamente: ");   
		}
		else
		{

			if (sinal=='-' && (i=='i' || i=='j'))
			{
				im1 = -1*im1;
				Z = set(re1, im1);
				op=0;
			}
			if (sinal=='+' && (i=='i' || i=='j'))
			{
				Z = set(re1, im1);   		
				op=0; 
			} 

			if (sinal!='+' && sinal!='-')
			{
				printf("\n \t\tCARACTER estranho no sinal!!!\n");
				printf("\n\n \t\t Digite novamente: ");
			}  
			if (i!='i' && i!='j')
			{
				printf("\n \t\tCARACTER estranho no imaginario!!!, digite i ou j\n"); 
				printf("\n\n \t\t Digite novamente: ");
			}  
		}   		
	}             
	return Z;
}

void calculadora(int op, int n)
{
	FILE *escrita; 
	int opcao = -1, pot, pontos=0, nPerguntas = n;
	char result[80]="", respUtil[25]="", nome[35]="";
	complexo Z1, Z2, resAdd, resSub, resMul, resDiv, resSime, resConj, resInve, resPot, resUtil;
	resultado *p;
	if ( op == 2) // no caso teste de conhecimentos, cria array e regista o nome
	{
		p = (resultado*) malloc (nPerguntas * sizeof(resultado));  // cria array de estruturas

		// Pedir o nome do jogador
		fflush (stdin);
		printf("\n\t\t Escreva o seu nome: "); 
		gets(nome);  
	}

	printf("\n\n\t\t Inserir o 1 complexo Z1 : ");
	Z1 = validaZ(0); 

	while(opcao != 0)
	{   
		visor(op, Z1, nome, nPerguntas, nPerguntas-n+1); // op=1 calculadora, op=2 Teste de conhecimentos 

		menu2(op); 

		scanf("%d",&opcao);
		switch (opcao) 
		{ 
		case 1: //Soma

			printf("\n\n \t\t Inserir o 2 complexo Z2 : "); 

			Z2 = validaZ(1); 
			resAdd = add(Z1, Z2);

			//Guarda o ficheiro
			if ( op != 2)
			{
				escrita = fopen( "resultados.txt", "a" );
				fprintf( escrita,"Sum -> (%s)",notation(Z1));
				fprintf( escrita," + (%s)",notation(Z2)); 
				fprintf( escrita," = %s \n",notation(resAdd)); 
				fclose(escrita);
			}


			if ( op == 2)
			{
				strcpy(result,notation(Z1)); 
				strcat(result, " + "); 
				strcat(result,notation(Z2)); 
				strcat(result, " = "); 
				strcat(result,notation(resAdd));   

				printf("\n \t\t Inserir a sua resposta: "); 
				resUtil = validaZ(1);
				strcat(result, " ("); 
				strcat(result,notation(resUtil));			
				strcat(result, " )"); 
				strcpy(respUtil,notation(resUtil));	

				if(strcmp(respUtil,notation(resAdd)) == 0)
				{
					strcpy(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 1;                                                           
				}
				else
				{
					strcat(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 0; 
				}
			}
			Z1 = resAdd;           
			break;
		case 2: //Subtração
			printf("\n\n\t\t Inserir o 2 complexo Z2 : "); 
			Z2 = validaZ(2);   

			resSub = sub(Z1, Z2);

			//Guarda o ficheiro
			if ( op != 2)
			{
				escrita = fopen( "resultados.txt", "a" );
				fprintf( escrita,"Sub -> (%s)",notation(Z1));
				fprintf( escrita," - (%s)",notation(Z2)); 
				fprintf( escrita," = %s \n",notation(resSub)); 
				fclose(escrita);
			}


			if ( op == 2)
			{
				strcpy(result,notation(Z1)); 
				strcat(result, " - "); 
				strcat(result,notation(Z2)); 
				strcat(result, " = "); 
				strcat(result,notation(resSub));   

				printf("\n\t\t Inserir a sua resposta: "); 
				//scanf("%f %c %f %c",&re1, &sinal, &im1, &i);
				resUtil = validaZ(2);
				strcat(result, " ("); 
				strcat(result,notation(resUtil));			
				strcat(result, " )"); 
				strcpy(respUtil,notation(resUtil));	

				if(strcmp(respUtil,notation(resSub)) == 0)
				{
					strcpy(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 1;                                                           
				}
				else
				{
					strcat(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 0; 
				}
			}

			Z1 = resSub; 

			break;

		case 3: //Mutiplicação
			printf("\n\n\t\t Inserir o 2 complexo Z2 : "); 
			Z2 = validaZ(3);   

			resMul = mul(Z1, Z2);

			//Guarda o ficheiro
			if ( op != 2)
			{
				escrita = fopen( "resultados.txt", "a" );
				fprintf( escrita,"Mul -> (%s)",notation(Z1));
				fprintf( escrita," x (%s)",notation(Z2)); 
				fprintf( escrita," = %s \n",notation(resMul)); 
				fclose(escrita);
			}


			if ( op == 2)
			{
				strcpy(result,notation(Z1)); 
				strcat(result, " x "); 
				strcat(result,notation(Z2)); 
				strcat(result, " = "); 
				strcat(result,notation(resSub));   

				printf("\n\t\t Inserir a sua resposta: "); 
				//scanf("%f %c %f %c",&re1, &sinal, &im1, &i);
				resUtil = validaZ(3);
				strcat(result, " ("); 
				strcat(result,notation(resUtil));			
				strcat(result, " )"); 
				strcpy(respUtil,notation(resUtil));	

				if(strcmp(respUtil,notation(resMul)) == 0)
				{
					strcpy(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 1;                                                           
				}
				else
				{
					strcat(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 0; 
				}
			}
			Z1 = resMul; 

			break;

		case 4: //Divisão
			printf("\n\n\t\t Inserir o 2 complexo Z2 : "); 
			Z2 = validaZ(4); 

			resDiv = divi(Z1, Z2);

			//Guarda o ficheiro
			if ( op != 2)
			{
				escrita = fopen( "resultados.txt", "a" );
				fprintf( escrita,"Div -> (%s)",notation(Z1));
				fprintf( escrita," / (%s)",notation(Z2)); 
				fprintf( escrita," = %s \n",notation(resDiv)); 
				fclose(escrita);
			}


			if ( op == 2)
			{
				strcpy(result,notation(Z1)); 
				strcat(result, " / "); 
				strcat(result,notation(Z2)); 
				strcat(result, " = "); 
				strcat(result,notation(resDiv));   

				printf("\n\t\t Inserir a sua resposta: "); 
				//scanf("%f %c %f %c",&re1, &sinal, &im1, &i);

				resUtil = validaZ(0);

				strcat(result, " ("); 
				strcat(result,notation(resUtil));			
				strcat(result, " )"); 
				strcpy(respUtil,notation(resUtil));	

				if(strcmp(respUtil,notation(resDiv)) == 0)
				{
					strcpy(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 1;                                                           
				}
				else
				{
					strcat(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 0; 
				}
			}
			Z1 = resDiv; 
			break;

		case 5: // Simetrico
			resSime = simetrico(Z1); 

			//Guarda o ficheiro

			if ( op != 2)
			{
				escrita = fopen( "resultados.txt", "a" );
				fprintf( escrita,"Simetrico -> (%s)",notation(Z1));
				fprintf( escrita," = %s \n",notation(resSime)); 
				fclose(escrita);
			}


			if ( op == 2)
			{
				strcpy(result, "Simetrico -> ");                  
				strcat(result,notation(Z1));  
				strcat(result, " = "); 
				strcat(result,notation(resSime));   

				printf("\n\t\t Inserir a sua resposta: "); 
				//scanf("%f %c %f %c",&re1, &sinal, &im1, &i);

				resUtil = validaZ(5);

				strcat(result, " ("); 
				strcat(result,notation(resUtil));			
				strcat(result, " )"); 
				strcpy(respUtil,notation(resUtil));	

				if(strcmp(respUtil,notation(resSime)) == 0)
				{
					strcpy(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 1;                                                           
				}
				else
				{
					strcat(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 0; 
				}
			}

			Z1 = resSime;         
			break;	

		case 6: // Conjudado
			resConj = conjugado(Z1); 

			//Guarda o ficheiro
			if ( op != 2)
			{
				escrita = fopen( "resultados.txt", "a" );
				fprintf( escrita,"Conjugado -> (%s)",notation(Z1));
				fprintf( escrita," = %s \n",notation(resConj)); 
				fclose(escrita);
			}


			if ( op == 2)
			{
				strcpy(result, "Conjugado -> ");                  
				strcat(result,notation(Z1));  
				strcat(result, " = "); 
				strcat(result,notation(resConj));   

				printf("\n\t\t Inserir a sua resposta: "); 
				//scanf("%f %c %f %c",&re1, &sinal, &im1, &i);

				resUtil = validaZ(6);

				strcat(result, " ("); 
				strcat(result,notation(resUtil));			
				strcat(result, " )"); 
				strcpy(respUtil,notation(resUtil));	

				if(strcmp(respUtil,notation(resConj)) == 0)
				{
					strcpy(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 1;                                                           
				}
				else
				{
					strcat(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 0; 
				}
			}

			Z1 = resConj;         
			break;

		case 7: // Inverso
			resInve = inverso(Z1); 

			//Guarda o ficheiro
			if ( op != 2)
			{
				escrita = fopen( "resultados.txt", "a" );
				fprintf( escrita,"Inverso -> (%s)",notation(Z1));
				fprintf( escrita," = %s \n",notation(resInve)); 
				fclose(escrita);
			}


			if ( op == 2)
			{
				strcpy(result, "Inverso -> ");                  
				strcat(result,notation(Z1));  
				strcat(result, " = "); 
				strcat(result,notation(resInve));   

				printf("\n\t\t Inserir a sua resposta: "); 
				//scanf("%f %c %f %c",&re1, &sinal, &im1, &i);
				resUtil = validaZ(7);

				strcat(result, " ("); 
				strcat(result,notation(resUtil));			
				strcat(result, " )"); 
				strcpy(respUtil,notation(resUtil));	

				if(strcmp(respUtil,notation(resInve)) == 0)
				{
					strcpy(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 1;                                                           
				}
				else
				{
					strcat(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 0; 
				}
			}

			Z1 = resInve;         
			break;

		case 8: // Potenciação
			printf("\n\n\t\t Qual expoente Z1? : "); 
			scanf("%d",&pot); 		
			resPot = potencia(Z1, pot); 
			//printf("\n\t\t potencia -> (%s)",notation(resPot));

			//Guarda o ficheiro
			if ( op != 2)
			{
				escrita = fopen( "resultados.txt", "a" );
				fprintf( escrita,"potencia -> (%s)^%d",notation(Z1), pot);
				fprintf( escrita," = %s \n",notation(resPot)); 
				fclose(escrita);
			}


			if ( op == 2)
			{
				strcpy(result, "Potencia -> ");                  
				strcat(result,notation(Z1));  
				strcat(result, " = "); 
				strcat(result,notation(resPot));   

				printf("\n\t\t Inserir a sua resposta: "); 
				//scanf("%f %c %f %c",&re1, &sinal, &im1, &i);

				resUtil = validaZ(8);

				strcat(result, " ("); 
				strcat(result,notation(resUtil));			
				strcat(result, " )"); 

				strcpy(respUtil,notation(resUtil));	

				if(strcmp(respUtil,notation(resPot)) == 0)
				{
					strcpy(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 1;                                                           
				}
				else
				{
					strcat(p[nPerguntas - n].resposta, result);
					p[nPerguntas - n].pontos = 0; 
				}
			}

			Z1 = resPot;         
			break; 

		case 9: // Limpar o ficheiro
			n++ ;

			escrita = fopen( "resultados.txt", "w" );
			fclose(escrita);

			printf("\n\n\t\t Inserir o 1 complexo Z1 : "); 
			Z1 = validaZ(9);
			break;

		case 0:		
			break; 

		default:
			printf("Por favor escolha uma das opções do Menu!\n\n");
			system("PAUSE");
		} 
		n--;  // decrementa o n até zero numero de perguntas definidas pelo utilizador para teste de conhecimento
		
		if ( op == 2 && n == 0) // Valida e mostra o resultado ao utilizador
		{                 
			printf("\n  \t\t            R E S U L T A D O                ");
			printf("\n  \t\t___________________________________________\n");
			for ( n = 0; n < nPerguntas; n++)
			{
				printf("\n\t\t %d ) %s\n",n+1, p[n].resposta);
				pontos += p[n].pontos;
			}
			free(p);
			printf("\n\t\t-> Numero de perguntas .: %d \n\t\t-> Respostas certas ....: %d",
				nPerguntas , pontos);

			printf("\n  \t\t___________________________________________\n"); 
			if ( ((float)pontos/(float)nPerguntas)*100 >= 50)
			{
				printf("\n\t\tPARABENS %s -> Media final.: %.1f \n\n", nome, ((float)pontos/(float)nPerguntas)*100);
			}
			else
			{
				printf("\n\t\t\t    VOLTE A TENTAR ...\n");                
			}
			opcao = 0; // retrocede ao menu1
			system("pause");
		}  	
	}
}
 
