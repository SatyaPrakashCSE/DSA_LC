struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* left = head;
    struct ListNode* right = head;

    while (right != NULL) {
        if (left->val == right->val) {
            right = right->next;
        }
        else {
            left->next = right;
            left = right;
            right = right->next;
        }
    }

    if (left != NULL) {
        left->next = NULL;
    }

    return head;
}