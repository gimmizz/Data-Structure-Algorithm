/*
* 11052번 카드 구매하기 | DP
* 기본적인 디피문제! 복습하기 좋았다
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include<vector>
using namespace std;

int price[1001];
int dp[1001] = { 0, };
int main() {
   int n;
   cin >> n;
   for (int i = 1; i <= n; i++) {
      cin >> price[i];
   }
   for (int i = 1; i <= n; i++) {
      dp[i] = price[i];
      for (int j = 1; j < i; j++) {
         dp[i] = max(dp[i], dp[i - j] + dp[j]);
      }
   }
   cout << dp[n];
   return 0;
}