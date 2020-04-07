#include <iostream>
#include <fstream>

using namespace std;

//����������� ���������;
struct Birthday
{
	int date;
	int month;
	int year;
	bool isCorrect();
};

struct Pensioner
{
	char surname[56];
	char name[32];
	char patronomyc[56];
	char sex[10];
	char nationality[56];
	char country[32];
	char region[32];
	char city[32];
	char street[32];
	int index;
	int home;
	int apartment;
	long long int phone_number;
	long long int time = 0;
	Birthday DATE;
};

//������� ������������ ����;
bool Birthday::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((date <= 31) && (date > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((date <= 30) && (date > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((date <= 28) && (date > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((date <= 29) && (date > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((date == 28) && (date > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((date <= 29) && (date > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

//������� �������� � ���� ����� �����������;
void Old_time(Pensioner* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int count1;
		count1 = arr[i].DATE.year;

		for (int j = 1; j <= count1; j++)
		{
			if (j % 4 != 0)
			{
				arr[i].time += 365;
				if (j == count1 - 1)
				{
					if (arr[i].DATE.month == 1)
						arr[i].time += 31 + arr[i].DATE.date;
					if (arr[i].DATE.month == 2)
						arr[i].time += 28 + 31 + arr[i].DATE.date;
					if (arr[i].DATE.month == 3)
						arr[i].time += 31 * 2 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 4)
						arr[i].time += 31 * 2 + 28 + 30 + arr[i].DATE.date;
					if (arr[i].DATE.month == 5)
						arr[i].time += 31 * 3 + 30 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 6)
						arr[i].time += 31 * 3 + 30 * 2 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 7)
						arr[i].time += 31 * 4 + 30 * 2 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 8)
						arr[i].time += 31 * 5 + 30 * 2 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 9)
						arr[i].time += 31 * 5 + 30 * 3 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 10)
						arr[i].time += 31 * 6 + 30 * 3 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 11)
						arr[i].time += 31 * 6 + 30 * 4 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 12)
						arr[i].time += 31 * 7 + 30 * 4 + 28 + arr[i].DATE.date;
				}
			}

			if (j % 4 == 0)
			{
				arr[i].time += 366;
				if (j == count1 - 1)
				{
					if (arr[i].DATE.month == 1)
						arr[i].time += 31 + arr[i].DATE.date;
					if (arr[i].DATE.month == 2)
						arr[i].time += 29 + 31 + arr[i].DATE.date;
					if (arr[i].DATE.month == 3)
						arr[i].time += 31 * 2 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 4)
						arr[i].time += 31 * 2 + 29 + 30 + arr[i].DATE.date;
					if (arr[i].DATE.month == 5)
						arr[i].time += 31 * 3 + 30 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 6)
						arr[i].time += 31 * 3 + 30 * 2 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 7)
						arr[i].time += 31 * 4 + 30 * 2 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 8)
						arr[i].time += 31 * 5 + 30 * 2 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 9)
						arr[i].time += 31 * 5 + 30 * 3 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 10)
						arr[i].time += 31 * 6 + 30 * 3 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 11)
						arr[i].time += 31 * 6 + 30 * 4 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 12)
						arr[i].time += 31 * 7 + 30 * 4 + 29 + arr[i].DATE.date;
				}
			}
		}	
	}
}

