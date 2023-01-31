#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    vector<int> neighbors;
    bool visited = false;
    int distance = 0;
};

// 도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X
int N, M, K, X;
queue<int> frontier;
vector<int> result;

int main(int argc, const char * argv[]) {
    cin >> N >> M >> K >> X;
    node map[N];
    for (int i = 0; i < M; ++i) {
        int from, to;
        cin >> from >> to;
        map[from - 1].neighbors.push_back(to - 1);
    }
    
    //bfs
    map[X-1].visited = true;
    frontier.push(X-1);
    
    while (!frontier.empty()) {
        int current = frontier.front();
        frontier.pop();
        
        for (int i = 0; i < map[current].neighbors.size(); ++i) {
            if (!map[map[current].neighbors[i]].visited) {
                map[map[current].neighbors[i]].distance = map[current].distance + 1;
                frontier.push(map[current].neighbors[i]);
                map[map[current].neighbors[i]].visited = true;
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        if (map[i].distance == K) {
            result.push_back(i+1);
        }
    }
    
    if (result.size() == 0) cout << -1;
        else {
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << endl;
        }
}
