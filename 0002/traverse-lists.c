/**
 * Definition for singly-linked list:
 *
 * ```
 * struct ListNode {
 *     int val;
 *     struct ListNode* next;
 * };
 * ```
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    if (l1 == NULL || (l1->val == 0 && l1->next == NULL)) {
        return l2;
    }

    if (l2 == NULL || (l2->val == 0 && l2->next == NULL)) {
        return l1;
    }

    int carry = 0;
    struct ListNode* l1_curr = l1;
    struct ListNode* l2_curr = l2;

    // Add up the common digits.
    for (;;) {
        // Assuming l1 and l2 are valid, sum will always be less than 100.
        int sum = l1_curr->val + l2_curr->val + carry;
        l1_curr->val = sum % 10;
        carry = sum / 10;

        if (l1_curr->next == NULL || l2_curr->next == NULL) {
            break;
        }

        l1_curr = l1_curr->next;
        l2_curr = l2_curr->next;
    }

    // Make sure l1 has more digits.
    if (l1_curr->next == NULL) {
        l1_curr->next = l2_curr->next;
    }

    // Add up the rest of the digits.
    while (carry != 0) {

        if (l1_curr->next == NULL) {
            break;
        }

        l1_curr = l1_curr->next;

        int sum = l1_curr->val + carry;
        l1_curr->val = sum % 10;
        carry = sum / 10;
    }

    // Cater for carry without node.
    if (carry != 0) {
        if (l1_curr->next == NULL) {
            l1_curr->next = l2;
            l2->val = carry;
            l2->next = NULL;
        }
    }

    return l1;
}
