/** Write a program to calculate the sum of even numbers using 1 thread
    and sum of odd number using another thread
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


pthread_mutex_t mutex_lock;
int shared_data =0;
int sum_even =0;
int sum_odd =0;
int rc;


void even_thread() {

    pthread_mutex_lock(&mutex_lock);

    while(shared_data<=10) {
        if( !(shared_data%2) ) {
            sleep(1);
            sum_even +=shared_data;
            printf("EVEN THREAD %d\n",shared_data);
            shared_data++;
        } else {
            rc=pthread_mutex_unlock(&mutex_lock);
        }
    }
}

void odd_thread() {

    pthread_mutex_lock(&mutex_lock);
    while(shared_data<=10) {
        if(shared_data%2) {
            sleep(1);
            sum_odd +=shared_data;
            printf("ODD THREAD %d\n",shared_data);
            shared_data++;
        } else {
            rc=pthread_mutex_unlock(&mutex_lock);
        }
    }
}


int main() {

    pthread_t even_t, odd_t;

    pthread_create(&even_t,NULL,even_thread,NULL);
    pthread_create(&odd_t,NULL,odd_thread,NULL);

    printf("Sum EVEN %d \n",sum_even);
    printf("Sum ODD %d \n",sum_odd);

    pthread_join(even_t,NULL);
    pthread_join(odd_t,NULL);

    printf("Sum EVEN %d \n",sum_even);
    printf("Sum ODD %d \n",sum_odd);

    return 0;
}


/*** OUTPUT ****

Sum EVEN 0
Sum ODD 0
EVEN THREAD 0
ODD THREAD 1
EVEN THREAD 2
ODD THREAD 3
EVEN THREAD 4
ODD THREAD 5
EVEN THREAD 6
ODD THREAD 7
EVEN THREAD 8
ODD THREAD 9
EVEN THREAD 10
Sum EVEN 30
Sum ODD 25

****/
