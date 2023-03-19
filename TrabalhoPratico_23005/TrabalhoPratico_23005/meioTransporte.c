/*****************************************************************//**
 * \file   meioTransporte.c
 * 
 * \author Eduardo Queir�s
 * \date   March 2023
 *********************************************************************/

#include <stdlib.h>
#include <string.h>
#include "Header.h"


#pragma warning(disable: 4996)
//Armazenar dados num ficheiro de texto

/**
 *
 * \function name- guardarMeio
 * \params- inicio
 * \brief- guarda os valores inseridos na fun��o inserirMeio, no ficheiro de texto "meios.txt", a fun��o ir� guardar o c�digo do meio,
 *		 o tipo do meio, o estado da bateria, a autonomia do meio(em km), o estado de aluguer, e a sua localiza��o.
 *	
 */
int guardarMeio(meioTransporte* inicio) //meioTransporte* inicio � uma lista ligada
{
	FILE* fp;
	fp = fopen("meios.txt", "w");

	if (fp != NULL)
	{
		meioTransporte* aux = inicio;
		
		while (aux != NULL)
		{
			fprintf(fp, "%d;%s;%.2f;%.2f;%s;%s\n", aux->codigo, aux->tipo, aux->bateria, aux->autonomia, aux->aluguer, aux->localizacao);			
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);
	}
	else return(0);
	
} //verificar se isto est� correto!!!!!

/**
 *
 * \function name- guardarCliente
 * \params- inicio
 * \brief- guarda os valores inseridos na fun��o inserirCLiente, no ficheiro de texto "clientes.txt", ir� guardar o c�digo do cliente,
 *		 o nome do cliente, o n�mero de tel�movel, o nif e o mail do cliente
 */
int guardarCliente(cliente* inicio) //Cliente* inicio de uma lista ligada
{
	FILE* fp;
	fp = fopen("clientes.txt", "w");

	if (fp != NULL)
	{
		cliente* aux2 = inicio;
		while (aux2 != NULL)
		{
			fprintf(fp, "%d;%s;%d;%d;%s", aux2->codigo, aux2->nome, aux2->numTelemovel, aux2->nif, aux2->mail);
			aux2 = aux2->seguinte;
		}
		fclose(fp);
		return(1);
	}
	//ver se o else return deveria estar aqui ou deveria sair
	else return(0);
}

/**
 *
 * \function name- guardarGestor
 * \params- inicio
 * \brief- guarda os valores inseridos na fun��o inserirGestor, no ficheiro de texto "gestores.txt", ir� guardar o c�digo do gestor, 
 *		o nome do gestor e a sua password
 */
int guardarGestor(gestor* inicio) //gestor* inicio de uma lista ligada
{
	FILE* fp;
	fp = fopen("gestores.txt", "w");
	if (fp != NULL)
	{
		gestor* aux3 = inicio;
		while (aux3 != NULL)
		{
			fprintf(fp, "%d;%s;%s", aux3->codigo, aux3->nome, aux3->password);
			aux3 = aux3->seguinte;
		}
		fclose(fp);
		return(1);
	}
	else return(0);
}




//LER DADOS

/**
 *
 * \function name- lerMeio
 * \brief- A fun��o ir� ler o ficheiro de texto "meios.txt"
 *  
 */
meioTransporte*	lerMeio() 
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
			fscanf(fp, "%d;%s;%f;%f;%s;%s\n", &cod,tipo, &bat, &aut,alug,local);
			aux = inserirMeio(aux, cod, tipo, bat, aut, alug, local);
		}
		fclose(fp);
	}
	return(aux);
}

/**
*
* \function name- lerCliente
* \brief- A fun��o ir� ler o ficheiro de texto "clientes.txt"
*  
*/
cliente* lerCliente()
{
	FILE* fp;
	int cod, numTele, NIF;
	char name[50], email[50];
	cliente* aux = NULL;
	fp = fopen("clientes.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%s;%d;%d;%s\n", &cod, name, &numTele, &NIF, email);
			aux = inserirCliente(aux, cod, name, numTele, NIF, email);
		}
		fclose(fp);
	}
	return(aux);
}
	/**
	 *
	 * \function name- lerGestor
	 * \brief- A fun��o ir� ler o ficheiro de texto "gestores.txt"
	 * 
	 * \return 
	 *  
	 */
