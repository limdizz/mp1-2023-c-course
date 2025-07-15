#include "acutest.h"
#include "students.h"

void TestFunction() {
    struct Student students1[3] = {{20, kReadBooks}, {18, kPlaySport}, {22, kPlaySport}};
    int max_sport_index1, min_reading_index1;
    FindOldestSportStudent(students1, 3, &max_sport_index1);
    FindYoungestReadingStudent(students1, 3, &min_reading_index1);
    TEST_ASSERT(max_sport_index1 == 2);
    TEST_ASSERT(min_reading_index1 == 0);
    struct Student students2[4] = {
        {20, kReadBooks}, {18, kPlaySport}, {22, kPlaySport}, {19, kListenToMusic}};
    int max_sport_index2, min_reading_index2;
    FindOldestSportStudent(students2, 3, &max_sport_index2);
    FindYoungestReadingStudent(students2, 4, &min_reading_index2);
    TEST_ASSERT(max_sport_index2 == 2);
    TEST_ASSERT(min_reading_index2 == 0);
}

TEST_LIST = {{"students", TestFunction}, {NULL, NULL}};
