/*
* Level 1 하샤드 수 | 구현
* 자릿수합 문제. 아주 간단! Level 1 배지용
*/
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int copy = x;
    int sum_x = 0;
    while (copy){
        sum_x += copy % 10;
        copy = copy / 10;
    }
    if ( x % sum_x == 0){
        return true;
    } else{
        return false;
    }
}