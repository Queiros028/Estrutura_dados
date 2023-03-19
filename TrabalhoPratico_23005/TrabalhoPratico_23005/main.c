/*****************************************************************//**
 * \file   main.c
 * 
 * \author Eduardo Queirós
 * \date   March 2023
 *********************************************************************/

#include <stdio.h>
#include "Header.h"


#pragma warning(disable: 4996)

/**
 *
 * \function name- menuPrincipal
 * \brief- Esta função será utilizada como um menu principal do programa. Este menu será apresentado no início do programa. 
 *		   A função irá perguntar ao utilizador qual o tipo de utilizador é(Gestor ou Cliente). 
 *  
 */
int menuPrincipal() 
{

	int opcaoPrincipal;
	printf("Menu Principal: \n");
	printf("1- Gestor\n");
	printf("2- Cliente\n");
	printf("Opcao:\n");
	printf("*******************************\n");
	scanf("%d", &opcaoPrincipal);
	printf("*******************************\n");
	return(opcaoPrincipal);
}

/**
 *
 * \function name- menuGestor
 * \brief- A função mostra as operações que o gestor pode realizar, o gestor consegue realizar todas as operações
 *
 */
int menuGestor() 
{

	int opcaoGestor;
	printf("*******************************\n");
	printf("Menu Gestor: \n");
	printf("1-Armazenar\n");
	printf("2-Ler/listar meios\n");
	printf("3-Ler/listar clientes\n");
	printf("4-Ler/listar gestores\n");
	printf("5-Inserir meios de transporte \n");
	printf("6-Inserir clientes \n");
	printf("7-Inserir gestores \n");
	printf("8-Remover meios de transporte \n");
	printf("9-Remover clientes\n");
	printf("10-Remover gestores\n");
	printf("11-Alterar meios de transporte \n");
	printf("12-Alterar clientes\n");
	printf("13-Alterar gestores\n");
	printf("14-Registo aluguer \n");
	printf("15-Listar meios por autonomia\n");
	printf("16-Listar meios por localizacao\n");
	printf("0-SAIR\n");
	printf("*******************************\n");
	printf("Opcao:\n");
	scanf("%d", &opcaoGestor);
	printf("*******************************\n");
	return(opcaoGestor);

}

/**
 *
 * \function name- menuCliente
 * \brief- A função mostra as operações que o cliente pode realizar, o cliente não consegue fazer todas as operações
 *  
 */
int menuCliente(){

	int opcaoCliente;
	printf("*******************************\n");
	printf("Menu Cliente: \n");
	printf("1-Armazenar clientes \n");
	printf("2-Inserir clientes \n");
	printf("3-Registo aluguer\n");
	printf("4-Ler/listar clientes\n");
	printf("5-Listar meios por autonomia\n");
	printf("6-Listar meios por localizacao\n");
	printf("0-SAIR\n");
	printf("*******************************\n");
	printf("Opcao:\n");
	scanf("%d", &opcaoCliente);
	printf("*******************************\n");
	return(opcaoCliente);
}

//MENU GESTOR
/**
 *
 * \function name- Gestor
 * \brief- A função funciona em relação ao menuGestor, isto é, consoante a opção que o gestor escolher, a função irá executar a função
 *		correspondente.
 *  
 */
