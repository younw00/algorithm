#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 25

using namespace std;

struct node {
    int data = NULL;
    bool visited = false;
};

int total_unit = 0; // total nunber of groups
int unit;       // number of houses in a group
int N;

int x_index[4] = {0, 0, -1, 1};
int y_index[4] = {-1, 1, 0, 0};

node map[MAX][MAX];
vector<int> each_unit;

void dfs(int start_x, int start_y){
    //search for houses in the same group of input (start_x, start_y)
    for (int i = 0; i < 4; ++i) {
        int x = start_x + x_index[i];
        int y = start_y + y_index[i];
        
        if ((x >= 0 && x < N) && (y >= 0 && y < N) &&
            !map[x][y].visited && map[x][y].data == 1) {
            ++unit;
            map[x][y].visited = true;
            dfs(x, y);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < N; ++j) {
            map[i][j].data = row[j] - '0'; // to convert char to int
        }
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) { // search whole map if there is another group of houses
            if (!map[i][j].visited && map[i][j].data == 1) { // 1. not visited 2. there is house
                map[i][j].visited = true;
                unit = 1; //reset unit number to one before counting whole group of houses
                dfs(i,j); //iterate through a group of connected houses
                each_unit.push_back(unit);
                total_unit++; // after iterating a group, count them
            }
        }
    }
    
    sort(each_unit.begin(), each_unit.end()); // print out in ascending order
    cout << total_unit << '\n';
    for (int i = 0; i < each_unit.size(); ++i) {
        cout << each_unit[i] << '\n';
    }
    
    
}
