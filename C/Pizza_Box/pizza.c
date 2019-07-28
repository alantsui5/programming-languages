#include<stdio.h>

int main(){
    int choice = 0;
    double cost = 0,tax = 0.3;
    double pizza_price[3];
    pizza_price[0] = 50.99;
    pizza_price[1] = 23.99;
    pizza_price[2] = 18.33;
    char *pizza[3];
    pizza[0] = "A Pizza";
    pizza[1] = "B Pizza";
    pizza[2] = "C Pizza";
    int pizza_number[3];
        pizza_number[0] = 0;
        pizza_number[1] = 0;
        pizza_number[2] = 0;
    while (1){
        

        printf("\nBasket --------\n\n");
        if(pizza_number[0]>0) printf("%s  %.2f\n",pizza[0],pizza_price[0]*pizza_number[0]);
        if(pizza_number[1]>0) printf("%s  %.2f\n",pizza[1],pizza_price[1]*pizza_number[1]);
        if(pizza_number[2]>0) printf("%s  %.2f\n",pizza[2],pizza_price[2]*pizza_number[2]);
        printf("Total Cost %.2f\n---------------\n\n",cost);
        printf("Please select a pizza to add to your basket:\n");
        printf("1: %s price: %.2f\n",pizza[0],pizza_price[0]);
        printf("1: %s price: %.2f\n",pizza[1],pizza_price[1]);
        printf("1: %s price: %.2f\n",pizza[2],pizza_price[2]);
        printf("Enter your choice here >>\n");
        scanf("%d",&choice);

        
        switch (choice){
            case 1:
            cost += pizza_price[0]*(1+tax);
            pizza_number[0]+=1;
            break;
            case 2:
            cost += pizza_price[1]*(1+tax);
            pizza_number[1]+=1;
            break;
            case 3:
            cost += pizza_price[2]*(1+tax);
            pizza_number[2]+=2;
            break;
            case 0:
            printf("Exit\n");
            return 0;
            default:
            printf("You inserted incorrect number");
            break;
        }
    }

}