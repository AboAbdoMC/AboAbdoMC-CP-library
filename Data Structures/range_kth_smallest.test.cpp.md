---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"Data Structures/range_kth_smallest.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define F first\n#define S second\n#define pb push_back\n\
    #define all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n\ntypedef\
    \ long long ll;\ntypedef long double ld;\ntypedef pair<int,int> pii;\ntypedef\
    \ pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\nmt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());\
    \  \n#define SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random\
    \ numbers.\n\nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l,\
    \ r)(RNG);\n}\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo\
    \ = 1e9 + 7;\nconst ll lloo = 1e18 + 7;\nconst int N = 1e6 + 7;\n\nint n,q,a[N];\n\
    \nstruct wavelet_tree{\n\t#define vi vector<int>\n\t#define pb push_back\n\tint\
    \ lo, hi;\n\twavelet_tree *l, *r;\n\tvi b;\n \n\t//nos are in range [x,y]\n\t\
    //array indices are [from, to)\n\twavelet_tree(int *from, int *to, int x, int\
    \ y){\n\t\tlo = x, hi = y;\n\t\tif(lo == hi or from >= to) {\n\t\t\tl=r=0;\n\t\
    \t\treturn;\n\t\t}\n\t\tint mid = (lo+hi)/2;\n\t\tauto f = [mid](int x){\n\t\t\
    \treturn x <= mid;\n\t\t};\n\t\tb.reserve(to-from+1);\n\t\tb.pb(0);\n\t\tfor(auto\
    \ it = from; it != to; it++)\n\t\t\tb.pb(b.back() + f(*it));\n\t\t//see how lambda\
    \ function is used here\t\n\t\tauto pivot = stable_partition(from, to, f);\n\t\
    \tl = new wavelet_tree(from, pivot, lo, mid);\n\t\tr = new wavelet_tree(pivot,\
    \ to, mid+1, hi);\n\t}\n \n\t//kth smallest element in [l, r]\n\tint kth(int l,\
    \ int r, int k){\n\t\tif(l > r) return 0;\n\t\tif(lo == hi) return lo;\n\t\tint\
    \ inLeft = b[r] - b[l-1];\n\t\tint lb = b[l-1]; //amt of nos in first (l-1) nos\
    \ that go in left \n\t\tint rb = b[r]; //amt of nos in first (r) nos that go in\
    \ left\n\t\tif(k <= inLeft) return this->l->kth(lb+1, rb , k);\n\t\treturn this->r->kth(l-lb,\
    \ r-rb, k-inLeft);\n\t}\n \n\t//count of nos in [l, r] Less than or equal to k\n\
    \tint LTE(int l, int r, int k) {\n\t\tif(l > r or k < lo) return 0;\n\t\tif(hi\
    \ <= k) return r - l + 1;\n\t\tint lb = b[l-1], rb = b[r];\n\t\treturn this->l->LTE(lb+1,\
    \ rb, k) + this->r->LTE(l-lb, r-rb, k);\n\t}\n \n\t//count of nos in [l, r] equal\
    \ to k\n\tint count(int l, int r, int k) {\n\t\tif(l > r or k < lo or k > hi)\
    \ return 0;\n\t\tif(lo == hi) return r - l + 1;\n\t\tint lb = b[l-1], rb = b[r],\
    \ mid = (lo+hi)/2;\n\t\tif(k <= mid) return this->l->count(lb+1, rb, k);\n\t\t\
    return this->r->count(l-lb, r-rb, k);\n\t}\n\t~wavelet_tree(){\n\t\tdelete l;\n\
    \t\tdelete r;\n\t}\n};\n\nvoid solve(int tc) {\n\tscanf(\"%d %d\",&n,&q);\n\t\
    for(int i = 1 ; i <= n ; i++) scanf(\"%d\",a+i);\n\twavelet_tree wt(a+1,a+n+1,0,1e9);\n\
    \tfor(int i = 0 ; i < q ; i++) {\n\t\t int l,r,k;\n\t\t scanf(\"%d %d %d\",&l,&r,&k);\n\
    \t\t printf(\"%d\\n\",wt.kth(l+1,r,k+1));\n\t}\n}\n\nint main() {\n\t// freopen(\"\
    in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\tint T = 1;\n\t//scanf(\"\
    %d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define S second\n\
    #define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n\
    \ntypedef long long ll;\ntypedef long double ld;\ntypedef pair<int,int> pii;\n\
    typedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\nmt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());\
    \  \n#define SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random\
    \ numbers.\n\nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l,\
    \ r)(RNG);\n}\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo\
    \ = 1e9 + 7;\nconst ll lloo = 1e18 + 7;\nconst int N = 1e6 + 7;\n\nint n,q,a[N];\n\
    \nstruct wavelet_tree{\n\t#define vi vector<int>\n\t#define pb push_back\n\tint\
    \ lo, hi;\n\twavelet_tree *l, *r;\n\tvi b;\n \n\t//nos are in range [x,y]\n\t\
    //array indices are [from, to)\n\twavelet_tree(int *from, int *to, int x, int\
    \ y){\n\t\tlo = x, hi = y;\n\t\tif(lo == hi or from >= to) {\n\t\t\tl=r=0;\n\t\
    \t\treturn;\n\t\t}\n\t\tint mid = (lo+hi)/2;\n\t\tauto f = [mid](int x){\n\t\t\
    \treturn x <= mid;\n\t\t};\n\t\tb.reserve(to-from+1);\n\t\tb.pb(0);\n\t\tfor(auto\
    \ it = from; it != to; it++)\n\t\t\tb.pb(b.back() + f(*it));\n\t\t//see how lambda\
    \ function is used here\t\n\t\tauto pivot = stable_partition(from, to, f);\n\t\
    \tl = new wavelet_tree(from, pivot, lo, mid);\n\t\tr = new wavelet_tree(pivot,\
    \ to, mid+1, hi);\n\t}\n \n\t//kth smallest element in [l, r]\n\tint kth(int l,\
    \ int r, int k){\n\t\tif(l > r) return 0;\n\t\tif(lo == hi) return lo;\n\t\tint\
    \ inLeft = b[r] - b[l-1];\n\t\tint lb = b[l-1]; //amt of nos in first (l-1) nos\
    \ that go in left \n\t\tint rb = b[r]; //amt of nos in first (r) nos that go in\
    \ left\n\t\tif(k <= inLeft) return this->l->kth(lb+1, rb , k);\n\t\treturn this->r->kth(l-lb,\
    \ r-rb, k-inLeft);\n\t}\n \n\t//count of nos in [l, r] Less than or equal to k\n\
    \tint LTE(int l, int r, int k) {\n\t\tif(l > r or k < lo) return 0;\n\t\tif(hi\
    \ <= k) return r - l + 1;\n\t\tint lb = b[l-1], rb = b[r];\n\t\treturn this->l->LTE(lb+1,\
    \ rb, k) + this->r->LTE(l-lb, r-rb, k);\n\t}\n \n\t//count of nos in [l, r] equal\
    \ to k\n\tint count(int l, int r, int k) {\n\t\tif(l > r or k < lo or k > hi)\
    \ return 0;\n\t\tif(lo == hi) return r - l + 1;\n\t\tint lb = b[l-1], rb = b[r],\
    \ mid = (lo+hi)/2;\n\t\tif(k <= mid) return this->l->count(lb+1, rb, k);\n\t\t\
    return this->r->count(l-lb, r-rb, k);\n\t}\n\t~wavelet_tree(){\n\t\tdelete l;\n\
    \t\tdelete r;\n\t}\n};\n\nvoid solve(int tc) {\n\tscanf(\"%d %d\",&n,&q);\n\t\
    for(int i = 1 ; i <= n ; i++) scanf(\"%d\",a+i);\n\twavelet_tree wt(a+1,a+n+1,0,1e9);\n\
    \tfor(int i = 0 ; i < q ; i++) {\n\t\t int l,r,k;\n\t\t scanf(\"%d %d %d\",&l,&r,&k);\n\
    \t\t printf(\"%d\\n\",wt.kth(l+1,r,k+1));\n\t}\n}\n\nint main() {\n\t// freopen(\"\
    in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\tint T = 1;\n\t//scanf(\"\
    %d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Data Structures/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2023-01-18 11:08:29+03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Data Structures/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/Data Structures/range_kth_smallest.test.cpp
- /verify/Data Structures/range_kth_smallest.test.cpp.html
title: Data Structures/range_kth_smallest.test.cpp
---
