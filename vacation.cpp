#include<bits/stdc++.h>

#define ll long long int
#define llu unsigned long long int
#define f(n) for(ll i=0;i<n;i++)
#define fr(n) for(ll i=n-1;i>=0;i--)
#define endl "\n"
#define mod 1000000007

using namespace std;

vector<ll> a,b,c;
vector<ll> aa,bb,cc;
ll vacation(ll i,ll n,char type){
	if(i>=n){
		return 0;
	}
	ll v1=0;
	ll v2=0;
	if(type=='a'){
		if(bb[i+1]==-1){
			bb[i+1]=vacation(i+1,n,'b')+b[i];
		}
		if(cc[i+1]==-1){
			cc[i+1]=vacation(i+1,n,'c')+c[i];
		}
		v1=bb[i+1];
		v2=cc[i+1];
	}else if(type=='b'){
		if(aa[i+1]==-1){
			aa[i+1]=vacation(i+1,n,'a')+a[i];
		}
		if(cc[i+1]==-1){
			cc[i+1]=vacation(i+1,n,'c')+c[i];
		}
		v1=aa[i+1];
		v2=cc[i+1];
	}else if(type=='c'){
		if(bb[i+1]==-1){
			bb[i+1]=vacation(i+1,n,'b')+b[i];
		}
		if(aa[i+1]==-1){
			aa[i+1]=vacation(i+1,n,'a')+a[i];
		}
		v1=bb[i+1];
		v2=aa[i+1];
	}
	ll v3=max(v1,v2);
	return v3;
}


int main()
{
	std::ios_base::sync_with_stdio(false);

	ll n;
	cin>>n;
	
	f(n){
		ll x,y,z;
		cin>>x>>y>>z;
		a.push_back(x);
		b.push_back(y);
		c.push_back(z);
	}
	f(n+1){
		aa.push_back(-1);
		bb.push_back(-1);
		cc.push_back(-1);
	}
	cout<<max(vacation(0,n,'a'),max(vacation(0,n,'b'),vacation(0,n,'c')));
	
	return 0;
}