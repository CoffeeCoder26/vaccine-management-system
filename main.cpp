// vaccine management system

// header files

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <evntprov.h>
#include <unistd.h>

#define total_vaccine 400

using namespace std;

class covid_management
{
protected:
    string username, password, usn;

    // FOR VACCINE CENTER
    string center1 = "1center";
    string center2 = "2center";
    string center3 = "3center";
    int sum_vaccine_c1 = 0; // Center1 vaccine Dose
    int sum_vaccine_c2 = 0; // Center2 vaccine Dose
    int sum_vaccine_c3 = 0; // Center3 vaccine Dose
    int number_of_vaccines, center_no;

    // For Doctor Details
    string identification_id;
    char specialization[100];
    string center, adhaar;
    // For User and some Doctor Details
    char name[100];
    char gender[100];
    int age;
    int c;
    string phone_no, profession, address, vaccine_name;
    int dose;

public:
    void main_menu();
    void admin();
    void admin_password();
    void user();
    void user_password();

    // For ADMIN
    void add_vaccine_stock();     // 1
    void display_vaccine_stock(); // 2
    void show_patient_data();     // 4
    void show_data();             // 4-a
    void applied_vaccine();       // 5
    void add_doctor();            // 6
    void search_doctor_data();    // 7
    void display_doctor_data();   // 8
    void doctor_show_data();      // 8-a
    void search_by_aadhar();      // 4-a(1)
    void search_by_age();         // 4-a(2)
    void search_by_profession();  // 4-a(3)
    void search_by_gender();

    // for USER

    void search_center();
};

// project main_menu

void covid_management::main_menu()
{

    // System(cls) CLS (for clear screen)
    system("cls");

    int choice;
    cout << "\n\t\t\t\t\t*********************************************";
    cout << "\n\t\t\t\t\t   *       Covid Management System*       *";
    cout << "\n\t\t\t\t\t*********************************************";

    // main menu

    cout << "\n\n\t\t --> Main Menu <--";
    cout << "\n\n\t\t --> 1. Admin";
    cout << "\n\n\t\t --> 2. User";
    cout << "\n\n\t\t --> 3. Exit";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> choice;

    // calling relevant function

    switch (choice)
    {
    case 1:
        admin();
        break;

    case 2:
        user();
        break;

    case 3:
        system("cls");
        cout << "\n\n\t\t COVID - MANAGEMENT - SYSTEM";
        Sleep(10);
        exit(0);
    default:
        cout << "\n\n\t\tEnter Valid Choice";
        cout << "\n\n\t\tPress Any Key To Continue .......";

        // getch() method pauses the Output Console until a key is pressed
        getch();
        main_menu();
    }
}

// Admin Panel
void covid_management::admin()
{
    admin_password();

A:
    system("cls");
    int admin_choice;

    cout << "\n\t\t\t\t\t*********************************************";
    cout << "\n\t\t\t\t\t   *       Admin Options       *";
    cout << "\n\t\t\t\t\t*********************************************";

    // Admin options

    cout << "\n\n\t\tAdmin Menu";
    cout << "\n\n\t\t 1. Add Vaccine Stock";
    cout << "\n\t\t 2. Show Vaccine Center";
    cout << "\n\t\t 3. Show Vaccine Stock";
    cout << "\n\t\t 4. Show Patient Data";
    cout << "\n\t\t 5. Show Total Number of Vaccines Applied";
    cout << "\n\t\t 6. Add New Doctor Data";
    cout << "\n\t\t 7. Search Doctor Data";
    cout << "\n\t\t 8. Show Doctor Data";
    cout << "\n\t\t 9. Logout";

    cout << "\n\n\t\tEnter Choice: ";
    cin >> admin_choice;

    switch (admin_choice)
    {
    case 1:
        add_vaccine_stock();
        goto A;
        break;

    case 2:
        search_center();
        goto A;
        break;

    case 3:
        display_vaccine_stock();
        goto A;
        break;

    case 6:
        add_doctor();
        goto A;
        break;

    case 8:
        display_doctor_data();
        goto A;
        break;
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        cout << "\n\n Press Any Key To Continue: ";
        getch();
        goto A;
        break;
    }
}

// Admin Verified Panel

