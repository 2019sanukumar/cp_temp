#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <cstring>


using namespace std;


typedef long long ll; 
typedef pair<ll,ll> pii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<ll,ll> mp;
typedef set<ll> si;
typedef multiset<ll> MSETI;


#define MP make_pair
#define pb push_back
#define INF (int)1e9
#define fr0(i,n) for(int i=0;i<n;i++)
#define fr1(i,n) for(int i=1;i<=n;i++)
#define sort(a) sort(a.begin(),a.end());
#define reverse(a) reverse(a.begin(),a.end());
#define int long long



template <typename T1,typename T2>
istream& operator>>(istream &istream ,pair<T1,T2>&p){return (istream >> p.first >> p.second);}

template <typename T>
istream& operator>>(istream &istream ,vector<T> &v)
{
    for(auto &it:v)
    {
        cin>>it;
    }
    return istream;
}



template<typename T1,typename T2>
ostream& operator<<(ostream &ostream ,const pair<T1,T2> &p){return (ostream << p.first <<" "<< p.second);}

template<typename T>
ostream& operator<<(ostream &ostream ,const vector<T> &c)
{
    for(auto &it:c)
    {
        cout<<it<<" ";
    }
    return ostream;
}


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

ll mod=1000000007;
ll MOD=998244353;

const int N=2e5+5;


ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b % a, a);}
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
    return ans % mod;}
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
    return ans ;}
vi parent;
vi ranks;
int get(int x) {

    return parent[x] = (x == parent[x]) ? x : get(parent[x]);}
void Union(int a, int b) {
    int x = get(a);
    int y = get(b);
    if (ranks[x] > ranks[y]) {
        parent[y] = x;
        ranks[x] += ranks[y];
        ranks[y] = 0;
    }
    else {
        parent[x] = y;
        ranks[y] += ranks[x];
        ranks[x] = 0;
    }}

// --------------------------------------------------------------------------------------------------//

void solve1()
{
    
    
    
  
}


int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve1();
    }
    

    return 0;
}



