
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <int> prefix(string pattern) {
	int l = pattern.size();
	vector <int> tabel(l, 0);
	int i = 1;
	int pref_match = 0;
	while (i < l) {
		if (pattern[i] == pattern[pref_match]) {
			pref_match++;
			tabel[i] = pref_match;
			i++;
		}
		else if (pref_match == 0) {
			tabel[i] = pref_match;
			i++;
		}
		else {
			pref_match = tabel[pref_match - 1];
		}

	}
	return tabel;

}



void KMP(string pattern, string text) {
	string both = pattern + "$" + text;
	vector <int> func = prefix(pattern);
	vector<int> bigtext = prefix(both);
	int n = pattern.size();
	
	vector <int> answer;
	
	int m = both.size();
	
	for (int i = n + 1; i < m; i++) {
		if (bigtext[i] == n) {
			answer.push_back(i - (2 * n));
		}
	}
	
	cout << "Prefix template: ";
	for (int i = 0; i < func.size(); i++) {
		cout << func[i] << " ";
	}
	cout << endl;
	cout << "Prefix function: ";
	for (int i = 0; i < bigtext.size(); i++) {
		cout << bigtext[i] << " ";
	}
	cout << endl;
	cout << "Matches: ";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}




int main()
{
	string pattern;
	string text;
	cin >> pattern;
	cin >> text;
	KMP(pattern, text);
}

