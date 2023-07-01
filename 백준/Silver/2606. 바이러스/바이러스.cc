#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N, M, num = 0;
vector<vector<int>> adj(1001);
vector<bool> visited(1001, false);

void sortList() {
    for (int i = 0; i <= N; i++)
        sort(adj[i].begin(), adj[i].end());
}

void bfs() {
    queue<int> Q;
    Q.emplace(1);
    visited[1] = true;
    // 탐색 시작
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop(); 
        
        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                Q.emplace(next);
                num++;
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    
    bfs();
	
    cout << num;
	
	return 0;
}