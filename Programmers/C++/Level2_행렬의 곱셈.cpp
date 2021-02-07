/*
* Level 2 행렬의 곱셈 | 구현, 수학 
* vector의 size를 미리 정해놓으려는 생각 말자. vector를 제대로 쓰지 않고 있는 것.
*/
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int a = arr1.size();
    int b = arr2[0].size();
    int c = arr1[0].size(); // axc, cxb -> axb 행렬
    
//     // answer 벡터 resize
//     answer.resize(a);
//     for (int i = 0 ; i < answer.size() ; i++){
//         answer[i].resize(c);
//     }
    
    // answer 벡터 채우기
    for (int i = 0 ; i < a ; i++){
        vector<int> temp;
        for (int j = 0 ; j < b; j++){
            int sum = 0;
            for (int k = 0 ; k < c; k++){
                sum += (arr1[i][k] * arr2[k][j]);
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }
    
    return answer;
}