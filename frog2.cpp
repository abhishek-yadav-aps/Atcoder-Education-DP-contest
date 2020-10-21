#include<bits/stdc++.h>

#define ll long long int
#define llu unsigned long long int
#define f(n) for(ll i=0;i<n;i++)
#define fr(n) for(ll i=n-1;i>=0;i--)
#define endl "\n"
#define mod 1000000007

using namespace std;
vector <ll> v;
vector<ll> dp;

ll frog(ll i,ll n,ll k){
	if(i>=n){
		return 0;
	}
	for(ll j=1;j<=k;j++){
		if(dp[i+j]==-1 && i+j<=n){
			dp[i+j]=frog(i+1,n,k);
		}
	}
	ll v3=1000000000;
	for(ll j=1;j<=k;j++){
		if(i+j<=n){
			v3=min(v3,dp[i+j]+(abs(v[i+j]-v[i])));
		}
	}
	dp[i]=v3;
	return v3;
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	ll n,k;
	cin>>n>>k;
	v.push_back(0);
	f(n)
	{
		ll x;
		cin>>x;
		v.push_back(x);
	}
	f(n+1){
		dp.push_back(-1);
	}
	dp[0]=0;
	frog(1,n,k);
	cout<<dp[1];
	
	
	return 0;
}