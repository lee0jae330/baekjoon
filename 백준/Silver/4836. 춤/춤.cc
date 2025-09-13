#include<iostream>
#include<string>

#include<vector>
#include<set>
#include<algorithm>

using namespace std;

set<int>rules;
vector<string>tokens;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;

	while (getline(cin, str)) {
		string input = str;

		rules.clear();
		tokens.clear();

		int pos = 0;
		while (((pos = input.find(' ')) != string::npos)) {
			string token = input.substr(0, pos);
			tokens.push_back(token);
			input.erase(0, pos + 1);
		}
		tokens.push_back(input);

		// 4번
		if (tokens[0] == "jiggle") {
			rules.insert(4);
		}

		// 5번
		int flag = 0;
		if (find(tokens.begin(), tokens.end(), "dip") == tokens.end()) {
			rules.insert(5);
		}


		// 3번
		if (find(tokens.begin(), tokens.end(), "twirl") != tokens.end() && find(tokens.begin(), tokens.end(), "hop") == tokens.end()) {
			rules.insert(3);
		}

		int sz = tokens.size();

		// 2번
		if (sz < 3 || !(tokens[sz - 3] == "clap" && tokens[sz - 2] == "stomp" && tokens[sz - 1] == "clap")) {
			rules.insert(2);
		}

		// 1번
		for (int i = 0; i < sz; i++) {
			if (tokens[i] == "dip") {
				int flag = 0;
				if (i > 0 && tokens[i - 1] == "jiggle") {
					flag = 1;

				}
				if (i > 1 && tokens[i - 2] == "jiggle") {
					flag = 1;
				}

				if (i < sz - 1 && tokens[i + 1] == "twirl") {
					flag = 1;
				}

				if (!flag) {
					tokens[i] = "DIP";
					rules.insert(1);
				}
			}
		}

		if (rules.empty()) {
			cout << "form ok: " << str << '\n';
		}
		else {
			cout << "form ";
			
			int ruleSz = rules.size();
				
			if (ruleSz == 1) {
				cout << "error ";
			}
			else {
				cout << "errors ";
			}

			int num = 0;
			for (auto iter = rules.begin(); iter != rules.end(); iter++) {
				cout << *iter;
				num++;
				if (num == ruleSz) {
					cout << ": ";
				}
				else if (num == ruleSz - 1) {
					cout << " and ";
				}
				else {
					cout << ", ";
				}

			}

			for (int i = 0; i < sz; i++) {
				cout << tokens[i];
				if (i < sz - 1) {
					cout << ' ';
				}
				else {
					cout <<'\n';
				}
			}
		}
	}
	return 0;
}