void covid_management::admin_password()
{

    system("cls");

    char admin_name[20];
    char admin_password[20];
    int ch, i = 0, capt = 0, capta = 0;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t -->> LOGIN ADMIN <<--";
    cout << "\n\n\t\tEnter Your Name: ";
    cin >> admin_name;
    cout << "\n\t\tEnter Your Password: ";
    while ((ch = getch()) != 13)
    {
        cout << "*";
        admin_password[i] = ch;
        i++;
    }
    admin_password[i] = '\0';
    srand(time(0));
    capt = rand();
    cout << "\n\n\t\tCaptcha: " << capt;
    cout << "\n\n\t\tEnter Valid Captcha: ";
    cin >> capta;
    if ((strcmp(admin_name, "karim") == 0) && (strcmp(admin_password, "karim26") == 0) && (capt == capta))
    {
        cout << "\n\n\n\t\t\t\t\t| Verfiying ADMIN |\n\t\t\t\t\t";
        for (int a = 1; a < 8; a++)
        {
            Sleep(500);
            cout << "...";
        }
        cout << "\n\nAccess Granted..\n\n";
        system("PAUSE");
        system("cls");
    }
    else
    {
        cout << "\n\n\n\t\t\t\t\t| Verfiying ADMIN |\n\t\t\t\t\t";
        for (int a = 1; a < 8; a++)
        {
            Sleep(500);
            cout << "...";
        }
        cout << "\n\nAccess Aborted...\n\n";
        system("PAUSE");
        system("cls");
        main_menu();
    }
}

// User panel

void covid_management::user()
{

    system("cls");

    user_password();
    int user_choice;
    cout << "\n\t\t\t\t\t***************************************";
    cout << "\n\t\t\t\t\t   *       User Options       *";
    cout << "\n\t\t\t\t\t***************************************";

    // user options

    cout << "\n\n\t\tUser Options";
    cout << "\n\n\t\t 1. Search Vaccination Center";
    cout << "\n\t\t 2. Apply For Vaccine Dose";
    cout << "\n\t\t 3. Show Details";
    cout << "\n\t\t 4. Apply For Vaccine Second Dose";
    cout << "\n\t\t 5. LOG OUT";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> user_choice;
}

// User Verified Panel

void covid_management::user_password()
{
    system("cls");
    char c;
    int user_choice;
    string fname, usern;
    ofstream fileoutput;
    ifstream fileinput;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t -->> USER SUB-MENU <<--";
    cout << "\n\n\t\t 1. Create Account";
    cout << "\n\t\t 2. Login";
    cout << "\n\t\t 3. Back";
    cout << "\n\t\tEnter Choice: ";
    cin >> user_choice;
    if (user_choice == 1)
    {
        system("cls");
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\n\t\t -->> REGISTRATION USER <<--";
        cout << "\n\n\t\tEnter Your Name: ";
        cin.ignore();
        getline(cin, username);
        cout << "\n\t\tEnter Your Username: ";
        cin >> usn;

        cout << "\n\t\tEnter Your password: ";
        cin >> password;
        fname = usn + ".txt";
        fileoutput.open(fname.c_str());
        fileoutput << usn << endl
                   << username << endl
                   << password << endl;
        cout << "\nYou are successfully registered:)";
        cout << "\n\nPress Any Key To Continue..";
        Sleep(500);
        getch();
        fileoutput.close();
        user();
    }
    else if (user_choice == 2)
    {
        system("cls");
        string u_name, u_pass;
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
        cout << "\n\t\t\t\t*****************************************";
        // LOGIN USER
        cout << "\n\n\t\t -->> LOGIN USER <<--";
        cout << "\n\n\t\tEnter Your Username: ";
        cin >> u_name;
        cout << "\n\t\tEnter Your Password: ";
        cin >> u_pass;
        fname = u_name + ".txt";
        fileinput.open(fname.c_str());
        if (!fileinput.is_open() && fileinput.fail())
        {
            cout << "\nYou are not registered, please register before logging in.\n";
            fileinput.close();
            getch();
            user_password();
        }
        getline(fileinput, usern);
        getline(fileinput, u_pass);
        if (u_name == usn && u_pass == password)
        {
            cout << "\nYou are successfully logged in:)";
            cout << "\n\nPress Any Key To Continue..";
            Sleep(500);
            getch();
            user();
        }
    }
    else if (user_choice == 3)
    {
        main_menu();
    }
    else
    {
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        cout << "\n\n Press Any Key To Continue: ";
        getch();
        user_password();
    }
}

