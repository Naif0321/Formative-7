#include <iostream>
#include <string>
using namespace std;

struct TravelAgency {

	string travelerName, productName, locationName, dateOfArrival, dateOfDeparture;
	int travelerAge, productQuantity, productNumber, locationNumber, travelerWeight, travelerHeight, ticketPrice, productPrice;

	void TravelerData() {
		cout << "\n-----------------------\n"
			<< "Traveler name: " << travelerName << "\n"
			<< "Traveler age: " << travelerAge << "\n"
			<< "Traveler height: " << travelerHeight << "\n"
			<< "Traveler weight: " << travelerWeight << "\n"
			<< "-----------------------\n";
	}
};

struct NodeTraveler {
	TravelAgency traveler;
	NodeTraveler* next;
};

struct NodeProducts {
	TravelAgency products;
	NodeProducts* next;
};

struct NodeLocation {
	TravelAgency location;
	NodeLocation* next;
};

int ChooseRole();
int EmployeeMainMenu();
int TravelerMainMenu();
int BuyTicketChoice();
void AddTravelerData(TravelAgency&);
void AddTravelerRecord(TravelAgency&, NodeTraveler*&, NodeTraveler*&);
void ViewRecord(NodeTraveler*&);
void AddProductData(TravelAgency&);
void ClearTravelerRecord(NodeTraveler*&);
void AddProductRecord(TravelAgency&, NodeProducts*&, NodeProducts*&);
void ViewProducts(NodeProducts*&);
void BuyProducts(TravelAgency&, NodeProducts*&, NodeProducts*&);
void AddTravelLocation(TravelAgency&);
void AddTravelLocationRecord(TravelAgency&, NodeLocation*&, NodeLocation*&);
void ViewTravelLocation(NodeLocation*&);
void BuyTravelTicket(TravelAgency&, NodeLocation*&, NodeLocation*&);

int main()
{
	TravelAgency traveler, product, location;
	NodeTraveler* headTraveler = NULL, * tailTraveler = NULL;
	NodeProducts* headProduct = NULL, * tailProduct = NULL;
	NodeLocation* headLocation = NULL, * tailLocation = NULL;
	string employeeName, employeePassword;
	int employeeChoice, travelerChoice, pickRole = 0;

	do {
		pickRole = ChooseRole();

		if (pickRole == 1) {

			do {
				do {
					travelerChoice = TravelerMainMenu();
					switch (travelerChoice)
					{
					case 1:
						ViewProducts(headProduct);
						break;
					case 2:
						ViewProducts(headProduct);
						BuyProducts(product, headProduct, tailProduct);
						break;
					case 3:
						ViewTravelLocation(headLocation);
						break;
					case 4:
						ViewTravelLocation(headLocation);
						BuyTravelTicket(location, headLocation, tailLocation);
						break;
					case 5:
						cout << "Returning to main menu\n";
						system("pause");
						system("CLS");
						break;
					case 0:
						cout << "Thank you for using the program! \n";
						system("pause");
						exit(0);
					default:
						cout << "Incorrect choice\n";
						system("pause");
						system("CLS");
						break;
					}
				} while (travelerChoice != 5);

			} while (travelerChoice >= 1 && travelerChoice <= 4);
		}


		else if (pickRole == 2) {

			do {
				system("CLS");
				cout << "Enter employee name: "; cin >> employeeName;
				cout << "Enter employee password: "; cin >> employeePassword;

			} while (employeeName != "Adrian" || employeePassword != "IloveyousomuchZyrah");

			system("CLS");
			do {
				do {
					employeeChoice = EmployeeMainMenu();
					switch (employeeChoice)
					{
					case 1:
						AddTravelerData(traveler);
						AddTravelerRecord(traveler, headTraveler, tailTraveler);
						break;
					case 2:
						ViewRecord(headTraveler);
						break;
					case 3:
						AddProductData(product);
						AddProductRecord(product, headProduct, tailProduct);
						break;
					case 4:
						ViewProducts(headProduct);
						break;
					case 5:
						ClearTravelerRecord(headTraveler);
						break;
					case 6:
						AddTravelLocation(location);
						AddTravelLocationRecord(location, headLocation, tailLocation);
						break;
					case 7:
						ViewTravelLocation(headLocation);
						break;
					case 8:
						cout << "Returning to main menu\n";
						system("pause");
						system("CLS");
						break;
					case 0:
						cout << "Thank you for using the program! \n";
						system("pause");
						exit(0);
					default:
						cout << "Incorrect choice\n";
						system("pause");
						system("CLS");
						break;
					}

				} while (employeeChoice != 8);

			} while (employeeChoice >= 1 && employeeChoice <= 7);
		}
		else if (pickRole == 0) {
			cout << "Thank you for using the program! \n";
			system("pause");
			exit(0);
		}

	} while (true);
	return 0;
}


