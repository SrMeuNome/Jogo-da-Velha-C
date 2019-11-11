/*– Jogo: Jogadores, Número de turnos, estado do jogo
(matriz de posições), estado do final de
jogo( vencedor )
– Estado do jogo: matriz de posições e seus
respectivos valores (vazio, X, 0), a vez do jogador;*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jogo.h"

char buffer [200];

void copiarTexto(char* texto_copia, char* texto_original)
{
    int i;
    for(i=0;texto_original[i]!='\0';i++)
    {
        texto_copia[i] = texto_original[i];
    }
    texto_copia[i] = '\0';
};

JOGO* IniciarJogo(int linhas, int colunas)
{
    JOGO* novoJogo = (JOGO*) malloc(sizeof(JOGO));
    novoJogo->estado = CriarEstado();
    IniciarEstado(novoJogo->estado, linhas, colunas);
    novoJogo->numeroTurno = 1;
    novoJogo->estado->playerTurno = 1;
    return novoJogo;
}

void PegarJogadores(JOGO* jogo)
{
    printf("Nome do Jogador 1: ");
    scanf(" %[^\n]", buffer);
    jogo->Jogador1 = (char*) malloc(sizeof(char)*strlen(buffer)+sizeof(char));
    copiarTexto(jogo->Jogador1, buffer);
    printf("\n");
    printf("Nome do Jogador 2: ");
    scanf(" %[^\n]", buffer);
    jogo->Jogador2 = (char*) malloc(sizeof(char)*strlen(buffer)+sizeof(char));
    copiarTexto(jogo->Jogador2, buffer);
}

void EscolherSimbolo(JOGO* jogo)
{
    int escolha;
    do
    {
        printf("\n");
        printf("%s escolha um Simbolo: ", jogo->Jogador1);
        printf("\n");
        printf("1: X");
        printf("\n");
        printf("2: O");
        printf("\n\n");
        scanf("%d", &escolha);
        switch(escolha)
        {
            case 1:
                jogo->SimboloPlayer1 = jogo->estado->X;
                jogo->SimboloPlayer2 = jogo->estado->O;
                break;
            case 2:
                jogo->SimboloPlayer1 = jogo->estado->O;
                jogo->SimboloPlayer2 = jogo->estado->X;
                break;
            default:
                printf("\n");
                printf("Opcao invalida...");
                break;
        }
    } while(escolha>2);
}

int FinalizarJogo(JOGO* jogo, int totalLinha, int totalColuna)
{
    if((Finalizar(jogo->estado, totalLinha, totalColuna) == 'X' && jogo->SimboloPlayer1 == 'X') || (Finalizar(jogo->estado, totalLinha, totalColuna) == 'O' && jogo->SimboloPlayer1 == 'O') && !DeuVelha(jogo->estado, totalLinha, totalColuna))
    {
        #ifdef WIN32
            system("CLS");
        #else
            system("CLEAR");
        #endif // WINDOWS
        printf("\n\n%s GANHOU!!!\n\n",jogo->Jogador1);
        return 0;

    } else if((Finalizar(jogo->estado, totalLinha, totalColuna) == 'O' && jogo->SimboloPlayer2 == 'O') || (Finalizar(jogo->estado, totalLinha, totalColuna) == 'X' && jogo->SimboloPlayer2 == 'X') && !DeuVelha(jogo->estado, totalLinha, totalColuna))
    {
        #ifdef WIN32
            system("CLS");
        #else
            system("CLEAR");
        #endif // WINDOWS
        printf("\n\n%s GANHOU!!!\n\n",jogo->Jogador2);
        return 0;

    } else if(DeuVelha(jogo->estado, totalLinha, totalColuna))
    {
        #ifdef WIN32
            system("CLS");
        #else
            system("CLEAR");
        #endif // WINDOWS
        printf("\n\nDEU VELHA!!!\n\n");
        return 0;
    }
    return 1;
}





