#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>


using namespace std;

enum Major { ���������_�����, �����������, Գ����_��_����������� };
string majorStr[] = { "����'����� �����", "�����������", "Գ���� �� �����������" };

struct Student {
	string last_name;
	int course;
	Major major;
	int physics;
	int math;
	int informatics;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void CalculateAverages(Student* p, const int N);
int CountPhysics(Student* p, const int N);


int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "������ ������� �������� N: "; cin >> N;

	Student *p = new Student[N];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;

		switch (menuItem) {
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			CalculateAverages(p, N);
			cout << "ʳ������ �������� � ������� 4 ��� 5 � ������: " << CountPhysics(p, N) << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	delete[] p;

	return 0;
}

void Create(Student* p, const int N) {
	int major;
	for (int i = 0; i < N; i++) {
		cout << " ������� � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " �������: "; getline(cin, p[i].last_name);
		cout << " ����: "; cin >> p[i].course;
		cout << " ������������: (0 - ���������_�����, 1 - �����������, 2 - Գ����_��_�����������): ";
		cin >> major;
		p[i].major = (Major)major;

		cout << " ���� �� ������: "; cin >> p[i].physics;
		cout << " ���� �� ����������: "; cin >> p[i].math;
		cout << " ���� �� �����������: "; cin >> p[i].informatics;
		cout << endl;
	}
}

void Print(Student* p, const int N) {
	cout << "=======================================================================================" << endl;
	cout << "| � | �������     | ���� | ������������         | Գ���� | ���������� | ����������� |" << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(2) << right << i + 1;
		cout << "| " << setw(13) << left << p[i].last_name
			<< "| " << setw(4) << right << p[i].course << " "
			<< "| " << setw(22) << left << majorStr[p[i].major]
			<< "| " << setw(6) << right << p[i].physics << " "
			<< "| " << setw(10) << right << p[i].math << " "
			<< "| " << setw(12) << right << p[i].informatics << "" << "|"
			<< endl;
	}
	cout << "=======================================================================================" << endl;
	cout << endl;
}

void CalculateAverages(Student* p, const int N) {
	double totalPhysics = 0;
	double totalMath = 0;
	double totalInformatics = 0;

	for (int i = 0; i < N; i++) {
		totalPhysics += p[i].physics;
		totalMath += p[i].math;
		totalInformatics += p[i].informatics;
	}

	double avgPhysics = totalPhysics / N;
	double avgMath = totalMath / N;
	double avgInformatics = totalInformatics / N;

	cout << "������� ��� � ������: " << avgPhysics << endl;
	cout << "������� ��� � ����������: " << avgMath << endl;
	cout << "������� ��� � �����������: " << avgInformatics << endl;
}

int CountPhysics(Student* p, const int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (p[i].physics == 5 || p[i].physics == 4) {
			count++;
		}
	}
	return count;
}
