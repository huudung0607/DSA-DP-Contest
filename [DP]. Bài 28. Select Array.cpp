
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
int a[100005];
long long dp[100005][105];
const int mod = 1e9 + 7;
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (a[1] == 0) {
		for (int i = 1; i <= m; i++) dp[1][i] = 1;
	}
	else {
		dp[1][a[1]] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (a[i] == 0) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % mod + dp[i - 1][j + 1]) % mod;
			}
		}
		else {
			int j = a[i];
			dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % mod + dp[i - 1][j + 1]) % mod;
		}
	}
	int res = 0;
	for (int i = 1; i <= m; i++) {
		res = (res + dp[n][i]) % mod;
	}
	cout << res;
}

