#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return add_two_numbers(l1, l2);
    }
private:
    ListNode* add_two_numbers(ListNode* a, ListNode* b) {
        auto current_a = a;
        auto current_b = b;
        ListNode* current = nullptr;
        int carry = 0;

        while (current_a != nullptr && current_b != nullptr) {
            current_a->val += current_b->val + carry;
            if (current_a->val >= 10) {
                carry = 1;
                current_a->val -= 10;
            }
            else {
                carry = 0;
            }
            current = current_a;
            current_a = current_a->next;
            current_b = current_b->next;
        }

        while (current_a != nullptr || current_b != nullptr) {
            auto x = (current_a != nullptr) ? current_a : current_b;
            if (current != nullptr) {
                current->next = x;
                current_a = x;
                current_b = nullptr;
            }
            else {
                return x;
            }
            while (current_a != nullptr) {
                current_a->val += carry;
                if (current_a->val >= 10) {
                    carry = 1;
                    current_a->val -= 10;
                }
                else {
                    carry = 0;
                }
                current = current_a;
                current_a = current_a->next;
            }
        }


        if (carry == 0) {
            return a;
        }
        else {
            current->next = new ListNode(carry);
            if (current->next == nullptr) {
                throw;
            }
            return a;
        }
    }
};

void print_list(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << '\t';
        head = head->next;
    }
    cout << '\n';
}

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
    auto a = get_list({0});
    auto b = get_list({7, 3});
    Solution x;
    auto list = x.addTwoNumbers(a, b);
    print_list(list);

    return 0;
}