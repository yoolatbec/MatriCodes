#include <stdio.h>
#include <stdbool.h>

int main(){
    char a[100];
    char b[100];
    scanf("%s", a);
    scanf("%s", b);
    char a_letter[26];
    for(int count = 0; count < 26; count++){
        a_letter[count] = 0;
        b_letter[count] = 0;
    }
    char b_letter[26];
    for(int count = 0; count < 26; count++){
    }
    int current_a = 0;
    while(a[current_a] != '\0'){
        a_letter[a[current_a] - 'a']++;
        current_a++;
    }
    int current_b = 0;
    while(b[current_b] != '\0'){
        b_letter[b[current_b] - 'a']++;
        current_b++;
    }
    int flag = true;
    for(int count = 0; count < 26; count++){
        if(a_letter[count] != b_letter[count]){
            flag = false;
        }
    }
    if(flag){
        printf("%s\n", "Yes");
    } else {
        printf("%s\n", "No");
    }

    return 0;
}
