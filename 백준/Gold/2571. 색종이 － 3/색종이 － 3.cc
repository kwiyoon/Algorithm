#include <iostream>
using namespace std;
int paper[101][101] = { 0 };
int maxS = 100;

bool check(int i, int j, int k, int t) {
	for (int a = i; a <= k; a++)
		for (int b = j; b <= t; b++)
			if (paper[a][b] == 0)
				return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j < a + 10; j++) {
			for (int k = b; k < b + 10; k++)
				paper[j][k] = 1;
		}
	}


	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j] == 0) continue; // 다음 열 검사
			for (int k = i + 1; k < 101; k++) {
				for (int t = j + 1; t < 101; t++) {
					if (paper[k][t] == 0) break; // 다음 행 검사
					if ((k - i + 1) * (t - j + 1) > maxS) {
						bool flag = check(i, j, k, t);
						if (flag) maxS = (k - i + 1) * (t - j + 1);
					}
				}
			}
		}
	}

	cout << maxS;
	return 0;
}