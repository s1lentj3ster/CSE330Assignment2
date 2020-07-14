#ifndef SEM_H
#define SEM_H
#include <stdio.h>
#include <string.h>
#include "threads.h"



struct Semaphore{
    int value;
    struct q *semQ; //For every semaphore, you declare you have to create a new queue semQ;
};

void InitSem(Semaphore *semaphore, int value);
void P(Semaphore *semaphore);
void V(Semaphore *semaphore);


void InitSem(Semaphore *semaphore, int value){


    semaphore->value = value;
}

void P(Semaphore *semaphore){

    ucontext_t current;
    semaphore->value--;
    
    if(semaphore->value <= 0)
    {
        struct TCB_t *deleteReadyQ;
        deleteReadyQ = delQueue(runQ);  //Deleting thread from runQ
        AddQueue((semaphore->semQ),deleteReadyQ); //Adding TCB from runQ to semQ
        getcontext(&current);              
        swapcontext(&current,&(runQ->head->context)); //perform swap of current context with the head of RunQ and start
        //yield();

    }
    #endif


}

void V(Semaphore *semaphore){

    

    semaphore->value++;

    if(semaphore->value <= 0)
    {
        struct TCB_t *deleteSemQ;
        deleteSemQ = delQueue(semaphore->semQ);//Deleting head of semQ
        AddQueue(runQ, deleteSemQ); //Adding to runQ
        yield();
    }

    
}