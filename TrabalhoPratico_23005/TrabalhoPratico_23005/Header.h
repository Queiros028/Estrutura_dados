/*****************************************************************//**
 * \file   Header.h
 * 
 * \author Eduardo Queir�s
 * \date   March 2023
 *********************************************************************/

#pragma once
#include<stdio.h>
#include <string.h>
#pragma warning(disable: 4996)


typedef struct registo {
	int codigo; //codigo do meio de transporte
	char tipo[50];//tipo de meio de transporte(ex: trotinete el�trica)
	float bateria;
	float autonomia;
	char aluguer[50]; //registo de aluguer
	char localizacao[50]; //localiza��o do meio de transporte
	struct registo* seguinte; //endere�o de mem�ria para uma struct registo
}meioTransporte;

typedef struct registo2 {
	int codigo; //codigo do cliente
	char nome[50]; //nome do cliente
	int numTelemovel; //numero de telefone
	int nif; 
	char mail[50];
	struct registo2* seguinte; //endere�o de mem�ria para uma struct registo
}cliente;


typedef struct registo3 {
	int codigo; //codigo do gestor
	char nome[50]; //nome do gestor
	char password[50]; //password do gestor
	struct registo3* seguinte; //endere�o de mem�ria para uma struct registo
}gestor;



//FUN��ES PARA GUARDAR NO FICHEIRO DE TEXTO
	//guardar os meios de transporte

int guardarMeio(meioTransporte* inicio);
	//guardar os clientes 
int guardarCliente(cliente* inicio);
	//guardar os gestores
int guardarGestor(gestor* inicio);

//FUN��ES PARA LER OS DADOS
	//ler meios
meioTransporte* lerMeio();
	//ler clientes
cliente* lerCliente();
	//ler gestores
gestor* lerGestor();

//FUN��ES PARA VERIFICAR SE DETERMINADO DADO J� EXISTE
	//fun��o para verificar se j� existe o tipo de transporte
int existeMeio(meioTransporte* inicio, int cod);
	//fun��o para verificar se j� existe cliente
int existeCliente(cliente* inicio, int cod);
	//fun��o para verificar se j� existe o gestor
int existeGestor(gestor* inicio, int cod);

//FUN��ES PARA LISTAR OS DADOS 
	//fun��o para listar os dados do meio de transporte
void listarMeios(meioTransporte* inicio);
	//fun��o para listar os dados do cliente
void listarCliente(cliente* inicio);
	//fun��o para listar os dados do gestor
void listarGestor(gestor* inicio);


//fun��es para inserir um novo registo
	//fun��o para inserir meio de transporte
meioTransporte* inserirMeio(meioTransporte* inicio, int cod, char tipo[], float bat, float aut, char alug[], char local[]);
	//fun��o para inserir cliente
cliente* inserirCliente(cliente* inicio, int cod, char name[], int numTel, int NIF, char email[]);
	//fun��o para inserir gestor
gestor* inserirGestor(gestor* inicio, int cod, char name[], char pass[]);


//fun��es para remover determinado tipo de dados
	//fun��o para remover meio de transporte
meioTransporte* removerMeio(meioTransporte* inicio, int cod);
	//fun��o para remover cliente
cliente* removerCliente(cliente* inicio, int cod);
	//fun��o para remover gestor
gestor* removerGestor(gestor* inicio, int cod);

//fun��es para alterar detemerminado tipo de dados
	//fun��o para alterar meio transporte
meioTransporte* alterarMeio(meioTransporte* inicio, int cod, char tipo[], float bat, float aut, char alug[], char local[]);
	//fun��o para alterar cliente
cliente* alterarCliente(cliente* inicio, int cod, char name[], int numTel, int NIF, char email[]);
//fun��o para alterar gestor
gestor* alterarGestor(gestor* inicio, int cod, char name[], char pass);


//fun��o para registo de aluguer de um determinado meio de mobilidade eletrica
void registoAluguer(meioTransporte* inicio, int cod); 

//ordenar meios de transporte por ordem decrescente de autonomia
meioTransporte* Ordenar(meioTransporte* inicio);
//listagem dos meios de mobilidade el�trica por ordem decrescente de autonomia
void listarMeiosAutonomia(meioTransporte* listagem);

//listagem de meios de mobilidade existentes numa localiza��o com determinado geoc�digo
void listarMeiosLocalizacao(meioTransporte* inicio, char local[]); 