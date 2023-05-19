#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    int day;
    int month;
    int year;
} DOB;
typedef struct
{
    char Last_name[20];
    char First_name[20];
    DOB Date_of_Birth;
    char address[100];
    char phone_number[20];
    char email[30];
} directory;
directory x[100];
int count;
int VALID_PHONE(char* p)
{
    if(*p=='\0')
        return 0;
    if(*p=='+' || isdigit(*p))
    {
        p++;
        while(*p!='\0')
        {
            if(!(isdigit(*p)))
                return 0;
            p++;
        }
    }
    else
        return 0;
    return 1;
}
int VALID_EMAIL(char x[])
{
    int count=0;
    int countp=0;
    int i,j;
    int t,t2;
    if(!((isalpha(x[0]))||isdigit(x[0])))
        return 0;
    for(i=0 ; i<strlen(x) ; i++)
    {
        if(x[i]==' ')
            return 0;
    }
    for(i=0 ; i<strlen(x) ; i++)
    {
        if(x[i]=='@')
        {
            count++;
            t=i;
            if(x[i-1]=='.')
                return 0;
        }
    }
    if (count!=1)
        return 0;
    if(count==1)
    {
        for(j=0; j<t ; j++)
        {
            if(!(x[j]=='_') && !(x[j]=='.') &&!(isalpha(x[j])||isdigit(x[j])))
            {
                return 0;
            }
        }
        for(i=t ; i<strlen(x) ; i++)
        {
            if(x[i]=='.')
            {
                countp++;
                t2=i;
                if(t2==t+1)
                    return 0;
                if(x[t2]==x[t2-1])
                    return 0;
            }
        }
        if(countp>0)
        {
            for(j=t+1; j<strlen(x) ; j++)
            {
                if(!(x[j]=='.')&&!(isalpha(x[j])||isdigit(x[j])))
                {
                    return 0;
                }
            }
        }
        else
            return 0;
        return 1;
    }
    return 1;
}
int VALID_BDAY(DOB* bday)
{
    if((bday->day<=0)||(bday->day>31))
        return 0;
    if((bday->month<=0)||(bday->month>12))
        return 0;
    if((bday->year>2021||bday->year<1900))
        return 0;
    return 1;
}
void sortbyLname ()
{
    int i;
    int j;
    directory temp;
    for(i=0; i<count; i++)
    {
        for(j=i+1; j<count; j++)
        {
            if(strcasecmp(x[i].Last_name,x[j].Last_name)>0)
            {
                temp=x[j];
                x[j]=x[i];
                x[i]=temp;
            }
        }
    }
    for(i=0; i<count; i++)
    {
        printf("\nDetails of user %d in the directory\n",i+1);
        printf("Last name:%s\n",x[i].Last_name);
        printf("First name:%s\n",x[i].First_name);
        printf("Date of birth:%d-%d-%d\n",x[i].Date_of_Birth.day,x[i].Date_of_Birth.month,x[i].Date_of_Birth.year);
        printf("address:%s\n",x[i].address);
        printf("phone number:%s\n",x[i].phone_number);
        printf("Email:%s\n\n",x[i].email);
    }
}
void SortByDOB ()
{
    int i,j;
    char k[20];
    directory temp;
    while(1)
    {
        printf("\n1.Sort from youngest to oldest\n2.Sort from oldest to youngest\n0.exit\nchoose 1, 2 or 0:");
        scanf("%s",k);
        if(strcasecmp("0",k)==0)
        {
            return;
        }
        else if(strcasecmp("1",k)==0)
        {
            for(i=0; i<count; i++)
            {
                for(j=i+1; j<count; j++)
                {
                    if(x[i].Date_of_Birth.year<x[j].Date_of_Birth.year)
                    {
                        temp=x[j];
                        x[j]=x[i];
                        x[i]=temp;
                    }
                    if(x[i].Date_of_Birth.year==x[j].Date_of_Birth.year)
                    {
                        if(x[i].Date_of_Birth.month<x[j].Date_of_Birth.month)
                        {
                            temp=x[j];
                            x[j]=x[i];
                            x[i]=temp;
                        }
                        if(x[i].Date_of_Birth.month==x[j].Date_of_Birth.month)
                        {
                            if(x[i].Date_of_Birth.day<x[j].Date_of_Birth.day)
                            {
                                temp=x[j];
                                x[j]=x[i];
                                x[i]=temp;
                            }
                        }
                    }
                }
            }
            printf("\nSorted from youngest to oldest:\n");
            for(i=0; i<count; i++)
            {
                printf("\nDetails of user %d in the directory\n",i+1);
                printf("Last name:%s\n",x[i].Last_name);
                printf("First name:%s\n",x[i].First_name);
                printf("Date of birth:%d-%d-%d\n",x[i].Date_of_Birth.day,x[i].Date_of_Birth.month,x[i].Date_of_Birth.year);
                printf("address:%s\n",x[i].address);
                printf("phone number:%s\n",x[i].phone_number);
                printf("Email:%s\n\n",x[i].email);
            }
            return;
        }

        else if(strcasecmp("2",k)==0)
        {
            for(i=0; i<count; i++)
            {
                for(j=i+1; j<count; j++)
                {
                    if(x[i].Date_of_Birth.year>x[j].Date_of_Birth.year)
                    {
                        temp=x[j];
                        x[j]=x[i];
                        x[i]=temp;
                    }
                    if(x[i].Date_of_Birth.year==x[j].Date_of_Birth.year)
                    {
                        if(x[i].Date_of_Birth.month>x[j].Date_of_Birth.month)
                        {
                            temp=x[j];
                            x[j]=x[i];
                            x[i]=temp;
                        }
                        if(x[i].Date_of_Birth.month==x[j].Date_of_Birth.month)
                        {
                            if(x[i].Date_of_Birth.day>x[j].Date_of_Birth.day)
                            {
                                temp=x[j];
                                x[j]=x[i];
                                x[i]=temp;
                            }
                        }
                    }
                }
            }
            printf("\nSorted from oldest to youngest:\n");
            for(i=0; i<count; i++)
            {
                printf("\nDetails of user %d in the directory\n",i+1);
                printf("Last name:%s\n",x[i].Last_name);
                printf("First name:%s\n",x[i].First_name);
                printf("Date of birth:%d-%d-%d\n",x[i].Date_of_Birth.day,x[i].Date_of_Birth.month,x[i].Date_of_Birth.year);
                printf("address:%s\n",x[i].address);
                printf("phone number:%s\n",x[i].phone_number);
                printf("Email:%s\n\n",x[i].email);
            }
            return;
        }
        else
            printf("Invalid option, please type 1, 2 or 0.\n");
    }

}
void LOAD(int*flag)
{
    FILE *f;
    f=fopen("Book.txt","r");
    if (f!=NULL)
    {
        while (!feof(f))
        {
            fscanf(f,"%[^,],",x[count].Last_name);
            fscanf(f,"%[^,],",x[count].First_name);
            fscanf(f,"%d-%d-%d,",&x[count].Date_of_Birth.day,&x[count].Date_of_Birth.month,&x[count].Date_of_Birth.year);
            fscanf(f,"%[^,],",x[count].address);
            fscanf(f,"%[^,],",x[count].phone_number);
            fscanf(f,"%s ",x[count].email);
            count++;
        }
        printf("FILE LOADED\n");
        *flag=1;
        fclose(f);
    }
    else
        printf("No data found. Try add some contacts and save them then try again.\n");
}
void SAVE()
{
    int i;
    FILE*f;
    f=fopen("Book.txt","w");
    for (i=0; i<count; i++)
    {
        fprintf(f,"%s,",x[i].Last_name);
        fprintf(f,"%s,",x[i].First_name);
        fprintf(f,"%d-%d-%d,",x[i].Date_of_Birth.day,x[i].Date_of_Birth.month,x[i].Date_of_Birth.year);
        fprintf(f,"%s,",x[i].address);
        fprintf(f,"%s,",x[i].phone_number);
        fprintf(f,"%s\n",x[i].email);
    }
    fclose(f);
    printf("ALL CHANGES HAVE BEEN SAVED\n");
}
void PRINT()
{
    char a[20];
    while(1)
    {
        printf("Print the directory sorted by:\n\n1.Sorted by last name\n2.Sorted by date of birth\n0.To exit:\nChoose 0, 1 or 2:");
        scanf("%s",a);
        if(strcasecmp("0",a)==0)
            return;
        if(strcasecmp("1",a)==0)
        {
            printf("\nSorted by last name alphabetically:\n");
            sortbyLname();
            return;
        }
        else if(strcasecmp("2",a)==0)
        {
            printf("\nSorted by date of birth:\n");
            SortByDOB();
            return;
        }
        else
        {
            printf("Invalid request,please type '1' or '2'\n\n");
        }
    }
}
void QUERY()
{
    int s=0;
    char L[20];
    int i;
    while(1)
    {
     printf("Enter Last Name To Search for contacts or type (0) to return: ");
     scanf("%s",L);
     if((strcasecmp(L,"0"))==0)
         return;
     for(i=0; i<count; i++)
     {
         if((strcasecmp(L,x[i].Last_name))==0)
         {
             s++;
             printf("\n\nContact %d:\n",s);
             printf("The First Name Is: %s\n",x[i].First_name);
             printf("The Date Of Birth Is %d/%d/%d\n",x[i].Date_of_Birth.day,
                    x[i].Date_of_Birth.month,x[i].Date_of_Birth.year);
             printf("Address Is: %s\n",x[i].address);
             printf("Email Is: %s\n",x[i].email);
             printf("Phone number Is: %s\n",x[i].phone_number);
         }
     }
     if (i==count&&s!=0)
         return;
     else if (s==0)
         printf("User Not Found\n");
    }
}
void ADD()
{
    char phone[20],email[20],e[5],f[5],g[5];
    char null[10] = "";
    DOB bday;
    printf("\nEnter contact to be added:\nEnter 0 to leave the function\n");
    printf("Last name: ");
    scanf("%s",x[count].Last_name);
    if(strcasecmp(x[count].Last_name,"0")==0)
    {
        strcpy(x[count].Last_name,null);
        return;
    }
    printf("First name: ");
    scanf("%s",x[count].First_name);
    if(strcasecmp(x[count].First_name,"0")==0)
    {
        strcpy(x[count].First_name,null);
        strcpy(x[count].Last_name,null);
        return;
    }
    while(1)
    {
        printf("Date of birth: ");
        printf("\nDay ?: ");
        scanf("%s",e);
        if(strcasecmp(e,"0")==0)
        {
            strcpy(x[count].First_name,null);
            strcpy(x[count].Last_name,null);
            return;
        }
        printf("Month ?: ");
        scanf("%s",f);
        if(strcasecmp(f,"0")==0)
        {
            strcpy(x[count].First_name,null);
            strcpy(x[count].Last_name,null);
            return;
        }
        printf("Year ?: ");
        scanf("%s",g);
        if(strcasecmp(g,"0")==0)
        {
            strcpy(x[count].First_name,null);
            strcpy(x[count].Last_name,null);
            return;
        }
        bday.day=0;
        bday.month=0;
        bday.year=0;
        if(strlen(e)<3&&strlen(f)<3&&strlen(g)==4)
        {
            bday.day=atoi(e);
            bday.month=atoi(f);
            bday.year=atoi(g);
            if(VALID_BDAY(&bday))
            {
                x[count].Date_of_Birth.day=bday.day;
                x[count].Date_of_Birth.month=bday.month;
                x[count].Date_of_Birth.year=bday.year;
                break;
            }
            else
                printf("NONE VALID BIRTH DATE\n\n");
        }
        else
            printf("NONE VALID BIRTH DATE\n\n");
    }
    printf("Address: ");
    getchar();
    gets(x[count].address);
    if(strcasecmp(x[count].address,"0")==0)
    {
        strcpy(x[count].First_name,null);
        strcpy(x[count].Last_name,null);
        strcpy(x[count].address,null);
        return;
    }
    while(1)
    {
        printf("Phone number: ");
        scanf("%s",phone);
        if(strcasecmp(phone,"0")==0)
        {
            strcpy(x[count].First_name,null);
            strcpy(x[count].Last_name,null);
            strcpy(x[count].address,null);
            return;
        }
        if(VALID_PHONE(phone))
        {
            strcpy(x[count].phone_number, phone);
            break;
        }
        else
            printf("NONE VALID PHONE NUMBER\n\n");
    }
    while(1)
    {
        printf("E-mail: ");
        scanf("%s",email);
        if(strcasecmp(email,"0")==0)
        {
            strcpy(x[count].First_name,null);
            strcpy(x[count].Last_name,null);
            strcpy(x[count].address,null);
            return;
        }
        if(VALID_EMAIL(email))
        {
            strcpy(x[count].email, email);
            break;
        }
        else
            printf("NONE VALID EMAIL ADDRESS\n\n");
    }
    printf("CONTACT ADDED\n");
    count++;
}
void DELETE()
{
    char m[20],n[20];
    int i=0,j,test=0;
    while(1)
    {
        printf("enter the last name which you want to delete or type (0) to return: ");
        scanf("%s",m);
        if(strcasecmp(m,"0")==0)
            return;
        printf("enter the first name which you want to delete: ");
        scanf("%s",n);
        for(i=0; i<count; i++)
        {
            if (strcasecmp(m,x[i].Last_name)==0&&strcasecmp(n, x[i].First_name)==0)
            {
                for(j=i; j<count; j++)
                {
                    x[j]=x[j+1];
                }
                i--;
                test++;
                count--;
            }
        }
        if(test!=0)
        {
            printf("CONTACT DELETED\n");
            return;
        }
        else
            printf("There is no contact with such last and first name\n");
    }
}
void MODIFY()
{
    int index=1,ind,in=0,num;
    char phone[20],email[20],lastname[20],option1[20],option2[20];
    DOB bday;
    while(1)
    {
        printf("Enter the last name of the contact you want to modify or type (0) to exit: ");
        scanf("%s",lastname);
        if (strcasecmp(lastname,"0")==0)
            return;
        for(int i=0; i<count; i++)
        {
            if (strcasecmp(lastname,x[i].Last_name)==0)
            {
                printf("%d.Last name: %s First name: %s \n",index, x[i].Last_name, x[i].First_name);
                ind=i;
                index++;
            }
        }
        if (index==1)
            printf("There is no contact with this last name\n\n");
        else
            break;
    }
    if(index>2)
    {
        while(1)
        {
            printf("^^^^Choose a contact from the above list^^^^: ");
            scanf("%s",option2);
            if(strlen(option2)==1||strlen(option2)==2)
            {
                in=0;
                for(int j=0; j<strlen(option2); j++)
                {
                    if(isdigit(option2[j])==0)
                    {
                        printf("Not s valid option\n");
                        in--;
                        break;
                    }
                    num=atoi(option2);
                    if(num>index-1||num<1)
                    {
                        printf("Not a valid option\n");
                        break;

                    }
                    in++;
                }
                printf("%d",in);
                if(in==1||in==2)
                    break;
            }
            else
                printf("Not a valid option\n");
        }
    }
    index=0;
    {
        for(int i=0; i<count; i++)
        {
            if (strcasecmp(lastname,x[i].Last_name)==0)
            {
                index++;
                if(index==num)
                {
                    ind=i;
                }
            }
        }
    }

    while(1)
    {
        printf("Which field do you want to modify?\n1.Last name\n2.First name\n3.Date of birth\n4.Address\n5.Phone number\n6.Email\n7.Quit\nChoose an option: ");
        scanf("%s",option1);

        if(strlen(option1)==1)
        {
            switch(*option1)
            {
            case('1'):
                printf("Enter the new Last name: ");
                scanf("%s",x[ind].Last_name);
                break;
            case('2'):
                printf("Enter the new First name: ");
                scanf("%s",x[ind].First_name);
                break;
            case('3'):
                while(1)
                {
                    char e[5],f[5],g[5];
                    printf("Enter the new Date of birth: ");
                    bday.day=0;
                    bday.month=0;
                    bday.year=0;
                    printf("\nday? :");
                    scanf("%s",e);
                    printf("month? :");
                    scanf("%s",f);
                    printf("year? :");
                    scanf("%s",g);
                    if(strlen(e)<3&&strlen(f)<3&&strlen(g)<5)
                    {
                        bday.day=atoi(e);
                        bday.month=atoi(f);
                        bday.year=atoi(g);
                        if(VALID_BDAY(&bday))
                        {
                            x[ind].Date_of_Birth.day=bday.day;
                            x[ind].Date_of_Birth.month=bday.month;
                            x[ind].Date_of_Birth.year=bday.year;
                            break;
                        }
                        else
                            printf("NONE VALID BIRTH DATE\n\n");
                    }
                    else
                        printf("NONE VALID BIRTH DATE\n\n");
                }
                break;
            case('4'):
                printf("Enter the new Address: ");
                getchar();
                gets(x[ind].address);
                break;
            case('5'):
                while(1)
                {
                    printf("Enter the new phone number: ");
                    scanf("%s",phone);
                    if(VALID_PHONE(phone))
                    {
                        strcpy(x[ind].phone_number, phone);
                        break;
                    }
                    else
                        printf("NONE VALID PHONE NUMBER\n\n");
                }
                break;
            case('6'):
                while(1)
                {
                    printf("Enter the new e-mail: ");
                    scanf("%s",email);
                    if(VALID_EMAIL(email))
                    {
                        strcpy(x[ind].email, email);
                        break;
                    }
                    else
                        printf("NONE VALID EMAIL ADDRESS\n\n");
                }
                break;
            case('7'):
                return;
            default:
                printf("\n\nNot a valid option, please choose a number from 1 to 7.\n");
            }
        }
        else
            printf("\n\nNot a valid option, please choose a number from 1 to 7.\n");
    }
    printf("\nCONTACT MODIFIED\n");
}
int TELEPHONE_BOOK()
{
    count=0;
    int flag=0;
    while(1)
    {
        char y[20];

        printf("\n1.LOAD\n2.Query\n3.ADD\n4.DELETE\n5.MODIFY\n6.PRINT\n7.SAVE\n8.Quit\nChoose an option: ");
        scanf("%s",y);
        if(strlen(y)==1)
        {
            switch(*y)
            {
            case('1'):
            {
                printf("\nflag value %d\n",flag);
                LOAD(&flag);
                printf("\nflag value %d\n",flag);
                break;
            }
            case('2'):
            {
                if(flag==0)
                    LOAD(&flag);
                QUERY();
                printf("\nflag value %d\n",flag);
                break;
            }
            case('3'):
            {
                if(flag==0)
                    LOAD(&flag);
                ADD();
                break;
            }
            case('4'):
            {
                if(flag==0)
                    LOAD(&flag);
                DELETE();
                break;
            }
            case('5'):
            {
                if(flag==0)
                    LOAD(&flag);
                MODIFY();
                printf("\nflag value %d\n",flag);
                break;
            }
            case('6'):
            {
                if(flag==0)
                {
                    LOAD(&flag);
                }
                PRINT();
                break;
            }
            case('7'):
            {
                if(flag==0)
                    LOAD(&flag);
                SAVE();
                break;
            }
            case('8'):

                return 0;
            default:
                printf("Not a correct choice, choose a number between 1 and 8");
            }
        }
        else
            printf("Not a correct choice, choose a number between 1 and 8");
    }
    return 1;
}
int main()
{
    TELEPHONE_BOOK();
    return 0;
}