int ChooseRole() {
	int roleChoice;
	do {
		cout << "---------------------------------------\n"
			<< "|             Travel Agency           |\n"
			<< "---------------------------------------\n"
			<< "| 1 - Traveler      | 2 - Employee    |\n"
			<< "|          0 - Exit Program           |\n"
			<< "---------------------------------------\n"
			<< "\n Enter choice here: "; cin >> roleChoice;

		system("CLS");

		if (roleChoice == 0) {
			cout << "Thank you!\n";
			system("pause");
			system("CLS");
		}

	} while (roleChoice < 0 || roleChoice > 2);

	return roleChoice;
}

int EmployeeMainMenu() {

	int employeeMenuChoice;

	cout << "==============================================\n"
		<< "                 Employee Menu\n"
		<< "==============================================\n"
		<< "1. Add Traveler record\n"
		<< "2. View Traveler records\n"
		<< "3. Add product list\n"
		<< "4. View product list\n"
		<< "5. Clear Traveler records\n"
		<< "6. Add Travel location\n"
		<< "7. View travel location\n"
		<< "8. Go back to choose role\n"
		<< "0. Exit\n"
		<< "\nEnter choice here: ";
	cin >> employeeMenuChoice;

	system("CLS");

	return employeeMenuChoice;
}

int TravelerMainMenu() {
	int travelerMenuChoice;

	cout << "==============================================\n"
		<< "                Traveler Menu\n"
		<< "==============================================\n"
		<< "1. View product list\n"
		<< "2. Buy products\n"
		<< "3. View travel locations\n"
		<< "4. Buy travel tickets\n"
		<< "5. Go back to choose role\n"
		<< "0. Exit\n"
		<< "\nEnter choice here: ";
	cin >> travelerMenuChoice;

	system("CLS");

	return travelerMenuChoice;
}

int BuyTicketChoice()
{
	int ticketChoice;

	cout << "Would you like to buy the ticket ? \n"
		<< "|  1 - yes       |  2 - no        |\n"
		<< "\nEnter choice here: ";
	cin >> ticketChoice;

	return ticketChoice;
}

void AddTravelerData(TravelAgency& travelerInfo) {
	cout << "Enter Traveler name: ";
	cin >> travelerInfo.travelerName;
	cout << "Enter Traveler age: ";
	cin >> travelerInfo.travelerAge;
	cout << "Enter Traveler height: ";
	cin >> travelerInfo.travelerHeight;
	cout << "Enter Traveler weight: ";
	cin >> travelerInfo.travelerWeight;
	cout << "\n";
}

void AddTravelerRecord(TravelAgency& travelerInfo, NodeTraveler*& headTraveler, NodeTraveler*& tailTraveler) {
	NodeTraveler* temp = new NodeTraveler;
	temp->traveler = travelerInfo;
	temp->next = NULL;

	if (!headTraveler)
	{
		headTraveler = temp;
	}
	else
		tailTraveler->next = temp;
	tailTraveler = temp;
	system("pause");
	system("CLS");
}

void ViewRecord(NodeTraveler*& headTraveler) {
	NodeTraveler* temp = headTraveler;

	if (!headTraveler) {
		cout << "No traveler info yet!";
	}
	else {
		while (temp)
		{
			temp->traveler.TravelerData();
			temp = temp->next;
		}

	}
	cout << "\n";
	system("pause");
	system("CLS");
}

void ClearTravelerRecord(NodeTraveler*& headTraveler)
{
	NodeTraveler* temp = nullptr, * current = headTraveler;

	if (!headTraveler)
		cout << "No Traveler Records Yet!\n\n";
	else
	{
		while (current != nullptr)
		{
			temp = current->next;
			delete current;
			current = temp;
		}
		headTraveler = nullptr;

		cout << "Traveler Record Cleared!\n";
	}
	cout << "\n";
	system("pause");
	system("cls");
}

void AddProductData(TravelAgency& productInfo) {
	cout << "Enter product number: ";
	cin >> productInfo.productNumber;
	cout << "Enter product name: ";
	cin >> productInfo.productName;
	cout << "Enter product quantity: ";
	cin >> productInfo.productQuantity;
	cout << "Enter product price: ";
	cin >> productInfo.productPrice;
	cout << "\n";
}

void AddProductRecord(TravelAgency& productInfo, NodeProducts*& headProduct, NodeProducts*& tailProduct) {
	NodeProducts* temp = new NodeProducts;
	temp->products = productInfo;
	temp->next = NULL;

	if (!headProduct)
	{
		headProduct = temp;
	}
	else
		tailProduct->next = temp;
	tailProduct = temp;
	system("pause");
	system("CLS");
}

void ViewProducts(NodeProducts*& headProduct) {
	NodeProducts* temp = headProduct;

	if (!headProduct) {
		cout << "No products yet!";
	}
	else {
		while (temp)
		{
			cout << "\n---------------------------------\n"
				<< "Product number: " << temp->products.productNumber << "\n"
				<< "Product name: " << temp->products.productName << "\n"
				<< "Product quantity: " << temp->products.productQuantity << "\n"
				<< "Product price: " << temp->products.productPrice << "\n"
				<< "---------------------------------\n";
			temp = temp->next;
		}
	}
	cout << "\n";
	system("pause");
	system("CLS");
}

