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

int n,q,a[N];

struct wavelet_tree{
	#define vi vector<int>
	#define pb push_back
	int lo, hi;
	wavelet_tree *l, *r;
	vi b;
 
	//nos are in range [x,y]
	//array indices are [from, to)
	wavelet_tree(int *from, int *to, int x, int y){
		lo = x, hi = y;
		if(lo == hi or from >= to) {
			l=r=0;
			return;
		}
		int mid = (lo+hi)/2;
		auto f = [mid](int x){
			return x <= mid;
		};
		b.reserve(to-from+1);
		b.pb(0);
		for(auto it = from; it != to; it++)
			b.pb(b.back() + f(*it));
		//see how lambda function is used here	
		auto pivot = stable_partition(from, to, f);
		l = new wavelet_tree(from, pivot, lo, mid);
		r = new wavelet_tree(pivot, to, mid+1, hi);
	}
 
	//kth smallest element in [l, r]
	int kth(int l, int r, int k){
		if(l > r) return 0;
		if(lo == hi) return lo;
		int inLeft = b[r] - b[l-1];
		int lb = b[l-1]; //amt of nos in first (l-1) nos that go in left 
		int rb = b[r]; //amt of nos in first (r) nos that go in left
		if(k <= inLeft) return this->l->kth(lb+1, rb , k);
		return this->r->kth(l-lb, r-rb, k-inLeft);
	}
 
	//count of nos in [l, r] Less than or equal to k
	int LTE(int l, int r, int k) {
		if(l > r or k < lo) return 0;
		if(hi <= k) return r - l + 1;
		int lb = b[l-1], rb = b[r];
		return this->l->LTE(lb+1, rb, k) + this->r->LTE(l-lb, r-rb, k);
	}
 
	//count of nos in [l, r] equal to k
	int count(int l, int r, int k) {
		if(l > r or k < lo or k > hi) return 0;
		if(lo == hi) return r - l + 1;
		int lb = b[l-1], rb = b[r], mid = (lo+hi)/2;
		if(k <= mid) return this->l->count(lb+1, rb, k);
		return this->r->count(l-lb, r-rb, k);
	}
	~wavelet_tree(){
		delete l;
		delete r;
	}
};

void solve(int tc) {
	scanf("%d %d",&n,&q);
	for(int i = 1 ; i <= n ; i++) scanf("%d",a+i);
	wavelet_tree wt(a+1,a+n+1,0,1e9);
	for(int i = 0 ; i < q ; i++) {
		 int l,r,k;
		 scanf("%d %d %d",&l,&r,&k);
		 printf("%d\n",wt.kth(l+1,r,k+1));
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
