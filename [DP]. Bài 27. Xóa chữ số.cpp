
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
long long dp[1000005];
int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1e18;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = i;
		while (tmp) {
			int d = tmp % 10;
			tmp /= 10;
			if (d) {
				dp[i] = min(dp[i], dp[i - d] + 1);
			}
		}
	}
	cout << dp[n];
}

