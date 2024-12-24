#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int N,M;

map<string,string>m;

string find(string x) {
	if (x == m[x]) {
		return x;
	}
	return m[x] = find(m[x]);
}

void merge(string x, string y, char result) {
	string rootX = find(x);
	string rootY = find(y);

	if (result == '1') {
		if (rootX == rootY) {
			if (x == rootX) {
				//x가 종주국, 종주국이 속국을 이기면 그냥 return
				return; 
			} else if(y == rootY) {
				//y가 종주국, 속국x가 이긴 것
				m[rootY] = x;
				m[x] = x; //x를 종주국으로
			}
		}
		else {
			//x가 이김
			m[rootY] = rootX;
		}
	}
	else {
		if (rootX == rootY) {
			if (x == rootX) {
				//x가 종주국, 속국y가 이김
				m[rootX] = y;
				m[y]=y;
			} else if(y==rootY) {
				//종주국 y가 이김
				return;
			}
		}
		else {
			//y가 이김
			m[rootX] = rootY;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);
		string name = str.substr(11);
		m[name] = name;
	}

	while (M--) {
		string str;
		getline(cin, str);
		
		int idx = str.find(',');
		string first = str.substr(0,idx);
		string x = first.substr(11);

		
		string tmp = str.substr(idx+1);
		idx = tmp.find(',');
		string second = tmp.substr(0,idx);
		string y = second.substr(11);

		char result = str[str.length()-1];
		
		/*
		cout << first <<'\n';
		cout << x <<'\n';
		cout << tmp << '\n';
		cout << second <<'\n';
		cout << y <<'\n';
		cout << result <<'\n';
		*/
		merge(x, y, result);
	}

	vector<string>v;
	for (auto iter : m) {
		if (iter.first == iter.second) {
			v.push_back(iter.first);
		}
	}
	cout << v.size()<<'\n';
	for (auto iter : v) {
		cout <<"Kingdom of " << iter << '\n';
	}
	
	return 0;
}