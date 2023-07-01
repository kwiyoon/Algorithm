#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>

#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T, N, n; cin >> T;
    char c;

    while (T--) {
        cin >> N;
        map<int, int> m;
        
        for (int i = 0; i < N; i++) {
            cin >> c >> n;
            if (c == 'I') {
                if (m.find(n) != m.end())
                    m[n]++;
                else
                    m.emplace(n, 1);
            }
            else if (c == 'D') {
                if (m.empty()) continue;

                if (n == 1) {
                    auto it = m.end();
                    it--;
                    if (it->second == 1)
                        m.erase(it);
                    else
                        it->second--;
                }
                else if(n == -1) {
                    if (m.begin()->second == 1)
                        m.erase(m.begin());
                    else m.begin()->second--;
                }
            }
        }

        if (m.empty()) cout << "EMPTY\n";
        else {
            auto it = m.end();
            it--;
            cout << it->first << " " << m.begin()->first<< "\n";
        }
    }

    return 0;
}

