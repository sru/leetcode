int brokenCalc(int x, int y) {
    int count = 0;

    while (x < y) {

        if (y % 2 == 0) { y /= 2; }
        else { ++y; }

        ++count;
    }

    return count + x - y;
}
