#include <iostream>
#include <vector>
using namespace std;

class Book
{
public:
  int id;
  string title;
  bool isIssued;
  int dueDays;

  Book(int i, string t)
  {
    id = i;
    title = t;
    isIssued = false;
    dueDays = 0;
  }
};

class Library
{
  vector<Book> books;

public:
  void addBook(int id, string title)
  {
    books.push_back(Book(id, title));
    cout << "Book Added Successfully\n";
  }

  void displayBooks()
  {
    for (auto &b : books)
    {
      cout << "ID: " << b.id
           << ", Title: " << b.title
           << ", Issued: " << (b.isIssued ? "Yes" : "No");

      if (b.isIssued)
        cout << ", Due in: " << b.dueDays << " days";

      cout << endl;
    }
  }

  void issueBook(int id, int days)
  {
    for (auto &b : books)
    {
      if (b.id == id)
      {
        if (!b.isIssued)
        {
          b.isIssued = true;
          b.dueDays = days;
          cout << "Book Issued\n";
        }
        else
        {
          cout << "Already Issued\n";
        }
        return;
      }
    }
    cout << "Book Not Found\n";
  }

  void returnBook(int id)
  {
    for (auto &b : books)
    {
      if (b.id == id)
      {
        if (b.isIssued)
        {
          b.isIssued = false;
          b.dueDays = 0;
          cout << "Book Returned\n";
        }
        else
        {
          cout << "Book was not issued\n";
        }
        return;
      }
    }
    cout << "Book Not Found\n";
  }
};

int main()
{
  Library lib;
  int choice;

  while (true)
  {
    cout << "\n1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n5. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
      int id;
      string title;
      cout << "Enter ID and Title: ";
      cin >> id >> title;
      lib.addBook(id, title);
    }
    else if (choice == 2)
    {
      lib.displayBooks();
    }
    else if (choice == 3)
    {
      int id, days;
      cout << "Enter Book ID and Due Days: ";
      cin >> id >> days;
      lib.issueBook(id, days);
    }
    else if (choice == 4)
    {
      int id;
      cout << "Enter Book ID: ";
      cin >> id;
      lib.returnBook(id);
    }
    else if (choice == 5)
    {
      break;
    }
  }

  return 0;
}