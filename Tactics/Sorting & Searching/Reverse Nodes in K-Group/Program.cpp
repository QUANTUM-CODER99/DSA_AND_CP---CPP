#include <bits/stdc++.h>
using namespace std;

#define FAST_IO()                                                              \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || k == 1)
      return head;

    // DUMMY NODE
    ListNode *dummy = new ListNode();
    dummy->next = head;

    ListNode *groupPrev = dummy;

    while (true) {
      ListNode *kth = getKthNode(groupPrev, k);
      if (!kth)
        break;

      ListNode *groupNext = kth->next;

      // REVERSE GROUP
      ListNode *prev = groupNext;
      ListNode *curr = groupPrev->next;

      while (curr != groupNext) {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
      }

      // CONNECT WITH THE PREVIOUS PART
      ListNode *temp = groupPrev->next;
      groupPrev->next = kth;
      groupPrev = temp;
    }

    return dummy->next;
  }

  ListNode *getKthNode(ListNode *curr, int k) {
    while (curr != nullptr && k > 0) {
      curr = curr->next;
      k--;
    }

    return curr;
  }
};

int main() {
  Solution s;
  int len, val, k;

  cout << "ENTER THE LEN :" << endl;
  cin >> len;

  if (len < 1)
    return 0;

  cout << "ENTER THE VALUES :" << endl;
  cin >> val;
  len--;

  ListNode *head = new ListNode(val);
  ListNode *mem = head;

  while (len-- > 0) {
    cin >> val;
    ListNode *curr = new ListNode(val);
    head->next = curr;
    head = head->next;
  }

  cout << "ENTER K :" << endl;
  cin >> k;

  mem = s.reverseKGroup(mem, k);

  while (mem) {
    cout << mem->val << '\t';
    mem = mem->next;
  }

  return 0;
}