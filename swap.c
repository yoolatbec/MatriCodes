#include <stdlib.h>
#include <string.h>

void swapAnyThing(void *, void *, size_t);

void swapAnyThing(void * a, void * b, size_t mem_len){
    void * tmp = malloc(mem_len);
    memcpy(tmp, a, mem_len);
    memcpy(a, b, mem_len);
    memcpy(b, tmp, mem_len);
    free(tmp);
}