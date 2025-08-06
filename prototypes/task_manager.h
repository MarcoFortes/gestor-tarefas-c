#ifndef TASK_MANAGER_H_INCLUDED
#define TASK_MANAGER_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum priority{ //Podemos utilizar as prioridades como enums que podem ser usados em termos de comparativos de tarefas com cada um tendo um valor
    //h-high prority, m-medium priotity, l-low priority
    h = 2, m = 1, l = 0
};

typedef struct TaskList{
    int id; //dps pode ser implemento de forma a que cada tarefa adicionada/criada tenha um incremento no valor do ID de forma automatico
    char* taskName;
    char* taskDescription;
    int taskDuration;
    enum priority taskPriority; //durante a criacao/adicao da tarefa e passado seu tipo de prioridade
    struct TaskList* next;
}list;

list* createTaskList();
list* addTask(list *taskList,int p_id,char* p_taskName,char* p_TaskDescription,int p_taskDuratation,enum priority p_TaskPriority);

#endif // TASK_MANAGER_H_INCLUDED
