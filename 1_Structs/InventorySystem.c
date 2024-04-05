#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
#define flush fflush(stdin);

typedef char string[20];

typedef struct{
    int id;
    string name;
    float price;
    int quantity;
    string supplier;
}item;

typedef struct{
    int count;
    item list[MAX];
}inventory;

void inializeInventory(inventory* List){
    List->count=0;
}

void addItem(inventory* List){
    if(List->count < MAX){
        printf("Enter the ID of the item: ");
        flush;
        scanf("%d",&List->list[List->count].id);
        printf("Enter the name of the item: ");
        flush;
        scanf("%[^\n]s",List->list[List->count].name);
        printf("Enter the price of the item: ");
        flush;
        scanf("%f",&List->list[List->count].price);
        printf("Enter the quantity of the item: ");
        flush;
        scanf("%d",&List->list[List->count].quantity);
        printf("Enter the supplier of the item: ");
        flush;
        scanf("%[^\n]s",List->list[List->count].supplier);

        List->count++;
        printf("Item added to inventory.\n\n");
    }else{
        printf("No more space.\n\n");
    }
}

void displayItem(item info){
    printf("ID: %d\n",info.id);
    printf("Name: %s\n",info.name);
    printf("Price: %.2f\n",info.price);
    printf("Quantity: %d\n",info.quantity);
    printf("Suppplier: %s\n\n",info.supplier);
}

void searchItem(inventory List){
    int itemID;
    printf("Enter item ID: ");
    scanf("%d",&itemID);
    int i;
    for(i=0;i<List.count&&List.list[i].id!=itemID;i++){}
    if(i<List.count){
        displayItem(List.list[i]);
    }
}

void displayInventory(inventory List){
    printf("\nCurrent inventory:\n");
    int i;
    for(i=0;i<List.count;i++){
        displayItem(List.list[i]);
    }
    printf("\n");
}

void report(inventory List){
    float sales = 0;
    int quant = 0;

    int i;
    for(i=0;i<List.count;i++){
        sales += List.list[i].price * List.list[i].quantity;
        quant += List.list[i].quantity;
    }
    printf("Total sales: $%.2f\n",sales);
    printf("Total quantity: %d\n\n",quant);
}

int main(){
    inventory L;
    inializeInventory(&L);
    int option = 0;

    while(1){
        printf("Inventory Management System\n");
        printf("1. Add new item\n");
        printf("2. Search item by ID\n");
        printf("3. Display inventory\n");
        printf("4. Generate report\n");
        printf("5. Exit\n");

        printf("Enter option.No: ");
        scanf("%d",&option);

        if(option == 1){
            addItem(&L);
            
        }else if(option == 2){
            searchItem(L);
        }else if(option == 3){
            displayInventory(L);
        }else if(option == 4){
            report(L);
        }else if(option == 5){
            printf("Exiting program.");
            exit(0);
        }

        option = 0;
    }
    return 0;
}
