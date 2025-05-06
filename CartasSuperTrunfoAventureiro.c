#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular densidade populacional
float calcularDensidade(unsigned long int populacao, float area) {
    if (area == 0) return 0;
    return populacao / area;
}

// Função para calcular PIB per capita
float calcularPIBPerCapita(float pib, unsigned long int populacao) {
    if (populacao == 0) return 0;
    return pib * 1000000 / populacao; // PIB em milhões
}

// Função para ler dados da carta
void lerCarta(Carta *carta) {
    printf("Digite o estado: ");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    carta->estado[strcspn(carta->estado, "\n")] = '\0';

    printf("Digite o codigo: ");
    scanf("%d", &carta->codigo);
    getchar();

    printf("Digite o nome: ");
    fgets(carta->nome, sizeof(carta->nome), stdin);
    carta->nome[strcspn(carta->nome, "\n")] = '\0';

    printf("Digite a populacao: ");
    scanf("%lu", &carta->populacao);
    getchar();

    printf("Digite a area (em km^2): ");
    scanf("%f", &carta->area);
    getchar();

    printf("Digite o PIB (em milhoes): ");
    scanf("%f", &carta->pib);
    getchar();

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta->pontos_turisticos);
    getchar();
}

int main() {
    Carta carta1, carta2;

    printf("Digite os dados da Carta 1:\n");
    lerCarta(&carta1);

    printf("\nDigite os dados da Carta 2:\n");
    lerCarta(&carta2);

    // Calcular atributos derivados
    carta1.densidade_populacional = calcularDensidade(carta1.populacao, carta1.area);
    carta2.densidade_populacional = calcularDensidade(carta2.populacao, carta2.area);

    carta1.pib_per_capita = calcularPIBPerCapita(carta1.pib, carta1.populacao);
    carta2.pib_per_capita = calcularPIBPerCapita(carta2.pib, carta2.populacao);

    // Comparar PIB per capita
    printf("\nComparacao de cartas (Atributo: PIB per capita):\n\n");
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, carta1.pib_per_capita);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, carta2.pib_per_capita);

    if (carta1.pib_per_capita > carta2.pib_per_capita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}

