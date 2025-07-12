int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year) {
    switch (month) {
        case 1: 
        case 3: 
        case 5: 
        case 7: 
        case 8: 
        case 10: 
        case 12: 
            return 31;
        case 4: 
        case 6: 
        case 9: 
        case 11: 
            return 30;
        case 2: 
            if (is_leap_year(year)) {
                return 29;
            }
            else {
                return 28;
            }
    }
    return 0;
}

int next_day(int current) {
    int year = current % 10000; 
    int month = current / 10000 % 100;
    int day = current / 1000000;

    if (day == days_in_month(month, year)) {
        
        if (month == 12) {
            year++; 
            month = 1; 
            day = 1; 
        }
        else {
            month++; 
            day = 1; 
        }
    }
    else {
        day++;
    }
    return day * 1000000 + month * 10000 + year;
}