/*
* 1463번 1로 만들기  |  DP 
* 맨 처음엔 단순히 그리디라고 생각했는데, 아니다! dp다! 
*/
#include <iostream>
#include <cstring>
using namespace std;

int N, dp[1000001];

int go(int n){
	int &ret = dp[n];
	if (n==1) return 0;
	if (ret != -1) return ret;

	if (n%6 == 0) ret = min(min(go(n-1)+1, go(n/3) + 1), go(n/2) + 1);
	else if (n%3 == 0) ret = min(go(n-1)+1, go(n/3) + 1);
	else if (n%2 == 0) ret = min(go(n-1)+1, go(n/2) + 1);
	else ret = go(n-1) + 1 ;
	
	return ret;
}

int main(){
	cin >> N;
	memset(dp, -1, sizeof(dp));
	cout << go(N);
	return 0;
}