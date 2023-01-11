#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

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

struct DSU {
	vector<int> par, rnk, sz;
	int c;
	DSU(int n) : c(n) {
		rnk.resize(n+1);
		par.resize(n+1);
		sz.resize(n+1);
		for (int i = 1; i <= n; ++i) par[i] = i;
	}
	int find(int i) {
		return (par[i] == i ? i : (par[i] = find(par[i])));
	}
	bool same(int i, int j) {
		return find(i) == find(j);
	}
	int get_size(int i) {
		return sz[find(i)];
	}
	int count() {
		return c;    //connected components
	}
	int merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return -1;
		else --c;
		if (rnk[i] > rnk[j]) swap(i, j);
		par[i] = j;
		sz[j] += sz[i];
		if (rnk[i] == rnk[j]) rnk[j]++;
		return j;
	}
};

void solve(int tc) {
	int n,q;
	scanf("%d %d",&n,&q);
	DSU dsu(n);
	for(int i = 0 ; i < q ;i++) {
		int t,u,v;
		scanf("%d %d %d",&t,&u,&v);
		if (t) {
			printf("%d\n",(int)dsu.same(u,v));
		} else {
			dsu.merge(u,v);
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
