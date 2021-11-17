#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

typedef pair<ll,ll> pii;
typedef vector<ll> VI;
// typedef vector<int> vi;
typedef vector<string> vs;
// typedef vector<PII> vii;
// typedef vector<VI> vvi;
typedef map<ll,ll> mp;
typedef set<ll> SETI;
typedef multiset<ll> MSETI;

#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define in(a) for(auto &i:a)cin>>i;
#define sort(a) sort(a.begin(),a.end());
#define reverse(a) reverse(a.begin(),a.end());

ll mod=1000000007;
// vector<int,int> fact(2 * 1e5 + 1);
ll MOD = 998244353;


ll power(ll a,ll b,ll mod){
    if(b == 0){
        return 1;
    }
    ll ans = power(a,b/2,mod);
    ans *= ans;
    ans %= mod;
    if(b % 2){
        ans *= a;
    }
    return ans % mod;
}
ll power1(ll a,ll b){
    if(b == 0){
        return 1;
    }
    ll ans = power1(a,b/2);
    ans *= ans;
    // ans %= mod;
    if(b % 2){
        ans *= a;
    }
    return ans ;
}

ll ncr(ll n,ll r)
{
    vector<vector<ll>>c(5001,vector<ll>(5001,0));
    for(int i=1;i<=5000;i++)
    {
        c[i][0]=1;
        
    }
    c[1][1]=1;
    for(int i=1;i<=5000;i++)
    {
        for(int j=1;j<=i && j<=5000;j++)
        {
            if(i==1 && j==1)continue;
            else
            {
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
            }
        }
    }
    return c[n][r];
    
}


//prime factor in log(N) using seive -->loglog(n);
vector<ll> primefact(ll n)
{
    vector<ll>arr(100001);
    for(int i=0;i<100001;i++)arr[i]=i;
    for(int i=2;i*i<100001;i++)
    {
        if(arr[i]==i)
        {
            for(int j=i*i;j<100001;j+=i)
            {
                if(arr[j]==j)
                {
                    arr[j]=i;
                }
            }
        }
    }
    //seive will be ready in loglog(n);
    //now our seive is rready we now nedd too log(n) operatoin to find the all fromt factor
    vector<ll>ans;
    while(n>1)
    {
        ans.push_back(arr[n]);
        n=n/arr[n];
    }
    return ans;
    
    
    
    
    
    
}

//all prime factor 
//all factor in sqrt(n)
// {
    
//     vector<pair<ll,ll>>v;
//     for(ll i=2;i*i<=n;i++)
//     {
//         ll cnt=0;
//         while(n%i==0)
//         {
//             cnt++;
//             n=n/i;
//         }
//         if(cnt>0)
//         {
//             v.push_back({cnt,i});
//             cnt=0;
//         }
        
//     }
//     if(n>0)v.push_back({1,n});
// }


// 1....using DSU


// vector<int>par1,par2,ran1,ran2;
int find_parent(vector<int> &parent,int i)
{
    if(parent[i]!=i)
    {
        parent[i]=find_parent(parent,parent[i]);
    }
    return parent[i];
}
    
void cal_union(vector<int>&parent,vector<int>&rank,int x,int y)
{
    int p=find_parent(parent,x);
    int q=find_parent(parent,y);
        
    if(rank[p]>rank[q])parent[q]=p;
    else if(rank[p]<rank[q])parent[p]=q;
    else 
    {
        parent[p]=q;
        rank[q]++;
    }
}

pair<int,int> find_ratio(int a,int b)
{
    int g=__gcd(a,b);
    a/=g;
    b/=g;
    return{a,b};
}

struct cmp {
	bool operator() (const string &a, const string &b)  {
		return count(begin(a),end(a),'1')<count(begin(b),end(b),'1');
		// ll cnt1=0;
	 // ll cnt2=0;
	 // for(ll i=0;i<a.size();i++)if(a[i]=='1')cnt1++;
		// for(ll i=0;i<b.size();i++)if(b[i]=='1')cnt2++;
		// if(cnt1<cnt2)return a<b;
		// else false;
	}
};

// bool cmp(const string &a, const string &b)
// {
  
//   int cnt1=0;
// 	  int cnt2=0;
// 	  for(int i=0;i<a.size();i++)if(a[i]=='1')cnt1++;
// 		for(int i=0;i<b.size();i++)if(a[i]=='1')cnt2++;
// 		if(cnt1<cnt2)
// 		{
// 		  return a>b;
// 		}
// 		else if(cnt1>cnt2)return b>a;
// 		else
// 		{
// 		  for(int i=0;i<a.size();i++)
// 		  {
// 		    if(a[i]=='0' && b[i]=='0')continue;
// 		    else if(a[i]=='0' && b[i]=='1')return a>b;
// 		    else b>a;
// 		  }
// 		}
  
// }
// -----------------------------------------------------------------------------//
// -----------------------------------------------------------------------------//
// -----------------------------------------------------------------------------//
// -----------------------------------------------------------------------------//
// -----------------------------------------------------------------------------//



void solve()
{
  ll n,m;
  cin>>n>>m;
  vector<string>t;
  for(ll i=0;i<n;i++)
  {
    string s;
    cin>>s;
    t.PB(s);
  
  }
  sort(t.begin(),t.end(),cmp());
  ll final_ans=0;
  ll cnt=0;
  for(ll i=n-1;i>=0;i--)
  {
    // cout<<t[i]<<"\n";
    for(ll j=m-1;j>=0;j--)
    {
      if(t[i][j]=='0')cnt++;
      if(t[i][j]=='1')final_ans+=cnt;
      
    }
  }
  
  cout<<final_ans<<"\n";
  
  
  
}





int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }

	return 0;
}




