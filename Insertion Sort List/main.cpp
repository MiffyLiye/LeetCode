#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << '\t';
        head = head->next;
    }
    cout << '\n';
}

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        return insertion_sort_list(head);
    }
private:
    ListNode* list_insert(ListNode*& head, ListNode* link) {
        if (head == nullptr) {
            link->next = nullptr;
            return link;
        }
        if (head->val > link->val) {
            link->next = head;
            return link;
        }
        auto current = head;
        for (; current->next != nullptr; current = current->next) {
            if (current->next->val > link->val) {
                link->next = current->next;
                current->next = link;
                return head;
            }
        }
        current->next = link;
        link->next = nullptr;
        return head;
    }

    ListNode* insertion_sort_list(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* current = head->next;
        head->next = nullptr;

        while (current != nullptr) {
            auto t = current;
            current = current->next;
            head = list_insert(head, t);
        }
        return head;
    }
};

ListNode* get_list(vector<int> v)
{
    if (v.size() == 0) {
        return nullptr;
    }
    else {
        ListNode* list = nullptr;
        ListNode* current = nullptr;
        for (size_t i = 0; i < v.size(); i++) {
            if (list == nullptr) {
                list = new ListNode(v[i]);
                current = list;
            }
            else {
                current->next = new ListNode(v[i]);
                current = current->next;
            }
            if (current == nullptr) {
                cerr << "error! get_list: no enough space" <<endl;
                throw;
            }
        }
        return list;
    }
}

int main()
{
    auto list = get_list({1, 3, 5, 2, 4, 6});
    print_list(list);

    Solution x;
    list = x.insertionSortList(list);
    print_list(list);
    
    return 0;
}