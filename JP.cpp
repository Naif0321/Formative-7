#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Student {
    int studentNumber;
    string fullName;
    string address;
    string birthday;
    string degree;
    char gender;
    int year;
    Student* next;
};

struct Teacher
{
    int teacherNumber;
    string tFullName;
    string tAddress;
    string tBirthday;
    string tDegree;
    char tGender;
    int tYear;
    Teacher* next;
};

struct NonAcademic
{
    int employeeNumber;
    string eFullName;
    string eAddress;
    string eBirthday;
    char eGender;
    string department;
    int eYear;
    NonAcademic* next;
};

void displayMenu();
void addRecord(Student*& head);
void viewSpecificRecord(const Student* head);
void viewAllRecord(const Student* head);
void deleteSpecificRecord(Student*& head);
void saveStudentRecord(const Student* head);
void loadRecord(Student*& head);

void addRecordTeacher(Teacher*& head);
void viewSpecificRecordTeacher(const Teacher* head);
void viewAllRecordTeacher(const Teacher* head);
void deleteSpecificRecordTeacher(Teacher*& head);
void saveRecordTeacher(const Teacher* head);
void loadRecordTeacher(Teacher*& head);

void addRecordEmployee(NonAcademic*& head);
void viewSpecificRecordEmployee(const NonAcademic* head);
void viewAllRecordEmployee(const NonAcademic* head);
void deleteSpecificRecordEmployee(NonAcademic*& head);
void saveRecordEmployee(const NonAcademic* head);
void loadRecordEmployee(NonAcademic*& head);

int main() {
    Student* headStudent = NULL;
    Teacher* headTeacher = NULL;
    NonAcademic* headNonAcademic = NULL;

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        system("cls");

        switch (choice) {
        case 1:
            addRecord(headStudent);
            break;
        case 2:
            viewSpecificRecord(headStudent);
            break;
        case 3:
            viewAllRecord(headStudent);
            break;
        case 4:
            deleteSpecificRecord(headStudent);
            break;
        case 5:
            saveStudentRecord(headStudent);
            break;
        case 6:
            addRecordTeacher(headTeacher);
            break;
        case 7:
            viewSpecificRecordTeacher(headTeacher);
            break;
        case 8:
            viewAllRecordTeacher(headTeacher);
            break;
        case 9:
            deleteSpecificRecordTeacher(headTeacher);
            break;
        case 10:
            saveRecordTeacher(headTeacher);
            break;
        case 11:
            addRecordEmployee(headNonAcademic);
            break;
        case 12:
            viewSpecificRecordEmployee(headNonAcademic);
            break;
        case 13:
            viewAllRecordEmployee(headNonAcademic);
            break;
        case 14:
            deleteSpecificRecordEmployee(headNonAcademic);
            break;
        case 15:
            saveRecordEmployee(headNonAcademic);
            break;
        case 16:
            exit(0);
        default:
            cout << "Invalid choice. Please select another category";
        }
    } while (choice != 16);

    return 0;
}

void displayMenu() {
    cout << "Select your preferred category" << endl;
    cout << "1. Add Student Record" << endl;
    cout << "2. View Specific Student's Record" << endl;
    cout << "3. View All Student Record" << endl;
    cout << "4. Delete Specific Student's Record" << endl;
    cout << "5. Save Student's Record\n" << endl;
    cout << "6. Add Teachers' Record" << endl;
    cout << "7. View Specific Teachers's Record" << endl;
    cout << "8. View All Teachers' Record" << endl;
    cout << "9. Delete Specific Teachers's Record" << endl;
    cout << "10. Save Teachers' Record\n" << endl;
    cout << "11. Add Employees' Record" << endl;
    cout << "12. View Specific Employees's Record" << endl;
    cout << "13. View All Employees' Record" << endl;
    cout << "14. Delete Specific Employees's Record" << endl;
    cout << "15. Save Employees' Record" << endl;
    cout << "16. Exit" << endl;
    cout << "Input your choice : ";
}

