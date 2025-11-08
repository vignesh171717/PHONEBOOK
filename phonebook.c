#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct phonebook{
    char name[100];
    char mail[100];
    char cn[15];
};
void add();
void search();
void delete();
void display();
void update();
int main(){
    int choice;
    do{
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                        PhoneBook");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1->add contact\n");
        printf("2->search contact\n");
        printf("3->remove contact\n");
        printf("4->display contacts\n");
        printf("5->update contact\n");
        printf("6->Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                add(); 
                break;
            case 2: 
                search(); 
                break;
            case 3: 
                delete(); 
                break;
            case 4: 
                display(); 
                break;
            case 5: 
                update(); 
                break;
            case 6: printf("Exited successfully......"); exit(0);
            default: printf("Enter valid number to perform operations"); 
        }
    }
    while(1);
}
void add(){
    struct phonebook x;
    FILE *p;
    p = fopen("phone.txt","a");
    printf("Enter name:");
    scanf("%s",&x.name);
    printf("Enter mail-id:");
    scanf("%s",&x.mail);
    printf("Enter cell number:");
    scanf("%s",&x.cn);
    fprintf(p,"%s %s %s\n",&x.name,&x.cn,&x.mail);
    fclose(p);
}
void display(){
    struct phonebook x;
    FILE *p;
    p = fopen("phone.txt","r");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                        PhoneBook");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%-20s %-15s %-30s","Name","Cell No","Mail");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while(fscanf(p,"%s%s%s",x.name,x.cn,x.mail)==3){
        printf("%-20s%-15s%-30s\n",x.name,x.cn,x.mail);
    }
    fclose(p);
}
void search(){
    struct phonebook x;
    FILE *p;
    p = fopen("phone.txt","r");
    char c[50];
    int cc,i=0;
    printf("1.Name\n2.Cell\n3.Mail\n");
    printf("Enter choice:");
    scanf("%d",&cc);
    printf("Enter:");
    scanf("%s",&c);
    while(fscanf(p,"%s%s%s",x.name,x.cn,x.mail)==3){
        if(strcmp(x.name,c)==0 || strcmp(x.mail,c)==0 || strcmp(x.cn,c)==0){
            printf("Details Found....\n");
            printf("%s\t%s\t%s\n",x.name,x.cn,x.mail);
            i++;
            break;
        }
        
    }
    if(i==0){
        printf("Details Not found\n");
    }
    fclose(p);
}
void update(){
    struct phonebook x;
    FILE *p, *temp;
    p = fopen("phone.txt","r");
    temp = fopen("phone1.txt","w");
    char c[50];
    int cc;
    printf("Enter old name:");
    scanf("%s",&c);
    while(fscanf(p,"%s%s%s",x.name,x.cn,x.mail)==3){
        if(strcmp(x.name,c)==0){
            printf("Enter new mail-id:");
            scanf("%s",&x.mail);
            printf("Enter new cell number:");
            scanf("%s",&x.cn);
            cc++;    
        }
        fprintf(temp,"%s %s %s\n",x.name,x.cn,x.mail);
    }
    if(cc==1){
        printf("Updated successfully");
    }
    fclose(p);
    fclose(temp);
    remove("phone.txt");
    rename("phone1.txt","phone.txt");
}
void delete(){
    struct phonebook x;
    FILE *p,*temp;
    p = fopen("phone.txt","r");
    temp = fopen("phone1.txt","w");
    char c[50];
    int cc=0;
    printf("Enter name whose details to be deleted:");
    scanf("%s",&c);
    while(fscanf(p,"%s%s%s",x.name,x.cn,x.mail)==3){
        if(strcmp(x.name,c)==0){
            cc++;
            continue;
        }
        fprintf(temp,"%s %s %s\n",x.name,x.cn,x.mail);
    }
    if(cc){
        printf("Deleted successfully");
    }
    fclose(p);
    fclose(temp);
    remove("phone.txt");
    rename("phone1.txt","phone.txt");
}