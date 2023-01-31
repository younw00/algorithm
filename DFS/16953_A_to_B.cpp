#include <iostream>
#define MAX 100000

using namespace std;

long long a, b;
int number_of_conversion = 0;
int indicator = MAX;

void dfs(long long a, int number_of_conversion){
    if (a == b) {
        indicator = min(indicator, number_of_conversion);
    };
    if (a < b) {
        dfs(a*2, number_of_conversion + 1);
        dfs(a*10+1, number_of_conversion + 1);
    }
    else return;
}

int main(int argc, const char * argv[]) {
    cin >> a >> b;
    dfs(a, 1);
    if (indicator == MAX) cout << -1;
    else cout << indicator;
}
