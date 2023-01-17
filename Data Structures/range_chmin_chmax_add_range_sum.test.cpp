#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

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

int n,q;ll a[N];

struct node {
	ll sum;
	ll mn,mn2,mncnt;
	ll mx,mx2,mxcnt;
	ll lazy;
	node(ll x = 0) :
		sum(x),
		mn(x),mn2(lloo),mncnt(1),
		mx(x),mx2(-lloo),mxcnt(1),
		lazy(0) {}
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
		ret.mn = left.mn < right.mn ? left.mn:right.mn;
		ret.mncnt = 0;
		ret.mncnt += (ret.mn == left.mn) ? left.mncnt:0;
		ret.mncnt += (ret.mn == right.mn) ? right.mncnt:0;
		
		ret.mx = left.mx > right.mx ? left.mx:right.mx;
		ret.mxcnt = 0;
		ret.mxcnt += (ret.mx == left.mx) ? left.mxcnt:0;
		ret.mxcnt += (ret.mx == right.mx) ? right.mxcnt:0;
		
		vector<ll> tmp;
		tmp.pb(left.mn);tmp.pb(left.mn2);
		tmp.pb(right.mn);tmp.pb(right.mn2);
		
		sort(all(tmp));
		for(int i = 0 ; i < sz(tmp) ; i++) {
			if (tmp[i] != ret.mn) {
				ret.mn2 = tmp[i];
				break;
			}
		}
		
		vector<ll> tmp2;
		tmp2.pb(left.mx);tmp2.pb(left.mx2);
		tmp2.pb(right.mx);tmp2.pb(right.mx2);
		
		sort(all(tmp2),greater<ll>());
		for(int i = 0 ; i < sz(tmp2) ; i++) {
			if (tmp2[i] != ret.mx) {
				ret.mx2 = tmp2[i];
				break;
			}
		}
		
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

	void pushmn(int id,ll x) {
		if (seg[id].mx <= x) return;
		seg[id].sum += (x-seg[id].mx)*seg[id].mxcnt;
		if (seg[id].mn == seg[id].mx) {
			seg[id].mn = x;
		} else if (seg[id].mn2 == seg[id].mx) {
			seg[id].mn2 = x;
		}
		seg[id].mx = x;
	}

	void pushmx(int id,ll x) {
		if (seg[id].mn >= x) return;
		seg[id].sum += (x-seg[id].mn)*seg[id].mncnt;
		if (seg[id].mx == seg[id].mn) {
			seg[id].mx = x;
		} else if (seg[id].mx2 == seg[id].mn) {
			seg[id].mx2 = x;
		}
		seg[id].mn = x;
	}

	void pushadd(int l,int r,int id) {
		if (l != r) {
			seg[lc].lazy += seg[id].lazy;
			seg[rc].lazy += seg[id].lazy;
		}
		
		seg[id].sum += seg[id].lazy*((ll)(r-l+1));
		seg[id].mn += seg[id].lazy;
		seg[id].mx += seg[id].lazy;
		if (seg[id].mn2 != lloo) seg[id].mn2 += seg[id].lazy;
		if (seg[id].mx2 != -lloo) seg[id].mx2 += seg[id].lazy;
		seg[id].lazy = 0;
	}

	void push(int l,int r,int id) {
		
		pushadd(l,r,id);
		
		if (l == r) return;
		pushadd(l,mid,lc);
		pushadd(mid+1,r,rc);
		pushmn(lc,seg[id].mx);
		pushmn(rc,seg[id].mx);
		pushmx(lc,seg[id].mn);
		pushmx(rc,seg[id].mn);
	}

	void updmx(int L,int R,ll x,int l = 0,int r = n-1,int id = 1) {
		push(l,r,id);
		if (l > R || r < L || seg[id].mn >= x) return;
		
		if (l >= L && r <= R && seg[id].mn2 > x) {
			pushmx(id,x);
			return;
		}

		updmx(L,R,x,l,mid,lc);
		updmx(L,R,x,mid+1,r,rc);
		pull(id);
	}

	void updmn(int L,int R,ll x,int l = 0,int r = n-1,int id = 1) {
		push(l,r,id);
		if (l > R || r < L || seg[id].mx <= x) return;
		
		if (l >= L && r <= R && seg[id].mx2 < x) {
			pushmn(id,x);
			return;
		}

		updmn(L,R,x,l,mid,lc);
		updmn(L,R,x,mid+1,r,rc);
		pull(id);
	}

	void updadd(int L,int R,ll x,int l = 0,int r = n-1,int id = 1) {
		push(l,r,id);
		if (l > R || r < L) return;
		
		if (l >= L && r <= R) {
			seg[id].lazy += x;
			push(l,r,id);
			return;
		}

		updadd(L,R,x,l,mid,lc);
		updadd(L,R,x,mid+1,r,rc);
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
	for(int i = 0 ; i < n ; i++) scanf("%lld",a+i);
	ST segtree;
	segtree.build();
	
	for(int i = 0 ; i < q ; i++) {
		int t;
		scanf("%d",&t);
		if (t == 0) {
			int l,r;ll x;
			scanf("%d %d %lld",&l,&r,&x);
			r--;
			segtree.updmn(l,r,x);
		} else if (t == 1) {
			int l,r;ll x;
			scanf("%d %d %lld",&l,&r,&x);
			r--;
			segtree.updmx(l,r,x);
		} else if (t == 2) {
			int l,r;ll x;
			scanf("%d %d %lld",&l,&r,&x);
			r--;
			segtree.updadd(l,r,x);
		} else if (t == 3) {
			int l,r;
			scanf("%d %d",&l,&r);
			r--;
			printf("%lld\n",segtree.query(l,r).sum);
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
