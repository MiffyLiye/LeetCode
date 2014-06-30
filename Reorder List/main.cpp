#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        reorder_list(head);
    }
private:
    ListNode* reverse_list(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        auto current = head;
        auto current_next = head->next;
        head->next = nullptr;
        
        while (current_next != nullptr) {
            auto link = current_next->next;
            current_next->next = current;
            current = current_next;
            current_next = link;
        }
        return current;
    }

    void merge(ListNode* head, ListNode* a) {
        auto current = head;
        while(current != nullptr && a != nullptr) {
            auto t_current = current->next;
            current->next = a;
            a = a->next;
            current->next->next = t_current;
            current = t_current;
        }
    }

    void reorder_list(ListNode* head) {
        auto current = head;
        auto tail = head;
        if (head != nullptr) {
            tail = head->next;
        }
        else {
            return;
        }
        while (tail != nullptr && tail->next != nullptr) {
            current = current->next;
            tail = tail->next->next;

        }
        auto half_head = current->next;
        current->next = nullptr;
        half_head = reverse_list(half_head);
        merge(head, half_head);
    }
};

int main()
{
    Solution x;
    ListNode n_1(1);
    ListNode n_2(2);
    n_1.next = &n_2;
    ListNode n_3(3);
    n_2.next = &n_3;
    ListNode n_4(4);
    n_3.next = &n_4;

    auto head = &n_1;

    auto t = head;
    while (t != nullptr) {
        cout << t->val << '\t';
        t = t->next;
    }
    cout << '\n';

    x.reorderList(head);

    t = head;
    while (t != nullptr) {
        cout << t->val << '\t';
        t = t->next;
    }
    cout << '\n';

    return 0;
}