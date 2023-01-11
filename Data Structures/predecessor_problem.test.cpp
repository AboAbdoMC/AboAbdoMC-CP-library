/*
 _____              _                                   _____           _     _                
|  __ \            | |                                 |  __ \         | |   | |               
| |__) | __ ___  __| | ___  ___ ___  ___ ___  ___  _ __| |__) | __ ___ | |__ | | ___ _ __ ___  
|  ___/ '__/ _ \/ _` |/ _ \/ __/ _ \/ __/ __|/ _ \| '__|  ___/ '__/ _ \| '_ \| |/ _ \ '_ ` _ \ 
| |   | | |  __/ (_| |  __/ (_|  __/\__ \__ \ (_) | |  | |   | | | (_) | |_) | |  __/ | | | | |
|_|   |_|  \___|\__,_|\___|\___\___||___/___/\___/|_|  |_|   |_|  \___/|_.__/|_|\___|_| |_| |_|
                                                                                               
                                                                                               
*/

#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

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

char buff[N];

void solve(int tc) {
	int n,q;
	scanf("%d %d",&n,&q);
	set<int> st;
	
	scanf(" %s",buff);
	string str = buff;
	for(int i = 0 ; i < n ; i++) if (str[i]&1) st.insert(i);
	
	for(int i = 0 ; i < q ; i++) {
		int c,k;
		scanf("%d %d",&c,&k);
		if (c == 0) {
			st.insert(k);
		} else if (c == 1) {
			if (st.count(k)) st.erase(k);
		} else if (c == 2) {
			printf("%d\n",(int)st.count(k));
		} else if (c == 3) {
			auto it = st.lower_bound(k);
			printf("%d\n",it == st.end() ? -1:*it);
		} else if (c == 4) {
			auto it = st.upper_bound(k);
			if (it == st.begin()) {puts("-1");continue;}
			it--;
			printf("%d\n",it == st.end() ? -1:*it);
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
