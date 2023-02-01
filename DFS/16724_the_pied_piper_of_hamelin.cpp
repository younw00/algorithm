#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 1001

using namespace std;

int x_index[4] = {0, 1, 0, -1};
int y_index[4] = {-1, 0, 1, 0};

struct node{
    char data;
    int group;
};

int N, M;
int cnt, ret;
node map[MAX][MAX];

void bfs (int start_x, int start_y) {
    if (map[start_x][start_y].group == 0) {
        //map[start_x][start_y]를 아직 탐색하지 않았다
        map[start_x][start_y].group = cnt;
        int index;
        if (map[start_x][start_y].data == 'U') index = 3;
        else if (map[start_x][start_y].data == 'R') index = 2;
        else if (map[start_x][start_y].data == 'D') index = 1;
        else index = 0;
        
        int x = start_x + x_index[index];
        int y = start_y + y_index[index];
        bfs(x, y);
    }
    else if (map[start_x][start_y].group == cnt) {
        //map[start_x][start_y] 가 현재그룹이면 현재그룹의 iteration은 다 돌았기때문에 다음 그룹의 수를 increment해주고 dfs를 빠져나온다
        ++ret;
        ++cnt;
        return;
    }
    else if (map[start_x][start_y].group > 0 && map[start_x][start_y].group != cnt) {
        //map[start_x][start_y]를 이미 들렸고, 다른 그룹에 포함되어 있다면, 그 그룹의 cycle에 포함된 것으로 dfs를 빠져나온다
        ++cnt;
        return;
    }
    return;
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j) {
            map[i][j].data = row[j];
        }
    }
    
    cnt = 1;
    ret = 0;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j].group == 0) {
                bfs(i, j);
            }
        }
    }
    cout << ret;
}
