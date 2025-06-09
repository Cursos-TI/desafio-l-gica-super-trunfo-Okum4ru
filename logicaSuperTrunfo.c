#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_PAISES 8

typedef struct {
    char nome[30];
    int populacao; // em milhões
    int pib;       // em bilhões de dólares
    int area;      // em mil km²
} Pais;

void exibirPais(Pais p) {
    printf("País: %s\n", p.nome);
    printf("População: %d mi\n", p.populacao);
    printf("PIB: %d bi USD\n", p.pib);
    printf("Área: %d mil km²\n", p.area);
}

int compararAtributo(Pais a, Pais b, int atributo) {
    switch (atributo) {
        case 1: return (a.populacao > b.populacao) ? 1 : (a.populacao < b.populacao) ? -1 : 0;
        case 2: return (a.pib > b.pib) ? 1 : (a.pib < b.pib) ? -1 : 0;
        case 3: return (a.area > b.area) ? 1 : (a.area < b.area) ? -1 : 0;
        default: return 0;
    }
}

int main() {
    srand(time(NULL));

    Pais paises[TOTAL_PAISES] = {
        {"Brasil", 213, 1445, 8516},
        {"EUA", 331, 22940, 9834},
        {"China", 1441, 16862, 9597},
        {"Rússia", 146, 1771, 17098},
        {"Índia", 1390, 3176, 3287},
        {"Alemanha", 83, 4254, 357},
        {"Japão", 125, 4937, 378},
        {"Canadá", 38, 1990, 9985}
    };

    // Embaralhar
    for (int i = 0; i < TOTAL_PAISES; i++) {
        int r = rand() % TOTAL_PAISES;
        Pais temp = paises[i];
        paises[i] = paises[r];
        paises[r] = temp;
    }

    Pais jogador1[4], jogador2[4];
    for (int i = 0; i < 4; i++) {
        jogador1[i] = paises[i];
        jogador2[i] = paises[i + 4];
    }

    int pontos1 = 0, pontos2 = 0;
    for (int i = 0; i < 4; i++) {
        printf("\n--- Rodada %d ---\n", i + 1);
        printf("Jogador 1:\n");
        exibirPais(jogador1[i]);

        int escolha1, escolha2;
        printf("Escolha dois atributos (1 - População, 2 - PIB, 3 - Área)\n");
        printf("Primeiro atributo: ");
        scanf("%d", &escolha1);
        printf("Segundo atributo: ");
        scanf("%d", &escolha2);

        // Verificar se são atributos diferentes
        while (escolha1 == escolha2 || escolha1 < 1 || escolha1 > 3 || escolha2 < 1 || escolha2 > 3) {
            printf("Escolhas inválidas. Selecione dois atributos diferentes entre 1 e 3.\n");
            printf("Primeiro atributo: ");
            scanf("%d", &escolha1);
            printf("Segundo atributo: ");
            scanf("%d", &escolha2);
        }

        printf("Jogador 2:\n");
        exibirPais(jogador2[i]);

        int resultado1 = compararAtributo(jogador1[i], jogador2[i], escolha1);
        int resultado2 = compararAtributo(jogador1[i], jogador2[i], escolha2);

        int vitorias1 = (resultado1 > 0) + (resultado2 > 0);
        int vitorias2 = (resultado1 < 0) + (resultado2 < 0);

        if (vitorias1 > vitorias2) {
            printf("Jogador 1 venceu a rodada!\n");
            pontos1++;
        } else if (vitorias2 > vitorias1) {
            printf("Jogador 2 venceu a rodada!\n");
            pontos2++;
        } else {
            printf("Empate na rodada!\n");
        }
    }

    printf("\n=== Resultado Final ===\n");
    printf("Jogador 1: %d pontos\n", pontos1);
    printf("Jogador 2: %d pontos\n", pontos2);
    if (pontos1 > pontos2)
        printf("🏆 Jogador 1 venceu o jogo!\n");
    else if (pontos2 > pontos1)
        printf("🏆 Jogador 2 venceu o jogo!\n");
    else
        printf("🤝 O jogo terminou empatado!\n");

    return 0;
