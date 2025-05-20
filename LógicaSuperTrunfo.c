#include <stdio.h>
#include <string.h>

#define NUM_ATRIBUTOS 5
#define NUM_CARTAS 2

// Estrutura da carta
typedef struct {
    char nome[30];
    int populacao;
    int pib;
    int territorio;
    int idh;
    int densidade;
} Carta;

// Prototipação
void exibirMenuAtributos(int ignorar);
int obterAtributo(char *nomeAtributo);
int compararAtributos(int valor1, int valor2, int atributo);
void exibirResultado(Carta c1, Carta c2, int a1, int a2);

int main() {
    // Cartas pré-cadastradas
    Carta cartas[NUM_CARTAS] = {
        {"Brasil", 213, 22000, 8516, 76, 25},
        {"Canadá", 38, 18000, 9985, 92, 4}
    };

    int atributo1, atributo2;

    printf("Escolha o primeiro atributo para comparar:\n");
    exibirMenuAtributos(-1);
    scanf("%d", &atributo1);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    exibirMenuAtributos(atributo1);
    scanf("%d", &atributo2);

    if (atributo1 == atributo2 || atributo1 < 1 || atributo1 > NUM_ATRIBUTOS || atributo2 < 1 || atributo2 > NUM_ATRIBUTOS) {
        printf("Erro: atributos inválidos ou repetidos.\n");
        return 1;
    }

    exibirResultado(cartas[0], cartas[1], atributo1, atributo2);

    return 0;
}

// Exibe o menu de atributos, omitindo o que já foi escolhido
void exibirMenuAtributos(int ignorar) {
    if (ignorar != 1) printf("1 - Populacao\n");
    if (ignorar != 2) printf("2 - PIB\n");
    if (ignorar != 3) printf("3 - Territorio\n");
    if (ignorar != 4) printf("4 - IDH\n");
    if (ignorar != 5) printf("5 - Densidade Demografica\n");
}

// Retorna o valor do atributo selecionado
int obterAtributoValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.pib;
        case 3: return c.territorio;
        case 4: return c.idh;
        case 5: return c.densidade;
        default: return 0;
    }
}

// Nome do atributo para exibição
char* obterNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "PIB";
        case 3: return "Territorio";
        case 4: return "IDH";
        case 5: return "Densidade";
        default: return "Desconhecido";
    }
}

// Comparação individual entre dois atributos
int compararAtributos(int valor1, int valor2, int atributo) {
    if (atributo == 5) // Densidade Demográfica: menor vence
        return (valor1 < valor2) ? 1 : (valor2 < valor1) ? 2 : 0;
    else
        return (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
}

// Exibe a comparação completa
void exibirResultado(Carta c1, Carta c2, int a1, int a2) {
    int v1_attr1 = obterAtributoValor(c1, a1);
    int v2_attr1 = obterAtributoValor(c2, a1);
    int v1_attr2 = obterAtributoValor(c1, a2);
    int v2_attr2 = obterAtributoValor(c2, a2);

    printf("\n--- Comparando Cartas ---\n");
    printf("Carta 1: %s\n", c1.nome);
    printf("Carta 2: %s\n", c2.nome);

    printf("\nAtributo 1: %s\n", obterNomeAtributo(a1));
    printf("  %s: %d\n", c1.nome, v1_attr1);
    printf("  %s: %d\n", c2.nome, v2_attr1);

    printf("\nAtributo 2: %s\n", obterNomeAtributo(a2));
    printf("  %s: %d\n", c1.nome, v1_attr2);
    printf("  %s: %d\n", c2.nome, v2_attr2);

    int soma1 = v1_attr1 + v1_attr2;
    int soma2 = v2_attr1 + v2_attr2;

    printf("\nSoma dos atributos:\n");
    printf("  %s: %d\n", c1.nome, soma1);
    printf("  %s: %d\n", c2.nome, soma2);

    // Resultado final
    if (soma1 > soma2)
        printf("\nResultado: %s venceu!\n", c1.nome);
    else if (soma2 > soma1)
        printf("\nResultado: %s venceu!\n", c2.nome);
    else
        printf("\nResultado: Empate!\n");
}
