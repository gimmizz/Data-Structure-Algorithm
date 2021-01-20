#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// 20000개 노드, 가중치가 10 이하니까 200000 값 이상이 나오기 힘드니까  
#define INF 300000 

struct Node{
   int end, dist;
   Node(int e, int d){
      end = e;
      dist = d;
   }
};

struct comp {
	bool operator()(Node a, Node b) {
		return a.dist > b.dist;
	}
};

int v, e, start_node, dist[20010];
vector<Node> adj[20010];

void dijk() {
	// priority_queue<자료형, 컨테이너, 비교함수>  
	priority_queue<Node, vector<Node>, comp> pq;
	
	dist[start_node] = 0;
	pq.push(Node(start_node, 0));
	while (!pq.empty()){
		Node cur = pq.top(); pq.pop();
//		// debug
//		printf("end : %d	dist : %d\n", cur.end, cur.dist) ;
		
		// cur의 주변을 탐색한다. 
		for (int i = 0 ; i < adj[cur.end].size() ; i++) {
			Node nxt = adj[cur.end][i];
			int temp = cur.dist + nxt.dist; // cur --> nxt 로 이동할 때 드는 비용 
			if (dist[nxt.end] > temp){
				dist[nxt.end] = temp;
				pq.push(Node(nxt.end, temp));
			}

		}
	}
}

int main() {
   scanf("%d%d%d", &v, &e, &start_node);
   
   //adj 배열 완성 
   for (int i = 0 ; i < e ; i++){
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c); // a --> b, 가중치가 c
      adj[a].push_back(Node(b, c));      
   }
   
//   // adj 배열 디버그용  
//    for(int i=0; i<=v; i++){
//        for(int j=0; j<adj[i].size(); j++){
//			  printf("cur: %d 	end : %d	dist : %d\n", i, adj[i][j].end, adj[i][j].dist) ;
//        }
//    }

   // dist 배열 초기화
   for (int i = 1; i <= v ; i++) dist[i] = INF; 
   
   // dijkstra
   dijk();
   
   // output, INF출력, 시작노드는 0 
   for (int i = 1 ; i <= v ; i++){
		if (dist[i] == INF) {
			printf("INF\n");
		} else{
    		printf("%d\n", dist[i]);
		}

   }
   
}
