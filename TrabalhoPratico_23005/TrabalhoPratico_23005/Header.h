/*****************************************************************//**
 * \file   Header.h
 * 
 * \author Eduardo Queirós
 * \date   March 2023
 *********************************************************************/

#pragma once
#include<stdio.h>
#include <string.h>
#pragma warning(disable: 4996)


typedef struct registo {
	int codigo; //codigo do meio de transporte
	char tipo[50];//tipo de meio de transporte(ex: trotinete elétrica)
	float bateria;
	float autonomia;
	char aluguer[50]; //registo de aluguer
	char localizacao[50]; //localização do meio de transporte
	struct registo* seguinte; //endereço de memória para uma struct registo
}meioTransporte;

typedef struct registo2 {
	int codigo; //codigo do cliente
	char nome[50]; //nome do cliente
	int numTelemovel; //numero de telefone
	int nif; 
	char mail[50];
	struct registo2* seguinte; //endereço de memória para uma struct registo
}cliente;


typedef struct registo3 {
	int codigo; //codigo do gestor
	char nome[50]; //nome do gestor
	char password[50]; //password do gestor
	struct registo3* seguinte; //endereço de memória para uma struct registo
}gestor;



//FUNÇÕES PARA GUARDAR NO FICHEIRO DE TEXTO
	//guardar os meios de transporte

int guardarMeio(meioTransporte* inicio);
	//guardar os clientes 
int guardarCliente(cliente* inicio);
	//guardar os gestores
int guardarGestor(gestor* inicio);

//FUNÇÕES PARA LER OS DADOS
	//ler meios
meioTransporte* lerMeio();
	//ler clientes
cliente* lerCliente();
	//ler gestores
gestor* lerGestor();

//FUNÇÕES PARA VERIFICAR SE DETERMINADO DADO JÁ EXISTE
	//função para verificar se já existe o tipo de transporte
int existeMeio(meioTransporte* inicio, int cod);
	//função para verificar se já existe cliente
int existeCliente(cliente* inicio, int cod);
	//função para verificar se já existe o gestor
int existeGestor(gestor* inicio, int cod);

//FUNÇÕES PARA LISTAR OS DADOS 
	//função para listar os dados do meio de transporte
void listarMeios(meioTransporte* inicio);
	//função para listar os dados do cliente
void listarCliente(cliente* inicio);
	//função para listar os dados do gestor
void listarGestor(gestor* inicio);


//funções para inserir um novo registo
	//função para inserir meio de transporte
meioTransporte* inserirMeio(meioTransporte* inicio, int cod, char tipo[], float bat, float aut, char alug[], char local[]);
	//função para inserir cliente
cliente* inserirCliente(cliente* inicio, int cod, char name[], int numTel, int NIF, char email[]);
	//função para inserir gestor
gestor* inserirGestor(gestor* inicio, int cod, char name[], char pass[]);


//funções para remover determinado tipo de dados
	//função para remover meio de transporte
meioTransporte* removerMeio(meioTransporte* inicio, int cod);
	//função para remover cliente
cliente* removerCliente(cliente* inicio, int cod);
	//função para remover gestor
gestor* removerGestor(gestor* inicio, int cod);

//funções para alterar detemerminado tipo de dados
	//função para alterar meio transporte
meioTransporte* alterarMeio(meioTransporte* inicio, int cod, char tipo[], float bat, float aut, char alug[], char local[]);
	//função para alterar cliente
cliente* alterarCliente(cliente* inicio, int cod, char name[], int numTel, int NIF, char email[]);
//função para alterar gestor
gestor* alterarGestor(gestor* inicio, int cod, char name[], char pass);


//função para registo de aluguer de um determinado meio de mobilidade eletrica
void registoAluguer(meioTransporte* inicio, int cod); 

//ordenar meios de transporte por ordem decrescente de autonomia
meioTransporte* Ordenar(meioTransporte* inicio);
//listagem dos meios de mobilidade elétrica por ordem decrescente de autonomia
void listarMeiosAutonomia(meioTransporte* listagem);

//listagem de meios de mobilidade existentes numa localização com determinado geocódigo
void listarMeiosLocalizacao(meioTransporte* inicio, char local[]); 