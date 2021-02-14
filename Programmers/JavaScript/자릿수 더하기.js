// 자릿수 더하기 | 수학
// javascript에서 parseInt 함수 처음 써봤다. 이 방법만 알면, 간단한 문제
function solution(n)
{
    var answer = 0;
    console.log(n);
    while ( n / 10 != 0){
        answer += (n % 10);
        n = parseInt(n/10)
        console.log(n, answer);
    }

    return answer;
}