void addRecord(Student*& head) {
    Student* newStudent = new Student;

    cout << "Student Number : ";
    cin >> newStudent->studentNumber;
    cin.ignore();

    cout << "Full Name : ";
    getline(cin, newStudent->fullName);

    cout << "Gender (M/F) : ";
    cin >> newStudent->gender;

    cout << "Birthday (YYYY-MM-DD) : ";
    cin >> newStudent->birthday;
    cin.ignore();

    cout << "Address : ";
    getline(cin, newStudent->address);

    cout << "Degree/Program : ";
    getline(cin, newStudent->degree);

    cout << "Year Level : ";
    cin >> newStudent->year;

    newStudent->next = head;
    head = newStudent;

    cout << "Recorded Successfully" << endl;

    cin.ignore();
    system("cls");
}

void viewSpecificRecord(const Student* head) {
    int searchId;
    const Student* current = head;
    cout << "Input the Student's Student Number : ";
    cin >> searchId;

    while (current != NULL) {
        if (current->studentNumber == searchId) {
            cout << "Record Found" << endl;
            cout << "Student Number : " << current->studentNumber << endl;
            cout << "Full Name : " << current->fullName << endl;
            cout << "Gender : " << current->gender << endl;
            cout << "Birthday : " << current->birthday << endl;
            cout << "Address : " << current->address << endl;
            cout << "Degree/Program : " << current->degree << endl;
            cout << "Year Level : " << current->year << endl;
            cin.ignore();
            system("cls");
            return;
        }
        current = current->next;
    }
    cout << "Record not found!" << endl;
    cin.ignore();
    system("cls");
}

void viewAllRecord(const Student* head) {
    const Student* current = head;
    cout << "ALL RECORDS" << endl;
    while (current != NULL) {
        cout << "Record Found" << endl;
        cout << "Student Number : " << current->studentNumber << endl;
        cout << "Full Name : " << current->fullName << endl;
        cout << "Gender : " << current->gender << endl;
        cout << "Birthday : " << current->birthday << endl;
        cout << "Address : " << current->address << endl;
        cout << "Degree/Program : " << current->degree << endl;
        cout << "Year Level : " << current->year << endl;
        cout << endl;
        current = current->next;
    }
    cin.ignore();
    system("cls");
}

void deleteSpecificRecord(Student*& head) {
    int deleteId;
    Student* current = head;
    Student* prev = NULL;
    cout << "Input the Student's Student Number : ";
    cin >> deleteId;

    while (current != NULL) {
        if (current->studentNumber == deleteId) {
            if (prev == NULL) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            cout << "Student record deleted.." << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Record Not Found" << endl;
    cin.ignore();
    system("cls");
}

void saveStudentRecord(const Student* head) {
    ofstream outFile("students.txt");
    if (outFile.is_open()) {
        const Student* current = head;
        while (current != NULL) {
            outFile << current->studentNumber << endl
                << current->fullName << endl
                << current->gender << endl
                << current->birthday << endl
                << current->address << endl
                << current->degree << endl
                << current->year << endl;
            current = current->next;
        }
        outFile.close();
        cout << "Record Saved" << endl;
    }
    else {
        cout << "Unable to save records" << endl;
    }
}

void loadRecord(Student*& head) {
    ifstream inFile("students.txt");
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            Student* newStudent = new Student;
            inFile >> newStudent->studentNumber;
            inFile.ignore();
            getline(inFile, newStudent->fullName);
            inFile >> newStudent->gender;
            inFile.ignore();
            getline(inFile, newStudent->birthday);
            getline(inFile, newStudent->address);
            getline(inFile, newStudent->degree);
            inFile >> newStudent->year;
            inFile.ignore();
            newStudent->next = head;
            head = newStudent;
        }
        inFile.close();
        cout << "Records loaded successfully" << endl;
    }
    else {
        cout << "Unable to open file of the records" << endl;
    }
}

