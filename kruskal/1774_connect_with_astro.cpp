#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
int parent[1002];
vector<pair<int,int>> god;
vector<tuple<int,int,double>> path;

int find (int x) { // find parent of x
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union (int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

void Kruskal () {
    double sum = 0;
    for (auto p : path) {
        int a = get<0>(p);
        int b = get<1>(p);
        double cost = get<2>(p);
        if (find(a) != find(b)) {
            sum += cost;
            Union(a, b);
        }
    }
    cout << sum;
}

double distance(int i, int j) {
    return sqrt(pow(god[i].first - god[j].first, 2) + pow(god[i].second - god[j].second, 2));
}

bool cmp (tuple<int, int, double> a, tuple<int, int, double> b) {
    return get<2>(a) < get<2>(b);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cout << fixed;
    cout.precision(2);
    
    for (int i = 0; i < N; ++i) parent[i] = i;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        god.push_back(make_pair(x-1, y-1));
    }
    
    for (int i = 0; i < god.size(); ++i) {
        for (int j = i; j < god.size(); ++j) {
            if (i == j) continue;
            path.push_back(make_tuple(i, j, distance(i, j)));
        }
    }
    
    sort(path.begin(), path.end(), cmp);
    
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        Union(x-1, y-1);
    }

    Kruskal();
}
