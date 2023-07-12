#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> arr;

bool isPrime(int num){
    if(num == 1) return false;
    for(int i = 2; i <= sqrt(num); i++){
        if(num%i==0)return false;
    }
    return true;
}

void recursive(int digit, int num){
    if(digit == 1) cout<<num<<"\n";

    for(int i = 1; i < 10; i += 2){
        if(isPrime(num*10 + i))
            recursive(digit-1, num*10 + i);
    }


}

int main(void){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    
    recursive(N, 2);
    recursive(N, 3);
    recursive(N, 5);
    recursive(N, 7);

    return 0;
}