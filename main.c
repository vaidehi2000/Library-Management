#include<stdio.h>
#include <stdlib.h>
#include<string.h>

char catagories[][20]={"Programming","Digital_Electronics","Mathematics","English","Physics"};
void returnfunc(void);//645
void mainmenu(void);//62
void addbooks(void);//130
void deletebooks(void);//174
void editbooks(void);//593
void searchbooks(void);//245
void issuebooks(void);//360
void viewbooks(void);//557
int  getdata();//656
int  checkid(int);//695
void Password();//712

FILE *fp,*ft,*fs;

int s;
char findbook;
char password[10]={"IIITV"};


struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    char *cat;
};
struct books a;
int main()

{
      Password();
      getch();
   return 0;

}
void mainmenu()
{

    system("cls");
    int i;
     printf("\t\t\t####*** IIIT VADODARA LIBRARY MANAGEMENT ****####\n");
     printf("                              ===================================\n\n");
     printf("********** MAIN MENU ************\n");


    printf(" 1. Add Books   \n");

    printf(" 2. Delete books\n");

    printf(" 3. Search Books\n");

    printf(" 4. Issue Books\n");

    printf(" 5. View Book list\n");

    printf(" 6. Edit Book's Record\n");

    printf(" 7. Close Application\n");

    printf("------------------------------------------\n");


        printf("Enter your choice:\n");
    switch(getch())
    {
        case '1':
        addbooks();
        break;
    case '2':
        deletebooks();
        break;
        case '3':
        searchbooks();
        break;
    case '4':
        issuebooks();
        break;
        case '5':
        viewbooks();
        break;
        case '6':
        editbooks();
        break;
        case '7':
        {

        exit(0);
        }
        default:
        {
                printf("\aWrong Entry!!Please re-entered correct option\n");
        if(getch())
        mainmenu();

        }


    }
}
void addbooks(void)    // add books
{
    system("cls");
    int i;

    printf("************SELECT CATEGOIES***************\n");


    printf(" 1. Programming\n");

    printf(" 2. Digital Electronics\n");

    printf(" 3. mathematics\n");

    printf(" 4. English\n");

    printf(" 5. Physics\n");

    printf(" 6. Back to main menu\n");

    printf("Enter your choice:\n");
    scanf("%d",&s);
    if(s==6)

    mainmenu() ;
    system("cls");
    fp=fopen("book.txt","a+");
    if(getdata()==1)
    {
    a.cat=catagories[s-1];
    fseek(fp,0,SEEK_END);
    fwrite(&a,sizeof(a),1,fp);
    fclose(fp);

    printf("The record is sucessfully saved\n");

    printf("Save any more?(Y / N):\n");
    if(getch()=='n')
        mainmenu();
    else
        system("cls");
        addbooks();
    }
}
void deletebooks()   // delete books
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')
    {
    system("cls");

    printf("Enter the Book ID to  delete:\n");
    scanf("%d",&d);
    fp=fopen("book.txt","r+");
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if(a.id==d)
        {


        printf("The book record is available\n");

        printf("Book name is %s\n",a.name);


        findbook='t';
        }
    }
    if(findbook!='t')
    {

        printf("No record is found modify the search\n");
        if(getch())
        mainmenu();
    }
    if(findbook=='t' )
    {

                printf("Do you want to delete it?(Y/N):\n");
        if(getch()=='y')
        {
        ft=fopen("test.txt","w+");
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id!=d)
            {
            fseek(ft,0,SEEK_CUR);
            fwrite(&a,sizeof(a),1,ft);
            }
        }
        fclose(ft);
        fclose(fp);
        remove("book.txt");
        rename("test.txt","book.txt");
        fp=fopen("book.txt","r+");
        if(findbook=='t')
        {
                     printf("The record is sucessfully deleted\n");

            printf("Delete another record?(Y/N)\n");
        }
        }
    else
    mainmenu();
    fflush(stdin);
    another=getch();
    }
    }

    mainmenu();
}
void searchbooks()
{
    system("cls");
    int d;
    printf("\n\n\t\t*****************************Search Books*********************************");

    printf(" 1. Search By ID\n");

    printf(" 2. Search By Name\n");

    printf("Enter Your Choice\n");
    fp=fopen("book.txt","r+");
    rewind(fp);
    switch(getch())
    {
      case '1':
    {
        system("cls");

        printf("****Search Books By Id****\n");

        printf("Enter the book id:\n");
        scanf("%d",&d);

        printf("Searching........\n");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
        if(a.id==d)
        {


            printf("The Book is available\n");

            printf(" ID:%d",a.id);

            printf(" Name:%s",a.name);

            printf(" Author:%s ",a.Author);

            printf(" Qantity:%d ",a.quantity);

            printf(" Price:Rs.%.2f",a.Price);



            findbook='t';
        }

        }
        if(findbook!='t')
        {

        printf("\aNo Record Found\n");
        }

        printf("Try another search?(Y/N)\n");
        if(getch()=='y')
        searchbooks();
        else
        mainmenu();
        break;
    }
    case '2':
    {
        char s[15];
        system("cls");

        printf("****Search Books By Name****\n");

        printf("Enter Book Name:\n");
        scanf("%s",s);
        int d=0;
        while(fread(&a,sizeof(a),1,fp)==1)
        {
        if(strcmp(a.name,(s))==0)
        {
               printf("The Book is available\n");

            printf(" ID:%d",a.id);

            printf("Name:%s",a.name);

            printf(" Author:%s",a.Author);

            printf(" Qantity:%d",a.quantity);

            printf(" Price:Rs.%.2f",a.Price);

            d++;
        }

        }
        if(d==0)
        {


        printf("\aNo Record Found\n");
        }

        printf("Try another search?(Y/N)\n");
        if(getch()=='y')
        searchbooks();
        else
        mainmenu();
        break;
    }
    default :
    getch();
    searchbooks();
    }
    fclose(fp);
}
void issuebooks(void)
{
    int t;

    system("cls");
    printf("********************************ISSUE SECTION**************************\n");

    printf(" 1. Issue a Book\n");

    printf(" 2. View Issued Book\n");

    printf(" 3. Remove Issued Book\n");

    printf("Enter a Choice:\n");
    switch(getch())
    {
    case '1':  //issue book
    {
        system("cls");
        int c=0;
        char another='y';
        while(another=='y')
        {
            system("cls");

            printf("***Issue Book section***");

            printf("Enter the Book Id:\n");
            scanf("%d",&t);
            fp=fopen("book.txt","r+");
            fs=fopen("Issue.txt","a+");
            if(checkid(t)==0)
            {
                printf("The book record is available\n");

                 printf("There are %d unissued books in library\n ",a.quantity);

                 printf("The name of book is %s\n",a.name);

                 printf("Enter student name:\n");
                 scanf("%s",a.stname);

                 fseek(fs,sizeof(a),SEEK_END);
                 fwrite(&a,sizeof(a),1,fs);
                 fclose(fs);
                 c=1;
            }
            if(c==0)
            {

            printf("No record found\n");
            }

            printf("Issue any more(Y/N):");
            fflush(stdin);
            another=getch();
            fclose(fp);
        }

        break;
    }
    case '2':  //show issued book list
    {
        system("cls");
        int j=3;
        printf("*******************************Issued book list*******************************\n");

        printf("\nSTUDENT NAME    CATEGORY       ID      BOOK NAME    \n");
           fs=fopen("Issue.txt","r+");
        while(fread(&a,sizeof(a),1,fs)==1)
        {


            printf("%s\t\t",a.stname);

            printf("%s\t",a.cat);

            printf("%d\t",a.id);

            printf("%s\t\t\n",a.name);


            j++;

        }
        fclose(fs);

        returnfunc();
    }
    break;

    case '3':  //remove issued books
    {
        system("cls");
        int b;
        FILE *fg;
        char another='y';
        while(another=='y')
        {

            printf("Enter book id to remove:\n");
            scanf("%d",&b);
            fs=fopen("Issue.txt","r+");
            while(fread(&a,sizeof(a),1,fs)==1)
            {
                if(a.id==b)
                {

                    findbook='t';
                }
                if(findbook=='t')
                {

                    printf("Do You Want to Remove it?(Y/N)");
                    if(getch()=='y')
                    {
                        fg=fopen("record.txt","w+");
                        rewind(fs);
                        while(fread(&a,sizeof(a),1,fs)==1)
                        {
                            if(a.id!=b)
                            {
                            fseek(fs,0,SEEK_CUR);
                            fwrite(&a,sizeof(a),1,fg);
                            }
                        }
                        fclose(fs);
                        fclose(fg);
                        remove("Issue.txt");
                        rename("record.txt","Issue.txt");

                        printf("The issued book is removed from list\n");

                       }

                }
                if(findbook!='t')
                {

                    printf("No Record Found\n");
                }
            }

            printf("Delete any more?(Y/N)");
            another=getch();
        }
    }
    default:

    printf("\aWrong Entry!!\n");
    getch();
    issuebooks();
    break;
      }

      returnfunc();
}
void viewbooks(void)
{
    int i=0,j;
    system("cls");

    printf("\n*********************************Book List*****************************\n");

  //  printf(" CATEGORY       ID             BOOK NAME              AUTHOR                    QTY             PRICE           \n");
    j=4;
    fp=fopen("book.txt","r+");
    while(fread(&a,sizeof(a),1,fp)==1)
    {

    printf("CATEGORY : %s\t\n",a.cat);

    printf("ID : %d\t\n",a.id);

    printf("BOOK NAME : %s\n",a.name);

    printf("AUTHOR : %s\n",a.Author);

    printf("QTY : %d\n",a.quantity);

    printf("PRICE : %.2f\n",a.Price);


    printf("\n\n");
    j++;
    i=i+a.quantity;
      }

      printf("Total Books =%d\n",i);
      fclose(fp);

      returnfunc();
}
void editbooks(void)  //edit information
{
    system("cls");
    int c=0;
    int d,e;

    printf("****Edit Books Section****\n");
    char another='y';
    while(another=='y')
    {
        system("cls");

        printf("Enter Book Id to be edited:\n");
        scanf("%d",&d);
        fp=fopen("book.txt","r+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(checkid(d)==0)
            {

                printf("The book is availble\n");

                printf("The Book ID:%d\n",a.id);

                printf("Enter new name:\n");scanf("%s",a.name);

                printf("Enter new Author:\n");scanf("%s",a.Author);

                printf("Enter new quantity:\n");scanf("%d",&a.quantity);

                printf("Enter new price:\n");scanf("%f",&a.Price);


                printf("The record is modified\n");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                c=1;
            }
            if(c==0)
            {

                printf("No record found\n");
            }
        }

        printf("Modify another Record?(Y/N)\n");
        fflush(stdin);
        another=getch() ;
    }
        returnfunc();
}
void returnfunc(void)
{
    {
    printf(" Press ENTER to return to main menu\n");
    }
    a:
    if(getch()==13)
    mainmenu();
    else
    goto a;
}
int getdata ()
{
    int t;

    printf("Enter the Information Below\n");


    printf("Category:\n");

    printf("%s\n",catagories[s-1]);

    printf("Book ID:\t");

    scanf("%d",&t);
    if(checkid(t) == 0)
    {

        printf("\aThe book id already exists\a\n");
        getch();
        mainmenu();
        return 0;
    }
    a.id=t;

    printf("Book Name:\n");
    scanf("%s",a.name);

    printf("Author:\n");
    scanf("%s",a.Author);

    printf("Quantity:\n");
    scanf("%d",&a.quantity);

    printf("Price:\n");
    scanf("%f",&a.Price);


    return 1;
}
int checkid(int t)
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    if(a.id==t)
    return 0;
      return 1;
}


void Password()
{

   system("cls");

   char ch,pass[10];
   int i=0,j;
   system("COLOR 08");

   printf("###************Protected Password****************###\n");
   printf("\t    ========================");



   printf("\nEnter Password:\t");

   while(ch!=13)
   {
    ch=getch();

    if(ch!=13 && ch!=8)
    {
    putchar('*');
    pass[i] = ch;
    i++;
    }
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {

    printf("\nPassword match\n");

    printf("Press any key to countinue.....");
    getch();
    mainmenu();
   }
   else
   {

     printf("\aWarning!! Incorrect Password");
     getch();
     Password();
   }
}
