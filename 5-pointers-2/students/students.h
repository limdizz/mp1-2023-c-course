enum Hobby { kPlaySport, kReadBooks, kListenToMusic };

struct Student {
    int age;
    enum Hobby hobby;
};

void FindOldestSportStudent(struct Student students[], int n, int* max) {
    int i;
    *max = -1;
    int max_age = -1;
    for (i = 0; i < n; i++) {
        if (students[i].hobby == kPlaySport) {
            if (*max == -1 || students[i].age > max_age) {
                *max = i;
                max_age = students[i].age;
            }
        }
    }
}

void FindYoungestReadingStudent(struct Student students[], int n, int* min) {
    int i;
    *min = -1;
    int min_age = -1;
    for (i = 0; i < n; i++) {
        if (students[i].hobby == kReadBooks) {
            if (*min == -1 || students[i].age < min_age) {
                *min = i;
                min_age = students[i].age;
            }
        }
    }
}
