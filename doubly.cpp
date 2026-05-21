#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class NODED
{
public:
    NODED *PREV;
    string ID;
    string UNAME;
    string Instagram ;
    NODED *NEXT;
    NODED(string x, string y, string z)
    {
        PREV = nullptr;
        ID = x;
        UNAME = y;
        Instagram  = z;
        NEXT = nullptr;
    }
};
class DLinkList
{
public:
    string instragramid;
    int ICNT;
    string UName, UInstagram ;
    NODED *START,*END;
    int countNode;
    DLinkList(){
        ICNT = 1001;
        countNode = 0;
        START = nullptr;
        END = nullptr;
    }
    void getPost()
    {
        instragramid = "Instagram Post"+ to_string(ICNT);
        cout<<"\nEnter Instragram Post id -- "<<instragramid<<endl;
        //getline(cin,instragramid);
        cout<<"Enter Username -- ";
        //cin.ignore();
        getline(cin,UName);
        cout<<"Enter Post Caption -- ";
        getline(cin,UInstagram );
    }
    char continueCheck()
    {
        char c;
        cout<<"\n\nAre you.. \n";
        cout<<"1. Continue with Same\n";
        cout<<"2. Go to Main Previous Menu\n";
        cout<<"3. Go to Main Menu..\n";
        cout<<"4. Exit\n";
        c = getch();
        if ( c == '4'){
            thanksLine();
            exit(0);
        }else{
            return (c);
        }
    }
    int insertNode(int opr)
    {
        system("cls");
        if ( opr == 1){
            cout<<"\n\nInsert At Beginning . \n\n";
            getPost();
            NODED *TEMP = new NODED(instragramid,UName, UInstagram);
            if ( TEMP == nullptr){
                cout<<"Insufficient Memory.. \n";
                return 0;
            }
            if ( START == nullptr){
                END = START = TEMP;
            }
            else{
                TEMP->NEXT = START;
                START->PREV = TEMP;
                START = TEMP;
            }
            cout<<END->UNAME;
            countNode++;
            ICNT++;
        }
        else if ( opr == 2){
            cout<<"\n\nInsert At End . \n\n";
            getPost();
            NODED *TEMP = new NODED(instragramid,UName, UInstagram );
            if ( TEMP == nullptr){
                cout<<"Insufficient Memory.. \n";
                return 0;
            }
            if ( START == nullptr){
                END = START = TEMP;
            }
            else{
                END->NEXT = TEMP;
                TEMP->PREV = END;
                END = TEMP;
            }
            countNode++;
            ICNT++;
        }
        else if ( opr == 3){
            cout<<"\n\nInsert At Given Position . \n\n";
            cout<<"Total Post -- "<<countNode<<"\n\n";
            int pos;
            getPost();
            cout<<"Enter Position Between 0 to "<<countNode<<" -- ";
            cin>>pos;

            NODED *TEMP = new NODED(instragramid,UName, UInstagram);
            if ( TEMP == nullptr){
                cout<<"Insufficient Memory.. \n";
                return 0;
            }
            int i;
            NODED *TEMP1 = START;
            for ( i = 2 ; i < pos ; i++){
                TEMP1 = TEMP1->NEXT;
            }
            if ( START == nullptr){
                END = START = TEMP;
            }
            else{

                TEMP->NEXT = TEMP1->NEXT;
                TEMP1->NEXT = TEMP;
                TEMP->PREV = TEMP1;
                TEMP->NEXT->PREV=TEMP;
                if ( TEMP1 == END){
                    END = TEMP1->NEXT;
                }
            }
            countNode++;
            ICNT++;
        }
        char c = continueCheck();
        if (c == '1')
            insertNode(opr);
        else if ( c == '2')
            insertionOperation();
        else if ( c == '3')
            MainMenu();
    }
    int showNode()
    {
        cout<<"\n\nDoubly Link List Show Post -- \n\n";
        cout<<"* Head -> ";
        if ( START == nullptr){
            cout<<"null \n\nlist is empty\n";
            return 0;
        }
        cout<<"\n\n1.Show  Forward Post ..\n";
        cout<<"2.  Show Backward Post\n";
        cout<<"3. Goto to Main Menu..\n";
        cout<<"4. Exit\n";
        char c = getch();
        if ( c == '1'){
            cout<<"\n\nShow  Forward Post \n\n";
            cout<<"null <- ";
            NODED *TEMP = START;
            while ( TEMP!= nullptr){
                cout<<"["<<TEMP->ID<<", ";
                cout<<TEMP->UNAME<<", ";
                cout<<TEMP->Instagram<<"] -> ";
                TEMP = TEMP->NEXT;
            }
            cout<<"Null\n\n";
        }
        else if ( c == '2'){
            cout<<"\n\nShow Backward Post\n\n";
            cout<<"null <- ";
            NODED *TEMP = END;
            while ( TEMP!= nullptr){
                cout<<"["<<TEMP->ID<<", ";
                cout<<TEMP->UNAME<<", ";
                cout<<TEMP->Instagram <<"] -> ";
                TEMP = TEMP->PREV;
            }
            cout<<"Null\n\n";
        }
        else if ( c == '3'){
            MainMenu();
        }
        else if (c == '4'){
            exit(0);
        }

        cout<<"\n\nAre you .. \n";
        cout<<"1. Continue with Same\n";
        cout<<"2. Go to Main Menu..\n";
        cout<<"3. Exit\n";
        c = getch();
        if (c == '1')
            showNode();
        else if ( c == '2')
            MainMenu();
        else if ( c == '3'){
            thanksLine();
            exit(0);
        }

    }
    void countNodes()
    {
        system("cls");
        cout<<"Count Post Module --\n\n";
        cout<<"Total Number of Post -- "<<countNode<<" Post Available\n\n"
;    }
    int insertionOperation()
    {
        system("cls");
        cout<<"\nInsert Instragram Detail..\n\n";
        cout<<"1. Insert Post At Beginning\n";
        cout<<"2. Insert Post At End\n";
        cout<<"3. Insert  After Post\n";
        cout<<"4. Go to Main Menu\n";
        cout<<"5. Exit.\n";
        char c = getch();
        if ( c == '1'){
            insertNode(1);
        }
        else if ( c == '2'){
            insertNode(2);
        }
        else if ( c == '3'){
            insertNode(3);
        }
        else if ( c == '4'){
            MainMenu();
        }
        else if ( c == '5'){
            thanksLine();
            exit(0);
        }
    }

