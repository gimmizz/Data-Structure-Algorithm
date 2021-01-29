/*
* 11286번 절댓값 힙 | 우선순위 큐, 구현  
* 약간의 응용. pair형 힙으로 만들어서, 원래 값도 저장하도록 했다. 어렵지 않지만, comp 구조체 처음 써봐서 뿌듯한 문제 유후!  
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct comp{
	bool operator()(pair<int, int> a, pair<int, int> b){ // a : 절댓값, b : 원래 값 
		if ( a.first == b.first ){
			return a.second > b.second;
		}
		return a.first > b.first;
	}
};


int N, command; 
priority_queue < pair<int, int>, vector<pair<int, int> >, comp > pq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	cin >> N;
	for (int i = 0 ; i < N ; i++ ){
		cin >> command;
		if ( command != 0 ){
			pq.push({abs(command), command});
		} else{
			if (pq.empty()){
				cout << "0\n";
			} else{
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
	}
	return 0;
}