#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

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

int n,q,a[N];

int add(int x,int y) {
	ll ret = (ll)x+y+mod;
	while(ret >= mod) ret -= mod;
	return ret;
}

int mult(int x,int y) {
	int ret = ((ll)x*y)%mod;
	return ret;
}

struct node {
	int sum;
	int lazy_b, lazy_c;
	node(ll _sum = 0) : sum(_sum), lazy_b(1), lazy_c(0) {}
};

struct ST {
	#define lc (id<<1)
	#define rc ((id<<1)|1)
	#define mid (l+(r-l)/2)

	vector<node> seg;
	ST() {seg.resize(n*4);}

	inline void push(int l,int r,int id) {
		if (seg[id].lazy_b == 1 && seg[id].lazy_c == 0) return;
		if (l != r) {
			seg[lc].lazy_c = add(mult(seg[lc].lazy_c,seg[id].lazy_b),seg[id].lazy_c);
			seg[lc].lazy_b = mult(seg[lc].lazy_b,seg[id].lazy_b);
			
			seg[rc].lazy_c = add(mult(seg[rc].lazy_c,seg[id].lazy_b),seg[id].lazy_c);
			seg[rc].lazy_b = mult(seg[rc].lazy_b,seg[id].lazy_b);
		}
		seg[id].sum = add(mult(seg[id].lazy_b,seg[id].sum),mult(r-l+1,seg[id].lazy_c));
		seg[id].lazy_b = 1;
		seg[id].lazy_c = 0;
	}

	inline node merge(node left,node right) {
		node ret;
		ret.sum = add(left.sum, right.sum);
		return ret;
	}

	inline void pull(int id) {
		seg[id] = merge(seg[lc],seg[rc]);
	}

	void build(int l = 0,int r = n-1,int id = 1) {
		if (l == r) {
			seg[id] = node(a[l]);
			return;
		}
		build(l,mid,lc);
		build(mid+1,r,rc);
		pull(id);
	}

	void upd(int L,int R,int x,int y,int l = 0,int r = n-1,int id = 1) {
		push(l,r,id);
		if (l > R || r < L) return;
		if (l >= L && r <= R) {
			seg[id].lazy_b = x;
			seg[id].lazy_c = y;
			push(l,r,id);
			return;
		}
		upd(L,R,x,y,l,mid,lc);
		upd(L,R,x,y,mid+1,r,rc);
		pull(id);
	}

	node query(int L,int R,int l = 0,int r = n-1,int id = 1) {
		push(l,r,id);
		if (l > R || r < L) return node();
		if (l >= L && r <= R) return seg[id];
		return merge(query(L,R,l,mid,lc),query(L,R,mid+1,r,rc));
	}
};

void solve(int tc) {
	scanf("%d %d",&n,&q);
	for(int i = 0; i < n ; i++) scanf("%d",a+i);
	ST segtree;
	segtree.build();
	for(int i = 0 ; i < q ; i++) {
		int t;
		scanf("%d",&t);
		if (t == 0) {
			int l,r,b,c;
			scanf("%d %d %d %d",&l,&r,&b,&c);
			segtree.upd(l,r-1,b,c);
		} else if (t == 1) {
			int l,r;
			scanf("%d %d",&l,&r);
			printf("%d\n",segtree.query(l,r-1).sum);
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
