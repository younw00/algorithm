#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

struct node {
    int data = NULL;
    bool visited = false;
    int distance = 0; // 이동칸 기록욕
};

int row, column;
queue<pair<int,int>> frontier;
node arr[MAX][MAX];
int x_index[] = {-1, 1, 0, 0};
int y_index[] = {0, 0, -1, 1};

void bfs(int start_x, int start_y){
    arr[start_x][start_y].visited = true;
    frontier.push(make_pair(start_x, start_y));
    ++arr[start_x][start_y].distance;
    
    while (!frontier.empty()) {
        int x = frontier.front().first;
        int y = frontier.front().second;
        
        frontier.pop();
        
        for (int i = 0; i < 4; ++i) {
            int child_x = x + x_index[i];
            int child_y = y + y_index[i];
            
            if ((child_x < row && child_x >= 0) && (child_y < column && child_y >= 0) &&
                !arr[child_x][child_y].visited && arr[child_x][child_y].data == 1) {
                arr[child_x][child_y].visited = true;
                frontier.push(make_pair(child_x, child_y));
                arr[child_x][child_y].distance = arr[x][y].distance + 1;
            }
        }
        
    }
}

int main(int argc, const char * argv[]) {
    cin >> row >> column;

    for (int i = 0; i < row; ++i) {
        string line;
        cin >> line;
        
        for (int j = 0; j < column; ++j) {
            arr[i][j].data = line[j] - '0';
        }
    }
    bfs(0,0);
    cout << arr[row-1][column-1].distance;
}
