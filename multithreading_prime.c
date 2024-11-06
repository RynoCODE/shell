#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdbool.h>

bool is_prime(int num){
    if (num <= 1) 
        return false;
    for (int i = 2; i*i<=num; i++){
        if (num % i == 0) 
            return false;
    }
    return true;
}
void *calculate_sum(void* args){
    int* range = (int*)args;
    int start = range[0];
    int end = range[1];
    int * sum = (int *)malloc(sizeof(int));
    *sum=0;
    for (int i = start; i <= end; i++) {
        *sum += i;
    }
    printf("Sum of numbers from %d to %d: %d\n", start, end, *sum);
    pthread_exit((void*) sum);
}
void * find_prime(void * args){
    int* range = (int*)args;
    int start = range[0];
    int end = range[1];
    int * prime_count = (int *)malloc(sizeof(int));
    *prime_count=0;
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            (*prime_count)++;
        }
    }
    printf("\n");
    pthread_exit((void*)prime_count);
}
int main(){
    int start, end;
    printf("enter the ranges \n");
    scanf("%d %d", &start, &end);
    int range[2]={start,end};
    pthread_t thread1,thread2;

    pthread_create(&thread1,NULL,calculate_sum,range);
    pthread_create(&thread2,NULL,find_prime,range);

    int * sum,*prime_count;
    pthread_join(thread1,(void**)&sum);
    pthread_join(thread2,(void**)&prime_count);

    printf("Total sum: %d\n", *sum);
    printf("Count of prime numbers: %d\n", *prime_count);

    return 0;

    
}