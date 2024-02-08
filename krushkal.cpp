#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <queue>
#define f(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef struct node {
    int edge;
    int* adj;
} node;

int cycle(node arr[], int* visited, int u, int p) {
    int flag = 1;
    if(visited[u]) return 0;
    visited[u] =1;
    for(int i=0; i< arr[u].edge; i++) if(arr[u].adj[i] != p) {
        flag = cycle(arr,visited,arr[u].adj[i],u);
        if(!flag) break;
    }
    visited[u] = 0;
    return flag;
}
int main() {
      FILE* in  = fopen("input.txt", "r+");
      FILE* out = fopen("output.txt", "w+");
      int n = 7;
      int m = 9;
      node arr[n+1];
      int* visited = (int*) calloc(n+1, sizeof(int));
      f(i,n+1) {
        arr[i].edge = 0;
        arr[i].adj =(int*) malloc(0*sizeof(int));
      }
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
        arr[u].edge++;
        arr[u].adj = (int*) realloc(arr[u].adj, arr[u].edge*sizeof(int));
        arr[u].adj[arr[u].edge-1] = v;
        arr[v].edge++;
        arr[v].adj = (int*) realloc(arr[v].adj, arr[v].edge*sizeof(int));
        arr[v].adj[arr[v].edge-1] = u;
        if(cycle(arr,visited,u,0)) {
           cost += w;
           fprintf(out,"%d %d\n", u,v);
          k++;
        } else {
            arr[u].edge--;
            arr[v].edge--;
            arr[u].adj = (int*) realloc(arr[u].adj, arr[u].edge*sizeof(int));
            arr[v].adj = (int*) realloc(arr[v].adj, arr[v].edge*sizeof(int));
        }
      }
      if(k==n-1) {
        fprintf(out, "The MST formed above costed %d\n", cost);
      } else  fprintf(out, "This doesnt form a MST\n"); 
     fclose(in);
     fclose(out);
     return 0;
}