#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define NAVIO 3  // valor para representar partes dos navios
#define AGUA 0   // valor para representar água
#define TAMANHO_NAVIO 3

// Função para verificar se uma posição está livre e válida para posicionar um navio
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        if (diagonal) {
            l += (direcao == 1) ? i : -i;
            c += (direcao == 1) ? i : -i;
        } else {
            if (direcao == 0) c += i;      // horizontal
            else l += i;                   // vertical
        }

        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO)
            return 0; // Fora dos limites

        if (tabuleiro[l][c] != AGUA)
            return 0; // Já ocupado
    }
    return 1; // Válido
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        if (diagonal) {
            l += (direcao == 1) ? i : -i;
            c += (direcao == 1) ? i : -i;
        } else {
            if (direcao == 0) c += i;
            else l += i;
        }

        tabuleiro[l][c] = NAVIO;
    }
}

// Função para imprimir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro 10x10:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Tentativa de posicionamento fixo para 4 navios (2 normais + 2 diagonais)

    // 1. Navio Horizontal (linha 0, coluna 0, direcao=0 horizontal)
    if (podePosicionar(tabuleiro, 0, 0, 0, 0))
        posicionarNavio(tabuleiro, 0, 0, 0, 0);

    // 2. Navio Vertical (linha 2, coluna 2, direcao=1 vertical)
    if (podePosicionar(tabuleiro, 2, 2, 1, 0))
        posicionarNavio(tabuleiro, 2, 2, 1, 0);

    // 3. Navio Diagonal Principal (de cima para baixo, esquerda p/ direita)
    if (podePosicionar(tabuleiro, 5, 5, 1, 1))  // linha, coluna, direcao, diagonal=1
        posicionarNavio(tabuleiro, 5, 5, 1, 1);

    // 4. Navio Diagonal Secundária (de baixo para cima, direita p/ esquerda)
    if (podePosicionar(tabuleiro, 7, 2, -1, 1))
        posicionarNavio(tabuleiro, 7, 2, -1, 1);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
