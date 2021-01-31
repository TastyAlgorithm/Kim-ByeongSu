/*
  url: https://algospot.com/judge/problem/read/TRIANGLEPATH
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int TRIANGLEPATH(int x, int y);

int N;
int cache[101][101];
int triangle[100][100];

int main(void) {
	int C;
	cin >> C;
	vector<int> answer(C);

	for (int i = 0; i < C; i++) {
		cin >> N;

		fill(&cache[0][0], &cache[100][101], -1);
		fill(&triangle[0][0], &triangle[99][100], -1);

		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < j; k++) {
				cin >> triangle[j - 1][k];
			}
		}

		answer[i] = TRIANGLEPATH(0, 0);
	}

	for (int output : answer) {
		cout << output << endl;
	}

	return 0;
}

int TRIANGLEPATH(int x, int y) {
	// 기저 사례 처리
	if (y == N - 1)			return triangle[y][x];

	int& ret = cache[y][x];
	if (ret != -1)			return ret;

	return ret = triangle[y][x] + max(TRIANGLEPATH(x, y + 1), TRIANGLEPATH(x + 1, y + 1));
}
