#include <stdio.h>

void pattern_0(int pattern, int to_display);
void pattern_1(int display);
void pattern_2(int display);
void pattern_3(int display);
void pattern_4(int display);

int main(){
    int pattern, display;
    scanf("%d%d", &pattern, &display);
    pattern_0(pattern, display);

    return 0;
}

void pattern_0(int pattern, int display){
    switch(pattern){
        case 1:
            pattern_1(display);
            break;
        case 2:
            pattern_2(display);
            break;
        case 3:
            pattern_3(display);
            break;
        case 4:
            pattern_4(display);
            break;
        default:
            break;
    }
}

void pattern_1(int display){
    for(int outer = 1; outer <= display; outer++){
        for(int inner = 1; inner <= outer; inner++){
            printf("%3d", inner);
        }
        printf("\n");
    }
}

void pattern_2(int display){
    for(int outer = display; outer >= 1; outer--){
        for(int inner = 1; inner <= outer; inner++){
            printf("%3d", inner);
        }
        printf("\n");
    }
}

void pattern_3(int display){
    for(int outer = 1; outer <= display; outer++){
        for(int blank_count = display - outer; blank_count > 0; blank_count--){
            printf("   ");
        }
        for(int count = 1; count <= outer; count++){
            printf("%3d", count);
        }
        printf("\n");
    }
}

void pattern_4(int display){
    for(int outer = display; outer >= 1; outer--){
        for(int blank_count = display - outer; blank_count > 0; blank_count--){
            printf("   ");
        }
        for(int count = 1; count <= outer; count++){
            printf("%3d", count);
        }
        printf("\n");
    }
}