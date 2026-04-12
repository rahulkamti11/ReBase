#include <iostream>
using namespace std;

class BOOK{
public:   
    int bookId;
    string title;
    string author;
    bool isIssued;

    void input(int bookId, string title, string author){
        this->bookId = bookId;
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }

    void display(){
        cout << "-------Book Details-------" << endl;
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Issue Status: " << (isIssued ? "Issued" : "Available") << endl;
    }

    void issueBook(){
        if (isIssued)
            cout << "Book already Issued." << endl;
        else
        {
            isIssued = true;
            cout << "Book Issue Successful." << endl;
        }
    }

    void returnBook(){
        isIssued = false;
        cout << "Book return Successful." << endl;
    }
};

class USER{
public:   
    int userId;
    string name;
    BOOK* issuedBook;

    void input(int userId, string name){
        this->userId = userId;
        this->name = name;
        issuedBook = NULL;
    }

    void display(){
        cout << "-------User Details-------" << endl;
        cout << "User ID: " << userId << endl;
        cout << "User Name: " << name << endl;

        if (issuedBook)
            cout << "Book Issued: YES" << endl;
        else
            cout << "Book Issued: NO" << endl;
    }

    void borrowBook(BOOK* b){
        issuedBook = b;
    }

    void returnBook(){
        issuedBook = NULL;
    }
};

void Menu(){
    cout << "----- M E N U -----" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Add User" << endl;
    cout << "3. Issue Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Display Books" << endl;
    cout << "6. Display Users" << endl;
    cout << "7. EXIT" << endl;
}

void userChoice(int userInput, int &bookCount , int &userCount , BOOK bookArr[], USER userArr[])
{
    switch (userInput){
    //---ADD BOOK---
    case 1:{   
        if(bookCount < 10){
            int bookId;
            string title, author;
            cout << "Enter book Id, Title, Author : ";
            cin >> bookId >> title >> author;

            bookArr[bookCount].input(bookId, title, author);
            cout << "Book Added Successfully." << endl;
            bookCount++;
        }
        else cout << "Maximum Book Creation Limit Reached." << endl;
        break;
    }

    //---ADD USER---
    case 2:{    
        if(userCount < 10){
            int id;
            string name;
            cout << "Enter user id: ";
            cin >> id;
            cout << "Enter user name: ";
            cin >> name;

            userArr[userCount].input(id, name);
            cout << "User Added Successfully." << endl;
            userCount++;
        }
        else cout << "Maximum User Creation Limit Reached." << endl;
        break;
    }

    //---ISSUE BOOK---
    case 3:{    
        int uid, bid;
        cout << "Enter User ID and Book ID: ";
        cin >> uid >> bid;

        for(int i = 0; i < userCount; i++){
            if(userArr[i].userId == uid){

                if(userArr[i].issuedBook != NULL){
                    cout << "User already has a book." << endl;
                    return;
                }

                for(int j = 0; j < bookCount; j++){
                    if(bookArr[j].bookId == bid){

                        if(bookArr[j].isIssued){
                            cout << "Book already issued." << endl;
                            return;
                        }

                        userArr[i].borrowBook(&bookArr[j]);
                        bookArr[j].issueBook();

                        cout << "Book Issued Successfully." << endl;
                        return;
                    }
                }
            }
        }

        cout << "User or Book not found." << endl;
        break;
    }

    //---Return Book---
    case 4:{   
        int uid;
        cout << "Enter User ID: ";
        cin >> uid;

        for(int i = 0; i < userCount; i++){
            if(userArr[i].userId == uid){

                if(userArr[i].issuedBook == NULL){
                    cout << "User has no book." << endl;
                    return;
                }

                BOOK* b = userArr[i].issuedBook;
                b->returnBook();
                userArr[i].returnBook();

                cout << "Book Returned Successfully." << endl;
                return;
            }
        }

        cout << "User not found." << endl;
        break;
    }

    //---Display Books---
    case 5:
        for(int i=0 ; i<bookCount ; i++){
            bookArr[i].display();
        }
        break;

    //---Display Users---
    case 6:
        for(int i=0 ; i<userCount ; i++){
            userArr[i].display();
        }
        break;

    // Default to EXIT
    default:
        userInput = 7;
        break;
    }
}

int main(){

    int userInput, bookCount=0 , userCount=0;

    USER user[10];
    BOOK book[10];

    cout << "-----Book Issuing System------" << endl;

    do{
        cout << endl;
        Menu();   //Display MENU

        cout << "\nEnter a no. to choose from MENU:";
        cin >> userInput;

        if (userInput < 1 || userInput > 7){
            cout << "Invalid Choice (Enter 1-7)" << endl;
        }
        else{   
            userChoice(userInput, bookCount, userCount, book, user);
        }

    } while (userInput != 7);

    return 0;
}
