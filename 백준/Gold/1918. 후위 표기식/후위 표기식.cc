#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	stack<char> op;
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i]!=' ') {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				cout << s[i];
			}
			else {
				if (s[i] == '(') op.push(s[i]);
				else if (s[i] == ')') {
					while (!op.empty()) { // ( 를 만날 때 까지 pop
						if (op.top() == '(')break;
						cout << op.top();
						op.pop();
					}
					op.pop(); // ( pop
				}
				else if (s[i] == '*' || s[i] == '/') {
					if (!op.empty() && (op.top() == '*' || op.top() == '/')) {
						cout << op.top(); op.pop();
					}
					op.push(s[i]);
				}
				else if (s[i] == '+' || s[i] == '-') {
					while (!op.empty() && op.top() != '(') {
						cout << op.top(); op.pop();
					}
					op.push(s[i]);
				}
			}
		}
	}
	while (!op.empty()) {
		cout << op.top(); op.pop();
	}

	return 0;
}