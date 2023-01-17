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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"Data Structures/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define\
    \ S second\n#define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define\
    \ sz(x) ((int)(x).size())\n\ntypedef long long ll;\ntypedef long double ld;\n\
    typedef pair<int,int> pii;\ntypedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\n\
    mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  \n#define\
    \ SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random numbers.\n\
    \nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l, r)(RNG);\n\
    }\n\nconst ld eps = 1e-9;\nconst int mod = 998244353;\nconst int oo = 1e9 + 7;\n\
    const ll lloo = 1e18 + 7;\nconst int N = 5e5 + 7;\n\nint n,q;ll a[N];\n\nstruct\
    \ node {\n\tll sum;\n\tll mn,mn2,mncnt;\n\tll mx,mx2,mxcnt;\n\tll lazy;\n\tnode(ll\
    \ x = 0) :\n\t\tsum(x),\n\t\tmn(x),mn2(lloo),mncnt(1),\n\t\tmx(x),mx2(-lloo),mxcnt(1),\n\
    \t\tlazy(0) {}\n};\n\nstruct ST {\n\t#define lc (id<<1)\n\t#define rc ((id<<1)|1)\n\
    \t#define mid (l+(r-l)/2)\n\n\tvector<node> seg;\n\tST() {seg.resize(n*4);}\n\n\
    \tinline node merge(node left,node right) {\n\t\tnode ret;\n\t\tret.sum = left.sum\
    \ + right.sum;\n\t\tret.mn = left.mn < right.mn ? left.mn:right.mn;\n\t\tret.mncnt\
    \ = 0;\n\t\tret.mncnt += (ret.mn == left.mn) ? left.mncnt:0;\n\t\tret.mncnt +=\
    \ (ret.mn == right.mn) ? right.mncnt:0;\n\t\t\n\t\tret.mx = left.mx > right.mx\
    \ ? left.mx:right.mx;\n\t\tret.mxcnt = 0;\n\t\tret.mxcnt += (ret.mx == left.mx)\
    \ ? left.mxcnt:0;\n\t\tret.mxcnt += (ret.mx == right.mx) ? right.mxcnt:0;\n\t\t\
    \n\t\tvector<ll> tmp;\n\t\ttmp.pb(left.mn);tmp.pb(left.mn2);\n\t\ttmp.pb(right.mn);tmp.pb(right.mn2);\n\
    \t\t\n\t\tsort(all(tmp));\n\t\tfor(int i = 0 ; i < sz(tmp) ; i++) {\n\t\t\tif\
    \ (tmp[i] != ret.mn) {\n\t\t\t\tret.mn2 = tmp[i];\n\t\t\t\tbreak;\n\t\t\t}\n\t\
    \t}\n\t\t\n\t\tvector<ll> tmp2;\n\t\ttmp2.pb(left.mx);tmp2.pb(left.mx2);\n\t\t\
    tmp2.pb(right.mx);tmp2.pb(right.mx2);\n\t\t\n\t\tsort(all(tmp2),greater<ll>());\n\
    \t\tfor(int i = 0 ; i < sz(tmp2) ; i++) {\n\t\t\tif (tmp2[i] != ret.mx) {\n\t\t\
    \t\tret.mx2 = tmp2[i];\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\t\n\t\treturn ret;\n\
    \t}\n\n\tinline void pull(int id) {\n\t\tseg[id] = merge(seg[lc],seg[rc]);\n\t\
    }\n\n\tvoid build(int l = 0,int r = n-1,int id = 1) {\n\t\tif (l == r) {\n\t\t\
    \tseg[id] = node(a[l]);\n\t\t\treturn;\n\t\t}\n\t\tbuild(l,mid,lc);\n\t\tbuild(mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tvoid pushmn(int id,ll x) {\n\t\tif (seg[id].mx <= x) return;\n\
    \t\tseg[id].sum += (x-seg[id].mx)*seg[id].mxcnt;\n\t\tif (seg[id].mn == seg[id].mx)\
    \ {\n\t\t\tseg[id].mn = x;\n\t\t} else if (seg[id].mn2 == seg[id].mx) {\n\t\t\t\
    seg[id].mn2 = x;\n\t\t}\n\t\tseg[id].mx = x;\n\t}\n\n\tvoid pushmx(int id,ll x)\
    \ {\n\t\tif (seg[id].mn >= x) return;\n\t\tseg[id].sum += (x-seg[id].mn)*seg[id].mncnt;\n\
    \t\tif (seg[id].mx == seg[id].mn) {\n\t\t\tseg[id].mx = x;\n\t\t} else if (seg[id].mx2\
    \ == seg[id].mn) {\n\t\t\tseg[id].mx2 = x;\n\t\t}\n\t\tseg[id].mn = x;\n\t}\n\n\
    \tvoid pushadd(int l,int r,int id) {\n\t\tif (l != r) {\n\t\t\tseg[lc].lazy +=\
    \ seg[id].lazy;\n\t\t\tseg[rc].lazy += seg[id].lazy;\n\t\t}\n\t\t\n\t\tseg[id].sum\
    \ += seg[id].lazy*((ll)(r-l+1));\n\t\tseg[id].mn += seg[id].lazy;\n\t\tseg[id].mx\
    \ += seg[id].lazy;\n\t\tif (seg[id].mn2 != lloo) seg[id].mn2 += seg[id].lazy;\n\
    \t\tif (seg[id].mx2 != -lloo) seg[id].mx2 += seg[id].lazy;\n\t\tseg[id].lazy =\
    \ 0;\n\t}\n\n\tvoid push(int l,int r,int id) {\n\t\t\n\t\tpushadd(l,r,id);\n\t\
    \t\n\t\tif (l == r) return;\n\t\tpushadd(l,mid,lc);\n\t\tpushadd(mid+1,r,rc);\n\
    \t\tpushmn(lc,seg[id].mx);\n\t\tpushmn(rc,seg[id].mx);\n\t\tpushmx(lc,seg[id].mn);\n\
    \t\tpushmx(rc,seg[id].mn);\n\t}\n\n\tvoid updmx(int L,int R,ll x,int l = 0,int\
    \ r = n-1,int id = 1) {\n\t\tpush(l,r,id);\n\t\tif (l > R || r < L || seg[id].mn\
    \ >= x) return;\n\t\t\n\t\tif (l >= L && r <= R && seg[id].mn2 > x) {\n\t\t\t\
    pushmx(id,x);\n\t\t\treturn;\n\t\t}\n\n\t\tupdmx(L,R,x,l,mid,lc);\n\t\tupdmx(L,R,x,mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tvoid updmn(int L,int R,ll x,int l = 0,int r = n-1,int\
    \ id = 1) {\n\t\tpush(l,r,id);\n\t\tif (l > R || r < L || seg[id].mx <= x) return;\n\
    \t\t\n\t\tif (l >= L && r <= R && seg[id].mx2 < x) {\n\t\t\tpushmn(id,x);\n\t\t\
    \treturn;\n\t\t}\n\n\t\tupdmn(L,R,x,l,mid,lc);\n\t\tupdmn(L,R,x,mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tvoid updadd(int L,int R,ll x,int l = 0,int r = n-1,int\
    \ id = 1) {\n\t\tpush(l,r,id);\n\t\tif (l > R || r < L) return;\n\t\t\n\t\tif\
    \ (l >= L && r <= R) {\n\t\t\tseg[id].lazy += x;\n\t\t\tpush(l,r,id);\n\t\t\t\
    return;\n\t\t}\n\n\t\tupdadd(L,R,x,l,mid,lc);\n\t\tupdadd(L,R,x,mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tnode query(int L,int R,int l = 0,int r = n-1,int id =\
    \ 1) {\n\t\tpush(l,r,id);\n\t\tif (l > R || r < L) return node();\n\t\tif (l >=\
    \ L && r <= R) return seg[id];\n\t\treturn merge(query(L,R,l,mid,lc),query(L,R,mid+1,r,rc));\n\
    \t}\n};\n\nvoid solve(int tc) {\n\tscanf(\"%d %d\",&n,&q);\n\tfor(int i = 0 ;\
    \ i < n ; i++) scanf(\"%lld\",a+i);\n\tST segtree;\n\tsegtree.build();\n\t\n\t\
    for(int i = 0 ; i < q ; i++) {\n\t\tint t;\n\t\tscanf(\"%d\",&t);\n\t\tif (t ==\
    \ 0) {\n\t\t\tint l,r;ll x;\n\t\t\tscanf(\"%d %d %lld\",&l,&r,&x);\n\t\t\tr--;\n\
    \t\t\tsegtree.updmn(l,r,x);\n\t\t} else if (t == 1) {\n\t\t\tint l,r;ll x;\n\t\
    \t\tscanf(\"%d %d %lld\",&l,&r,&x);\n\t\t\tr--;\n\t\t\tsegtree.updmx(l,r,x);\n\
    \t\t} else if (t == 2) {\n\t\t\tint l,r;ll x;\n\t\t\tscanf(\"%d %d %lld\",&l,&r,&x);\n\
    \t\t\tr--;\n\t\t\tsegtree.updadd(l,r,x);\n\t\t} else if (t == 3) {\n\t\t\tint\
    \ l,r;\n\t\t\tscanf(\"%d %d\",&l,&r);\n\t\t\tr--;\n\t\t\tprintf(\"%lld\\n\",segtree.query(l,r).sum);\n\
    \t\t}\n\t}\n}\n\nint main() {\n\t// freopen(\"in\",\"r\",stdin);\n\t// freopen(\"\
    out\",\"w\",stdout);\n\tint T = 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i\
    \ < T ; i++) solve(i+1);\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define F first\n#define\
    \ S second\n#define pb push_back\n#define all(x) (x).begin(), (x).end()\n#define\
    \ sz(x) ((int)(x).size())\n\ntypedef long long ll;\ntypedef long double ld;\n\
    typedef pair<int,int> pii;\ntypedef pair<ll,ll> pll;\n\n// RANDOM NUMBER GENERATOR\n\
    mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  \n#define\
    \ SHUF(v) shuffle(all(v), RNG); \n// Use mt19937_64 for 64 bit random numbers.\n\
    \nint getrand(int l,int r) {\n\treturn uniform_int_distribution<int>(l, r)(RNG);\n\
    }\n\nconst ld eps = 1e-9;\nconst int mod = 998244353;\nconst int oo = 1e9 + 7;\n\
    const ll lloo = 1e18 + 7;\nconst int N = 5e5 + 7;\n\nint n,q;ll a[N];\n\nstruct\
    \ node {\n\tll sum;\n\tll mn,mn2,mncnt;\n\tll mx,mx2,mxcnt;\n\tll lazy;\n\tnode(ll\
    \ x = 0) :\n\t\tsum(x),\n\t\tmn(x),mn2(lloo),mncnt(1),\n\t\tmx(x),mx2(-lloo),mxcnt(1),\n\
    \t\tlazy(0) {}\n};\n\nstruct ST {\n\t#define lc (id<<1)\n\t#define rc ((id<<1)|1)\n\
    \t#define mid (l+(r-l)/2)\n\n\tvector<node> seg;\n\tST() {seg.resize(n*4);}\n\n\
    \tinline node merge(node left,node right) {\n\t\tnode ret;\n\t\tret.sum = left.sum\
    \ + right.sum;\n\t\tret.mn = left.mn < right.mn ? left.mn:right.mn;\n\t\tret.mncnt\
    \ = 0;\n\t\tret.mncnt += (ret.mn == left.mn) ? left.mncnt:0;\n\t\tret.mncnt +=\
    \ (ret.mn == right.mn) ? right.mncnt:0;\n\t\t\n\t\tret.mx = left.mx > right.mx\
    \ ? left.mx:right.mx;\n\t\tret.mxcnt = 0;\n\t\tret.mxcnt += (ret.mx == left.mx)\
    \ ? left.mxcnt:0;\n\t\tret.mxcnt += (ret.mx == right.mx) ? right.mxcnt:0;\n\t\t\
    \n\t\tvector<ll> tmp;\n\t\ttmp.pb(left.mn);tmp.pb(left.mn2);\n\t\ttmp.pb(right.mn);tmp.pb(right.mn2);\n\
    \t\t\n\t\tsort(all(tmp));\n\t\tfor(int i = 0 ; i < sz(tmp) ; i++) {\n\t\t\tif\
    \ (tmp[i] != ret.mn) {\n\t\t\t\tret.mn2 = tmp[i];\n\t\t\t\tbreak;\n\t\t\t}\n\t\
    \t}\n\t\t\n\t\tvector<ll> tmp2;\n\t\ttmp2.pb(left.mx);tmp2.pb(left.mx2);\n\t\t\
    tmp2.pb(right.mx);tmp2.pb(right.mx2);\n\t\t\n\t\tsort(all(tmp2),greater<ll>());\n\
    \t\tfor(int i = 0 ; i < sz(tmp2) ; i++) {\n\t\t\tif (tmp2[i] != ret.mx) {\n\t\t\
    \t\tret.mx2 = tmp2[i];\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\t\n\t\treturn ret;\n\
    \t}\n\n\tinline void pull(int id) {\n\t\tseg[id] = merge(seg[lc],seg[rc]);\n\t\
    }\n\n\tvoid build(int l = 0,int r = n-1,int id = 1) {\n\t\tif (l == r) {\n\t\t\
    \tseg[id] = node(a[l]);\n\t\t\treturn;\n\t\t}\n\t\tbuild(l,mid,lc);\n\t\tbuild(mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tvoid pushmn(int id,ll x) {\n\t\tif (seg[id].mx <= x) return;\n\
    \t\tseg[id].sum += (x-seg[id].mx)*seg[id].mxcnt;\n\t\tif (seg[id].mn == seg[id].mx)\
    \ {\n\t\t\tseg[id].mn = x;\n\t\t} else if (seg[id].mn2 == seg[id].mx) {\n\t\t\t\
    seg[id].mn2 = x;\n\t\t}\n\t\tseg[id].mx = x;\n\t}\n\n\tvoid pushmx(int id,ll x)\
    \ {\n\t\tif (seg[id].mn >= x) return;\n\t\tseg[id].sum += (x-seg[id].mn)*seg[id].mncnt;\n\
    \t\tif (seg[id].mx == seg[id].mn) {\n\t\t\tseg[id].mx = x;\n\t\t} else if (seg[id].mx2\
    \ == seg[id].mn) {\n\t\t\tseg[id].mx2 = x;\n\t\t}\n\t\tseg[id].mn = x;\n\t}\n\n\
    \tvoid pushadd(int l,int r,int id) {\n\t\tif (l != r) {\n\t\t\tseg[lc].lazy +=\
    \ seg[id].lazy;\n\t\t\tseg[rc].lazy += seg[id].lazy;\n\t\t}\n\t\t\n\t\tseg[id].sum\
    \ += seg[id].lazy*((ll)(r-l+1));\n\t\tseg[id].mn += seg[id].lazy;\n\t\tseg[id].mx\
    \ += seg[id].lazy;\n\t\tif (seg[id].mn2 != lloo) seg[id].mn2 += seg[id].lazy;\n\
    \t\tif (seg[id].mx2 != -lloo) seg[id].mx2 += seg[id].lazy;\n\t\tseg[id].lazy =\
    \ 0;\n\t}\n\n\tvoid push(int l,int r,int id) {\n\t\t\n\t\tpushadd(l,r,id);\n\t\
    \t\n\t\tif (l == r) return;\n\t\tpushadd(l,mid,lc);\n\t\tpushadd(mid+1,r,rc);\n\
    \t\tpushmn(lc,seg[id].mx);\n\t\tpushmn(rc,seg[id].mx);\n\t\tpushmx(lc,seg[id].mn);\n\
    \t\tpushmx(rc,seg[id].mn);\n\t}\n\n\tvoid updmx(int L,int R,ll x,int l = 0,int\
    \ r = n-1,int id = 1) {\n\t\tpush(l,r,id);\n\t\tif (l > R || r < L || seg[id].mn\
    \ >= x) return;\n\t\t\n\t\tif (l >= L && r <= R && seg[id].mn2 > x) {\n\t\t\t\
    pushmx(id,x);\n\t\t\treturn;\n\t\t}\n\n\t\tupdmx(L,R,x,l,mid,lc);\n\t\tupdmx(L,R,x,mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tvoid updmn(int L,int R,ll x,int l = 0,int r = n-1,int\
    \ id = 1) {\n\t\tpush(l,r,id);\n\t\tif (l > R || r < L || seg[id].mx <= x) return;\n\
    \t\t\n\t\tif (l >= L && r <= R && seg[id].mx2 < x) {\n\t\t\tpushmn(id,x);\n\t\t\
    \treturn;\n\t\t}\n\n\t\tupdmn(L,R,x,l,mid,lc);\n\t\tupdmn(L,R,x,mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tvoid updadd(int L,int R,ll x,int l = 0,int r = n-1,int\
    \ id = 1) {\n\t\tpush(l,r,id);\n\t\tif (l > R || r < L) return;\n\t\t\n\t\tif\
    \ (l >= L && r <= R) {\n\t\t\tseg[id].lazy += x;\n\t\t\tpush(l,r,id);\n\t\t\t\
    return;\n\t\t}\n\n\t\tupdadd(L,R,x,l,mid,lc);\n\t\tupdadd(L,R,x,mid+1,r,rc);\n\
    \t\tpull(id);\n\t}\n\n\tnode query(int L,int R,int l = 0,int r = n-1,int id =\
    \ 1) {\n\t\tpush(l,r,id);\n\t\tif (l > R || r < L) return node();\n\t\tif (l >=\
    \ L && r <= R) return seg[id];\n\t\treturn merge(query(L,R,l,mid,lc),query(L,R,mid+1,r,rc));\n\
    \t}\n};\n\nvoid solve(int tc) {\n\tscanf(\"%d %d\",&n,&q);\n\tfor(int i = 0 ;\
    \ i < n ; i++) scanf(\"%lld\",a+i);\n\tST segtree;\n\tsegtree.build();\n\t\n\t\
    for(int i = 0 ; i < q ; i++) {\n\t\tint t;\n\t\tscanf(\"%d\",&t);\n\t\tif (t ==\
    \ 0) {\n\t\t\tint l,r;ll x;\n\t\t\tscanf(\"%d %d %lld\",&l,&r,&x);\n\t\t\tr--;\n\
    \t\t\tsegtree.updmn(l,r,x);\n\t\t} else if (t == 1) {\n\t\t\tint l,r;ll x;\n\t\
    \t\tscanf(\"%d %d %lld\",&l,&r,&x);\n\t\t\tr--;\n\t\t\tsegtree.updmx(l,r,x);\n\
    \t\t} else if (t == 2) {\n\t\t\tint l,r;ll x;\n\t\t\tscanf(\"%d %d %lld\",&l,&r,&x);\n\
    \t\t\tr--;\n\t\t\tsegtree.updadd(l,r,x);\n\t\t} else if (t == 3) {\n\t\t\tint\
    \ l,r;\n\t\t\tscanf(\"%d %d\",&l,&r);\n\t\t\tr--;\n\t\t\tprintf(\"%lld\\n\",segtree.query(l,r).sum);\n\
    \t\t}\n\t}\n}\n\nint main() {\n\t// freopen(\"in\",\"r\",stdin);\n\t// freopen(\"\
    out\",\"w\",stdout);\n\tint T = 1;\n\t//scanf(\"%d\",&T);\n\tfor(int i = 0 ; i\
    \ < T ; i++) solve(i+1);\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Data Structures/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-17 12:52:30+03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Data Structures/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/Data Structures/range_chmin_chmax_add_range_sum.test.cpp
- /verify/Data Structures/range_chmin_chmax_add_range_sum.test.cpp.html
title: Data Structures/range_chmin_chmax_add_range_sum.test.cpp
---
