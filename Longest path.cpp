#include<bits/stdc++.h>

#define ll long long int
#define llu unsigned long long int
#define f(n) for(ll i=0;i<n;i++)
#define fr(n) for(ll i=n-1;i>=0;i--)
#define endl "\n"
#define mod 1000000007

using namespace std;
vector<vector<ll>> v(1000000);
ll l=0;
vector<ll> dp(1000000,-1);

ll path(ll x){
	ll lg=0;
	if(dp[x]==-1){
		for(ll i=0;i<v[x].size();i++){
			lg=max(lg,path(v[x][i]));
		}
		dp[x]=lg;
		return dp[x]+1;
	}
	else{
		return dp[x]+1;
	}
}

int main()
{
	
	std::ios_base::sync_with_stdio(false);

	ll n,m;
	cin>>n>>m;
	vector<vector<ll>> vv(1000000);
	vector<ll> a;
	f(m){
		ll x,y;
		cin>>x>>y;
		v[x].push_back(y);
		vv[y].push_back(x);
	}
	for(ll i=1;i<=n;i++){
		if(vv[i].size()==0)
		{
			a.push_back(i);
		}
	}
	ll ans=0;
	for(ll i=0;i<a.size();i++){
		ans=max(ans,path(a[i])-1);
	}
	cout<<ans;
	
	return 0;
}