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

typedef struct q semQ;

//void InitSem(semQ *semaphore, int value);
//void P(semQ *semaphore);
//void V(semQ *semaphore);

struct q runQ;

void InitSem(semQ *semaphore, int value){

    semaphore->value = value;
    //InitQueue(semaphore->semQ);    
}

void P(semQ *semaphore){
    //struct q *semQ;
    // = semaphore;
    if(semaphore->value > 0)
    {
        semaphore->value--;
        return;
    }
    else if(semaphore->value <= 0)
    {
        struct TCB_t *deleteRunQ;
        deleteRunQ = delQueue(&runQ);  //Deleting thread from runQ
        AddQueue(semaphore, deleteRunQ); //Adding TCB from runQ to semQ
        
          //grabbing current context and storing            
        swapcontext(&(runQ.head->prev->context),&(runQ.head->context)); //perform swap of current context with the head of RunQ and start
    }
    



}

void V(semQ *semaphore){
    //struct q semQ;
    if(semaphore->value > 0){
        semaphore->value++;
        return;
    }
    

   else if(semaphore->value <= 0)
    {

        //struct TCB_t *deleteSemQ; //Declare Temporary TCB_t item
        //deleteSemQ = delQueue(semaphore);//Deleting head of semQ, getting item in return
        AddQueue(&runQ, delQueue(semaphore)); //Adding to runQ
       // yield(); //Important
    }
    yield();
    
}
#endif