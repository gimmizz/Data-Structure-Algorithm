#include <cstdio>
// #include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int n, tri[510][510], max_val[510][510], ans;

int main() {
   scanf("%d", &n);
   for (int i = 1 ; i <= n ; i++){
      for (int j = 1 ; j <= i ; j++){
         scanf("%d", &tri[i][j]);
      }
   }
   
   max_val[1][1] = tri[1][1];
   
   for (int i = 2 ; i <= n ; i++){
      for (int j = 1 ; j <= i ; j++){
         max_val[i][j] = max(max_val[i-1][j-1], max_val[i-1][j]) + tri[i][j];
      }
   }
   
   for (int i = 1 ; i <= n ; i++){
      ans = max(max_val[n][i], ans);
   }
   
   printf("%d", ans);
}


