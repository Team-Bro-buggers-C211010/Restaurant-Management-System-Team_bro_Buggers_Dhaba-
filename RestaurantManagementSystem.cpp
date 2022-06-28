/*
                        Author: Team_Bro_bugger's

    Member 1: Shovan Bhattacharjee  |  Member 2: Tanveer Alam
          Id: C211010               |        Id: C211040
         Sec: 2AM                   |       Sec: 2AM
_________________________________________________________________________________________________________________________________________
At a glance:
    Restaurant_Menu_Update_Version_6.0!!(Final)
    note: Every food price and amount will be valid.
    1. Owner section :                                                     |  2. Customer Section :
                    i) Show All Menu.                                      |              i) Login
                    ii) Add New Items.                                     |             ii) Sign up (Uniquness of customer id)
                    iii) Edit Existing Items. (Special-> Delete an item)   |            iii) Customer Order
                    iv)  Change owner Password.                            |             iv) Keeping Ordered list in a file
                    v) Show All Customer.                                  |             v) Showing net bill ,
                    vi) Delete A Customer data.                            |                with a discount (Promo applied with message)
                    vii) Show All Registered Owner.                        |                with out a discount(No Promo applied)
                    viii) See All Customer Ordered Data.                   |
                    iX) Show All Promo Code available.                     |
                    x) Add Promo Code or Delete Promo Code.                |
                    xi) Log out.
*/

#include <bits/stdc++.h>
using namespace std;

///Food Class is to control the data of Restaurant Menu.
class Food
{
protected:
    string itemName;
    int itemPrice, itemAvailibility;

public:
    void fileToMenu(string FtoM_name, int FtoM_price, int FtoM_quantity)
    {
        itemName = FtoM_name;
        itemPrice = FtoM_price;
        itemAvailibility = FtoM_quantity;
    }

    void All_Menu()
    {
        cout << "                                                                           ||||||||||||||||||||||||||||||||||\n";
        cout << "                                                                           |Name           : " << itemName;
        cout << "\n                                                                           |Price          : " << itemPrice << " taka";
        cout << "\n                                                                           |Item Available : " << itemAvailibility << "\n";
        cout << "                                                                           ||||||||||||||||||||||||||||||||||\n";
    }

    int countQuantityAvailibility()
    {
        return itemAvailibility;
    }

    void setQuantityAvailibility(int set_Quant)
    {
        itemAvailibility = set_Quant;
    }

    int Set_Bill(int amount_Item)
    {
        return itemPrice * amount_Item;
    }
    void setFile()
    {
        ofstream New_Menu;
        New_Menu.open("restaurant.txt", ios::out | ios::app);
        New_Menu << itemName << "\n"
                 << itemPrice << "\n"
                 << itemAvailibility << "\n";
        New_Menu.close();
    }
};

///Customer class who access food class
class Customer : public Food
{
protected:
    string customer_login_id, customer_name, customer_contact, customer_pass, Order_Date, Order_Item;
    int Order_Quantity, Order_Price;

public:
    void set_customer_details(string customer_login_id, string customer_name, string customer_contact, string customer_pass)
    {
        this->customer_login_id = customer_login_id;
        this->customer_name = customer_name;
        this->customer_contact = customer_contact;
        this->customer_pass = customer_pass;
    }
    void show_customer_details()
    {
        cout << "                                                                       IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
        cout << "                                                                       I            Customer details:           I\n";
        cout << "                                                                       I========================================I\n";
        cout << "                                                                       I Name            : " << customer_name << "\n";
        cout << "                                                                       I Mobile No.      : " << customer_contact << "\n";
        cout << "                                                                       IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
    }
    void select_itemBill(int amount_Item, string date)
    {
        cout << "                                                                           ||||||||||||||||||||||||||||||||||\n";
        cout << "                                                                           |Name           : " << itemName;
        cout << "\n                                                                           |Quantity  : " << amount_Item;
        cout << "\n                                                                           |The Bill  : " << itemPrice * amount_Item << " Taka only.\n";
        cout << "                                                                           ||||||||||||||||||||||||||||||||||\n";

        Order_Item = itemName;
        Order_Quantity = amount_Item;
        Order_Date = date;
        Order_Price = itemPrice * amount_Item;
    }
    string check_customer_id()
    {
        return customer_login_id;
    }
    string check_customer_pass() ///Check the owner Id & pass
    {
        return customer_pass;
    }
    string check_customer_name()
    {
        return customer_name;
    }
    void set_customer_Pass(string str)
    {
        customer_pass = str;
    }
    void set_Customer_File()
    {
        ofstream New_Customer;
        New_Customer.open("Customer.txt", ios::out | ios::app);
        New_Customer << customer_login_id << "\n"
                     << customer_name << "\n"
                     << customer_contact << "\n"
                     << customer_pass << "\n";
        New_Customer.close();
    }
    void set_Customer_Order_File(string customer_login_id, string customer_name)
    {
        ofstream New_Order;
        New_Order.open("OrderdList.txt", ios::out | ios::app);
        New_Order << customer_login_id << "\n"
                  << customer_name << "\n"
                  << Order_Date << "\n"
                  << Order_Item << "\n"
                  << Order_Quantity << "\n"
                  << Order_Price << "\n";
        New_Order.close();
    }
};

///Owner Class who can access whole restaurent management system .
class Owner : public Customer ///Multilevel Inheritence--> Indirectly access food class
{
protected:
    string O_name, O_mobile, O_pass, O_loggin_id;

public:
    void set_O_details(string O_loggin_id, string O_name, string O_mobile, string O_pass) /// set owner data
    {
        this->O_loggin_id = O_loggin_id;
        this->O_name = O_name;
        this->O_mobile = O_mobile;
        this->O_pass = O_pass;
    }
    string check_Owner_Id()
    {
        return O_loggin_id;
    }
    string check_Owner_pass()
    {
        return O_pass;
    }
    void set_Owner_passWord(string str)
    {
        O_pass = str;
    }
    void show_Owner_details()
    {
        cout << "                                                                       ###########################################\n";
        cout << "                                                                       ::            ~~(Owner details)~~     \n";
        cout << "                                                                       :: [Name]          : " << O_name << "           \n";
        cout << "                                                                       :: [Mobile No].    : " << O_mobile << "          \n";
        cout << "                                                                       ###########################################\n";
    }

