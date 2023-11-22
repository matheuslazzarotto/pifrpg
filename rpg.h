// rpg.h

#ifndef RPG_H
#define RPG_H

// Estrutura para representar um personagem
typedef struct {
    char nome[50];
    int vida;
    int ataque;
    int defesa;
} Personagem;

// Função para inicializar um personagem
Personagem* inicializaPersonagem(const char* nome, int vida, int ataque, int defesa);

// Função para realizar um ataque entre dois personagens com um fator aleatório
void atacar(Personagem* atacante, Personagem* defensor);

// Função para realizar uma ação de defesa com um fator aleatório
void defender(Personagem* defensor);

#endif
