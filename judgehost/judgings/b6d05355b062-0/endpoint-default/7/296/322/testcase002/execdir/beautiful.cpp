//uva11472
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int dp[101][11][1025];

int main() {
	int t, n, m;
	while (cin >> t)
	while (t--) {
		cin >> n >> m;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i < n; ++i)
			dp[0][i][1 << i] = 1;
		int u = 1 << n, b1, b2;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 1; k < u; ++k) {
					b1 = k | (1 << (j - 1));
					if (j > 0)
						dp[i + 1][j - 1][b1] = (dp[i + 1][j - 1][b1] + dp[i][j][k]) % 1000000007;
					b2 = k | (1 << (j + 1));
					if (j < n - 1)
						dp[i + 1][j + 1][b2] = (dp[i + 1][j + 1][b2] + dp[i][j][k]) % 1000000007;
				}
			}
		}
		
		int sum = 0;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				sum = (sum + dp[i][j][u - 1]) % 1000000007;

		cout << sum << endl;
	}
	return 0;
}