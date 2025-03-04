#include<iostream>
#include<string>
using namespace std;

int main() {
	string line;
	int count[26] = { 0 };
	for (int i = 0; i < 4; ++i) {
		getline(cin, line);
		for (char c : line) {
			if (c >= 'A' && c <= 'Z') {
				count[c - 'A']++;
			}
		}
	}
	int maxCount = 0;
	for (int i = 0; i < 26; ++i) {
		if (count[i] > maxCount) {
			maxCount = count[i];
		}
	}
	for (int i = maxCount; i > 0; i--) {
		for (int j = 0; j < 26; j++) {
			if (count[j] >= i) {
				cout << "*";
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}
	for (int i = 0; i < 26; ++i) {
		cout << char('A' + i) << ' ';
	}
	return 0;
}