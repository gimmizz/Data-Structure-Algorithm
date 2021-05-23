/*
* 1525번 퍼즐 | BFS + 완전탐색
* bfs 탐색이다! 인지최 과제 생각나서 풀었다. 자료구조 설정만 잘하면 큰 문제는 없었다!
*/
#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int c=0;
map<int, int> depth;
queue<int> que;

void bfs(int cur) {
	que.push(cur);
	while(que.empty()==false) {
		int l = que.front();
		if (l == 123456789) {
			break;
		}
		que.pop();
		string h = to_string(l);
		int q = h.find('9');
		int w = q / 3;
		int e = q % 3;
		for (int i = 0; i < 4; i++) {
			int z = w + dx[i];
			int x = e + dy[i];
			if (z >= 0 && z < 3 && x >= 0 && x < 3) {
				string yo = h;
				swap(yo[z * 3 + x], yo[q]);
				int yolo = stoi(yo);
				if (depth.count(yolo) == 0) {
					depth[yolo] = depth[l] + 1;
					que.push(yolo);
				}
			}
		}
	}
}


int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int a;
			cin >> a;
			if (a == 0) {
				a = 9;
			}
			c = c * 10 + a;
		}
	}
	depth[c] = 0;
	bfs(c);
	if (depth.count(123456789) == 0) {
		cout << -1;
	}
	else
		cout << depth[123456789];
	return 0;
}