gestor* lerGestor()
{
	FILE* fp;
	int cod;
	char name[50], pass[50];
	gestor* aux = NULL;
	fp = fopen("gestores.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%s;%s\n", &cod, name, pass);
			aux = inserirGestor(aux, cod, name, pass);
		}
		fclose(fp);
	}
	return(aux);
}

//AS FUN��ES DE "EXISTE", SERVEM PARA VERIFICAR SE O DETERMINADO TIPO EXISTE PARA A FUN��O INSERIR

/**
 *
 * \function name- existeMeio
 * \params- inicio
 * \params- cod
 * \brief- A fun��o verifica se existe determinado meio de transporte atrav�s do c�digo do meio, caso exista a fun��o, atrav�s do 
 *		cliclo "while" indica que esse meio de transporte j� existe
 * 
 * \return- indica se existe, ou n�o, um meio com o mesmo c�digo na lista ligada
 *  
 */
int existeMeio(meioTransporte* inicio, int cod)
{
	while (inicio != NULL)
	{
		if (inicio->codigo == cod) {
			return(1);
		}		
		inicio = inicio->seguinte;
	}
	return(0);
}

/**
 *
 * \function name- existeCliente
 * \params- inicio
 * \params- cod
 * \brief- A fun��o verifica se existe determinado clinte atrav�s do c�digo do cliente, caso exista a fun��o, atrav�s do 
 *		cliclo "while" indica que esse cliente j� existe
 * 
 * \brief-
 * 
 * \return - indica se existe, ou n�o, um cliente com o mesmo c�digo na lista ligada
 *  
 */
int existeCliente(cliente* inicio, int cod)
{
	while (inicio != NULL)
	{
		if (inicio->codigo == cod) {
			return(1);
		}
		inicio = inicio->seguinte;
	}
	return(0);
}

/**
 *
 * \function name- existeGestor
 * \params- inicio
 * \params- cod
 * \brief- A fun��o verifica se existe determinado clinte atrav�s do c�digo do cliente, caso exista a fun��o, atrav�s do 
 *		cliclo "while" indica que esse cliente j� existe
 * 
 * \return- indica se existe, ou n�o, um gestor com o mesmo c�digo na lista ligada
 *  
 */
int existeGestor(gestor* inicio, int cod)
{
	while (inicio != NULL)
	{
		if (inicio->codigo == cod) {
			return(1);
		}
		inicio = inicio->seguinte;
	}
	return(0);
}


//*******************
//A INSER��O EST� DIVIDIDA EM 3 PARTES, uma fun��o para meios de transportes, clientes e gestores

/**
 *
 * \function name- inserirMeio
 * \params- inicio
 * \params- cod
 * \params- tipo
 * \params- bat
 * \params- aut
 * \params- alug
 * \params- local
 * \brief- Insere os dados do c�digo do meio de transporte, o tipo do meio, o estado da bateria, a autonomia, o estado de alugado
 *		e a localiza��o do meio de transporte.
 *		A inser��o � realizada no in�cio da lista ligada
 *		A fun��o devolve como resultado o novo endere�o inicial da lista ligada
 * 
 * \return- Utilizando a fun��o existeMeio, antes de inserirmos os valores, verificamos se existe um meio de transporte com o mesmo c�digo,
 *			de seguida se o apontador da lista ligada for diferente de nulo, insere os dados do meio de transporte	
 *  
 */
meioTransporte* inserirMeio(meioTransporte* inicio, int cod, char tipo[], float bat, float aut, char alug[], char local[])
{

	if (!existeMeio(inicio, cod))
	{
		meioTransporte* novo = malloc(sizeof(struct registo));
		if (novo != NULL)
		{
			novo->codigo = cod;
			strcpy(novo->tipo, tipo);
			novo->bateria = bat;
			novo->autonomia = aut;
			strcpy(novo->aluguer, alug);
			strcpy(novo->localizacao, local);
			novo->seguinte = inicio;
			return(novo);
		}
		
	}
	else return(inicio); // n�o foi poss�vel alocar mem�ria para o novo meio de transporte
}

