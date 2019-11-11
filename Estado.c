#include <stdio.h>
#include <stdlib.h>
#ifndef ESTADO_H_
#define ESTADO_H_

#include "Estado.h"

#endif

ESTADO* CriarEstado()
{
   ESTADO* novoEstado = (ESTADO*) malloc(sizeof(ESTADO));
   return novoEstado;
}

void IniciarEstado(ESTADO* campo, int totalLinhas, int totalColunas)
{
    int i, j;
    campo->X = 'X';
    campo->O = 'O';
    campo->Vazio = 32;

    for(i=0;i<totalLinhas;i++)
    {
        for(j=0;j<totalColunas;j++)
        {
            campo->posicao[i][j] = campo->Vazio;
        }

    }
}


void AtualizarEstado(ESTADO* campo)
{

    char horizontal = '|';
    char vertical = '-';


    printf("\n %c %c %c %c %c \n", campo->posicao[0][0], horizontal, campo->posicao[0][1], horizontal, campo->posicao[0][2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c\n", vertical, vertical, vertical, horizontal, vertical, vertical, vertical, horizontal, vertical, vertical, vertical);
    printf(" %c %c %c %c %c \n", campo->posicao[1][0], horizontal, campo->posicao[1][1], horizontal, campo->posicao[1][2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c\n",  vertical, vertical, vertical, horizontal, vertical, vertical, vertical, horizontal, vertical, vertical, vertical);
    printf(" %c %c %c %c %c \n", campo->posicao[2][0], horizontal, campo->posicao[2][1], horizontal, campo->posicao[2][2]);
    printf("\n\n");

}

int PegarValor(ESTADO* campo, int totalLinha, int totalColuna)
{
    int linha;
    int coluna;
    int k;
    do
    {
    scanf("%d,%d", &linha, &coluna);

    if(linha<=0 || coluna<=0 || linha>totalLinha || coluna>totalColuna)
        {
            printf("\n\nEntrada invalida tente novamente...\n\n");
        }
    }while(linha<=0 || coluna<=0 || linha>totalLinha || coluna>totalColuna);
    k = linha*totalColuna+coluna;
    return k;
}

void AdicionarValor(ESTADO* campo,int totalLinha, int totalColuna, int numeroPosicao, char valor)
{
    int linha;
    int coluna;
        linha = (numeroPosicao/totalColuna)-1;
        coluna = (numeroPosicao%totalColuna)-1;
        campo->posicao[linha][coluna] = valor;
}

int EstaVazia(ESTADO* campo, int k, int totalLinha, int totalColuna)
{
    int linha;
    int coluna;

    linha = (k/totalColuna)-1;
    coluna = (k%totalColuna)-1;

    if(campo->posicao[linha][coluna] == 32)
    {
        return 0;
    } else
    {
        return 1;
    }
}

int DeuVelha(ESTADO* campo, int TotalLinhas, int TotalColunas)
{
    int i;
    int j;
    int totalEspaco;
    int EspacoPreenchido=0;

    totalEspaco = TotalLinhas*TotalColunas;

    for(i=0;i<TotalLinhas;i++)
    {
        for(j=0;j<TotalColunas;j++)
        {
            if(campo->posicao[i][j]!=32)
            {
                EspacoPreenchido++;
            }
        }
    }

    if(EspacoPreenchido >= totalEspaco)
    {
        return 1;
    } else
    {
        return 0;
    }
}


char Finalizar(ESTADO* campo, int totalLinha, int totalColuna)
{
    int i;
    int j;
    int quantXH=0;
    int quantOH=0;
    int quantXV=0;
    int quantOV=0;
    int quantXDP=0;
    int quantODP=0;
    int quantXDS=0;
    int quantODS=0;

    for(i=0;i<totalLinha;i++)
    {
        for(j=0;j<totalColuna;j++)
        {

            //Comparar horizontal
            if(campo->posicao[i][j] == campo->X)
            {
                quantXH++;
            }

            if(campo->posicao[i][j] == campo->O)
            {
                quantOH++;
            }

            //Comparar vertical
            if(campo->posicao[j][i] == campo->X)
            {
                quantXV++;
            }

            if(campo->posicao[j][i] == campo->O)
            {
                quantOV++;
            }

            //Comparar diagonal principal
            if(campo->posicao[i][j] == campo->X && i==j)
            {
                quantXDP++;
            }

            if(campo->posicao[i][j] == campo->O && i==j)
            {
                quantODP++;
            }

            //Comparar diagonal secundaria
            if(campo->posicao[i][j] == campo->X && i==totalColuna-j-1)
            {
                quantXDS++;
            }

            if(campo->posicao[i][j] == campo->O && i==totalColuna-j-1)
            {
                quantODS++;
            }
        }
        if(quantXH>=totalColuna || quantXV>=totalColuna)
        {
            return campo->X;
        } else
        {
            quantXH = 0;
            quantXV = 0;
        }

        if(quantOH>=totalColuna || quantOV>=totalColuna)
        {
            return campo->O;
        } else
        {
            quantOH = 0;
            quantOV = 0;
        }
    }
    if(quantODP >= totalColuna || quantODS >= totalColuna)
    {
        return campo->O;
    }

    if(quantXDP >= totalColuna || quantXDS >= totalColuna)
    {
        return campo->X;
    }
    return 32;
}
