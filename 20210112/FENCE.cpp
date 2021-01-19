/*
  url: https://algospot.com/judge/problem/read/FENCE
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int FENCE();
int getLeft(int index);
int getRight(int index);

vector<int> fence;

int main(void) {
	int C;
	cin >> C;
	vector<int> answer(C);
	
	for (int i = 0; i < C; i++) {
		fence.clear();
		fence.push_back(-1);

		int N;
		cin >> N;
		for (int k = 0; k < N; k++) {
			int temp;
			cin >> temp;
			fence.push_back(temp);
		}
		fence.push_back(-1);
		/*
		23, 33 번째 줄에서 -1 을 push 해주는 이유?
		input 으로 7 1 5 9 6 7 3 라는 숫자들이 주어졌을 때, -1 을 맨 처음과 맨 마지막에 넣어주면 
		getLeft() 함수와 getRight() 함수의 for loop 에서 index 범위를 벗어났는지 따로 체크하지 않아도 되기 때문.
		*/
		
		answer[i] = FENCE();
	}

	for (int i = 0; i < C; i++)
		cout << answer[i] << endl;

	return 0;
}

int FENCE() {
	int ret = 0;

	for (int i = 1; i < fence.size() - 1; i++) {
		int left = getLeft(i);
		int right = getRight(i);
		int size = (right - left + 1) * fence[i];

		ret = max(ret, size);
	}

	return ret;
}

int getLeft(int index) {
	int ret = index;

	for (int i = index - 1; i > 0; i--) {
		if (fence[i] < fence[index])		break;
		ret = i;
	}

	return ret;
}

int getRight(int index) {
	int ret = index;

	for (int i = index + 1; i < fence.size(); i++) {
		if (fence[i] < fence[index])		break;
		ret = i;
	}
	
	return ret;
}
