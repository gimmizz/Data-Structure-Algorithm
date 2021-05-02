/*
* 18235번 지금 만나러 갑니다 | bfs
* 좀 독특한 bfs 문제! -1이 뜨는 조건을 잘 찾아야한다!
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a,b;
vector<int> arr[20];
map<pair<int,int>,int> dic;
queue<pair<int,int>> que;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>n>>a>>b;
	que.push({a,0});
	que.push({b,0});
	while(!que.empty()){
		int cur=que.front().first;
		int day=que.front().second;
		que.pop();
		if(dic[{cur,day}]!=0){
			cout<<day;
			return 0;
		}
		dic[{cur,day}]=1;
		int move=pow(2,day);
		if(cur+move<=n){
			que.push({cur+move,day+1});
		}
		if(cur-move>=1){
			que.push({cur-move,day+1});
		}
	}
	cout<<-1;
	return 0;
}