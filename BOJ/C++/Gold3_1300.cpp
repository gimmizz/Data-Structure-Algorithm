/*
* 1300번 K번째 수 | 이분탐색
* 중간에 for문 처리를해서 이분탐색을 돌리는 생각을 하느라 오래걸렸다.....ㅎ 내용은 간단하지만 계속 걸리는 문제 유형
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n,k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	cin>>k;
	
	int a=1;
	int b=k;
	while(a<b){
		int c=(a+b)/2;
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=min(c/i,n);
		}
		if(sum>=k){
			b=c;
		}
		else{
			a=c+1;
		}
	}
	cout<<a;
	
	
	
	return 0;
}