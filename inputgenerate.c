#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main() {
    int n = 100000;
    FILE* in  = fopen("input2.txt", "w+");
    srand(time(NULL));
    fprintf(in, "%d ", n);
    while(n--) {
         int r = rand() % 10001; // inputs willhave the range from 0 to 10001
          fprintf(in, "%d ", r);
    }
    fclose(in);
}