int Gestor() {

	int opcaoGestor;
	// variáveis para a struct meioTransporte
	int codTransporte;
	float bat, aut;
	char tipo[50], alug[50], local[50];
	//***************

	// variáveis para a struct cliente
	int codCliente, numTelefone, NIF;
	char nomeCliente[50], email[50];
	//**********************

	// variáveis para a struct gestor
	int codGestor;
	char nomeGestor[50], pass[50];

	meioTransporte* meios = NULL; //Lista ligada vazia!!!
	cliente* clientes = NULL; //Lista ligada vazia!!!
	gestor* gestores = NULL; //Lista ligada vazia!!!
	do
	{
		opcaoGestor = menuGestor();
		switch (opcaoGestor)
		{
		case 1:guardarMeio(meios);
			guardarCliente(clientes);
			guardarGestor(gestores);
			break;
		case 2:	meios = lerMeio();
			listarMeios(meios);
			break;
		case 3: clientes = lerCliente();
			listarCliente(clientes);
			break;
		case 4: gestores = lerGestor();
			listarGestor(gestores);
			break;
		case 5: printf("Insira o codigo:\n");
			scanf("%d", &codTransporte);
			scanf("%*c");
			printf("Insira o tipo de transporte:\n");
			scanf("%[^\n]s", tipo);
			printf("Insira o nivel da bateria:\n");
			scanf("%f", &bat);
			printf("Insira a autonomia do transporte:\n");
			scanf("%f", &aut);
			printf("Insira o aluguer:\n");
			scanf("%s", &alug);
			printf("Insira a localizacao:\n");
			scanf("%s", &local);
			meios = inserirMeio(meios, codTransporte, tipo, bat, aut, alug, local);
			break;

		case 6: printf("Insira o codigo:\n");
			scanf("%d", &codCliente);
			scanf("%*c");
			printf("Insira o nome:\n");
			scanf("%[^\n]s", nomeCliente);
			printf("Insira o numero de telefone:\n");
			scanf("%d", &numTelefone);
			printf("Insira o nif:\n");
			scanf("%d", &NIF);
			printf("Insira o email:\n");
			scanf("%s", &email);
			clientes = inserirCliente(clientes, codCliente, nomeCliente, numTelefone, NIF, email);
			break;

		case 7: printf("Insira o codigo:\n");
			scanf("%d", &codGestor);
			scanf("%*c");
			printf("Insira o nome:\n");
			scanf("%s", nomeGestor);
			printf("Insira a password:\n");
			scanf("%s", &pass);
			gestores = inserirGestor(gestores, codGestor, nomeGestor, pass);
			break;

		case 8:printf("Codigo do meio de mobilidade a remover?\n");
			scanf("%d", &codTransporte);
			meios = removerMeio(meios, codTransporte);	
			break;

		case 9: printf("Codigo do cliente a remover?\n");
			scanf("%d", &codCliente);
			clientes = removerCliente(clientes, codCliente);
			break;

		case 10: printf("Codigo do gestor a remover?\n");
			scanf("%d", &codGestor);
			gestores = removerGestor(gestores, codGestor);
			break;

		case 11:printf("Introduza o codigo do meio de transporte que pretende alterar: \n");
			scanf("%d", &codTransporte);
			printf("Insira o tipo de transporte:\n");
			scanf("%s", tipo);
			printf("Insira o nivel da bateria:\n");
			scanf("%f", &bat);
			printf("Insira a autonomia do transporte:\n");
			scanf("%f", &aut);
			printf("Insira o aluguer:\n");
			scanf("%s", &alug);
			printf("Insira a localizacao:\n");
			scanf("%s", &local);
			meios = alterarMeio(meios, codTransporte, tipo, bat, aut, alug, local);
			break;

		case 12:printf("Introduza o codigo do cliente que pretende alterar: \n");
			scanf("%d", &codCliente);
			printf("Insira o nome:\n");
			scanf("%s", nomeCliente);
			printf("Insira o numero de telefone:\n");
			scanf("%d", &numTelefone);
			printf("Insira o nif:\n");
			scanf("%d", &NIF);
			printf("Insira o email:\n");
			scanf("%s", &email);
			clientes = alterarCliente(clientes, codCliente, nomeCliente, numTelefone, NIF, email);
			break;

		case 13:printf("Introduza o codigo do gestor que pretende alterar: \n");
			scanf("%d", &codGestor);
			printf("Insira o nome:\n");
			scanf("%[^\n]s", nomeGestor);
			printf("Insira a password:\n");
			scanf("%s", &pass);
			gestores = alterarGestor(gestores, codGestor, nomeGestor, pass);
			break;

		case 14:registoAluguer(meios, codTransporte);
			break;
		case 15:Ordenar(meios);
			listarMeiosAutonomia(meios);
			break;
		case 16:printf("Qual o localizacao do meio: \n");
			scanf("%s", &local);
			listarMeiosLocalizacao(meios, local);
			break;
		}

	} while (opcaoGestor != 0);


}

//MENU CLIENTE
/**
 *
 * \function name- Cliente
 * \brief- A função funciona em relação ao menuCliente, isto é, consoante a opção que o cliente escolher, a função irá executar a função
 *		correspondente.
 *  
 */
int Cliente() {

	int opcaoCliente;
	char resposta;
	// variáveis para a struct meioTransporte
	int codTransporte;
	float bat, aut;
	char tipo[50], alug[50], local[50];

	// variáveis para a struct cliente
	int codCliente, numTelefone, NIF;
	char nomeCliente[50], email[50];
	//**********************

	// variáveis para a struct gestor
	int codGestor;
	char nomeGestor[50], pass[50];

	meioTransporte* meios = NULL; //Lista ligada vazia!!!
	cliente* clientes = NULL;
	gestor* gestores = NULL;


	do
	{
		opcaoCliente = menuCliente();
		switch (opcaoCliente)
		{
		case 1:	guardarCliente(clientes);
			break;
		case 2: printf("Insira o codigo:\n");
			scanf("%d", &codCliente);
			scanf("%*c");
			printf("Insira o nome:\n");
			scanf("%[^\n]s", nomeCliente);
			printf("Insira o numero de telefone:\n");
			scanf("%d", &numTelefone);
			printf("Insira o nif:\n");
			scanf("%d", &NIF);
			printf("Insira o email:\n");
			scanf("%s", &email);
			clientes = inserirCliente(clientes, codCliente, nomeCliente, numTelefone, NIF, email);
			break;

		case 3:printf("Introduza o codigo do cliente que pretende alterar: \n");
			scanf("%d", &codCliente);
			printf("O que deseja alterar? \n");
			scanf("%s", &resposta);
			clientes = alterarCliente(clientes, codCliente, nomeCliente, numTelefone, NIF, email); 
			break;
		case 4: clientes = lerCliente();
			listarCliente(clientes);
		case 5:Ordenar(meios);
			listarMeiosAutonomia(meios);
			break;
		case 6: printf("Qual o localizacao do meio: ");
			scanf("%s", &local);
			listarMeiosLocalizacao(meios, local);
			break;
		}

	} while (opcaoCliente != 0);
	return(0);

}

/**
 *
 * \function name- main
 * \brief- A função irá "abrir" um menu consoante a resposta do utilizador no menu principal. Caso o utilizador escolha a opção 1 o programa
 *		irá abrir o menu do gestor, caso escolha 2 irá abrir o menu do cliente
 *		A função também faz com que as listas ligadas fiquem vazias
 *  
 */
int main() {
	meioTransporte* meios = NULL; //Lista ligada vazia!!!
	cliente* clientes = NULL;
	gestor* gestores = NULL;

	int opPrincipal = menuPrincipal();
	switch (opPrincipal) {
		case 1: Gestor();
			break;	
		case 2: Cliente();
			break;
		default: printf("Opcao invalida!!!!!!\n");
	}
			
}