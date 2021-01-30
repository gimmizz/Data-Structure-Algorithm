/*
* Level 2. 점프와 순간 이동 | 수학
* 원리만 생각하면 간단히 풀수 있는 쉬운 문제.
*/
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while ( n/2 != 0 ){
        // cout << n << " " << ans << endl;
        if ( n % 2 == 0 ){
            n = n/2;
        } else{
            n = (n-1) ;
            ans++;
        }
    }
    return ans+1;
}