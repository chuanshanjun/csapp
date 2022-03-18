#include <stdlib.h>
#include <stdio.h>

#include "vec.h"

#define IDENT 0
#define OP *

/* Create vector of specified length */
vec_ptr new_vec(long len) {
    /* Allocate header structure */
    vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
    data_t *data = NULL;
    if (!result)
        return NULL; /* Couldn't allocate storage */
    result->len = len;
    /* Allocate array */
    if (len > 0) {
        data = (data_t *) calloc(len, sizeof(data_t));
        if (!data) {
            free((void *)result);
            return NULL; /* Couldn't allocate storage */
        }
    }
    /* Data will either be NULL or allocated array */
    result->data = data;
    return result;
}

/*
 * Retrieve vector element and store at dest
 * Return 0 (out of bounds) or 1 (successful)
 */
int get_vec_element(vec_ptr v, long index, data_t *dest) {
    if (index < 0 || index >= v->len)
        return 0;
    *dest = v->data[index];
    return 1;
}

/* Return length of vector */
long vec_length(vec_ptr v) {
    return v->len;
}

data_t *get_vec_start(vec_ptr v) {
    return v->data;
}

/* Implementation with maximum use of data abstraction */
void combine1(vec_ptr v, data_t *dest) {
    long i;

    *dest = IDENT;

    for (i = 0; i < vec_length(v); i++) {
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OP val;
    }

    printf("after combine1"); 
}

/* Move call to vec_length out of loop */
void combine2(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);

    *dest = IDENT;
    for (i = 0; i < length; i++) {
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OP val;
    }
}

/* Direct access to vector data */
void combine3(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    data_t *data = get_vec_start(v);

    *dest = IDENT;
    for (i = 0; i < length; i++) {
        *dest = *dest OP data[i];
    }
}

void combine3o2(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    data_t *data = get_vec_start(v); 
    data_t acc = IDENT;

    /* Initialize in event length <= 0 */
    *dest = acc;

    for (i = 0; i < length; i++) {
        acc = acc OP data[i];
        *dest = acc;
    }
}

/* Accumulate result in local variable */
void combine4(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    data_t *data = get_vec_start(v);
    data_t acc = IDENT;

    for (i = 0; i < length; i++) {
        acc = acc OP data[i];
    }

    *dest = acc;
}

/* 2 x 1 loop unrolling */
void combine5(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    long limit = length - 1;
    data_t *data = get_vec_start(v);
    data_t acc = IDENT;

    /* Combine 2 elements at a time */
    for (i = 0; i < limit; i+=2) {
        acc = (acc OP data[i]) OP data[i+1];
    }

    /* Finish any remaining elements */
    for (; i < length; i++) {
        acc = acc OP data[i];
    }
    *dest = acc;
}

/* 2 x 2 loop unrolling */
void combine6(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    long limit = length - 1;
    data_t *data = get_vec_start(v);
    data_t acc0 = IDENT;
    data_t acc1 = IDENT;

    /* Combine 2 elements at a time */
    for (i = 0; i < limit; i+=2) {
        acc0 = acc0 OP data[i];
        acc1 = acc1 OP data[i+1];
    }

    /* Finish any remaining elements */
    for (; i < length; i++) {
        acc0 = acc0 OP data[i];
    }
    *dest = acc0 OP acc1;
}

/* 2 x 1a loop unrolling */
void combine7(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    long limit = length - 1;
    data_t *data = get_vec_start(v);
    data_t acc = IDENT;

    /* Combine 2 elements at a time */
    for (i = 0; i < limit; i+=2) {
        acc = acc OP (data[i] OP data[i+1]);
    }

    /* Finish any remaining elements */
    for (; i < length; i++) {
        acc = acc OP data[i];
    }
    *dest = acc;
}

double aprod(double a[], long n) {
    long i;
    double x, y, z;
    double r = 1;
    for (i = 0; i < n-2; i+=3) {
        x = a[i]; y = a[i+1]; z = a[i+2];
        r = r * x * y * z; /* Product computation */ 
    }
    for (; i < n; i++)
        r *= a[i];
    return r;
}

/* 5 x 1 loop unrolling */
void combine5p(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    long limit = length - 4;
    data_t *data = get_vec_start(v);
    data_t acc = IDENT;

    for (i = 0; i < limit; i+=5) {
        acc = (acc OP data[i]) OP data[i+1] OP data[i+2] OP data[i+3] OP data[i+4];
    }

    for (; i < length; i++) {
        acc = acc OP data[i];
    }
    *dest = acc;
}

int main() {
    vec_ptr vec = new_vec(4);

    // 给vec 赋值
    for (int i = 0; i < 4; i++) {
        vec->data[i] = i;
    } 

    for (int i = 0; i < 4; i++) {
        printf("data[%d] = %ld ", i, vec->data[i]);
    }

    printf("\n");

    data_t dest;

    combine1(vec, &dest);

    printf("final val = %ld\n", dest);
}

