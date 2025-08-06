#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

// modelo para tarefa
typedef struct Tarefa{
    unsigned int id;
    char nome[90];
    char descricao[255];
    int duracao;           // duração em minutos
    char prioridade;       // b = baixa, m = media, a = alta
    struct Tarefa* prox;
}Tarefa;


// modelo para lista
typedef struct Lista{
    Tarefa* tarefa;
    int itens;
} Lista;


// protótipos
Lista* CriarLista();
Tarefa* CriarTarefa();
bool ListaVazia(Lista* l);
void AdicionarNoInicio(Lista* l, Tarefa* t);
void AdicionarNoFinal(Lista* l, Tarefa* t);
void AdicionarEmPosicao(Lista* l, Tarefa* t);

#endif