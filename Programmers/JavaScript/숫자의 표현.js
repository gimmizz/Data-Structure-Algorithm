// 숫자의 표현 | 단순구현
// 종결조건만 잘 선언하면 전혀 문제 없는 단순한 구현 문제였다.
function solution(n) {
    var answer = 0;
    
    for (var i = n ; i > 0 ; i--){ // i : 시작숫자
        var temp = 0;
        for (var j = i ; j > 0 ; j --){
            temp += j;
            if (temp == n){
                answer += 1;
                break;
            } else if (temp > n){
                break;
            }
        }
    }
    
    return answer;
}