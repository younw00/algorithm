#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 10001

using namespace std;

vector<pair<int, int>> v[MAX];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
bool visited[MAX];
int sum;

void prim(int a){
    visited[a] = true; // 시작 노드 방문 처리
    for (int i = 0; i < v[a].size(); ++i) { // Node a와 연결된 방문 안한 다른 노드들 우선 순위 큐에 넣기
        if (!visited[v[a][i].second]) {
            pq.push(make_pair(v[a][i].first, v[a][i].second));
        }
    }
    while (!pq.empty()) {
        pair<int,int> pp = pq.top();
        pq.pop();
        if (!visited[pp.second]) {
            sum += pp.first;
            prim(pp.second);
            return;
        }
    }
}

int main(int argc, const char * argv[]) {
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= b; ++i) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        v[a1].push_back(make_pair(a3, a2));
        v[a2].push_back(make_pair(a3, a1));
    }
    prim(1);
    cout << sum;
}
