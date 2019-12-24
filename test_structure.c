#include <stdio.h>

struct my_struct{
    int a;
    int b;
};

void test_struct(struct my_struct );

int main(){
    struct my_struct a = {
        20,
        30
    };
    printf("%p\n", &a);
    test_struct(a);

    return 0;
}

void test_struct(struct my_struct m){
    printf("%p\n", &m);
}