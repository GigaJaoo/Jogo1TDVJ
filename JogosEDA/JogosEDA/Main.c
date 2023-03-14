/*****************************************************************//**
 * \file   Main.c
 * \brief  Programa Principal
 * 
 * \author João Pereira - a24254
 * \date   March 2023
 *********************************************************************/

#include "Assinaturas.h"

int main() {
	Jogo* inicio = NULL;    //Inicio da Lista

	//Criar um novo jogo
	Jogo* novo = CriaJogo(1, "GigaJao vs Pilar");

	printf("Jogo: Titulo: %s\n", novo->titulo);

	inicio = novo;
	printf("Inicio da Lista: Titulo: %s\n", inicio->titulo);

	Jogo* outroJogo = CriaJogo(2, "Abogus");
	inicio->next = outroJogo;

	MostraTodosJogos(inicio);

}
