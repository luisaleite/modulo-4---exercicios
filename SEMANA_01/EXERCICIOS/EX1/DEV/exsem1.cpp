#include <iostream>
#include <cstring>

using namespace std;

// 1 -  Faca uma funcao que recebe uma certa medida e ajusta ela percentualmente
// entre dois valores minimo e maximo e retorna esse valor

/*1. Implemente a fun��o 'converteSensor' que receber� 3 argumentos: uma medida,
um valor m�nimo e um valor m�ximo. A fun��o retornar� o valor percentual da
medida (0 a 100) em fun��o do intervalo entre os valores m�nimo e m�ximo.*/

int converteSensor (int medida, int maximo, int minimo)
{
	int intervalo = maximo - minimo;
	medida = medida - minimo;

	float porcentagem = float(medida) / intervalo;

	return porcentagem * 100;
}



// 2 - Faca uma funcao que simule a leitura de um sensor lendo o
// valor do teclado ao final a funcao retorna este valor

/*2. Implemente a fun��o 'leituraSensor' que n�o receber� argumentos.
 Esta fun��o tem por objetivo simular a leitura de sensores
 (neste caso, sensores de dist�ncia). A fun��o solicita e retorna
 um valor inteiro, entre o intervalo de m�nimo e m�ximo (ver item 1),
  digitado pelo usu�rio (via teclado).*/

int leituraSensor ()
{
	int valorInteiro = 0;
	cout << "Digite o valor que foi mostrada no sensor" << endl;
	cin >> valorInteiro;
	return valorInteiro;
}



// 3 - Faca uma funcao que armazena uma medida inteira qualquer
// em um vetor fornecido. Note que como C nao possui vetores
// nativos da linguagem, lembre-se que você precisa passar o
// valor maximo do vetor assim como a ultima posicao preenchida
// Evite tambem que, por acidente, um valor seja escrito em
// uma area de memoria fora do vetor

/*3. Implemente a fun��o 'armazenaVetor' que receber� 4 argumentos:
o ponteiro do vetor que receber� a medida, o tamanho do vetor,
a posi��o atual para armazenamento e a medida para ser armazenada no vetor.
A fun��o deve armazenar a medida no vetor, segundo posi��o indicada
(posi��o atual) e retornar a pr�xima posi��o para armazenamento futuro.*/

int armazenaVetor(int* ponteiroVetor, int tamanhoVetor, int posicaoVetor, int medidaVetor)
{
	if (posicaoVetor < tamanhoVetor)
	{
		ponteiroVetor[posicaoVetor] = medidaVetor;
		return posicaoVetor + 1;
	}
}



// 4 - Faca uma funcao que recebe um vetor com 4 posicoes que contem
// o valor da distancia de um pequeno robo ate cada um dos seus 4 lados.
// A funcao deve retornar duas informacoes: A primeira e a direcao
// de maior distancia ("Direita", "Esquerda", "Frente", "Tras") e a
// segunda e esta maior distancia.

/*4. Implemente a fun��o 'direcaoMenorCaminho' que receber� 2 argumentos:
(1) o ponteiro para um vetor e (2) o ponteiro para uma vari�vel.
Esta fun��o deve avaliar 4 valores do vetor, a partir do ponteiro
(1) recebido. Os 4 valores representam as dist�ncias nos sentidos:
Direta, Esquerda, Frente e Tr�s (esses valores foram inseridos com a fun��o
'leituraSensor', convertidos com a fun��o 'converteSensor' e armazenados no
vetor com a fun��o 'armazenaVetor'). Esta fun��o retorna o sentido de maior
dist�ncia, e com base no ponteiro (2) para a vari�vel, nela armazena o valor
da maior dist�ncia.*/


