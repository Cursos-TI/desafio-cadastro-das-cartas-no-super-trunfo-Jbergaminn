#include <stdio.h>

#define MAX_NOME 100
#define MAX_CODIGO 5

typedef struct {
    char estado;
    char codigo[MAX_CODIGO];
    char nomeCidade[MAX_NOME];
    int populacao;
    float area;
    float pib; // PIB em milhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

void calcularIndicadores(Carta* carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000) / carta->populacao; // Corrigido!
}

void exibirCarta(Carta carta, int numero) {
    printf("\n=== Carta %d ===\n", numero + 1);
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib / 1000); // Corrigido!
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
}

int main() {
    Carta carta1 = {
        'A', "A01", "São Paulo", 12325000, 1521.11, 699280.00, 50
    };
    Carta carta2 = {
        'B', "B02", "Rio de Janeiro", 6748000, 300500.00, 30
    };

    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    exibirCarta(carta1, 0);
    exibirCarta(carta2, 1);

    return 0;
}
