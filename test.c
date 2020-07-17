#include "sem.h"
//#include "q.h"


void Prod(int);
void Cons(int);
struct Semaphore *Full; //Consumer
struct Semaphore *Empty;//Producer
//struct q *runQ;
//struct q *runQ;
int prod_thread;
int cons_thread;
int thread_ID;
int main()
{
    int x = 0;
    Full = (struct Semaphore*)malloc(sizeof(struct Semaphore));
    runQ = (struct q *)malloc(sizeof(struct q));
    InitQueue(runQ);
    //InitSem(Full, 0);
    //InitSem(Empty, 0);
    //thread_ID = 1;
    //start_thread(runfunction);
    //thread_ID = 2;
    //start_thread(runfunction);
    thread_ID = 1;
    int type[4]={1,2,-1,-2};
    prod_thread = 1;
    cons_thread = 1;
    while(x < 4){
        if(type[x]>0){
            thread_ID = prod_thread;
            start_thread(Prod);
            prod_thread++;            
            x++;
        }
        else
        {
            thread_ID = cons_thread;
            start_thread(Cons);
            cons_thread++;
            x++;
        }

       
    }

    run();
    return 0; 
}




void Prod(int thread_ID){

    
    printf("\nTesting Prod because this isn't working otherwise. Thread: %d\n", thread_ID);
    yield();

}

void Cons(int thread_ID){

    printf("\nTesting Consumer because this isn't working. Thread: %d\n", thread_ID);
    yield();
}