void easy()
{
	cout << endl;
	cout << "���������� ������� ������������ ���������� �� �����," << endl;
	cout << "���������� ������ ���������� � ����������� �� �������," << endl;
	cout << "� ����� ��������� ��� ���������� � ����� ����" << endl << endl;

	char symbol;

	string read = "Old_file.txt"; //���� � �������� �� ����� ����������;
	string new_read = "New_file.txt";

	ofstream write; //������� �������� ����������;
	ofstream new_write;

	ifstream console;

	console.open(read);

	if (!console.is_open()) //���� �� ������� ������� ���� - ������ ���������;
	{
		cout << "�� ������� ������� ��� ����� ����������� ����!";
	}

	else
	{
		cout << "���� ������! � ������ ����� ��������: " << endl;

		while (console.get(symbol)) //����������� ��������� � ������� ������ �� �����;
		{
			cout << symbol;
		}

		cout << endl;
		cout << "------------------------------------------------" << endl << endl;
	}

	console.close();

	Pensioner* arr;
	int size, count, day, month, full_time = 0, sixty_year_time = 0, year = 2020, life_time = 65;

	do
	{
		cout << "������� ���������� �����������, ������ ������� �� ������ �������: ";
		cin >> size;
	} while (size < 1);

	arr = new Pensioner[size];

	cout << endl;

	//���� ����������� ����������;
	for (int i = 0; i < size; i++)
	{
		cout << "������� ������� ���������� ��� ������� " << i + 1 << ": ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].surname, 56);
		cout << endl;

		cout << "������� ���: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].name, 56);
		cout << endl;

		cout << "������� ��������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].patronomyc, 56);
		cout << endl;

		cout << "������� ���: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].sex, 10);
		cout << endl;

		cout << "������� ��������������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].nationality, 56);
		cout << endl;

		cout << "������� ����� ��������: ";
		cin >> arr[i].phone_number;
		cout << endl;

		do
		{
			do
			{
				cout << "������� ���� ��������: ";
				cin >> arr[i].DATE.date;
				cout << endl;
				cout << "�����: ";
				cin >> arr[i].DATE.month;
				cout << endl;
				cout << "���: ";
				cin >> arr[i].DATE.year;
				cout << endl;
			} while (!arr[i].DATE.isCorrect());
		} while (arr[i].DATE.year > 1960);

		do
		{
			count = 0;

			cout << "������� �������� ������: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> arr[i].index;

			if (arr[i].index < 100000 && arr[i].index >= 10000)
			{
				count++;
			}
			cout << endl;

		} while (count == 0);

		cout << "������� ������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].country, 32);
		cout << endl;

		cout << "������� ������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].region, 32);
		cout << endl;

		cout << "������� �����: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].city, 32);
		cout << endl;

		cout << "������� �����: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].street, 32);
		cout << endl;

		cout << "������� ����� ����: ";
		cin >> arr[i].home;
		cout << endl;

		cout << "������� ����� ��������: ";
		cin >> arr[i].apartment;
		cout << endl;
	}

	cout << "------------------------------------------------------" << endl << endl;
	cout << "��� ������ ���������� � ����������� ����������� ���������� ������ �������� ���� � �����(��� �������� ��� 2020)" << endl << endl;

	do
	{
		count = 0;

		cout << "������� �������� ����: ";
		cin >> day;
		cout << endl;
		cout << "������� �������� �����: ";
		cin >> month;
		cout << endl;

		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day <= 31 && day > 0)
			{
				count++;
			}
		}

		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day <= 30 && day > 0)
			{
				count++;
			}
		}

		else
		{
			if (month == 2 && year % 4 != 0)
			{
				if (day <= 28 && day > 0)
				{
					count++;
				}
			}

			else
			{
				if (year % 400 == 0)
				{
					if ((day <= 29) && (day > 0))
					{
						count++;
					}
				}

				else
				{
					if ((year % 100 == 0) && (year % 400 != 0))
					{
						if ((day == 28) && (day > 0))
						{
							count++;
						}
					}

					else
					{
						if ((year % 4 == 0) && (year % 100 != 0))
						{
							if ((day <= 29) && (day > 0))
							{
								count++;
							}
						}
					}
				}
			}
		}

	} while (count == 0); //������� � ���� ��������� ����;

	for (int i = 1; i <= year; i++) //������� �������� ����� � ����;
	{
		if (i % 4 != 0)
		{
			full_time += 365;
		}

		if (i % 4 == 0)
		{
			full_time += 366;
		}
	}

	if (year % 4 != 0)
	{
		if (month == 1)
			full_time += 31 + day;
		if (month == 2)
			full_time += 28 + 31 + day;
		if (month == 3)
			full_time += 31 * 2 + 28 + day;
		if (month == 4)
			full_time += 31 * 2 + 28 + 30 + day;
		if (month == 5)
			full_time += 31 * 3 + 30 + 28 + day;
		if (month == 6)
			full_time += 31 * 3 + 30 * 2 + 28 + day;
		if (month == 7)
			full_time += 31 * 4 + 30 * 2 + 28 + day;
		if (month == 8)
			full_time += 31 * 5 + 30 * 2 + 28 + day;
		if (month == 9)
			full_time += 31 * 5 + 30 * 3 + 28 + day;
		if (month == 10)
			full_time += 31 * 6 + 30 * 3 + 28 + day;
		if (month == 11)
			full_time += 31 * 6 + 30 * 4 + 28 + day;
		if (month == 12)
			full_time += 31 * 7 + 30 * 4 + 28 + day;
	}

	if (year % 4 == 0)
	{
		if (month == 1)
			full_time += 31 + day;
		if (month == 2)
			full_time += 29 + 31 + day;
		if (month == 3)
			full_time += 31 * 2 + 29 + day;
		if (month == 4)
			full_time += 31 * 2 + 29 + 30 + day;
		if (month == 5)
			full_time += 31 * 3 + 30 + 29 + day;
		if (month == 6)
			full_time += 31 * 3 + 30 * 2 + 29 + day;
		if (month == 7)
			full_time += 31 * 4 + 30 * 2 + 29 + day;
		if (month == 8)
			full_time += 31 * 5 + 30 * 2 + 29 + day;
		if (month == 9)
			full_time += 31 * 5 + 30 * 3 + 29 + day;
		if (month == 10)
			full_time += 31 * 6 + 30 * 3 + 29 + day;
		if (month == 11)
			full_time += 31 * 6 + 30 * 4 + 29 + day;
		if (month == 12)
			full_time += 31 * 7 + 30 * 4 + 29 + day;
	}

	Old_time(arr, size); //������� ���������� ������� ����� ����������� � ����;

	//��������� ������ ���� ������ 65-�� ��� - ��������� � ��� ����� �� ���;
	for (int i = 0; i < life_time; i++)
	{
		if (i % 4 != 0)
		{
			sixty_year_time += 365;
		}

		if (i % 4 == 0)
		{
			sixty_year_time += 366;
		}
	}

	write.open(read);
	new_write.open(new_read);

	int count2 = 0;

	write << "���������� � ����������� � ���������� ������ ������ 5 ��� " << endl;
	new_write << "���������� � ����������� � ���������� ������ ������ 5 ��� " << endl;

	for (int i = 0; i < size; i++) //���� ������� � ���� ����� �������� �������� � �������� ����� ������ 65 ���, �� ��� ��� ���������� ������� ���������� � 60 ������� �� ������ ������ 5 ���;
	{
		long long int different = full_time - arr[i].time;

		if (different > sixty_year_time)
		{
			if (!write.is_open()) //���� �� ������� ������� ���� - ������ ���������;
			{
				cout << "�� ������� ������� ��� ����� ����������� ����!" << endl;
			}

			else
			{
				write << "������� �������� ��� ������� " << i + 1 << ": " << arr[i].surname << ", ���: " << arr[i].name << ", ��������: " << arr[i].patronomyc << endl;
				write << "���: " << arr[i].sex << ", ��������������: " << arr[i].nationality << ", ���� ��������: " << arr[i].DATE.date << " " << arr[i].DATE.month << " " << arr[i].DATE.year << endl;
				write << "����� ��������: " << arr[i].phone_number << ", �������� ������: " << arr[i].index << ", ������: " << arr[i].country << ", ������: " << arr[i].region << ", �����: " << arr[i].city << endl;
				write << "�����: " << arr[i].street << ", ���: " << arr[i].home << ", ��������: " << arr[i].apartment << endl;
				count2++;
			}

			if (!new_write.is_open()) //���� �� ������� ������� ���� - ������ ���������;
			{
				cout << "�� ������� ������� ��� ����� ����������� ����!" << endl;
			}

			else
			{
				new_write << "������� �������� ��� ������� " << i + 1 << ": " << arr[i].surname << ", ���: " << arr[i].name << ", ��������: " << arr[i].patronomyc << endl;
				new_write << "���: " << arr[i].sex << ", ��������������: " << arr[i].nationality << ", ���� ��������: " << arr[i].DATE.date << " " << arr[i].DATE.month << " " << arr[i].DATE.year << endl;
				new_write << "����� ��������: " << arr[i].phone_number << ", �������� ������: " << arr[i].index << ", ������: " << arr[i].country << ", ������: " << arr[i].region << ", �����: " << arr[i].city << endl;
				new_write << "�����: " << arr[i].street << ", ���: " << arr[i].home << ", ��������: " << arr[i].apartment << endl;
				count2++;
			}
		}
	}

	if (count2 == 0)
	{
		write << "��� ����������� � ���������� ������ ������ 5 ���";
		new_write << "��� ����������� � ���������� ������ ������ 5 ���";
	}

	cout << endl << endl << "�������������� ���������� �������� � ��������� ����";
    cout << endl << endl;
}

