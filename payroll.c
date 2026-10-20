#include <stdio.h>
#define C 0.125
#define FT 0.25
#define ST 0.1
#define R 0.08
float commission(int sales){
    return C*sales;
}
float Federal(float gross){
    return FT*gross;
}
float State(float gross){
    return ST*gross;
}
float Retirement(float gross){
    return R*gross;
}
int main()
{
    int sales[100],n,highest,choice,find,found=0,UL[100],TS=0;
    float gross[100],ns[100],bonus[100],TG=0,TB=0,Tns=0;
    char name[100][20];
    int id[100];
    printf("Number of employees:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    printf("Enter ID:");
        scanf("%d",&id[i]);
        printf("Employee name:");
        scanf("%19s",name[i]);
    printf("Enter worth of sales of employee:");
    scanf("%d",&sales[i]);
        printf("Number of unpaid leaves:");
        scanf("%d",&UL[i]);
    bonus[i]=(20*sales[i])/100-(UL[i]*100);
    gross[i]=commission(sales[i])+bonus[i];
        ns[i]=gross[i]-Federal(gross[i])-State(gross[i])-Retirement(gross[i]);
        printf("Bonus received:%.2f\n",bonus[i]);
    printf("Commission recieved:%.2f\n",commission(sales[i]));
    printf("Federal tax:%.2f\n",Federal(gross[i]));
    printf("State tax:%.2f\n",State(gross[i]));
    printf("Retirement Deduction:%.2f\n",Retirement(gross[i]));
    printf("Net earning:%.2f\n",ns[i]);
        printf("\n===============\n");
        highest=gross[0];
        for(int i=1;i<n;i++){
            if(gross[i]>highest){
                highest=gross[i];
            }
        }
        TS+=sales[i];
        TB+=bonus[i];
        TG+=gross[i];
        Tns+=ns[i];
            }
    do{
    printf("\n===================\nChoose among following options\n");
    printf("1.View employee(s) details\n2.View employee(s) of the month\n3.Give total analysis\n4.EXIT\n");
        printf("=================\n");
        printf("Choice:");
    scanf("%d",&choice);
        switch(choice){
            case(1):
            printf("Enter employee ID:");
            scanf("%d",&find);
            for(int i=0;i<n;i++){
                if(find==id[i]){
                    found=1;
                    if(found==1){
                printf("\n=================\n");
                printf("Employee ID:%d\n",id[i]);
                printf("Employee name:%s\n",name[i]);
                printf("sales made by employee:%d\n",sales[i]);
                printf("Bonus recieved by employee:%d\n",bonus[i]);
                printf("Net salary of employee :%.2f\n",ns[i]);
                printf("\n===================\n");
                }
                }
            }
                if(found==0){
                    printf("\nEmployee not found\n");
                    printf("====================");
                }
            break;
    case(2):
    printf("==============\nEmployee of the month award\n");
    for(int i=0;i<n;i++){
    if(gross[i]==highest){
     printf("ID:%d\n",id[i]);
    printf("Name:%s\n",name[i]);
     printf("Sales:%d\n",sales[i]);
    printf("Number of unpaid leaves:%d\n",UL[i]);
        printf("Gross earnings:%.2f\n",gross[i]);
        printf("Award based on highest gross earnings\n");
     printf("\n=================\n");
    }
    }
            break;
            case(3):
            printf("\n==TOTAL ANALYSIS OF ALL EMPLOYEES==\n");
            printf("\nTotal sales made:%d\n",TS);
            printf("Total bonuses given:%.2f\n",TB);
            printf("Total gross earning of employees:%.2f\n",TG);
                printf("Total net earnings of employees:%.2f\n",Tns);
                printf("\n=================\n");
            break;
            case(4):
            printf("\nEXITING THE SYSTEM\n");
            break;
            default:
            printf("\nInvalid option\n");
            break;
    }
    }
        while(choice!=4);
    return 0;
}