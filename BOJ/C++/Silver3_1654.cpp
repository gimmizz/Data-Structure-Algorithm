/*
* 랜선 자르기 | 이분 탐색
* 단순한 이분 탐색문제! 이분탐색을 여러번 해주면 된다
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

long long n, k;
long long lan[10001];


int main() {
	cin >> k >> n;
	for (long long i = 0; i < k; i++) {
		cin >> lan[i];
	}
	long long a = 0;
	long long b = pow(2, 31) - 1;
	long long c;
	long long answer;
	while (a < b) {
		answer = 0;
		c = (a + b+1) / 2;
		for (long long i = 0; i < k; i++) {
			long long k = lan[i];
			while (k >= c) {
				k -= c;
				answer++;
			}
		}
			if(answer >= n){
				a = c;
			}
			else {
				b = c-1;
			}
		}
	cout << a;
}