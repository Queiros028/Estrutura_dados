#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grafo.h"


int guardarMeio(Grafo g)
{
	FILE* fp;
	fp = fopen("meios.txt", "w");

	if (fp != NULL)
	{
		meioTransporte aux = g->meios;
		
		while (aux != NULL)
		{
			fprintf(fp, "%d;%s;%.2f;%.2f;%s\n",aux->codigo, aux->tipo, aux->bateria, aux->autonomia,aux->localizacao);			
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);
	}
	else return(0);
	
}

int guardarCliente(Grafo g)
{
	FILE* fp;
	fp = fopen("meios.txt", "w");

	if (fp != NULL)
	{
		Cliente aux = g->clientes;

		while (aux != NULL)
		{
			fprintf(fp, "%d;%s;%d;%d;%s;%s\n", aux->codigo,aux->nome, aux->numTele, aux->nif, aux->mail, aux->localizacao);
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);
	}
	else return(0);

}


//esta parte n esta acabada, ver como fzr a parte da variavel auxiliar
	/*
int lerMeio(Grafo g)
{
	FILE* fp;
	int cod;
	float bat, aut;
	char tipo[50], alug[50], local[50];
	meioTransporte* aux = NULL;
	fp = fopen("meios.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%s;%f;%f;%s;%s\n", &cod, tipo, &bat, &aut, alug, local);
			aux = inserirMeio(aux, cod, tipo, bat, aut, alug, local);
		}
		fclose(fp);
	}
	return(aux);
}
*/



// Criar um novo vértice
// Devolve 1 em caso de sucesso ou 0 caso contrário
int CriarVertice(Grafo *g, char novoId[])
{
	Grafo novo = malloc(sizeof(struct registo1));
	if (novo != NULL)
	{
		strcpy(novo->vertice, novoId);
		novo->meios = NULL;
		novo->seguinte = *g;
		*g = novo;
		return(1);
	}
	else return(0);
}

// Devolve 1 se o vertice existe no grafo ou 0 caso contrário
int existeVertice(Grafo g, char vertice[])
{
	while (g != NULL)
	{
		if (strcmp(g->vertice, vertice) == 0) 
		{
			return(1);
		}
		else g = g->seguinte;
	}
	return(0);
}


// Criar uma nova aresta
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarAresta(Grafo g, char verticeOrigem[], char verticeDestino[], float peso)
{
	Adjacente novo;
	if (existeVertice(g, verticeOrigem) && existeVertice(g, verticeDestino))
	{
		while (strcmp(g->vertice, verticeOrigem) != 0) g = g->seguinte;
		novo = malloc(sizeof(struct registo1));
		if (novo != NULL)
		{
			strcpy(novo->vertice, verticeDestino);
			novo->peso = peso;
			novo->seguinte = g->adjacentes;
			g->adjacentes = novo;
			return(1);
		}
		else return(0);
	}
	else return(0);
}


// Inserir meio de transporte na localização com geocódigo passado por parâmetro
// Devolve 1 em caso de sucesso ou 0 caso contrário
int inserirMeio(Grafo g, char geocodigo[], int cod, char tipoo[], float bat,float aut, char local[])
{
	while ((g != NULL) && (strcmp(g->vertice, geocodigo) != 0)) 
	{
		g = g->seguinte;
	}
		
	if (g == NULL) return(0);
	else {
		meioTransporte novo = malloc(sizeof(struct registo));
		novo->codigo = cod;
		strcpy(novo->tipo, tipoo);
		novo->bateria = bat;
		novo->autonomia = aut;
		strcpy(novo->localizacao, local);
		novo->seguinte = g->meios;
		g->meios = novo;
		return(1);
	}
}

int inserirClientes(Grafo g,char geocodigo[], int cod, char name[], int numTel, int niff, char email[], char local[])
{
	while ((g != NULL) && (strcmp(g->vertice, geocodigo) != 0))
	{
		g = g->seguinte;
	}
	if (g == NULL)
	{
		return(0);
	}
	else {
		Cliente novo = malloc(sizeof(struct registo3));
		novo->codigo = cod;
		strcpy(novo->nome, name);
		novo->numTele = numTel;
		novo->nif = niff;
		strcpy(novo->mail,email);
		strcpy(novo->localizacao,local);
		novo->seguinte = g->meios;
		g->meios = novo;
		return(1);
	}

}





//AS DUAS FUNCOES DE LISTAR AINDA N ESTAO ACABADAS!!!!!!!!!!!!!!!!!!
// Listar os códigos dos meios de transporte presente numa determinada localização passada por parâmetro
void listarMeios(Grafo g, char local[])
{
	while ((g != NULL) && (strcmp(g->vertice, local) != 0))
		g = g->seguinte;
	if (g != NULL)
	{
		meioTransporte aux = g->meios;
		if (aux == NULL) {
			printf("sem meios de transporte\n");
		}		
		else while (aux != NULL)
		{
			printf("Codigo meio: %d\n", aux->codigo);
			aux = aux->seguinte;
		}
	}else printf("Localizacao inexistente\n");
}


// Listar os vértices adjacentes 
//funcao auxiliar para listar os meios(alinea 3 do tp)
void listarAdjacentes(Grafo g, char vertice[], int distancia)
{
	Adjacente aux;
	if (existeVertice(g, vertice))
	{
		while (strcmp(g->vertice, vertice) != 0) g = g->seguinte; 
		{
			aux = g->adjacentes;
		}
		while (aux != NULL)
		{
			printf("Adjacente:%s Peso:%.2f\n", aux->vertice, aux->peso);
			aux = aux->seguinte;
		}
	}
}