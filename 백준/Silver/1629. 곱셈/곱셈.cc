#include <iostream>
using namespace std;

int mul(int A, int B, int C) {
    if (B == 0) return 1;
    int tmp = mul(A, B / 2, C);
    long long int res = (long long int) tmp * tmp % C;
    if (B % 2 != 0) res = (long long int) res * A % C;

    return res;
}

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int A, B, C; cin >> A >> B >> C;

    cout << mul(A, B, C);

    return 0;
}