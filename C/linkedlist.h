#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ITEM;

typedef struct NODE{
    struct NODE next;
    ITEM item;
}NODE;