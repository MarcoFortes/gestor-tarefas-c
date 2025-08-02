#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"task_manager.h"

list* createTaskList(){
    return NULL;
}

list* addTask(list* taskList,int p_id,char* p_taskName,char* p_TaskDescription,int p_taskDuratation,enum priority p_TaskPriority){
    taskList = (list*)malloc(sizeof(list));
    if(taskList == NULL){
        printf("Erro ao alocar lista!\n");
        exit(EXIT_FAILURE);
    }

    taskList->taskName = (char*)malloc(strlen(p_taskName)+1); //alocao para o nome da tarefa
    if(taskList->taskName == NULL){
        printf("Erro na alocacao!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(taskList->taskName,p_taskName);

    taskList->taskDescription = (char*)malloc(strlen(p_TaskDescription)+1); //alocacao para a descricao da tarefa
    if(taskList->taskDescription == NULL){
        printf("Erro na alocacao!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(taskList->taskDescription,p_TaskDescription);

    taskList->id = p_id;
    taskList->taskDuration = p_taskDuratation;
    taskList->taskPriority = p_TaskPriority;

    taskList->next = NULL;

    return taskList;
}
