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
✅ Advantages over your original code:
-> No used[] array → saves O(n) space.
-> No extra vector operations (push_back/pop_back) per recursive level → faster.
-> Still purely backtracking.
-> Very easy to understand.

| Complexity type | Complexity |
| --------------- | ---------- |
| Time            | O(n · n!)  |
| Space (output)  | O(n · n!)  |
| Auxiliary space | O(n)       |

*/

/*---------Permutation Function-------*/
void permute(int index, vector<int>& nums, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) { // CORE BACKTRACKING ...
        swap(nums[index], nums[i]);
        permute(index + 1, nums, result);
        swap(nums[index], nums[i]); 
    }
}

vector<vector<int>> generatePermutations(vector<int>& nums) {
    vector<vector<int>> result;
    permute(0, nums, result);
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