/*
* 1927번 최소 힙 | 우선순위 큐  
* 최대 힙 문제와 흡사하다. 근데 greater 쓰려면 functional 헤더 추가해야하는데 그냥 해도 되는군 !  
*/
#include <iostream>
#include <queue>
using namespace std;

int N, a;
priority_queue< int, vector<int>, greater<int> > pq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0 ; i < N ; i++){
		cin >> a;
		if ( a > 0 ){
			pq.push(a);
		} else if ( a == 0 ){
			if ( pq.empty() ){
				cout << "0\n";
			} else{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
	return 0;
}