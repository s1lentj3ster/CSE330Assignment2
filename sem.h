#ifndef SEM_H
#define SEM_H
#include <stdio.h>
#include <string.h>
#include "threads.h"



typedef struct Semaphore{
    int value;
    struct TCB_t *head; //For every semaphore, you declare you have to create a new queue semQ;
}Semaphore;

void InitSem(Semaphore *semaphore, int value);
void P(Semaphore *semaphore);
void V(Semaphore *semaphore);


void InitSem(Semaphore *semaphore, int value){

    semaphore->value = value;
    
    
}

void P(Semaphore *semaphore){

    
    
    
    if(semaphore->value > 0)
    {
        semaphore->value--;
        return;
    }
    else if(semaphore->value <= 0)
    {
        struct TCB_t *deleteRunQ;
        deleteRunQ = delQueue(&runQ);  //Deleting thread from runQ
        AddQueue((semaphore->head),deleteRunQ); //Adding TCB from runQ to semQ
        
        getcontext(&current);  //grabbing current context and storing            
        swapcontext(&current,&(runQ.head->context)); //perform swap of current context with the head of RunQ and start
    }
    



}

void V(Semaphore *semaphore){

    semaphore->value++;

    if(semaphore->value <= 0)
    {
        //struct TCB_t *deleteSemQ; //Declare Temporary TCB_t item
        //deleteSemQ = delQueue(semaphore->semQ);//Deleting head of semQ, getting item in return
        AddQueue(&runQ, delQueue(semaphore->head)); //Adding to runQ
        yield(); //Important
    }

    
}
#endif