/*****************************************************************//**
 * \file   main.c
 * 
 * \author Eduardo Queirós
 * \date   March 2023
 *********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

#pragma warning(disable: 4996) 

int menuOpcoes()
{
	int opcao;
	printf("*******************************************\n");
	printf("1- Inserir meios\n");
	printf("2- Inserir clientes\n");
	printf("3- Armazenar meios\n");
	printf("4- Armazenar clientes\n");
	printf("5- Ler meios\n");
	printf("6- Ler clientes\n");
	printf("7- Listar meios em x raio\n");
	printf("8- Caixeiro viajante\n");
	printf("0 - SAIR\n");
	printf("*******************************************\n");
	printf("Opcao?\n ");
	scanf("%d", &opcao);
	printf("*******************************************\n");
	return(opcao);

}

int menu() 
{
	int opcao;
	//variaveis meioTransporte
	int codmeio;
	char tipoo[TAM], localMeio[TAM];
	float bat, aut;

	//variavies cliente
	int codcliente, numTel, niff;
	char nomeCliente[TAM],email[TAM], localCliente[TAM];


	meioTransporte* meios = NULL;
	Cliente* clientes = NULL;

	do 
	{
		opcao = menuOpcoes();
		switch (opcao)
		{
		case 1: printf("Insira o codigo do meio:\n");
			scanf("%d", &codmeio);
			scanf("%*c");
			printf("Insira o tipo de transporte:\n");
			scanf("%[^\n]s", tipoo);
			printf("Insira o nivel da bateria:\n");
			scanf("%f", &bat);
			printf("Insira a autonomia do transporte:\n");
			scanf("%f", &aut);
			printf("Insira a localizacao:\n");
			scanf("%s", &localMeio);				
			inserirMeio(meios, codmeio, tipoo, bat, aut, localMeio);
			break;
		case 2: printf("Insira o codigo do cliente:\n");
			scanf("%d", &codcliente);
			scanf("%*c");
			printf("Insira o nome:\n");
			scanf("%[^\n]s", nomeCliente);
			printf("Insira o numero de telemovel\n");
			scanf("%d", &numTel);
			printf("Insira o nif:\n");
			scanf("%d", &niff);
			printf("Insira o email:\n");
			scanf("%s", &email);
			printf("Insira a localizacao:\n");
			scanf("%s", &localCliente);		
			inserirClientes(clientes, codcliente, numTel, niff, email, localCliente);
			break;


		default:
			break;
		}
	} while (opcao != 0);
}

int main() {
	Grafo G = NULL;



}
