/*
* Level 2. 조이스틱 | Greedy
* greedy라는 걸 알고 접근해서 조금 더 쉽게 풀었을 것 같은데, 모르고 풀었으면 더 오래 걸릴 뻔 했다. 방향이 바뀔 수도 있다는 것을 처음에는 인지 못했는데, 테스트케이스 혼자 해보면서 깨달았다. 구현해내는 속도가 더 빠르면 좋을 것 같다.. 아직은 너무 느리다!
*/
#include <string>
#include <iostream>
using namespace std;
 
int solution(string name) {
    int answer=0;
    string match(name.length(), 'A');
    int cur = 0;
    cout << match << endl;
    while (name != match){
        cout << match << endl;
        // 현재 값 변경
        answer += min(name[cur]-'A', 'Z'-name[cur]+1);
        match[cur] = name[cur];
        if (name == match){
            return answer;
        }
        // 왼쪽, 오른쪽 방향으로 다를 때까지 이동하는 횟수가 작은 쪽으로 이동.
        // 왼쪽 count
        int left_idx = cur;
        int left_cnt = 0;
        while (name[left_idx] == match[left_idx]){
            left_idx--;
            left_cnt++;
            if(left_idx == -1){ // 범위가 벗어날 경우
                left_idx = name.length() - 1;
            }
        }
        // 오른쪽 count
        int right_idx = cur;
        int right_cnt = 0;
        while (name[right_idx] == match[right_idx]){
            right_idx++;
            right_cnt++;
            if(right_idx == name.length()){ // 범위가 벗어날 경우
                right_idx = 0;
            }
        }
        // 왼쪽, 오른쪽 중 작은 경우의 방향으로 이동
        if (left_cnt < right_cnt){
            cur = left_idx;
            answer += left_cnt;
        } else{
            cur = right_idx;
            answer += right_cnt;
        }
    }
    
    return answer;
}