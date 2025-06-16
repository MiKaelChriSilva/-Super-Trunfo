#include <stdio.h>
#include <string.h>

typedef struct {
    char estado;
    char codigo[4]; 
    char nome_cidade[50];
    unsigned long int populacao;
    float area;
    float PIB;
    int pontos_turisticos;
    float densidade;
    float PIB_per_capita;
    float super_poder;
} Carta;

void ler_carta(Carta *carta, int numero_carta) {
    printf("\n=== Dados da Carta %d ===\n", numero_carta);
    
   
    do {
        printf("Estado (A-H): ");
        scanf(" %c", &carta->estado);
        if(carta->estado < 'A' || carta->estado > 'H') {
            printf("Estado inválido! Digite uma letra de A a H.\n");
        }
    } while(carta->estado < 'A' || carta->estado > 'H');
    
    
    printf("Código da carta (%c01-%c04): ", carta->estado, carta->estado);
    scanf("%3s", carta->codigo);
    
   
    printf("Nome da cidade: ");
    scanf(" %49[^\n]", carta->nome_cidade);
    
    
    printf("População: ");
    scanf("%lu", &carta->populacao);
    
 
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    
   
    printf("PIB: ");
    scanf("%f", &carta->PIB);
    
   
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    
    carta->densidade = (carta->area > 0) ? carta->populacao / carta->area : 0;
    carta->PIB_per_capita = (carta->populacao > 0) ? carta->PIB / carta->populacao : 0;
    carta->super_poder = carta->populacao + carta->area + carta->PIB + 
                        carta->pontos_turisticos + carta->PIB_per_capita + 
                        ((carta->densidade > 0) ? (1.0 / carta->densidade) : 0);
}

void exibir_carta(Carta carta, int numero_carta) {
    printf("\n=== Carta %d: %s ===\n", numero_carta, carta.codigo);
    printf("Estado: %c\n", carta.estado);
    printf("Cidade: %s\n", carta.nome_cidade);
    printf("População: %lu habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.PIB);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per capita: %.2f\n", carta.PIB_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
}

void comparar_cartas(Carta c1, Carta c2) {
    printf("\n=== RESULTADOS DA COMPARAÇÃO ===\n");
    printf("Atributo\t\t\tVencedor (1=Carta1, 0=Carta2)\n");
    printf("------------------------------------------------------------\n");
    printf("População\t\t\t%d\n", c1.populacao > c2.populacao);
    printf("Área\t\t\t\t%d\n", c1.area > c2.area);
    printf("PIB\t\t\t\t%d\n", c1.PIB > c2.PIB);
    printf("Pontos Turísticos\t\t%d\n", c1.pontos_turisticos > c2.pontos_turisticos);
    printf("Densidade Populacional\t\t%d\n", c1.densidade < c2.densidade);
    printf("PIB per capita\t\t\t%d\n", c1.PIB_per_capita > c2.PIB_per_capita);
    printf("Super Poder\t\t\t%d\n", c1.super_poder > c2.super_poder);
}

int main() {
    Carta carta1, carta2;
    
    printf("=== SUPER TRUNFO - VERSÃO COMPLETA ===\n");
    printf("Cadastre duas cartas para compará-las!\n\n");
    
    
    ler_carta(&carta1, 1);
    ler_carta(&carta2, 2);
    
   
    printf("\n=== RESUMO DAS CARTAS ===\n");
    exibir_carta(carta1, 1);
    exibir_carta(carta2, 2);
    
   
    comparar_cartas(carta1, carta2);
    
    printf("\nFim do programa. Pressione Enter para sair...");
    getchar();
    getchar(); 
    return 0;
}
