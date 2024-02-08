#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <queue>
using namespace std;
#define f(i, n) for (int i = 0; i < n; i++)
typedef struct node {
  int edge;
  int* adj;
  int* val;
  int vis;
} node;
node g[10];
int main() {
  int n = 7,m=9,mst = 0;
  f(i,10) {
    g[i].edge = 0;
    g[i].adj = (int*) malloc(0);
    g[i].vis = 0;
    g[i].val = (int*) malloc(0);
   }
   f(i,m) {
    int u,v,w;
    scanf("%d %d %d", &u,&v,&w);
    g[u].edge++;
    g[u].adj = (int*) realloc(g[u].adj, g[u].edge*sizeof(int));
    g[u].val = (int*) realloc(g[u].val, g[u].edge*sizeof(int));
    g[u].adj[g[u].edge -1] = v;
    g[u].val[g[u].edge -1] = w;
    g[v].edge++;
    g[v].adj = (int*) realloc(g[v].adj, g[v].edge*sizeof(int));
    g[v].val = (int*) realloc(g[v].val, g[v].edge*sizeof(int));
    g[v].adj[g[v].edge -1] = u;
    g[v].val[g[v].edge -1] = w;
   }
   clock_t start = clock();
   int t = 50000;
   while(t--) {
   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
   int currennode = 1; //preselect
   int visnode = 0;
   while(visnode != n) {
      visnode++;
       g[currennode].vis = 1;
        f(i,g[currennode].edge) {
            pq.push({g[currennode].val[i], {currennode,g[currennode].adj[i]}});
        }
        while(!pq.empty()) {
        pair<int,pair<int,int>> top = pq.top();
        pq.pop();
        if(!g[top.second.second].vis) {
          if(t==49999)  printf("%d %d\n", top.second.first, top.second.second);
            currennode = top.second.second;
            mst += top.first;
            break;
        } 
        }
   }
   if(t==49999)  printf("MST == %d\n", mst);
   }
    printf ( "execution time for 50000 executions - %f\n", ( (double)clock() - start ) / (CLOCKS_PER_SEC) );
  return 0;
}