#include <stdio.h>

#define MAX_NOME 100
#define MAX_CODIGO 5

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado;
    char codigo[MAX_CODIGO];
    char nomeCidade[MAX_NOME];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

void exibirCarta(Carta carta, int numero) {
    printf("\n=== Carta %d ===\n", numero + 1);
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área (km²): %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

int main() {
    Carta cartas[2] = {
        {
            'A',
            "A01",
            "São Paulo",
            12300000,
            1521.11,
            2360000.00,
            57
        },
        {
            'B',
            "B02",
            "Rio de Janeiro",
            6748000,
            1182.30,
            321000.00,
            73
        }
    };

    for (int i = 0; i < 2; i++) {
        exibirCarta(cartas[i], i);
    }

    return 0;
}
