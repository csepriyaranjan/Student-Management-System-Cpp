#include <iostream>
#include <fstream>
#include <cstring>
/* www.github.com/ErPriyaranjan */
using namespace std;

struct Student {
    int Roll_no;
    char Name[25];
    char Class[10];
};


void Add_data(){
    fstream file;
    Student st;

    
    file.open("Student.dat", ios::binary | ios::app);
    if (!file) {
        cout << "\nError in opening file." << endl;
        return;
    }

    char wish = 'y';
    system("cls");
    cout << "\n\n---------------------------------------";
    cout << "\n           ADD STUDENT RECORD            ";
    cout << "\n\n---------------------------------------";
    while (wish == 'y') {
        cout << "\n\n ENTER STUDENT ROLL NO. : ";
        cin >> st.Roll_no;
        cout << "\n ENTER STUDENT NAME : ";
        cin.ignore(); // to ignore any leftover newline character in the input buffer
        cin.getline(st.Name, 25);
        cout << "\n ENTER STUDENT CLASS : ";
        cin.getline(st.Class, 10);

        file.write((char *)&st, sizeof(st));

        cout << "\n\nWant to add more record (y/n)? : ";
        cin >> wish;
        system("cls");
    }
    file.close();
};


void Search_data(){
    int rn;
    cout << "\nENTER ROLL NO. : ";
    cin >> rn;

    fstream file;
    Student st;

    file.open("Student.dat", ios::binary|ios::in);  
    if (!file.is_open()) {
        cout<< "\n\nError opening file. " << endl;
    }

    bool found = false;
    while (file.read((char *)&st, sizeof(st))) {
        if (st.Roll_no == rn) {
            found = true;
            cout << "\n\n---------------------------------------";
            cout << "\n            STUDENT RECORD             ";
            cout << "\n\n---------------------------------------";
            cout << "\n ROLL NO. \t NAME \t CLASS ";
            cout << "\n-----------------------------------------";
            cout << "\n" << st.Roll_no << "\t\t" << st.Name << "\t" << st.Class;
            break;
        }
    }

    if (!found) {
        cout << "\n\nRecord with Roll No. " << rn << " not found." << endl;
    }

    file.close();
};


void Edit_data(){
    fstream infile, outfile;
    Student st;

    int rn;
    cout << "\nENTER ROLL NO. : ";
    cin >> rn;

    infile.open("Student.dat", ios::binary | ios::in);
    outfile.open("temp.dat", ios::binary | ios::out);
    if (!infile || !outfile) {
        cout << "\n\nError in opening file." << endl;
    }

    while (infile.read((char *)&st, sizeof(st))) {
        if (st.Roll_no != rn) {

            outfile.write((char *)&st, sizeof(st));
        }
        else{
            cout << "\n-----------------------------------------";
            cout << "\n ROLL NO. \t NAME \t CLASS ";
            cout << "\n-----------------------------------------";
            cout << "\n" << st.Roll_no << "\t\t" << st.Name << "\t" << st.Class<<"\n\n";
            cout << "\n\n ENTER STUDENT ROLL NO. : ";
            cin >> st.Roll_no;
            cout << "\n ENTER STUDENT NAME : ";
            cin.ignore(); // to ignore any leftover newline character in the input buffer
            cin.getline(st.Name, 25);
            cout << "\n ENTER STUDENT CLASS : ";
            cin.getline(st.Class, 10);

            outfile.write((char *)&st, sizeof(st));
        }
    }
    infile.close();
    outfile.close();

    remove("Student.dat");
    rename("temp.dat", "Student.dat");
    cout << "\n\nRecord deleted successfully if it existed." << endl;
};

void Display_all_data(){
    fstream file;
    Student st;


    file.open("Student.dat", ios::binary | ios::in);
    if (!file) {
        cout << "Error in opening file." << endl;
    }
    else{
        cout << "\n\n---------------------------------------";
        cout << "\n            STUDENT RECORD               ";
        cout << "\n\n---------------------------------------";
        cout << "\nRN.\t NAME \t CLASS ";
        cout << "\n-----------------------------------------";
        while (file.read((char *)&st, sizeof(st))) {
            cout <<"\n" << st.Roll_no << "\t  " << st.Name << "\t" << st.Class;
        }
        file.close();
    }
};


void Delete_an_data(){
    fstream infile, outfile;
    Student st;

    int rn;
    cout << "\nENTER ROLL NO. : ";
    cin >> rn;

    infile.open("Student.dat", ios::binary | ios::in);
    outfile.open("temp.dat", ios::binary | ios::out);
    if (!infile || !outfile) {
        cout << "\n\nError in opening file." << endl;
    }

    while (infile.read((char *)&st, sizeof(st))) {
        if (st.Roll_no != rn) {
            outfile.write((char *)&st, sizeof(st));
        }
    }
    infile.close();
    outfile.close();

    remove("Student.dat");
    rename("temp.dat", "Student.dat");
    cout << "\n\nRecord deleted successfully if it existed." << endl;
};



int main() {
    int i;
    system("cls");
    do{
        cout << "\n---------------------------------------------";
        cout << "\n          STUDENT MANAGEMENT SYSTEM          ";
        cout << "\n---------------------------------------------\n";
        cout << "\n\n01. ADD STUDENT RECORD";
        cout << "\n\n02. DISPLAY A RECORD";
        cout << "\n\n03. MODIFY A RECORD";
        cout << "\n\n04. DISPLAY ALL RECORDS";
        cout << "\n\n05. DELETE A RECORD";
        cout << "\n\n06. EXIT FROM PROGRAM";
        cout << "\n\n\nSELECT THE OPTION: ";
        cin>>i;
        system("cls");
        switch (i){
            case 1:
                Add_data();
                break;
            case 2:
                Search_data();
                break;
            case 3:
                Edit_data();
                break;
            case 4:
                Display_all_data();
                break;
            case 5:
                Delete_an_data();
                break;
            default:
            cout << "Hi !  www.github.com/ErPriyaranajan ";
        };
        cin.clear();
        fflush(stdin);
        cin.get();
        system("cls");
    }while(i!=6);
    return 0;
}
