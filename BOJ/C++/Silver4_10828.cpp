#include <bits/stdc++.h>
using namespace std;

int n, command_num;
string command;
vector<int> s;

int main(){
	scanf("%d", &n);
	
	for (int i = 0 ; i < n ; i++){
		cin >> command;
		if (command == "push"){
			cin >> command_num;
			s.push_back(command_num);
		} else if (command == "pop"){
			if (s.size() == 0){
				cout << -1 << endl;
			} else {
				cout << s.back() << endl;
				s.pop_back();
			}

		} else if (command == "size"){
			cout << s.size() << endl;
		} else if (command == "empty"){
			cout << (s.size()==0) << endl;
		} else if (command == "top"){
			if (s.size() == 0){
				cout << -1 << endl;
			} else{
				cout << s.back() << endl;
			}
		}
	}
}