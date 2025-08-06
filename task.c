#include"task.h"

TaskList *createTaskList(){
    return NULL;
}

TaskList *createTask(TaskList* list, int TaskId, char *TaskName, char* TaskDescription,int TaskDuration, Priority TaskPriority){

    //validação de dados não nulos
    if (!TaskName || !TaskDescription || TaskDuration < 0) {
        printf("ERRO: Parametro invalidos\n");
        return NULL;
    }

    TaskList* newTask = (TaskList*)malloc(sizeof(TaskList));
    if (newTask == NULL) {
        printf("ERRO: nao foi possivel alocar tarefa!\n");
        return NULL;
    }

    newTask->taskName = (char*)malloc(strlen(TaskName)+1);
    if (newTask->taskName == NULL){
        printf("ERRO: nao foi possivel faze alocacao!\n");
        free(newTask->taskName);
        free(newTask);
        return NULL;
    }
    strcpy(newTask->taskName, TaskName);


    newTask->taskDescription = (char*)malloc(strlen(TaskDescription)+1);
    if (newTask->taskDescription == NULL){
        printf("ERRO: nao foi possivel faze alocacao!\n");
        free(newTask->taskDescription);
        free(newTask);
        return NULL;
    }
    
    strcpy(newTask->taskDescription, TaskDescription);
    
    newTask->id = TaskId;
    newTask->taskDuration = TaskDuration;
    newTask->taskPriority = TaskPriority;


    newTask->nextTask = list;

    return newTask;
}

void printTaskList(TaskList *list) {
    printf("\n=== LISTA DE TAREFAS ===\n");
    while (list != NULL) {
        const char *priorityStr; //ponteiro para uma string constante que armazenará a representação textual da prioridade.
        switch(list->taskPriority) {
            case high: priorityStr = "Alta"; break;
            case medium: priorityStr = "Media"; break;
            case low: priorityStr = "Baixa"; break;
            default: priorityStr = "Desconhecida";
        }
        
        printf("[%d] %s\n", list->id, list->taskName);
        printf("   Descricao: %s\n", list->taskDescription);
        printf("   Duracao: %d minutos\n", list->taskDuration);
        printf("   Prioridade: %s\n\n", priorityStr);
        
        list = list->nextTask;
    }
    printf("=== FIM DA LISTA ===\n");
}

void freeTaskList(TaskList *list) {
    while (list != NULL) {
        TaskList *next = list->nextTask;
        free(list->taskName);
        free(list->taskDescription);
        free(list);
        list = next;
    }
}