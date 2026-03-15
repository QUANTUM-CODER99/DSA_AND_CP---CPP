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
Notes
-> Time: O(n · n!)
-> Space: O(n) recursion
-> Fewer swaps than standard backtracking
-> Very efficient in practice
*/

void heapPermute(int n, vector<int>& nums, vector<vector<int>>& result) {
    if (n == 1) {
        result.push_back(nums);
        return;
    }

    for (int i = 0; i < n; i++) {
        heapPermute(n - 1, nums, result);

        if (n % 2 == 1)
            swap(nums[0], nums[n - 1]);
        else
            swap(nums[i], nums[n - 1]);
    }
}

vector<vector<int>> generatePermutations(vector<int>& nums) {
    vector<vector<int>> result;
    heapPermute(nums.size(), nums, result);
    return result;
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

    vector<vector<int>> ans = generatePermutations(v);

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