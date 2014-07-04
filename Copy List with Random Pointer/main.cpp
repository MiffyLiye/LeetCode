#include<iostream>
#include<stack>
#include<unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        return copy_random_list(head);
    }
private:
    RandomListNode* copy_random_list(RandomListNode* head) {
        if (head == nullptr) {
            return head;
        }
        stack<RandomListNode*> to_do {};
        unordered_map<RandomListNode*, RandomListNode*> m {};

        to_do.push(head);
        auto new_node = new RandomListNode(head->label);
        if (new_node == nullptr) {
            cerr << "error! copy_random_list: no enough space" << endl;
            throw;
        }
        m.insert(pair<RandomListNode*, RandomListNode*>(head, new_node));

        while (to_do.size() > 0) {
            auto x = to_do.top();
            to_do.pop();
            new_node = new RandomListNode(x->label);
            if (new_node == nullptr) {
                cerr << "error! copy_random_list: no enough space" << endl;
                throw;
            }
            m.insert(pair<RandomListNode*, RandomListNode*>(x, new_node));
            if (x->next != nullptr && m.find(x->next) == m.end()) {
                to_do.push(x->next);
            }
            if (x->random != nullptr && m.find(x->random) == m.end()) {
                to_do.push(x->random);
            }
        }

        for (auto i = m.begin(); i != m.end(); i++) {
            i->second->next = (i->first->next == nullptr) ? nullptr : m[i->first->next];
            i->second->random = (i->first->random == nullptr) ? nullptr : m[i->first->random];
        }
        return m[head];
    }
};

int main()
{
    cout << "no local test\n";
    return 0;
}