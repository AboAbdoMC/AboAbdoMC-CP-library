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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"Data Structures/unionfind.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define F first\n#define S second\n#define pb push_back\n\
    #define all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n\ntypedef\
    \ long long ll;\ntypedef long double ld;\ntypedef pair<int,int> pii;\ntypedef\
    \ pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\nmt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());\
    \  \n#define SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random\
    \ numbers.\n\nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l,\
    \ r)(RNG);\n}\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo\
    \ = 1e9 + 7;\nconst ll lloo = 1e18 + 7;\nconst int N = 1e6 + 7;\n\nstruct DSU\
    \ {\n\tvector<int> par, rnk, sz;\n\tint c;\n\tDSU(int n) : c(n) {\n\t\trnk.resize(n+1);\n\
    \t\tpar.resize(n+1);\n\t\tsz.resize(n+1);\n\t\tfor (int i = 1; i <= n; ++i) par[i]\
    \ = i;\n\t}\n\tint find(int i) {\n\t\treturn (par[i] == i ? i : (par[i] = find(par[i])));\n\
    \t}\n\tbool same(int i, int j) {\n\t\treturn find(i) == find(j);\n\t}\n\tint get_size(int\
    \ i) {\n\t\treturn sz[find(i)];\n\t}\n\tint count() {\n\t\treturn c;    //connected\
    \ components\n\t}\n\tint merge(int i, int j) {\n\t\tif ((i = find(i)) == (j =\
    \ find(j))) return -1;\n\t\telse --c;\n\t\tif (rnk[i] > rnk[j]) swap(i, j);\n\t\
    \tpar[i] = j;\n\t\tsz[j] += sz[i];\n\t\tif (rnk[i] == rnk[j]) rnk[j]++;\n\t\t\
    return j;\n\t}\n};\n\nvoid solve(int tc) {\n\tint n,q;\n\tscanf(\"%d %d\",&n,&q);\n\
    \tDSU dsu(n);\n\tfor(int i = 0 ; i < q ;i++) {\n\t\tint t,u,v;\n\t\tscanf(\"%d\
    \ %d %d\",&t,&u,&v);\n\t\tif (t) {\n\t\t\tprintf(\"%d\\n\",(int)dsu.same(u,v));\n\
    \t\t} else {\n\t\t\tdsu.merge(u,v);\n\t\t}\n\t}\n}\n\nint main() {\n\t// freopen(\"\
    in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\tint T = 1;\n\t//scanf(\"\
    %d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define S second\n\
    #define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n\
    \ntypedef long long ll;\ntypedef long double ld;\ntypedef pair<int,int> pii;\n\
    typedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\nmt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());\
    \  \n#define SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random\
    \ numbers.\n\nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l,\
    \ r)(RNG);\n}\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo\
    \ = 1e9 + 7;\nconst ll lloo = 1e18 + 7;\nconst int N = 1e6 + 7;\n\nstruct DSU\
    \ {\n\tvector<int> par, rnk, sz;\n\tint c;\n\tDSU(int n) : c(n) {\n\t\trnk.resize(n+1);\n\
    \t\tpar.resize(n+1);\n\t\tsz.resize(n+1);\n\t\tfor (int i = 1; i <= n; ++i) par[i]\
    \ = i;\n\t}\n\tint find(int i) {\n\t\treturn (par[i] == i ? i : (par[i] = find(par[i])));\n\
    \t}\n\tbool same(int i, int j) {\n\t\treturn find(i) == find(j);\n\t}\n\tint get_size(int\
    \ i) {\n\t\treturn sz[find(i)];\n\t}\n\tint count() {\n\t\treturn c;    //connected\
    \ components\n\t}\n\tint merge(int i, int j) {\n\t\tif ((i = find(i)) == (j =\
    \ find(j))) return -1;\n\t\telse --c;\n\t\tif (rnk[i] > rnk[j]) swap(i, j);\n\t\
    \tpar[i] = j;\n\t\tsz[j] += sz[i];\n\t\tif (rnk[i] == rnk[j]) rnk[j]++;\n\t\t\
    return j;\n\t}\n};\n\nvoid solve(int tc) {\n\tint n,q;\n\tscanf(\"%d %d\",&n,&q);\n\
    \tDSU dsu(n);\n\tfor(int i = 0 ; i < q ;i++) {\n\t\tint t,u,v;\n\t\tscanf(\"%d\
    \ %d %d\",&t,&u,&v);\n\t\tif (t) {\n\t\t\tprintf(\"%d\\n\",(int)dsu.same(u,v));\n\
    \t\t} else {\n\t\t\tdsu.merge(u,v);\n\t\t}\n\t}\n}\n\nint main() {\n\t// freopen(\"\
    in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\tint T = 1;\n\t//scanf(\"\
    %d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Data Structures/unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-01-11 21:20:22+03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Data Structures/unionfind.test.cpp
layout: document
redirect_from:
- /verify/Data Structures/unionfind.test.cpp
- /verify/Data Structures/unionfind.test.cpp.html
title: Data Structures/unionfind.test.cpp
---
