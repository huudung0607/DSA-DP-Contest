
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
long long dp[505][505];
int main()
{
	int a, b; cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (i == j) dp[i][j] = 0;
			else {
				dp[i][j] = 1e9;
				for (int k = 1; k < i; k++) {
					dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
				}
				for (int k = 1; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
				}
			}
		}
	}
	cout << dp[a][b];
}

