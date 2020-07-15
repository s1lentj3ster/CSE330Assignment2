#include <stdio.h>
#include <string.h>
#include "threads.h"
#include "sem.h"


void Prod(int);
void Cons(int);

struct Semaphore *Full;//Consumer
struct Semaphore *Empty; //Producer


int B,Pr,C,N;  //Buffer, Producers, Consumers, Loops
int global;
int prod_id = 0; //in
int cons_id = 0; //out
int buffer = 0;
int main(){

    struct q runQ;
    InitQueue(&runQ);
    
    Full = malloc(sizeof(Semaphore));
    Empty = malloc(sizeof(Semaphore));
    
    InitSem(Full, 0);
    InitSem(Empty, B);

    //scanf("%d,%d,%d,%d",&B,&Pr,&C,&N);
    int num[100];
    int test;
    int i = 0;
    int k = 0;
    thread_ID = 0;
    
    scanf("%d,%d,%d,%d", &B,&Pr,&C,&N);
    while(scanf("%d", &test) != EOF){
        //printf("\n%d", test);
        num[i] = test;
        i++;
    }
    
    global = N;

    //
    while(k <= i){
        if(num[k] < 0 ){
           // Cons();
           if(cons_id < C){
            cons_id++;
            thread_ID = cons_id;
            start_thread(Cons);
           }
            k++;
            
        }
        else 
        {
            //Prod();
           if(prod_id < Pr){
            
            prod_id++; 
            thread_ID = prod_id;           
            start_thread(Prod);
            
           }
          k++;
           
        }
        
        
    }
    run();   
}


void Prod(int thread_ID){
    int x = 1;
    
        while(x<= global){
    
        P(Empty);
      
        runQ.number = runQ.number + 1;
      
        //printf("\n%d is this real?", global);
     
        printf("\nthis is the %d producer\n", thread_ID);
      
        //printf("\n%d", runQ.number);
        //printf("\n%d stopped. \n", runQ.number);
        V(Full);
        x++; 
        
         }
    
    
    
     
   //yield();
}


void Cons(int thread_ID){
    int y = 1;
    while(y<=global){
        P(Full);
        printf("\nThis is the %d consumer\n", thread_ID);
        
        P(Empty);
        
    }
    
    //yield();
}
