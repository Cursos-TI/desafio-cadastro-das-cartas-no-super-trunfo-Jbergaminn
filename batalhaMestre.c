#include <stdio.h>
#include <string.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água (0) e alguns navios (3)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Colocando alguns navios para exemplo
    tabuleiro[2][2] = NAVIO;
    tabuleiro[3][2] = NAVIO;
    tabuleiro[4][2] = NAVIO;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTABULEIRO:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Cria a matriz da habilidade em forma de cone apontando para baixo
void criarMatrizCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int meio = TAM_HABILIDADE / 2;
            matriz[i][j] = (j >= meio - i && j <= meio + i) ? 1 : 0;
        }
    }
}

// Cria a matriz da habilidade em forma de cruz
void criarMatrizCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int meio = TAM_HABILIDADE / 2;
            matriz[i][j] = (i == meio || j == meio) ? 1 : 0;
        }
    }
}

// Cria a matriz da habilidade em forma de octaedro (losango)
void criarMatrizOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = (abs(meio - i) + abs(meio - j) <= meio) ? 1 : 0;
        }
    }
}

// Aplica a matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int matrizHabilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                       int origemLinha, int origemColuna) {
    int offset = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (matrizHabilidade[i][j] == 1) {
                int linha = origemLinha - offset + i;
                int coluna = origemColuna - offset + j;
                // Verifica se está dentro do tabuleiro
                if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                    // Marca com 5 apenas se não for navio
                    if (tabuleiro[linha][coluna] != NAVIO) {
                        tabuleiro[linha][coluna] = HABILIDADE;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);

    // Criar matrizes de habilidades
    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);

    // Aplicar habilidades em diferentes posições do tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);      // Aplica cone no centro de um navio
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // Aplica cruz no meio do tabuleiro
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Aplica octaedro no canto inferior direito

    // Exibir resultado
    exibirTabuleiro(tabuleiro);

    return 0;
}
