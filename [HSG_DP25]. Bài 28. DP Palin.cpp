
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
int F[5005][5005];
int main()
{
	string s; cin >> s;
	int n = s.size();
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		F[i][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i + 1]) F[i][i + 1] = 1;
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j + i - 1 <= n; j++) {
			int k = j + i - 1;
			if (s[j] == s[k] && F[j + 1][k - 1]) {
				F[j][k] = 1;
			}
		}
	}
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		if (F[l][r]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