/**
 *
 * \function name- inserirCliente
 * \params- inicio
 * \params- cod
 * \params- name
 * \params- numTel
 * \params- NIF
 * \params- email
 * \brief- Insere os dados do c�digo cliente, o nome, o n�mero de tel�movel, o nif e o email do cliente
 *		A inser��o � realizada no in�cio da lista ligada
 *		A fun��o devolve como resultado o novo endere�o inicial da lista ligada
 * 
 * \return- Utilizando a fun��o existeCliente, antes de inserirmos os valores, verificamos se existe um cliente com o mesmo c�digo,
 *			de seguida se o apontador da lista ligada for diferente de nulo, insere os dados do cliente
 *  
 */
cliente* inserirCliente(cliente* inicio, int cod, char name[], int numTel, int NIF, char email[])
{
	if (!existeCliente(inicio, cod)) 
	{
		cliente* novo = malloc(sizeof(struct registo2));
		if (novo != NULL)
		{
			novo->codigo = cod;
			strcpy(novo->nome, name);
			novo->numTelemovel = numTel;
			novo->nif = NIF;
			strcpy(novo->mail, email);
			novo->seguinte = inicio;
			return(novo);
		}

	}
	else return(inicio);
}


/**
 *
 * \function name- inserirGestor
 * \params- inicio
 * \params- cod
 * \params- name
 * \params- pass
\brief- Insere os dados do c�digo do gestor, o nome e a sua password
 *		A inser��o � realizada no in�cio da lista ligada
 *		A fun��o devolve como resultado o novo endere�o inicial da lista ligada
 *
 * \return- Utilizando a fun��o existeGestor, antes de inserirmos os valores, verificamos se existe um gestor com o mesmo c�digo,
 *			de seguida se o apontador da lista ligada for diferente de nulo, insere os dados do gestor
 *  
 */
gestor* inserirGestor(gestor* inicio, int cod, char name[], char pass[])
{
	if (!existeGestor(inicio, cod)) 
	{
		gestor* novo = malloc(sizeof(struct registo3));
		if (novo != NULL)
		{
			novo->codigo = cod;
			strcpy(novo->nome, name);
			strcpy(novo->password, pass);
			novo->seguinte = inicio;
			return(novo);
		}
	}
	else return(inicio);
}

/**
 *
 * \function name- listarMeios
 * \params- inicio
 * \brief- A fun��o ir� listar os dados do meio de transporte
 * 
 *  
 */
void listarMeios(meioTransporte* inicio) 
{
	while (inicio != NULL) {
		printf("%d;%s;%f;%f;%s;%s\n", inicio->codigo, inicio->tipo, inicio->bateria, inicio->autonomia, inicio->aluguer, inicio->localizacao);
		inicio = inicio->seguinte;
	}
}

/**
 *
 * \function name- listarCliente
 * \params- inicio
 * \brief- A fun��o ir� listar os dados do cliente
 * 
 *  
 */
void listarCliente(cliente* inicio)
{
	while (inicio != NULL) {
		printf("%d;%s;%d;%d;%s\n", inicio->codigo, inicio->nome, inicio->numTelemovel, inicio->nif, inicio->mail);
		inicio = inicio->seguinte;
	}
}

/**
 *
 * \function name- listarCliente
 * \params- inicio
 * \brief- A fun��o ir� listar os dados do gestor
 * 
 *  
 */
void listarGestor(gestor* inicio)
{
	while (inicio != NULL) {
		printf("%d;%s;%s\n", inicio->codigo, inicio->nome, inicio->password );
		inicio = inicio->seguinte;
	}
}



//A REMO��O DO DIFERENTE TIPO DE DADOS EST� DIVIDIDA EM 3 FUN��ES

/**
 *
 * \function name- removerMeio
 * \params- inicio
 * \params- cod
 * \brief- A fun��o ir� remover os dados do meio de transporte a partir do c�digo do meio de transporte
 * 
 */
