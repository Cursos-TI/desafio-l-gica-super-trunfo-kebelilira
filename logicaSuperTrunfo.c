#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "");

    
    // Declaração das variáveis para a Carta 1
    char estado[3], codigo[10], cidade[100];
    int populacao, pontosTuristicos;
    float area, pib;

    // Declaração das variáveis para a Carta 2
    char estado2[3], codigo2[10], cidade2[100];
    int populacao2, pontosTuristicos2;
    float area2, pib2;

    /*Entrada dos dados da Carta 1*/
    printf("---- Carta 1 ----\n");
    printf("- Insira o estado: ");
    scanf(" %2s", estado);

    printf("- Insira o código: ");
    scanf(" %9s", codigo);

    /*Usei uma forma diferente de pegar os dados para que a formatação
    para que aceite espaços e acentos*/
    printf("- Insira o nome da cidade: ");
    getchar();
    fgets(cidade, 100, stdin);
    cidade[strcspn(cidade, "\n")] = 0;

    printf("- Insira o número da população: ");
    scanf("%lu", &populacao);

    printf("- Insira a área: ");
    scanf("%f", &area);

    printf("- Insira o PIB: ");
    scanf("%f", &pib);

    printf("- Insira a quantidade de pontos turísticos do local: ");
    scanf("%i", &pontosTuristicos);

    /*Entrada dos dados da carta 2*/
    printf("\n---- Carta 2 ----\n");
    printf("- Insira o estado (Ex: SP): ");
    scanf(" %2s", estado2);

    printf("- Insira o código: ");
    scanf(" %9s", codigo2);

    /*Usei uma forma diferente de pegar os dados para que a formatação
    para que aceite espaços e acentos*/
    printf("- Insira o nome da cidade: ");
    getchar();
    fgets(cidade2, 100, stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("- Insira o número da população: ");
    scanf("%lu", &populacao2);

    printf("- Insira a área: ");
    scanf("%f", &area2);

    printf("- Insira o PIB: ");
    scanf("%f", &pib2);

    printf("- Insira a quantidade de pontos turísticos do local: ");
    scanf("%i", &pontosTuristicos2);

    /*Efetuando as divisões para cada dado*/
    float densidade = populacao / area;
    float densidade2 = populacao2 / area2;

    float pibPerCapita = pib / populacao;
    float pibPerCapita2 = pib2 / populacao2;
    
    /*Resultado da Carta 1*/
    printf("\n- Resultados -\n");
    printf("Carta 1:\n");
    printf("Estado: %s\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Cidade: %s\n", cidade);
    printf("População: %lu\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %i\n", pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade);
    printf("PIB per Capita: %.2f reais\n\n", pibPerCapita);

    /*Resultado carta 2*/
    printf("Carta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %i\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n\n", pibPerCapita2);
    
    /* Comparação usando condicionais */
    printf("\n ---Comparação de Cartas (Atributo: PIB per Capita) ----\n");

    if (pibPerCapita > pibPerCapita2) {
        printf("Carta 1 - %s (%s): %.2f\n", cidade, estado, pibPerCapita);
        printf("Carta 2 - %s (%s): %.2f\n", cidade2, estado2, pibPerCapita2);
        printf("Resultado: Carta 1 (%s) venceu!\n", estado);
    } 
    else if (pibPerCapita2 > pibPerCapita) {
        printf("Carta 1 - %s (%s): %.2f\n", cidade, estado, pibPerCapita);
        printf("Carta 2 - %s (%s): %.2f\n", cidade2, estado2, pibPerCapita2);
        printf("Resultado: Carta 2 (%s) venceu!\n", estado2);
    }     
    return 0;
}