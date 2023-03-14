/*****************************************************************//**
 * \file   Funcoes.c
 * \brief  Implementação das Funções
 * 
 * \author João Pereira - a24254
 * \date   March 2023
 *********************************************************************/

#include "Assinaturas.h"

/**
 * Criar novo Jogo
 * 
 * 1º Criar espaço em memoria
 * 2º Inserir dados nesse espeaço
 * 3º Devolver o Jogo
 * 
 * \param cod
 * \param titulo
 * \return 
 */
Jogo* CriaJogo(int c, char* titulo) {
	//1º
	Jogo* aux = (Jogo*)malloc(sizeof(Jogo));

	//2º
	aux->cod = c;
	strcpy(aux->titulo, titulo);
	aux->next = NULL;

	//3º
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
