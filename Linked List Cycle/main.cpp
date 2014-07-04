#include<iostream>
#include<set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        return has_cycle_s(head);
    }
private:
    bool has_cycle(ListNode* head) {
        set<ListNode*> s;
        while (head != nullptr) {
            if (s.find(head) != s.end()) {
                return true;
            }
            s.insert(head);
            head = head->next;
        }
        return false;
    }

    bool has_cycle_s(ListNode* head) {
        if (head == nullptr) {
            return false;
        }
        auto slower = head;
        auto faster = head->next;
        while (faster != nullptr) {
            if (slower == faster) {
                return true;
            }
            slower = slower->next;
            faster = (faster->next == nullptr) ? nullptr : faster->next->next;
        }
        return false;
    }
};

int main()
{
    ListNode n_0 {0};
    ListNode n_1 {1};
    n_0.next = &n_1;

    Solution x;
    cout << (x.hasCycle(&n_0) ? "has" : "has not") << endl;

    n_1.next = &n_0;
    cout << (x.hasCycle(&n_0) ? "has" : "has not") << endl;

    return 0;
}