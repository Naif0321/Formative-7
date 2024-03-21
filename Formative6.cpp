#include <iostream>
#include <string>
using namespace std;
struct Player {
	string nickname;
	int age;
	double score1;
	double score2;
};
struct Node {
	Player player;
	Node* next;
};

// Put head on Functions;

void addRecord(const Player& player, Node*& head);
void viewRecords(Node*& head);
void computeAverage(Node*& head);
void showMaxAverage(Node*& head);
void showMinAverage(Node*& head);

void getPlayerInformation(Node*& head)
{
	Player newplayer;

	cout << "Enter Player Name : ";
	cin >> newplayer.nickname;
	cout << "Enter Player age :";
	cin >> newplayer.age;
	cout << "Enter Player 1st Score :";
	cin >> newplayer.score1;
	cout << "Enter Player 2nd Score :";
	cin >> newplayer.score2;
	addRecord(newplayer, head);
}

void addRecord(const Player& player, Node*& head) {
	Node* newNode = new Node;
	newNode->player = player;
	newNode->next = head;
	head = newNode;
}
void viewRecords(Node*& head) {
	Node* current = head;
	while (current != NULL) {
		cout << "Nickname: " << current->player.nickname << endl;
		cout << "Age: " << current->player.age << endl;
		cout << "Score 1: " << current->player.score1 << endl;
		cout << "Score 2: " << current->player.score2 << endl;
		cout << "----------------------------------" << endl;
		current = current->next;
	}
}
void computeAverage(Node*& head) {
	Node* current = head;
	while (current != nullptr) {
		double average = (current->player.score1 + current->player.score2) / 2.0;
		cout << "Nickname: " << current->player.nickname << endl;
		cout << "Average Score: " << average << endl;
		cout << "----------------------------------" << endl;
		current = current->next;
	}
}
void showMaxAverage(Node*& head) {
	Node* current = head;
	double maxAverage = -1;
	while (current != NULL) {
		double average = (current->player.score1 + current->player.score2) / 2.0;
		if (average > maxAverage) {
			maxAverage = average;
		}
		current = current->next;
	}
	current = head;
	while (current != NULL) {
		double average = (current->player.score1 + current->player.score2) / 2.0;
		if (average == maxAverage) {
			cout << "---Maximum-- " << endl;
			cout << "Nickname: " << current->player.nickname << endl;
			cout << "Average Score: " << average << endl;
			cout << "----------------------------------" << endl;
		}
		current = current->next;
	}
}
void showMinAverage(Node*& head) {
	Node* current = head;
	double minAverage = 999999;
	while (current != NULL) {
		double average = (current->player.score1 + current->player.score2) / 2.0;
		if (average < minAverage) {
			minAverage = average;
		}
		current = current->next;
	}
	current = head;
	while (current != NULL) {
		double average = (current->player.score1 + current->player.score2) / 2.0;
		if (average == minAverage) {
			cout << "---Minimum-- " << endl;
			cout << "Nickname: " << current->player.nickname << endl;
			cout << "Average Score: " << average << endl;
			cout << "----------------------------------" << endl;
		}
		current = current->next;
	}
}

// Put the Functions in the int main

int main()
{
	Node* head = nullptr;
	int category;
	do
	{
		cout << "---Welcome to Player Records---" << endl;
		cout << "1. Add Record" << endl;
		cout << "2. View Records" << endl;
		cout << "3. Compute Records" << endl;
		cout << "4. Show Maximum Player Records" << endl;
		cout << "5. Show Minimum Player Records" << endl;
		cout << "6. Exit" << endl;
		cout << ":: ";
		cin >> category;
		system("cls");

		switch (category)
		{
		case 1:
			getPlayerInformation(head);
			system("cls");
			break;
		case 2:
			viewRecords(head);
			system("pause");
			break;
		case 3:
			computeAverage(head);
			system("pause");
			break;
		case 4:
			showMaxAverage(head);
			system("pause");
			break;
		case 5:
			showMinAverage(head);
			system("pause");
			break;
		case 6:
			exit(0);
			break;
		default:
			break;
		}

	} while (category != 6);
	return 0;
}
