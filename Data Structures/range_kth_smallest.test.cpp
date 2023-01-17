#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

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


struct node {
	ll sum;
	node(ll _sum = 0) : sum(_sum) {}
};

struct ST {
	#define lc (id<<1)
	#define rc ((id<<1)|1)
	#define mid (l+(r-l)/2)

	vector<node> seg;
	ST() {seg.resize(n*4);}

	inline node merge(node left,node right) {
		node ret;
		ret.sum = left.sum + right.sum;
		return ret;
	}

	inline void pull(int id) {
		seg[id] = merge(seg[lc],seg[rc]);
	}

	void build(int l = 0,int r = n-1,int id = 1) {
		if (l == r) {
			seg[id].sum = a[l];
			return;
		}
		build(l,mid,lc);
		build(mid+1,r,rc);
		pull(id);
	}

	void upd(int i,int x,int l = 0,int r = n-1,int id = 1) {
		if (l == r) {
			seg[id] = node(x);
			return;
		}
		if (i <= mid) upd(i,x,l,mid,lc);
		else upd(i,x,mid+1,r,rc);
		pull(id);
	}

	node query(int L,int R,int l = 0,int r = n-1,int id = 1) {
		if (l > R || r < L) return node();
		if (l >= L && r <= R) return seg[id];
		return merge(query(L,R,l,mid,lc),query(L,R,mid+1,r,rc));
	}
};

void solve(int tc) {
	
}

int main() {
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	int T = 1;
	//scanf("%d",&T);
	for(int i = 0 ; i < T ; i++) solve(i+1);
	return 0;
}
