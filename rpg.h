// rpg.h

#ifndef RPG_H
#define RPG_H

typedef struct {
    char nome[50];
    int vida;
    int ataque;
    int defesa;
} Personagem;

Personagem* inicializaPersonagem(const char* nome, int vida, int ataque, int defesa);

void atacar(Personagem* atacante, Personagem* defensor);

void defender(Personagem* defensor);

#endif
