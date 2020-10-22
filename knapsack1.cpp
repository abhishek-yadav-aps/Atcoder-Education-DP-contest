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

	ll n,tw;
	cin>>n>>tw;
	vector<ll> w,v;
	w.push_back(0);
	v.push_back(0);
	f(n){
		ll x,y;
		cin>>x>>y;
		w.push_back(x);
		v.push_back(y);
	}
	vector<vector<ll>> dp(n+1,vector<ll>(tw+1,0));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=tw;j++){
			ll v1=dp[i-1][j];
			ll v2=0;
			if(j-w[i]>=0){
				v2=dp[i-1][j-w[i]]+v[i];
			}
			dp[i][j]=max(v1,v2);
		}
	}
	cout<<dp[n][tw];
	
	return 0;
}