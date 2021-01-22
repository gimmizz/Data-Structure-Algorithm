#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin >> n;
	int q[n+1], s=0, e=0;
	
	for (int i = 0 ; i < n ; i++){
		string command;
		cin >> command;
		
		
		if (command == "push"){
			int command_num;
			cin >> command_num;
			q[e] = command_num;
			e++;
		} else if( command == "pop"){
			if (s == e){
				cout << -1 << endl;
			} else {
				cout << q[s] << endl;
				s++;
				
			}
		} else if ( command == "size"){
			cout << (e-s) << endl;
		} else if ( command == "empty"){
			if (s == e){
				cout << 1 << endl;
			} else{
				cout << 0 << endl;
			}
		} else if ( command == "front"){
			if ( s == e){
				cout << -1 << endl;
			} else{
				cout << q[s] << endl;
			}
		} else if ( command == "back"){
			if ( s == e){
				cout << -1 << endl;
			} else{
				cout << q[e-1] << endl;
			}
		}
	}
}