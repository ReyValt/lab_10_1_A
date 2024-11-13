//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <string>
//#include <Windows.h> // забезпечення відображення кирилиці
//
//using namespace std;
//
//enum Posada { ROBITNYK, INZHENER, SLUZHBOVETS };
//string posadaStr[] = { "робітник", "інженер", "службовець" };
//
//struct Pracivnyk
//{
//	string prizv;
//	unsigned rik_nar;
//	Posada posada;
//	union
//	{
//		double taryf;
//		int stavka;
//	};
//};
//void Create(Pracivnyk* p, const int N);
//void Print(Pracivnyk* p, const int N);
//
//void SaveToFile(Pracivnyk* p, const int N, const char* filename);
//void LoadFromFile(Pracivnyk*& p, int& N, const char* filename);
//
//
//
//int main()
//{ // забезпечення відображення кирилиці:
//	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
//	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
//
//	int N;
//	cout << "Введіть кількість працівників N: "; cin >> N;
//
//	Pracivnyk* p = new Pracivnyk[N];
//
//	char filename[100];
//	int menuItem;
//	do {
//		cout << endl << endl << endl;
//		cout << "Виберіть дію:" << endl << endl;
//		cout << " [1] - введення даних з клавіатури" << endl;
//		cout << " [2] - вивід даних на екран" << endl;
//
//		cout << " [7] - запис даних у файл" << endl;
//		cout << " [8] - зчитування даних із файлу" << endl << endl;
//		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
//		cout << "Введіть значення: "; cin >> menuItem;
//		cout << endl << endl << endl;
//		switch (menuItem)
//		{
//		case 1:
//			Create(p, N);
//			break;
//		case 2:
//			Print(p, N);
//			break;
//
//
//		case 7:
//			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
//			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
//
//			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
//			SaveToFile(p, N, filename);
//			break;
//		case 8:
//			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
//			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
//
//			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
//			LoadFromFile(p, N, filename);
//			break;
//		case 0:
//			break;
//		default:
//			cout << "Ви ввели помилкове значення! "
//				"Слід ввести число - номер вибраного пункту меню" << endl;
//		}
//	} while (menuItem != 0);
//	return 0;
//}
//void Create(Pracivnyk* p, const int N)
//{
//	int posada;
//	for (int i = 0; i < N; i++)
//	{
//		cout << "Працівник № " << i + 1 << ":" << endl;
//		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
//		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
//
//		cout << " прізвище: "; getline(cin, p[i].prizv);
//		cout << " рік нар.: "; cin >> p[i].rik_nar;
//		cout << " посада (0 - робітник, 1 - інженер, 2 - службовець): ";
//		cin >> posada;
//		p[i].posada = (Posada)posada;
//		switch (p[i].posada)
//		{
//		case ROBITNYK:
//			cout << " тариф : "; cin >> p[i].taryf;
//			break;
//		case INZHENER:
//		case SLUZHBOVETS:
//			cout << " ставка : "; cin >> p[i].stavka;
//			break;
//		}
//		cout << endl;
//	}
//}
//void Print(Pracivnyk* p, const int N)
//{
//	cout << "========================================================================="
//		<< endl;
//	cout << "| № | Прізвище | Рік.нар. | Посада | Тариф | Ставка |"
//		<< endl;
//	cout << "-------------------------------------------------------------------------"
//		<< endl;
//	for (int i = 0; i < N; i++)
//	{
//		cout << "| " << setw(3) << right << i + 1 << " ";
//		cout << "| " << setw(13) << left << p[i].prizv
//			<< "| " << setw(4) << right << p[i].rik_nar << " "
//			<< "| " << setw(11) << left << posadaStr[p[i].posada];
//		switch (p[i].posada)
//		{
//		case ROBITNYK:
//			cout << "| " << setw(9) << setprecision(2) << fixed << right
//				<< p[i].taryf << " |" << setw(13) << right << "|" << endl;
//			break;
//		case INZHENER:
//		case SLUZHBOVETS:
//			cout << "| " << setw(11) << right << "|" << " " << setw(8) << right
//				<< p[i].stavka << " |" << endl;
//			break;
//		}
//	}
//	cout << "========================================================================="
//		<< endl;
//	cout << endl;
//}
//
//
//
//void SaveToFile(Pracivnyk* p, const int N, const char* filename)
//{
//	ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
//	fout.write((char*)&N, sizeof(N)); // записали кількість елементів
//	for (int i = 0; i < N; i++)
//		fout.write((char*)&p[i], sizeof(Pracivnyk)); // записали елементи масиву
//	fout.close(); // закрили файл
//}
//
//void LoadFromFile(Pracivnyk*& p, int& N, const char* filename)
//{
//	delete[] p; // знищили попередні дані
//	ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
//	fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
//	p = new Pracivnyk[N]; // створили динамічний масив
//	for (int i = 0; i < N; i++)
//		fin.read((char*)&p[i], sizeof(Pracivnyk)); // прочитали елементи масиву
//	fin.close(); // закрили файл
//}