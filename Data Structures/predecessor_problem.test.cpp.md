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
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"Data Structures/predecessor_problem.test.cpp\"\n/*\n _____\
    \              _                                   _____           _     _   \
    \             \n|  __ \\            | |                                 |  __\
    \ \\         | |   | |               \n| |__) | __ ___  __| | ___  ___ ___  ___\
    \ ___  ___  _ __| |__) | __ ___ | |__ | | ___ _ __ ___  \n|  ___/ '__/ _ \\/ _`\
    \ |/ _ \\/ __/ _ \\/ __/ __|/ _ \\| '__|  ___/ '__/ _ \\| '_ \\| |/ _ \\ '_ `\
    \ _ \\ \n| |   | | |  __/ (_| |  __/ (_|  __/\\__ \\__ \\ (_) | |  | |   | | |\
    \ (_) | |_) | |  __/ | | | | |\n|_|   |_|  \\___|\\__,_|\\___|\\___\\___||___/___/\\\
    ___/|_|  |_|   |_|  \\___/|_.__/|_|\\___|_| |_| |_|\n                        \
    \                                                                       \n   \
    \                                                                            \
    \                \n*/\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define\
    \ S second\n#define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define\
    \ sz(x) ((int)(x).size())\n\ntypedef long long ll;\ntypedef long double ld;\n\
    typedef pair<int,int> pii;\ntypedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\n\
    mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  \n#define\
    \ SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random numbers.\n\
    \nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l, r)(RNG);\n\
    }\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo = 1e9 + 7;\n\
    const ll lloo = 1e18 + 7;\nconst int N = 1e6 + 7;\n\nchar buff[N];\n\nvoid solve(int\
    \ tc) {\n\tint n,q;\n\tscanf(\"%d %d\",&n,&q);\n\tset<int> st;\n\t\n\tscanf(\"\
    \ %s\",buff);\n\tstring str = buff;\n\tfor(int i = 0 ; i < n ; i++) if (str[i]&1)\
    \ st.insert(i);\n\t\n\tfor(int i = 0 ; i < q ; i++) {\n\t\tint c,k;\n\t\tscanf(\"\
    %d %d\",&c,&k);\n\t\tif (c == 0) {\n\t\t\tst.insert(k);\n\t\t} else if (c == 1)\
    \ {\n\t\t\tif (st.count(k)) st.erase(k);\n\t\t} else if (c == 2) {\n\t\t\tprintf(\"\
    %d\\n\",(int)st.count(k));\n\t\t} else if (c == 3) {\n\t\t\tauto it = st.lower_bound(k);\n\
    \t\t\tprintf(\"%d\\n\",it == st.end() ? -1:*it);\n\t\t} else if (c == 4) {\n\t\
    \t\tauto it = st.upper_bound(k);\n\t\t\tif (it == st.begin()) {puts(\"-1\");continue;}\n\
    \t\t\tit--;\n\t\t\tprintf(\"%d\\n\",it == st.end() ? -1:*it);\n\t\t}\n\t}\n}\n\
    \nint main() {\n\t// freopen(\"in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\"\
    ,stdout);\n\tint T = 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i < T ; i++)\
    \ solve(i+1);\n\treturn 0;\n}\n"
  code: "/*\n _____              _                                   _____       \
    \    _     _                \n|  __ \\            | |                        \
    \         |  __ \\         | |   | |               \n| |__) | __ ___  __| | ___\
    \  ___ ___  ___ ___  ___  _ __| |__) | __ ___ | |__ | | ___ _ __ ___  \n|  ___/\
    \ '__/ _ \\/ _` |/ _ \\/ __/ _ \\/ __/ __|/ _ \\| '__|  ___/ '__/ _ \\| '_ \\\
    | |/ _ \\ '_ ` _ \\ \n| |   | | |  __/ (_| |  __/ (_|  __/\\__ \\__ \\ (_) | |\
    \  | |   | | | (_) | |_) | |  __/ | | | | |\n|_|   |_|  \\___|\\__,_|\\___|\\\
    ___\\___||___/___/\\___/|_|  |_|   |_|  \\___/|_.__/|_|\\___|_| |_| |_|\n    \
    \                                                                            \
    \               \n                                                           \
    \                                    \n*/\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define\
    \ S second\n#define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define\
    \ sz(x) ((int)(x).size())\n\ntypedef long long ll;\ntypedef long double ld;\n\
    typedef pair<int,int> pii;\ntypedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\n\
    mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  \n#define\
    \ SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random numbers.\n\
    \nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l, r)(RNG);\n\
    }\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo = 1e9 + 7;\n\
    const ll lloo = 1e18 + 7;\nconst int N = 1e6 + 7;\n\nchar buff[N];\n\nvoid solve(int\
    \ tc) {\n\tint n,q;\n\tscanf(\"%d %d\",&n,&q);\n\tset<int> st;\n\t\n\tscanf(\"\
    \ %s\",buff);\n\tstring str = buff;\n\tfor(int i = 0 ; i < n ; i++) if (str[i]&1)\
    \ st.insert(i);\n\t\n\tfor(int i = 0 ; i < q ; i++) {\n\t\tint c,k;\n\t\tscanf(\"\
    %d %d\",&c,&k);\n\t\tif (c == 0) {\n\t\t\tst.insert(k);\n\t\t} else if (c == 1)\
    \ {\n\t\t\tif (st.count(k)) st.erase(k);\n\t\t} else if (c == 2) {\n\t\t\tprintf(\"\
    %d\\n\",(int)st.count(k));\n\t\t} else if (c == 3) {\n\t\t\tauto it = st.lower_bound(k);\n\
    \t\t\tprintf(\"%d\\n\",it == st.end() ? -1:*it);\n\t\t} else if (c == 4) {\n\t\
    \t\tauto it = st.upper_bound(k);\n\t\t\tif (it == st.begin()) {puts(\"-1\");continue;}\n\
    \t\t\tit--;\n\t\t\tprintf(\"%d\\n\",it == st.end() ? -1:*it);\n\t\t}\n\t}\n}\n\
    \nint main() {\n\t// freopen(\"in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\"\
    ,stdout);\n\tint T = 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i < T ; i++)\
    \ solve(i+1);\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Data Structures/predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '2023-01-11 21:04:56+03:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Data Structures/predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/Data Structures/predecessor_problem.test.cpp
- /verify/Data Structures/predecessor_problem.test.cpp.html
title: Data Structures/predecessor_problem.test.cpp
---
