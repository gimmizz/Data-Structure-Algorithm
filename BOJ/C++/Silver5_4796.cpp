/*
* 4706번 캠핑 | 그리디 알고리즘, 수학 
* 그리디 알고리즘 입문용 문제. 
*/

#include <iostream>
#include <algorithm>
using namespace std;

int L, P, V, cnt=0, answer;

int main(){
	cin >> L >> P >> V;
	
	while (L!=0 && P!=0 & V!=0){ 
		// case 별 선언
		answer = 0; 
		cnt++;
		
		while (V > 0){ // V : remaining days
			if ( V >= P){ // P 기간 만큼 남으면, 무조건 L days를 캠핑  
				answer += L;
				V -= P;
			} else{  // l과 V(남은 기간) 중 최소 값만큼 캠핑 가능. 
				answer += min(L, V);
				V = 0;
			}
		}
		cout << "Case " << cnt << ": " << answer << endl;
		cin >> L >> P >> V;
	}
}