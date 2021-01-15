function solution(arr)
{
    var answer = [];
    var prev = arr[0];
    answer.push(prev);
    for (var cur=1 ; cur < arr.length ; cur++){
        if (prev != arr[cur]){
            answer.push(arr[cur]);
        }
        prev = arr[cur]; 
    }

    return answer;
}

// var, let, const 차이
// var: 변수를 한 번 더 선언해도 에러가 나오지 않는다.
// let: 한 번 더 선언 시, 에러 + mutable
// const: immutable, 변수값 수정이 불가하다. 