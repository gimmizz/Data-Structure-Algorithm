function solution(array, commands) {
    var answer = [];
    var temp = [];
    for (var i=0 ; i < commands.length ; i++){
        temp = array.slice(commands[i][0]-1, commands[i][1]);
        temp.sort(function(a,b){
            return a-b;
        });
        // console.log(temp);
        answer.push(temp[commands[i][2]-1]);
    }
    return answer;
}

// arr.sort([compareFunction])
// compareFunction 값이 생략되면, 배열의 element들은 문자열로 취급되어, 유니코드 값 순서대로 정렬된다.
// 두 개의 배열 elememt(ex. a,b)를 파라미터로 입력 받아, 
// return 값이 0보다 작으면 a,b 의 순으로 / 0보다 크면 b,a / 같으면 순서를 변경하지 않는다.