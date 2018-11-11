bool isValid(char* s) {
    size_t cap = BUFSIZ;
    size_t len = 0;
    char* stack = malloc(cap * sizeof(char));

    while (*s != '\0') {
        char ch = *s++;
        if (ch == '(' || ch == '[' || ch == '{') {
            if (len == cap) {
                cap *= 2;
                stack = realloc(stack, cap * sizeof(char));
            }
            stack[len++] = ch;
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (
                len == 0 ||
                ch == ')' && stack[len - 1] != '(' ||
                ch == ']' && stack[len - 1] != '[' ||
                ch == '}' && stack[len - 1] != '{'
            ) {
                free(stack);
                return false;
            }
            --len;
        }
    }

    free(stack);
    return len == 0;
}
