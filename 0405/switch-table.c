char* toHex(int num) {
    // Maximum is 8 characters for 32-bit integer.
    char* hex = malloc(9 * sizeof(char));
    size_t len = 0;
    unsigned int dec = num;

    if (dec == 0) {
        hex[0] = '0';
        hex[1] = '\0';
        return hex;
    }

    unsigned int multiple = 1u << 28;
    while (dec / multiple == 0) {
        multiple >>= 4;
    }

    while (multiple != 0) {
        switch(dec / multiple) {
            case 0: hex[len++] = '0'; break;
            case 1: hex[len++] = '1'; break;
            case 2: hex[len++] = '2'; break;
            case 3: hex[len++] = '3'; break;
            case 4: hex[len++] = '4'; break;
            case 5: hex[len++] = '5'; break;
            case 6: hex[len++] = '6'; break;
            case 7: hex[len++] = '7'; break;
            case 8: hex[len++] = '8'; break;
            case 9: hex[len++] = '9'; break;
            case 10: hex[len++] = 'a'; break;
            case 11: hex[len++] = 'b'; break;
            case 12: hex[len++] = 'c'; break;
            case 13: hex[len++] = 'd'; break;
            case 14: hex[len++] = 'e'; break;
            case 15: hex[len++] = 'f'; break;
        }
        dec &= multiple - 1;
        multiple >>= 4;
    }

    hex[len] = '\0';
    return hex;
}
