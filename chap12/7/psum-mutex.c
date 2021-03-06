#include "young.h"
#define MAXTHREADS 32

void *sum_mutex(void *vargp); /* Thread routine */
void *sum_array(void *vargp);
void *sum_local(void *vargp);

/* Global shared variables */
long gsum = 0; /* Global sum */
long nelems_per_thread; /* Number of elements to sum */
sem_t mutex; /* Mutex to protect global sum */
long psum[MAXTHREADS];

int main(int argc, char **argv) {
    time_t start_t, end_t;
    double diff_t;

    time(&start_t);

    long i, nelems, log_nelems, nthreads, myid[MAXTHREADS];
    pthread_t tid[MAXTHREADS];

    /* Get input arguments */
    if (argc != 3) {
        printf("Usage: %s <nthreads> <log_nelems>\n", argv[0]);
        exit(0);
    }
    nthreads = atoi(argv[1]);
    log_nelems = atoi(argv[2]);
    nelems = (1L << log_nelems);
    nelems_per_thread = nelems / nthreads;
    sem_init(&mutex, 0, 1);

    /* Create peer threads and wait for them to finish */
    for (i = 0; i < nthreads; i++) {
        myid[i] = i;
        // Pthread_create(&tid[i], NULL, sum_mutex, &myid[i]);
        // Pthread_create(&tid[i], NULL, sum_array, &myid[i]);
        Pthread_create(&tid[i], NULL, sum_local, &myid[i]);
    }
    for (i = 0; i < nthreads; i++)
        Pthread_join(tid[i], NULL);

    for (i = 0; i <nthreads ; i++) {
        gsum += psum[i];
    }
    printf("gsum = %lu\n", gsum);

    /* Check final answer */
    if (gsum != (nelems * (nelems - 1))/2) {
        printf("Error: result=%ld\n", gsum);
        exit(1);
    }
        
    time(&end_t);
    diff_t = difftime(end_t, start_t);
    printf("consume time = %f\n", diff_t);

    exit(0);
}

/* Thread routine for psum-mutex.c */
void *sum_mutex(void *vargp) {
    long myid = *((long *)vargp); /* Extract the thead ID */
    long start = myid * nelems_per_thread; /* Start element index */
    long end = start + nelems_per_thread; /* End element index */
    long i;

    for (i = start; i < end; i++) {
        P(&mutex);
        gsum += i;
        V(&mutex);
    }
    return NULL;
}

/* Thread routine for psum-array.c */
void *sum_array(void *vargp) {
    long myid = *((long *)vargp); /* Extract the thread ID */
    long start = myid * nelems_per_thread; /* Start element index */
    long end = start + nelems_per_thread; /* End element index */
    long i;

    for (i = start; i < end; i++) {
        psum[myid] += i;
    }
    return NULL;
}

/* Thread routine for psum-local.c */
void *sum_local(void *vargp) {
    long myid = *((long *) vargp);
    long start = myid * nelems_per_thread; /* Extract the thread ID */
    long end = start + nelems_per_thread; /* End element index */
    long i, sum = 0;

    for (i = start; i < end; i++) {
        sum += i;
    }
    psum[myid] = sum;
}