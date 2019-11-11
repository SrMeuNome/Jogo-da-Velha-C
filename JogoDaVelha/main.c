#include <stdio.h>
#include <stdlib.h>
#include "../Jogo.h"

int main()
{
    JOGO* jogo;
    jogo = IniciarJogo(3,3);
    PegarJogadores(jogo);
    EscolherSimbolo(jogo);
    char resposta='S';
    char escolha;

    do
    {
        #ifdef WIN32
            system("CLS");
        #else
            system("CLEAR");
        #endif // WINDOWS
        printf("Turno: %d\n", jogo->numeroTurno);
        if(jogo->estado->playerTurno == 1)
        {
            printf("Jogador: %s\n\n", jogo->Jogador1);
        } else if(jogo->estado->playerTurno == 2)
        {
            printf("Jogador: %s\n\n", jogo->Jogador2);
        }
        AtualizarEstado(jogo->estado);
        do
        {
            escolha = PegarValor(jogo->estado, 3, 3);
            if(EstaVazia(jogo->estado, escolha, 3, 3))
            {
                printf("\n\nEsta posicao ja possue valor, tente outra...\n\n");
            }
        }while(EstaVazia(jogo->estado, escolha, 3, 3));
        if(jogo->estado->playerTurno == 1)
        {
            AdicionarValor(jogo->estado,3,3,escolha, jogo->SimboloPlayer1);
            jogo->estado->playerTurno++;
        } else if(jogo->estado->playerTurno == 2)
        {
            AdicionarValor(jogo->estado,3,3,escolha, jogo->SimboloPlayer2);
            jogo->estado->playerTurno--;
        }
        jogo->numeroTurno++;
        /*if(FinalizarJogo(jogo,3,3) == 0)
        {
            printf("Deseja jogar novamente? [S]im/[N]ao: ");
            scanf(" %c", resposta);
            if(resposta!='N')
            {
                jogo = IniciarJogo(3,3);
                PegarJogadores(jogo);
                EscolherSimbolo(jogo);
            }
        }*/
    }while(FinalizarJogo(jogo,3,3)/*resposta!='N'*/);
    return 0;
}
