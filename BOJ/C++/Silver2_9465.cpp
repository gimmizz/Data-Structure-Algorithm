/*
* 9465번 스티커 | DP
* 내가 설정한 DP의 정의에 따라, 상태 변화 체크하는게 아직 너무 어렵다ㅠㅠ 많이 연습해야할 것 같다. 오랜만에 DP풀었어두 유형은 익숙해서 다행
*/
#include <iostream>
#include <string.h>
using namespace std;

int T, N;
int score[2][100001], dp[100001][3];


int go(int col, int status){
		// dp(열, 현재 열의  status) : 해당 열까지 떼어냈을 때의 점수 최댓값  
		// status : 0(아무것도 떼지 않음)
		//			1(윗칸 뗐음)
		//			2(아랫칸 뗐음)  
	int &ret = dp[col][status];
	if (ret != -1) return ret;
	if (col == 0) {
		if (status == 0) return ret = 0;
		else if (status == 1) return ret = score[0][0];
		else if (status == 2) return ret = score[1][0];
	}
	
	if (status == 0) ret = max( go(col-1, 0), max(go(col-1, 1), go(col-1, 2)) );
 	else if ( status == 1 ) ret = max( go(col-1, 0),  go(col-1, 2) ) + score[0][col];
	else if ( status == 2 ) ret = max( go(col-1, 0),  go(col-1, 1) ) + score[1][col];
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for(int t = 0 ; t < T ; t++){
		int answer = 0;
		cin >> N;
		memset(score, 0, sizeof(score));
		memset(dp, -1, sizeof(dp));
		for (int col = 0 ; col < 2 ; col++){
			for (int n = 0 ; n < N ; n++){
				cin >> score[col][n];
			}
		}
		
		answer = max(max(go(N,0),go(N,1)), go(N,2));

		cout << answer << "\n";
	}
	return 0;
}