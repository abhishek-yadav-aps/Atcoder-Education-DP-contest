#include<bits/stdc++.h>

#define ll long long int
#define llu unsigned long long int
#define f(n) for(ll i=0;i<n;i++)
#define fr(n) for(ll i=n-1;i>=0;i--)
#define endl "\n"
#define mod 1000000007

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);

	ll n;
	cin>>n;
	vector <double> v;
	v.push_back(0.0);
	f(n)
	{
		double x;
		cin>>x;
		v.push_back(x);
	}
	vector<vector<double>> dp(n+1,vector<double>(n+1,0.0));
	dp[0][0]=1.0;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=i;j++){
			if(j==0){
				dp[i][j]=dp[i-1][j]*(1.0-v[i]);
			}
			else{
				dp[i][j]=dp[i-1][j-1]*(v[i]) + dp[i-1][j]*(1.0-v[i]);
			}
		}
	}
	double ans=0;
	for(ll i=(n+1)/2;i<=n;i++){
		ans+=dp[n][i];
	}
	cout<<setprecision(10)<<fixed<<ans;
	
	return 0;
}