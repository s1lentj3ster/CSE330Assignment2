#include <stdio.h>
#include <string.h>
#include "threads.h"


void Prod(void);
void Cons(void);
//struct semaphore Full; //Consumer
//struct semaphore Empty; //Producer


int B,Pr,C,N;
int global;
int main(){

    //scanf("%d,%d,%d,%d",&B,&Pr,&C,&N);
    int num[100];
    int test;
    int i = 0;
    int k = 0;
    
    scanf("%d,%d,%d,%d", &B,&Pr,&C,&N);
    while(scanf("%d", &test) != EOF){
        //printf("\n%d", test);
        num[i] = test;
        i++;
    }

    while(k < i){
        if(num[k] < 0 ){
            Cons();
            global = num[k];
            start_thread(Cons);
        }
        else
        {
            Prod();
            global = num[k];
            start_thread(Prod);
        }
        k++;
        
    }




    //printf("\n%d\n", i);
    /*printf("\n%d", B);
    printf("\n%d", Pr);
    printf("\n%d", C);
    printf("\n%d", N);*/
    /*while(scanf("%[^\n]%*d", &test)){
        num[i] = test;
        i++;
    }
    

    while(k <= i){
        printf("\n%d", num[k]);
        k++;
    }*/
printf("\n");
return 0;
        
    
    
   
        
   // printf("%d\n", B);
   // printf("%d\n", Pr);
    //printf("%d\n", C);
    //printf("%d\n", N);
    
    


    
}


void Prod(void){
    printf("\nthis is the %d producer", global);
}

void Cons(void){
    printf("\nThis is the %d consumer", global);
}
