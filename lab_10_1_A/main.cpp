#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>


using namespace std;

enum Major { Компютерні_науки, Інформатика, Фізика_та_інформатика };
string majorStr[] = { "Комп'ютерні науки", "Інформатика", "Фізика та інформатика" };

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
	cout << "Введіть кількість студентів N: "; cin >> N;

	Student *p = new Student[N];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;

		switch (menuItem) {
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			CalculateAverages(p, N);
			cout << "Кількість студентів з оцінкою 4 або 5 з фізики: " << CountPhysics(p, N) << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	delete[] p;

	return 0;
}

void Create(Student* p, const int N) {
	int major;
	for (int i = 0; i < N; i++) {
		cout << " Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " Прізвище: "; getline(cin, p[i].last_name);
		cout << " Курс: "; cin >> p[i].course;
		cout << " Спеціальність: (0 - Комп’ютерні_науки, 1 - Інформатика, 2 - Фізика_та_інформатика): ";
		cin >> major;
		p[i].major = (Major)major;

		cout << " Бали за фізику: "; cin >> p[i].physics;
		cout << " Бали за математику: "; cin >> p[i].math;
		cout << " Бали за інформатику: "; cin >> p[i].informatics;
		cout << endl;
	}
}

void Print(Student* p, const int N) {
	cout << "=======================================================================================" << endl;
	cout << "| № | Прізвище     | Курс | Спеціальність         | Фізика | Математика | Інформатика |" << endl;
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

	cout << "Середній бал з фізики: " << avgPhysics << endl;
	cout << "Середній бал з математики: " << avgMath << endl;
	cout << "Середній бал з інформатики: " << avgInformatics << endl;
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
