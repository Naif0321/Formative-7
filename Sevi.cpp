#include <iostream>
#include <string>

using namespace std;

struct Patient {
    string name;
    int age;
    string diagnosis;
    double height;
    double weight;
    Patient* next;
};

struct Medicine {
    string name;
    int quantity;
    string expirationDate; 
    Medicine* next;
};

void addPatient(Patient*& head, const string& name, int age, const string& diagnosis, double height, double weight) {
    Patient* newPatient = new Patient;
    newPatient->name = name;
    newPatient->age = age;
    newPatient->diagnosis = diagnosis;
    newPatient->height = height;
    newPatient->weight = weight;
    newPatient->next = nullptr;

    if (head == nullptr) {
        head = newPatient;
    }
    else {
        Patient* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newPatient;
    }
}

void displayPatients(Patient* head) {
    Patient* temp = head;
    while (temp != nullptr) {
        cout << "\nName: " << temp->name << ", Age: " << temp->age << ", Height: " << temp->height << " cm, Weight: " << temp->weight << " kg, Diagnosis: " << temp->diagnosis << endl;
        temp = temp->next;
    }
}

void displayPatientsWithNumbers(Patient* head) {
    Patient* temp = head;
    int count = 1;
    while (temp != nullptr) {
        cout << count << ". Name: " << endl;
        temp = temp->next;
        count++;
    }
}

