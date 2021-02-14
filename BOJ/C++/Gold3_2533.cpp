/*
* 2533번 사회망 서비스(sns)  |  DP, 트리  
* 트리만드는 유형은 처음 풀어봐서, 힌트를 보고 구현해냈다. dp 초기 선언은 -1이라는 점, 각 ret는 재선언해주어야 한다는 점 반드시 기억하자! 
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 1000000
using namespace std; 

int N;
vector<int> adj[1000001], child[1000001];
bool visited[1000001];
int dp[1000001][2];

void dfs(int cur){
	visited[cur] = true;
	
	for (int nxt: adj[cur]){
		if (!visited[nxt]){
			child[cur].push_back(nxt);
			dfs(nxt);
		}
	}
}

int go(int cur, bool e){
	int &ret = dp[cur][e]; // dp(cur, e) : cur이 earlyadapter(e) 일때, 아래의 자식들이 모두 조건을 만족시키는 최소 수 
	if (ret != -1) return ret;
	if (child[cur].empty()){ 	// child가 없으면, return 0 
		ret = e;
		return ret = e;
	}


	if (e){ // cur 가 earlyadapter이면, 자유로운 선택
		ret = 1;
		for (int nxt : child[cur]){
			 // nxt를 earlyadapter로 pick할지 여부에 따라, min 값을 더한다.  
			int pick = go(nxt, 1);
			int notpick = go(nxt, 0);
			ret += min(pick, notpick);
		}
	} else{ // cur 가 earlyadapter가 아니면, 무조건 nxt는 1 
		ret = 0;
		for (int nxt : child[cur]){
			ret += go(nxt,1);
		}
	}
	return ret;
}

int main(){
	cin >> N;
	for (int i = 0 ; i < N-1 ; i++){
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