    void set_Owner_File() /// Updated owner data tranfer in Owner.txt file
    {
        ofstream New_Owner;
        New_Owner.open("Owner.txt", ios::out | ios::app);
        New_Owner << O_loggin_id << "\n"
                  << O_name << "\n"
                  << O_mobile << "\n"
                  << O_pass << "\n";
        New_Owner.close();
    }

    /// using Edit funtion to edit my menu information
    void EditFull_Items(string N_name, int N_price, int N_amount)
    {
        itemName = N_name;
        itemPrice = N_price;
        itemAvailibility = N_amount;
    }

    void Edit_Name(string N_name)
    {
        itemName = N_name;
    }

    void Edit_Price(int N_price)
    {
        itemPrice = N_price;
    }

    void Edit_Amount(int N_amount)
    {
        itemAvailibility = N_amount;
    }
    void show_all_customer_toAnOwner()
    {
        cout << "                                                                           ++++++++++++++++++++++++++++++++++\n";
        cout << "                                                                           |Customer Id         : " << customer_login_id;
        cout << "\n                                                                           |Customer Name       : " << customer_name;
        cout << "\n                                                                           |Customer Mobile No. : " << customer_contact << "\n";
        cout << "                                                                           ++++++++++++++++++++++++++++++++++\n";
    }
};

void set_Promo_Code(string Promo_Date, string Promo_Code, string Promo_Message) /// Promo code information added in Promo_Code_list.txt file
{
    ofstream New_Promo;
    New_Promo.open("Promo_Code_List.txt", ios::out | ios::app);
    New_Promo << Promo_Date << "\n"
              << Promo_Code << "\n"
              << Promo_Message << "\n";
    New_Promo.close();
}

void Net_Bill(int bill) /// total bill funtion
{
    cout << "                                                                | Your Net Bill: " << bill << " Taka only.                         |\n";
    cout << "                                                                | Thank's for your order!                                |\n";
    cout << "                                                                | Hope you enjoyed your meal!!!                          |\n";
    cout << "                                                                |--------------------------------------------------------|\n";
    cout << "                                                                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "                                                                @---People who loves to eat are always the best people---@\n";
    cout << "                                                                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
}

Owner add_Menu[50], add_Owner[100], Customer[200];
int count_Owner = 0, count_Customer = 0, line = 1, line1 = 1, line2 = 1, Count_Menu = 0;

void All_data_file_to_object() /// here all information of (1.Owner, 2.Customer, 3.restaurant) are added in their Object from their file
{

    /// Ownerer data-- File to Object
    ifstream New_Owner;
    New_Owner.open("Owner.txt", ios::out | ios::app);
    string O_string, test_loggin_id, test_Oname, test_Omobile, test_Opass;
    while (getline(New_Owner, O_string))
    {
        if (line == 1)
            test_loggin_id = O_string;
        else if (line == 2)
            test_Oname = O_string;
        else if (line == 3)
            test_Omobile = O_string;
        else if (line == 4)
        {
            test_Opass = O_string;
            count_Owner++;
            add_Owner[count_Owner].set_O_details(test_loggin_id, test_Oname, test_Omobile, test_Opass);
            line = 0;
        }
        line++;
    }
    New_Owner.close();

    /// Customer data-- File to Object
    ifstream New_Customer;
    New_Customer.open("Customer.txt", ios::out | ios::app);
    string Output_string, test_customer_loggin_id, test_customer_name, test_customer_mobile, test_customer_pass;
    while (getline(New_Customer, Output_string))
    {
        if (line1 == 1)
            test_customer_loggin_id = Output_string;
        else if (line1 == 2)
            test_customer_name = Output_string;
        else if (line1 == 3)
            test_customer_mobile = Output_string;
        else if (line1 == 4)
        {
            test_customer_pass = Output_string;
            count_Customer++;
            Customer[count_Customer].set_customer_details(test_customer_loggin_id, test_customer_name, test_customer_mobile, test_customer_pass);
            line1 = 0;
        }
        line1++;
    }
    New_Owner.close();

    /// Restaurant data-- File to Object
    ifstream New_Menu;
    New_Menu.open("restaurant.txt", ios::out | ios::app);
    string testString, testName, testPrice, testAmount;
    while (getline(New_Menu, testString))
    {
        if (line2 == 1)
            testName = testString;
        else if (line2 == 2)
            testPrice = testString;
        else if (line2 == 3)
        {
            Count_Menu++;
            testAmount = testString;
            add_Menu[Count_Menu].fileToMenu(testName, stoi(testPrice), stoi(testAmount));
            line2 = 0;
        }
        line2++;
    }
    New_Menu.close();
}
void Show_Menu() /// Menu funtion
{
    cout << "\n                                                                         **|__Showing whole existing menu:__|**\n\n";
    for (int j = 1; j <= Count_Menu; j++)
    {
        cout << "                                                                                          Dish " << j << "\n";
        add_Menu[j].All_Menu();
        cout << "\n";
    }
}

