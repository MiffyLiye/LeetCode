#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
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
    ListNode *sortList(ListNode *head) {
        return merge_sort(head);
    }
private:
    ListNode* merge_sort_s(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* new_head = nullptr;
        ListNode* new_tail = nullptr;
        size_t count = 0;

        while (head != nullptr) {
            auto x = head;
            head = head->next;
            count += x != nullptr ? 1 : 0;
            x->next = nullptr;

            auto y = head;
            head = (head != nullptr) ? head->next : nullptr;
            count += (y != nullptr) ? 1 : 0;

            if (y != nullptr) {
                y->next = nullptr;
            }

            auto z = merge_s(x, y);
            if (new_head == nullptr) {
                new_head = z[0];
                new_tail = z[1];
            }
            else {
                new_tail->next = z[0];
                new_tail = z[1];
            }
        }

        head = new_head;

        for (size_t n = 2; n < count; n *= 2) {
            head = semi_merge_sort(head, n);
        }

        return head;
    }

    ListNode* semi_merge_sort(ListNode* head, size_t n) {
        ListNode* new_head = nullptr;
        ListNode* new_tail = nullptr;

        while (head != nullptr) {
            ListNode* head_x = nullptr;
            ListNode* x = nullptr;
            for (size_t i = 0; i < n && head != nullptr; i++) {
                if (head_x == nullptr) {
                    head_x = head;
                    x = head_x;
                    head = head->next;
                }
                else {
                    x->next = head;
                    x = x->next;
                    head = head->next;
                }
            }
            x->next = nullptr;

            ListNode* head_y = nullptr;
            ListNode* y = nullptr;
            for (size_t i = 0; i < n && head != nullptr; i++) {
                if (head_y == nullptr) {
                    head_y = head;
                    y = head_y;
                    head = head->next;
                }
                else {
                    y->next = head;
                    y = y->next;
                    head = head->next;
                }
            }
            if (y != nullptr) {
                y->next = nullptr;
            }

            auto z = merge_s(head_x, head_y);
            if (new_head == nullptr) {
                new_head = z[0];
            }
            else {
                new_tail->next = z[0];
            }
            new_tail = z[1];
        }

        return new_head;
    }

    vector<ListNode*> merge_s(ListNode* a, ListNode* b) {
        ListNode* head = nullptr;
        ListNode* current = nullptr;

        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                if (head == nullptr) {
                    head = a;
                    current = head;
                    a = a->next;
                }
                else {
                    current->next = a;
                    current = current->next;
                    a = a->next;
                }
            }
            else {
                if (head == nullptr) {
                    head = b;
                    current = head;
                    b = b->next;
                }
                else {
                    current->next = b;
                    current = current->next;
                    b = b->next;
                }
            } 
        }

        if (a != nullptr || b != nullptr) {
            ListNode* x = nullptr;
            if (a != nullptr) {
                x = a;
            }
            else {
                x = b;
            }
            while (x != nullptr) {
                if (head == nullptr) {
                    head = x;
                    current = head;
                    x = x->next;
                }
                else {
                    current->next = x;
                    current = current->next;
                    x = x->next;
                }
            }
        }

        return vector<ListNode*> {head, current};
    }

    ListNode* merge_sort(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        queue<ListNode*> q;
        while (head != nullptr) {
            auto x = head;
            auto y = head->next;
            head = y != nullptr ? y->next : y;
            x->next = nullptr;
            if (y != nullptr) {
                y->next = nullptr;
            }
            q.push(merge(x, y));
        }
        while (q.size() > 1) {
            auto x = q.front();
            q.pop();
            auto y = q.front();
            q.pop();
            q.push(merge(x, y));
        }
        return q.front();
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* head = nullptr;
        ListNode* current = nullptr;
        if (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                head = a;
                current = head;
                a = a->next;
            }
            else {
                head = b;
                current = head;
                b = b->next;
            } 
        }
        else {
            if (a != nullptr) {
                return a;
            }
            else if (b != nullptr) {
                return b;
            }
            else {
                return nullptr;
            }
        }
        
        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                current->next = a;
                current = current->next;
                a = a->next;
            }
            else {
                current->next = b;
                current = current->next;
                b = b->next;
            }
        }

        if (a != nullptr || b != nullptr) {
            if (a != nullptr) {
                current->next = a;
            }
            else {
                current ->next = b;
            }
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
    list = x.sortList(list);
    print_list(list);
    
    return 0;
}
