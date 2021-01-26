/*
* 1449번 캠핑 | 그리디 알고리즘, 정렬 
* 생각하기 쉬웠는데, 정렬을 안해서 틀리게 하는건 너무해! 
*/
#include <algorithm>
#include <iostream>
using namespace std;

int N, L, cnt;

int main(){
	cin >> N >> L;
	
	int arr[1001];
	int cur = 0;
	
	// arr 초기화
	for (int i = 0 ; i < N ; i++){
		cin >> arr[i]; 
	}
	sort(arr,arr+N);
	for (int i = 0 ; i < N ; i++){
		while ( cur < arr[i] ){
			cur = arr[i];
			cur += (L-1);
			cnt++;
		}
	}
	cout << cnt;
} 
