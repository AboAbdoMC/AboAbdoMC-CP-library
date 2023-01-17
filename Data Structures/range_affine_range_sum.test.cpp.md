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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"Data Structures/range_affine_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define S second\n\
    #define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n\
    \ntypedef long long ll;\ntypedef long double ld;\ntypedef pair<int,int> pii;\n\
    typedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\nmt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());\
    \  \n#define SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random\
    \ numbers.\n\nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l,\
    \ r)(RNG);\n}\n\nconst ld eps = 1e-9;\nconst int mod = 998244353;\nconst int oo\
    \ = 1e9 + 7;\nconst ll lloo = 1e18 + 7;\nconst int N = 5e5 + 7;\n\nint n,q,a[N];\n\
    \nint add(int x,int y) {\n\tll ret = (ll)x+y+mod;\n\twhile(ret >= mod) ret -=\
    \ mod;\n\treturn ret;\n}\n\nint mult(int x,int y) {\n\tint ret = ((ll)x*y)%mod;\n\
    \treturn ret;\n}\n\nstruct node {\n\tint sum;\n\tint lazy_b, lazy_c;\n\tnode(ll\
    \ _sum = 0) : sum(_sum), lazy_b(1), lazy_c(0) {}\n};\n\nstruct ST {\n\t#define\
    \ lc (id<<1)\n\t#define rc ((id<<1)|1)\n\t#define mid (l+(r-l)/2)\n\n\tvector<node>\
    \ seg;\n\tST() {seg.resize(n*4);}\n\n\tinline void push(int l,int r,int id) {\n\
    \t\tif (seg[id].lazy_b == 1 && seg[id].lazy_c == 0) return;\n\t\tif (l != r) {\n\
    \t\t\tseg[lc].lazy_c = add(mult(seg[lc].lazy_c,seg[id].lazy_b),seg[id].lazy_c);\n\
    \t\t\tseg[lc].lazy_b = mult(seg[lc].lazy_b,seg[id].lazy_b);\n\t\t\t\n\t\t\tseg[rc].lazy_c\
    \ = add(mult(seg[rc].lazy_c,seg[id].lazy_b),seg[id].lazy_c);\n\t\t\tseg[rc].lazy_b\
    \ = mult(seg[rc].lazy_b,seg[id].lazy_b);\n\t\t}\n\t\tseg[id].sum = add(mult(seg[id].lazy_b,seg[id].sum),mult(r-l+1,seg[id].lazy_c));\n\
    \t\tseg[id].lazy_b = 1;\n\t\tseg[id].lazy_c = 0;\n\t}\n\n\tinline node merge(node\
    \ left,node right) {\n\t\tnode ret;\n\t\tret.sum = add(left.sum, right.sum);\n\
    \t\treturn ret;\n\t}\n\n\tinline void pull(int id) {\n\t\tseg[id] = merge(seg[lc],seg[rc]);\n\
    \t}\n\n\tvoid build(int l = 0,int r = n-1,int id = 1) {\n\t\tif (l == r) {\n\t\
    \t\tseg[id] = node(a[l]);\n\t\t\treturn;\n\t\t}\n\t\tbuild(l,mid,lc);\n\t\tbuild(mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tvoid upd(int L,int R,int x,int y,int l = 0,int r = n-1,int\
    \ id = 1) {\n\t\tpush(l,r,id);\n\t\tif (l > R || r < L) return;\n\t\tif (l >=\
    \ L && r <= R) {\n\t\t\tseg[id].lazy_b = x;\n\t\t\tseg[id].lazy_c = y;\n\t\t\t\
    push(l,r,id);\n\t\t\treturn;\n\t\t}\n\t\tupd(L,R,x,y,l,mid,lc);\n\t\tupd(L,R,x,y,mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tnode query(int L,int R,int l = 0,int r = n-1,int id =\
    \ 1) {\n\t\tpush(l,r,id);\n\t\tif (l > R || r < L) return node();\n\t\tif (l >=\
    \ L && r <= R) return seg[id];\n\t\treturn merge(query(L,R,l,mid,lc),query(L,R,mid+1,r,rc));\n\
    \t}\n};\n\nvoid solve(int tc) {\n\tscanf(\"%d %d\",&n,&q);\n\tfor(int i = 0; i\
    \ < n ; i++) scanf(\"%d\",a+i);\n\tST segtree;\n\tsegtree.build();\n\tfor(int\
    \ i = 0 ; i < q ; i++) {\n\t\tint t;\n\t\tscanf(\"%d\",&t);\n\t\tif (t == 0) {\n\
    \t\t\tint l,r,b,c;\n\t\t\tscanf(\"%d %d %d %d\",&l,&r,&b,&c);\n\t\t\tsegtree.upd(l,r-1,b,c);\n\
    \t\t} else if (t == 1) {\n\t\t\tint l,r;\n\t\t\tscanf(\"%d %d\",&l,&r);\n\t\t\t\
    printf(\"%d\\n\",segtree.query(l,r-1).sum);\n\t\t}\n\t}\n}\n\nint main() {\n\t\
    // freopen(\"in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\tint T\
    \ = 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\t\
    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define\
    \ S second\n#define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define\
    \ sz(x) ((int)(x).size())\n\ntypedef long long ll;\ntypedef long double ld;\n\
    typedef pair<int,int> pii;\ntypedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\n\
    mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  \n#define\
    \ SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random numbers.\n\
    \nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l, r)(RNG);\n\
    }\n\nconst ld eps = 1e-9;\nconst int mod = 998244353;\nconst int oo = 1e9 + 7;\n\
    const ll lloo = 1e18 + 7;\nconst int N = 5e5 + 7;\n\nint n,q,a[N];\n\nint add(int\
    \ x,int y) {\n\tll ret = (ll)x+y+mod;\n\twhile(ret >= mod) ret -= mod;\n\treturn\
    \ ret;\n}\n\nint mult(int x,int y) {\n\tint ret = ((ll)x*y)%mod;\n\treturn ret;\n\
    }\n\nstruct node {\n\tint sum;\n\tint lazy_b, lazy_c;\n\tnode(ll _sum = 0) : sum(_sum),\
    \ lazy_b(1), lazy_c(0) {}\n};\n\nstruct ST {\n\t#define lc (id<<1)\n\t#define\
    \ rc ((id<<1)|1)\n\t#define mid (l+(r-l)/2)\n\n\tvector<node> seg;\n\tST() {seg.resize(n*4);}\n\
    \n\tinline void push(int l,int r,int id) {\n\t\tif (seg[id].lazy_b == 1 && seg[id].lazy_c\
    \ == 0) return;\n\t\tif (l != r) {\n\t\t\tseg[lc].lazy_c = add(mult(seg[lc].lazy_c,seg[id].lazy_b),seg[id].lazy_c);\n\
    \t\t\tseg[lc].lazy_b = mult(seg[lc].lazy_b,seg[id].lazy_b);\n\t\t\t\n\t\t\tseg[rc].lazy_c\
    \ = add(mult(seg[rc].lazy_c,seg[id].lazy_b),seg[id].lazy_c);\n\t\t\tseg[rc].lazy_b\
    \ = mult(seg[rc].lazy_b,seg[id].lazy_b);\n\t\t}\n\t\tseg[id].sum = add(mult(seg[id].lazy_b,seg[id].sum),mult(r-l+1,seg[id].lazy_c));\n\
    \t\tseg[id].lazy_b = 1;\n\t\tseg[id].lazy_c = 0;\n\t}\n\n\tinline node merge(node\
    \ left,node right) {\n\t\tnode ret;\n\t\tret.sum = add(left.sum, right.sum);\n\
    \t\treturn ret;\n\t}\n\n\tinline void pull(int id) {\n\t\tseg[id] = merge(seg[lc],seg[rc]);\n\
    \t}\n\n\tvoid build(int l = 0,int r = n-1,int id = 1) {\n\t\tif (l == r) {\n\t\
    \t\tseg[id] = node(a[l]);\n\t\t\treturn;\n\t\t}\n\t\tbuild(l,mid,lc);\n\t\tbuild(mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tvoid upd(int L,int R,int x,int y,int l = 0,int r = n-1,int\
    \ id = 1) {\n\t\tpush(l,r,id);\n\t\tif (l > R || r < L) return;\n\t\tif (l >=\
    \ L && r <= R) {\n\t\t\tseg[id].lazy_b = x;\n\t\t\tseg[id].lazy_c = y;\n\t\t\t\
    push(l,r,id);\n\t\t\treturn;\n\t\t}\n\t\tupd(L,R,x,y,l,mid,lc);\n\t\tupd(L,R,x,y,mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tnode query(int L,int R,int l = 0,int r = n-1,int id =\
    \ 1) {\n\t\tpush(l,r,id);\n\t\tif (l > R || r < L) return node();\n\t\tif (l >=\
    \ L && r <= R) return seg[id];\n\t\treturn merge(query(L,R,l,mid,lc),query(L,R,mid+1,r,rc));\n\
    \t}\n};\n\nvoid solve(int tc) {\n\tscanf(\"%d %d\",&n,&q);\n\tfor(int i = 0; i\
    \ < n ; i++) scanf(\"%d\",a+i);\n\tST segtree;\n\tsegtree.build();\n\tfor(int\
    \ i = 0 ; i < q ; i++) {\n\t\tint t;\n\t\tscanf(\"%d\",&t);\n\t\tif (t == 0) {\n\
    \t\t\tint l,r,b,c;\n\t\t\tscanf(\"%d %d %d %d\",&l,&r,&b,&c);\n\t\t\tsegtree.upd(l,r-1,b,c);\n\
    \t\t} else if (t == 1) {\n\t\t\tint l,r;\n\t\t\tscanf(\"%d %d\",&l,&r);\n\t\t\t\
    printf(\"%d\\n\",segtree.query(l,r-1).sum);\n\t\t}\n\t}\n}\n\nint main() {\n\t\
    // freopen(\"in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\tint T\
    \ = 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\t\
    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Data Structures/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-17 12:52:30+03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Data Structures/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/Data Structures/range_affine_range_sum.test.cpp
- /verify/Data Structures/range_affine_range_sum.test.cpp.html
title: Data Structures/range_affine_range_sum.test.cpp
---
