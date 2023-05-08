/*****************************************************************//**
 * \file   main.c
 * 
 * \author Eduardo Queirós
 * \date   May 2023
 *********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

#pragma warning(disable: 4996) 

int menuOpcoes()
{
	int opcao;
	printf("*************************Trabalho pratico -> Fase 2************************\n");
	printf("Escolha a operacao que deseja implementar: \n");
	printf("1- Criar vertice\n");
	printf("2- Criar Aresta\n");
	printf("3- Listar vertices adjacentes\n");
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
	printf("Opcao: \n ");
	scanf("%d", &opcao);
	printf("*******************************************\n");
	return(opcao);

}

int menu() 
{
	int opcao;
	//variaveis para os vertices/arestas
	char localVertice[TAM];
	int resultado;//ns se isto deve estar em int ou char!!!!!!!

	//variaveis meioTransporte
	int codmeio;
	char tipoo[TAM], localMeio[TAM], geocodigoMeio[TAM];
	float bat, aut;

	//variavies cliente
	int codcliente, numTel, niff;
	char nomeCliente[TAM],email[TAM], localCliente[TAM], geocodigoCliente[TAM];

	Grafo g = NULL;

	do 
	{
		opcao = menuOpcoes();
		switch (opcao)
		{	
		case 1: printf("Qual o geocodigo do vertice que pretende criar?\n");
			scanf("%s", &localVertice);
			resultado = CriarVertice(&g, localVertice);
			printf("***************\n");
			if (resultado == 1) {
				printf("Vertice criado!\n");
			}
			else if (resultado == 0) 
			{
				printf("Vertice nao foi criado\n");
			}
			break;
		case 2: 
			break;	
		case 3: 
			break;
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
			inserirMeio(g, geocodigoMeio,codmeio, tipoo, bat, aut, localMeio);
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
			inserirClientes(g,geocodigoCliente ,codcliente,nomeCliente ,numTel, niff, email, localCliente);
			break;

		case 6: guardarCliente(g); 
			break;
		case 7: guardarMeio(g); 
			break;
		//case 8: meios = lerMeio(g);
			//break;
		//case 9: clientes = lerCliente(g);
			//break;		
		}
	} while (opcao != 0);

	return(0);
}

int main() {
	Grafo g = NULL;

	/*
	*	aqui vou fzr assim para ja ter 3 vertices ligados antes de correr menu
	* depois no menu posso adicionar mais vertices e pra ligar os mesmos tenho de criar arestas entre eles
	*/
	CriarVertice(&g, "earplug.amazons.distortion"); //1º vértice pré existente(localizao ipca)
	CriarVertice(&g, "fruit.cutback.breeding"); //2º vértice pré existente(localizacao zona ribeirinha)
	CriarVertice(&g, "embark.birdseed.ticked"); //3º vértice pré existente(localizacao estadio gil vicente)

	criarAresta(g, "earplug.amazons.distortion", "fruit.cutback.breeding", 4);// aresta entre ipca e zona ribeirinha
	criarAresta(g, "earplug.amazons.distortion", "embark.birdseed.ticked", 1); //aresta entre ipca e estadio gil
	criarAresta(g, "fruit.cutback.breeding", "embark.birdseed.ticked", 1); //aresta entre zonha ribeirinha e estadio gil
	

	int opcaoPrincipal = menu(); 

}