int main()
{
    string main_pass = "CPP2AM"; /// First verification password

    All_data_file_to_object();

    int select1, select2, select3, select4, quantity, testQuantity, set;
    int Owner_Iterator;
    string menuName, menuPrice, menuAmount;

    cout << "\t\t\t\t\t\t\t**|";
    for (int i = 0; i < 12; i++)
        cout << "__";
    cout << "Restaurant Interface";
    for (int i = 0; i < 12; i++)
        cout << "__";
    cout << "|**\n\n"; /// design the console

    /// Here Owner work start.

find:

    cout << "                                                                 ________________________________________________________ \n";
    cout << "                                                                |********************************************************|\n";
    cout << "                                                                |----------****** The_Bro_bugger's Dhaba ******----------|\n";
    cout << "                                                                |________________________________________________________|\n\n\n";

    cout << "                                                                      _____________________________________________\n";
    cout << "                                                                      ||......  Are you Owner or Customer: ......||\n";
    int select_Identity, breakdown = 0;
    while (1)
    {
        cout << "                                                                      ||_________________________________________||\n";
        cout << "                                                                      ||          [1]. Owner Login.              ||\n";
        cout << "                                                                      ||          [2]. Customer Login.           ||\n";
        cout << "                                                                      ||          [3]. Exit.                     ||\n";
        cout << "                                                                      ||_________________________________________||\n";
        cout << "\n                                                                      [Select your choice]:=>  ";
        cin >> select_Identity;
        if (select_Identity == 1) ///Owner Login
        {
            string pass1, O_loggin_id, O_name, O_mobile, O_pass;
            cout << "\n\n                                                                ========================================================\n";
            cout << "                                                               |     Enter the pass for first step verification         |\n";
            cout << "                                                               |     which is given by main Owner:                      |\n";
            cout << "                                                                     Password : ";
            cin >> pass1;
            cout << "                                                               |========================================================|\n";
            if (pass1 == main_pass) /// first verification pass matched & owner can be access
            {
                cout << "\n\n                                                               #########################################################\n";
                cout << "                                                               |                      OWNER SECTION                    |\n";
                cout << "                                                               #########################################################\n";
                cout << "                                                                           //////////////////////////////////\n";
                cout << "                                                                           |          Welcome Sir!!!        |\n";
                cout << "                                                                           |   Please enter your details:   |\n";
                cout << "                                                                           |                                |\n";
                cout << "                                                                           | [1]    Already exist:          |\n";
                cout << "                                                                           | [2]    New Owner:              |\n";
                cout << "                                                                           |                                |\n";
                cout << "                                                                           //////////////////////////////////\n";
                int select_Ownertypes;
                cout << "\n\n                                                                       [Select]:=> ";
                cin >> select_Ownertypes;

                if (select_Ownertypes == 1) ///Existing Owner
                {
                    cout << "\n\n                                                                           ||||||||||||||||||||||||||||||||||\n";
                    cout << "                                                                              >> Enter login id       : ";
                    cin >> O_loggin_id;
                    for (int i = 1; i <= count_Owner; i++)
                    {
                        if (add_Owner[i].check_Owner_Id() == O_loggin_id) ///Check existing owner id
                        {
                            cout << "                                                                              >> Enter your password  : ";
                            cin >> O_pass;
                            cout << "                                                                           ||||||||||||||||||||||||||||||||||\n";
                            if (O_pass == add_Owner[i].check_Owner_pass()) /// Id pass cmplt then Password check
                            {
                                Owner_Iterator = i;
                                cout << "\n                                                                                 Succesfully logged in \n\n";
                                add_Owner[i].show_Owner_details(); ///after verification Owner details showed
                                breakdown = 1;
                            }
                            break;
                        }
                    }
                    if (!breakdown) /// If id doesn't matched.
                    {
                        cout << "\n                                                                      _____________________________________________\n";
                        cout << "                                                                      ||       ... Invalid Login Id!!! ...       ||\n";
                        cout << "                                                                      ||       ... Please,select again ...       ||\n";
                        cout << "                                                                      ||_________________________________________||\n";
                    }
                }
                else if (select_Ownertypes == 2) /// Adding new owner details
                {
                    while (1)
                    {
                        int slow = 0;
                        cout << "\n                                                                      _____________________________________________\n";
                        cout << "                                                                          Fill up all option with correct information.!\n";
                        cout << "\n\n                                                                           ||||||||||||||||||||||||||||||||||\n";
                        cout << "                                                                             Enter your Id            : ";
                        cin >> O_loggin_id;
                        for (int i = 1; i <= count_Owner; i++)
                        {
                            if (O_loggin_id == add_Owner[i].check_Owner_Id()) /// Checking the uniqueness of the given owner id
                            {
                                slow = 1;
                                break;
                            }
                        }
                        if (slow == 1)
                        {
                            cout << "\n                                                                      Id is already taken or using....\n";
                            cout << "\n                                                                      Try another one.\n";
                        }
                        else if (slow == 0)
                            break;
                    }
                    cout << "                                                                             Enter your Name          : ";
                    cin.ignore();
                    getline(cin, O_name);
                    cout << "                                                                             Enter your Mobile Number : ";
                    cin >> O_mobile;
                    cout << "                                                                             Enter your Pass          : ";
                    cin >> O_pass;
                    count_Owner++;
                    add_Owner[count_Owner].set_O_details(O_loggin_id, O_name, O_mobile, O_pass); /// New Owner Details add in objects
                    breakdown = 1;
                    cout << "\n                                                                              Succesfully login as,\n";
                    add_Owner[count_Owner].show_Owner_details();
                    Owner_Iterator = count_Owner;
                }
                else
                {
                    cout << "\n                                                                      ____________________________________________ \n";
                    cout << "                                                                      ||     You select a invalid option!!!..    ||\n";
                }
            }
            else /// first verification--> not matched
            {
                cout << "\n                                                                      _____________________________________________\n";
                cout << "                                                                      ||    ... Invalid Password!!! ...          ||\n";
                cout << "                                                                      ||    ... Please,select again ...          ||\n";
            }

            if (breakdown) /// first verification--> matched
                break;
        }
        else if (select_Identity == 2) /// Customer Option and go to
            break;
        else if (select_Identity == 3) /// Exit
        {
            cout << "\n                                                                                 Thank you.\n"
                 << "                                                                            !_Take Care of yourself._!\n";
            break;
        }
        else
        {
            cout << "\n                                                                           Invalid Option!!.\n";
            cout << "                                                                             Select: \n\n";
            cout << "                                                                      _____________________________________________\n";
            cout << "                                                                      ||......  Are you Owner or Customer: ......||\n";
        }
    }

    int first = 1;

    /// Valid Owner Access Part
    while (breakdown)
    {
        if (first)
        {
            first = 0;
            cout << "\n";

            cout << "\n                                                              Hello Sr!!!Good Day....\n";
        }

    Owner_Choose:

        cout << "                                                             =======================================================================\n";
        cout << "                                                             |                 "
             << "*** What do you want to do sir?  ***"
             << "                |\n";
        cout << "                                                             =======================================================================\n";
        cout << "                                                             | "
             << "[01]. Show All Menu."
             << "             [02]. Add New Items.               |\n";

        cout << "                                                             | "
             << "[03]. Edit Existing Items."
             << "       [04]. Change Password.             |\n";

        cout << "                                                             | "
             << "[05]. Show All Customer."
             << "         [06]. Delete A Customer data.      |\n";

        cout << "                                                             | "
             << "[07]. Show All Registered Owner."
             << " [08]. See All Customer Ordered Data|\n";

        cout << "                                                             | "
             << "[09]. Show All Promos."
             << "                                              |\n";

        cout << "                                                             | "
             << "[10]. Add Promo or Delete Promos."
             << "[11]. Log out.                     |\n";
        cout << "                                                             =======================================================================\n";

        cout << endl;

        cout << "\n                                                             [Select Your Options]:=> ";
        cin >> select1;
        cout << "\n";

        if (select1 == 1) /// Show all menu
        {
            if (Count_Menu > 0)
            {
                Show_Menu();
            }
            else
            {
                cout << "                                                                    **|__Showing whole existing menu:__|**\n";
                cout << "                                                                             The menu is empty!..\n\n";
            }
        }
        else if (select1 == 2) /// adding new items
        {
            int TestPrice, TestAmount;
            string testName;
            cout << "                                                                           ||||||||||||||||||||||||||||||||||\n";
            cout << "                                                                             How many items: ";
            cin >> select2;
            for (int i = 1; i <= select2; i++)
            {
                cout << "                                                                             #" << i;
                cout << "\n                                                                             Name             : ";
                cin.ignore();
                getline(cin, testName);
                cout << "                                                                             Price            : ";
                cin >> TestPrice;
                while (TestPrice < 0)
                {
                    cout << "                                                                             Invalid price tag!!...\n";
                    cout << "                                                                             Please reconfirm your price: ";
                    cin >> TestPrice;
                }
                cout << "                                                                             Amount Available : ";
                cin >> TestAmount;
                cout << "                                                                           ||||||||||||||||||||||||||||||||||\n";
                while (TestAmount <= 0)
                {
                    cout << "                                                                             Invalid amount!!...\n";
                    cout << "                                                                             Please reconfirm your amount: ";

                    cin >> TestAmount;
                }
                cout << "\n";
                Count_Menu++;
                add_Menu[Count_Menu].fileToMenu(testName, TestPrice, TestAmount); /// New Item add in class object
            }
        }
        else if (select1 == 3) /// edit existing menu
        {
            int NumberOfEdit_item;
        Edit:

            if (Count_Menu > 0)
            {
                Show_Menu();
            }
            else
            {
                cout << "                                                                    **|__Showing whole existing menu:__|**\n";
                cout << "                                                                           \n>>The menu is empty!..\n";
            }

            cout << "                                                                [How many items you want to delete or edit]? : ";
            cin >> NumberOfEdit_item;
            cout << "\n";
            if (NumberOfEdit_item <= Count_Menu)
            {
                while (NumberOfEdit_item--)
                {
                    cout << "                                                                           ////////////////////////////////////////////////\n";
                    cout << "                                                                           |   Select how you change the existing items:  |\n";
                    cout << "                                                                           |   ........................................   |\n";
                    cout << "                                                                           | [1].Change the full items.                   |\n";
                    cout << "                                                                           | [2].Change only items name.                  |\n";
                    cout << "                                                                           | [3].Change only items price.                 |\n";
                    cout << "                                                                           | [4].Change only items amount.                |\n";
                    cout << "                                                                           | [5].Delete items.                            |\n";
                    cout << "                                                                           | [6].Cancel.                                  |\n";
                    cout << "                                                                           ////////////////////////////////////////////////\n";

                    string E_name;
                    int E_item, E_price, E_amount, E_iNum; /// E consider as Edit
                    cout << "                                                                           [Select your choice]: ";
                    cin >> E_item;
                    if (E_item == 1) /// Change full menu
                    {
                        Show_Menu();
                        cout << "                                                                           [Select item number which you want to edit]: ";
                        cin >> E_iNum;
                        if (E_iNum <= Count_Menu) /// check valid item number
                        {
                            cout << "                                                                           ||||||||||||||||||||||||||||||||||\n";
                            cout << "                                                                            Edit Item Name: ";
                            cin.ignore();
                            getline(cin, E_name);
                            cout << "                                                                            Edit Item Price: ";
                            cin >> E_price;
                            while (E_price < 0) ///negative proce check
                            {
                                cout << "                                                                             Invalid price tag!!...\n";
                                cout << "                                                                             Please reconfirm your price: ";
                                cin >> E_price;
                            }
                            cout << "                                                                            Edit Item Amount: ";
                            cin >> E_amount;
                            while (E_amount <= 0) /// negative amount check
                            {
                                cout << "                                                                             Invalid amount!!...\n";
                                cout << "                                                                             Please reconfirm your amount: ";
                                cin >> E_amount;
                            }
                            cout << "                                                                           ||||||||||||||||||||||||||||||||||\n";
                            add_Menu[E_iNum].EditFull_Items(E_name, E_price, E_amount); /// update in objets
                            cout << "\n";
                        }
                        else
                        {
                            cout << "                                                                             Invalid item number!....\n\n";
                            goto Edit;
                        }
                    }
                    else if (E_item == 2) /// change item name
                    {
                        Show_Menu();
                        cout << "                                                                             Select item number which you want to edit: ";
                        cin >> E_iNum;
                        if (E_iNum <= Count_Menu)
                        {
                            cout << "                                                                             Edit Item Name: ";
                            cin.ignore();
                            getline(cin, E_name);
                            add_Menu[E_iNum].Edit_Name(E_name); /// update in objets
                            cout << "\n";
                        }
                        else
                        {
                            cout << "                                                                             Invalid item number!....\n\n";
                            goto Edit;
                        }
                    }
                    else if (E_item == 3) ///change item price
                    {
                        Show_Menu();
                        cout << "                                                                             Select item number which you want to edit: ";
                        cin >> E_iNum;
                        if (E_iNum <= Count_Menu)
                        {
                            cout << "                                                                             Edit Item Price: ";
                            cin >> E_price;
                            while (E_price < 0)
                            {
                                cout << "                                                                             Invalid price tag!!...\n";
                                cout << "                                                                             Please reconfirm your price: ";
                                cin >> E_price;
                            }
                            cout << "                                                                             taka";
                            add_Menu[E_iNum].Edit_Price(E_price); /// update in objets
                            cout << "\n";
                        }
                        else
                        {
                            cout << "                                                                             Invalid item number!....\n\n";
                            goto Edit;
                        }
                    }
                    else if (E_item == 4) /// change item amount
                    {
                        Show_Menu();
                        cout << "\n";
                        cout << "                                                                             Select item number which you want to edit: ";
                        cin >> E_iNum;
                        if (E_iNum <= Count_Menu)
                        {
                            cout << "                                                                                 Edit Item Amount: ";
                            cin >> E_amount;
                            while (E_amount <= 0)
                            {
                                cout << "                                                                             Invalid amount!!...\n";
                                cout << "                                                                             Please reconfirm your amount: ";
                                cin >> E_amount;
                            }
                            add_Menu[E_iNum].Edit_Amount(E_amount); /// update in objets
                            cout << "\n";
                        }
                        else
                        {
                            cout << "\n";
                            cout << "                                                                             Invalid item number!....\n\n";
                            goto Edit;
                        }
                    }
                    else if (E_item == 5) /// Delete a menu
                    {
                        if (Count_Menu > 0)
                        {
                            Show_Menu();
                            cout << "                                                                             Select item number which you want to delete: ";
                            cin >> E_iNum;
                            if (E_iNum <= Count_Menu)
                            {
                                if (Count_Menu == 1)
                                {
                                    Count_Menu--;
                                }
                                else
                                {
                                    for (int i = E_iNum; i <= Count_Menu - 1; i++)
                                    {
                                        Owner temp;
                                        temp = add_Menu[i + 1];
                                        add_Menu[i] = temp;
                                    }
                                    Count_Menu--;
                                }
                                cout << "\n                                                                             After successfully deleting....\n";
                                if (Count_Menu > 0)
                                    Show_Menu();
                                else
                                {
                                    cout << "                                                                            **|__Showing whole existing menu:__|**\n";
                                    cout << "                                                                              The menu is empty!..\n";
                                }
                            }
                            else
                            {
                                cout << "                                                                             Invalid item number!....\n\n";
                                goto Edit;
                            }
                        }
                        else
                        {
                            cout << "                                                                           **|__Showing whole existing menu:__|**\n";
                            cout << "                                                                              The menu is empty!..\n\n";
                        }
                        cout << "\n";
                    }
                    else
                        continue;
                }
            }
            else
            {
                cout << "\n";
                cout << "                                                                             Invalid item selected!...\n\n";
            }
        }
        else if (select1 == 4) ///change password
        {
            string new_pass;
            cout << "\n                                                                           ||||||||||||||||||||||||||||||||||\n";
            cout << "                                                                             Enter your new password : ";
            cin >> new_pass;
            add_Owner[Owner_Iterator].set_Owner_passWord(new_pass);
            cout << "                                                                             Succesfully Updated...\n";
            cout << "                                                                           ||||||||||||||||||||||||||||||||||\n";
        }
        else if (select1 == 5) ///show all customer
        {
            cout << "\n                                                                                   Customer Registered: \n";
            cout << "                                                                           ..................................\n";
            for (int i = 1; i <= count_Customer; i++)
            {
                cout << "\n                                                                                     No. : " << i << "\n";
                Customer[i].show_all_customer_toAnOwner();
            }
            if (count_Customer == 0)
                cout << "\n                                                                            !! Database is empty !!\n";
        }
        else if (select1 == 6) ///delete an customer information
        {
            int delete_no;
            cout << "                                                                                   Customer Registered: \n";
            cout << "                                                                           ..................................\n";
            if (count_Customer > 0) /// If the item is not empty.
            {
                for (int i = 1; i <= count_Customer; i++)
                {
                    cout << "\n                                                                            No. : " << i << "\n";
                    Customer[i].show_all_customer_toAnOwner();
                }
            }
            else
            {
                cout << "\n                                                                           The customer registered database is empty...\n";
                cout << "                                                                           Selecte another program : \n";
                goto Owner_Choose;
            }
            cout << "\n                                                                           Which customer's details you want to delete? ";
            cin >> delete_no;
            if (delete_no <= count_Customer)
            {
                if (count_Customer == 1)
                {
                    count_Customer--;
                }
                else
                {
                    for (int i = delete_no; i <= count_Customer - 1; i++)
                    {
                        Owner temp;
                        temp = Customer[i + 1];
                        Customer[i] = temp;
                    }
                    count_Customer--;
                }
                cout << "\n";
                cout << "                                                                           After successfully deleting....\n";
                if (count_Customer > 0)
                {
                    cout << "                                                                           Customer Registered: \n";
                    for (int i = 1; i <= count_Customer; i++)
                    {
                        cout << "                                                                           No.             : " << i << "\n";
                        Customer[i].show_all_customer_toAnOwner();
                    }
                }
                else
                {
                    cout << "                                                                               Customer Registered: \n";
                    cout << "                                                                              The register is empty!..\n";
                }
            }
        }
        else if (select1 == 7) /// show all owner details
        {
            if (count_Owner > 0)
            {
                cout << "                                                                                [Registered Owner Details]  \n";
                cout << "                                                                                ``````````````````````````  \n";
                for (int i = 1; i <= count_Owner; i++)
                {
                    cout << "                                                                        No.: " << i;
                    cout << "\n";
                    add_Owner[i].show_Owner_details();
                }
            }
            else
            {
                cout << "                                                                                Registered Owner Details : \n";
                cout << "                                                                                 The register is empty\n\n";
            }
        }
        else if (select1 == 8) /// show all ordered list by customer
        {
            ifstream New_Ordered_List;
            New_Ordered_List.open("OrderdList.txt", ios::out | ios::app);
            string getCustomerId, getCustomerName, getOrderedName, getOrderDate, getOrderQuantity, getOrderPrice;
            int flag = 1;
            while (getline(New_Ordered_List, getCustomerId))
            {
                getline(New_Ordered_List, getCustomerName);
                getline(New_Ordered_List, getOrderDate);
                getline(New_Ordered_List, getOrderedName);
                getline(New_Ordered_List, getOrderQuantity);
                getline(New_Ordered_List, getOrderPrice);
                if (flag == 1)
                    cout << "\n                                                                                  Ordered List : \n";
                cout << "                                                                       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
                cout << "\n                                                                       ## List Number  : " << flag;
                cout << "\n                                                                       ## Customer Id  : " << getCustomerId;
                cout << "\n                                                                       ## Customer Name: " << getCustomerName;
                cout << "\n                                                                       ## Ordered Date : " << getOrderDate;
                cout << "\n                                                                       ## Item Name    : " << getOrderedName;
                cout << "\n                                                                       ## Item Quantity: " << getOrderQuantity;
                cout << "\n                                                                       ## Item Price   : " << getOrderPrice << " taka";
                cout << "\n                                                                       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
                flag++;
            }
            if (flag == 1)
            {
                cout << "\n                                                                       !_No database found of this customer id._!\n\n";
            }
            New_Ordered_List.close();

            /// after show all list we can delete this or can exit
            cout << "\n                                                                      ________________________________________________\n";
            cout << "                                                                         Here you can delete this file record...\n";
            cout << "                                                                         1. Delete this record. or Skip(except 1 press)\n";
            cout << "\n                                                                         [Select] : ";
            char take;
            cin >> take;
            cout << "\n";
            if (take == '1')
            {
                remove("OrderdList.txt");
                cout << "\n                                                                       Succesfully deleted this OrderdList.txt file.\n";
            }
            else
            {
                cout << "\n                                                                           Not Deleted!..\n";
            }
        }
        else if (select1 == 9) ///Show all Promo Code List
        {
            ifstream New_Promo;
            New_Promo.open("Promo_Code_List.txt", ios::out | ios::app);
            string Promo_Code, Promo_Date, Promo_Message;
            int flag = 1;
            while (getline(New_Promo, Promo_Date))
            {
                getline(New_Promo, Promo_Code);
                getline(New_Promo, Promo_Message);
                if (flag == 1)
                {
                    cout << "                                                                           IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
                    cout << "                                                                           I         Promo Code List        I\n";
                    cout << "                                                                           IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
                }
                cout << "\n                                                                           I================================I";
                cout << "\n                                                                           I Promo Number      : " << flag;
                cout << "\n                                                                           I Promo Valid Date  : " << Promo_Date;
                cout << "\n                                                                           I Promo Code        : " << Promo_Code;
                cout << "\n                                                                           I Promo Message     : " << Promo_Message;
                cout << "\n                                                                           I================================I";

                cout << "\n\n";
                flag++;
            }
            if (flag == 1)
            {
                cout << "\n                                                                          !_No database found of this Promo List._!\n\n";
            }
            New_Promo.close();
        }
        else if (select1 == 10) /// Adding new promo code or delete exiting promo code
        {
            cout << "                                                                           |||||||||||||||||||||||||||||||||||||\n";
            cout << "                                                                           || Are you interested in=>         ||\n";
            cout << "                                                                           || [1]. Adding Promo.              ||\n";
            cout << "                                                                           || [2]. Delete existing promo list.||\n";
            cout << "                                                                           || or, Exit. (Press except (1/2)   ||\n\n";
            cout << "                                                                              [Select] :=> ";
            char take;
            cin >> take;
            if (take == '1') /// add promo code
            {
                string date, message, code;
                cout << "\n                                                                            >>Enter Validity Date(DD-MM-Year) : ";
                cin >> date;
                cout << "                                                                              >>Enter Promo Code                : ";
                cin >> code;
                cout << "                                                                              >>Reason of adding code           : ";
                cin.ignore();
                getline(cin, message);
                set_Promo_Code(date, code, message);
                cout << "\n                                                                        _____________________________________________\n";

                cout << "\n                                                                               Successfully added the promo.....!\n\n";
            }
            else if (take == '2') /// delete promo code file
            {
                remove("Promo_Code_List.txt");
                cout << "\n                                                                          __________________________________________________\n";

                cout << "                                                                             Successfully deleted the Promo_Code_List.txt file......\n\n";
            }
            else /// exit
            {
                cout << "\n                                                                                !_Exit_!\n";
            }
        }
        else
        {
            goto find;
        }

        cout << "\n                                                                        Are you interest to do more in menu items sir? \n";
        cout << "\n                                                                        _______________________________________________\n";
    }

    int Calculate_Bill = 0, Cal_Num = 0, flag = 0, select_customer_type, stop = 0, select_5 = 0, customer_Iterator;
    string customer_login_id, customer_name, customer_contact, customer_pass, record_name, record_id;

    /// Customer Section Start
    if (select_Identity == 2)
    {
        while (1)
        {
            cout << "\n\n                                                               #########################################################\n";
            cout << "                                                               |                     CUSTOMER SECTION!                 |\n";
            cout << "                                                               #########################################################\n\n";
            cout << "                                                                           //////////////////////////////////\n";
            cout << "                                                                           |        Hello Visitors!!!       |\n";
            cout << "                                                                           |  *__ Welcome to restaurant __* |\n";
            cout << "                                                                           |````````````````````````````````|\n";
            cout << "                                                                           |   Customer Login:              |\n";
            cout << "                                                                           |                                |\n";
            cout << "                                                                           | [1]    Login.                  |\n";
            cout << "                                                                           | [2]    Sign up.                |\n";
            cout << "                                                                           |                                |\n";
            cout << "                                                                           //////////////////////////////////\n";

            cout << "                                                                           [Select]:=> ";
            cin >> select_customer_type;
            cout << "\n";
            if (select_customer_type == 1) /// Login part
            {
                cout << "                                                                           ||||||||||||||||||||||||||||||||||\n";
                cout << "                                                                            Give your customer login id:  ";
                cin >> customer_login_id;
                for (int i = 1; i <= count_Customer; i++)
                {
                    if (Customer[i].check_customer_id() == customer_login_id) /// check id
                    {
                        cout << "                                                                            Give your pass: ";
                        cin >> customer_pass;
                        cout << "                                                                           ||||||||||||||||||||||||||||||||||\n";
                        if (customer_pass == Customer[i].check_customer_pass()) /// Check passwor if id matched
                        {
                            system("cls");
                            customer_Iterator = i;
                            record_id = Customer[i].check_customer_id();
                            record_name = Customer[i].check_customer_name();
                            cout << "\n                                                                               >>Succesfully login as,\n";
                            Customer[i].show_customer_details();
                            stop = 1; ///login key
                            cout << "\n";
                        }
                        break;
                    }
                }
                if (!stop) /// login failed
                {
                    cout << "\n                                                                                   >>Invalid login id!!!..\n";
                    cout << "                                                                                   >>Please,select again..\n";
                }
            }
            else if (select_customer_type == 2) /// Customer sign up
            {
                while (1)
                {
                    int nap = 0;
                    cout << "                                                               !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                    cout << "                                                                   Fill up all option with correct information.!\n\n";
                    cout << "                                                                   Enter your customer id: ";
                    cin >> customer_login_id;
                    for (int i = 1; i <= count_Customer; i++)
                    {
                        if (customer_login_id == Customer[i].check_customer_id()) /// Checking uniqueness of customer id
                        {
                            nap = 1;
                            break;
                        }
                    }
                    if (nap == 0)
                        break;
                    else if (nap == 1) /// not unique id
                    {
                        cout << "                                                               _________________________________________________________\n";
                        cout << "                                                                   Id is already taken or using....\n";
                        cout << "                                                                   Try another one.\n";
                    }
                }
                cout << "                                                               !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                cout << "                                                                   Enter your Name          : ";
                cin.ignore();
                getline(cin, customer_name);
                cout << "                                                                   Enter your Mobile Number : ";
                cin >> customer_contact;
                cout << "                                                                   Enter your Pass          : ";
                cin >> customer_pass;
                cout << "                                                               !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                count_Customer++;
                Customer[count_Customer].set_customer_details(customer_login_id, customer_name, customer_contact, customer_pass); /// adding customer details in object

                stop = 1; /// Key to access customer option
                record_id = customer_login_id;
                record_name = customer_name;
                cout << "\n                                                                   >>Succesfully login as,\n";
                Customer[count_Customer].show_customer_details();
                customer_Iterator = count_Customer;
                cout << "\n";
            }
            else
            {
                cout << "\n                                                                     >>You select a invalid option!!!..\n";
            }

            /// after successfully login of customer
            /// Customer permitted option
            if (stop)
            {

            ThinkToOrder:

                cout << "                                                               +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
                cout << "                                                               | Hey " << record_name << "!,                                         \n";
                cout << "                                                               | Are you ready to order or see your previous orderd list.        |\n";
                cout << "                                                               | [1]. Go to order.                                               |\n";
                cout << "                                                               | [2]. See my past activities.                                    |\n";
                cout << "                                                               | [3]. Change Password.                                           |\n";
                cout << "                                                               +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

                cout << "                                                                   [Select] : ";
                cin >> select_5;
                if (select_5 == 1) /// Going Order section
                {
                    break;
                }
                else if (select_5 == 2) /// Check Previous ordered history of these login customer
                {
                    ifstream New_OrderList;
                    New_OrderList.open("OrderdList.txt", ios::out | ios::app);
                    string Checker_String, getCustomerName, getOrderedName, getOrderDate, getOrderQuantity, getOrderPrice;
                    int flag = 1;
                    while (getline(New_OrderList, Checker_String))
                    {
                        if (Checker_String == record_id) /// Customer iteration store in record_id and check this in file
                        {
                            getline(New_OrderList, getCustomerName);
                            getline(New_OrderList, getOrderDate);
                            getline(New_OrderList, getOrderedName);
                            getline(New_OrderList, getOrderQuantity);
                            getline(New_OrderList, getOrderPrice);
                            if (flag == 1)
                            {
                                cout << "\n                                                                           =====================================\n";
                                cout << "                                                                            Customer Name : " << getCustomerName << "\n";
                                cout << "                                                                            Ordered List  : \n\n";
                            }
                            cout << "                                                                           ||||||||||||||||||||||||||||||||||\n";
                            cout << "                                                                            List Number  : " << flag;
                            cout << "\n                                                                            Ordered Date : " << getOrderDate;
                            cout << "\n                                                                            Item Name    : " << getOrderedName;
                            cout << "\n                                                                            Item Quantity: " << getOrderQuantity;
                            cout << "\n                                                                            Item Price   : " << getOrderPrice << " taka";
                            cout << "\n                                                                           ||||||||||||||||||||||||||||||||||\n";
                            cout << "\n\n";
                            flag++;
                        }
                    }
                    if (flag == 1)
                    {
                        cout << "\n                                                                           !_No database found of this customer id._!\n\n";
                    }
                    New_OrderList.close();

                    goto ThinkToOrder;
                }
                else if (select_5 == 3) /// Change customer password
                {
                    string new_Pass;
                    cout << "\n                                                                           |||||||||||||||||||||||||||||||||||\n";
                    cout << "\n                                                                           Enter your new login password : ";
                    cin >> new_Pass;
                    Customer[customer_Iterator].set_customer_Pass(new_Pass);
                    cout << "\n                                                                          Succesfully updated your password...\n\n";
                    goto ThinkToOrder;
                }
                else
                {
                    cout << "\n                                                                                 Invalid keyword!!!...\n";
                    cout << "                                                                                   Please reconfirm.\n";
                    goto ThinkToOrder;
                }
            }
        }

        ///Order section start
        string today_date;
        while (1)
        {
            cout << "                                                                           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "                                                                           |       How can we help you!!    |\n";
            cout << "                                                                           |================================|\n";
            cout << "                                                                           | [1]See all Menu.               |\n";
            cout << "                                                                           | [2]Select your items for order.|\n";
            cout << "                                                                           | [Or]That's all                 |\n";
            cout << "                                                                           //////////////////////////////////\n";
            cout << "\n                                                                         [Seletc an option]: ";
            cin >> select3;
            if (select3 == 1) /// Show all menu
            {
                if (Count_Menu > 0)
                    Show_Menu();
                else
                {
                    cout << "\n                                                                           **|__Showing whole existing menu:__|**\n";
                    cout << "\n                                                                                  The menu is empty!..\n\n";
                }
            }
            else if (select3 == 2) /// Order here
            {
                if (Count_Menu > 0)
                {
                select_Item:
                    cout << "                                                                                 [Select an item]: ";
                    cin >> select4;
                    if (select4 <= Count_Menu)
                    {
                        cout << "                                                                                 Amount of this item: ";
                        cin >> quantity;
                        cout << "\n";
                        testQuantity = add_Menu[select4].countQuantityAvailibility();
                        while (1)
                        {
                            if (testQuantity == 0) /// if the item finished than customer can select another item
                            {
                                cout << "\n                                                                               Sorry sir\n";
                                cout << "                                                                               This item have been finished!!\n";
                                cout << "                                                                               Please select another items:\n\n";
                                cout << "                                                                               [Select item]:=> ";
                                cin >> select4;
                                cout << "                                                                               Amount of this item: ";
                                cin >> quantity;
                                cout << "\n";
                                testQuantity = add_Menu[select4].countQuantityAvailibility();
                                continue;
                            }
                            else if (quantity <= testQuantity && quantity > 0) /// only orderd when quantity was valid and exist
                            {
                                set = testQuantity - quantity;
                                add_Menu[select4].setQuantityAvailibility(set);
                                cout << "                                                                       ||||||||||||||||||||||||||||||||||||||||||||||||||\n";
                                cout << "                                                                        Enter todays date(DD-MM-Year) ::  ";
                                cin >> today_date;
                                Calculate_Bill += add_Menu[select4].Set_Bill(quantity);
                                Cal_Num++;
                                cout << "\n";
                                cout << "                                                                                       #Selected item: " << Cal_Num << "\n";
                                add_Menu[select4].select_itemBill(quantity, today_date); /// Every ,single item bill.
                                add_Menu[select4].set_Customer_Order_File(record_id, record_name);
                                flag++;
                                break;
                            }
                            else if (quantity <= 0) /// Negative quantity ncheck
                            {
                                cout << "\n                                                                            Sorry Sir, you choose invalid quantity\n";
                                cout << "                                                                            Please again choose\n";
                                cout << "                                                                            Amount of this item: ";
                                cin >> quantity;
                                cout << "\n";
                            }
                            else /// if order more than the item Availibility
                            {
                                cout << "\n                                                                            Sorry Sir, you choose over quantity\n";
                                cout << "                                                                            Please again choose\n";
                                cout << "                                                                            Amount of this item: ";
                                cin >> quantity;
                                cout << "\n";
                            }
                        }
                    }
                    else /// Item not exist
                    {
                        cout << "\n\n                                                                       This item doesn't exist!...\n";
                        goto select_Item;
                    }
                }
                else
                {
                    cout << "\n\n                                                                           The restaurant food is empty...!\n";
                    cout << "                                                                           Please sir,order in later.\n";
                    cout << "                                                                           Thank you.\n";
                    cout << "\n                                                                         Succesfully log out...\n";
                    break;
                }
            }
            else /// Billing Part
            {
                if (flag != 0) /// If ordered
                {
                    ifstream New_Promo;
                    New_Promo.open("Promo_Code_List.txt", ios::out | ios::app);
                    string Promo_Code, Promo_Date, Promo_Message;
                    int counter = 1;
                    while (getline(New_Promo, Promo_Date))
                    {
                        if (Promo_Date == today_date) /// Check the date with Promo special date
                        {
                            string Input_Promo;
                            getline(New_Promo, Promo_Code);
                            getline(New_Promo, Promo_Message);
                            cout << "\n\n                                                               ##############################################################\n";
                            cout << "                                                               Congratulations!!!! You got a promo code ==>> " << Promo_Code << "\n";
                            cout << "                                                               " << Promo_Message << "\n";
                            cout << "                                                               ##############################################################\n";
                            cout << "\n                                                                   >>Enter your promo code to get discount! : ";
                            cin >> Input_Promo; ///Customer given the promo code
                            if (Input_Promo == Promo_Code)
                            {
                                cout << "\n                                                                 ________________________________________________________ \n";
                                cout << "                                                                |********************************************************|\n";
                                cout << "                                                                |----------****** The_Bro_bugger's Dhaba ******----------|\n";
                                cout << "                                                                |________________________________________________________|\n";
                                cout << "                                                                |---------------------                                   |\n";
                                cout << "                                                                [  Before discount   ]                                   |\n";
                                cout << "                                                                |---------------------                                   |\n";
                                cout << "                                                                | Your Bill : " << Calculate_Bill << " taka only.                            |\n";
                                cout << "                                                                |--------------------------------------------------------|\n";
                                cout << "                                                                | Congo...! You got 15% "
                                     << "discount on your net bill.       |\n";
                                cout << "                                                                |                                                        |\n";
                                cout << "                                                                |---------------------                                   |\n";
                                cout << "                                                                [   After discount   ]                                   |\n";
                                cout << "                                                                |---------------------                                   |\n";
                                Calculate_Bill = Calculate_Bill * 0.85;
                                Net_Bill(Calculate_Bill);
                            }
                            else /// Customer put wrong promo code!!..
                            {
                                cout << "\n                                                                 ________________________________________________________ \n";
                                cout << "                                                                |********************************************************|\n";
                                cout << "                                                                |----------****** The_Bro_bugger's Dhaba ******----------|\n";
                                cout << "                                                                |________________________________________________________|\n";
                                cout << "                                                                |      Wrong promo code!..                               |\n";
                                Net_Bill(Calculate_Bill);
                            }
                            counter = 0;
                        }
                        New_Promo.close();
                    }
                    if (counter == 1) /// If no promo date exist
                    {
                        cout << "\n                                                                 ________________________________________________________ \n";
                        cout << "                                                                |********************************************************|\n";
                        cout << "                                                                |----------****** The_Bro_bugger's Dhaba ******----------|\n";
                        cout << "                                                                |________________________________________________________|\n";
                        Net_Bill(Calculate_Bill); /// Net_Bill of total selecting items
                    }
                }
                else /// Not ordered.
                {
                    cout << "                                                                       Not any order placed yet!\n";
                    cout << "                                                                       Sir,Try to place your order later.\n";
                    cout << "                                                                       [Thank You]!...\n";
                    cout << "                                                                       Succesfully log out...\n";
                    cout << "                                                               ____________________________________________________________\n";
                }
                break;
            }
            cout << "\n\n                                                                       Sir,Do you want to place your order now or skip: \n";
        }
    }

    ///After resetting the quantity delete old file information
    remove("restaurant.txt");
    remove("Owner.txt");
    remove("Customer.txt");

    ///Again transfer update data into file

    for (int i = 1; i <= count_Owner; i++)
        add_Owner[i].set_Owner_File();

    for (int j = 1; j <= Count_Menu; j++)
    {
        add_Menu[j].setFile();
    }

    for (int i = 1; i <= count_Customer; i++)
    {
        Customer[i].set_Customer_File();
    }
    return 0;
}
