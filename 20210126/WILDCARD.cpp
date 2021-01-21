/*
  url: https://algospot.com/judge/problem/read/WILDCARD
*/

#include<iostream>	
#include<string>	
#include<vector>
#include<algorithm>

#define TRUE 2
#define FALSE 1
#define NONE 0

using namespace std;

int solve(string wildcard, string filename);

int cache[101][101];
string wildCard;
vector<string> fileName;

int main(void) {
	int C;	
	cin >> C;
	vector<vector<string>> answer(C);

	for (int i = 0; i < C; i++) {
		cin >> wildCard;
		int N;
		cin >> N;
		
		fileName.clear();
		for (int k = 0; k < N; k++) {
			string temp;
			cin >> temp;
			fileName.push_back(temp);
		}

		vector<string> vec;
		for (int k = 0; k < N; k++) {
			fill(&cache[0][0], &cache[100][101], NONE);
			int ret = solve(wildCard, fileName[k]);
			if (ret == TRUE)
				vec.push_back(fileName[k]);
		}
		sort(vec.begin(), vec.end());
		answer[i] = vec;
	}

	for (int i = 0; i < answer.size(); i++) {
		for (int j = 0; j < answer[i].size(); j++) {
			cout << answer[i][j] << endl;
		}
	}

	return 0;
}

int solve(string wildcard, string filename) {
	if (filename.size() == 0 && wildcard.size() == 0)
		return TRUE;

	// filename 에 비교할 문자가 더 존재하지 않고, wildcard 에 '?' 와 '*' 가 아닌 문자가 존재하는 경우 -> 일치하지 않음
	if (filename.size() == 0 && !(wildcard.at(0) == '?' || wildcard.at(0) == '*')) 
		return FALSE;
	
	// filename이 wildcard 보다 더 긴 경우 -> 일치하지 않음
	if (filename.size() > 0 && wildcard.size() == 0)
		return FALSE;


	int& ret = cache[wildcard.size() - 1][filename.size() - 1];
	if (ret != NONE)
		return ret;

	if (wildcard.at(0) == '?') {
		// filename 에 비교할 문자가 더 존재하는 경우 -> '?' 를 filename.at(0) 으로 간주하고 재귀호출
		if (filename.size() > 0) {
			ret = solve(wildcard.substr(1, wildcard.size() - 1), filename.substr(1, filename.size() - 1));
		}
		// filename 에 비교할 문자가 더 존재하지 않는 경우 -> '?' 를 공백으로 간주하고 재귀호출
		ret = max(ret, solve(wildcard.substr(1, wildcard.size() - 1), filename));
	}
	else if (wildcard.at(0) == '*') {
		/* 
		filename 에 비교할 문자가 더 존재하는 경우 
		-> filename.at(0) 을 '*' 의 부분문자열로 간주하고 재귀호출 하거나,
		-> filename.at(0) 을 '*' 로 간주하고 재귀호출
		*/
		if (filename.size() > 0) {
			ret = max(solve(wildcard, filename.substr(1, filename.size() - 1)), solve(wildcard.substr(1, wildcard.size() - 1), filename.substr(1, filename.size() - 1)));
		}
		// filename 에 비교할 문자가 더 존재하지 않는 경우 -> '*' 을 공백으로 간주하고 재귀호출
		ret = max(ret, solve(wildcard.substr(1, wildcard.size() - 1), filename));
	}
	// wildcard.at(0) 과 filename.at(0) 이 같은 경우 -> 서브스트링끼리 재귀호출
	else if (wildcard.at(0) == filename.at(0)) {
		ret = solve(wildcard.substr(1, wildcard.size() - 1), filename.substr(1, filename.size() - 1));
	}
	// wildcard.at(0) 이 '?' 도 아니고, '*' 도 아닌 경우에 filename.at(0) 과도 다른 경우 -> 일치하지 않음
	else {
		ret = FALSE;
	}

	return ret;
}
