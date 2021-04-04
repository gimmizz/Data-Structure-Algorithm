/*
* 1269번 대칭 차집합 | 집합
* 평소에 잘 안 쓰는 set을 사용해봤다! 잘 쓰이지 않아도 기억해놔야겠다 호호
*/
#include <bits/stdc++.h>
using namespace std;


int n,m;
set<int> arr;
int k;
int answer=0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>k;
		arr.insert(k);
	}
	for(int i=0;i<m;i++){
		cin>>k;
		if(arr.count(k)!=0){
			arr.erase(k);
		}
		else{
			answer++;
		}
	}
	answer+=arr.size();
	cout<<answer;


	return 0;
}