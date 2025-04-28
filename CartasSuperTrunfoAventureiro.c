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
    float super_poder;
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

// Função para calcular Super Poder
float calcularSuperPoder(Carta c) {
    // Soma todos os atributos numéricos e o inverso da densidade (quanto menor, melhor)
    float inverso_densidade = (c.densidade_populacional == 0) ? 0 : (1 / c.densidade_populacional);
    return (float)c.populacao + c.area + c.pib + (float)c.pontos_turisticos + c.pib_per_capita + inverso_densidade;
}

// Função para ler dados da carta
// Função para ler dados da carta
void lerCarta(Carta *carta) {
    printf("Digite o estado: ");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    carta->estado[strcspn(carta->estado, "\n")] = '\0'; // Remove newline

    printf("Digite o codigo: ");
    scanf("%d", &carta->codigo);
    getchar(); // Limpa buffer após scanf

    printf("Digite o nome: ");
    fgets(carta->nome, sizeof(carta->nome), stdin);
    carta->nome[strcspn(carta->nome, "\n")] = '\0'; // Remove newline

    printf("Digite a populacao: ");
    scanf("%lu", &carta->populacao);
    getchar(); // Limpa buffer após scanf

    printf("Digite a area (em km^2): ");
    scanf("%f", &carta->area);
    getchar(); // Limpa buffer após scanf

    printf("Digite o PIB (em milhoes): ");
    scanf("%f", &carta->pib);
    getchar(); // Limpa buffer após scanf

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta->pontos_turisticos);
    getchar(); // Limpa buffer após scanf
}

// Função para comparar dois valores e imprimir o vencedor
void compararEApresentar(char *atributo, int resultado) {
    printf("%s: Carta 1 venceu (%d)\n", atributo, resultado);
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

    carta1.super_poder = calcularSuperPoder(carta1);
    carta2.super_poder = calcularSuperPoder(carta2);

    printf("\nComparacao de Cartas:\n\n");

    // Comparações
    compararEApresentar("Populacao", carta1.populacao > carta2.populacao);
    compararEApresentar("Area", carta1.area > carta2.area);
    compararEApresentar("PIB", carta1.pib > carta2.pib);
    compararEApresentar("Pontos Turisticos", carta1.pontos_turisticos > carta2.pontos_turisticos);
    compararEApresentar("Densidade Populacional", carta1.densidade_populacional < carta2.densidade_populacional);
    compararEApresentar("PIB per Capita", carta1.pib_per_capita > carta2.pib_per_capita);
    compararEApresentar("Super Poder", carta1.super_poder > carta2.super_poder);

    return 0;
}
