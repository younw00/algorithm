#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 101

using namespace std;

struct node{
    int data = NULL;
    bool visited = false;
    int distance = 0;
};

int x_index[4] = {-1, 1, 0, 0};
int y_index[4] = {0, 0, -1, 1};
int ans = 10001; // set it to a big number

int N, M, T;
node map[MAX][MAX];
queue<pair<int,int>> frontier;

void bfs (int start_x, int start_y) {
    map[start_x][start_y].visited = true;
    frontier.push(make_pair(start_x, start_y));
    
    while (!frontier.empty()) {
        int x = frontier.front().first;
        int y = frontier.front().second;
        frontier.pop();
        
        if (map[x][y].data == 2) { // 그람을 발견하고 목적지까지 직행 (Manhattan distance)
            int potential_ans = map[x][y].distance + ((N-1) - x) + ((M-1) - y);
            if (potential_ans < ans) ans = potential_ans;
        }
        
        if (x == N - 1 && y == M - 1) { //그람없이 목적지를 간 경우
            int potential_ans = map[x][y].distance;
            if (potential_ans < ans) ans = potential_ans;
        }
        
        for (int i = 0; i < 4; ++i) {
            int child_x = x + x_index[i];
            int child_y = y + y_index[i];
            
            if ((child_x >= 0 && child_x < N) && (child_y >= 0 && child_y < M)
                && !map[child_x][child_y].visited && map[child_x][child_y].data != 1) {
                frontier.push(make_pair(child_x, child_y));
                map[child_x][child_y].visited= true;
                map[child_x][child_y].distance = map[x][y].distance + 1;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> N  >> M >> T;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int data;
            cin >> data;
            map[i][j].data = data;
        }
    }
    
    bfs(0,0);
    
    if (ans <= T) cout << ans << '\n';
    else cout << "Fail" << '\n';
}
