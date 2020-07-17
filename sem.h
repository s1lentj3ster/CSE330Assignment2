#ifndef SEM_H
#define SEM_H
#include <stdio.h>
#include <string.h>
#include "threads.h"



/*struct Semaphore{
    int value;
    struct q *semQ; //For every semaphore, you declare you have to create a new queue semQ;
};*/
//struct Semaphore semQ;

struct Semaphore{

    struct q *semQ;
    int value;


};

//void InitSem(semQ *semaphore, int value);
//void P(semQ *semaphore);
//void V(semQ *semaphore);

struct q runQ;

void InitSem(struct Semaphore *semaphore, int value){
    semaphore->semQ = (struct q*)malloc(sizeof(struct q));
    InitQueue(semaphore->semQ);
    semaphore->value = value;
    //semaphore->semQ->head = NULL;   
    return;
}

void P(struct Semaphore *semaphore){
    //struct TCB_t addQueue; 
    if(semaphore->value > 0)
    {
        semaphore->value--;
        //return;
    }
    else if(semaphore->value <= 0)
    {

        //ucontext_t current;
        //struct TCB_t *deleteRunQ;
        //deleteRunQ = ;  //Deleting thread from runQ      
        AddQueue(semaphore->semQ, delQueue(&runQ)); //Adding TCB from runQ to semQ(Rotate)//blocking
        //getcontext(&current);
        //grabbing current context and storing            
        swapcontext(&(semaphore->semQ->head->context),&(runQ.head->context)); //perform swap of current context with the head of RunQ and start
    }
    return;



}

void V(struct Semaphore *semaphore){
    struct TCB_t *deleteSemQ; //Declare Temporary TCB_t item
    if(semaphore->value > 0){
        semaphore->value++;
       // return;
    }
    else if(semaphore->value <= 0)
    {
        
        //deleteSemQ = ;//Deleting head of semQ, getting item in return
        AddQueue(&runQ, delQueue((semaphore->semQ))); //Adding to runQ
         //Important
    }
    yield();
    return;
}
#endif