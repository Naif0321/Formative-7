#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Customer
{
    int customerId;
    string fullName;
    string email;
    string nationality;
    string destination;
    int pax;
    Customer* next;
};

struct LandTransportation {
    string type;
    string destination;
    string vehicleInfo;
    double pricePerDay;
    LandTransportation* next;
};

void AddCustomer(Customer*& head) {
    Customer* newCustomer = new Customer;

    cout << "Enter Customer ID: ";
    cin >> newCustomer->customerId;
    cin.ignore();

    cout << "Enter Customer Name: ";
    getline(cin, newCustomer->fullName);

    cout << "Enter Contact Information: ";
    getline(cin, newCustomer->email);

    cout << "Enter Nationality: ";
    getline(cin, newCustomer->nationality);

    cout << "Enter Number of Individuals: ";
    cin >> newCustomer->pax;
    cin.ignore();

    cout << "Enter Destination: ";
    getline(cin, newCustomer->destination);

    newCustomer->next = head;
    head = newCustomer;

    cout << "Customer added successfully.\n";
}

void DisplayAllCustomers(const Customer* head) {
    cout << "All Customers:\n";
    const Customer* current = head;
    while (current != nullptr) {
        cout << "Customer ID: " << current->customerId << endl;
        cout << "Name: " << current->fullName << endl;
        cout << "Contact Information: " << current->email << endl;
        cout << "Nationality: " << current->nationality << endl;
        cout << "Number of individuals: " << current->pax << endl;
        cout << "Destination: " << current->destination << endl;
        cout << endl;
        current = current->next;
    }
}

void SaveCustomerData(const Customer* head) {
    ofstream outFile("customer_data.txt");
    if (outFile.is_open()) {
        const Customer* current = head;
        while (current != nullptr) {
            outFile << current->customerId << endl
                    << current->fullName << endl
                    << current->email << endl
                    << current->nationality << endl
                    << current->pax << endl
                    << current->destination << endl;
            current = current->next;
        }
        outFile.close();
        cout << "Customer data saved successfully.\n";
    } else {
        cout << "Unable to save customer data.\n";
    }
}

void LoadCustomerData(Customer*& head) {
    ifstream inFile("customer_data.txt");
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            Customer* newCustomer = new Customer;
            inFile >> newCustomer->customerId;
            inFile.ignore();
            getline(inFile, newCustomer->fullName);
            getline(inFile, newCustomer->email);
            getline(inFile, newCustomer->nationality);
            inFile >> newCustomer->pax;
            inFile.ignore();
            getline(inFile, newCustomer->destination);
            newCustomer->next = head;
            head = newCustomer;
        }
        inFile.close();
        cout << "Customer data loaded successfully.\n";
    } else {
        cout << "Unable to open customer data file.\n";
    }
}

void CustomerMenu() {
    int customerChoice;
    Customer* headCustomer = nullptr;
    LoadCustomerData(headCustomer);

    do {
        cout << "Customer Menu" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. View All Customers" << endl;
        cout << "3. Save Customer Data" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> customerChoice;

        switch (customerChoice) {
            case 1:
                AddCustomer(headCustomer);
                break;
            case 2:
                DisplayAllCustomers(headCustomer);
                break;
            case 3:
                SaveCustomerData(headCustomer);
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please select another option." << endl;
        }
    } while (customerChoice != 4);
}

void AddLandTransportation(LandTransportation*& head) {
    LandTransportation* newService = new LandTransportation;

    cout << "Enter Type of Transportation (e.g., Car Rental, Bus Tour, etc.): ";
    cin.ignore();
    getline(cin, newService->type);

    cout << "Enter Destination: ";
    getline(cin, newService->destination);

    cout << "Enter Vehicle Information: ";
    getline(cin, newService->vehicleInfo);

    cout << "Enter Price per Day: $";
    cin >> newService->pricePerDay;

    newService->next = head;
    head = newService;

    cout << "Land transportation service added successfully.\n";
}

void DisplayAllLandTransportation(const LandTransportation* head) {
    cout << "All Land Transportation Services:\n";
    const LandTransportation* current = head;
    while (current != nullptr) {
        cout << "Type of Transportation: " << current->type << endl;
        cout << "Destination: " << current->destination << endl;
        cout << "Vehicle Information: " << current->vehicleInfo << endl;
        cout << "Price per Day: $" << current->pricePerDay << endl;
        cout << endl;
        current = current->next;
    }
}

void SaveLandTransportationData(const LandTransportation* head) {
    ofstream outFile("land_transportation_data.txt");
    if (outFile.is_open()) {
        const LandTransportation* current = head;
        while (current != nullptr) {
            outFile << current->type << endl
                    << current->destination << endl
                    << current->vehicleInfo << endl
                    << current->pricePerDay << endl;
            current = current->next;
        }
        outFile.close();
        cout << "Land transportation data saved successfully.\n";
    } else {
        cout << "Unable to save land transportation data.\n";
    }
}

void LoadLandTransportationData(LandTransportation*& head) {
    ifstream inFile("land_transportation_data.txt");
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            LandTransportation* newService = new LandTransportation;
            inFile.ignore();
            getline(inFile, newService->type);
            getline(inFile, newService->destination);
            getline(inFile, newService->vehicleInfo);
            inFile >> newService->pricePerDay;
            inFile.ignore();
            newService->next = head;
            head = newService;
        }
        inFile.close();
        cout << "Land transportation data loaded successfully.\n";
    } else {
        cout << "Unable to open land transportation data file.\n";
    }
}

void LandTransportationMenu() {
    int landChoice;
    LandTransportation* landTransportationHead = nullptr;
    LoadLandTransportationData(landTransportationHead);

    do {
        cout << "Land Transportation Menu" << endl;
        cout << "1. Add Land Transportation Service" << endl;
        cout << "2. View All Land Transportation Services" << endl;
        cout << "3. Save Land Transportation Data" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> landChoice;

        switch (landChoice) {
            case 1:
                AddLandTransportation(landTransportationHead);
                break;
            case 2:
                DisplayAllLandTransportation(landTransportationHead);
                break;
            case 3:
                SaveLandTransportationData(landTransportationHead);
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please select another option." << endl;
        }
    } while (landChoice != 4);
}

int main() {
    int mainChoice;
    do {
        cout << "Main Menu" << endl;
        cout << "1. Customer Menu" << endl;
        cout << "2. Land Transportation Menu" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                CustomerMenu();
                break;
            case 2:
                LandTransportationMenu();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please select another option." << endl;
        }
    } while (mainChoice != 3);

    return 0;
}
