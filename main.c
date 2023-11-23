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
}
 
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
 
// Estrutura para armazenar informações de uma partida
typedef struct {
    char nomeHeroi[50];
    char nomeVilao[50];
    char resultado[50];
} Partida;
 
// Função para imprimir o ranking
void printRanking(Partida ranking[], int tamanho) {
    printf("\n************ RANKING ************\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Partida %d:\n", i + 1);
        printf("Herói: %s\n", ranking[i].nomeHeroi);
        printf("Vilão: %s\n", ranking[i].nomeVilao);
        printf("Resultado: %s\n", ranking[i].resultado);
        printf("------------------------\n");
    }
}
 
int main() {
    srand(time(NULL));
 
    Partida ranking[3];
 
    printStartScreen();
 
    Personagem* heroi = inicializaPersonagem("Herói", 100, 20, 10);
    Personagem* vilao = inicializaPersonagem("Vilão", 80, 15, 8);
 
    printBarbarianIntro();
 
    printEnemyEncounter();
 
    int partidaAtual = 0;
 
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
            printf("\nVocê derrotou o vilão e emergiu vitorioso do Labirinto das Sombras!\n");
            printf("Seu nome ecoará nas lendas, e sua coragem será contada por gerações.\n");
 
            // Atualizar o ranking com os resultados da partida
            sprintf(ranking[partidaAtual].nomeHeroi, "%s", heroi->nome);
            sprintf(ranking[partidaAtual].nomeVilao, "%s", vilao->nome);
            sprintf(ranking[partidaAtual].resultado, "%s derrotou %s", heroi->nome, vilao->nome);
 
            // Imprimir o ranking atualizado
            printRanking(ranking, 3);
 
            // Incrementar o índice da partida atual
            partidaAtual++;
        }
 
        atacar(vilao, heroi);
 
        if (heroi->vida <= 0) {
            printf("%s derrotou %s!\n", vilao->nome, heroi->nome);
            printf("\nInfelizmente, o vilão provou ser forte demais. O Labirinto das Sombras reclama mais uma vítima.\n");
            printf("Seu sacrifício não será esquecido, mas o desafio continua para outros aventureiros.\n");
 
            // Atualizar o ranking com os resultados da partida
            sprintf(ranking[partidaAtual].nomeHeroi, "%s", heroi->nome);
            sprintf(ranking[partidaAtual].nomeVilao, "%s", vilao->nome);
            sprintf(ranking[partidaAtual].resultado, "%s derrotou %s", vilao->nome, heroi->nome);
 
            // Imprimir o ranking atualizado
            printRanking(ranking, 3);
 
            // Incrementar o índice da partida atual
            partidaAtual++;
        }
    }
 
    // Liberar a memória alocada para os personagens
    free(heroi);
    free(vilao);
 
    return 0;
}
 