void viewDiagnosis(Patient* head, const string& name) {
    Patient* temp = head;
    while (temp != nullptr) {
        if (temp->name == name) {
            cout << "Diagnosis for " << name << ": " << temp->diagnosis << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Patient " << name << " not found." << endl;
}

void updatePatient(Patient* head, int updateChoice) {
    Patient* temp = head;
    int count = 1;
    while (temp != nullptr) {
        if (count == updateChoice) {
            cout << "\nUpdate patient's name: ";
            cin >> temp->name;
            cout << "Update patient's age: ";
            cin >> temp->age;
            cout << "Update patient's height (in cm): ";
            cin >> temp->height;
            cout << "Update patient's weight (in kg): ";
            cin >> temp->weight;
            cout << "Update patient's diagnosis: ";
            cin.ignore();
            getline(cin, temp->diagnosis);
            cout << "\nPatient updated successfully." << endl;
            return;
        }
        temp = temp->next;
        count++;
    }
    cout << "Invalid choice. No patient found with the provided number." << endl;
}

void removePatient(Patient*& head, const string& name) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->name == name) {
        Patient* temp = head;
        head = head->next;
        delete temp;
        cout << "Patient " << name << " removed successfully." << endl;
        return;
    }
    Patient* prev = head;
    Patient* curr = head->next;
    while (curr != nullptr) {
        if (curr->name == name) {
            prev->next = curr->next;
            delete curr;
            cout << "Patient " << name << " removed successfully." << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Patient " << name << " not found." << endl;
}

void deletePatients(Patient* head) {
    Patient* current = head;
    while (current != nullptr) {
        Patient* next = current->next;
        delete current;
        current = next;
    }
}

void addMedicine(Medicine*& head, const string& name, int quantity, const string& expirationDate) {
    Medicine* newItem = new Medicine;
    newItem->name = name;
    newItem->quantity = quantity;
    newItem->expirationDate = expirationDate;
    newItem->next = nullptr;

    if (head == nullptr) {
        head = newItem;
    }
    else {
        Medicine* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
}

void useMedicine(Medicine*& head, const string& name, int quantity) {
    Medicine* temp = head;
    while (temp != nullptr) {
        if (temp->name == name) {
            temp->quantity -= quantity;
            if (temp->quantity < 0) {
                temp->quantity = 0;
            }
            return;
        }
        temp = temp->next;
    }
}

void viewMedicineInventory(Medicine* head) {
    Medicine* temp = head;
    cout << "Medicine Inventory:" << endl;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << ", Quantity: " << temp->quantity << ", Expiration Date: " << temp->expirationDate << endl;
        temp = temp->next;
    }
}

void removeExpiredMedicine(Medicine*& head, const string& currentDate) {
    if (head == nullptr) {
        cout << "Medicine inventory is empty." << endl;
        return;
    }

    Medicine* prev = nullptr;
    Medicine* curr = head;

    while (curr != nullptr) {
        if (curr->expirationDate == currentDate) {
            if (prev == nullptr) {
                head = curr->next;
                delete curr;
                curr = head;
            }
            else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            cout << "Expired medicine removed successfully." << endl;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
}

int main() {
    Patient* patientHead = nullptr;
    Medicine* medicineInventoryHead = nullptr;
    string name, diagnosis, medicineName, expirationDate;
    int age, quantity;
    double height, weight;
    string currentDate;
    int updateChoice;

    cout << "Enter current date (Month Date Year format, e.g., January 20 2024): ";
    getline(cin, currentDate);

    char choice;
    do {
        system("cls"); 
        cout << "\n==================================";
        cout << "         \n\tMenu:" << endl;
        cout << "1. Add a patient record" << endl;
        cout << "2. View patient records" << endl;
        cout << "3. Update patient record" << endl;
        cout << "4. Remove patient record" << endl;
        cout << "5. View diagnosis" << endl;
        cout << "6. Add medicine to inventory" << endl;
        cout << "7. Use medicine from inventory" << endl;
        cout << "8. View medicine inventory" << endl;
        cout << "9. Remove expired medicine" << endl;
        cout << "0. Exit" << endl;
        cout << "==================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            system("cls");
            cout << "\n\n*****************************";
            cout << "\nEnter patient's name: ";
            cin >> name;
            cout << "\nEnter patient's age: ";
            cin >> age;
            cout << "\nEnter height (in cm): ";
            cin >> height;
            cout << "\nEnter weight (in kg): ";
            cin >> weight;
            cout << "\nEnter diagnosis: ";
            cin.ignore();
            getline(cin, diagnosis);
            cout << "\n*****************************\n";

            addPatient(patientHead, name, age, diagnosis, height, weight);
            break;
        }
        case '2': {
            system("cls"); 
            cout << "\n\n*****************************";
            displayPatients(patientHead);
            cout << "\n*****************************\n";
            break;
        }
        case '3': {
            system("cls"); 
            cout << "\n\n*****************************";
            cout << "\nChoose the patient to update:\n";
            displayPatientsWithNumbers(patientHead);
            cout << "Enter the number corresponding to the patient: ";
            cin >> updateChoice;
            updatePatient(patientHead, updateChoice);
            cout << "\n*****************************\n";
            break;
        }
        case '4': {
            system("cls"); 
            cout << "\n\n*****************************";
            cout << "\nEnter patient's name to remove: ";
            cin >> name;
            removePatient(patientHead, name);
            cout << "\n*****************************\n";
            break;
        }
        case '5': {
            system("cls");
            cout << "\n\n*****************************";
            cout << "\nEnter patient's name: ";
            cin >> name;
            viewDiagnosis(patientHead, name);
            cout << "\n*****************************\n";
            break;
        }
        case '6': {
            system("cls"); 
            cout << "\n\n*****************************";
            cout << "\nEnter medicine name: ";
            cin >> medicineName;
            cout << "\nEnter quantity: ";
            cin >> quantity;
            cout << "\nEnter expiration date (Month Date Year format, e.g., January 20 2024): ";
            cin.ignore();
            getline(cin, expirationDate);
            addMedicine(medicineInventoryHead, medicineName, quantity, expirationDate);
            cout << "\nMedicine added to inventory.\n";
            cout << "\n*****************************\n";
            break;
        }
        case '7': {
            system("cls");
            cout << "\n\n*****************************";
            cout << "\nEnter medicine name: ";
            cin >> medicineName;
            cout << "\nEnter quantity to use: ";
            cin >> quantity;
            useMedicine(medicineInventoryHead, medicineName, quantity);
            cout << "\nMedicine used from inventory.\n";
            cout << "\n*****************************\n";
            break;
        }
        case '8': {
            system("cls");
            cout << "\n\n*****************************";
            viewMedicineInventory(medicineInventoryHead);
            cout << "\n*****************************\n";
            break;
        }
        case '9': {
            system("cls"); 
            removeExpiredMedicine(medicineInventoryHead, currentDate);
            break;
        }
        case '0':
            deletePatients(patientHead);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        system("pause"); 
    } while (choice != '0');

    return 0;
}