void BuyProducts(TravelAgency& productInfo, NodeProducts*& headProduct, NodeProducts*& tailProduct) {
	NodeProducts* current = headProduct;
	int chooseProducts, chooseProductQuantity, cashAmount, totalChange;
	double totalAmount = 0;

	cout << "\n-----------------------\n"
		<< "Enter product number: "
		<< "\n-----------------------\n";
	cin >> chooseProducts;


	while (current != nullptr && current->products.productNumber != chooseProducts) {
		current = current->next;
	}

	if (current == nullptr) {
		cout << "Product not found!\n";
		return;
	}

	cout << "\n---------------------------------\n"
		<< "Chosen product details:\n\n"
		<< "Product Name: " << current->products.productName << "\n"
		<< "Product Quantity: " << current->products.productQuantity << "\n"
		<< "Product Price: " << current->products.productPrice << "\n"
		<< "---------------------------------\n";

	cout << "\n-----------------------\n"
		<< "Choose how many quantity: "
		<< "\n-----------------------\n";
	cin >> chooseProductQuantity;


	if (chooseProductQuantity > current->products.productQuantity) {
		cout << "Not enough quantity available!\n";
	}
	else {
		current->products.productQuantity -= chooseProductQuantity;
		totalAmount = chooseProductQuantity * current->products.productPrice;
		cout << "Total amount for chosen products: " << totalAmount << "\n";
	}

	cout << "\n-----------------------\n" 
		<< "Enter your cash amount: "
		<< "\n-----------------------\n";
	cin >> cashAmount;

	if (cashAmount < totalAmount) {
		cout << "\nNot enough money\n";
	}
	else {
		totalChange = cashAmount - totalAmount;
		cout << "\nTotal change is: " << totalChange << "\n";
	}

	system("pause");
	system("CLS");
}

void AddTravelLocation(TravelAgency& locationInfo) {
	cout << "Enter location number: ";
	cin >> locationInfo.locationNumber;
	cout << "Enter location name: ";
	cin >> locationInfo.locationName;
	cout << "Enter date of arrival: ";
	cin >> locationInfo.dateOfArrival;
	cout << "Enter date of departure: ";
	cin >> locationInfo.dateOfDeparture;
	cout << "Enter ticket price: ";
	cin >> locationInfo.ticketPrice;
	cout << "\n";
}

void AddTravelLocationRecord(TravelAgency& locationInfo, NodeLocation*& headLocation, NodeLocation*& tailLocation) {
	NodeLocation* temp = new NodeLocation;
	temp->location = locationInfo;
	temp->next = NULL;

	if (!headLocation)
	{
		headLocation = temp;
	}
	else
		tailLocation->next = temp;
	tailLocation = temp;
	system("pause");
	system("CLS");
}

void ViewTravelLocation(NodeLocation*& headLocation) {
	NodeLocation* temp = headLocation;

	if (!headLocation) {
		cout << "No locations yet!";
	}
	else {
		while (temp)
		{
			cout << "\n---------------------------------\n"
				<< "Location number: " << temp->location.locationNumber << "\n"
				<< "Location name: " << temp->location.locationName << "\n"
				<< "Location date of arrival: " << temp->location.dateOfArrival << "\n"
				<< "Location date of departure: " << temp->location.dateOfDeparture << "\n"
				<< "Ticket price: " << temp->location.ticketPrice << "\n"
				<< "---------------------------------\n";
			temp = temp->next;
		}
	}
	cout << "\n";
	system("pause");
	system("CLS");
}

void BuyTravelTicket(TravelAgency& locationInfo, NodeLocation*& headLocation, NodeLocation*& tailLocation) {
	NodeLocation* current = headLocation;
	int chooseTicket, ticketChoice, cashAmount;
	double totalChange = 0;

	cout << "\n-----------------------\n"
		<< "Enter ticket number: "
		<< "\n-----------------------\n";
	cin >> chooseTicket;


	while (current != nullptr && current->location.locationNumber != chooseTicket) {
		current = current->next;
	}

	if (current == nullptr) {
		cout << "Product not found!\n";
		return;
	}

	cout << "\n---------------------------------\n" 
		<< "Chosen location details:\n\n"
		<< "Location Number: " << current->location.locationNumber << "\n"
		<< "Location Name: " << current->location.locationName << "\n"
		<< "Location date of arrival: " << current->location.dateOfArrival << "\n"
		<< "Location date of departure: " << current->location.dateOfDeparture << "\n"
		<< "Location price: " << current->location.ticketPrice
		<< "\n---------------------------------\n";

	ticketChoice = BuyTicketChoice();
	cout << "\n";

	if (ticketChoice == 1)
	{
		cout << "\n-----------------------\n"
			<< "Enter cash amount: "
			<< "\n-----------------------\n";
		cin >> cashAmount;

		if (cashAmount < current->location.ticketPrice) {
			cout << "\nNot enough money\n";
		}
		else {
			totalChange = cashAmount - current->location.ticketPrice;
			cout << "\nTotal change is: " << totalChange << "\n";
		}

		cout << "\n\n-----------------------\n" 
			<< "Ticket Submitted successfully!\n"
			<< "-----------------------\n";
	}

	else
	{
		cout << "Thank you!\n";
	}

	system("pause");
	system("CLS");
}
