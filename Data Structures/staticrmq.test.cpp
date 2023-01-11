/*
  _____ _        _   _      _____  __  __  ____  
 / ____| |      | | (_)    |  __ \|  \/  |/ __ \ 
| (___ | |_ __ _| |_ _  ___| |__) | \  / | |  | |
 \___ \| __/ _` | __| |/ __|  _  /| |\/| | |  | |
 ____) | || (_| | |_| | (__| | \ \| |  | | |__| |
|_____/ \__\__,_|\__|_|\___|_|  \_\_|  |_|\___\_\
                                                 
                                                 
*/

#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

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
const int N = 5e3 + 7;
const int LOG = 20;

int n,q,a[N];

struct SparseTable {
	int st[N][LOG];

	void build() {
		for(int j = 0;j < LOG;j++)
			for(int i = 0;i < n;i++) if(i + (1 << j) - 1 < n)
				st[i][j] = (j ? min(st[i][j-1], st[i + (1 << (j-1))][j-1]): a[i]);
	}

	int query(int l,int r) {
		int x = 31 - __builtin_clz(r-l+1);
		return min(st[l][x],st[r-(1<<x)+1][x]);
	}
};

void solve(int tc) {
	scanf("%d %d",&n,&q);
	for(int i = 0 ; i < n ; i++) scanf("%d",a+i);
	SparseTable sp;
	sp.build();
	for(int i = 0 ; i < q; i++) {
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",sp.query(l,r-1));
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
