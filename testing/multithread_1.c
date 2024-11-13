#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void *sum(void *arr){
    int* range = (int*)arr;
    int start = range[0];
    int end = range[1];
    int * sum = (int *)malloc(sizeof(int));
    *sum=0;
    for (int i = start; i <= end; i++) {
        *sum += i;
    }
    printf("The sum is: %d",*sum);
    printf("\n");
    pthread_exit((void *)sum);
}
void *findPrime(void *arr){
    int* range = (int*)arr;
    int start = range[0];
    int end = range[1];
    int * primeCount = (int *)malloc(sizeof(int));
    *primeCount=0;
    for (int i = start; i <= end; i++)
    {
        if(isPrime(i)){
            printf("%d ",i);
            (*primeCount)++;
        }
    }
    printf("\n");
    pthread_exit((void *)primeCount);
}

int main(){
    int start, end;
    printf("enter the ranges \n");
    scanf("%d %d", &start, &end);
    int range[2]={start,end};
    pthread_t thread1, thread2;

    pthread_create(&thread1,NULL,findPrime,range);
    pthread_create(&thread2,NULL,sum,range);

    int *sum, *primeCount;
    pthread_join(thread1,(void**)&primeCount);
    pthread_join(thread2,(void**)&sum);

    printf("The total sum %d", *sum);
    printf("\n");
    printf("The total prime Count: %d",*primeCount);
    printf("\n");
    return 0;
}