#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string input;
stack<int> s; // ( -1, ) -2, [ -3, ] -4
int ans;

int main(){
	cin >> input;
	
	for (int i = 0 ; i < input.length() ; i++){
		char target = input[i];
		int temp = 0;
		
		if ( target == ')'){ 
			if (s.empty() || s.top() == -3 || s.top() == -4 || s.top() == -2){ // return 0 
				cout << 0;
				return 0;
			} else{
				if (s.top() == -1){ // 짝 찾은 경우 
					s.pop();
//					cout << 2 << endl;
					s.push(2);
				} else{ // 숫자인 경우 
					while (s.top() != -1) {
						if (s.empty() || s.top() == -3 || s.top() == -4 || s.top() == -2){ // return 0 
							cout << 0;
							return 0;
						} else{
							temp += s.top();
							s.pop();
							if (s.empty()){
								cout << 0;
								return 0;
							}
						}
					}
					s.pop();
//					cout << 2*temp << endl;
					s.push(2*temp);
				} 
			}
		} else if ( target == ']') {
			if (s.empty() || s.top() == -1|| s.top() == -2 || s.top() == -4){ // return 0 
				cout << 0;
				return 0;
			} else{
				if (s.top() == -3){ // 짝 찾은 경우 
					s.pop();
//					cout << 3 << endl;
					s.push(3);
				} else{ // 숫자인 경우 
					while (s.top() != -3) {
						if (s.empty() || s.top() == -1|| s.top() == -2 || s.top() == -4){ // return 0 
							cout << 0;
							return 0;
						} else{
							temp += (s.top());
							s.pop();
							if (s.empty()){
								cout << 0;
								return 0;
							}
						}
					}
					s.pop();
//					cout << 3*temp << endl;
					s.push(3*temp);
				} 
			}
		} else {
			if ( target == '('){
				s.push(-1); // ( : -1
//				cout << s.top() << endl;
			} else if ( target == '['){
				s.push(-3); // [ : -3
			}
		}
	}
	
	while (!s.empty()){
		if (s.top() == -1 || s.top() == -3 || s.top() == -4 || s.top() == -2){ // 괄호가 남아있는 경우, return 0 
			cout << 0;
			return 0;
		}
		ans += (s.top()); 
		s.pop();
	}
	
	cout << ans;
}

