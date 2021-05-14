#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void my_thread_func() {
    sleep(1);
    printf("Inside thread!!\n");

}


int main() {

    pthread_t thread_id;

    printf("Before thread!!\n");
    pthread_create(&thread_id,NULL,my_thread_func,NULL );
    pthread_join(thread_id,NULL);

    printf("After thread !\n");

    return 0;
}