void addRecordTeacher(Teacher*& head) {
    Teacher* newTeacher = new Teacher;

    cout << "Teacher Number : ";
    cin >> newTeacher->teacherNumber;
    cin.ignore();

    cout << "Full Name : ";
    getline(cin, newTeacher->tFullName);

    cout << "Gender (M/F) : ";
    cin >> newTeacher->tGender;

    cout << "Birthday (YYYY-MM-DD) : ";
    cin >> newTeacher->tBirthday;
    cin.ignore();

    cout << "Address : ";
    getline(cin, newTeacher->tAddress);

    cout << "Degree/Program : ";
    getline(cin, newTeacher->tDegree);

    cout << "Number of Years in Service : ";
    cin >> newTeacher->tYear;

    newTeacher->next = head;
    head = newTeacher;

    cout << "Recorded Successfully" << endl;

    cin.ignore();
    system("cls");
}

void viewSpecificRecordTeacher(const Teacher* head) {
    int searchTeacherId;
    const Teacher* current = head;
    cout << "Input the Teacher's Number : ";
    cin >> searchTeacherId;

    while (current != NULL) {
        if (current->teacherNumber == searchTeacherId) {
            cout << "Record Found" << endl;
            cout << "Teacher Number : " << current->teacherNumber << endl;
            cout << "Full Name : " << current->tFullName << endl;
            cout << "Gender : " << current->tGender << endl;
            cout << "Birthday : " << current->tBirthday << endl;
            cout << "Address : " << current->tAddress << endl;
            cout << "Degree/Program : " << current->tDegree << endl;
            cout << "Number of Years in Service : " << current->tYear << endl;
            cin.ignore();
            system("cls");
            return;
        }
        current = current->next;
    }
    cout << "Record not found!" << endl;
    cin.ignore();
    system("cls");
}

void viewAllRecordTeacher(const Teacher* head) {
    const Teacher* current = head;
    cout << "ALL RECORDS" << endl;
    while (current != NULL) {
        cout << "Record Found" << endl;
        cout << "Teacher Number : " << current->teacherNumber << endl;
        cout << "Full Name : " << current->tFullName << endl;
        cout << "Gender : " << current->tGender << endl;
        cout << "Birthday : " << current->tBirthday << endl;
        cout << "Address : " << current->tAddress << endl;
        cout << "Degree/Program : " << current->tDegree << endl;
        cout << "Number of Years in Service : " << current->tYear << endl;
        cout << endl;
        current = current->next;
    }
    cin.ignore();
    system("cls");
}

void deleteSpecificRecordTeacher(Teacher*& head) {
    int deleteTeacherId;
    Teacher* current = head;
    Teacher* prev = NULL;
    cout << "Input the Teacher's Number : ";
    cin >> deleteTeacherId;

    while (current != NULL) {
        if (current->teacherNumber == deleteTeacherId) {
            if (prev == NULL) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            cout << "Teacher record deleted.." << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Record Not Found" << endl;
    cin.ignore();
    system("cls");
}

void saveRecordTeacher(const Teacher* head) {
    ofstream outFile("teachers.txt");
    if (outFile.is_open()) {
        const Teacher* current = head;
        while (current != NULL) {
            outFile << current->teacherNumber << endl
                << current->tFullName << endl
                << current->tGender << endl
                << current->tBirthday << endl
                << current->tAddress << endl
                << current->tDegree << endl
                << current->tYear << endl;
            current = current->next;
        }
        outFile.close();
        cout << "Record Saved" << endl;
    }
    else {
        cout << "Unable to save records" << endl;
    }
}

void loadRecordTeacher(Teacher*& head) {
    ifstream inFile("teachers.txt");
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            Teacher* newTeacher = new Teacher;
            inFile >> newTeacher->teacherNumber;
            inFile.ignore();
            getline(inFile, newTeacher->tFullName);
            inFile >> newTeacher->tGender;
            inFile.ignore();
            getline(inFile, newTeacher->tBirthday);
            getline(inFile, newTeacher->tAddress);
            getline(inFile, newTeacher->tDegree);
            inFile >> newTeacher->tYear;
            inFile.ignore();
            newTeacher->next = head;
            head = newTeacher;
        }
        inFile.close();
        cout << "Records loaded successfully" << endl;
    }
    else {
        cout << "Unable to open file of the records" << endl;
    }
}


