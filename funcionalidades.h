#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H
#include "../Fila de Clientes/includes.h"

// funcionalidades

// cria a lista
Lista* CriarLista(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (lista == NULL){
        printf(" Sem espaço para criar lista\n");
        return NULL;
    }

    lista->itens = 0;
    lista->tarefa = NULL;

    return lista;
}

// cria uma tarefa
Tarefa* CriarTarefa(){
    Tarefa* T = (Tarefa*) malloc(sizeof(Tarefa));
     if (T == NULL){
        printf(" Sem espaço para tarefa\n");
        return NULL;
    }

    // id
    printf(" Digite ID da Tarefa: ");
    scanf("%d", &T->id);

    // nome
    printf(" Digite Nome da Tarefa: ");
    fgets(T->nome, sizeof(T->nome), stdin);

    // descrição
    printf(" Descrição da Tarefa: ");
    fgets(T->descricao, sizeof(T->descricao), stdin);

    // duração
    printf(" Digite a Duração da Tarefa (min): ");
    scanf("%d", &T->duracao);

    // prioridade
    printf(" Digite a Prioridade da Tarefa: ");
    scanf(" %c", &T->prioridade);

    T->prox = NULL;

    return T;
}

// tarefa no início
void AdicionarNoInicio(Lista* l, Tarefa* t){
    if (ListaVazia(l)){
        l->tarefa = t;
        t->prox = NULL;
    } else {
        t->prox = l->tarefa;
        l->tarefa = t;  
    }

    l->itens++;
}

// tarefa no final
void AdicionarNoFinal(Lista* l, Tarefa* t){
    if (ListaVazia(l)){
        l->tarefa = t;
        t->prox = NULL;
    } else {
        Tarefa* atual;
        atual = l->tarefa;
        while (atual->prox != NULL){
            atual = atual->prox;
        }

        atual->prox = t;
        t->prox = NULL;
    }

    l->itens++;
}

// tarefa em posição especifica
void AdicionarEmPosicao(Lista* l, Tarefa* t){
    
}


bool ListaVazia(Lista* l){
    return (l->tarefa == NULL);
}

#endif
