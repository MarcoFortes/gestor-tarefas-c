#include"task.h"

int main(){

    TaskList *listaTarefas = createTaskList();

    listaTarefas = createTask(listaTarefas,1, "Estudar", "Estudar POO para a prova", 120, high);
    listaTarefas = createTask(listaTarefas,2, "Exercícios", "Fazer lista de exercícios", 60, medium);
    listaTarefas = createTask(listaTarefas,3, "Revisar", "Revisar código do projeto", 90, low);

    printTaskList(listaTarefas);
    
    freeTaskList(listaTarefas);
    return 0;
}