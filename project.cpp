#include <iostream>
// #include<windows.h> //library for window
#include <unistd.h> //library for Linux
using namespace std;
class node
{
private:
    string friend_name;
    node *address;

public:
    void create_head();
    void desired();
    void insert(int);              // insert specific position
    void delete_name(string name); // delete specific position
    void show_data();              // show data
};
node *head = NULL;
void node::desired()
{
    // veriable use in this function
    int gu = 1, d;
    node *p1;
    p1 = head;

    //...............................................................
    // making node
    node *update = new node; // update is new memory
    // A node make in this area
    cout << "enter friend name" << endl;
    cin >> update->friend_name;
    update->address = NULL;
    // A node make in this area
    //...............................................................
    // give the position
    cout << "Select Which Positon you want to Insert Data" << endl;
    cin >> d;
    // give the position
    //...............................................................
    // the main code of updating the value in desired position
    if (d == 1)
    {
        update->address = head;
        head = update;
    }
    else
    {
        while (gu < d - 1)
        {
            p1 = p1->address;
            gu++;
        }
        update->address = p1->address;
        p1->address = update;
    }
}
void node::create_head()
{
    head = new node;
    cout << "TYPE YOUR FIRST FRIEND NAME...";
    cin >> head->friend_name;
    head->address = NULL;
}
void node::insert(int q)
{
    node *next = new node;
    cout << "TYPE YOUR_" << q + 1 << "_FRIEND NAME...";
    cin >> next->friend_name;
    next->address = NULL;
    node *tem;
    tem = head;
    while (tem->address != NULL)
    {
        tem = tem->address;
    }
    tem->address = next;
}
void node::delete_name(string name)
{
    node *temp, *flag;
    if (head->friend_name == name)
    {
        temp = head;
        head = temp->address;
        delete temp;
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            if (temp->friend_name == name)
            {
                flag->address = temp->address;
                delete temp;
                break;
            }
            flag = temp;
            temp = temp->address;
        }
    }
}
void node::show_data()
{
    node *check;
    check = head;
    while (check != NULL)
    {
        cout << "your friend name:--" << check->friend_name << endl;
        check = check->address;
    }
}
int main()
{
    node obj;
    cout << "\n \t \t welcome to ADD DATA GAME \n"
         << endl;
    bool t_f = 1;
    int value, range;
    while (t_f)
    {
        cout << "PRESS 1. FOR INSERT DATA" << endl;
        cout << "PRESS 2. FOR DELETE DATA" << endl;
        cout << "PRESS 3. FOR SHOW DATA" << endl;
        cout << "PRESS 4. FOR INSERT DATA SPECIFIC LOCATION" << endl;
        cout << "PRESS 5. FOR EXIT" << endl;
        cout << "\n \nSelect your Option......";
        cin >> value;
        switch (value)
        {
        case 1:
            // this is case one insert the data
            //  system("CLS"); //for clear the screen
            cout << "---------------------------------------------------" << endl;
            cout << "How many values you have insert in" << endl;
            cin >> range;
            for (int i = 0; i < range; i++)
            {
                if (head == NULL)
                {
                    obj.create_head();
                }
                else
                {
                    obj.insert(i);
                }
            }
            cout << "!--Succefully INSERT your DATA--!" << endl;
            cout << "---------------------------------------------------" << endl;
            break;
        case 2:
            if (head == NULL)
            {
                cout << "your LINKED LIST EMPTY" << endl;
            }
            else
            {
                string vname;
                cout << "enter name which you want delete" << endl;
                cin >> vname;
                obj.delete_name(vname);
                cout << "---------------------------------------------------" << endl;
                cout << "SUCCEFULLY DELETE" << endl;
                cout << "---------------------------------------------------" << endl;
            }
            break;
        case 3:
            if (head == NULL)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "The linked list is empty" << endl;
                cout << "---------------------------------------------------" << endl;
            }
            else
            {
                cout << "---------------------------------------------------" << endl;
                obj.show_data();
                cout << "---------------------------------------------------" << endl;
            }
            break;
        case 4:
            if (head == NULL)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "this linked list EMPTY" << endl;
                cout << "---------------------------------------------------" << endl;
            }
            else
            {
                obj.desired();
                cout << "---------------------------------------------------" << endl;
                cout << "succefully INSERT your Desired LOCATION";
                cout << "---------------------------------------------------" << endl;
            }
            break;
        case 5:
            t_f = 0;
            cout << "---------------------------------------------------" << endl;
            cout << "\t \tthanks for using this Application";
            cout << "---------------------------------------------------" << endl;
            break;
        default:
            cout << "This is the wrong Input" << endl;
            break;
        }
    }

    return 0;
}