#ifndef SEM_H
#define SEM_H
#include <stdio.h>
#include <string.h>
#include "threads.h"

struct q runQ;

struct Semaphore{
    int value;
    struct q *head;
};

void InitSem(Semaphore *semaphore, int value);
void P(Semaphore *semaphore);
void V(Semaphore *semaphore);


void InitSem(Semaphore *semaphore, int value){

    semaphore->head = NULL;
    semaphore->value = value;
}

void P(Semaphore *semaphore){

    struct TCB_t *blockSemaphore;
    semaphore->value = semaphore->value - 1;
    if(semaphore->value <= 0)
    {
        
        ucontext_t current;
        blockSemaphore = delQueue(runQ);
        newItem((semaphore->head),blockSemaphore);
        swapcontext(current,&(runQ->head->context));

    }
    //yield();


}

void V(Semaphore *semaphore){

    

    semaphore->value = semaphore->value + 1;

    if(semaphore->value <= 0)
    {
        struct TCB_t *fromSemaphore;
        fromSemaphore = delQueue(semaphore->head);
        addQueue(&runQ, fromSemaphore);

    }

    yield();
}