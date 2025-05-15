#include <stdio.h>

// -------------------- TORRE --------------------
// Movimento recursivo da Torre: Direita
void moverTorre(int casasRestantes) {
    if (casasRestantes == 0) return;

    printf("Direita\n");
    moverTorre(casasRestantes - 1);  // Chamada recursiva
}

// -------------------- RAINHA --------------------
// Movimento recursivo da Rainha: Esquerda
void moverRainha(int casasRestantes) {
    if (casasRestantes == 0) return;

    printf("Esquerda\n");
    moverRainha(casasRestantes - 1);  // Chamada recursiva
}

// -------------------- BISPO --------------------
// Movimento recursivo do Bispo: Cima + Direita
// Loop externo (i): vertical (Cima)
// Loop interno (j): horizontal (Direita)
void moverBispo(int casas) {
    if (casas == 0) return;

    // Simula um passo em diagonal (Cima e Direita)
    for (int i = 0; i < 1; i++) {
        printf("Cima\n");
        for (int j = 0; j < 1; j++) {
            printf("Direita\n");
        }
    }

    moverBispo(casas - 1);  // Chamada recursiva para repetir o padrão
}

// -------------------- CAVALO --------------------
// Movimento em "L": duas casas para cima e uma para a direita
// Usando loops aninhados e controle de fluxo com break/continue
void moverCavalo() {
    const int casasCima = 2;
    const int casasDireita = 1;

    int cima = 0;
    int direita = 0;

    printf("Movimento do Cavalo:\n");

    for (int i = 0; i < 5; i++) {  // Loop externo para simular ações
        // Movimento para cima
        if (cima < casasCima) {
            printf("Cima\n");
            cima++;
            continue;  // Continua até concluir movimento vertical
        }

        // Movimento para direita após concluir as subidas
        for (int j = 0; j < 3; j++) {
            if (direita < casasDireita) {
                printf("Direita\n");
                direita++;
                break;  // Sai do loop após a primeira direita
            }
        }

        break;  // Sai do loop externo após concluir o "L"
    }
}

// -------------------- MAIN --------------------
int main() {
    // Torre: 5 casas para a direita
    printf("Movimento da Torre:\n");
    moverTorre(5);

    // Linha em branco para separar
    printf("\n");

    // Bispo: 4 casas em diagonal (Cima + Direita)
    printf("Movimento do Bispo:\n");
    moverBispo(4);

    // Linha em branco para separar
    printf("\n");

    // Rainha: 6 casas para a esquerda
    printf("Movimento da Rainha:\n");
    moverRainha(6);

    // Linha em branco para separar
    printf("\n");

    // Cavalo: duas casas para cima e uma para a direita
    moverCavalo();

    return 0;
}
