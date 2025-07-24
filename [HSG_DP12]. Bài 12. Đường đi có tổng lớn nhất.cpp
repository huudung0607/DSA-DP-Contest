
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

int dx[3] = { -1,0,1 };
int dy[3] = { 1,1,1 };
int a[1005][1005];
long long F[1005][1005];
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		F[i][1] = a[i][1];
	}
	for(int j = 2;j <= m;j++){
		for(int i= 1;i <= n;i++){
			F[i][j] = F[i][j - 1] + a[i][j];
			if (i > 1) {
				F[i][j] = max( F[i][j],F[i - 1][j - 1] + a[i][j]);
			}
			if (i < n) {
				F[i][j] = max( F[i][j],F[i + 1][j - 1] + a[i][j]);
			}
		}
	}
	long long res = -100000;
	for (int i = 1; i <= n; i++) {
		res = max(res, F[i][m]);
	}
	cout << res;
}

