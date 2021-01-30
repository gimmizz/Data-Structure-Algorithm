/*
* 1012번 유기농배추 | 그래프, DFS 
* 컴포넌트 개수 구하기 전형적인 문제 유형. 
*/
#include <iostream>
using namespace std;

int T, M, N, K;
int answer;
int arr[51][51]; 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int a, int b){
	if (arr[b][a] == 0) {
		return;
	}
	arr[b][a] = 0;
	for (int i = 0 ; i < 4 ; i++){
		int p = a + dx[i];
		int q = b + dy[i];
		if (arr[q][p] == 1){
			dfs(p, q);
		}

	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T; // T : 테스트케이스  
	for (int t = 0 ; t < T ; t++){
		answer = 0;
		cin >> M >> N >> K; // M(가로), N(세로), K(배추개수)
		
		// 배추 행렬(arr) 세팅하기  
		int x, y;
		for (int i = 0 ; i < K ; i++){
			cin >> x >> y; // x(가로), y(세로) 
			arr[y][x] = 1;
		}
		
		// 
		for (int i = 0 ; i < M ; i++){
			for (int j = 0 ; j < N ; j++){
				if (arr[j][i] == 1){
					dfs(i, j);
					answer++;
				}
			}
		}
		cout << answer << "\n";
	} 
	return 0;
}

