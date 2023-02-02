#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
#include <cmath>
#include <algorithm>
#define INF 987654321

using namespace std;

int V, E, start;
vector<pair<int,int>> node[20005];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int value[20005];


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
   
    cin >> V >> E >> start;
    
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        node[u].push_back(make_pair(v, w));
    }
    
    for (int i = 1; i <= V; ++i) value[i] = INF;
    
    value[start] = 0;
    
    pq.push(make_pair(0, start));
    
    while (!pq.empty()) {
        int x = pq.top().first; // the distance between adjacent nodes
        int U = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < node[U].size(); ++i) { // iterate all edges from node U
            int V = node[U][i].first;
            int W = node[U][i].second;
            
            if (x+W<value[V]) { // when the saved distance is greater than the sum of adjacent distance and previous distance value
                value[V] = x+W;
                pq.push(make_pair(x+W, V));
            }
        }
    }
    
    for(int i = 1; i <= V; i++) {
        if(value[i]==INF) printf("INF\n");
        else printf("%d\n",value[i]);
    }
}
