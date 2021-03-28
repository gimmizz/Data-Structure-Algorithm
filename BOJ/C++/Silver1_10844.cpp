/*
* 쉬운 계단 수 | DP
* 자리수처리만 해주면, 무난한 dp 문제이다
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include<vector>
using namespace std;

int dp[10][101];
int main() {
	int n;
	cin >> n;
	dp[0][0] = 0;
	for (int i = 1; i < 10; i++) {
		dp[i][0] = 1;
	}
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < 10;i++) {
			if ((i != 0) && (i != 9)) {
				dp[i][j] = (dp[i + 1][j - 1] % 1000000000 + dp[i - 1][j - 1] % 1000000000)%1000000000;
			}
			else if(i==0) {
				dp[i][j] = dp[1][j - 1] % 1000000000;
			}
			else {
				dp[i][j] = dp[8][j - 1] % 1000000000;
			}
		}
	}
	long long answer = 0;
	for (int i = 0; i < 10; i++) {
		answer += dp[i][n - 1]%1000000000;
		answer %= 1000000000;
	}
	cout << answer<<"\n";
	return 0;
}