/*Author-:Palak*/
/*
 * Only write code when you are sure of the approach .Remember of penalties!!
 * Do optimized thinking (Think which technique/observation can be used,deep drive into the problem!!).
 * Do post analysis after the contest./Upsolving is much more important than giving contest
 * Learn a technique and solve some problems if its new to you--->Solve as many as problems to be confident in those kinds of problem!!
 * DON'T GET STUCK ON ONE APPROACH,Move your mind in all directions
 *Remember who you are and your Capabilities!!
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(ll n)
{
	//Corner case:
	if(n<=1)
	return false;
	if(n<=3)
	return true;

	//This optimizes the complexity:
	if(n%2==0||n%3==0)
	return false;
	for(ll i=5;i*i<=n;i=i+6)
	{
		if(n%i==0||n%(i+2)==0)
		return false;
	}
	return true;
}string printLCS(string a,string b,int n,int m)
{
	int dp[n+1][m+1];
	for (int i=0; i<=n; i++) 
   { 
     for (int j=0; j<=m; j++) 
     { 
       if (i == 0 || j == 0) 
         dp[i][j] = 0; 
       else if (a[i-1] == b[j-1]) 
         dp[i][j] = dp[i-1][j-1] + 1; 
       else
         dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
     } 
   } 
/*	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/

	string res="";
	int i=n,j=m;
	while(i>0&&j>0)
	{
			if(a[i-1]==b[j-1])
			{
			res.push_back(a[i-1]);
			i--;
			j--;
		    }
		    else if(dp[i][j-1]>dp[i-1][j])
		    j--;
		    else
		    i--;
		}
	reverse(res.begin(),res.end());
	return res;
	}
int main()
{
	string s,r;
	cin>>s>>r;
	int n=s.length(),m=r.length();
string ans=printLCS(s,r,n,m);
cout<<ans<<endl;
return 0;
}
