#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int n, step[310], dp[310][10];

int main(){
	scanf("%d", &n)	;
	for (int i = 1 ; i <= n ; i++){
		scanf("%d", &step[i]);
	}
	
	dp[1][1] = step[1];
	
	for (int i = 2 ; i <= n ; i++){
		dp[i][2] = dp[i-1][1] + step[i];
		dp[i][1] = max(dp[i-2][1],dp[i-2][2])+step[i];
	}
	
	printf("%d", max(dp[n][1], dp[n][2]));
}