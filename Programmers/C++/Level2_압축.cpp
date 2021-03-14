/*
* 2018카카오블라인드 [3차] 압축 | 문자열, 구현
* https://programmers.co.kr/learn/courses/30/lessons/17684
* c++에서의 find함수, string->char(c_str, typeid등 다양하게 검색해봤는데, 생각해보니 아주 간단했다..ㅎ)를 검색하느라 애 먹었지만
* 처음 생각했던 로직이 잘 들어맞아서 기분 좋았다!
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dict; // 27번 부터 저장할 것 // 'A(65)'
    
    for (int i = 0 ; i < msg.length() ; i++){
        string temp = "";
        temp += msg[i];
        while (find(dict.begin(), dict.end(), (temp + msg[i+1])) != dict.end()){
            // dict에 다음글자가 있는 경우
            temp += msg[i+1];
            i++;
        } 
        if (temp.length() == 1){
            answer.push_back(temp[0] - 'A' + 1);
            dict.push_back(temp + msg[i+1]); // 다음 글자 dict에 추가
        } else{ //temp 2글자 이상일때 : dict에 찾아서 index_num + 27
            answer.push_back(find(dict.begin(), dict.end(), temp) - dict.begin() + 27); 
            dict.push_back(temp + msg[i+1]); // 다음 글자 dict에 추가
        }
    }
    
    return answer;
}