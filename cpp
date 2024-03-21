#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Player {
	string nickname;
	int age;
	double scores[5];
};
struct Node {
	Player player;
	Node* next;
};
	


	void GetPlayerinformation(Node*& head);
	void AddRecord(const Player& player, Node*& head);
	void ViewRecords(Node*& head);
	void ComputeAverage(Node*& head);
	void ShowMaxAverage(Node*& head);
	void ShowMinAverage(Node*& head);
	void SaveFile(Node*& head);
	void CloseFile(Node*& head);
	void ReadFile(Node*& head);

int main()
{
	Node* head = nullptr;
	int category;

		do {
			cout << "==============================================" << endl;
			cout << "\t\t MENU " << endl;
			cout << "==============================================" << endl;
			cout << "1. Add Record" << endl;
			cout << "2. View Player Records" << endl;
			cout << "3. Compute for the average" << endl;
			cout << "4. Show the player(s) who gets the max average." << endl;
			cout << "5. Show the player(s) who gets the min average." << endl;
			cout << "6. Save the file" << endl;
			cout << "7. Close the file" << endl;
			cout << "8. Read The File" << endl;
			cout << "9. Exit" << endl;
			cout << ":: ";
			cin >> category;

			switch (category)
			{
			case 1:
				GetPlayerinformation(head);
				system("cls");
				system("pause");
				break;
			case 2:
				ViewRecords(head);
				system("pause");

				break;
			case 3:
				ComputeAverage(head);
				system("pause");

				break;
			case 4:
				ShowMaxAverage(head);
				system("pause");

				break;
			case 5:
				ShowMinAverage(head);
				system("pause");

				break;
			case 6:
				SaveFile(head);
				system("pause");

				break;
			case 7:
				CloseFile(head);
				system("pause");

				break;
			case 8:
				ReadFile(head);
				system("pause");
				break;
			case 9:
				exit(0);
				break;
			default:
				break;
			}


		} while (category != 9);


		return 0;


}


void GetPlayerinformation(Node*& head)
{
	Player newPlayer;

	cout << "Enter Player Name : ";
	cin >> newPlayer.nickname;
	cout << "Age : ";
	cin >> newPlayer.age;
	cout << "Score 1 : ";
	cin >> newPlayer.scores[0];
	cout << "Score 2 : ";
	cin >> newPlayer.scores[1];
	cout << "Score 3 : ";
	cin >> newPlayer.scores[2];
	cout << "Score 4 : ";
	cin >> newPlayer.scores[3];
	cout << "Score 5 : ";
	cin >> newPlayer.scores[4];
	AddRecord(newPlayer, head);
}
void AddRecord(const Player& player, Node*& head) {
	Node* newNode = new Node;
	newNode->player = player;
	newNode->next = head;
	head = newNode;
}
void ViewRecords(Node*& head) {
	Node* current = head;
	while (current != nullptr) {
		cout << "Nickname: " << current->player.nickname << endl;
		cout << "Age: " << current->player.age << endl;
		cout << "Scores: ";
		for (int i = 0; i < 5; ++i) {
			cout << current->player.scores[i] << " ";
		}
		cout << endl;
		cout << "----------------------------------" << endl;
		current = current->next;
	}
}
void ComputeAverage(Node*& head) {
	Node* current = head;
	while (current != nullptr) {
		double sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += current->player.scores[i];
		}
		double average = sum / 5.0;
		cout << "Nickname: " << current->player.nickname << endl;
		cout << "Average Score: " << average << endl;
		cout << "----------------------------------" << endl;
		current = current->next;
	}
}
void ShowMaxAverage(Node*& head) {
	Node* current = head;
	double maxAverage = -1; // Initialize to a non-valid value
	while (current != nullptr) {
		double sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += current->player.scores[i];
		}
		double average = sum / 5.0;
		if (average > maxAverage) {
			maxAverage = average;
		}
		current = current->next;
	}
	// Now, iterate again to display players with the max average
	current = head;
	while (current != nullptr) {
		double sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += current->player.scores[i];
		}
		double average = sum / 5.0;
		if (average == maxAverage) {
			cout << "Nickname: " << current->player.nickname << endl;
			cout << "Average Score: " << average << endl;
			cout << "----------------------------------" << endl;
		}
		current = current->next;
	}
}
void ShowMinAverage(Node*& head) {
	Node* current = head;
	double minAverage = 100; // Initialize to a value higher than the possible average
	while (current != nullptr) {
		double sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += current->player.scores[i];
		}
		double average = sum / 5.0;
		if (average < minAverage) {
			minAverage = average;
		}
		current = current->next;
	}
	// Now, iterate again to display players with the min average
	current = head;
	while (current != nullptr) {
		double sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += current->player.scores[i];
		}
		double average = sum / 5.0;
		if (average == minAverage) {
			cout << "Nickname: " << current->player.nickname << endl;
			cout << "Average Score: " << average << endl;
			cout << "----------------------------------" << endl;
		}
		current = current->next;
	}
}
void SaveFile(Node*& head) {
	ofstream outFile("player_records.txt");
	Node* current = head;
	while (current != nullptr) {
		outFile << current->player.nickname << endl;
		outFile << current->player.age << endl;
		for (int i = 0; i < 5; ++i) {
			outFile << current->player.scores[i] << " ";
		}
		outFile << endl;
		current = current->next;
	}



	outFile.close();
	cout << "Records saved to 'player_records.txt'." << endl;
}
// Function to indicate closing the file
void CloseFile(Node*& head) {
	cout << "File closed." << endl;
}

void ReadFile(Node*& head)
{
	ifstream inFile("player_records.txt");	
	if (!inFile.is_open())
		cout << "File not found." << endl;
	else
		cout << inFile.rdbuf();
	inFile.close();
}

