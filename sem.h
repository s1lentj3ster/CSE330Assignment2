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
    semaphore->semQ = (struct q* )malloc(sizeof(struct q));
    InitQueue(semaphore->semQ);
    semaphore->value = value;
    //semaphore->semQ->head = NULL;  
    return;
}

void P(struct Semaphore *semaphore){
    
    
    semaphore->value--;
       
    
    if(semaphore->value <= 0)
    {
        struct TCB_t *deleteRunQ;
        deleteRunQ = delQueue(runQ);  //Deleting thread from runQ  
        AddQueue(semaphore->semQ, deleteRunQ); //Adding TCB from runQ to semQ(Rotate)//blocking        
        swapcontext(&(deleteRunQ->context),&(runQ->head->context)); //perform swap of current context with the head of RunQ and start
    }
  
  }

void V(struct Semaphore *semaphore){
    
  
    semaphore->value++; 
        

    if(semaphore->value <= 0)
    {
      
       if(semaphore->semQ == NULL){
           
           exit(-1);
       }
        struct TCB_t *deleteEmptyTCB;
        deleteEmptyTCB = delQueue(semaphore->semQ);//Deleting head of semQ, getting item in return
        AddQueue(runQ, deleteEmptyTCB); //Adding to runQ
            
    }
    //yield();
    
}
#endif