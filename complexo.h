// Definição da extrutura de dados
typedef struct{
	double r; // Parte Real
	double i; // Parte imaginária
}complexo;

// estrutura para guardar resultados na opção de teste de conhecimento
typedef struct{
	char resposta[80];
	int pontos;
}resultado;

// Criar um número complexo
complexo set(double x, double y);

// Soma dois números complexos
complexo add(complexo x, complexo y);

// Subtrai dois números complexos
complexo sub(complexo x, complexo y);

// Multiplica dois números complexos
complexo mul(complexo x, complexo y);

// Divide dois números complexos
complexo divi(complexo x, complexo y);

// Calcula o simetrico do complexo
complexo simetrico(complexo x);

// Calcula o conjugado do complexo
complexo conjugado(complexo x);

// Calcula o inverso do complexo
complexo inverso(complexo x);

// Calcula o modulo do complexo 
double modulo(complexo x);

//Potenciação de um numero complexo 
complexo potencia(complexo x, int pot);

// Retorna o número complexo em string
char * notation(complexo x);

// Calculadora
void calculadora(int op, int n);