void medium()
{
	cout << endl << "���������� ������� �� ����� �������, ���������� �� � �������� � ������ ����" << endl << endl;

	char arr[50], symbol;
	int count = 0;
	
	string read = "F_medium.txt"; //���� � �������� �� ����� ����������;
	string new_read = "G_medium.txt";
	
	ofstream write; //������� �������� ����������;
	
	ifstream console;

	console.open(read);

	if (!console.is_open()) //���� �� ������� ������� ���� - ������ ���������;
	{
		cout << "�� ������� ������� ��� ����� ����������� ����!" << endl;
	}

	else
	{
		cout << "���� ������! � ������ ����� ��������: " << endl;

		while (console.get(symbol)) //����������� ��������� � ������� ������ �� �����;
		{
			count++;
			for (int i = count; i <= count; i++)
			{
				arr[i] = symbol;
				cout << arr[i];
			}
		}
    }

	console.close();

	cout << endl << endl;

	for (int i = 0; i < count / 2; i++) //������������� ������;
	{
		char temp = arr[i];
		arr[i] = arr[count - i];
		arr[count - i] = temp;
	}

	write.open(new_read);

	if (!write.is_open()) //���� �� ������� ������� ���� - ������ ���������;
	{
		cout << "�� ������� ������� ��� ����� ����������� ����!" << endl;
	}

	else
	{
		cout << "�������������� ���������� ���� �������� � ����� ����" << endl;

		for (int i = 0; i < count; i++)
		{
			write << arr[i];
		}
	}

	cout << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "RU");

	int a;
	int count = 0;

	do
	{
		cout << "������� ����� ������� (easy - 1), (medium - 2): ";

		cin >> a;

		cout << endl;

		if (a == 1)
		{
			easy();
			count++;
		}

		if (a == 2)
		{
			medium();
			count++;
		}

	} while (count == 0);

	int b;

	do
	{

		count = 0;

		cout << "���������� ����? �� - 1, ��� - 2: ";

		cin >> b;

		cout << endl;

		if (b == 1)
		{
			count++;
			main();
		}

		if (b == 2)
		{
			cout << "�� ������ �� ����������";
			count++;
			break;
		}

	} while (count == 0);
}