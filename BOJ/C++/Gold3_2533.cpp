/*
* 2533번 사회망 서비스(sns)  |  DP, 트리  
* 트리만드는 유형은 처음 풀어봐서, 힌트를 보고 구현해냈다.  
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 1000000
using namespace std; 

int N;
vector<int> adj[1000001], child[1000001];
bool visited[1000001];

void dfs(int cur){
	visited[cur] = true;
	
	for (int nxt : adj[cur]){
		if (!visited[nxt]){
			child[cur].push_back(nxt);
			dfs[nxt];
		}
	}
}

int go(int cur, bool e){
	int &ret = dp[cur][e]; // dp(cur, e) : cur이 earlyadapter(e) 일때, 아래의 자식들이 모두 조건을 만족시키는 최소 수 
	if (ret != -1) return ret;
	
	for (int nxt : child[cur]){
		int pick = dp[nxt][!e] + !e;
	}
	// child가 없으면, return 0 
	return
}

int main(){
	cin >> N;
	for (int i = 0 ; i < N ; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	// 트리 만들기 (그냥 1번 노드를 root로 생각, child를 만들자)
	dfs(1);
	
	memset(dp, -1, sizeof(dp));
	cout << min(go(1, 0), go(1,1));
	return 0;
}