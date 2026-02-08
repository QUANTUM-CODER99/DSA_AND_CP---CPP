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

/*
Notes :
-> Time: O(n · n!)
-> Space: O(1) extra (excluding output)
-> Very readable
-> Uses STL magic, not algorithmic insight
*/

/*---------Permutation Function-------*/
vector<vector<int>> permutation(vector<int> &v) {
    vector<vector<int>> res;

    std::sort(v.begin(),v.end());

    do {
        res.push_back(v);
    }while(next_permutation(v.begin(),v.end()));

    return res;
}

/* ---------- Main ---------- */
int main() {
    FAST_IO();

    cout << "ENTER THE LENGTH : " << endl;
    int len;
    cin >> len;
    vector<int> v;

    cout << "ENTER THE ELEMENTS OF VECTOR V :" << endl;
    while(len-->0) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    vector<vector<int>> ans = permutation(v);

    cout<<"ELEMENTS OF VECTOR V :" << endl;
    for(int i=0;i<ans.size();i++) {
        cout << "[" ;
        for(int j=0;j<ans[i].size();j++) {
            cout<< " " << ans[i][j];
            if(j!=ans[i].size()-1) cout << ", ";
        }
        cout << "]" << '\n';
    }
    
    return 0;
}