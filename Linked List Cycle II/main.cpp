#include<iostream>
#include<unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        return detect_cycle(head);
    }
private:
    ListNode* detect_cycle(ListNode* head) {
        unordered_set<ListNode*> s;
        while (head != nullptr) {
            if (s.find(head) != s.end()) {
                return head;
            }
            s.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

int main()
{
    ListNode n_0 {0};
    ListNode n_1 {1};
    n_0.next = &n_1;

    Solution x;
    cout << (x.detectCycle(&n_0) != nullptr ? "has" : "has not") << endl;

    n_1.next = &n_0;
    cout << (x.detectCycle(&n_0) != nullptr ? "has" : "has not") << endl;

    return 0;
}