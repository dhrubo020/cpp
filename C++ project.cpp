#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

bool login()
{
char usrnm[6];
 cout<<"\t\t\tUsername : ";
cin>>usrnm;
 cout<<"\n\t\t\tPassword : ";

int c=0;
char pass[5];
char r[6] = "admin";
 int p;
 for (int i=0;i<6;i++)
 {
  pass[i] = getch();
  if(pass[i] == 127 || pass[i] == 8)
  {
        i--;
        continue;
  }
  cout<<"*";
 }
 for (int j=0;j<5;j++)
  {
    if (pass[j] == r[j])
    c = c+1;
  }
if (c == 5){
    cout<<"You are Logged in";
return true;
}
else{
            return false;
}
}

int main()
{
      cout<<"\n\n\t\t~~~~~~~~~~~~~~~~~    Welcome to BU CSE Data Center    ~~~~~~~~~~~~~~~~\n";
      cout<<"\n\n\nPlease Log in to enter .......\n\n\n";
      if(login())
      {
    FILE *fp, *ft;
    char another, choice;

    struct student
    {
        char first_name[50], last_name[50];
        char roll[100];
        int section;
    };


    struct student e;
    char xfirst_name[50], xlast_name[50];
    long int recsize;

    fp=fopen("users.txt","rb+");

    if (fp == NULL)
    {
        fp = fopen("users.txt","wb+");

        if (fp==NULL)
        {
            puts("Cannot open file");
            return 0;
        }
    }


    recsize = sizeof(e);

    while(1)
    {
        system("cls");

        cout << "\n\n\t\t===================  STUDENT DATABASE  ====================";
        cout <<"\n\n                                          ";
        cout << "\n\n";
        cout << "\n \t\t\t 1. Add  New";
        cout << "\n \t\t\t 2. List ";
        cout << "\n \t\t\t 3. Search ( by name )";
        cout << "\n \t\t\t 4. Search ( by roll )";
        cout << "\n \t\t\t 5. Delete";
        cout << "\n \t\t\t 6. Log out";
        cout << "\n \t\t\t 7. Exit  Program";
        cout << "\n\n";
        cout << "\t\t\t Select Your Choice :=> ";
        fflush(stdin);
        choice = getche();
        switch(choice)
        {
        case '1' :
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "Enter the Firt Name : ";
                cin >> e.first_name;
                cout << "Enter the Last Name : ";
                cin >> e.last_name;
                cout << "Enter the roll : ";
                cin >> e.roll;
                cout << "Enter the Batch : ";
                cin >> e.section;
                fwrite(&e,recsize,1,fp);
                cout << "\n New data is successfully added..!! ";
                cout << "\n\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
        case '2':
            system("cls");
            rewind(fp);
            cout << "\n\n\t\t==========  View the Records in the Database  ==========";
            cout << "\n";
            while (fread(&e,recsize,1,fp) == 1)
            {
                cout << "\n";
                cout <<"\n\tName : " << e.first_name << " "<< e.last_name;
                cout <<"\n\tRoll : " <<e.roll;
                cout << "\n\tBatch : "<< e.section;
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the first name of the student : ";
                cin >> xfirst_name;
                  bool f=false;
                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)
                  {
                        //cout<<xfirst_name <<" "<<e.first_name<<endl;
                        if (strcmp(xfirst_name , e.first_name ) == 0){
                            cout << "\n";
                            cout <<"\nName : " << e.first_name << " "<< e.last_name;
                            cout <<"\nRoll : " <<e.roll;
                            cout << "\nBatch : "<< e.section;
                            f=true;
                        }
                  }
                    if(f==false)
                        cout<<"\nNot found";
                cout << "\n\n Search Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;

            case '4' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the roll of the student : ";
                char ROLL[10];
                cin >> ROLL;
                  bool f=false;
                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)
                  {
                        //cout<<xfirst_name <<" "<<e.first_name<<endl;
                        if (strcmp(ROLL,e.roll) == 0){
                            cout << "\n";
                            cout <<"\nName : " << e.first_name << " "<< e.last_name;
                            cout <<"\nRoll : " <<e.roll;
                            cout << "\nBatch : "<< e.section;
                            f=true;
                        }
                  }
                    if(f==false)
                        cout<<"record not found";
                cout << "\n\n Search Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;

        case '5':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the first name of the student to delete : ";
                cin >> xfirst_name;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread (&e, recsize,1,fp) == 1)

                    if (strcmp(xfirst_name, e.first_name) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");

                fp=fopen("users.txt","rb+");
                  cout << "\n Data deleted successfully...!! ";
                cout << "\n\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }

            break;

        case '6':
              system("cls");
              main();
            break;

        case '7':
            fclose(fp);
            cout << "\n\n";
            cout << "\n\t\t\t\t THANK YOU";
            cout << "\n\n";
            exit(0);
        }
    }

    system("pause");
      }
      else{
            cout<<"\nInvalid username or password.\n";
            cout<<"\nPress (Y/y) to log in again  or  (N/n) to terminate.\n";
            char c;
            cin>>c;
            if(c=='Y' || c=='y'){
                  system("cls");
                  main();
            }
            else
                  return 0;
      }
    return 0;
}

