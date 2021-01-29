/*
* Level 1 두 정수 사이의 합 | 구현
* 이전에 푼 문제라 바로 구현했다. Level 1 배지용!
*/
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    for (int i = min(a,b) ; i <= max(a,b) ; i++){
        answer += i;
    }
    return answer;
}