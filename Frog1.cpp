#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
	cin>>a[i];
	ll dp[n+1];
	dp[0]=0;
	dp[1]=abs(a[1]-a[0]);
	for(ll i=2;i<n;i++){
		dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),
		dp[i-2]+abs(a[i]-a[i-2]));
	}
	cout<<dp[n-1]<<endl;
	return 0;
}
