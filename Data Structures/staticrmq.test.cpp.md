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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Data Structures/staticrmq.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define F first\n#define S second\n#define pb push_back\n\
    #define all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n\ntypedef\
    \ long long ll;\ntypedef long double ld;\ntypedef pair<int,int> pii;\ntypedef\
    \ pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\nmt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());\
    \  \n#define SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random\
    \ numbers.\n\nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l,\
    \ r)(RNG);\n}\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo\
    \ = 1e9 + 7;\nconst ll lloo = 1e18 + 7;\nconst int N = 5e5 + 7;\nconst int LOG\
    \ = 20;\n\nint n,q,a[N];\n\nstruct SparseTable {\n\tint st[N][LOG];\n\n\tvoid\
    \ build() {\n\t\tfor(int j = 0;j < LOG;j++)\n\t\t\tfor(int i = 0;i < n;i++) if(i\
    \ + (1 << j) - 1 < n)\n\t\t\t\tst[i][j] = (j ? min(st[i][j-1], st[i + (1 << (j-1))][j-1]):\
    \ a[i]);\n\t}\n\n\tint query(int l,int r) {\n\t\tint x = 31 - __builtin_clz(r-l+1);\n\
    \t\treturn min(st[l][x],st[r-(1<<x)+1][x]);\n\t}\n};\n\nvoid solve(int tc) {\n\
    \tscanf(\"%d %d\",&n,&q);\n\tfor(int i = 0 ; i < n ; i++) scanf(\"%d\",a+i);\n\
    \tSparseTable sp;\n\tsp.build();\n\tfor(int i = 0 ; i < q; i++) {\n\t\tint l,r;\n\
    \t\tscanf(\"%d %d\",&l,&r);\n\t\tprintf(\"%d\\n\",sp.query(l,r-1));\n\t}\n}\n\n\
    int main() {\n\t// freopen(\"in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\
    \tint T = 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\
    \treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define S second\n\
    #define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n\
    \ntypedef long long ll;\ntypedef long double ld;\ntypedef pair<int,int> pii;\n\
    typedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\nmt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());\
    \  \n#define SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random\
    \ numbers.\n\nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l,\
    \ r)(RNG);\n}\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo\
    \ = 1e9 + 7;\nconst ll lloo = 1e18 + 7;\nconst int N = 5e5 + 7;\nconst int LOG\
    \ = 20;\n\nint n,q,a[N];\n\nstruct SparseTable {\n\tint st[N][LOG];\n\n\tvoid\
    \ build() {\n\t\tfor(int j = 0;j < LOG;j++)\n\t\t\tfor(int i = 0;i < n;i++) if(i\
    \ + (1 << j) - 1 < n)\n\t\t\t\tst[i][j] = (j ? min(st[i][j-1], st[i + (1 << (j-1))][j-1]):\
    \ a[i]);\n\t}\n\n\tint query(int l,int r) {\n\t\tint x = 31 - __builtin_clz(r-l+1);\n\
    \t\treturn min(st[l][x],st[r-(1<<x)+1][x]);\n\t}\n};\n\nvoid solve(int tc) {\n\
    \tscanf(\"%d %d\",&n,&q);\n\tfor(int i = 0 ; i < n ; i++) scanf(\"%d\",a+i);\n\
    \tSparseTable sp;\n\tsp.build();\n\tfor(int i = 0 ; i < q; i++) {\n\t\tint l,r;\n\
    \t\tscanf(\"%d %d\",&l,&r);\n\t\tprintf(\"%d\\n\",sp.query(l,r-1));\n\t}\n}\n\n\
    int main() {\n\t// freopen(\"in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\
    \tint T = 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\
    \treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Data Structures/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2023-01-11 21:20:22+03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Data Structures/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/Data Structures/staticrmq.test.cpp
- /verify/Data Structures/staticrmq.test.cpp.html
title: Data Structures/staticrmq.test.cpp
---
