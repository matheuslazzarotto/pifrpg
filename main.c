// main.c
#include "rpg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printStartScreen() {
    printf("*******************************************\n");
    printf("*          BEM-VINDO AO RPGPIF            *\n");
    printf("*******************************************\n");
    printf("*                                         *\n");
    printf("*  Você, o poderoso bárbaro, está diante  *\n");
    printf("*  do Labirinto das Sombras. Sua aventura *\n");
    printf("*  começa agora!                          *\n");
    printf("*                                         *\n");
    printf("*******************************************\n");

void printBarbarianIntro() {
    printf("\nCom seu machado em mãos e vestindo uma armadura de couro robusta,\n");
    printf("você adentra o sombrio Labirinto das Sombras. A escuridão engole a luz de sua\n");
    printf("tocha, deixando apenas o eco de seus passos reverberando pelas paredes de pedra.\n");
    printf("Seu coração pulsa forte, ansioso pelo desconhecido que aguarda nas profundezas.\n");
}

void printEnemyEncounter() {
    printf("\nSubitamente, olhos amarelos brilham na penumbra, seguidos do rosnado de uma fera.\n");
    printf("Um goblin emerge das sombras, suas presas à mostra e garras prontas para o ataque.\n");
    printf("Você se prepara para o combate, a adrenalina correndo por suas veias.\n");
}
int main() {
    srand(time(NULL));

    printStartScreen();
    
    Personagem* heroi = inicializaPersonagem("Herói", 100, 20, 10);
    Personagem* vilao = inicializaPersonagem("Vilão", 80, 15, 8);

    while (heroi->vida > 0 && vilao->vida > 0) {
        int escolha;

        printf("\n%s (HP: %d) vs %s (HP: %d)\n", heroi->nome, heroi->vida, vilao->nome, vilao->vida);
        
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
