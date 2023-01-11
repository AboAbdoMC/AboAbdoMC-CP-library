/*
 __  __                                  ____  
|  \/  |                       /\    _  |  _ \ 
| \  / | __ _ _ __  _   _     /  \ _| |_| |_) |
| |\/| |/ _` | '_ \| | | |   / /\ \_   _|  _ < 
| |  | | (_| | | | | |_| |  / ____ \|_| | |_) |
|_|  |_|\__,_|_| |_|\__, | /_/    \_\   |____/ 
                     __/ |                     
                    |___/                      
*/

#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

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

void solve(int tc) {
	ll a,b;
	scanf("%lld %lld",&a,&b);
	printf("%lld\n",a+b);
}

int main() {
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	int T = 1;
	scanf("%d",&T);
	for(int i = 0 ; i < T ; i++) solve(i+1);
	return 0;
}
