struct Point {
    int x;
    int y;
};

int CountWays(struct Point start, struct Point finish) {
    if (start.x == finish.x && start.y == finish.y) {
        return 1;
    }
    int counter = 0;
    if (start.x < finish.x) {
        struct Point next = {start.x + 1, start.y};
        counter += CountWays(next, finish);
    }
    if (start.y < finish.y) {
        struct Point next = {start.x, start.y + 1};
        counter += CountWays(next, finish);
    }
    if (start.x < finish.x && start.y < finish.y) {
        struct Point next = {start.x + 1, start.y + 1};
        counter += CountWays(next, finish);
    }
    return counter;
}
