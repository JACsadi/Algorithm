#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define f(i, n) for (int i = 0; i < n; i++)
#define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k))
long long swapcount,comparecount;
int n,k;
void swap(int* arr,int i,int j) {
    swapcount++;
    arr[i] += arr[j];
    arr[j] = arr[i] - arr[j];
    arr[i] -= arr[j];
}
void k_bubble(int* arr) {
   f(i,k) {
    f(j,n-1) {
        comparecount++;
        if(arr[j] > arr[j+1]) swap(arr,j,j+1);
    }
   }
}
int main() {
   time_t start, end;
   FILE* in  = fopen("input3.txt", "r+");
   FILE* out = fopen("output.txt", "w+");
   fscanf(in, "%d", &n);
   k = n;
   ima(arr,int,n);
   f(i,n) fscanf(in, "%d", &arr[i]);
   time(&start);
   k_bubble(arr);
   time(&end);
   f(i,n) fprintf(out, "%d ", arr[i]);
   double timetook = (double)(end - start);
   printf("the input size was %d\n", n);
   printf("it took %lf seconds, it did %lld swap operations and %lld compare operations\n", timetook,swapcount,comparecount);
}
