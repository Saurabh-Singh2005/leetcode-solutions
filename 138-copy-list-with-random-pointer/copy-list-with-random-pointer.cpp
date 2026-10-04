class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> m;
        Node* oldTemp = head;

        while (oldTemp != nullptr) {
            m[oldTemp] = new Node(oldTemp->val);
            oldTemp = oldTemp->next;
        }

        oldTemp = head;
        while (oldTemp != nullptr) {
            m[oldTemp]->next = m[oldTemp->next];
            m[oldTemp]->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
        }

        return m[head];
    }
};