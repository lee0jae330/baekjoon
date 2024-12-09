#include<iostream>
#include<algorithm>

using namespace std;

const int SIZE = 5;

int A[SIZE][SIZE];
int B[SIZE][SIZE];
int total[SIZE][SIZE];

string name[5] = {
	"Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki"
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				total[i][j] += A[i][k] * B[k][j];
			}
		}
	}
		
	int sol[5]= {0,};
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			sol[i] +=total[i][j];
		}
	}

	int min = *min_element(begin(sol), end(sol));
	
	for (int i = SIZE - 1; i >= 0; i--) {
		if (sol[i] == min) {
			cout << name[i] <<'\n';
			return 0;
		}
	}
	

	return 0;
	
}