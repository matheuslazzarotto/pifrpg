// rpg.c
#include "rpg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Personagem* inicializaPersonagem(const char* nome, int vida, int ataque, int defesa) {
    Personagem* novoPersonagem = (Personagem*)malloc(sizeof(Personagem));
    strcpy(novoPersonagem->nome, nome);
    novoPersonagem->vida = vida;
    novoPersonagem->ataque = ataque;
    novoPersonagem->defesa = defesa;
    return novoPersonagem;
}

void atacar(Personagem* atacante, Personagem* defensor) {
    // Gerar um fator aleatório entre 0.8 e 1.2
    double fatorAleatorio = 0.8 + (rand() / (double)RAND_MAX) * 0.4;

    int dano = (int)((atacante->ataque - defensor->defesa) * fatorAleatorio);
    
    if (dano > 0) {
        defensor->vida -= dano;
        printf("%s ataca %s causando %d de dano!\n", atacante->nome, defensor->nome, dano);
    } else {
        printf("%s ataca %s, mas o ataque é bloqueado!\n", atacante->nome, defensor->nome);
    }
}

void defender(Personagem* defensor) {
    // Gerar um fator aleatório entre 0.5 e 1.0
    double fatorAleatorio = 0.5 + (rand() / (double)RAND_MAX) * 0.5;

    int defesa = (int)(defensor->defesa * fatorAleatorio);

    printf("%s se defende, reduzindo o dano em %d!\n", defensor->nome, defesa);

    // Implement counter-attack mechanic
    if (rand() % 100 < 70) {
        printf("%s contra-ataca!\n", defensor->nome);
        atacar(defensor, atacante);
    }
}
