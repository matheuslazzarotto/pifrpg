// main.c
#include "rpg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[50];
    int pontuacao;
} Score;

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

int main() {
    srand(time(NULL));
    Score* leaderboard = NULL;
    printStartScreen();
    
    Personagem* heroi = inicializaPersonagem("Herói", 100, 20, 10);
    Personagem* vilao = inicializaPersonagem("Vilão", 80, 15, 8);

    printBarbarianIntro();

    printEnemyEncounter();

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
            Score playerScore;
            strcpy(playerScore.nome, heroi->nome);
            playerScore.pontuacao = heroi->vida;
            addToLeaderboard(&leaderboard, playerScore);
            printf("\n************ LEADERBOARD ************\n");
            displayLeaderboard(leaderboard);
            break;
        }

        atacar(vilao, heroi);

        if (heroi->vida <= 0) {
            printf("%s derrotou %s!\n", vilao->nome, heroi->nome);
            printf("\nInfelizmente, o vilão provou ser forte demais. O Labirinto das Sombras reclama mais uma vítima.\n");
            printf("Seu sacrifício não será esquecido, mas o desafio continua para outros aventureiros.\n");
            break;
        }
    }

    // Liberar a memória alocada para os personagens
    free(heroi);
    free(vilao);
    freeLeaderboard(leaderboard);
    return 0;
}

void addToLeaderboard(Score** leaderboard, Score newScore) {
    Score* newNode = (Score*)malloc(sizeof(Score));
    strcpy(newNode->nome, newScore.nome);
    newNode->pontuacao = newScore.pontuacao;
    newNode->next = NULL;

    if (*leaderboard == NULL) {
        *leaderboard = newNode;
    } else {
        Score* current = *leaderboard;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the leaderboard
void displayLeaderboard(Score* leaderboard) {
    Score* current = leaderboard;
    int position = 1;

    while (current != NULL) {
        printf("%d. %s - Pontuação: %d\n", position, current->nome, current->pontuacao);
        current = current->next;
        position++;
    }
}

// Function to free the memory allocated for the leaderboard
void freeLeaderboard(Score* leaderboard) {
    Score* current = leaderboard;
    Score* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
