#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, K, num=0; cin >> N >> K;
    vector<int> ord;
    ord.emplace_back(-1);
    for (int i = 0; i < K; i++) { //전기용품의 이름이 정수로
        int a; cin >> a;
        ord.emplace_back(a);
    }

    int* plug = new int[N+1];
    for (int i = 0; i < N+1; i++) {
        plug[i] = 0;
    }

    int* ex = new int[N + 1]; // 플러그에 꽂혀있는 애들이 나중에 몇 번째에 나오는지 순서를 저장

    for (int i = 1; i < K + 1; i++) { // i번째꺼 꽂을 차례
        int empty = -1;
        for (int j = 1; j < N + 1; j++) { 
            if (plug[j] == 0) {
                empty = j;
                break;
            }
        }
        if (empty!=-1) {
            bool put = true;
            for (int j = 1; j < N + 1; j++) {
                if (plug[j] == ord[i]) { // 콘센트가 비었다. 근데 남은 자리 중에 ord랑 같은 게 있냐?
                    put = false;
                    break;
                }
            }
            if (put) {
                plug[empty] = ord[i];
            }
        }
        else {
            for (int j = 1; j < N + 1; j++) { // ex 초기화
                ex[j] = -1; // 안나오면 그대로 -1.
            }
            bool exist = false;
            for (int j = 1; j < N + 1; j++) { // 플러그 검사 N == 3 이라면 1, 2, 3
                if (plug[j] == ord[i]) { //플러그에 꽂혀있는지 검사
                    exist = true; // 꽂혀있다면 true
                    break;
                }
                for (int k = i; k < ord.size(); k++) { // 다음 순서들 탐색
                    if (plug[j] == ord[k]) { // 만약 j번째 플러그랑 같은 애의 순서(k)가 보인다?
                        ex[j] = k; // 순서 저장 
                        break; // 어차피 가장 빠른 애만 필요하니까 브레이크
                    }
                }
            }
            if (!exist) { // 현재 꽂을 거가 플러그에 꽂혀있지 않다면
                num++;
                int maxidx = 1;
                for (int j = 1; j < N + 1; j++) { // 앞으로 안쓰이거나, 제일 늦게 쓰이는 애를 찾아서 뽑아
                    if (ex[j] == -1) {
                        maxidx = j; break;
                    }
                    else {
                        if (ex[j] > ex[maxidx]) maxidx = j;
                    }
                }
                plug[maxidx] = ord[i]; // 앞으로 안쓰이거나, 제일 늦게 쓰이는 애를 찾아서 바꿔끼기
            }
        }
    }
    cout << num;

    delete[] ex;
    delete[] plug;

    return 0;
}