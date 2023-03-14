/*****************************************************************//**
 * \file   Funcoes.c
 * \brief  Implementa��o das Fun��es
 * 
 * \author Jo�o Pereira - a24254
 * \date   March 2023
 *********************************************************************/

#include "Assinaturas.h"

/**
 * Criar novo Jogo
 * 
 * 1� Criar espa�o em memoria
 * 2� Inserir dados nesse espea�o
 * 3� Devolver o Jogo
 * 
 * \param cod
 * \param titulo
 * \return 
 */
Jogo* CriaJogo(int c, char* titulo) {
	//1�
	Jogo* aux = (Jogo*)malloc(sizeof(Jogo));

	//2�
	aux->cod = c;
	strcpy(aux->titulo, titulo);
	aux->next = NULL;

	//3�
	return aux;
}

/**
 * Lista todos os Jogos
 * 
 * \param i
 */
void MostraTodosJogos(Jogo* head) {
	Jogo* aux = head;     //Inicio da Lista

	while (aux != NULL) {
		printf("Titulo: %s\n", aux->titulo);
		aux = aux->next;
	}
}
