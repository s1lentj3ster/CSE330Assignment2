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

typedef struct Semaphore{

    struct q *semQ;
    int value;


}semQ;

//void InitSem(semQ *semaphore, int value);
//void P(semQ *semaphore);
//void V(semQ *semaphore);

struct q runQ;

void InitSem(semQ *semaphore, int value){

    semaphore->value = value;
    semaphore->semQ->head = NULL;   
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
        ucontext_t current;
        
        //struct TCB_t *deleteRunQ;
        //deleteRunQ = ;  //Deleting thread from runQ
        AddQueue(semaphore->semQ, delQueue(&runQ)); //Adding TCB from runQ to semQ(Rotate)
        getcontext(&current);
        //grabbing current context and storing            
        swapcontext(&current,&(runQ.head->context)); //perform swap of current context with the head of RunQ and start
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

        struct TCB_t *deleteSemQ; //Declare Temporary TCB_t item
        deleteSemQ = delQueue(semaphore);//Deleting head of semQ, getting item in return
        AddQueue(&runQ, deleteSemQ); //Adding to runQ
         //Important
    }
    yield();
    
}
#endif