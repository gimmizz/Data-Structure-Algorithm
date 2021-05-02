/*
* 17144번 미세먼지 안녕! | 구현
* 그냥 구현문제. 문제 조건 그대로 구현하면 된다.
*/
#include <iostream>
#include <string.h>
using namespace std;

int R,C,T;
int arr[50][50];
int temp[50][50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int new_x, new_y, cnt;
int up,down;
bool found;

void step1(){
	for (int r=0;r<R;r++){
		for (int c=0;c<C;c++){
			if (arr[r][c] != 0){
				cnt = 0;
				for (int i=0;i<4;i++){
					new_x = r + dx[i];
					new_y = c + dy[i];
					
					if (new_x >= 0 && new_x < R && new_y >=0 && new_y < C && arr[new_x][new_y] != -1){
						cnt++;
						temp[new_x][new_y] += (arr[r][c]/5);
					}
				}
				temp[r][c] += (arr[r][c] - (arr[r][c]/5) * cnt);
			}
		}
	}
}
	
void step2(){
	// up 순환
	for (int r=0;r<R;r++){
		for (int c=0;c<C;c++){
			arr[r][c] = temp[r][c];
		}
	}
	
	// 1. up 포함된 row
	arr[up][1] = 0;
	for (int i=1;i<C-1;i++){
		arr[up][i+1] = temp[up][i];
	}
	// 2. 오른쪽
	for (int i=0;i<up;i++){
		arr[i][C-1] = temp[i+1][C-1];
	} 
	// 3. row 0
	for (int i=0;i<C-1;i++){
		arr[0][i] = temp[0][i+1];
	} 
	// 4. 왼쪽
	for (int i=1;i<up;i++){
		arr[i][0] = temp[i-1][0];
	} 
	
	// down 순환
	// 1. down 포함된 row
	arr[down][1] = 0;
	for (int i=1;i<C-1;i++){
		arr[down][i+1] = temp[down][i];
	}
	// 2. 오른쪽
	for (int i=down;i<R;i++){
		arr[i+1][C-1] = temp[i][C-1];
	} 
	// 3. row R
	for (int i=0;i<C-1;i++){
		arr[R-1][i] = temp[R-1][i+1];
	} 
	// 4. 왼쪽
	for (int i=down+1;i<R-1;i++){
		arr[i][0] = temp[i+1][0];
	} 
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> R >> C >> T;
	for (int r=0;r<R;r++){
		for (int c=0;c<C;c++){
			cin >> arr[r][c];
			if(arr[r][c] == -1){
				if (!found){
					up = r;
					found = true;
				} else{
					down = r;
				}
			}
		}
	}
	
	for(int t=0;t<T;t++){
		memset(temp, 0, sizeof(temp));
		step1();
		step2();
	}
	
	int sum = 2;
	for (int r=0;r<R;r++){
		for (int c=0;c<C;c++){
			sum += arr[r][c];
		}
	}	

	cout << sum;
	return 0;
}