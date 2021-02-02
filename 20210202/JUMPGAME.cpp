/*
	url: https://algospot.com/judge/problem/read/JUMPGAME
*/

#include<iostream>
#include<vector>

using namespace std;

int JUMPGAME(int x, int y);

vector<vector<int>> map;
int cache[100][100];

int main(void) {
	int C;
	cin >> C;
	vector<int> answer(C);

	for (int i = 0; i < C; i++) {
		int N;
		cin >> N;

		fill(&cache[0][0], &cache[99][100], -1);
		map = vector<vector<int>>(N, vector<int>(N));
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> map[j][k];
			}
		}

		answer[i] = JUMPGAME(0, 0);
	}

	for (int output : answer) {
		cout << (output ? "YES" : "NO") << endl;
	}

	return 0;
}

// (N-1, N-1) 로 이동하는 경로가 하나라도 존재하는 경우 양수를 리턴, 그렇지 않은 경우에는 0을 리턴
int JUMPGAME(int x, int y) {
	// 기저 사례 처리
	if (x >= map.size() || y >= map.size())			return 0;

	if (x == map.size() - 1 && y == map.size() - 1)			return 1;

	int& ret = cache[y][x];
	if (ret != -1)			return ret;

	return ret = JUMPGAME(x + map[y][x], y) + JUMPGAME(x, y + map[y][x]);
}
