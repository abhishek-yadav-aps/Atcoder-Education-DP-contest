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

	string a,b;
	cin>>a>>b;
	ll na=a.length();
	ll nb=b.length();
	vector<vector<ll>> v(na+1,vector<ll>(nb+1,0));
	for(ll i=1;i<=na;i++){
		for(ll j=1;j<=nb;j++){
			if(a[i-1]==b[j-1]){
				v[i][j]=v[i-1][j-1]+1;
			}
			else{
				v[i][j]=max(v[i-1][j],v[i][j-1]);
			}
		}
	}
	ll index = v[na][nb]; 
  
   
   char lcs[index+1]; 
   lcs[index] = '\0'; 
   ll flag=0;
	ll i = na, j = nb; 
   while (i > 0 && j > 0) 
   { 
      if (a[i-1] == b[j-1]) 
      { 
          lcs[index-1] = a[i-1]; 
          flag=1;
          i--; j--; index--;   
      } 
      else if (v[i-1][j] > v[i][j-1]) 
         i--; 
      else
         j--; 
   } 
   if(flag==1){
	cout<<lcs;
	}
	else{
		cout<<' ';
	}
	return 0;
}