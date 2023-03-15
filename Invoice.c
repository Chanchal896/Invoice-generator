#include<stdio.h>
#include<string.h>
#include<time.h>

struct order
{
    char item[50];
    int quantity;
    float price;
};

struct customers{
    char name[50];
    int num;
     struct order ord[50];
};
void generateBillHeader(char name[50]){
        time_t now=time(NULL);
        char *tnow=ctime(&now);
        printf("\n\n");
        printf("Time:%s\n",tnow);
        printf("\nInvoice To: %s",name);
        printf("\n");
        printf("---------------------------------------\n");
        printf("Items\t\t");
        printf("Qty\t\t");
        printf("Total\t\t");
        printf("\n---------------------------------------\n\n");
}
void generateBillBody(char item[30],int qty, float price){
        printf("%s\t\t",item);
        printf("%d\t\t",qty);
        printf("%.2f\t\t",qty * price);
        printf("\n");
}
void generateBillFooter(float total){
    printf("\n");
    int a;
    float tax=0;
    float netTotal=total;
    printf("In which province do you belong to:\n\n");
    printf("press 1 for: Alberta, British Columbia, Manitoba, Northwest Territories, Nunavut, Quebec, Saskatchewan, and Yukon\n\n");
    printf("press 2 for:Ontario\n\n");
    printf("press 3 for New Brunswick, Newfoundland and Labrador, Nova Scotia, and Prince Edward Island\n\n");
    scanf("%d",&a);
    switch (a)
    {
    case 1:tax=0.05;
            netTotal=(tax*total)+total;
        break;
    case 2:tax=0.13;
            netTotal=(tax*total)+total;
        break;
    case 3:tax=0.15;
            netTotal=(tax*total)+total;
        break;
    default: printf("not a valid option using Ontario tax bracket");
            tax=0.13;
            netTotal=(tax*total)+total;
        break;
    }
    printf("---------------------------------------\n");
    printf("\n\t\t\t\t-------");
    printf("\n GST/HSt tax \t\t\t %.2f",tax);
    printf("\n Total is \t\t\t%.2f",netTotal);
    printf("\n---------------------------------------\n");
}
int main(){
    int opt,n;
    opt=1;
    int total=0;
    struct customers cuw;
       //dashboard
    printf("\t============Invoice Generator============");
    printf("\n\nGenerate Invoice");
    while(opt==1){
        printf("\nPlease enter the name of the customer:\t");
        fgets(cuw.name,50,stdin);

        printf("\nPlease enter the number of items:\t");
        scanf("%d",&n);
       cuw.num = n;
        for(int i=0;i<n;i++){
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d:\t",i+1);
            fgets(cuw.ord[i].item,20,stdin);

            printf("Please enter the quantity:\t");
            scanf("%d",&cuw.ord[i].quantity);
            printf("Please enter the unit price:\t");
            scanf("%f",&cuw.ord[i].price);
            total += cuw.ord[i].quantity * cuw.ord[i].price;
        }

        generateBillHeader(cuw.name);
        for(int i=0;i<cuw.num;i++){
            generateBillBody(cuw.ord[i].item,cuw.ord[i].quantity,cuw.ord[i].price);
        }
        generateBillFooter(total);
        printf("To generate more invoices press 1:");
        scanf("%d",&opt);
}
return 0;
}