/*
* 2178번 미로 탐색 | BFS, 그래프 탐색 
* 각 정점의 최단거리를 재야 한다 -> level 저장 방식. bfs는 익숙해지도록 반복하자!! 
*/
#include <iostream> 
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int arr[101][101];
bool visited[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	// arr 배열 초기화
	string temp;
	for (int i = 0 ; i < N ; i++){ // 행 i
		cin >> temp;
		for (int j = 0 ; j < M ; j++){ //열 j
			arr[i][j] = temp[j]-'0' ; // (행, 열)  
		}
	}
	queue< pair<int, int> > q;
	pair<int, int> cur;
	int level = 0;
	q.push({0,0});
	visited[0][0] = true;
	while(!q.empty()){
//		cout << "------ level " << level << " ------" << endl;
		int current_qsize = q.size();
		for ( int x = 0 ; x < current_qsize ; x++){
			cur = q.front(); q.pop();
//			cout << x << "cur: " << cur.first << " " << cur.second << endl;
			if (cur.first==(N-1) && cur.second==(M-1)){
				cout << level + 1;
				return 0;
			}
			for(int i = 0 ; i < 4 ; i++){
				int c = cur.first + dy[i]; // 행 
				int d = cur.second + dx[i]; // 열  
				if (c>=0 && c<N && d>=0 && d<M){
					if (arr[c][d] == 1 && !visited[c][d]){
//						cout << c << " " << d << "\n";
						q.push( {c, d});
						visited[c][d] = true;
					}
				}
			}		
		}
		level++;
	}	
	return 0;
}