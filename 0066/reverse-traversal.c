int* plusOne(int* digits, int digitsSize, int* returnSize) {

    *returnSize = digitsSize;

    int carry = 1;
    for (int i = digitsSize - 1; carry != 0 && i >= 0; --i) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry == 1) {
        int* newDigits = malloc(sizeof(int) * (digitsSize + 1));
        *returnSize = digitsSize + 1;
        newDigits[0] = 1;
        memcpy(&newDigits[1], digits, sizeof(int) * digitsSize);
        digits = newDigits;
    }

    return digits;
}
