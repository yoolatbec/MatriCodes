#include <stdio.h>

void get_days(int year, int month);

int main(){
    int y, m;
    scanf("%d%d", &y, &m);
    get_days(y, m);

    return 0;
}

void get_days(int year, int month){
    if(year < 0 || year > 9999 || month <= 0 || month >= 13){
        puts("Invalid Input Detected");
        return;
    }
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int special_Feb = 29;
    int result;
    if(month != 2){
        result = months[month - 1];
    } else {
        if((year % 4) == 0){
            if((year % 100) == 0){
                if((year % 400) == 0){
                    result = special_Feb;
                } else {
                    result = months[month - 1];
                }
            } else {
                result = special_Feb;
            }
        } else {
            result = months[month - 1];
        }
    }
    printf("%04d/%02d has %d days.\n", year, month, result);
}