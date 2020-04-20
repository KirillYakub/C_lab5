#include <iostream>
#include <fstream>

using namespace std;

///////////////////////////////////////////////////////////

//необходимые структуры;
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

//функции корректности даты;
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

int isCorrect1(int day, int month, int year)
{
	int count = 0;

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

	return count;
}

//функция подсчета в днях жизни пенсионеров;
void Old_time(Pensioner* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int count1;
		count1 = arr[i].DATE.year;

		for (int j = 0; j < count1; j++)
		{
			if (j % 4 != 0)
			{
				
				arr[i].time += 365;

				if (j == count1 - 1)
				{
					if (arr[i].DATE.month == 1)
						arr[i].time += arr[i].DATE.date;
					if (arr[i].DATE.month == 2)
						arr[i].time += 31 + arr[i].DATE.date;
					if (arr[i].DATE.month == 3)
						arr[i].time += 31 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 4)
						arr[i].time += 31 * 2 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 5)
						arr[i].time += 31 * 2 + 30 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 6)
						arr[i].time += 31 * 3 + 30 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 7)
						arr[i].time += 31 * 3 + 30 * 2 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 8)
						arr[i].time += 31 * 4 + 30 * 2 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 9)
						arr[i].time += 31 * 4 + 30 * 3 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 10)
						arr[i].time += 31 * 4 + 30 * 4 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 11)
						arr[i].time += 31 * 5 + 30 * 4 + 28 + arr[i].DATE.date;
					if (arr[i].DATE.month == 12)
						arr[i].time += 31 * 5 + 30 * 5 + 28 + arr[i].DATE.date;
				}
			}

			if (j % 4 == 0)
			{
				
			    arr[i].time += 366;

				if (j == count1 - 1)
				{
					if (arr[i].DATE.month == 1)
						arr[i].time += arr[i].DATE.date;
					if (arr[i].DATE.month == 2)
						arr[i].time += 31 + arr[i].DATE.date;
					if (arr[i].DATE.month == 3)
						arr[i].time += 31 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 4)
						arr[i].time += 31 * 2 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 5)
						arr[i].time += 31 * 2 + 30 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 6)
						arr[i].time += 31 * 3 + 30 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 7)
						arr[i].time += 31 * 3 + 30 * 2 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 8)
						arr[i].time += 31 * 4 + 30 * 2 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 9)
						arr[i].time += 31 * 4 + 30 * 3 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 10)
						arr[i].time += 31 * 4 + 30 * 4 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 11)
						arr[i].time += 31 * 5 + 30 * 4 + 29 + arr[i].DATE.date;
					if (arr[i].DATE.month == 12)
						arr[i].time += 31 * 5 + 30 * 5 + 29 + arr[i].DATE.date;
				}
			}
		}	
	}
}

int New_time(int full_time, int year, int day, int month) //функция подсчета полного времени в днях;
{
	if (year % 4 != 0)
	{
		if (month == 1)
			full_time += day;
		if (month == 2)
			full_time += 31 + day;
		if (month == 3)
			full_time += 31 + 28 + day;
		if (month == 4)
			full_time += 31 * 2 + 28 + day;
		if (month == 5)
			full_time += 31 * 2 + 30 + 28 + day;
		if (month == 6)
			full_time += 31 * 3 + 30 + 28 + day;
		if (month == 7)
			full_time += 31 * 3 + 30 * 2 + 28 + day;
		if (month == 8)
			full_time += 31 * 4 + 30 * 2 + 28 + day;
		if (month == 9)
			full_time += 31 * 4 + 30 * 3 + 28 + day;
		if (month == 10)
			full_time += 31 * 4 + 30 * 4 + 28 + day;
		if (month == 11)
			full_time += 31 * 5 + 30 * 4 + 28 + day;
		if (month == 12)
			full_time += 31 * 5 + 30 * 5 + 28 + day;
	}

	if (year % 4 == 0)
	{
		if (month == 1)
			full_time += day;
		if (month == 2)
			full_time += 31 + day;
		if (month == 3)
			full_time += 31 + 29 + day;
		if (month == 4)
			full_time += 31 * 2 + 29 + day;
		if (month == 5)
			full_time += 31 * 2 + 30 + 29 + day;
		if (month == 6)
			full_time += 31 * 3 + 30 + 29 + day;
		if (month == 7)
			full_time += 31 * 3 + 30 * 2 + 29 + day;
		if (month == 8)
			full_time += 31 * 4 + 30 * 2 + 29 + day;
		if (month == 9)
			full_time += 31 * 4 + 30 * 3 + 29 + day;
		if (month == 10)
			full_time += 31 * 4 + 30 * 4 + 29 + day;
		if (month == 11)
			full_time += 31 * 5 + 30 * 4 + 29 + day;
		if (month == 12)
			full_time += 31 * 5 + 30 * 5 + 29 + day;
	}

	return full_time;
}

