#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *odd_gen(void *arr)
{
    int *range = (int *)arr;
    int a = range[0];
    int b = range[1];
    int count = 0;
    for (int i = a; i < b; i++)
    {
        if (i % 2 != 0)
        {
            printf("%d \t", i);
            count++;
        }
    }
    printf("\n");

    int *odd_count = (int *)malloc(sizeof(int));
    *odd_count = count;
    pthread_exit((void *)odd_count);
}

void *even_gen(void *arr)
{
    int *range = (int *)arr;
    int a = range[0];
    int b = range[1];
    int count = 0;
    for (int i = a; i < b; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d \t", i);
            count++;
        }
    }
    printf("\n");

    int *even_count = (int *)malloc(sizeof(int));
    *even_count = count;
    pthread_exit((void *)even_count);
}

int main()
{
    int a, b;
    printf("enter the ranges \n");
    scanf("%d %d", &a, &b);
    int arr[2] = {a, b};
    pthread_t odd_thread, even_thread;
    pthread_create(&odd_thread, NULL, odd_gen, arr);
    pthread_create(&even_thread, NULL, even_gen, arr);
    int *odd_count, *even_count;
    pthread_join(odd_thread, (void **)&odd_count);
    pthread_join(even_thread, (void **)&even_count);
    printf("Count of odd numbers: %d\n", *odd_count);
    printf("Count of even numbers: %d\n", *even_count);

    return 0;
}
