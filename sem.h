#ifndef SEM_H
#define SEM_H
#include <stdio.h>
#include <string.h>
#include "threads.h"



typedef struct SemaphoreQ{
    int value;
<<<<<<< HEAD
    struct q semQ; //For every semaphore, you declare you have to create a new queue semQ;
}SemaphoreQ;
=======
    struct TCB_t *head; //For every semaphore, you declare you have to create a new queue semQ;
}Semaphore;
>>>>>>> 858213112babaa83f15bcbf417838f4dae983aed

void InitSem(SemaphoreQ *semaphore, int value);
void P(SemaphoreQ *semaphore);
void V(SemaphoreQ *semaphore);

struct SemaphoreQ semQ;

void InitSem(SemaphoreQ *semaphore, int value){

    semaphore->value = value;    
    
}

void P(SemaphoreQ *semaphore){

    
    
    
    if(semaphore->value > 0)
    {
<<<<<<< HEAD
        //struct TCB_t *deleteRunQ;
       // deleteRunQ = delQueue(&runQ);  //Deleting thread from runQ
        AddQueue(&semaphore,delQueue(&runQ)); //Adding TCB from runQ to semQ
=======
        semaphore->value--;
        return;
    }
    else if(semaphore->value <= 0)
    {
        struct TCB_t *deleteRunQ;
        deleteRunQ = delQueue(&runQ);  //Deleting thread from runQ
        AddQueue((semaphore->head),deleteRunQ); //Adding TCB from runQ to semQ
        
>>>>>>> 858213112babaa83f15bcbf417838f4dae983aed
        getcontext(&current);  //grabbing current context and storing            
        swapcontext(&current,&(runQ.head->context)); //perform swap of current context with the head of RunQ and start
    }
    



}

void V(SemaphoreQ *semaphore){

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