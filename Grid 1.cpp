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
 
 	ll a,b;
 	cin>>a>>b;
 	vector<vector<ll>> v(a+1,vector<ll>(b+1,0));
 	for(ll i=0;i<a;i++){
 		for(ll j=0;j<b;j++){
 			char x;
 			cin>>x;
 			if(x=='.'){
 				v[i][j]=1;
 			}
 		}
 	}
 	vector<vector<ll>> dp(a+1,vector<ll>(b+1,0));
	for(ll i=0;i<a;i++){
 		for(ll j=0;j<b;j++){
 			ll v1=0;
 			ll v2=0;
 			if(i-1>=0){
 				v1=dp[i-1][j]%mod;
 			}
 			if(j-1>=0){
 				v2=dp[i][j-1]%mod;
 			}
 			if(v[i][j]==1){
 				dp[i][j]=(v1+v2)%mod;
 			}
 			else{
 				dp[i][j]=0;
 			}
 			if(i==0 && j==0){
 				dp[i][j]=1;
 			}
 		}
 	}
 	cout<<dp[a-1][b-1]%mod;
 	return 0;
 }