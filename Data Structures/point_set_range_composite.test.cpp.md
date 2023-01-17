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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"Data Structures/point_set_range_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define S second\n\
    #define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n\
    \ntypedef long long ll;\ntypedef long double ld;\ntypedef pair<int,int> pii;\n\
    typedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\nmt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());\
    \  \n#define SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random\
    \ numbers.\n\nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l,\
    \ r)(RNG);\n}\n\nconst ld eps = 1e-9;\nconst int mod = 998244353;\nconst int oo\
    \ = 1e9 + 7;\nconst ll lloo = 1e18 + 7;\nconst int N = 5e5 + 7;\n\nint add(int\
    \ x,int y) {\n\tll ret = (ll)x+y+mod;\n\twhile(ret >= mod) ret -= mod;\n\treturn\
    \ ret;\n}\n\nint mult(int x,int y) {\n\tint ret = ((ll)x*y)%mod;\n\treturn ret;\n\
    }\n\nint n,q,a[N],b[N];\n\nstruct node {\n\tint c,d;\n\tnode(int _c = 1,int _d\
    \ = 0) : c(_c), d(_d) {}\n};\n\nstruct ST {\n\t#define lc (id<<1)\n\t#define rc\
    \ ((id<<1)|1)\n\t#define mid (l+(r-l)/2)\n\n\tvector<node> seg;\n\tST() {seg.resize(n*4);}\n\
    \n\tinline node merge(node left,node right) {\n\t\tnode ret;\n\t\tret.c = mult(left.c,right.c);\n\
    \t\tret.d = add(mult(right.c,left.d),right.d);\n\t\treturn ret;\n\t}\n\n\tinline\
    \ void pull(int id) {\n\t\tseg[id] = merge(seg[lc],seg[rc]);\n\t}\n\n\tvoid build(int\
    \ l = 0,int r = n-1,int id = 1) {\n\t\tif (l == r) {\n\t\t\tseg[id] = node(a[l],b[l]);\n\
    \t\t\treturn;\n\t\t}\n\t\tbuild(l,mid,lc);\n\t\tbuild(mid+1,r,rc);\n\t\tpull(id);\n\
    \t}\n\n\tvoid upd(int i,int x,int y,int l = 0,int r = n-1,int id = 1) {\n\t\t\
    if (l == r) {\n\t\t\tseg[id] = node(x,y);\n\t\t\treturn;\n\t\t}\n\t\tif (i <=\
    \ mid) upd(i,x,y,l,mid,lc);\n\t\telse upd(i,x,y,mid+1,r,rc);\n\t\tpull(id);\n\t\
    }\n\n\tnode query(int L,int R,int l = 0,int r = n-1,int id = 1) {\n\t\tif (l >\
    \ R || r < L) return node();\n\t\tif (l >= L && r <= R) return seg[id];\n\t\t\
    return merge(query(L,R,l,mid,lc),query(L,R,mid+1,r,rc));\n\t}\n};\n\nvoid solve(int\
    \ tc) {\n\tscanf(\"%d %d\",&n,&q);\n\tfor(int i = 0 ; i < n ; i++) scanf(\"%d\
    \ %d\",a+i,b+i);\n\tST segtree;\n\tsegtree.build();\n\tfor(int i = 0 ; i < q ;\
    \ i++) {\n\t\tint t;\n\t\tscanf(\"%d\",&t);\n\t\tif (t == 0) {\n\t\t\tint p,c,d;\n\
    \t\t\tscanf(\"%d %d %d\",&p,&c,&d);\n\t\t\tsegtree.upd(p,c,d);\n\t\t} else if\
    \ (t == 1) {\n\t\t\tint l,r,x;\n\t\t\tscanf(\"%d %d %d\",&l,&r,&x);\n\t\t\tr--;\n\
    \t\t\tnode ret = segtree.query(l,r);\n\t\t\tint ans = add(mult(x,ret.c),ret.d);\n\
    \t\t\tprintf(\"%d\\n\",ans);\n\t\t}\n\t}\n}\n\nint main() {\n\t// freopen(\"in\"\
    ,\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\tint T = 1;\n\t//scanf(\"\
    %d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define\
    \ S second\n#define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define\
    \ sz(x) ((int)(x).size())\n\ntypedef long long ll;\ntypedef long double ld;\n\
    typedef pair<int,int> pii;\ntypedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\n\
    mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  \n#define\
    \ SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random numbers.\n\
    \nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l, r)(RNG);\n\
    }\n\nconst ld eps = 1e-9;\nconst int mod = 998244353;\nconst int oo = 1e9 + 7;\n\
    const ll lloo = 1e18 + 7;\nconst int N = 5e5 + 7;\n\nint add(int x,int y) {\n\t\
    ll ret = (ll)x+y+mod;\n\twhile(ret >= mod) ret -= mod;\n\treturn ret;\n}\n\nint\
    \ mult(int x,int y) {\n\tint ret = ((ll)x*y)%mod;\n\treturn ret;\n}\n\nint n,q,a[N],b[N];\n\
    \nstruct node {\n\tint c,d;\n\tnode(int _c = 1,int _d = 0) : c(_c), d(_d) {}\n\
    };\n\nstruct ST {\n\t#define lc (id<<1)\n\t#define rc ((id<<1)|1)\n\t#define mid\
    \ (l+(r-l)/2)\n\n\tvector<node> seg;\n\tST() {seg.resize(n*4);}\n\n\tinline node\
    \ merge(node left,node right) {\n\t\tnode ret;\n\t\tret.c = mult(left.c,right.c);\n\
    \t\tret.d = add(mult(right.c,left.d),right.d);\n\t\treturn ret;\n\t}\n\n\tinline\
    \ void pull(int id) {\n\t\tseg[id] = merge(seg[lc],seg[rc]);\n\t}\n\n\tvoid build(int\
    \ l = 0,int r = n-1,int id = 1) {\n\t\tif (l == r) {\n\t\t\tseg[id] = node(a[l],b[l]);\n\
    \t\t\treturn;\n\t\t}\n\t\tbuild(l,mid,lc);\n\t\tbuild(mid+1,r,rc);\n\t\tpull(id);\n\
    \t}\n\n\tvoid upd(int i,int x,int y,int l = 0,int r = n-1,int id = 1) {\n\t\t\
    if (l == r) {\n\t\t\tseg[id] = node(x,y);\n\t\t\treturn;\n\t\t}\n\t\tif (i <=\
    \ mid) upd(i,x,y,l,mid,lc);\n\t\telse upd(i,x,y,mid+1,r,rc);\n\t\tpull(id);\n\t\
    }\n\n\tnode query(int L,int R,int l = 0,int r = n-1,int id = 1) {\n\t\tif (l >\
    \ R || r < L) return node();\n\t\tif (l >= L && r <= R) return seg[id];\n\t\t\
    return merge(query(L,R,l,mid,lc),query(L,R,mid+1,r,rc));\n\t}\n};\n\nvoid solve(int\
    \ tc) {\n\tscanf(\"%d %d\",&n,&q);\n\tfor(int i = 0 ; i < n ; i++) scanf(\"%d\
    \ %d\",a+i,b+i);\n\tST segtree;\n\tsegtree.build();\n\tfor(int i = 0 ; i < q ;\
    \ i++) {\n\t\tint t;\n\t\tscanf(\"%d\",&t);\n\t\tif (t == 0) {\n\t\t\tint p,c,d;\n\
    \t\t\tscanf(\"%d %d %d\",&p,&c,&d);\n\t\t\tsegtree.upd(p,c,d);\n\t\t} else if\
    \ (t == 1) {\n\t\t\tint l,r,x;\n\t\t\tscanf(\"%d %d %d\",&l,&r,&x);\n\t\t\tr--;\n\
    \t\t\tnode ret = segtree.query(l,r);\n\t\t\tint ans = add(mult(x,ret.c),ret.d);\n\
    \t\t\tprintf(\"%d\\n\",ans);\n\t\t}\n\t}\n}\n\nint main() {\n\t// freopen(\"in\"\
    ,\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\tint T = 1;\n\t//scanf(\"\
    %d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Data Structures/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2023-01-17 12:52:30+03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Data Structures/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/Data Structures/point_set_range_composite.test.cpp
- /verify/Data Structures/point_set_range_composite.test.cpp.html
title: Data Structures/point_set_range_composite.test.cpp
---
