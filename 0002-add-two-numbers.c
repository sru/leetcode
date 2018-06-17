/**
 * # Problem
 *
 * You are given two __non-empty__ linked lists representing two non-negative
 * integers. The digits are stored in __reverse order__ and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Definition for singly-linked list:
 *
 * ```
 * struct ListNode {
 *     int val;
 *     struct ListNode* next;
 * };
 * ```
 *
 * # Explanation
 *
 * Since the digits are stored in reverse order, we can go through each digits
 * and add them together, along with proper carry, to achieve addition on the
 * linked lists. The first loop goes through every digit pair on both `l1` and
 * `l2`. The second loop goes through every digits existing in one list but not
 * in the other. For such digits, we only care about digit places affected by
 * the carry; the rest remain as they are.
 *
 * ## Time Complexity
 *
 * Let `N` be the number of digits of the first integer and `M` the number of
 * digits of the second integer. The solution has time complexity of O(max(N,
 * M)).
 *
 * ## Space Complexity
 *
 * There is no additional space used that depends on input, so the solution has
 * constant space complexity (O(1)).
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
