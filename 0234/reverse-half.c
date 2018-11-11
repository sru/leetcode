bool isPalindrome(struct ListNode* head) {

    if (head == NULL) {
        return true;
    }

    struct ListNode* tail = head;
    struct ListNode* half = head;

    while (tail->next != NULL && tail->next->next != NULL) {
        tail = tail->next->next;
        half = half->next;
    }

    if (tail->next != NULL) {
        tail = tail->next;
    }
    half = half->next;

    struct ListNode* prev = NULL;
    while (half != NULL) {
        struct ListNode* tmp = half->next;
        half->next = prev;
        prev = half;
        half = tmp;
    }

    while (head != NULL && tail != NULL) {
        if (head->val != tail->val) {
            return false;
        }
        head = head->next;
        tail = tail->next;
    }

    return true;
}
