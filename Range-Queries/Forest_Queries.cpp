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
 
const bool multipleTestCases = 0;
 
void harshit()
{
    int n , q;
    cin >> n >> q;
    V<V<int>> B(n,V<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x ;
            cin >> x;
           if(x=='*'){
                B[i][j] = 1;
           }
           else{
               B[i][j] = 0;
           }
        }
    }
 
    
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            B[i][j]+=B[i][j-1];
        }
    }
 
    // Column Prefix sum 
 
    for(int j=0;j<n;j++){
        for(int i=1;i<n;i++){
            B[i][j] +=B[i-1][j];
        }
    }
 
 
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << B[i][j] << " ";
    //     }
    //     cout << endl;
    // }
 
 
// while(q--){
//     int r1 , r2 , c1 , c2;
//     cin >> r1  >> c1  >> r2 >> c2;
//     r1--;
//     r2--;
//     c1--;
//     c2--;
//     if(r1!=0 && r2!=0){
//         cout <<   B[r2][c2] - B[r1][c1] - B[r2][c1-1]  + B[r1][c1-1] << endl; 
//     }
//    else if(r1==0){
//         cout << B[r2][c2] - B[r1][c1] - B[r1][c1-1];
//     }
//     else if(c1==0){
//         cout << B[r2][c2] - B[r1][c1] - B[r1-1][c1];
//     }
 
// }
  
    while (q--) {
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        r2--;
        c1--;
        c2--;
 
        int result = B[r2][c2];
        if (r1 > 0) result -= B[r1 - 1][c2];
        if (c1 > 0) result -= B[r2][c1 - 1];
        if (r1 > 0 && c1 > 0) result += B[r1 - 1][c1 - 1];
 
        cout << result << endl;
    }
 
 
 
    //0 1 1 1 
//    1 2 3 4 
//    2 4 5 6 
//    3 6 8 10 
 
    
}
 
signed main()
{
    Harshit
    int t = 1;
    multipleTestCases and cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        harshit();
    }

}