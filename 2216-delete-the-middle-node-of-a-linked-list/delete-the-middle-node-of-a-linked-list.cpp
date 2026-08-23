/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

       
        int l = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            l++;
            temp = temp->next;
        }

        
        temp = head;
        for (int i = 0; i < (l / 2) - 1; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

   
        return head;
    }
};