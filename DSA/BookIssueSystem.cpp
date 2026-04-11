#include <iostream>
using namespace std;

class book
{
private:
    int bookId;
    string title;
    string author;
    bool isIssued;

public:
    void input(int bookId, string title, string author)
    {
        this->bookId = bookId;
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }

    void display()
    {
        cout << "-------Book Details-------" << endl;
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Issue Status: " << ((isIssued) ? "Issued" : "Available") << endl;
    }

    void issueBook()
    {
        if (isIssued)
            cout << "Book already Issued." << endl;
        else
        {
            isIssued = true;
            cout << "Book Issue Soccessful." << endl;
        }
    }

    void returnBook()
    {
        isIssued = false;
        cout << "Book return Successful." << endl;
    }
};

class user
{
private:
    int userId;
    string name;

public:
    void input(int userId, string name)
    {
        this->userId = userId;
        this->name = name;
    }

    void display()
    {
        cout << "-------User Details-------" << endl;
        cout << "User ID: " << userId << endl;
        cout << "User Name: " << name << endl;
    }

};

void Menu()
{
    cout << "----- M E N U -----" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Add User" << endl;
    cout << "3. Issue Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Display Books" << endl;
    cout << "6. Display Users" << endl;
    cout << "7. EXIT" << endl;
}

int main()
{
    int userInput, bookCount=0 , userCount=0 ;

    user user[5];
    book book[5];

    cout << "-----Book Issuing System------" << endl;
    do
    {
        cout << endl;
        Menu();

        cout << "\nEnter a no. to choose from MENU:";
        cin >> userInput;

        if (userInput < 1 && userInput > 7)
        {
            while (userInput < 1 && userInput > 7)
            {
                cout << "Invalid Choice (Enter a no. between 1-7)" << endl;
                cin >> userInput;
            }
        }
        else
        {
            switch (userInput)
            {
            case 1:{
                if(bookCount <=5 ){
                int bookId;
                string title, author;
                cout << "Enter book Id, Title, Author : " ;
                cin >> bookId >> title >> author;
 
                book[bookCount].input(bookId, title, author);
                cout << "Book Added Successfully." << endl;
                bookCount++;
                }
                else cout << "Maximum Book Creation Limit Reached." << endl;
                break;
            }   
                
            case 2:{
                if(userCount <=5 ){
                int id;
                string name;
                cout << "Enter user id: " ;
                cin >> id;
                cout << "Enter user name: " ;
                cin >> name;

                user[userCount].input(id, name);
                cout << "User Added Successfully." << endl;
                userCount++;
                }
                else cout << "Maximum User Creation Limit Reached." << endl;
                break;
            }   

            case 3:{
                int bookId;
                cout << "Enter Book Id: " ;
                cin >> bookId;
                book[bookId].issueBook();
                cout << "Book Issued Successfully." << endl;
                break;
            }
                
            case 4:{
                int bookId;
                cout << "Enter Book Id: " ;
                cin >> bookId;
                book[bookId].returnBook();
                cout << "Book Returned Successfully." << endl;
                break;
            }

            case 5:
                for(int i=0 ; i<bookCount ; i++){
                    book[i].display();
                }
                break;

            case 6:
                for(int i=0 ; i<userCount ; i++){
                    user[i].display();
                }
                break;

            default:
                userInput = 7;
                break;
            }
        }

    } while (userInput != 7);
    return 0;
}