char *direcaoMenorCaminho(int *pvetor, int *pvariavel)
{

	static char dir;


	int valor_maximo = 0;


	if (pvetor[0] > valor_maximo)
	{

		dir = 'D';
		valor_maximo = pvetor[0];
	}

	if (pvetor[1] > valor_maximo)
	{

		dir = 'E';
		valor_maximo = pvetor[1];
	}

	if (pvetor[2] > valor_maximo)
	{

		dir = 'F';
		valor_maximo = pvetor[2];
	}

	if (pvetor[3] >valor_maximo)
	{

		dir = 'T';
		valor_maximo = pvetor[3];
	}

	
	*pvariavel = valor_maximo;


	return &dir;
}



// 5 - Faca uma funcao que pergunta ao usuario se ele deseja continuar o mapeamento e
// retorna verdadeiro ou falso

/*5. Implemente a fun��o 'leComando' que n�o receber� argumentos.
Esta fun��o pergunta ao usu�rio se ele deseja continuar o mapeamento.
A fun��o retorna o inteiro 1 (um) se a resposta for SIM ou 0 (zero) se a resposta for N�O.*/

int leComando ()
{
	cout << "Deseja continuar o mapeamento? Responda com 'sim' ou 'nao'" << endl;
	string resultado = " ";

	getline(cin, resultado);

	if (resultado == sim)
	{
		return true;
	}
	else
	{
		return false;
	}
}


// 6 - A funcao abaixo (que esta incompleta) vai "dirigindo" virtualmente um robo
// e atraves de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda",
// "Frente", "Tras").
//      A cada passo, ele verifica as distancias aos objetos e vai mapeando o terreno
// para uma movimentacao futura.
//      Ele vai armazenando estas distancias em um vetor fornecido como parametro
// e retorna a ultima posicao preenchida do vetor.
//      Esta funcao deve ir lendo os 4 sensores ate que um comando de pare seja enviado
//
//      Para simular os sensores e os comandos de pare, use as funcoes ja� construi�das
// nos itens anteriores e em um looping continuo ate que um pedido de parada seja
// enviado pelo usuario.
//
//      Complete a funcao com a chamada das funcoes ja� criadas


int dirige(int *v, int maxv)
{
	int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;
	while(dirigindo)
	{
		int medida = leituraSensor();/// .. Chame a funcao de de leitura da medida para a "Direita"
		medida = converteSensor(medida, 0, 830);
		posAtualVetor = armazenaVetor(int * ponteiroVetor, int tamanhoVetor, int posicaoVetor, int medidaVetor); // Chame a funcao para armazenar a medida no vetor

		medida = leituraSensor();/// .. Chame a funcao de de leitura da medida para a "Esquerda"
		medida = converteSensor(medida, 0, 830);
		posAtualVetor = armazenaVetor(int * ponteiroVetor, int tamanhoVetor, int posicaoVetor, int medidaVetor);

		medida = leituraSensor();/// .. Chame a funcao de de leitura da medida para a "atras"
		medida = converteSensor(medida, 0, 830);
		posAtualVetor = armazenaVetor(int * ponteiroVetor, int tamanhoVetor, int posicaoVetor, int medidaVetor);

		medida = leituraSensor();/// .. Chame a funcao de de leitura da medida para a "frente"
		medida = converteSensor(medida, 0, 830);
		posAtualVetor = armazenaVetor(int * ponteiroVetor, int tamanhoVetor, int posicaoVetor, int medidaVetor);

		dirigindo = leComando();
	}
	return posAtualVetor;
}


// O trecho abaixo ira utilizar as funcoes acima para ler os sensores e o movimento
// do robo e no final percorrer o vetor e mostrar o movimento a cada direcao baseado
// na maior distancia a cada movimento
void percorre(int *v, int tamPercorrido)
{
	int *vetorMov = v;
	int maiorDir = 0;

	for(int i = 0; i < tamPercorrido; i += 4)
	{
		char *direcao = direcaoMenorCaminho(&(vetorMov[i]), &maiorDir);
		printf("Movimentando para %s distancia = %i\n", direcao, maiorDir);
	}
}

int main(int argc, char** argv)
{
	int maxVetor = 100;
	int vetorMov[maxVetor * 4];
	int posAtualVet = 0;

	posAtualVet = dirige(vetorMov, maxVetor);
	percorre(vetorMov, posAtualVet);

	return 0;
}
