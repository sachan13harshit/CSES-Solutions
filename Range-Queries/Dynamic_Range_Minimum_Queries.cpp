#include <bits/stdc++.h>
 
using namespace std;
#ifndef HARSHIT
    #define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
#else
    #define debug(...);
#endif
template <typename T> std::ostream &operator<<(std::ostream &stream, const vector<T> &vec) {for (size_t i = 0; i < vec.size(); i++) { stream << vec[i]; if (i != vec.size() - 1) stream << ' '; }; return stream; } template <typename T> std::istream &operator>>(std::istream &stream, vector<T> &vec) {for (T &x : vec) stream >> x; return stream; } template <typename T, typename U> std::ostream &operator<<(std::ostream &stream, const pair<T, U> &pr) {stream << pr.first << ' ' << pr.second; return stream; } template <typename T, typename U> std::istream &operator>>(std::istream &stream, pair<T, U> &pr) {stream >> pr.first >> pr.second; return stream; }template <typename A, typename B> string to_string(pair<A, B> p);template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);string to_string(const string &s) { return '"' + s + '"'; }string to_string(char c) {string s; s += c; return s; }string to_string(const char *s) { return to_string((string)s); }string to_string(bool b) { return (b ? "1" : "0"); }string to_string(vector<bool> v) {bool first = true; string res = "{ "; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", "; } first = false; res += to_string(v[i]); } res += " }"; return res; }template <size_t N> string to_string(bitset<N> v) {string res = ""; for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]); } return res; }template <typename A> string to_string(A v) {bool first = true; string res = "{ "; for (const auto &x : v) {if (!first) {res += ", "; } first = false; res += to_string(x); } res += " }"; return res; }template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }void debug_out() { cout << endl; }template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cout << " " << to_string(H); debug_out(T...); }
 
#define int long long
#define endl '\n'
# define Harshit  cin.tie(nullptr)->sync_with_stdio(false);
#define X first
#define Y second
#define  V vector
#define pb push_back
 
const bool multipleTestCases = 1;
 
 
// 0 based indexing
 
class SegmentTree
{
public :
    V<int> tree;
    int identity = 0;
     int N;  // size of the given array
 
    int merge(int a , int b){
        return min(a,b);
    }
    SegmentTree(int n , int identity) {
        N = n;
        this->identity = identity;
        tree.assign(4*N , identity);
    }
    void update (int qIdx , int val){
        function <void(int , int , int ) > f = [&] (int tIdx , int tL , int tR)
        {
            if(tL == tR)
            {
                tree[tIdx] = val;
                return;
            }
            int tM = (tL + tR) / 2;
            // left child = 2 * tIdx + 1  , tL , tM
            // right child = 2 * tIdx + 2 , tM + 1 , tR
 
            if(tL <= qIdx and qIdx <= tM)
            {
                f(2*tIdx + 1 , tL , tM);
            }
            else
            {
                f(2*tIdx + 2 , tM + 1 , tR);
            }
 
            tree[tIdx] = merge(tree[2*tIdx + 1]  , tree[2*tIdx + 2] );
        };
 
        f(0 , 0 , N-1);
    }
 
    int query(int l , int r){
        function <int(int , int , int ) > f = [&] (int tIdx , int tL , int tR)
        {
            // no overlap
            if(l > tR or r < tL)
            {
                return identity;
            }
            // complete overlap
            if(l <= tL and tR <= r)
            {
                return tree[tIdx];
            }
            // partial overlap
            int tM = (tL + tR) / 2;
            return merge(f(2*tIdx + 1 , tL , tM) , f(2*tIdx + 2 , tM + 1 , tR));
        };
        return f(0 , 0 , N-1);
    }
};
 
 
void harshit()
{
    int n , q;
    cin >> n >> q;
    SegmentTree st(n + 1 , 1e18);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        st.update(i , x);
    }
 
    while(q--){
        int t , l , r;
        cin >> t >> l >> r;
        if(t == 1){
            st.update(l , r);
        }
        else{
            cout << st.query(l , r) << endl;
        }
    }
}
 
signed main()
{
    Harshit
    int t = 1;
    multipleTestCases;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        harshit();
    }
}