/*
* 11279번 최대 힙  |
* queue 헤더를 사용해 pq로 간단히 풀었다. 아주 기초! + endl은 시간초과 뜨니까 주의.. 
*/
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int N, a;

int main(){
	scanf("%d", &N);
	priority_queue< int, vector<int>, less<int> > pq;
	for (int i = 0 ; i < N ; i++){
		scanf("%d", &a);
//		cin >> a;
		if ( a > 0 ){
			pq.push(a);
		} else if ( a == 0 ){
			if ( pq.empty() ){
				printf("0\n");
//				cout << 0 << endl;
			} else {
				printf("%d\n", pq.top());
//				cout << pq.top() << endl;
				pq.pop();
			}
		}
		
	}
}