#ifndef UTIL_H
    
#define UTIL_H

#include <stdio.h> 
#include <stdlib.h>

#define MEMORY_CHECK

void mc_verify(int nbytes);
void* mc_malloc(int nbytes);
void mc_free(void* ptr);

#ifdef MEMORY_CHECK
    #define malloc mc_malloc
    #define free mc_free
#endif

#endif