meioTransporte* removerMeio(meioTransporte* inicio, int cod)
{
	meioTransporte* anterior = inicio, *atual = inicio, *aux;

	if (atual == NULL) {
		return(NULL);
	}	
	else if (atual->codigo == cod) // remo��o do 1� registo
	{
		aux = atual->seguinte;
		free(atual);
		return(aux);
	}
	else
	{
		while ((atual != NULL) && (atual->codigo != cod))
		{
			anterior = atual;
			atual = atual->seguinte;
		}
		if (atual == NULL) return(inicio);
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			return(inicio);
		}
	}
}


/**
 *
 * \function name- removerCliente
 * \params- inicio
 * \params- cod
 * \brief- A fun��o ir� remover os dados do cliente a partir do c�digo do cliente
 *  
 */
cliente* removerCliente(cliente* inicio, int cod)
{
	cliente* anterior = inicio, *atual = inicio, *aux;

	if (atual == NULL) {
		return(NULL);
	}		
	else if (atual->codigo == cod) // remo��o do 1� registo
	{
		aux = atual->seguinte;
		free(atual);
		return(aux);
	}
	else
	{
		while ((atual != NULL) && (atual->codigo != cod))
		{
			anterior = atual;
			atual = atual->seguinte;
		}
		if (atual == NULL) return(inicio);
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			return(inicio);
		}
	}
}


/**
 *
 * \function name- removerGestor
 * \params- inicio
 * \params- cod
 * \brief- A fun��o ir� remover os dados do gestor a partir do c�digo do gestor
 * 
 */
gestor* removerGestor(gestor* inicio, int cod)
{
	gestor* anterior = inicio, *atual = inicio, *aux;

	if (atual == NULL) {
		return(NULL);
	}
		
	else if (atual->codigo == cod) // remo��o do 1� registo
	{
		aux = atual->seguinte;
		free(atual);
		return(aux);
	}
	else
	{
		while ((atual != NULL) && (atual->codigo != cod))
		{
			anterior = atual;
			atual = atual->seguinte;
		}
		if (atual == NULL) return(inicio);
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			return(inicio);
		}
	}
}

//*****************************************
//Altera��o de determinados dados

/**
 *
 * \function name- alterarMeio
 * \params- inicio
 * \params- cod
 * \params- tipo
 * \params- bat
 * \params- aut
 * \params- alug
 * \params- local
 * \brief- A fun��o ir� alterar os dados do meio de transporte que o utilizador pretende atrav�s do c�digo do meio de transporte
 * 
 * \return-  Para os dados do meio serem alterados, ap�s o utilizador alterar os dados dever� usar a fun��o guardarMeio
 *  
 */
meioTransporte* alterarMeio(meioTransporte* inicio, int cod, char tipo[], float bat, float aut, char alug[], char local[]) 
{

	meioTransporte* atual = inicio;

	while (atual != NULL)
	{
		if (atual->codigo == cod) {
			// atualiza os dados do meio de transporte
			strcpy(atual->tipo, tipo);
			atual->bateria = bat;
			atual->autonomia = aut;
			strcpy(atual->aluguer, alug);
			strcpy(atual->localizacao, local);
			return(atual);
		}
		atual = atual->seguinte;
	}

	// se chegar at� aqui, significa que n�o encontrou um meio de transporte com o c�digo alterado
	return (inicio); // falha na altera��o
}

/**
 *
 * \function name- alterarCliente
 * \params- inicio
 * \params- cod
 * \params- name
 * \params- numTel
 * \params- NIF
 * \params- email
 * \brief- A fun��o ir� alterar os dados do cliente que o utilizador pretender atrav�s do c�digo de cliente
 * 
 * \return- Para os dados do cliente serem alterados, ap�s o utilizador alterar os dados dever� usar a fun��o guardarCLiente
 *  
 */
