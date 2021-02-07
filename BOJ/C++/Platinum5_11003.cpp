/*
* 11003번 최솟값 찾기 |  우선순위큐, 슬라이딩 윈도우   
* 윈도우 사이즈 넘어서는(기간이 지난) 원소들은 없애주어야 하는데, 내가 궁금한 건, 이 중 최솟값에 영향을 주는 것 -> 힙으로 kill 원소를 모아놓자.
* 덱 유형인데, pq로도 풀 수 있다.  
*/
#include <iostream>
#include <queue>
using namespace std; 

int N, L;
int inputs[5000001];
	
priority_queue< int, vector<int>, greater<int> > pq; // 최소힙 
priority_queue< int, vector<int>, greater<int> > kill; // 최소힙 (kill)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> L;

	for (int i = 0 ; i < N ; i++){
		cin >> inputs[i]; // input을 미리 받는다.  
	}
		
	for (int i = 0 ; i < N ; i++){
		pq.push(inputs[i]);
		if ( i >= L ){
			kill.push(inputs[i-L]);
		}
		while ( !kill.empty() && pq.top() == kill.top()){
			pq.pop(); kill.pop();
		}
		
		cout << pq.top() << " "; // 최소값 출력  
	}
	return 0;
}