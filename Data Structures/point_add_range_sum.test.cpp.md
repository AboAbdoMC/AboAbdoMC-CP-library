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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"Data Structures/point_add_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define S second\n\
    #define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n\
    \ntypedef long long ll;\ntypedef long double ld;\ntypedef pair<int,int> pii;\n\
    typedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\nmt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());\
    \  \n#define SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random\
    \ numbers.\n\nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l,\
    \ r)(RNG);\n}\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo\
    \ = 1e9 + 7;\nconst ll lloo = 1e18 + 7;\nconst int N = 5e5 + 7;\n\nint n,q,a[N];\n\
    \nstruct ST {\n\tll t[2 * N];\n\tST() {\n\t\tmemset(t, 0, sizeof t);\n\t}\n\t\
    inline ll combine(ll l, ll r) {\n\t\treturn l + r;\n\t}\n\tvoid build() {\n\t\t\
    for(int i = 0; i < n; i++) t[i + n] = a[i];\n\t\tfor(int i = n - 1; i > 0; --i)\
    \ t[i] = combine(t[i << 1], t[i << 1 | 1]);\n\t}\n\tvoid upd(int p, int v) {\n\
    \t\tfor (t[p += n] += v; p >>= 1; ) t[p] = combine(t[p << 1], t[p << 1 | 1]);\n\
    \t}\n\tll query(int l, int r) {\n\t\tr++;\n\t\tll resl = 0, resr = 0;\n\t\tfor(l\
    \ += n, r += n; l < r; l >>= 1, r >>= 1) {\n\t\t\tif(l & 1) resl = combine(resl,\
    \ t[l++]);\n\t\t\tif(r & 1) resr = combine(t[--r], resr);\n\t\t}\n\t\treturn combine(resl,\
    \ resr);\n\t}\n};\n\nvoid solve(int tc) {\n\tscanf(\"%d %d\",&n,&q);\n\tfor(int\
    \ i = 0 ; i < n ; i++) scanf(\"%d\",a+i);\n\tST segtree;\n\tsegtree.build();\n\
    \tfor(int i = 0 ; i < q ; i++) {\n\t\tint t;\n\t\tscanf(\"%d\",&t);\n\t\tif (t\
    \ == 0) {\n\t\t\tint p,x;\n\t\t\tscanf(\"%d %d\",&p,&x);\n\t\t\tsegtree.upd(p,x);\n\
    \t\t} else if (t == 1) {\n\t\t\tint l,r;\n\t\t\tscanf(\"%d %d\",&l,&r);\n\t\t\t\
    printf(\"%lld\\n\",segtree.query(l,r-1));\n\t\t}\n\t}\n}\n\nint main() {\n\t//\
    \ freopen(\"in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\tint T =\
    \ 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\treturn\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define S\
    \ second\n#define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define\
    \ sz(x) ((int)(x).size())\n\ntypedef long long ll;\ntypedef long double ld;\n\
    typedef pair<int,int> pii;\ntypedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\n\
    mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  \n#define\
    \ SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random numbers.\n\
    \nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l, r)(RNG);\n\
    }\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo = 1e9 + 7;\n\
    const ll lloo = 1e18 + 7;\nconst int N = 5e5 + 7;\n\nint n,q,a[N];\n\nstruct ST\
    \ {\n\tll t[2 * N];\n\tST() {\n\t\tmemset(t, 0, sizeof t);\n\t}\n\tinline ll combine(ll\
    \ l, ll r) {\n\t\treturn l + r;\n\t}\n\tvoid build() {\n\t\tfor(int i = 0; i <\
    \ n; i++) t[i + n] = a[i];\n\t\tfor(int i = n - 1; i > 0; --i) t[i] = combine(t[i\
    \ << 1], t[i << 1 | 1]);\n\t}\n\tvoid upd(int p, int v) {\n\t\tfor (t[p += n]\
    \ += v; p >>= 1; ) t[p] = combine(t[p << 1], t[p << 1 | 1]);\n\t}\n\tll query(int\
    \ l, int r) {\n\t\tr++;\n\t\tll resl = 0, resr = 0;\n\t\tfor(l += n, r += n; l\
    \ < r; l >>= 1, r >>= 1) {\n\t\t\tif(l & 1) resl = combine(resl, t[l++]);\n\t\t\
    \tif(r & 1) resr = combine(t[--r], resr);\n\t\t}\n\t\treturn combine(resl, resr);\n\
    \t}\n};\n\nvoid solve(int tc) {\n\tscanf(\"%d %d\",&n,&q);\n\tfor(int i = 0 ;\
    \ i < n ; i++) scanf(\"%d\",a+i);\n\tST segtree;\n\tsegtree.build();\n\tfor(int\
    \ i = 0 ; i < q ; i++) {\n\t\tint t;\n\t\tscanf(\"%d\",&t);\n\t\tif (t == 0) {\n\
    \t\t\tint p,x;\n\t\t\tscanf(\"%d %d\",&p,&x);\n\t\t\tsegtree.upd(p,x);\n\t\t}\
    \ else if (t == 1) {\n\t\t\tint l,r;\n\t\t\tscanf(\"%d %d\",&l,&r);\n\t\t\tprintf(\"\
    %lld\\n\",segtree.query(l,r-1));\n\t\t}\n\t}\n}\n\nint main() {\n\t// freopen(\"\
    in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\tint T = 1;\n\t//scanf(\"\
    %d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Data Structures/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-11 21:20:22+03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Data Structures/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/Data Structures/point_add_range_sum.test.cpp
- /verify/Data Structures/point_add_range_sum.test.cpp.html
title: Data Structures/point_add_range_sum.test.cpp
---