cliente* alterarCliente(cliente* inicio, int cod, char name[], int numTel, int NIF, char email[])
{
	cliente* atual = inicio;

	while (atual != NULL)
	{
		if (atual->codigo == cod) {
			// atualiza os dados do meio de transporte
			strcpy(atual->nome, name);
			atual->numTelemovel = numTel;
			atual->nif = NIF;
			strcpy(atual->mail, email);
			return (atual); // altera��o realizada com sucesso
		}
		atual = atual->seguinte;
	}

	// se chegar at� aqui, significa que n�o encontrou um meio de transporte com o c�digo alterado
	return (inicio); // falha na altera��o

}

/**
 *
 * \function name- alterarGestor
 * \params- inicio
 * \params- cod
 * \params- name
 * \params- pass
 * \brief- A fun��o ir� alterar os dados do cliente que o utilizador pretender atrav�s do c�digo de cliente
 * 
 * \return-  Para os dados do gestor serem alterados, ap�s o utilizador alterar os dados dever� usar a fun��o guardarGestor
 *  
 */
gestor* alterarGestor(gestor* inicio, int cod, char name[], char pass)
{
	gestor* atual = inicio;
	while (atual != NULL)
	{
		if (atual->codigo == cod) {
			// atualiza os dados do meio de transporte
			strcpy(atual->nome, name);
			strcpy(atual->password, pass);
			return (atual); // altera��o realizada com sucesso
		}
		atual = atual->seguinte;
	}

	// se chegar at� aqui, significa que n�o encontrou um meio de transporte com o c�digo alterado
	return (inicio); // falha na altera��o
}


/**
 *
 * \function name- registoAluguer
 * \params- inicio
 * \params- cod
 * \params- alug
 * \brief- Esta fun��o ir� alterar o estado de aluguer do meio de transporte
 * 
 *  
 */
void registoAluguer(meioTransporte* inicio,int cod ,char alug[])
{
	meioTransporte* aux = inicio;

	while (aux != NULL) 
	{

	}

}

//listagem de meios por ordem decrescente de autonomia
//ir� listar na consola o conte�do da lista ligada

/**
 *
 * \function name- listarMeiosAutonomia
 * \params- inicio
 * \brief- A fun��o ir� listar os meios de transporte por ordem decrescente de autonomia
 * 
 *  
 */

/**
 *
 * \function name- TrocaMeios
 * \params- antesTroca
 * \params- depoisTroca
 * \brief- Esta fun��o ir� realizar a troca dos meios de transporte
 */
void TrocaMeios(meioTransporte** antesTroca, meioTransporte** depoisTroca )
{
	meioTransporte* aux = *antesTroca;
	*antesTroca = *depoisTroca;
	*depoisTroca = aux;

}
/**
 *
 * \function name- listarMeiosAutonomia
 * \params- inicio
 * \brief- Lista os meios de transporte por ordem decrescente de autonomia
 * 
 *  
 */
void listarMeiosAutonomia(meioTransporte* inicio)
{
	int aux = 1;
	meioTransporte* atual = inicio;
	meioTransporte* seguinte = inicio;

	while (aux)
	{
		aux = 0;
		atual = inicio;
		while (atual->seguinte != seguinte)
		{
			if (atual->autonomia < atual->seguinte->autonomia) 
			{
				TrocaMeios(&atual, &(atual->seguinte));
				aux = 1;
			}
			atual = atual->seguinte;
		}
		seguinte = atual;
	}
	listarMeios(inicio);
}



//listagem de meios existentes numa localiza��o com determinado geoc�digo
/**
 *
 * \function name- listarMeiosLocalizacao
 * \params- inicio
 * \params- local
 * \brief- A fun��o ir� permitir a listagem dos meios de transporte que est�o localizados numa determinada localiza��o
 * 
 *  \return- A partir da localiza��o do meio de transporte, se determinado(s) meio(s) de transporte estiver na mesma localiza��o, o programa ir� listar os dados desses(s) meio(s)
 */
void listarMeiosLocalizacao(meioTransporte* inicio, char local[]) 
{
	while (inicio != NULL)
	{
		if(stricmp(inicio->localizacao, local) == 0)
		{
			printf("%d;%s;%f;%f;%s;%s\n", inicio->codigo,inicio->tipo,inicio->bateria,inicio->autonomia,inicio->aluguer,inicio->localizacao);
		}
		inicio = inicio->seguinte;
	}

}