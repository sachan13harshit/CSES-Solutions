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
 
const int maxN = 1000;
 
 
 
 
 
class MergeSortTree{
    public:
    V<V<int>> tree;
    int N;
    MergeSortTree(int n){
        N = n;
        tree.resize(4*n);
    }
       void build(vector<int>& arr, int si, int ss, int se) {
        if (ss == se) {
            tree[si].push_back(arr[ss]);
            return;
        }
        int mid = (ss + se) / 2;
        build(arr, 2 * si + 1, ss, mid);
        build(arr, 2 * si + 2, mid + 1, se);
         int i = 0;
        int j = 0;
        while(i<tree[2*si+1].size() && j<tree[2*si+2].size()){
            if(tree[2*si+1][i]<tree[2*si+2][j]){
                tree[si].pb(tree[2*si+1][i]);
                i++;
            }else{
                tree[si].pb(tree[2*si+2][j]);
                j++;
            }
        }
            while(i<tree[2*si+1].size()){
                tree[si].pb(tree[2*si+1][i]);
                i++;
            }
            while(j<tree[2*si+2].size()){
                tree[si].pb(tree[2*si+2][j]);
                j++;
            }
        }
 
      int query(int si , int ss , int se , int qs , int qe , int k){
        if(ss>qe || se<qs){
            return 0;
        }
        if(ss>=qs && se<=qe){
            return upper_bound(tree[si].begin() , tree[si].end() , k-1) - tree[si].begin();
        }
        int mid = (ss+se)/2;
        return query(2*si+1 , ss , mid , qs , qe , k) + query(2*si+2 , mid+1 , se , qs , qe , k);
      }
};
void harshit()
{
    int n , q;
    cin>>n>>q;
    V<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int , int> mp;
    V<int> B(n);
    for(int i=0;i<n;i++){
       if(mp.find(a[i])==mp.end()){
            B[i] = -1;
        }
        else{
            B[i] = mp[a[i]];
        
        }
        mp[a[i]] = i;
    }
    MergeSortTree st(n);
    st.build(B , 0 , 0 , n-1);
    while(q--){
        int l , r;
        cin>>l>>r;
        cout<<st.query(0 , 0 , n-1 , l-1 , r-1 , l-1)<<endl;
    }
 
 
}
 
signed main()
{
    Harshit
    int t = 1;
    multipleTestCases ;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        harshit();
    }
}