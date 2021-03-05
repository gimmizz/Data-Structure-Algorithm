/*
* 2533번 사회망 서비스(sns)  |  DP, 트리  
* 트리만드는 유형은 처음 풀어봐서, 힌트를 보고 구현해냈다. dp 초기 선언은 -1이라는 점, 각 ret는 재선언해주어야 한다는 점 반드시 기억하자! 
*/
#include <iostream>
#include <cstring>
using namespace std;

int N, dp[1000001];

int go(int n){
	int &ret = dp[n];
	if (n==1) return 0;
	if (ret != -1) return ret;

	if (n%3 == 0) ret = min(go(n-1)+1, go(n/3) + 1);
	if (n%2 == 0) ret = min(go(n-1)+1, go(n/2) + 1);
	return ret;
}

int main(){
	cin >> N;
	memset(dp, -1, sizeof(dp));
	cout << go(N);
	return 0;
}