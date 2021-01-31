#include<iostream>
#include<vector>

using namespace std;

int JUMPGAME(vector<vector<int>>& map, int x, int y);

int cache[100][100];

int main(void) {
	int C;
	cin >> C;
	vector<vector<int>> map;
	vector<int> answer;

	for (int tc = 0; tc < C; tc++) {
		map.clear();
		fill(&cache[0][0], &cache[99][99], -1);

		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			vector<int> line(n);
			for (int j = 0; j < n; j++)
				cin >> line[j];
			map.push_back(line);
		}

		answer.push_back(JUMPGAME(map, 0, 0));
	}

	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}

int JUMPGAME(vector<vector<int>>& map, int x, int y) {
	if (x >= map.size() || y >= map.size())     return 0;

	if (x == map.size() - 1 && y == map.size() - 1)     return 1;

	int& ret = cache[y][x];
	
	if (ret != -1)      return ret;

	return ret = (JUMPGAME(map, x + map[y][x], y) || JUMPGAME(map, x, y + map[y][x]));
}
