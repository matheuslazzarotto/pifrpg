// main.c
#include "rpg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    Personagem* heroi = inicializaPersonagem("Herói", 100, 20, 10);
    Personagem* vilao = inicializaPersonagem("Vilão", 80, 15, 8);

    while (heroi->vida > 0 && vilao->vida > 0) {
        int escolha;
        
        printf("Escolha uma ação:\n");
        printf("1. Atacar\n");
        printf("2. Defender\n");
        scanf("%d", &escolha);

        if (escolha == 1) {
            atacar(heroi, vilao);
        } else if (escolha == 2) {
            defender(heroi);
        } else {
            printf("Escolha inválida. Tente novamente.\n");
            continue;
        }

        if (vilao->vida <= 0) {
            printf("%s derrotou %s!\n", heroi->nome, vilao->nome);
            break;
        }

        atacar(vilao, heroi);

        if (heroi->vida <= 0) {
            printf("%s derrotou %s!\n", vilao->nome, heroi->nome);
            break;
        }
    }

    // Liberar a memória alocada para os personagens
    free(heroi);
    free(vilao);

    return 0;
}
