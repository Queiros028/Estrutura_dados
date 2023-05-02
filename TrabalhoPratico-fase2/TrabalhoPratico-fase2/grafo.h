#pragma once

//Representar um grafo orientado e pesado através da definição de uma lista ligada de listas ligadas

#define TAM 50

// Representação de um grafo orientado e pesado
typedef struct registo2
{char vertice[TAM]; // geocódigo what3words
 float peso;
 struct registo2 * seguinte;
} * Adjacente;

typedef struct registo {
	int codigo; //codigo do meio de transporte
	char tipo[50];//tipo de meio de transporte
	float bateria;
	float autonomia;
	char localizacao[50]; //localizacao do meio de transporte
	struct registo* seguinte; //endereco de memoria para uma struct registo
} * meioTransporte;

typedef struct registo3 {
	int codigo;
	char nome[50];
	int numTele;
	int nif;
	char mail[50];
	char localizacao[50];//localizacao do cliente
	struct registo3* seguinte; //endereco de memoria para uma struct registo
} *Cliente;

typedef struct registo1
{
	char vertice[TAM]; // geocódigo what3words
	Cliente clientes;
	Adjacente adjacentes;
	 meioTransporte meios; // Lista ligada com os códigos dos meios de transporte existente
	      // neste geocódigo
	struct registo1 * seguinte;
} * Grafo;



//*******************************************************************************************************

int guardarMeio(Grafo g);
int guardarCliente(Grafo g);
int inserirMeio(Grafo g, char geocodigo[], int cod, char tipoo[], float bat, float aut, char local[]);
int inserirClientes(Grafo g, char geocodigo[], int cod, char name[], int numTel, int niff, char email[], char local[]);

int CriarVertice(Grafo* g, char novoId[]);
// Criar uma nova aresta
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarAresta(Grafo g, char verticeOrigem[], char verticeDestino[], float peso);
int existeVertice(Grafo g, char vertice[]);





