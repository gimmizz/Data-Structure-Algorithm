/*
* 1182번 부분 수열의 합 | 완전탐색
* 정말 간단한 완전탐색이었다!
*/

#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[21];
int answer = 0;

void dfs(int cur,int plus) {
	if (cur == n)
		return;
	if (plus + arr[cur] == s) {
		answer ++;
	}
	dfs(cur + 1, plus);
	dfs(cur + 1, plus + arr[cur]);
}


int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >>arr[i];
	}
	dfs(0,0);
	cout << answer;
	return 0;
}