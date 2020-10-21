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

ll frog(ll i,ll n){
	if(i>=n){
		return 0;
	}

	if(dp[i+1]==-1){
		dp[i+1]=frog(i+1,n);
	}
	if(dp[i+2]==-1){
		dp[i+2]=frog(i+2,n);
	}
	ll v3=0;
	if(i+2<=n){
		v3=min(dp[i+1]+(abs(v[i+1]-v[i])),dp[i+2]+(abs(v[i+2]-v[i])));
		
	}
	else if(i+1<=n){
		v3=dp[i+1]+(abs(v[i+1]-v[i]));
		
	}
	dp[i]=v3;
	return v3;
}

int main()
{
	//#ifdef ONLINE_JUDGE
	freopen("inputDP.txt","r",stdin);
	freopen("outputDP.txt","w",stdout);
	//#endif
	std::ios_base::sync_with_stdio(false);

	ll n;
	cin>>n;
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
	frog(1,n);
	cout<<dp[1];
	
	return 0;
}