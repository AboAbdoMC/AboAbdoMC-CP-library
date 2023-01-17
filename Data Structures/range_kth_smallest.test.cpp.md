---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \ = 1e9 + 7;\nconst ll lloo = 1e18 + 7;\nconst int N = 1e6 + 7;\n\n\nstruct node\
    \ {\n\tll sum;\n\tnode(ll _sum = 0) : sum(_sum) {}\n};\n\nstruct ST {\n\t#define\
    \ lc (id<<1)\n\t#define rc ((id<<1)|1)\n\t#define mid (l+(r-l)/2)\n\n\tvector<node>\
    \ seg;\n\tST() {seg.resize(n*4);}\n\n\tinline node merge(node left,node right)\
    \ {\n\t\tnode ret;\n\t\tret.sum = left.sum + right.sum;\n\t\treturn ret;\n\t}\n\
    \n\tinline void pull(int id) {\n\t\tseg[id] = merge(seg[lc],seg[rc]);\n\t}\n\n\
    \tvoid build(int l = 0,int r = n-1,int id = 1) {\n\t\tif (l == r) {\n\t\t\tseg[id].sum\
    \ = a[l];\n\t\t\treturn;\n\t\t}\n\t\tbuild(l,mid,lc);\n\t\tbuild(mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tvoid upd(int i,int x,int l = 0,int r = n-1,int id = 1)\
    \ {\n\t\tif (l == r) {\n\t\t\tseg[id] = node(x);\n\t\t\treturn;\n\t\t}\n\t\tif\
    \ (i <= mid) upd(i,x,l,mid,lc);\n\t\telse upd(i,x,mid+1,r,rc);\n\t\tpull(id);\n\
    \t}\n\n\tnode query(int L,int R,int l = 0,int r = n-1,int id = 1) {\n\t\tif (l\
    \ > R || r < L) return node();\n\t\tif (l >= L && r <= R) return seg[id];\n\t\t\
    return merge(query(L,R,l,mid,lc),query(L,R,mid+1,r,rc));\n\t}\n};\n\nvoid solve(int\
    \ tc) {\n\t\n}\n\nint main() {\n\t// freopen(\"in\",\"r\",stdin);\n\t// freopen(\"\
    out\",\"w\",stdout);\n\tint T = 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i\
    \ < T ; i++) solve(i+1);\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define S second\n\
    #define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n\
    \ntypedef long long ll;\ntypedef long double ld;\ntypedef pair<int,int> pii;\n\
    typedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\nmt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());\
    \  \n#define SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random\
    \ numbers.\n\nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l,\
    \ r)(RNG);\n}\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo\
    \ = 1e9 + 7;\nconst ll lloo = 1e18 + 7;\nconst int N = 1e6 + 7;\n\n\nstruct node\
    \ {\n\tll sum;\n\tnode(ll _sum = 0) : sum(_sum) {}\n};\n\nstruct ST {\n\t#define\
    \ lc (id<<1)\n\t#define rc ((id<<1)|1)\n\t#define mid (l+(r-l)/2)\n\n\tvector<node>\
    \ seg;\n\tST() {seg.resize(n*4);}\n\n\tinline node merge(node left,node right)\
    \ {\n\t\tnode ret;\n\t\tret.sum = left.sum + right.sum;\n\t\treturn ret;\n\t}\n\
    \n\tinline void pull(int id) {\n\t\tseg[id] = merge(seg[lc],seg[rc]);\n\t}\n\n\
    \tvoid build(int l = 0,int r = n-1,int id = 1) {\n\t\tif (l == r) {\n\t\t\tseg[id].sum\
    \ = a[l];\n\t\t\treturn;\n\t\t}\n\t\tbuild(l,mid,lc);\n\t\tbuild(mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tvoid upd(int i,int x,int l = 0,int r = n-1,int id = 1)\
    \ {\n\t\tif (l == r) {\n\t\t\tseg[id] = node(x);\n\t\t\treturn;\n\t\t}\n\t\tif\
    \ (i <= mid) upd(i,x,l,mid,lc);\n\t\telse upd(i,x,mid+1,r,rc);\n\t\tpull(id);\n\
    \t}\n\n\tnode query(int L,int R,int l = 0,int r = n-1,int id = 1) {\n\t\tif (l\
    \ > R || r < L) return node();\n\t\tif (l >= L && r <= R) return seg[id];\n\t\t\
    return merge(query(L,R,l,mid,lc),query(L,R,mid+1,r,rc));\n\t}\n};\n\nvoid solve(int\
    \ tc) {\n\t\n}\n\nint main() {\n\t// freopen(\"in\",\"r\",stdin);\n\t// freopen(\"\
    out\",\"w\",stdout);\n\tint T = 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i\
    \ < T ; i++) solve(i+1);\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Data Structures/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2023-01-17 12:52:30+03:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Data Structures/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/Data Structures/range_kth_smallest.test.cpp
- /verify/Data Structures/range_kth_smallest.test.cpp.html
title: Data Structures/range_kth_smallest.test.cpp
---
