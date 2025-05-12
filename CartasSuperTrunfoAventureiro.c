#include <stdio.h>
#include <string.h>

// Definição da estrutura de uma carta com os atributos
typedef struct {
    char nome[50];                   // Nome do país
    int populacao;                   // População total
    float area;                      // Área em km²
    float pib;                       // Produto Interno Bruto em dólares
    int pontosTuristicos;           // Número de pontos turísticos
    float densidadeDemografica;     // Densidade populacional (hab/km²)
} Carta;

int main() {
    // Duas cartas cadastradas manualmente
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 1445000000000.0, 10, 25.0};
    Carta carta2 = {"Japão", 125800000, 377975.0, 5065000000000.0, 12, 333.0};

    int opcao;

    // Menu interativo
    printf("==== SUPER TRUNFO - PAÍSES ====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade demográfica (vence o menor!)\n");
    printf("Digite sua opção (1-5): ");
    scanf("%d", &opcao);

    // Exibe os nomes dos países em comparação
    printf("\nComparando %s e %s...\n", carta1.nome, carta2.nome);

    // Switch com lógica para cada atributo
    switch(opcao) {
        case 1: // População
            printf("População: %d vs %d\n", carta1.populacao, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("%s vence!\n", carta1.nome);
            else if (carta2.populacao > carta1.populacao)
                printf("%s vence!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 2: // Área
            printf("Área: %.2f km² vs %.2f km²\n", carta1.area, carta2.area);
            if (carta1.area > carta2.area)
                printf("%s vence!\n", carta1.nome);
            else if (carta2.area > carta1.area)
                printf("%s vence!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 3: // PIB
            printf("PIB: %.2f USD vs %.2f USD\n", carta1.pib, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("%s vence!\n", carta1.nome);
            else if (carta2.pib > carta1.pib)
                printf("%s vence!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Pontos turísticos: %d vs %d\n", carta1.pontosTuristicos, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("%s vence!\n", carta1.nome);
            else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
                printf("%s vence!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 5: // Densidade demográfica (vence o menor!)
            printf("Densidade demográfica: %.2f hab/km² vs %.2f hab/km²\n", carta1.densidadeDemografica, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica)
                printf("%s vence!\n", carta1.nome);
            else if (carta2.densidadeDemografica < carta1.densidadeDemografica)
                printf("%s vence!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        default: // Opção inválida
            printf("Opção inválida! Por favor, escolha de 1 a 5.\n");
    }

    return 0;
}
