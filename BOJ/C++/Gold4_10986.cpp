/*
* 10986번 나머지의 합 | 누적합
* 누적합을 이용하고, 쌍 매칭을 효율적으로 하면 되는 문제. 문제 자체는 그렇게 어려운건 아니지만, 평소에 누적합을 잘 안 써서 푸는데 오래걸렸다
*/
#include <bits/stdc++.h>

using namespace std;


long long n, m;
long long arr[1000001];
long long k;
long long gogo[1001];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	arr[0] = 0;
	memset(gogo, 0, 1000);
	long long answer = 0;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		arr[i] = (arr[i - 1] + k)%m;
		gogo[arr[i]] += 1;
	}
	answer += (gogo[0] + (gogo[0] * (gogo[0] - 1)) / 2);
	for (int i = 1; i < m;i++) {
		answer += (gogo[i] * (gogo[i] - 1)/ 2);
	}
	

	cout << answer;
	return 0;
}