#include <cstdio>
#include <bits/stdc++.h>
// bits 쓰면 좌표(x1, y1 등) 사용하면 안된다!
using namespace std;

int N, M, nums[1030][1030];
int sub_sum[1030][1030];
int a, b, c, d;

int main(){
	scanf("%d%d", &N, &M);
	
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j <= N ; j++){
			scanf("%d", &nums[i][j]);
		}
	}
	
	// 구간합 구하기  
	for (int i = 1 ; i <= N ; i++){
		int linesum = 0;
		for (int j = 1 ; j <= N ; j++){
			linesum += nums[i][j];
			sub_sum[i][j] = sub_sum[i-1][j] + linesum;
//			printf("%d ", sub_sum[i][j]);
		}
//		printf("\n");
	}		
	
	for (int i = 0 ; i < M ; i++){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int temp = sub_sum[c][d] - sub_sum[a-1][d] - sub_sum[c][b-1] + sub_sum[a-1][b-1];
		printf("%d\n", temp);
	}
}