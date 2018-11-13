struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    // Trivial cases.
    if (l1 == NULL) { return l2; }
    if (l2 == NULL) { return l1; }

    struct ListNode head;
    struct ListNode* curr = &head;

    // Make l1 the "next" node.
    if (l1->val > l2->val) {
        struct ListNode* tmp = l1;
        l1 = l2;
        l2 = tmp;
    }

    for (;;) {
        // Assign the next part.
        curr->next = l1;

        // No more to do.
        if (l2 == NULL) { break; }

        // Skip until the lists need to switch.
        while (l1->next != NULL && l1->next->val <= l2->val) { l1 = l1->next; }
        curr = l1;

        // Switch.
        l1 = l2;
        l2 = curr->next;
    }

    return head.next;
}
