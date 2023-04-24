#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grafo.h"

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
		if (strcmp(g->vertice, vertice) == 0) return(1);
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
int inserirMeio(Grafo g, char geocodigo[], int codMeio)
{
	while ((g != NULL) && (strcmp(g->vertice, geocodigo) != 0))
		g = g->seguinte;
	if (g == NULL) return(0);
	else {
		Meios novo = malloc(sizeof(struct registo3));
		novo->codigo = codMeio;
		novo->seguinte = g->meios;
		g->meios = novo;
		return(1);
	}
}

// Listar os códigos dos meios de transporte presente numa determinada localização passada por parâmetro
void listarMeios(Grafo g, char geocodigo[])
{
	while ((g != NULL) && (strcmp(g->vertice, geocodigo) != 0))
		g = g->seguinte;
	if (g != NULL)
	{
		Meios aux = g->meios;
		if (aux == NULL) printf("sem meios de transporte\n");
		else while (aux != NULL)
		{
			printf("Codigo meio: %d\n", aux->codigo);
			aux = aux->seguinte;
		}
	}
	else printf("geocodigo inexistente\n");
}
