#include <stdio.h>

// Define o tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10 e inicialização com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (linha e coluna)
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 1;

    int i;

    // Validação para o navio horizontal
    if (colunaNavioHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica sobreposição com navio vertical
        int sobreposicao = 0;
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // Se não houver sobreposição, posiciona o navio horizontal
        if (!sobreposicao) {
            for (i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
            }
        } else {
            printf("Erro: sobreposição detectada no navio horizontal.\n");
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
    }

    // Validação para o navio vertical
    if (linhaNavioVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica sobreposição com navio horizontal
        int sobreposicao = 0;
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // Se não houver sobreposição, posiciona o navio vertical
        if (!sobreposicao) {
            for (i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
            }
        } else {
            printf("Erro: sobreposição detectada no navio vertical.\n");
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
    }

    // Exibição do tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
