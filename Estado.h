struct estado
{
    char posicao[3][3];
    int playerTurno;
    char X;
    char O;
    char Vazio;
};

typedef struct estado ESTADO;

ESTADO* CriarEstado();

void IniciarEstado(ESTADO* campo, int totalLinhas, int totalColunas);

void AtualizarEstado(ESTADO* campo);

int PegarValor(ESTADO* campo, int totalLinha, int totalColuna);

void AdicionarValor(ESTADO* campo,int totalLinha, int totalColuna, int numeroPosicao, char valor);

int EstaVazia(ESTADO* campo, int k, int totalLinha, int totalColuna);

int DeuVelha(ESTADO* campo, int TotalLinhas, int TotalColunas);

char Finalizar(ESTADO* campo, int totalLinha, int totalColuna);