/********************ADMIN**************************************/

void covid_management::add_vaccine_stock()
{
A:
    fstream file;
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> ADD VACCINE IN CENTER <<--";
    cout << "\n\n\t\t1. " << center1 << "\t\t2. " << center2;
    cout << "\n\n\t\t3. " << center3 << "\t\t4. BACK";
    cout << "\n\t\tEnter Choice: ";
    cin >> center_no;
    switch (center_no)
    {
    case 1:
    {
        file.open("center1.txt", ios::app);
        cout << "\n\t\t -->> For Center 1 <<--";
        cout << "\n\tEnter Number Of Vaccines You Want To Add: ";
        cin >> number_of_vaccines;
        sum_vaccine_c1 += number_of_vaccines;
        file << sum_vaccine_c1;
        file.close();
        cout << "\n\n\tVaccine In Center: " << sum_vaccine_c1;
        cout << "\n\n\t\tSUCCESSFULLY ADDED VACCINES TO THE CENTER";
        cout << "\n\n\nPress Any Key To Continue..";
        getch();
        goto A;
        break;
    }

    case 2:
    {
        file.open("center2.txt", ios::app);
        cout << "\n\t\t -->> For Center 2 <<--";
        cout << "\n\tEnter Number Of Vaccines You Want To Add: ";
        cin >> number_of_vaccines;
        sum_vaccine_c2 += number_of_vaccines;
        file << sum_vaccine_c2;
        file.close();
        cout << "\n\n\tVaccine In Center: " << sum_vaccine_c2;
        cout << "\n\n\t\tSUCCESSFULLY ADDED VACCINES TO THE CENTER";
        cout << "\n\n\nPress Any Key To Continue..";
        getch();
        goto A;
        break;
    }

    case 3:
    {
        file.open("center3.txt", ios::app);
        cout << "\n\t\t -->> For Center 3 <<--";
        cout << "\n\tEnter Number Of Vaccines You Want To Add: ";
        cin >> number_of_vaccines;
        sum_vaccine_c3 += number_of_vaccines;
        file << sum_vaccine_c3;
        file.close();
        cout << "\n\n\tVaccine In Center: " << sum_vaccine_c3;
        cout << "\n\n\t\tSUCCESSFULLY ADDED VACCINES TO THE CENTER";
        cout << "\n\n\nPress Any Key To Continue..";
        getch();
        goto A;
        break;
    }

    case 4:
    {
        break;
    }
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        cout << "\n\n Press Any Key To Continue: ";
        getch();
        add_vaccine_stock();
        break;
    }
}

