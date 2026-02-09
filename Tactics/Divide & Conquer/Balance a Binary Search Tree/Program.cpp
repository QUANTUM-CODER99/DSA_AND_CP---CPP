// CORE CONCEPT DFS TRASVERSAL OF TREE !!!

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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode *balanceBST(TreeNode *root) {
    // STEP 1: STORING IT INTO THEH INORDER FORM
    vector<int> values;
    inorder(root, values);

    // STEP 2: BUILDING THE BST WITH THE SORTED VALUES
    return build(values, 0, values.size() - 1);
  }

private:
  void inorder(TreeNode *node, vector<int> &values) {
    if (!node)
      return;
    inorder(node->left, values);
    values.push_back(node->val);
    inorder(node->right, values);
  }

  TreeNode *build(const vector<int> &values, int left, int right) {
    if (left > right)
      return nullptr;

    int mid = left + (right - left) / 2;
    TreeNode *node = new TreeNode(values[mid]);

    node->left = build(values, left, mid - 1);
    node->right = build(values, mid + 1, right);

    return node;
  }
};