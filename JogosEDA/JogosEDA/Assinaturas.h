/*****************************************************************//**
 * \file   Assinaturas.h
 * \brief  Assinaturas das Fun��es e Structs
 * 
 * \author Jo�o Pereira - a24254
 * \date   March 2023
 *********************************************************************/

#define N 20
#include <stdlib.h>
#include <stdio.h>

/**
 * Estrutura do Jogo.
 */
typedef struct Jogo {
	int cod;
	char titulo[N];
	struct Jogo* next;
}Jogo, *JogoPtr;      //Jogo* p == JogoPtr q


Jogo* CriaJogo(int cod, char* titulo);  //char* titulo == char titulo[]

void MostraTodosJogos(Jogo* i);

Jogo* InsereJogoLista(Jogo* head, Jogo* novo);
