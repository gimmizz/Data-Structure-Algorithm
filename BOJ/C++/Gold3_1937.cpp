/*
* 1937번 욕심쟁이 판다  |  DP, 그래프  
* 처음에는 dp 파라미터로 상하좌우 state까지 고려해야 한다고 생각했는데, 생각해보니 visited가 필요하지 않은 유형. 
* 이미 방문한 노드는 현재 노드보다 대나무 수가 더 적은 것이 확실하기 때문에, 방문한 곳을 또 방문할리가 없다.  
* 행여, visited를 고려해야 하더라도, cost를 전역변수로 써서, 초기화시키는 방법도 있다고 한다! 다음에 풀어보자 
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std; 

int n;
int arr[501][501];
int dp[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int go(int a, int b){ // dp(a,b) : (a,b)에서 시작할 때, 판다가 살 수 있는 최대 값 
	int &ret = dp[a][b];
	if (ret != -1) return ret; // 이미 방문한 경우 
	
	int decision[4] = {0,0,0,0};
	for (int i = 0 ; i < 4 ; i ++){
		int nxt_x = a + dx[i];
		int nxt_y = b + dy[i];
		if (nxt_x < 0 || nxt_x >= n || nxt_y < 0 || nxt_y >= n ) continue; // 범위를 벗어나면, 제외
		
		if (arr[nxt_x][nxt_y] > arr[a][b])
			decision[i] = go(nxt_x,nxt_y) + 1;
	} 
	ret = *max_element(decision, decision+4);
	return ret;
}

int main(){
	cin >> n;
	for (int i = 0 ; i < n ; i++){ // 행 
		for (int j = 0 ; j < n ; j++){ // 열  
			cin >> arr[i][j];
		}
	}
	
	memset(dp, -1, sizeof(dp));
	int cnt = 0;
	for (int i = 0 ; i < n ; i++){ // 행 
		for (int j = 0 ; j < n ; j++){ // 열  
			int temp = go(i, j);
			if (cnt < temp){
				cnt = temp;
			}
		}
	}
	cout << cnt + 1;
	return 0;
}