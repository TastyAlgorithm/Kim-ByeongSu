/*
  url: https://algospot.com/judge/problem/read/BRACKETS2
*/

#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	int C;
	cin >> C;

	string* answer = new string[C];

	for (int i = 0; i < C; i++) {
		string input;
		cin >> input;

		bool check = true;
		stack<char> stk;
		for (int j = 0; j < input.size(); j++) {
			if (input[j] == '(' || input[j] == '{' || input[j] == '[') {
				stk.push(input[j]);
			}
			else if (input[j] == ')') {
				if (stk.empty() || stk.top() != '(') {
					check = false;
					break;
				}
				else if (stk.top() == '(')
					stk.pop();
			} 
			else if (input[j] == '}') {
				if (stk.empty() || stk.top() != '{') {
					check = false;
					break;
				}
				else if (stk.top() == '{')
					stk.pop();
			}
			else if (input[j] == ']') {
				if (stk.empty() || stk.top() != '[') {
					check = false;
					break;
				}
				else if (stk.top() == '[')
					stk.pop();
			}
		}

		if (!stk.empty() || !check) {
			answer[i] = "NO";
		}
		else {
			answer[i] = "YES";
		}
	}

	for (int i = 0; i < C; i++)
		cout << answer[i] << endl;

	return 0;
}
