//program to enter cost of, quantity, name of a product using structures
//also display the details of each product based on name entered by the user

#include<stdio.h>
#include<string.h>
typedef struct product{
    char product_name[30];
    int cost;
    int quantity;
}st;
void fnc(st *);
int main()
{
    st A[3];
    char productName[20];
    for(int i = 0;i<3;i++)
    {
        fnc(&A[i]);
        printf("\n");
    }
    printf("Enter product name : ");
    scanf("%s", productName);
    for(int i = 0;i<3;i++)
    {
        if(!strcmp(productName, A[i].product_name)){
            printf("cost = %d\n", A[i].cost);
            printf("quantity = %d\n", A[i].quantity);
        }
    }
    return 0;
} 
void  fnc(st *product)
{
    printf("Enter name of product: ");
    scanf(" %[^\n]s", product -> product_name);
    printf("Enter cost of product: ");
    scanf(" %d",&product->cost);
    printf("Enter quantity product: ");
    scanf(" %d",&product->quantity);

}