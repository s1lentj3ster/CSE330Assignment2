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
int flag[2] = {0,0};
int buffer[32]; //global?
int bufferInt = 0; //Remove 0, testing now
int main()
{
    int x = 0;
    
    Full = (struct Semaphore *)malloc(sizeof(struct Semaphore));
    Empty = (struct Semaphore *)malloc(sizeof(struct Semaphore));
    runQ = (struct q *)malloc(sizeof(struct q));
    InitQueue(runQ);
    InitSem(Full, 0);
    InitSem(Empty, 1);
    //thread_ID = 1;
    //start_thread(runfunction);
    //thread_ID = 2;
    //start_thread(runfunction);
    thread_ID = 1;
    int type[4]={1,-1,2,3};
    prod_thread = 1;
    cons_thread = 1;
    //buffer[32] = buffer[2];
   // for(int d = 0; d < 2; d++){
     //   buffer[d] = 0;
   // }
    

    while(x <= 4){
        if(type[x]>0){
            thread_ID = prod_thread;
            start_thread(Prod);
            printf("\nprod %d\n", thread_ID);
            prod_thread++;            
            x++;
        }
        else
        {
            thread_ID = cons_thread;
            start_thread(Cons);
            printf("\ncons %d", thread_ID);
            cons_thread++;
            x++;
        }

       
    }

    run();
    return 0; 
}




void Prod(int thread_ID){
    printf("\nProd %d going into queue\n", thread_ID);
    int prod = 0; //local
    
    while(prod < 3){
        
        P(Empty);
        flag[0] = 0;
        printf("\nprod %d loop %d\n", thread_ID, prod +1 );
        prod++;   
       // printf("\nTesting Prod because this isn't working otherwise. Thread: %d\n", thread_ID);    
        V(Full);
        yield();
    };
   // yield();

}

void Cons(int thread_ID){
    printf("\nConsumer %d is going into the queue\n", thread_ID);
    int cons = 0;
    while(cons < 3){
    P(Full);
    printf("\ncons %d loop %d\n", thread_ID, cons + 1);
    cons++;
    //bufferInt--;
    //if(flag != 1){
        //printf("\nConsumer %d is waiting\n", thread_ID);
        //yield();
   // }
   // printf("\nTesting Consumer because this isn't working. Thread: %d\n", thread_ID);
    V(Empty);
    printf("\nConsumer %d left the queue\n", thread_ID);
    //flag = 0;
    yield();
    }
    
    //yield();
}