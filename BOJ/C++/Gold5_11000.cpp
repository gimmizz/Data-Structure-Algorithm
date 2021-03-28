/*
* 11000번 강의실 배정 | 그리디
* 우선순위큐를 사용하면 그리디처럼 풀수 있다. (내가 풀었던거에 비해..) 난이도가 제법 있지만 예전에 풀어본 유형이라 풀수 있었다!
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int main(int argc,char* argv[]){
	int N;
	pair<int, int> p[200001];
	priority_queue<int, vector<int>, greater<int> > pri;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + N);
	pri.push(p[0].second);
	for (int i = 1; i < N; i++) {
		if(pri.top()<=p[i].first){
		pri.pop();
		pri.push(p[i].second);
	}
		else {
			pri.push(p[i].second);
		}
}
	cout << pri.size();
	return 0;
}