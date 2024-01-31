#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <queue>
#define f(i, n) for (int i = 0; i < n; i++)
#define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k))
using namespace std;
long long swapcount,comparecount;
int n,k;
// void swap(int* arr,int i,int j) {
//     swapcount++;
//     arr[i] += arr[j];
//     arr[j] = arr[i] - arr[j];
//     arr[i] -= arr[j];
// }
// void k_selection(int* arr) {
//    for(int i = n-1; i>= n-k; i--) {
//     for(int j = i-1; j>=0;j--) {
//         comparecount++;
//         if(arr[i] < arr[j]) swap(arr,i,j);
//     }
//    } 
// }
int main() {
   time_t start, end;
   FILE* in  = fopen("input4.txt", "r+");
   FILE* out = fopen("output.txt", "w+");
   fscanf(in, "%d", &n);
   k = n;
   ima(arr,int,n);
   f(i,n) fscanf(in, "%d", &arr[i]);
   time(&start);
   priority_queue<int> pq;
   f(i,n) pq.push(arr[i]);
   time(&end);
   f(i,k) {
    fprintf(out, "%d ", pq.top());
    pq.pop();
    }
   double timetook = (double)(end - start);
   printf("the input size was %d\n", n);
   printf("it took %lf seconds, it did --- swap operations and --- compare operations\n", timetook);
}
