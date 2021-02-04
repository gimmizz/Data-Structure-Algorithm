/*
* Level 2. 카펫 | 완전탐색
* for문을 통해 완전탐색 해보는 간단한 문제. 수학문제 같았다.
*/ 
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int m, n; // m(가로), n(세로)
    int mpn, mxn;
    mpn = (brown + 4)/2;
    mxn = brown + yellow;
    
    for (int i = 1 ; i <= mpn/2 ; i++){
        n = i; m = mpn-n;
        if (m*n == mxn){
            answer.push_back(m);
            answer.push_back(n);
            return answer;
        }
    }
    return answer;
}