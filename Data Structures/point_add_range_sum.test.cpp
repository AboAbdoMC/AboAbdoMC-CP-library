#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

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
const int N = 5e5 + 7;

int n,q,a[N];

struct ST {
	ll t[2 * N];
	ST() {
		memset(t, 0, sizeof t);
	}
	inline ll combine(ll l, ll r) {
		return l + r;
	}
	void build() {
		for(int i = 0; i < n; i++) t[i + n] = a[i];
		for(int i = n - 1; i > 0; --i) t[i] = combine(t[i << 1], t[i << 1 | 1]);
	}
	void upd(int p, int v) {
		for (t[p += n] += v; p >>= 1; ) t[p] = combine(t[p << 1], t[p << 1 | 1]);
	}
	ll query(int l, int r) {
		r++;
		ll resl = 0, resr = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) resl = combine(resl, t[l++]);
			if(r & 1) resr = combine(t[--r], resr);
		}
		return combine(resl, resr);
	}
};

void solve(int tc) {
	scanf("%d %d",&n,&q);
	for(int i = 0 ; i < n ; i++) scanf("%d",a+i);
	ST segtree;
	segtree.build();
	for(int i = 0 ; i < q ; i++) {
		int t;
		scanf("%d",&t);
		if (t == 0) {
			int p,x;
			scanf("%d %d",&p,&x);
			segtree.upd(p,x);
		} else if (t == 1) {
			int l,r;
			scanf("%d %d",&l,&r);
			printf("%lld\n",segtree.query(l,r-1));
		}
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