void covid_management::search_center()
{

    system("cls");
    ifstream file;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> Various Vaccination Centers In Your City <<--";
    file.open("center1.txt");
    if (!file)
    {
        cout << "\nFile Not Found ";
    }
    else
    {
        file >> sum_vaccine_c1;
        cout << "\n\n\t\t-->> " << center1 << " <<--";
        cout << "\n\t\tTotal Vaccine: " << sum_vaccine_c1;
    }
    file.close();
    file.open("center2.txt");
    if (!file)
    {
        cout << "\nFile Not Found ";
    }
    else
    {
        file >> sum_vaccine_c2;
        cout << "\n\n\t\t-->> " << center2 << " <<--";
        cout << "\n\t\tTotal Vaccine: " << sum_vaccine_c2;
    }
    file.close();
    file.open("center3.txt");
    if (!file)
    {
        cout << "\nFile Not Found ";
    }
    else
    {
        file >> sum_vaccine_c3;
        cout << "\n\n\t\t-->> " << center3 << " <<--";
        cout << "\n\t\tTotal Vaccine: " << sum_vaccine_c3;
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void covid_management::display_vaccine_stock()
{

    system("cls");
    ifstream ind;
    fstream file1, file2, file3;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t->> Available Vaccine Stock <<--\n\n";
    int i = 0;
    file1.open("center1.txt"); // Open Center1
    file2.open("center2.txt"); // Open Center2
    file3.open("center3.txt"); // Open Center3
    file1 >> sum_vaccine_c1;
    file2 >> sum_vaccine_c2;
    file3 >> sum_vaccine_c3;
    ind.open("Patient_Data.dat"); // Data take from Patient file

    // allows you to seek an arbitrary position in a file
    ind.seekg(0, ios::beg);
    while (ind.read((char *)this, sizeof(covid_management)))

    {
        i++;
    }
    ind.close();
    int s = total_vaccine + sum_vaccine_c1 + sum_vaccine_c2 + sum_vaccine_c3 - i;
    file1.close();
    file2.close();
    file3.close();
    cout << "\n\nAvailable Number Of Vaccines are: " << s;
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void covid_management ::add_doctor()
{

    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> ADD DOCTOR <<--";
    fstream file;
    cout << "\n\n\t\tEnter Name: ";
    fflush(stdin);
    cin.getline(name, 100);
    cout << "\n\n\t\tEnter Identification Number: ";
    fflush(stdin);
    cin >> identification_id;
C:
    cout << "\n\n\t\tEnter Aadhar No.: ";
    cin >> adhaar;
    if (adhaar.length() != 12)
    {
        cout << "\nInvalid Aadhar Card Number";
        goto C;
    }
    else
    {
        // The first letter should not start with 0 or 1
        if (adhaar[0] == '0' || adhaar[0] == '1')
        {
            cout << "\nInvalid Aadhar Card Number";
            goto C;
        }
        else
        {
            cout << "\nValid Aadhar Card Number";
        }
    }
B:
    cout << "\n\n\t\tEnter Your Mobile Number: ";
    cin >> phone_no;
    if (phone_no.length() != 11)
    {
        cout << "\nInvalid Phone Number";
        goto B;
    }
    else
    {
        cout << "\nValid Phone Number";
    }
    cout << "\n\n\t\tEnter Gender (M/F): ";
    cin >> gender;
    cout << "\n\n\t\tEnter Age: ";
    cin >> age;
    cout << "\n\n\t\tEnter Specialization: ";
    fflush(stdin);
    cin.getline(specialization, 40);
    cout << "\n\n\t\tEnter Center Allotted: ";
    cin >> center;

    // Open in binary mode.
    file.open("Doctor_Data.dat", ios::app | ios::binary);
    file.write((char *)this, sizeof(covid_management));
    cout << "\n\nSUCCESSFULLY INSERTED" << endl;
    cout << "\n\nPress Any Key To Continue..";
    file.close();
    getch();
}

void covid_management::display_doctor_data()
{
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SHOW DOCTOR DATA <<--";
    ifstream file;
    file.open("Doctor_Data.dat", ios::in | ios::binary);
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(*this));
        while (!file.eof())
        {
            cout << "\n";
            doctor_show_data();
            file.read((char *)this, sizeof(*this));
        }
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void covid_management::doctor_show_data()
{
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Name: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << name;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Identification No.: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << identification_id;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Aadhar No.: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << adhaar;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Mobile No.: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << phone_no;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Gender: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << gender;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Age: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << age;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Specialization: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << specialization;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Center Allotted: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << center;
}


void covid_management::show_patient_data()
{
B:
    system("cls");
    int choice;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA <<--";
    cout << "\n\t\t1. Search Data By Aadhar \t\t\t2. Search Data BY  AGE" << endl;
    cout << "\n\t\t3. Search Data By Profession \t\t\t4. Search Data By Gender" << endl;
    cout << "\n\t\t5. EXIT";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        search_by_aadhar();
        goto B;
   
    default:
        cout << "\n\n\t\tInvalid Choice.. Please Try Again..";
        getch();
        goto B;
    }
}

void covid_management::search_by_aadhar()
{
    int count = 0;
    string search_adhaar;
    ifstream file;
    file.open("Patient_Data.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA BY AADHAR <<--";
    cout << "\n\n\t\tEnter Aadhar No.: ";
    cin >> search_adhaar;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(covid_management));
    }
    while (!file.eof())
    {
        if (search_adhaar.compare(adhaar) == 0)
        {
            count++;
            show_data();
        }
        file.read((char *)this, sizeof(covid_management));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

int main()
{
    system("Color B");
    covid_management covidManagement;
    covidManagement.main_menu();
}
