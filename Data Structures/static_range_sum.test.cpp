/*
  _____ _        _   _      _____                         _____                 
 / ____| |      | | (_)    |  __ \                       / ____|                
| (___ | |_ __ _| |_ _  ___| |__) |__ _ _ __   __ _  ___| (___  _   _ _ __ ___  
 \___ \| __/ _` | __| |/ __|  _  // _` | '_ \ / _` |/ _ \\___ \| | | | '_ ` _ \ 
 ____) | || (_| | |_| | (__| | \ \ (_| | | | | (_| |  __/____) | |_| | | | | | |
|_____/ \__\__,_|\__|_|\___|_|  \_\__,_|_| |_|\__, |\___|_____/ \__,_|_| |_| |_|
                                               __/ |                            
                                              |___/                             
*/

#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.

int getrand(int l,int r) {
	return uniform_int_distribution<int>(l, r)(RNG);
}

const ld eps = 1e-9;
const int mod = 1e9 + 7;
const int oo = 1e9 + 7;
const ll lloo = 1e18 + 7;
const int N = 1e6 + 7;

int n,q,a[N];
ll pref[N];

void solve(int tc) {
	scanf("%d %d",&n,&q);
	for(int i = 0 ; i < n ; i++) {
		scanf("%d",a+i);
		pref[i] = (i?pref[i-1]:0)+a[i];
	}
	
	for(int i = 0 ; i < q ; i++) {
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%lld\n",pref[r-1]-(l?pref[l-1]:0));
	}
}

int main() {
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	int T = 1;
	//scanf("%d",&T);
	for(int i = 0 ; i < T ; i++) solve(i+1);
	return 0;
}
