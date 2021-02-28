/*
* 17374번 비트 베리 | 그리디 알고리즘, 정렬 
* 간단한 수학문제였다.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int t;
int p,q,a,b,c,d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>t;
	while(t--){
		cin>>p>>q>>a>>b>>c>>d;
		int coin=d*(q/c);
		if(p==coin){
			cout<<p<<"\n";
		}
		else if(p>coin){
			int c=(p-coin)/(a+b);
			int z=min(p-a*c,coin+b*c);
			int x=min(p-a*(c+1),coin+b*(c+1));
			cout<<max(z,x)<<"\n";
		}
		else{
			int c=(coin-p)/(a+b);
			int z=min(p+a*c,coin-b*c);
			int x=min(p+a*(c+1),coin-b*(c+1));
			cout<<max(z,x)<<"\n";
		}
	}
	return 0;
}