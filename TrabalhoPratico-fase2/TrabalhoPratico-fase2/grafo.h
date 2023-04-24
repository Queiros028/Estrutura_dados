#pragma once

//Representar um grafo orientado e pesado atrav�s da defini��o de uma lista ligada de listas ligadas

#define TAM 50

typedef struct registo3
{ int codigo;
  struct registo3 * seguinte;
} * Meios;

// Representa��o de um grafo orientado e pesado
typedef struct registo2
{char vertice[TAM]; // geoc�digo what3words
 float peso;
 struct registo2 * seguinte;
} * Adjacente;


typedef struct registo1
{char vertice[TAM]; // geoc�digo what3words
 Adjacente adjacentes;
 Meios meios; // Lista ligada com os c�digos dos meios de transporte existente
	      // neste geoc�digo
 struct registo1 * seguinte;
} * Grafo;