    int deleteNode(int opr)
    {
        NODED *TEMP;
        if ( opr == 1){
            cout<<"\n\nDelete From Beginning . \n\n";
            if ( START == nullptr)
            {
                cout<<"Post is Empty.. \n\n";
                return 0;
            }
            else if ( START->NEXT == nullptr){
                TEMP = START;
                END = START = nullptr;
            }
            else{
                TEMP = START;
                START = START->NEXT;
                START->PREV=nullptr;
            }
            countNode--;
            delete(TEMP);
            cout<<"\nPost Deleted Successfully\n\n";
        }
        else if ( opr == 2){
            cout<<"\n\nDelete From End . \n\n";
            if ( START == nullptr)
            {
                cout<<"Post is Empty.. \n\n";
                return 0;
            }
            else if ( START->NEXT == nullptr){
                TEMP = START;
                END = START = nullptr;
            }
            else{
                NODED *TEMP = END;
                END = END->PREV;
                END->NEXT = nullptr;
                delete(TEMP);
            }
            countNode--;
            cout<<"\nPost Deleted Successfully\n\n";
        }
        else if ( opr == 3){
            cout<<"\n\nDelete From Given Position . \n\n";

            if ( START == nullptr)
            {
                cout<<"Post is Empty.. \n\n";
                return 0;
            }
            int pos;
            cout<<"Enter Position for Delete (1 - "<<countNode<<") - ";
            cin>>pos;
            if ( pos == 1 && START == END)
            {
                TEMP = START;
                START = END = nullptr;
            }
            else{
                TEMP = START;
                for (int i = 1 ; i < pos ; i++)
                {
                    TEMP = TEMP->NEXT;
                }
                if (TEMP == END){
                    TEMP->PREV->NEXT = nullptr;
                    END = TEMP->PREV;
                    delete(TEMP);
                }
                else{
                    TEMP->PREV->NEXT = TEMP->NEXT;
                    TEMP->NEXT->PREV = TEMP->PREV;
                    delete(TEMP);
                }
            }
            countNode--;
            cout<<"\nPost Deleted Successfully\n\n";
        }
        char c = continueCheck();
        if (c == '1')
            deleteNode(opr);
        else if ( c == '2')
            deleteOperation();
        else if ( c == '3')
            MainMenu();
    }
    int deleteOperation()
    {
        system("cls");
        cout<<"\nDeletion Post..\n\n";
        cout<<"1. Delete Post From Beginning\n";
        cout<<"2. Delete Post From End\n";
        cout<<"3. Delete Post From Given Position\n";
        cout<<"4. Go to Main Menu\n";
        cout<<"5. Exit.\n";
        char c = getch();
        if ( c == '1'){
            deleteNode(1);
        }
        else if ( c == '2'){
            deleteNode(2);
        }
        else if ( c == '3'){
            deleteNode(3);
        }
        else if ( c == '4'){
            MainMenu();
        }
        else if ( c == '5'){
            thanksLine();
            exit(0);
        }
    }
    /*search module start*/

