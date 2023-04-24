#pragma once

//Representar um grafo orientado e pesado através da definição de uma lista ligada de listas ligadas

#define TAM 50

typedef struct registo3
{ int codigo;
  struct registo3 * seguinte;
} * Meios;

// Representação de um grafo orientado e pesado
typedef struct registo2
{char vertice[TAM]; // geocódigo what3words
 float peso;
 struct registo2 * seguinte;
} * Adjacente;


typedef struct registo1
{char vertice[TAM]; // geocódigo what3words
 Adjacente adjacentes;
 Meios meios; // Lista ligada com os códigos dos meios de transporte existente
	      // neste geocódigo
 struct registo1 * seguinte;
} * Grafo;