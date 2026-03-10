
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* v_head = new ListNode();
        v_head->next = head;

        ListNode* fast = v_head;
        ListNode* slow = v_head;

        for (int i {}; i < n; ++i) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* node = slow->next;
        slow->next = node->next;
        delete node;

        head = v_head->next;
        delete v_head;

        return head;
    }
};