    int searchInstagramInNode()
    {
        cout<<"\n\nSearch Instagram Post in Nodes -- \n\n";
        cout<<"* Head -> ";
        NODED *TEMP = START;
        if ( START == nullptr){
            cout<<"null \n\nlist is empty\n";
            return 0;
        }
        else{
            cout<<"\n\nEnter User Name To Find Instagram Posts -- ";
            string uname;
            int counter = 0;
            getline(cin,uname);
            while ( TEMP!= nullptr){
                if (TEMP->UNAME == uname)
                {
                    cout<<"\n["<<TEMP->ID<<", ";
                    cout<<TEMP->UNAME<<", ";
                    cout<<TEMP->Instagram <<"]\n";
                    counter++;
                }
                TEMP = TEMP->NEXT;
            }
            if ( counter == 0){
                cout<<"\nNo Instagram Post Found..\n\n";
            }
        }
        char c;
        cout<<"\n\nAre you .. \n";
        cout<<"1. Continue with Same\n";
        cout<<"2. Go to Main Menu..\n";
        cout<<"3. Exit\n";
        c = getch();
        if (c == '1')
            searchInstagramInNode();
        else if ( c == '2')
            MainMenu();
        else if ( c == '3'){
            thanksLine();
            exit(0);
        }
    }

    /*Search Module End*/
    int MainMenu()
    {
        system("cls");
        cout<<"========== Instragram Post Feed  ==========\n\n";
        cout<<"1. Insert Instragram Post\n";
        cout<<"2. Show Instragram Post\n";
        cout<<"3. Delete Post\n";
        cout<<"4. Search Post\n";
        cout<<"5. Count Post\n";
        cout<<"6. Exit\n";
        cout<<"Choose One of them -- ";
        /*l.insertNode(101,"Pooja","Hello Friends");
        l.insertNode(102,"Niharika","Hello Pooja");
        l.insertNode(103,"Deepak","Hello Tejswi");
        l.showNode();*/
        char c = getch();
        if ( c == '1'){
            insertionOperation();
        }
        else if ( c == '2'){
            showNode();
        }
        else if ( c == '3'){
            deleteOperation();
        }
        else if ( c == '4'){
            searchInstagramInNode();
        }
        else if ( c == '5'){
            countNodes();
        }
        else if ( c == '6'){
            thanksLine();
            exit(0);
        }
        cout<<"\n\nDo you want to continue .. press 1 else any key..";
        c = getch();
        if ( c == '1'){
            MainMenu();
        }
        return 0;
    }
    void thanksLine()
    {
        cout<<"\n\nThanks for Using My APP\n\n";
    }
};

/*int main()
{
   DLinkList l;
   l.MainMenu();
   cout<<"\n\nThanks for using My APP\n\n";
}*/





