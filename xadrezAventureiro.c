#include <stdio.h>

int main() {
    // Movimento da Torre – 5 casas para Direita (usando for)
    printf("Movimento da Torre:\n");
    for (int i = 0; i < 5; i++) {
        printf("Direita\n");
    }

    // Movimento do Bispo – 5 casas na Diagonal Cima Direita (usando while)
    int j = 0;
    printf("\nMovimento do Bispo:\n");
    while (j < 5) {
        printf("Cima Direita\n");
        j++;
    }

    // Movimento da Rainha – 8 casas para Esquerda (usando do-while)
    int k = 0;
    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        k++;
    } while (k < 8);

    // Movimento do Cavalo – 2 Baixo + 1 Esquerda (loops aninhados)
    printf("\nMovimento do Cavalo:\n");

    const int casasBaixo = 2;
    const int casasEsquerda = 1;

    // Primeiro loop: movimenta para baixo (usando for)
    for (int i = 0; i < casasBaixo; i++) {
        printf("Baixo\n");

        // Segundo loop: depois de mover para baixo, movimenta 1 para a esquerda (usando while)
        int movEsquerda = 0;
        while (movEsquerda < casasEsquerda && i == casasBaixo - 1) {
            // Só move para a esquerda após os dois movimentos para baixo
            printf("Esquerda\n");
            movEsquerda++;
        }
    }

    return 0;
}
