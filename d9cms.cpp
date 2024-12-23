
// DSPS assignment No. 9

/*  Implement c++ program for Charity Management system about donor name , their donation and address using linked list.
       - Accept the above record.
       - Display the record.
       - Search the particular record.
       - Modify the particular record.
       - Remove / Delete the particular record.		  */

#include <iostream>
#include <string>
using namespace std;

class CMS 
{
    int amt;
    string name, add;
    CMS* next;

public:
    static CMS* start;

    // Constructor
    CMS() : amt(0), name(""), add(""), next(NULL) {}

    // Member functions
    void accept();
    void display();
    void search();
    void modify();

    void remove();
};

// Initialize static member
CMS* CMS::start = NULL;

// Accept a new donor record
void CMS::accept() 
{
    CMS* nnode = new CMS;
    CMS* temp;

    cout << "\nEnter the Name: ";
    cin >> nnode->name;

    cout << "Enter the Address: ";
    cin >> nnode->add;

    cout << "Enter the Donation Amount: ";
    cin >> nnode->amt;

    nnode->next = NULL;

    if (start == NULL) 
    {
        start = nnode;
    } 
    else 
    {
        temp = start;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = nnode;
    }
    cout << "\nRecord added successfully.";
}

// Display all records
void CMS::display() 
{
    CMS* temp = start;
    int count = 0;

    if (temp == NULL) 
    {
        cout << "\nNo record available.";
        return;
    }

    cout << "\nName\tAddress\t\tDonation";
    while (temp != NULL) 
    {
        count++;
        cout << "\n" << temp->name << "\t" << temp->add << "\t\t" << temp->amt;
        temp = temp->next;
    }
    cout << "\n\nTotal Records: " << count;
}

// Search for a record by name
void CMS::search() 
{
    string searchName;
    CMS* temp = start;
    bool found = false;

    cout << "\nEnter the Name to Search: ";
    cin >> searchName;

    while (temp != NULL) 
    {
        if (temp->name == searchName) 
        {
            found = true;
            cout << "\nRecord Found:\n";
            cout << "Name: " << temp->name << "\nAddress: " << temp->add << "\nDonation: " << temp->amt << endl;
            break;
        }
        temp = temp->next;
    }

    if (!found) 
    {
        cout << "\nRecord not found.";
    }
}

// Modify a record by name
void CMS::modify() 
{
    string modifyName;
    CMS* temp = start;
    bool found = false;

    cout << "\nEnter the Name to Modify: ";
    cin >> modifyName;

    while (temp != NULL) 
    {
        if (temp->name == modifyName) 
        {
            found = true;
            cout << "\nCurrent Record:\n";
            cout << "Name: " << temp->name << "\nAddress: " << temp->add << "\nDonation: " << temp->amt << endl;

            cout << "\nEnter New Address: ";
            cin >> temp->add;
            cout << "Enter New Donation Amount: ";
            cin >> temp->amt;

            cout << "\nRecord Modified Successfully.";
            break;
        }
        temp = temp->next;
    }

    if (!found) 
    {
        cout << "\nRecord not found.";
    }
}

// Remove a record by name
void CMS::remove() 
{
    string removeName;
    CMS* temp = start;
    CMS* prev = NULL;
    bool found = false;

    cout << "\nEnter the Name to Remove: ";
    cin >> removeName;

    while (temp != NULL) 
    {
        if (temp->name == removeName) 
        {
            found = true;
            if (temp == start) 
            {
                start = temp->next;
            } 
            else 
            {
                prev->next = temp->next;
            }
            delete temp;
            cout << "\nRecord Removed Successfully.";
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found) 
    {
        cout << "\nRecord not found.";
    }
}

int main() 
{
    CMS cms;
    int choice;

    while (true) 
    {
        cout << "\n\nMenu:";
        cout << "\n1. Accept Record";
        cout << "\n2. Display Records";
        cout << "\n3. Search Record";
        cout << "\n4. Modify Record";
        cout << "\n5. Remove Record";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cms.accept();
            break;
        case 2:
            cms.display();
            break;
        case 3:
            cms.search();
            break;
        case 4:
            cms.modify();
            break;
        case 5:
            cms.remove();
            break;
        case 6:
            cout << "\nExiting Program.";
            return 0;
        default:
            cout << "\nInvalid Choice. Try Again.";
        }
    }

    return 0;
}
