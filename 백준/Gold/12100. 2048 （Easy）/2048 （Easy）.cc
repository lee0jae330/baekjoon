#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr1[21][21];
int arr[21][21];
int N;
vector<int>v;
int result;

void move(int dir) {
	int flag,num;
	if (dir == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N-1; j++) { //0 처리
				if (!arr[j][i]) {
					for (int k = j + 1; k < N; k++) {
						if (arr[k][i]) {
							int tmp=arr[j][i];
							arr[j][i]=arr[k][i];
							arr[k][i]=tmp;
							break;
						}
					}
				}
			}
			flag=0, num=-1;
			for (int j = 0; j < N - 1; j++) {
				if (arr[j][i] && arr[j][i] == arr[j + 1][i]) {
					arr[j][i]*=2;
					arr[j+1][i]=0;
					flag=1;
				}
			}

			for (int j = 0; j < N - 1; j++) { //0 처리
				if (!arr[j][i]) {
					flag = 0;
					for (int k = j + 1; k < N; k++) {
						if (arr[k][i]) {
							swap(arr[j][i], arr[k][i]);
							flag = 1;
							break;
						}
					}
					if (!flag) //flag값이 계속 0이면 아래는 전부 0임 
						break;
				}
			}
		}
	}
	else if (dir == 2) { //오른쪽 
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j > 0; j--) {
				if (!arr[i][j]) {
					for (int k = j - 1; k >= 0; k--) {
						if (arr[i][k]) {
							swap(arr[i][j], arr[i][k]);
							break;
						}
					}
				}
			}
			flag=0,num=-1;
			for (int j = N - 1; j > 0; j--) {
				if (arr[i][j] && arr[i][j] == arr[i][j - 1]) {
					arr[i][j]*=2;
					arr[i][j-1]=0;
					flag=1;
				}
			}
			for (int j = N - 1; j > 0; j--) {
				if (!arr[i][j]) {
					for (int k = j - 1; k >= 0; k--) {
						if (arr[i][k]) {
							swap(arr[i][j], arr[i][k]);
							break;
						}
					}
				}
			}
		}
	}
	else if (dir == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j > 0; j--) {
				if (!arr[j][i]) {
					for (int k = j - 1; k >= 0; k--) {
						if (arr[k][i]) {
							swap(arr[j][i],arr[k][i]);
							break;
						}
					}
				}
			}
			flag=0,num=-1;
			for (int j = N - 1; j > 0; j--) {
				if (arr[j][i] && arr[j][i] == arr[j - 1][i]) {
					arr[j][i]*=2;
					arr[j-1][i]=0;
					flag=1;
				}
			}
			for (int j = N - 1; j > 0; j--) {
				if (!arr[j][i]) {
					flag = 0;
					for (int k = j - 1; k >= 0; k--) {
						if (arr[k][i]) {
							swap(arr[j][i], arr[k][i]);
							flag = 1;
							break;
						}
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N-1; j++) {
				if (!arr[i][j]) {
					flag=0;
					for (int k = j + 1; k < N; k++) {
						if (arr[i][k]) {
							swap(arr[i][j],arr[i][k]);
							flag=1;
							break;
						}
					}
				}
			}
			flag=0, num=-1;
			for (int j = 0; j < N - 1; j++) {
				if (arr[i][j] && arr[i][j] == arr[i][j + 1]) {
					arr[i][j]*=2;
					arr[i][j+1]=0;
					flag=1;
				}
			}
			for (int j = 0; j < N - 1; j++) {
				if (!arr[i][j]) {
					flag = 0;
					for (int k = j + 1; k < N; k++) {
						if (arr[i][k]) {
							swap(arr[i][j], arr[i][k]);
							flag = 1;
							break;
						}
					}
				}
			}
		}
	}
}

int visited[6][5];

void backtrack(int cnt) {
	
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j]=arr1[i][j];
			}
		}

		for (int i = 0; i < v.size(); i++) {
			move(v[i]);
		}
	
		int tmp=-1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				tmp = max(tmp,arr[i][j]);
			}
		}
		result = max(result, tmp);
		return;
	}

	for (int i = 1; i <= 4; i++) {
		if (!visited[cnt][i]) {
			v.push_back(i);
			visited[cnt][i]=1;
			backtrack(cnt+1);
			visited[cnt][i]=0;
			v.pop_back();
		}
	}
}


int main(void) {
	fastio();

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr1[i][j];
		}
	}
	backtrack(0);
	cout << result <<'\n';
	return 0;
}