//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <string>
//#include <Windows.h> // ������������ ����������� ��������
//
//using namespace std;
//
//enum Posada { ROBITNYK, INZHENER, SLUZHBOVETS };
//string posadaStr[] = { "�������", "�������", "����������" };
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
//{ // ������������ ����������� ��������:
//	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
//	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������
//
//	int N;
//	cout << "������ ������� ���������� N: "; cin >> N;
//
//	Pracivnyk* p = new Pracivnyk[N];
//
//	char filename[100];
//	int menuItem;
//	do {
//		cout << endl << endl << endl;
//		cout << "������� ��:" << endl << endl;
//		cout << " [1] - �������� ����� � ���������" << endl;
//		cout << " [2] - ���� ����� �� �����" << endl;
//
//		cout << " [7] - ����� ����� � ����" << endl;
//		cout << " [8] - ���������� ����� �� �����" << endl << endl;
//		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
//		cout << "������ ��������: "; cin >> menuItem;
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
//			cin.get(); // ������� ����� ��������� � �� ����������� �������
//			cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
//
//			cout << "������ ��'� �����: "; cin.getline(filename, 99);
//			SaveToFile(p, N, filename);
//			break;
//		case 8:
//			cin.get(); // ������� ����� ��������� � �� ����������� �������
//			cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
//
//			cout << "������ ��'� �����: "; cin.getline(filename, 99);
//			LoadFromFile(p, N, filename);
//			break;
//		case 0:
//			break;
//		default:
//			cout << "�� ����� ��������� ��������! "
//				"��� ������ ����� - ����� ��������� ������ ����" << endl;
//		}
//	} while (menuItem != 0);
//	return 0;
//}
//void Create(Pracivnyk* p, const int N)
//{
//	int posada;
//	for (int i = 0; i < N; i++)
//	{
//		cout << "��������� � " << i + 1 << ":" << endl;
//		cin.get(); // ������� ����� ��������� � �� ����������� �������
//		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
//
//		cout << " �������: "; getline(cin, p[i].prizv);
//		cout << " �� ���.: "; cin >> p[i].rik_nar;
//		cout << " ������ (0 - �������, 1 - �������, 2 - ����������): ";
//		cin >> posada;
//		p[i].posada = (Posada)posada;
//		switch (p[i].posada)
//		{
//		case ROBITNYK:
//			cout << " ����� : "; cin >> p[i].taryf;
//			break;
//		case INZHENER:
//		case SLUZHBOVETS:
//			cout << " ������ : "; cin >> p[i].stavka;
//			break;
//		}
//		cout << endl;
//	}
//}
//void Print(Pracivnyk* p, const int N)
//{
//	cout << "========================================================================="
//		<< endl;
//	cout << "| � | ������� | г�.���. | ������ | ����� | ������ |"
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
//	ofstream fout(filename, ios::binary); // ������� ������� ���� ������
//	fout.write((char*)&N, sizeof(N)); // �������� ������� ��������
//	for (int i = 0; i < N; i++)
//		fout.write((char*)&p[i], sizeof(Pracivnyk)); // �������� �������� ������
//	fout.close(); // ������� ����
//}
//
//void LoadFromFile(Pracivnyk*& p, int& N, const char* filename)
//{
//	delete[] p; // ������� �������� ���
//	ifstream fin(filename, ios::binary); // ������� ������� ���� ����������
//	fin.read((char*)&N, sizeof(N)); // ��������� ������� ��������
//	p = new Pracivnyk[N]; // �������� ��������� �����
//	for (int i = 0; i < N; i++)
//		fin.read((char*)&p[i], sizeof(Pracivnyk)); // ��������� �������� ������
//	fin.close(); // ������� ����
//}