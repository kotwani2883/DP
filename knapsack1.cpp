#include<bits/stdc++.h>
#include <stdint.h>
using namespace std;

int main(){
	int64_t n,w;
	cin>>n>>w;
int64_t weight[n],value[n];
	for(int64_t i=0;i<n;i++)
	cin>>weight[i]>>value[i];
	int64_t dp[n+1][w+1];
	for(int64_t i=0;i<=n;i++)
	{
		for(int64_t j=0;j<=w;j++)
		if(i==0||j==0)
		dp[i][j]=0;
	}
	for(int64_t i=1;i<=n;i++){
		for(int64_t j=1;j<=w;j++){
			if(weight[i-1]<=j)
			dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
			else
			dp[i][j]=dp[i-1][j];
		}
	}
cout<<dp[n][w]<<endl;
return 0;
}
