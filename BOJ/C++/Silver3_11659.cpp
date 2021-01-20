#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int N, M, nums[100010], sum; 
int a, b;
int subsum[100010]; // 1부터 i번째 까지의 합 

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1 ; i <= N ; i++){
		scanf("%d", &nums[i]);
	}
	
	for (int i = 1 ; i <= N ; i++){
		sum = sum + nums[i];
		subsum[i] = sum;
	}
	
	for (int i = 0 ; i < M ; i++){
		scanf("%d%d", &a, &b);
		int temp = subsum[b] - subsum[a-1];
		printf("%d\n", temp);
	}
}