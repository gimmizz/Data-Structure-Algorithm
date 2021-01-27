/*
* 17509번 And the Winnder Is.. Ourselves! | 그리디 알고리즘, 정렬 
* 쉬웠다! 아주 쉬운 그리디 
*/
#include <algorithm>
#include <iostream>
using namespace std;

int D[12], V[12], penalty;

int main(){
	for (int i = 0 ; i < 11 ; i ++){
		cin >> D[i] >> V[i];
	}
	sort(D, D+11);
	
	// penalty 점수 합 구하기
	for (int i = 0 ; i < 11 ; i++){
		penalty += D[i] * (11-i) + V[i] * 20;
	} 
	
	cout << penalty;
} 
