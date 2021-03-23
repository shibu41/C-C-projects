// This module is for generating random numbers between a specified range.
#include "HandCricket.h"
#include <stdlib.h>
#include <time.h>
int rndnum(int lower, int upper)
{
    int i;
        srand(time(0));
        int num = (rand() % (upper - lower + 1)) + lower;
        return num;
}
