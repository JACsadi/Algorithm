#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <queue>
#define f(i, n) for (int i = 0; i < n; i++)
using namespace std;
int main() {
      FILE* in  = fopen("input.txt", "r+");
      FILE* out = fopen("output.txt", "w+");
      int n = 7;
      int m = 9;
      int* visited = (int*) calloc(n+1,sizeof(int));
    priority_queue< pair<int, pair<int,int> >, vector< pair<int, pair<int,int> > >, greater< pair<int, pair<int,int> > > > pq;
      f(i,m) {
        int u,v,w;
        fscanf(in,"%d %d %d", &u,&v,&w);
        pq.push({w,{u,v}});
      }
      int k = 0;
      int cost = 0;
      while(!pq.empty()) {
        pair<int, pair<int,int>> temp = pq.top();
        pq.pop();
        int w = temp.first;
        pair<int,int> top = temp.second;
        int u = top.first;
        int v = top.second;
        if(!(visited[u]*visited[v])) {
           visited[u] = 1;
           visited[v]=1;
           cost += w;
           fprintf(out,"%d %d\n", u,v);
          k++;
        }
      }
      if(k==n-1) {
        fprintf(out, "The MST formed above costed %d\n", cost);
      }
     fclose(in);
     fclose(out);
     return 0;
}