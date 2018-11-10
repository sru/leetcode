bool judgeCircle(char* moves) {
    int x = 0;
    int y = 0;
    for (;;) {
        switch (*moves++) {
            case 'L': --x; break;
            case 'R': ++x; break;
            case 'D': --y; break;
            case 'U': ++y; break;
            case '\0': return x == 0 && y == 0;
        }
    }
}