void addRecordEmployee(NonAcademic*& head) {
    NonAcademic* newEmployee = new NonAcademic;

    cout << "Employee Number : ";
    cin >> newEmployee->employeeNumber;
    cin.ignore();

    cout << "Full Name : ";
    getline(cin, newEmployee->eFullName);

    cout << "Gender (M/F) : ";
    cin >> newEmployee->eGender;

    cout << "Birthday (YYYY-MM-DD) : ";
    cin >> newEmployee->eBirthday;
    cin.ignore();

    cout << "Address : ";
    getline(cin, newEmployee->eAddress);

    cout << "Department : ";
    getline(cin, newEmployee->department);

    cout << "Number of Years in Service : ";
    cin >> newEmployee->eYear;

    newEmployee->next = head;
    head = newEmployee;

    cout << "Recorded Successfully" << endl;

    cin.ignore();
    system("cls");
}

void viewSpecificRecordEmployee(const NonAcademic* head) {
    int searchEmployeeId;
    const NonAcademic* current = head;
    cout << "Input the Employee's Number : ";
    cin >> searchEmployeeId;

    while (current != NULL) {
        if (current->employeeNumber == searchEmployeeId) {
            cout << "Record Found" << endl;
            cout << "Employee Number : " << current->employeeNumber << endl;
            cout << "Full Name : " << current->eFullName << endl;
            cout << "Gender : " << current->eGender << endl;
            cout << "Birthday : " << current->eBirthday << endl;
            cout << "Address : " << current->eAddress << endl;
            cout << "Department : " << current->department << endl;
            cout << "Number of Years in Service : " << current->eYear << endl;
            cin.ignore();
            system("cls");
            return;
        }
        current = current->next;
    }
    cout << "Record not found!" << endl;
    cin.ignore();
    system("cls");
}

void viewAllRecordEmployee(const NonAcademic* head) {
    const NonAcademic* current = head;
    cout << "ALL RECORDS" << endl;
    while (current != NULL) {
        cout << "Record Found" << endl;
        cout << "Employee Number : " << current->employeeNumber << endl;
        cout << "Full Name : " << current->eFullName << endl;
        cout << "Gender : " << current->eGender << endl;
        cout << "Birthday : " << current->eBirthday << endl;
        cout << "Address : " << current->eAddress << endl;
        cout << "Department : " << current->department << endl;
        cout << "Number of Years in Service : " << current->eYear << endl;
        cout << endl;
        current = current->next;
    }
    cin.ignore();
    system("cls");
}

void deleteSpecificRecordEmployee(NonAcademic*& head) {
    int deleteEmployeeId;
    NonAcademic* current = head;
    NonAcademic* prev = NULL;
    cout << "Input the Employee's Number : ";
    cin >> deleteEmployeeId;

    while (current != NULL) {
        if (current->employeeNumber == deleteEmployeeId) {
            if (prev == NULL) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            cout << "Employee record deleted.." << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Record Not Found" << endl;
    cin.ignore();
    system("cls");
}

void saveRecordEmployee(const NonAcademic* head) {
    ofstream outFile("employees.txt");
    if (outFile.is_open()) {
        const NonAcademic* current = head;
        while (current != NULL) {
            outFile << current->employeeNumber << endl
                << current->eFullName << endl
                << current->eGender << endl
                << current->eBirthday << endl
                << current->eAddress << endl
                << current->department << endl
                << current->eYear << endl;
            current = current->next;
        }
        outFile.close();
        cout << "Record Saved" << endl;
    }
    else {
        cout << "Unable to save records" << endl;
    }
}

void loadRecordEmployee(NonAcademic*& head) {
    ifstream inFile("employees.txt");
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            NonAcademic* newEmployee = new NonAcademic;
            inFile >> newEmployee->employeeNumber;
            inFile.ignore();
            getline(inFile, newEmployee->eFullName);
            inFile >> newEmployee->eGender;
            inFile.ignore();
            getline(inFile, newEmployee->eBirthday);
            getline(inFile, newEmployee->eAddress);
            getline(inFile, newEmployee->department);
            inFile >> newEmployee->eYear;
            inFile.ignore();
            newEmployee->next = head;
            head = newEmployee;
        }
        inFile.close();
        cout << "Records loaded successfully" << endl;
    }
    else {
        cout << "Unable to open file of the records" << endl;
    }
}
