#include <stdio.h>
#define ROAST_PRICE 5
#define HEN_PRICE 3
#define CHICK_PRICE 1

void buy_chicken(int cash, int total);

int main(){
    int cash, total;
    scanf("%d%d", &cash, &total);
    buy_chicken(cash, total);

    return 0;
}

void buy_chicken(int cash, int total){
    if((total > cash * 3) || (total < cash / ROAST_PRICE)){
        printf("%s", "no answer");
        return;
    }
    int flag = 0;
    int roast = 0;
    int hen = 0;
    int chick = 0;
    int max_roast = cash / ROAST_PRICE;
    int max_hen = 0;
    int current_cash;
    for(roast = max_roast; roast >= 0; roast--){
        current_cash = cash - roast * ROAST_PRICE;
        max_hen = current_cash / HEN_PRICE;
        for(hen = max_hen; hen >= 0; hen--){
            chick = (current_cash - hen * HEN_PRICE) * 3;
            if((roast + hen + chick) == total){
                flag = 1;
                printf("%d %d %d\n", roast, hen, chick);
            }
        }
    }
    if(!flag)
        printf("no answer");
}