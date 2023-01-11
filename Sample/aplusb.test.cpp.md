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
  bundledCode: "#line 1 \"Sample/aplusb.test.cpp\"\n/*\n           _             \
    \      _         _       __  __  _____ \n     /\\   | |            /\\   | | \
    \      | |     |  \\/  |/ ____|\n    /  \\  | |__   ___   /  \\  | |__   __| |\
    \ ___ | \\  / | |     \n   / /\\ \\ | '_ \\ / _ \\ / /\\ \\ | '_ \\ / _` |/ _\
    \ \\| |\\/| | |     \n  / ____ \\| |_) | (_) / ____ \\| |_) | (_| | (_) | |  |\
    \ | |____ \n /_/    \\_\\_.__/ \\___/_/    \\_\\_.__/ \\__,_|\\___/|_|  |_|\\\
    _____|\n*/\n\n// build command:\n// g++ -std=gnu++17 -O3 -DDEBUG -g -fsanitize=signed-integer-overflow\
    \ -fsanitize=bounds-strict -fsanitize=address -fsanitize=integer-divide-by-zero\
    \ -fsanitize=float-divide-by-zero -fsanitize=pointer-overflow -fsanitize=shift-exponent\
    \ -fsplit-stack -Wshadow -Wall -fconcepts -Wno-unused-result\n\n// REMEMBER:\n\
    // BS, Offline, Persistent SegTree, SQRT, Treap, MaxFlow, FFT, Matrices\n\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#pragma GCC optimize(\"O3,unroll-loops\")\n#pragma GCC\
    \ target(\"avx2,bmi,bmi2,lzcnt,popcnt\")\n\n// DEBUG STUFF\n#define coutc \"\\\
    033[48;5;196m\\033[38;5;15m\"\n#define endc \"\\033[0m\"\n#define len(x) ((int)(x).size())\n\
    #ifdef DEBUG\nstring to_string(char c) { return string({c}); }\n\ntemplate<class...\
    \ Ts>\nostream& operator<<(ostream& o, tuple<Ts...> t) {\n  string s = \"(\";\n\
    \  apply([&](auto&&... r) {\n    ((s += to_string(r) + \", \"), ...); }, t);\n\
    \  return o << s.substr(0, len(s) - 2) + \")\";\n}\n\nostream& operator<<(ostream\
    \ &o, pair<auto, auto> p) {\n  return o << \"(\" << p.fi << \", \" << p.se <<\
    \ \")\";\n}\n\ntemplate<class C, class T = typename C::value_type,\ntypename std::enable_if<!std::is_same<C,\
    \ std::string>\n::value>::type* = nullptr>\nostream& operator<<(ostream &o, C\
    \ c) {\n  for (auto e : c) o << setw(7) << right << e;\n  return o << endc <<\
    \ endl << coutc;\n}\n\nvoid debug(const auto &e, const auto &... r) {\n  cerr\
    \ << coutc << e;\n  ((cerr << \" \" << r), ..., (cerr << endc << endl));\n}\n\
    #else\n#define debug(...)\n#endif\n\n\n#define F first\n#define S second\n#define\
    \ pb push_back\n#define all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n\
    \ntypedef long long ll;\ntypedef long double ld;\ntypedef pair<int,int> pii;\n\
    typedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\nmt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());\
    \  \n#define SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random\
    \ numbers.\n\nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l,\
    \ r)(RNG);\n}\n\nconst ld eps = 1e-9;\nconst int mod = 1e9 + 7;\nconst int oo\
    \ = 1e9 + 7;\nconst ll lloo = 1e18 + 7;\nconst int N = 1e6 + 7;\n\nvoid solve(int\
    \ tc) {\n\tint a,b;\n\tscanf(\"%d %d\",&a,&b);\n\tprintf(\"%d\\n\",a+b);\n}\n\n\
    int main() {\n\t// freopen(\"in\",\"r\",stdin);\n\t// freopen(\"out\",\"w\",stdout);\n\
    \tint T = 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i < T ; i++) solve(i+1);\n\
    \treturn 0;\n}\n"
  code: "/*\n           _                   _         _       __  __  _____ \n   \
    \  /\\   | |            /\\   | |       | |     |  \\/  |/ ____|\n    /  \\  |\
    \ |__   ___   /  \\  | |__   __| | ___ | \\  / | |     \n   / /\\ \\ | '_ \\ /\
    \ _ \\ / /\\ \\ | '_ \\ / _` |/ _ \\| |\\/| | |     \n  / ____ \\| |_) | (_) /\
    \ ____ \\| |_) | (_| | (_) | |  | | |____ \n /_/    \\_\\_.__/ \\___/_/    \\\
    _\\_.__/ \\__,_|\\___/|_|  |_|\\_____|\n*/\n\n// build command:\n// g++ -std=gnu++17\
    \ -O3 -DDEBUG -g -fsanitize=signed-integer-overflow -fsanitize=bounds-strict -fsanitize=address\
    \ -fsanitize=integer-divide-by-zero -fsanitize=float-divide-by-zero -fsanitize=pointer-overflow\
    \ -fsanitize=shift-exponent -fsplit-stack -Wshadow -Wall -fconcepts -Wno-unused-result\n\
    \n// REMEMBER:\n// BS, Offline, Persistent SegTree, SQRT, Treap, MaxFlow, FFT,\
    \ Matrices\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#pragma GCC optimize(\"O3,unroll-loops\"\
    )\n#pragma GCC target(\"avx2,bmi,bmi2,lzcnt,popcnt\")\n\n// DEBUG STUFF\n#define\
    \ coutc \"\\033[48;5;196m\\033[38;5;15m\"\n#define endc \"\\033[0m\"\n#define\
    \ len(x) ((int)(x).size())\n#ifdef DEBUG\nstring to_string(char c) { return string({c});\
    \ }\n\ntemplate<class... Ts>\nostream& operator<<(ostream& o, tuple<Ts...> t)\
    \ {\n  string s = \"(\";\n  apply([&](auto&&... r) {\n    ((s += to_string(r)\
    \ + \", \"), ...); }, t);\n  return o << s.substr(0, len(s) - 2) + \")\";\n}\n\
    \nostream& operator<<(ostream &o, pair<auto, auto> p) {\n  return o << \"(\" <<\
    \ p.fi << \", \" << p.se << \")\";\n}\n\ntemplate<class C, class T = typename\
    \ C::value_type,\ntypename std::enable_if<!std::is_same<C, std::string>\n::value>::type*\
    \ = nullptr>\nostream& operator<<(ostream &o, C c) {\n  for (auto e : c) o <<\
    \ setw(7) << right << e;\n  return o << endc << endl << coutc;\n}\n\nvoid debug(const\
    \ auto &e, const auto &... r) {\n  cerr << coutc << e;\n  ((cerr << \" \" << r),\
    \ ..., (cerr << endc << endl));\n}\n#else\n#define debug(...)\n#endif\n\n\n#define\
    \ F first\n#define S second\n#define pb push_back\n#define all(x) (x).begin(),\
    \ (x).end()\n#define sz(x) ((int)(x).size())\n\ntypedef long long ll;\ntypedef\
    \ long double ld;\ntypedef pair<int,int> pii;\ntypedef pair<ll,ll> pll;\n\n//\
    \ RANDOM NUMBER GENERATOR\nmt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());\
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
  timestamp: '2023-01-11 20:09:54+03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Sample/aplusb.test.cpp
layout: document
redirect_from:
- /verify/Sample/aplusb.test.cpp
- /verify/Sample/aplusb.test.cpp.html
title: Sample/aplusb.test.cpp
---