void easy()
{
	cout << endl;
	cout << "Необходимо считать произвольную информацию из файла," << endl;
	cout << "переписать данную информацию в зависимости от задания," << endl;
	cout << "а также сохранить эту информацию в новый файл" << endl << endl;

	char symbol;

	string read = "Old_file.txt"; //файл к которому мы будем обращаться;
	string new_read = "New_file.txt";

	ofstream write; //создаем файловую переменную;
	ofstream new_write;

	ifstream console;

	console.open(read);

	if (!console.is_open()) //если не удается открыть файл - выдаем сообщение;
	{
		cout << "Не удалось открыть или найти необходимый файл!";
	}

	else
	{
		cout << "Файл открыт! В данном файле записано: " << endl;

		while (console.get(symbol)) //посимвольно считываем в консоль данные из файла;
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
		cout << "Введите количество пенсионеров, данные которых вы будете вводить: ";
		cin >> size;
	} while (size < 1);

	arr = new Pensioner[size];

	cout << endl;

	//ввод необходимой информации;
	for (int i = 0; i < size; i++)
	{
		cout << "Введите фамилию пенсионера под номером " << i + 1 << ": ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].surname, 56);
		cout << endl;

		cout << "Введите имя: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].name, 56);
		cout << endl;

		cout << "Введите отчество: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].patronomyc, 56);
		cout << endl;

		cout << "Введите пол: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].sex, 10);
		cout << endl;

		cout << "Введите национальность: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].nationality, 56);
		cout << endl;

		cout << "Введите номер телефона: ";
		cin >> arr[i].phone_number;
		cout << endl;

		do
		{
			do
			{
				cout << "Введите День Рождения: ";
				cin >> arr[i].DATE.date;
				cout << endl;
				cout << "Месяц: ";
				cin >> arr[i].DATE.month;
				cout << endl;
				cout << "Год: ";
				cin >> arr[i].DATE.year;
				cout << endl;
			} while (!arr[i].DATE.isCorrect());
		} while (arr[i].DATE.year > 1960);

		do
		{
			count = 0;

			cout << "Введите почтовый индекс: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> arr[i].index;

			if (arr[i].index < 100000 && arr[i].index >= 10000)
			{
				count++;
			}
			cout << endl;

		} while (count == 0);

		cout << "Введите страну: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].country, 32);
		cout << endl;

		cout << "Введите регион: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].region, 32);
		cout << endl;

		cout << "Введите город: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].city, 32);
		cout << endl;

		cout << "Введите улицу: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].street, 32);
		cout << endl;

		cout << "Введите номер дома: ";
		cin >> arr[i].home;
		cout << endl;

		cout << "Введите номер квартиры: ";
		cin >> arr[i].apartment;
		cout << endl;
	}

	cout << "------------------------------------------------------" << endl << endl;
	cout << "Для записи информации о необходимых пенсионерах необходимо ввести нынешние день и месяц(год известен как 2020)" << endl << endl;

	do
	{
		
		cout << "Введите нынешний день: ";
		cin >> day;
		cout << endl;
		cout << "Введите нынешний месяц: ";
		cin >> month;
		cout << endl;

	} while (isCorrect1(day, month, year) == 0); //проверка нынешней даты;

	for (int i = 0; i < year; i++) //находим нынешнее время в днях;
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

	long long int full_time_1 = New_time(full_time, year, day, month);

	Old_time(arr, size); //функция нахождения времени жизни пенсионеров в днях;

	//пенсионер должен быть старше 65-ти лет - разбиваем и это число на дни;
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

	write << "Информация о пенсионерах с пенсионным стажем больше 5 лет " << endl << endl;
	new_write << "Информация о пенсионерах с пенсионным стажем больше 5 лет " << endl << endl;

	for (int i = 0; i < size; i++) //если разница в днях между нынешним временем и временем жизни больше 65 лет, то так как пенсионный возраст начинается с 60 человек на пенсии больше 5 лет;
	{
		
		long long int different = full_time_1 - arr[i].time;

		cout << "Пенсионер " << i + 1 << endl;
		cout << "Полное время в днях - " << full_time_1 << endl;
		cout << "Время жизни в днях - " << arr[i].time << endl;
		cout << "65 лет в днях - " << sixty_year_time << endl;
		cout << "Разница - " << different << endl << endl;

		if (different > sixty_year_time)
		{
			if (!write.is_open()) //если не удается открыть файл - выдаем сообщение;
			{
				cout << "Не удалось открыть или найти необходимый файл!" << endl;
			}

			else
			{
				write << "Фамилия пенсионера под номером " << i + 1 << ": " << arr[i].surname << ", Имя: " << arr[i].name << ", Отчество: " << arr[i].patronomyc << endl;
				write << "Пол: " << arr[i].sex << ", Национальность: " << arr[i].nationality << ", Дата Рождения: " << arr[i].DATE.date << " " << arr[i].DATE.month << " " << arr[i].DATE.year << endl;
				write << "Номер телефона: " << arr[i].phone_number << ", Почтовый индекс: " << arr[i].index << ", Страна: " << arr[i].country << ", Регион: " << arr[i].region << ", Город: " << arr[i].city << endl;
				write << "Улица: " << arr[i].street << ", Дом: " << arr[i].home << ", Квартира: " << arr[i].apartment << endl << endl;
				count2++;
			}

			if (!new_write.is_open()) //если не удается открыть файл - выдаем сообщение;
			{
				cout << "Не удалось открыть или найти необходимый файл!" << endl;
			}

			else
			{
				new_write << "Фамилия пенсионера под номером " << i + 1 << ": " << arr[i].surname << ", Имя: " << arr[i].name << ", Отчество: " << arr[i].patronomyc << endl;
				new_write << "Пол: " << arr[i].sex << ", Национальность: " << arr[i].nationality << ", Дата Рождения: " << arr[i].DATE.date << " " << arr[i].DATE.month << " " << arr[i].DATE.year << endl;
				new_write << "Номер телефона: " << arr[i].phone_number << ", Почтовый индекс: " << arr[i].index << ", Страна: " << arr[i].country << ", Регион: " << arr[i].region << ", Город: " << arr[i].city << endl;
				new_write << "Улица: " << arr[i].street << ", Дом: " << arr[i].home << ", Квартира: " << arr[i].apartment << endl << endl;
				count2++;
			}
		}
	}

	if (count2 == 0)
	{
		write << endl << "Нет пенсионеров с пенсионным стажем больше 5 лет";
		new_write << endl << "Нет пенсионеров с пенсионным стажем больше 5 лет";
	}

	cout << endl << "Соответсвенная информация вывелась в текстовый файл";
    cout << endl << endl;
}

