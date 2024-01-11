#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>

#include <vector>

using namespace std;

typedef long long ll;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int N, i; cin >> N;
    vector<ll> arr(N);

    for (i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int s, e;
    ll ans[3]{ 0 }, sum, minNum = 3000000001;

    for (i = 0; i < N - 2; i++) {
        s = i + 1; e = N - 1;

        while (s < e) {
            sum = arr[s] + arr[e] + arr[i];
            if (minNum > abs(sum)) {
                minNum = abs(sum);
                ans[0] = arr[i];
                ans[1] = arr[s];
                ans[2] = arr[e];
            }
            if (sum < 0) s++;
            else e--;
        }
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2];

    return 0;
}

