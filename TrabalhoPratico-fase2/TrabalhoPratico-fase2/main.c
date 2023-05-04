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

int menuInicial() {

	int opcaoInicial;
	printf("*****************Trabalho Pratico- Fase 2!!****************************\n");
	printf("\n");
	printf("1- Continuar para o programa\n");
	printf("Opcao: \n");
	printf("*******************************\n");
	scanf("%d", &opcaoInicial);
	printf("*******************************\n");
	return(opcaoInicial);
}


int menuOpcoes()
{
	int opcao;
	printf("*******************************************\n");
	printf("1- Criar vertice\n");
	printf("2- Verificar se existe o vertice\n");
	printf("3- Criar Aresta\n");
	printf("4- Inserir meios\n");
	printf("5- Inserir clientes\n");
	printf("6- Armazenar meios\n");
	printf("7- Armazenar clientes\n");
	printf("8- Ler meios\n");
	printf("9- Ler clientes\n");
	printf("10- Listar meios em x raio\n");
	printf("11- Caixeiro viajante\n");
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
	char tipoo[TAM], localMeio[TAM], geocodigoMeio[TAM];
	float bat, aut;

	//variavies cliente
	int codcliente, numTel, niff;
	char nomeCliente[TAM],email[TAM], localCliente[TAM], geocodigoCliente[TAM];


	meioTransporte* meios = NULL;
	Cliente* clientes = NULL;

	do 
	{
		opcao = menuOpcoes();
		switch (opcao)
		{
			/*
		case 1: CriarVertice();
				break:
		case 2: existeVertice();
			break;
		case 3: criarAresta();
			break;
			*/
		case 4:printf("Insira o geocodigo:\n");
			scanf("%[^\n]s", geocodigoMeio); //ns se isto esta a dar direito, dps preciso de confirmar
			printf("Insira o codigo do meio:\n");
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
			inserirMeio(meios, geocodigoMeio,codmeio, tipoo, bat, aut, localMeio);
			break;
		case 5: printf("Insira o geocodigo:\n");
			scanf("%[^\n]s", geocodigoCliente);
			printf("Insira o codigo do cliente:\n");
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
			inserirClientes(clientes,geocodigoCliente ,codcliente,nomeCliente ,numTel, niff, email, localCliente);
			break;


		default:
			break;
		}
	} while (opcao != 0);
}

int main() {
	Grafo G = NULL;

	int opcaoPrincipal = menuInicial();
	switch (opcaoPrincipal) 
	{
		case 1: menuOpcoes();
			break;
		default: printf("Não existe essa opcao!!!\n");
	}

}
