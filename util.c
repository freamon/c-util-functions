/* Utility functions to use in future projects
 * 
 * Andrew Slater */ 

#include "util.h"

/* define MEMORY_CHECK to use these
 * calls to malloc() will go to mc_malloc() and free() to mc_free() */ 
    
/* keep running total of bytes allocated/freed.  
 * Call with '0' to show if any memory remains unfreed at the end */
 void mc_verify(int nbytes)
{
    static int total_bytes;

    total_bytes += nbytes;
    if (nbytes == 0)
        printf("Unfreed bytes: %d\n", total_bytes);
}

/* allocate one more memory slot than requested, store the amount
 * requested in the first slot, and return the address of the
 * second slot */  
void* mc_malloc(int nbytes)
{
#undef malloc    
    void* ptr = malloc(nbytes+sizeof(int));
#define malloc mc_malloc
    
    *((int*)ptr) = nbytes;
    mc_verify(nbytes);
    return ptr+sizeof(int);
}

/* use saved value of bytes allocated for mc_verify to take off
 * the running total, and free all the memory */   
void mc_free(void* ptr)
{
    mc_verify(-(*((int*)(ptr-sizeof(int)))));
    
#undef free
    free(ptr-sizeof(int));
#define free mc_free
} 
