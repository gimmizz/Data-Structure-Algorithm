/*
* 2252번 줄 세우기 | 그래프, 위상정렬
* 위상정렬 유형은 처음이라, 개념을 보고 구현해냈다. queue를 통해 구현하는것 기억해야겠다!
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

queue<int> que;
vector<int> adj[32001];
int come[32001];
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   memset(come,0,sizeof(come));
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      come[b]++;
   }
   for(int i=1;i<=n;i++){
      if(come[i]==0){
         que.push(i);
      }
   }
   while(!que.empty()){
      int cur=que.front();
      que.pop();
      cout<<cur<<" ";
      for(int item:adj[cur]){
         come[item]--;
         if(come[item]==0){
            que.push(item);
         }
      }
   }
   
   return 0;
}
