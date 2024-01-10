#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>

#include <vector>
#include <queue>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, num = 0; cin >> N;

    // 1. 일단 소수 배열을 구한다.
    int* primeNum = new int[N + 1];

    for (int i = 2; i <= N; i++) primeNum[i] = i;

    for (int i = 2; i <= sqrt(N); i++) {
        if (primeNum[i] == 0)continue;
        for (int j = i * i; j <= N; j += i) {
            primeNum[j] = 0;
        }
    }

    // 1-1. 소수들로만 간추리기
    vector<int> prime;
    for (int i = 2; i <= N; i++) {
        if (primeNum[i] != 0) prime.emplace_back(i);
    }


    // 2. 투 포인터 테크닉을 이용하여 더해준다~
    int s = 0, e = 0, res = 0, sum = 0;
    while (true) {
        if (sum >= N) sum -= prime[s++];
        else if (e == prime.size()) break;
        else sum += prime[e++];
        if (sum == N) res++;
    }

    cout << res;

    delete[] primeNum;

    return 0;
}

