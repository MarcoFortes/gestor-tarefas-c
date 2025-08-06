#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief Níveis de prioridade para as tarefas
 * @details Define os três níveis de prioridade disponíveis:
 * - high = 2 (Prioridade alta)
 * - medium = 1 (Prioridade média)
 * - low = 0 (Prioridade baixa)
 */
typedef enum {
    high = 2,
    medium = 1,
    low = 0
}Priority;

/**
 * @brief Estrutura que representa um nó da lista de tarefas
 * @details Contém:
 * - Identificador único (id)
 * - Nome e descrição da tarefa (alocados dinamicamente)
 * - Duração em minutos
 * - Nível de prioridade
 * - Ponteiro para o próximo elemento da lista
 */
typedef struct task{
    int id;
    char *taskName;
    char *taskDescription;
    int taskDuration;
    Priority taskPriority;
    struct task *nextTask;
}TaskList;

/**
 * @brief Inicializa uma lista vazia de tarefas
 * @return Retorna NULL indicando uma lista vazia
 * @note A lista deve ser liberada com freeTaskList()
 */
TaskList *createTaskList();

/**
 * @brief Cria uma nova tarefa e faz inserção no inicio da lista
 * @param list Ponteiro para o início da lista 
 * @param TaskId ID da tarefa
 * @param TaskName Nome da tarefa (string alocada dinamicamente)
 * @param TaskDescription Descrição da tarefa (string alocada dinamicamente)
 * @param TaskDuration Duração em minutos (>= 0)
 * @param TaskPriority Prioridade da tarefa (high/medium/low)
 * @return Ponteiro para o novo início da lista 
 * @warning O chamador deve garantir que TaskName e TaskDescription são strings válidas
 * @note A memória alocada será liberada por freeTaskList()
 */
TaskList *createTask(TaskList* list, int TaskId, char *TaskName, char* TaskDescription,int TaskDuration, Priority TaskPriority);

/**
 * @brief Imprime todas as tarefas da lista 
 * @param list Ponteiro para o primeiro elemento da lista
 * @note Se list for NULL, não imprime nada
 */
void printTaskList(TaskList *list);

/**
 * @brief Libera toda a memória alocada para a lista
 * @param list Ponteiro para o início da lista
 * @note É seguro chamar com list=NULL
 * @post Após a chamada, o ponteiro list não deve ser mais utilizado
 */
void freeTaskList(TaskList *list);
#endif