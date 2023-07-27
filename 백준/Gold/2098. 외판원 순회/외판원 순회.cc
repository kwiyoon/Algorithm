#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>

#define MAX 1000000000
using namespace std;

int W[16][16];
int dp[16][1 << 16];
int N;


int tsp(int cur, int visited) {
    if (visited == (1 << N) - 1) { // 모두 방문
        if (W[cur][0] == 0) { //현재 -x-> 시작점 인 경우
            return MAX;
        }
        return W[cur][0];
    }

    // 이미 방문
    if (dp[cur][visited] != -1) {
        return dp[cur][visited];
    }

    dp[cur][visited] = MAX;

    for (int i = 0; i < N; i++) {
        if (W[cur][i] == 0 || (visited & (1 << i)) != 0) {//갈수 없거나 이미 방문
            continue;
        }
        dp[cur][visited] = min(dp[cur][visited], tsp(i, visited | (1 << i)) + W[cur][i]);
    }
    return dp[cur][visited];
}

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N; // 도시의 수 N
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }

    fill(dp[0], dp[16], -1);
    cout << tsp(0, 1);

    return 0;
}

