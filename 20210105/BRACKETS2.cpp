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
			// push open bracket in stack
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

		/* 
		모든 인풋에 대한 처리를 수행했는데 스택이 비어있지 않음 -> open bracket 이 더 많은 경우에 해당
		check 변수가 false 인 경우 -> close bracket 을 처리할 때, 짝이 맞지 않았거나 스택이 비어있는 경우에 
		*/
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
