//Name: Brian Moore
//Class: CSE330 Summer 2020
//Assignment: Project 1
#ifndef TCB_H
#define TCB_H
#include<string.h>
#include <ucontext.h>


typedef struct TCB_t {
struct TCB_t	*next;
struct TCB_t	*prev;
ucontext_t	context;
} TCB_t;	
int thread_ID;



void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size) {
 

    memset(tcb, '\0', sizeof(TCB_t)); // wash, rinse
    getcontext(&tcb->context); // have to get parent context, 
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t) stack_size; 
    makecontext(&tcb->context, function, 1, thread_ID);// context is now cooked

    return;
}
#endif
