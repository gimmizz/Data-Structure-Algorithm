/*
* 1149번 RGB 거리  |  DP
* 전형적인 DP 유형. 탑다운 방식은 거의 템플릿이니까 외워버리자~ 
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 1000000
using namespace std; 

int N;
int arr[1001][3];
int dp[1001][3];

int go(int n, int color){
	int &ret = dp[n][color]; // dp(n,color) : n부터 N(마지막)까지 조건을 만족하며 칠하는 경우의 수 중, 비용의 최솟값
	if (ret != -1) return ret;
	if ( n == N ) return arr[N][color];
	
	int decision[3] = {INF,INF,INF};
	for (int i = 0; i < 3 ; i++){ // i : 다음에 쓸 색상  
		if (i == color) continue; // 이전과 같은 색을 칠할 수 없다.  
		decision[i] = go(n+1, i) + arr[n][color];
	}
	ret = *min_element(decision, decision+3);
	return ret;
}

int main(){
	cin >> N;
	for (int i = 0 ; i < N ; i++){
		for (int j = 0 ; j < 3 ; j++){
			cin >> arr[i][j];
		}
	}
	
	memset(dp, -1, sizeof(dp));
	int min_cost = INF;
	for (int i = 0 ; i < 3 ; i++){
		int temp = go(0, i);
		if (min_cost > temp) min_cost = temp;
	}
	
	cout << min_cost;
	return 0;
} 