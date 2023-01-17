#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

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
const int mod = 998244353;
const int oo = 1e9 + 7;
const ll lloo = 1e18 + 7;
const int N = 5e5 + 7;

int add(int x,int y) {
	ll ret = (ll)x+y+mod;
	while(ret >= mod) ret -= mod;
	return ret;
}

int mult(int x,int y) {
	int ret = ((ll)x*y)%mod;
	return ret;
}

int n,q,a[N],b[N];

struct node {
	int c,d;
	node(int _c = 1,int _d = 0) : c(_c), d(_d) {}
};

struct ST {
	#define lc (id<<1)
	#define rc ((id<<1)|1)
	#define mid (l+(r-l)/2)

	vector<node> seg;
	ST() {seg.resize(n*4);}

	inline node merge(node left,node right) {
		node ret;
		ret.c = mult(left.c,right.c);
		ret.d = add(mult(right.c,left.d),right.d);
		return ret;
	}

	inline void pull(int id) {
		seg[id] = merge(seg[lc],seg[rc]);
	}

	void build(int l = 0,int r = n-1,int id = 1) {
		if (l == r) {
			seg[id] = node(a[l],b[l]);
			return;
		}
		build(l,mid,lc);
		build(mid+1,r,rc);
		pull(id);
	}

	void upd(int i,int x,int y,int l = 0,int r = n-1,int id = 1) {
		if (l == r) {
			seg[id] = node(x,y);
			return;
		}
		if (i <= mid) upd(i,x,y,l,mid,lc);
		else upd(i,x,y,mid+1,r,rc);
		pull(id);
	}

	node query(int L,int R,int l = 0,int r = n-1,int id = 1) {
		if (l > R || r < L) return node();
		if (l >= L && r <= R) return seg[id];
		return merge(query(L,R,l,mid,lc),query(L,R,mid+1,r,rc));
	}
};

void solve(int tc) {
	scanf("%d %d",&n,&q);
	for(int i = 0 ; i < n ; i++) scanf("%d %d",a+i,b+i);
	ST segtree;
	segtree.build();
	for(int i = 0 ; i < q ; i++) {
		int t;
		scanf("%d",&t);
		if (t == 0) {
			int p,c,d;
			scanf("%d %d %d",&p,&c,&d);
			segtree.upd(p,c,d);
		} else if (t == 1) {
			int l,r,x;
			scanf("%d %d %d",&l,&r,&x);
			r--;
			node ret = segtree.query(l,r);
			int ans = add(mult(x,ret.c),ret.d);
			printf("%d\n",ans);
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
