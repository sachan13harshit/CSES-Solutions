#include <bits/stdc++.h>
using namespace std;

#ifndef HARSHIT
    #define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
#else
    #define debug(...);
#endif

template <typename T>
std::ostream &operator<<(std::ostream &stream, const vector<T> &vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        stream << vec[i];
        if (i != vec.size() - 1) stream << ' ';
    }
    return stream;
}

template <typename T>
std::istream &operator>>(std::istream &stream, vector<T> &vec) {
    for (T &x : vec) stream >> x;
    return stream;
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &stream, const pair<T, U> &pr) {
    stream << pr.first << ' ' << pr.second;
    return stream;
}

template <typename T, typename U>
std::istream &operator>>(std::istream &stream, pair<T, U> &pr) {
    stream >> pr.first >> pr.second;
    return stream;
}

template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s) { return '"' + s + '"'; }
string to_string(char c) { string s; s += c; return s; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "1" : "0"); }
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{ ";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += " }";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{ ";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += " }";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug_out(T...);
}

#define int long long
#define endl '\n'
#define Harshit  cin.tie(nullptr)->sync_with_stdio(false);
#define X first
#define Y second
#define V vector
#define pb push_back

const bool multipleTestCases = 0;

template<typename T>
class SegmentTree {
public:
    vector<T> tree;
    T identity;
    int N;

    SegmentTree(int n, T identity) {
        N = n;
        this->identity = identity;
        tree.assign(4 * N, identity);
    }

    T merge(T a, T b) {
        return a + b;
    }

    void update(int qIdx, T val) {
        function<void(int, int, int)> f = [&](int tIdx, int tL, int tR) {
            if (tL == tR) {
                tree[tIdx] = val;
                return;
            }

            int tM = (tL + tR) / 2;
            if (tL <= qIdx && qIdx <= tM) {
                f(2 * tIdx + 1, tL, tM);
            } else {
                f(2 * tIdx + 2, tM + 1, tR);
            }
            tree[tIdx] = merge(tree[2 * tIdx + 1], tree[2 * tIdx + 2]);
        };
        f(0, 0, N - 1);
    }

    T query(int l, int r) {
        function<T(int, int, int)> f = [&](int tIdx, int tL, int tR) {
            if (l > tR || r < tL) {
                return identity;
            }
            if (l <= tL && tR <= r) {
                return tree[tIdx];
            }
            int tM = (tL + tR) / 2;
            return merge(f(2 * tIdx + 1, tL, tM), f(2 * tIdx + 2, tM + 1, tR));
        };
        return f(0, 0, N - 1);
    }
};
void harshit() {
   int n, m;
    cin >> n >> m;
    SegmentTree<int> st(n + 2, 0);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    while (m--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            st.update(l,st.query(l,l) +  v);
            st.update(r + 1, st.query(r+1,r+1)-v);
        }
        else
        {
            int idx; cin >> idx;
            cout << a[idx] + st.query(1, idx) << endl;
        }
    }

}

signed main() {
    Harshit
    int t = 1;
    if (multipleTestCases) {
        cin >> t;
    }
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        harshit();
    }
    return 0;
}
