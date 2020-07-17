//Name: Brian Moore
//Class: CSE330 Summer 2020
//Assignment: Project 1
#ifndef THREADS_H
#define THREADS_H
#include "q.h"




struct q *runQ;

void start_thread(void (*function)(int));
void run();
void yield();


void start_thread(void (*function)(int))
{ 
    // begin pseudo code
    //allocate a stack (via malloc) of a certain size (choose 8192)
    void *newStack = (void *)malloc(8192);
    TCB_t *newTCB_t = newItem(); //allocate a TCB (via malloc)    
    init_TCB(newTCB_t,function,newStack,8192); //call init_TCB with appropriate arguments 
    AddQueue(runQ,newTCB_t);//call addQ to add this TCB into the “RunQ” which is a global header pointer
    

//end pseudo code

}


void run()
{	// real code
    ucontext_t parent;// get a place to store the main context, for faking
    getcontext(&parent);	// magic sauce
    swapcontext(&parent, &(runQ->head->context));	// start the first thread
}



void yield() // similar to run

{
    ucontext_t previous;
    getcontext(&previous);
    rotateQueue(runQ);
    swapcontext(&(runQ->head->prev->context), &(runQ->head->context));
//rotate the run Q;
//swap the context, from previous thread to the thread pointed to by RunQ

}
#endif
