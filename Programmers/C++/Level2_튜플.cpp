/*
* Level 2. 튜플(2019 카카오 개발자 겨울 인턴십) | 문자열처리
* c++에게 문자열처리는 아주 고약하다,, python이었다면 split으로 간단히 구현할 수 있었을 텐데. find 유형의 문제는 map에 저장하는 방식을 생각하자.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector< pair< int, vector<int> > > a;
    // vector<vector<char>> tmp = {{1,2}, {3, 1, 2}, {2}};
    // cout << tmp[0].size();
    vector<int> tmp;
    int num = 0 ;
    for (int i = 1 ; i < s.size()-1 ; i++){
        if (s[i] == '{'){
            continue;
        } else if (s[i] == '}'){
            tmp.push_back(num);
            // cout << "num: " << num << endl;
            num = 0;
            // tmp 에 모인 원소들을 큰 vector a에 추가
            a.push_back({tmp.size(), tmp});
            // 새 시작
            tmp.clear();
        } else if (s[i] == ','){
            if (s[i-1] == '}'){
                continue;
            }
            tmp.push_back(num);
            // cout << "num: " << num << endl;
            num = 0;
        } else { // 숫자인 경우
            num *= 10;
            num += (s[i] - '0');
        }
    }
    
    sort(a.begin(), a.end()); // 각 내부vector의 크기(size변수)로 정렬
    // cout << "a 크기" << a.size() << endl;
    
    map<int, int> dict;
    for (int i = 0 ; i < a.size() ; i++){
        vector<int> sub_vec = a[i].second;
        for ( int j = 0 ; j < sub_vec.size(); j++){
            int element = sub_vec[j];
            if (dict[element] != 1){ // 새로운 원소 발견
                answer.push_back(element);
                dict[element] = 1;
            }
            
        }
    }
    return answer;
}