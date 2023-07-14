#include <iostream>

using namespace std;

typedef long long ll;

int p[1000001];

int find(int n) {
    if (p[n] < 0) return n;
    p[n] = find(p[n]);
    return p[n];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    p[b] = a;
}

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 0; i <= n; i++) p[i] = -1;

    int w, a, b, tmpa, tmpb;
    while (m--) {
        cin >> w >> a >> b;
        if (w == 0) { // 합집합
            merge(a, b);
        }
        else if(w == 1){ // 두 원소가 같은 집합에 포합되어 있는지를 확인
            if (find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }


    return 0;
}

