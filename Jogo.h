/*– Jogo: Jogadores, Número de turnos, estado do jogo
(matriz de posições), estado do final de
jogo( vencedor )
– Estado do jogo: matriz de posições e seus
respectivos valores (vazio, X, 0), a vez do jogador;*/
#ifndef ESTADO_H_
#define ESTADO_H_

#include "Estado.h"

#endif

struct jogo
{
    char* Jogador1;
    char* Jogador2;
    int numeroTurno;
    ESTADO* estado;
    char* Vencedor;
    char SimboloPlayer1;
    char SimboloPlayer2;
};

typedef struct jogo JOGO;

JOGO* IniciarJogo(int linhas, int colunas);

void PegarJogadores(JOGO* jogo);

void EscolherSimbolo(JOGO* jogo);

int FinalizarJogo(JOGO* jogo, int totalLinha, int totalColuna);
