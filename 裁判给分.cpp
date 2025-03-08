#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

double calculateScore(const vector<int>& scores) {
	int minScore = *min_element(scores.begin(), scores.end());
	int maxScore = *max_element(scores.begin(), scores.end());
	int sum = 0;
	for (int score : scores) {
		sum += score;
	}
	sum -= minScore + maxScore;
	return static_cast<double>(sum) / (scores.size() - 2);
}

int main() {
	int n, m;
	cin >> n >> m;
	double maxScore = 0;

	for (int i = 0; i < n; ++i) {
		vector<int> score(m);
		for (int j = 0; j < m; ++j) {
			cin >> score[j];
		}
		double current = calculateScore(score);
		if (current > maxScore) {
			maxScore = current;
		}
	}
	cout << fixed << setprecision(2) << maxScore << endl;
	return 0;
}