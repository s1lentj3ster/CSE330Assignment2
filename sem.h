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

//struct q runQ;

void InitSem(struct Semaphore *semaphore, int value){
   
    semaphore->value = value;
    //semaphore->semQ->head = NULL;  
    return;
}

void P(struct Semaphore *semaphore){
     //struct TCB_t addQueue;
    //struct q *addEmpty = (struct q*)malloc(sizeof(struct q));
    //InitQueue(addEmpty); 
    if(semaphore->value > 0)
    {
        semaphore->value--;
        return;
    }
    else if(semaphore->value <= 0)
    {

        //addEmpty->head = semaphore->semQ;
        
        struct TCB_t *deleteRunQ;
        deleteRunQ = delQueue(runQ);  //Deleting thread from runQ  
        AddQueue(semaphore->semQ, deleteRunQ); //Adding TCB from runQ to semQ(Rotate)//blocking        
        swapcontext(&(deleteRunQ->context),&(runQ->head->context)); //perform swap of current context with the head of RunQ and start
    }
    //return;



}

void V(struct Semaphore *semaphore){
    //struct TCB_t *deleteSemQ; //Declare Temporary TCB_t item
    //struct q *deleteEmpty = (struct q*)malloc(sizeof(struct q));
    if(semaphore->value > 0){
        semaphore->value++;
        return;
    }
    else if(semaphore->value <= 0)
    {
        struct TCB_t *deleteEmptyTCB;
        //deleteEmpty->head = semaphore->semQ;
        
        deleteEmptyTCB = delQueue(semaphore->semQ);//Deleting head of semQ, getting item in return
        AddQueue(runQ, deleteEmptyTCB); //Adding to runQ
         //Important
    }
        yield();
    //return;
}
#endif