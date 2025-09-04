#include <stdio.h>
#include <string.h>
#include <stdlib.h> // para system() no Windows

// Estrutura para representar uma carta
typedef struct {
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade; // populacao / area
} Carta;

// Exibe menu de atributos (opcionalmente ignorando um)
void exibirMenuAtributos(int ignorar) {
    printf("\nEscolha o atributo para comparar:\n");
    if (ignorar != 1) printf("1 - População\n");
    if (ignorar != 2) printf("2 - Área\n");
    if (ignorar != 3) printf("3 - PIB\n");
    if (ignorar != 4) printf("4 - Pontos Turísticos\n");
    if (ignorar != 5) printf("5 - Densidade Demográfica\n");
    printf("Escolha: ");
}

// Retorna o valor do atributo da carta
float obterValorAtributo(Carta c, int opcao) {
    switch (opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidade;
        default: return 0;
    }
}

// Nome do atributo
const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Inválido";
    }
}

int main() {
    // Cartas pré-cadastradas
    Carta cartas[4] = {
        {"Brasil", 214000000, 8516000.0, 2.0, 50, 0},
        {"Japão", 125000000, 377975.0, 5.0, 100, 0},
        {"EUA", 331000000, 9834000.0, 21.0, 200, 0},
        {"França", 67000000, 551695.0, 3.0, 120, 0}
    };

    // Calcula densidade de cada carta
    for (int i = 0; i < 4; i++) {
        cartas[i].densidade = cartas[i].populacao / cartas[i].area;
    }

    int escolhaC1, escolhaC2;

    // Menu de escolha das cartas
    printf("=== SUPER TRUNFO - ESCOLHA DAS CARTAS ===\n");
    for (int i = 0; i < 4; i++) {
        printf("%d - %s\n", i+1, cartas[i].nome);
    }

    printf("\nEscolha a primeira carta: ");
    scanf("%d", &escolhaC1);

    printf("Escolha a segunda carta (diferente da primeira): ");
    scanf("%d", &escolhaC2);

    // Validação
    if (escolhaC1 < 1 || escolhaC1 > 4 || escolhaC2 < 1 || escolhaC2 > 4 || escolhaC1 == escolhaC2) {
        printf("Escolha inválida! Reinicie o jogo.\n");
        return 1;
    }

    Carta c1 = cartas[escolhaC1 - 1];
    Carta c2 = cartas[escolhaC2 - 1];

    int escolha1, escolha2;

    // Menu para atributos
    exibirMenuAtributos(0);
    scanf("%d", &escolha1);

    exibirMenuAtributos(escolha1);
    scanf("%d", &escolha2);

    // Valores dos atributos
    float valor1C1 = obterValorAtributo(c1, escolha1);
    float valor1C2 = obterValorAtributo(c2, escolha1);
    float valor2C1 = obterValorAtributo(c1, escolha2);
    float valor2C2 = obterValorAtributo(c2, escolha2);

    // Determina vencedor de cada atributo
    int vencedor1 = (escolha1 == 5) ? (valor1C1 < valor1C2 ? 1 : (valor1C2 < valor1C1 ? 2 : 0))
                                    : (valor1C1 > valor1C2 ? 1 : (valor1C2 > valor1C1 ? 2 : 0));
    int vencedor2 = (escolha2 == 5) ? (valor2C1 < valor2C2 ? 1 : (valor2C2 < valor2C1 ? 2 : 0))
                                    : (valor2C1 > valor2C2 ? 1 : (valor2C2 > valor2C1 ? 2 : 0));

    // Soma dos atributos
    float somaC1 = valor1C1 + valor2C1;
    float somaC2 = valor1C2 + valor2C2;

    int vencedorFinal = (somaC1 > somaC2) ? 1 : (somaC2 > somaC1 ? 2 : 0);

    // Exibição do resultado
    printf("\n===== RESULTADO DA RODADA =====\n");
    printf("%s x %s\n\n", c1.nome, c2.nome);

    printf("%s:\n  %.2f vs %.2f -> %s\n", nomeAtributo(escolha1), valor1C1, valor1C2,
           vencedor1 == 1 ? c1.nome : (vencedor1 == 2 ? c2.nome : "Empate"));

    printf("%s:\n  %.2f vs %.2f -> %s\n", nomeAtributo(escolha2), valor2C1, valor2C2,
           vencedor2 == 1 ? c1.nome : (vencedor2 == 2 ? c2.nome : "Empate"));

    printf("\nSoma dos atributos:\n  %s: %.2f | %s: %.2f\n", c1.nome, somaC1, c2.nome, somaC2);

    if (vencedorFinal == 1) printf("\nVencedor final: %s!\n", c1.nome);
    else if (vencedorFinal == 2) printf("\nVencedor final: %s!\n", c2.nome);
    else printf("\nEmpate!\n");

    // Mantém console aberto no Eclipse
    printf("\nPressione ENTER para sair...");
    getchar(); // consome o \n do buffer
    getchar(); // espera ENTER

    return 0;
}
