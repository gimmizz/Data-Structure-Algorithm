/*
* 14502번 연구소 | bfs, dfs
* bfs와 dfs를 활용한 문제. 시간을 생각보다 넉넉하게 줘서 경우를 모두 탐색해도 시간초과가 안떴다. 
*/
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, M;
int arr[8][8];
int visited[8][8];
int output = 0;
//queue<int, int> q;
vector< pair<int, int> > virus;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int new_x, new_y;
int zero_count = 0;

int bfs(int x, int y){
//	memset(visited, false, sizeof(visited));
	queue< pair<int, int> > q;
	q.push({x,y});
	visited[x][y] = true;
	pair<int, int> item;
	int added = 0;
	
	while(!q.empty()){
		item = q.front(); q.pop();
		
		for (int i=0;i<4;i++){
			new_x = item.first + dx[i];
			new_y = item.second + dy[i];
			
			if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && arr[new_x][new_y] == 0 && !visited[new_x][new_y]){
				added++;
				q.push({new_x, new_y});
				visited[new_x][new_y] = true;
			}
		}
	}
	
	return added;
}

void dfs(int cur){
	if(cur == 3){ // 3개 벽 만들기 완료, 안전 구역 세기  
		memset(visited, false, sizeof(visited));
		int total_added = 0;
		for (int i=0;i<virus.size();i++){
			total_added += bfs(virus[i].first, virus[i].second);
		}
		
		output = max (output, zero_count - total_added - cur);
	}
	else{
		for(int n=0;n<N;n++){
			for(int m=0;m<M;m++){
				if (arr[n][m] == 0){
					arr[n][m] = 1;
					dfs(cur + 1);
					arr[n][m] = 0;
				}
			}
		}	
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for(int n=0;n<N;n++){
		for(int m=0;m<M;m++){
			cin >> arr[n][m];
			if (arr[n][m] == 2){
				virus.push_back({n,m});
			} else if (arr[n][m] == 0){
				zero_count++;
			}
		}
	}

	dfs(0);
	
	cout << output;
}