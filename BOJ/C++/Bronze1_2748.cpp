/*
* 2748번 피보니치수 2 | 수학
* 기본적인 피보나치 문제이다! 오랜만에 풀어서 감잡기용으로 리마인드 하기 좋았다
*/
#include <string.h>
#include <iostream>
using namespace std;
typedef long long ll;

ll dp[101];

ll go(ll cur){
	ll &ret=dp[cur];
	if(ret!=-1){
		return ret;
	}
	ret=go(cur-1)+go(cur-2);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	dp[1]=1;
	ll n;
	cin>>n;
	cout<<go(n);
	
	
	return 0;
}