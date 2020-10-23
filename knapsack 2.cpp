#include <bits/stdc++.h>
#define MAX INT_MAX
#define MIN INT_MIN
#define ll long long int
#define for(i,s,e) for(ll i=(s);i<(e);i++)
#define  mod 1e9+7
using namespace std;

int main()
{
	ll n, w;
	cin >> n >> w;
	ll a[n + 1], b[n + 1];
	ll sum = 0;
	for (i, 1, n + 1)
	{
		cin >> a[i] >> b[i];
		sum += b[i];
	}
	ll ans = 0;
	vector<vector<ll>>dp(n + 1, vector<ll>(sum + 1, MAX));
	dp[0][0] = 0;
	for (i, 1, n + 1)
	{
		for (j, 0, sum + 1)
		{
			if (j == 0)
				dp[i][j] = 0;
			else if (b[i] <= j)
				dp[i][j] = min(a[i] + dp[i - 1][j - b[i]], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
			if (dp[i][j] <= w)
				ans = max(ans, j);
		}
	}
	cout << ans;
}