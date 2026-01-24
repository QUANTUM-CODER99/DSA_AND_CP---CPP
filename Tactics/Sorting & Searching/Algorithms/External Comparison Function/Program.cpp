#include <bits/stdc++.h>
using namespace std;

/* ---------- Fast I/O ---------- */
#define FAST_IO() ios::sync_with_stdio(false); cin.tie(NULL)

/* ---------- Typedefs ---------- */
using ll = long long;
using ull = unsigned long long;
using ld = long double;

/* ---------- Macros ---------- */
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

/*-----Using the external function for sorting-----*/
bool comp(const string& a , const string& b) {
    if(a.size()==b.size()) return a<b;
    return a.size()<b.size();
}

/* ---------- Main ---------- */
int main() {
    FAST_IO();

    int len;
    cout << "ENTER THE LENGTH : " << endl;
    cin>>len;

    vector<string> v;
    while(len-->0) {
        string s;
        cin>>s;
        v.push_back(s);
    }

    std::sort(all(v),comp);

    cout << "OUTPUT : " << '\n';
    for(int i=0;i<v.size(); i++)
    cout << v[i] << '\t';

    return 0;
}