//////////////////////////////////////////////////////////////////////////////

void medium()
{
	cout << endl << "Необходимо считать из файла символы, развернуть их и записать в другой файл" << endl << endl;

	char arr[50], symbol;
	int count = 0;
	
	string read = "F_medium.txt"; //файл к которому мы будем обращаться;
	string new_read = "G_medium.txt";
	
	ofstream write; //создаем файловую переменную;
	
	ifstream console;

	console.open(read);

	if (!console.is_open()) //если не удается открыть файл - выдаем сообщение;
	{
		cout << "Не удалось открыть или найти необходимый файл!" << endl;
	}

	else
	{
		cout << "Файл открыт! В данном файле записано: " << endl;

		while (console.get(symbol)) //посимвольно считываем в консоль данные из файла;
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

	for (int i = 0; i < count / 2; i++) //разворачиваем массив;
	{
		char temp = arr[i];
		arr[i] = arr[count - i];
		arr[count - i] = temp;
	}

	write.open(new_read);

	if (!write.is_open()) //если не удается открыть файл - выдаем сообщение;
	{
		cout << "Не удалось открыть или найти необходимый файл!" << endl;
	}

	else
	{
		cout << "Соответсвенная информация была записана в новый файл" << endl;

		for (int i = 0; i < count; i++)
		{
			write << arr[i];
		}
	}

	cout << endl << endl;
}

/////////////////////////////////////////////////////////////////////////////

void hard()
{
	cout << "Необходимо создать 2 файла. В один из них необходимо записать N-ое кол-во матриц K-ого порядка\n";
	cout << "В другое L-ое кол-во матриц. В файл с меньшим кол-вом матриц записать недостающее кол-во единичных матриц\n";
	cout << "Вывести данные из файлов в консоль" << endl;

	string read = "One_hard.txt"; //файлы с которыми мы будем работать;
	string read_1 = "Two_hard.txt";

	ofstream write, write_1;
	
	int quantity, quantity_2, order,** arr;
	const int order_2 = 4;
	int arr_1[order_2][order_2];
	char symbol;

	//Вводи кол-во матриц и размерность;
	cout << endl << "Введите количество матриц для записи в 1-й файл: ";

	cin >> quantity;

	cout << endl << "Введите порядок данных матриц: ";

	cin >> order;

	cout << endl << "Введите кол-во матриц для записи во 2-й файл(их порядок равен 4): ";

	cin >> quantity_2;

	cout << endl;

	//создаем двумерный динамический массив;
	arr = new int* [order];

	for (int i = 0; i < order; i++)
	{
		arr[i] = new int[order];
	}

	write.open(read);
	write_1.open(read_1);

	//записываем в оба файла матрицы;
	if (!write.is_open()) //если не удается открыть файл - выдаем сообщение;
	{
		cout << endl << "Не удалось открыть или найти необходимый первый файл!" << endl;
	}

	else
	{
		cout << endl << "В файл № 1 записано заданное кол-во матриц" << endl << endl;
		write << "Массивы первого файла: " << endl << endl;

		for (int k = 0; k < quantity; k++)
		{
			for (int i = 0; i < order; i++)
			{
				for (int j = 0; j < order; j++)
				{
					arr[i][j] = rand() % 10 - 5;
					write << arr[i][j] << "\t";
				}

				write << endl;
			}

			write << endl;
		}
    }

	if (!write_1.is_open()) //если не удается открыть файл - выдаем сообщение;
	{
		cout << endl << "Не удалось открыть или найти необходимый второй файл!" << endl;
	}

	else
	{
		cout << endl << "В файл № 2 записано заданное кол-во матриц" << endl << endl;
		write_1 << "Массивы второго файла: " << endl << endl;

		for (int k = 0; k < quantity_2; k++)
		{
			for (int i = 0; i < order_2; i++)
			{
				for (int j = 0; j < order_2; j++)
				{
					arr_1[i][j] = rand() % 20 - 10;
					write_1 << arr_1[i][j] << "\t";
				}

				write_1 << endl;
			}

			write_1 << endl;
		}
	}

	//закрываем файлы;
	write.close();
	write_1.close();

	//если кол-во матриц в первом файле не равно 1, то записываем в файл с большим кол-вом матриц недостающие единичные матрицы;
	if (quantity != 1)
	{
		if (quantity > quantity_2)
		{
			int different = quantity - quantity_2;

			write.open(read);

			if (!write.is_open()) //если не удается открыть файл - выдаем сообщение;
			{
				cout << endl << "Не удалось открыть или найти первый файл для перезаписи!" << endl;
			}

			else
			{
				cout << endl << "В файл № 1 записано недостающее число матриц" << endl << endl;
				write << "Недостающие массивы файла: " << endl << endl;

				for (int k = 0; k < different; k++)
				{
					for (int i = 0; i < order; i++)
					{
						for (int j = 0; j < order; j++)
						{
							arr[i][j] = 1;
							write << arr[i][j] << "\t";
						}

						write << endl;
					}

					write << endl;
				}

				write << endl << "Изначальные массивы данного файла: " << endl << endl;

				for (int k = 0; k < quantity; k++)
				{
					for (int i = 0; i < order; i++)
					{
						for (int j = 0; j < order; j++)
						{
							arr[i][j] = rand() % 10 - 5;
							write << arr[i][j] << "\t";
						}

						write << endl;
					}

					write << endl;
				}
			}

			write.close();
		}

		if (quantity < quantity_2)
		{
			int different = quantity_2 - quantity;

			write_1.open(read_1);

			if (!write_1.is_open()) //если не удается открыть файл - выдаем сообщение;
			{
				cout << endl << "Не удалось открыть или найти второй файл для перезаписи!" << endl;
			}

			else
			{
				cout << endl << "В файл № 2 записано недостающее число матриц" << endl << endl;
				write_1 << "Недостающие массивы файла: " << endl << endl;

				for (int k = 0; k < different; k++)
				{
					for (int i = 0; i < order_2; i++)
					{
						for (int j = 0; j < order_2; j++)
						{
							arr_1[i][j] = 1;
							write_1 << arr_1[i][j] << "\t";
						}

						write_1 << endl;
					}

					write_1 << endl;
				}

				write_1 << endl << "Изначальные массивы данного файла: " << endl << endl;

				for (int k = 0; k < quantity_2; k++)
				{
					for (int i = 0; i < order_2; i++)
					{
						for (int j = 0; j < order_2; j++)
						{
							arr_1[i][j] = rand() % 10 - 5;
							write_1 << arr_1[i][j] << "\t";
						}

						write_1 << endl;
					}

					write_1 << endl;
				}
			}

			write_1.close();
		}
	}

	//выводим данные в консоль;
	ifstream console, console_1;

	console.open(read);
	console_1.open(read_1);

	if (!console.is_open()) //если не удается открыть файл - выдаем сообщение;
	{
		cout << endl << "Не удалось открыть или найти первый файл!";
	}

	else
	{
		cout << endl << "Файл номер 1 открыт! В данном файле записано: " << endl << endl;

		while (console.get(symbol)) //посимвольно считываем в консоль данные из файла;
		{
			cout << symbol;
		}
	}

	if (!console_1.is_open()) //если не удается открыть файл - выдаем сообщение;
	{
		cout << endl << "Не удалось открыть или найти первый файл!";
	}

	else
	{
		cout << endl << "Файл номер 2 открыт! В данном файле записано: " << endl << endl;

		while (console_1.get(symbol)) //посимвольно считываем в консоль данные из файла;
		{
			cout << symbol;
		}
	}

	//закрываем файлы;
	console.close();
	console_1.close();

	cout << endl << endl;
}

////////////////////////////////////////////////////////////////////////////

int main()
{
	setlocale(LC_ALL, "RU");

	int a;
	int count = 0;

	do
	{
		cout << "Введите номер задания (easy - 1), (medium - 2), (hard - 3): ";

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

		if (a == 3)
		{
			hard();
			count++;
		}

	} while (count == 0);

	int b;

	do
	{

		count = 0;

		cout << "Продолжить ввод? Да - 1, Нет - 2: ";

		cin >> b;

		cout << endl;

		if (b == 1)
		{
			count++;
			main();
		}

		if (b == 2)
		{
			cout << "Вы решили не продолжать";
			count++;
			break;
		}

	} while (count == 0);
}

/////////////////////////////////////////////////////////////////