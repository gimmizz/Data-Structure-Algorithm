/*
* LeetCode Shortest distance to a character | 구현
* https://leetcode.com/problems/shortest-distance-to-a-character/submissions/
* 되게 단순한 데 조건 생각할 게 많았다,, 어떻게하면 더 짧게 구현할지 생각하며 공부했다!
*/

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> answer;
        for(int i = 0 ; i < s.length() ; i++){
            // 해당 글자가 e 일 경우
            if (s[i] == c) {
                answer.push_back(0);
                continue;
            }
            
            // 왼쪽으로 e 찾기
            int left = s.length();
            for (int j = i-1 ; j >= 0 ; j--){
                left = i-j;
                if (s[j] == c) break;
                if (j == 0) left = s.length(); // 끝까지 못찾은 경우
            }
            
            // 오른쪽으로 e 찾기
            int right = s.length();
            for (int j = i+1 ; j < s.length() ; j++){
                right = j-i;
                if (s[j] == c) break;
                if (j == s.length()-1) right = s.length(); // 끝까지 못찾은 경우
            }
            
            // 둘 비교해서 ans_vector에 추가
            // cout << left << " " << right << endl;
            answer.push_back(min(left, right));
        }
        
        return answer;
    }
};