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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Sample/aplusb.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define\
    \ S second\n#define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define\
    \ sz(x) ((int)(x).size())\n\ntypedef long long ll;\ntypedef long double ld;\n\
    typedef pair<int,int> pii;\ntypedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\n\
    mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  \n#define\
    \ SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random numbers.\n\
    \nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l, r)(RNG);\n\
    }\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo = 1e9 + 7;\n\
    const ll lloo = 1e18 + 7;\nconst int N = 1e6 + 7;\n\nvoid solve(int tc) {\n\t\
    int a,b;\n\tscanf(\"%d %d\",&a,&b);\n\tprintf(\"%d\\n\",a+b);\n}\n\nint main()\
    \ {\n\t// freopen(\"in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\t\
    int T = 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\
    \treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define F first\n#define S second\n#define pb push_back\n\
    #define all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n\ntypedef\
    \ long long ll;\ntypedef long double ld;\ntypedef pair<int,int> pii;\ntypedef\
    \ pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\nmt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());\
    \  \n#define SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random\
    \ numbers.\n\nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l,\
    \ r)(RNG);\n}\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo\
    \ = 1e9 + 7;\nconst ll lloo = 1e18 + 7;\nconst int N = 1e6 + 7;\n\nvoid solve(int\
    \ tc) {\n\tint a,b;\n\tscanf(\"%d %d\",&a,&b);\n\tprintf(\"%d\\n\",a+b);\n}\n\n\
    int main() {\n\t// freopen(\"in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\
    \tint T = 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\
    \treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Sample/aplusb.test.cpp
  requiredBy: []
  timestamp: '2023-01-11 21:20:22+03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Sample/aplusb.test.cpp
layout: document
redirect_from:
- /verify/Sample/aplusb.test.cpp
- /verify/Sample/aplusb.test.cpp.html
title: Sample/aplusb.test.cpp
---
