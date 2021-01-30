/*
* Level 2. n진수 게임
* 전형적인 n진수문제. 간단하다. python이었다면 더 쉬웠을 것 같다. repeat 변수가 음수로 넘어갈 경우도 있었는데, repeat > 0 이 아닌, 
* repeat != 0 으로 루프를 돌려서 무한루프를 해결하지 못해 풀지 못했다.. 으아 너무 아쉽다.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

char intToChar[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E' ,'F'};

string solution(int n, int t, int m, int p) {
    string answer = "";
    string turn = "";
    int repeat = t * m;
    int num = 0;
    while (repeat > 0){
        string temp = "";
        int copy_num = num;
        while (copy_num/n > 0){
            temp = intToChar[copy_num%n] + temp;
            copy_num /= n;
        }
        temp = intToChar[copy_num%n] + temp;
        repeat -= temp.length(); // num(10진법 숫자)를 char로 바꾼 문자열의 길이만큼 빼기
        turn = turn + temp;
        num++;
    }
    for (int i = 0 ; i < t*m ; i++){
        if ( i % m == p-1){
            answer = answer + turn[i];
        }
    }
    return answer;
}