#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <time.h>

#define TIMER_START clock_t _start = clock()
#define TIMER_STOP printf("Timer: %fs\n", (double)(clock() - _start) / CLOCKS_PER_SEC)