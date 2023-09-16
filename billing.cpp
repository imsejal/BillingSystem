
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu()
{
    while (true)
    {
        int choice;
        string email;
        string password;

        cout << "\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t         Supermarket Main Menu            \n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t| 1) Administrator  |\n";
        cout << "\t\t\t\t|                   |\n";
        cout << "\t\t\t\t| 2) Buyer          |\n";
        cout << "\t\t\t\t|                   |\n";
        cout << "\t\t\t\t| 3) Exit           |\n";
        cout << "\t\t\t\t|                   |\n";
        cout << "\n\t\t\t Please select! ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\t\t\t Please Login \n";
            cout << "\t\t\t Enter Email   \n";
            cin >> email;
            cout << "\t\t\t Password       \n";
            cin >> password;
            if (email == "sejal@email.com" && password == "sejal@123")
            {
                administrator();
            }
            else
            {
                cout << "Invalid email/password";
            }
            break;
        case 2:
            buyer();
            break;
        case 3:
            exit(0);
        default:
            cout << "Please select from the given options";
            break;
        }
    }
}

void shopping::administrator()
{
    while (true)
    {
        int choice;
        cout << "\n\n\n\t\t\t Administrator menu";
        cout << "\n\t\t\t|_____ 1) Add the product______|";
        cout << "\n\t\t\t|                              |";
        cout << "\n\t\t\t|_____ 2) Modify the product___|";
        cout << "\n\t\t\t|                              |";
        cout << "\n\t\t\t|_____ 3) Delete the product___|";
        cout << "\n\t\t\t|                              |";
        cout << "\n\t\t\t|_____ 4) Back to main menu____|";
        cout << "\n\t\t\t Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice!";
            break;
        }
    }
}

void shopping::buyer()
{
    while (true)
    {
        int choice;
        cout << "\t\t\t         Buyer  \n";
        cout << "\n\t\t\t|_____ 1) Display all products______|";
        cout << "\n\t\t\t|                                   |";
        cout << "\n\t\t\t|_____ 2) Buy product_______________|";
        cout << "\n\t\t\t|                                   |";
        cout << "\n\t\t\t|_____ 3) Back to main menu________|";
        cout << "\n\t\t\t Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list();
            break;
        case 2:
            receipt();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice!";
            break;
        }
    }
}

void shopping::add()
{
    ofstream outfile;
    outfile.open("product.txt", ios::app);
    cout << "\n\n\t\t\t\t Add the product \n";
    cout << "\t\t\t\t Enter Product Code: ";
    cin >> pcode;
    cout << "\t\t\t\t Enter Product Name: ";
    cin >> pname;
    cout << "\t\t\t\t Enter Price: ";
    cin >> price;
    cout << "\t\t\t\t Enter Discount(%): ";
    cin >> dis;
    outfile << pcode << " " << pname << " " << price << " " << dis << endl;
    outfile.close();
}

void shopping::edit()
{
    int pcode;
    string pname;
    float price;
    float dis;
    string new_pname;
    float new_price;
    float new_dis;
    bool found = false;

    cout << "\n\n\t\t\t\t Modify the product \n";
    cout << "\t\t\t\t Enter the product code to be modified: ";
    cin >> pcode;

    ifstream infile;
    ofstream outfile;
    infile.open("product.txt");
    outfile.open("temp.txt", ios::app);

    while (infile >> pcode >> pname >> price >> dis)
    {
        if (pcode == pcode)
        {
            found = true;
            cout << "\t\t\t\t Enter new product name: ";
            cin >> new_pname;
            cout << "\t\t\t\t Enter new price: ";
            cin >> new_price;
            cout << "\t\t\t\t Enter new discount(%): ";
            cin >> new_dis;
            outfile << pcode << " " << new_pname << " " << new_price << " " << new_dis << endl;
        }
        else
        {
            outfile << pcode << " " << pname << " " << price << " " << dis << endl;
        }
    }
    infile.close();
    outfile.close();

    remove("product.txt");
    rename("temp.txt", "product.txt");

    if (!found)
    {
        cout << "\t\t\t\t Product not found!";
    }
}

void shopping::rem()
{
    int pcode;
    string pname;
    float price;
    float dis;
    int code;
    bool found = false;

    cout << "\n\n\t\t\t\t Delete the product \n";
    cout << "\t\t\t\t Enter the product code to be deleted: ";
    cin >> code;

    ifstream infile;
    ofstream outfile;
    infile.open("product.txt");
    outfile.open("temp.txt", ios::app);

    while (infile >> pcode >> pname >> price >> dis)
    {
        if (pcode != code)
        {
            outfile << pcode << " " << pname << " " << price << " " << dis << endl;
        }
        else
        {
            found = true;
        }
    }
    infile.close();
    outfile.close();

    remove("product.txt");
    rename("temp.txt", "product.txt");

    if (!found)
    {
        cout << "\t\t\t\t Product not found!";
    }
}

void shopping::list()
{
    int pcode;
    string pname;
    float price;
    float dis;

    ifstream infile;
    infile.open("product.txt");

    cout << "\n\n\t\t\t\t Product List \n";
    cout << "\t\t\t\t____________________\n";
    cout << "\t\t\t\t|  Code  |   Name   |\n";
    cout << "\t\t\t\t|--------|----------|\n";

    while (infile >> pcode >> pname >> price >> dis)
    {
        cout << "\t\t\t\t|   " << pcode << "   |  " << pname << "   |\n";
    }

    infile.close();
}

void shopping::receipt()
{
    int pcode;
    string pname;
    float price;
    float dis;
    int code;
    int quantity;
    float total = 0;

    cout << "\n\n\t\t\t\t Buy product \n";
    cout << "\t\t\t\t Enter the product code to buy: ";
    cin >> code;
    cout << "\t\t\t\t Enter the quantity: ";
    cin >> quantity;

    ifstream infile;
    infile.open("product.txt");

    while (infile >> pcode >> pname >> price >> dis)
    {
        if (pcode == code)
        {
            float discounted_price = price - (price * dis / 100);
            total = discounted_price * quantity;
            cout << "\t\t\t\t Product: " << pname << endl;
            cout << "\t\t\t\t Price: " << price << endl;
            cout << "\t\t\t\t Discount: " << dis << "%" << endl;
            cout << "\t\t\t\t Quantity: " << quantity << endl;
            cout << "\t\t\t\t Total: " << total << endl;
            break;
        }
    }

    infile.close();
}

int main()
{
    shopping obj;
    obj.menu();
    return 0;
}
