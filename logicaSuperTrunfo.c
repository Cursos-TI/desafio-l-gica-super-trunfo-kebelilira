#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "");

    // Dados da Carta 1
    char estado[3], codigo[10], cidade[100];
    int populacao, pontosTuristicos;
    float area, pib;

    // Dados da Carta 2
    char estado2[3], codigo2[10], cidade2[100];
    int populacao2, pontosTuristicos2;
    float area2, pib2;

    // Entrada Carta 1
    printf("---- Carta 1 ----\n");
    printf("- Estado (EX: SP): ");
    scanf(" %2s", estado);
    printf("- Código: ");
    scanf(" %9s", codigo);
    printf("- Cidade: ");
    getchar();
    fgets(cidade, 100, stdin);
    cidade[strcspn(cidade, "\n")] = 0;
    printf("- População: ");
    scanf("%d", &populacao);
    printf("- Área (em Km²): ");
    scanf("%f", &area);
    printf("- PIB (use ponto como separador decimal, ex: 1234.56): ");
    scanf("%f", &pib);
    printf("- Pontos turísticos: ");
    scanf("%d", &pontosTuristicos);

    // Entrada Carta 2
    printf("\n---- Carta 2 ----\n");
    printf("- Estado (EX: SP): ");
    scanf(" %2s", estado2);
    printf("- Código: ");
    scanf(" %9s", codigo2);
    printf("- Cidade: ");
    getchar();
    fgets(cidade2, 100, stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;
    printf("- População: ");
    scanf("%d", &populacao2);
    printf("- Área (em Km²): ");
    scanf("%f", &area2);
    printf("- PIB (use ponto como separador decimal, ex: 1234.56): ");
    scanf("%f", &pib2);
    printf("- Pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos
    float densidade = populacao / area;
    float densidade2 = populacao2 / area2;
    float pibPerCapita = pib / populacao;
    float pibPerCapita2 = pib2 / populacao2;

    // Menu de atributos
    int atributo1, atributo2;
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n6 - PIB per Capita\n");
    printf("\n-- ");
    scanf("%d", &atributo1);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) 
    {
        if (i != atributo1) 
        {
            switch (i) 
            {
                case 1: 
                printf("%d - População\n", i); 
                break;
                case 2: printf("%d - Área\n", i); 
                break;
                case 3: printf("%d - PIB\n", i); 
                break;
                case 4: printf("%d - Pontos Turísticos\n", i); 
                break;
                case 5: printf("%d - Densidade Demográfica\n", i); 
                break;
                case 6: printf("%d - PIB per Capita\n", i);
                        printf("\n-- ") ;
                break;
            }
        }
    }
    scanf("%d", &atributo2);

    // Função de comparação dos atributos
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;

    // Comparação do atributo 1
    switch (atributo1) {
        case 1: valor1_c1 = populacao; valor1_c2 = populacao2; break;
        case 2: valor1_c1 = area; valor1_c2 = area2; break;
        case 3: valor1_c1 = pib; valor1_c2 = pib2; break;
        case 4: valor1_c1 = pontosTuristicos; valor1_c2 = pontosTuristicos2; break;
        case 5: valor1_c1 = densidade; valor1_c2 = densidade2; break;
        case 6: valor1_c1 = pibPerCapita; valor1_c2 = pibPerCapita2; break;
        default: printf("Atributo inválido!\n"); return 1;
    }

    // Comparação do atributo 2
    switch (atributo2) {
        case 1: valor2_c1 = populacao; valor2_c2 = populacao2; break;
        case 2: valor2_c1 = area; valor2_c2 = area2; break;
        case 3: valor2_c1 = pib; valor2_c2 = pib2; break;
        case 4: valor2_c1 = pontosTuristicos; valor2_c2 = pontosTuristicos2; break;
        case 5: valor2_c1 = densidade; valor2_c2 = densidade2; break;
        case 6: valor2_c1 = pibPerCapita; valor2_c2 = pibPerCapita2; break;
        default: printf("Atributo inválido!\n"); return 1;
    }

    // Regra: densidade vence com menor valor
    float soma1 = 0, soma2 = 0;
    soma1 += (atributo1 == 5) ? -valor1_c1 : valor1_c1;
    soma2 += (atributo1 == 5) ? -valor1_c2 : valor1_c2;
    soma1 += (atributo2 == 5) ? -valor2_c1 : valor2_c1;
    soma2 += (atributo2 == 5) ? -valor2_c2 : valor2_c2;

    // Exibição dos resultados
    printf("\n--- Resultado da Comparação ---\n");
    printf("Carta 1 - %s (%s):\n", cidade, estado);
    printf("  Atributo 1: %.2f\n", valor1_c1);
    printf("  Atributo 2: %.2f\n", valor2_c1);
    printf("  Soma: %.2f\n", soma1);

    printf("Carta 2 - %s (%s):\n", cidade2, estado2);
    printf("  Atributo 1: %.2f\n", valor1_c2);
    printf("  Atributo 2: %.2f\n", valor2_c2);
    printf("  Soma: %.2f\n", soma2);

    printf("\nResultado Final: ");
    if (soma1 > soma2) {
        printf("Carta 1 (%s) venceu!\n", cidade);
    } else if (soma2 > soma1) {
        printf("Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}