#include "Ticket2_Lib.h"

std::string* init(int* quantity) {
	std::cout << "Введите количество строк: ";
	do {
		std::cin >> *quantity;				//вводим количество строк по указателю
		if (*quantity <= 0) {
			std::cout << "Вы ввели число, меньшее или равное нулю. Перевведите число." << std::endl;
			std::cin.clear();
			std::cin.ignore(8192, '\n');    //пропускает до 8192 символов после введенного вплоть до перехода на новую строку
		}
	} while (*quantity <= 0);
	std::string* str_array = new std::string[*quantity];		//создаем массив строк
	std::cout << "Введите строки: " << std::endl;
	std::cin.ignore(8192, '\n');			//пропускает до 8192 символов после введенного вплоть до перехода на новую строку
	for (int i = 0; i < *quantity; i++)
		getline(std::cin, str_array[i]);						//вводим строки
	for (int i = 0; i < *quantity; i++) {
		if (str_array[i] != del_unnecessary(str_array[i])) {	//удаляем ненужные/некорректные символы и предупреждаем об это пользователя
			std::cout << "Внимание! Ваша строка " << i + 1 << " будет рассмотрена как: " << std::endl;
			str_array[i] = del_unnecessary(str_array[i]);
			std::cout << str_array[i] << std::endl;
		}
	}
	return str_array;
}

std::string del_unnecessary(std::string s) {
	std::string edited_string = "";
	bool is_empty = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0' || s[i] == '1') {						//символы-цифры двоичной системы счисления
			edited_string.push_back(s[i]);
			is_empty = false;
		}
		else if(s[i] == ' ' && edited_string != "" && i < s.size() - 1 && s[i + 1] != ' ')				//для ПРОБЕЛОВ: проверяем, не стоит ли пробел первым/последним и идет ли после него что-то (убираем двойные-тройные пробелы)
			edited_string.push_back(s[i]);
	}
	if (is_empty)												//если отредактированная строка пустая, добавляем '0'
		edited_string += '0';
	return edited_string;
}

std::string* get_dec_array(std::string* bin_array, int size) {
	std::string* M = new std::string[size];						//новый массив строк для переведенных в десятичную систему счисления чисел
	int start_pos;
	int temp_number, str_size;
	for (int i = 0; i < size; i++) {
		M[i] = "";
		str_size = bin_array[i].size();							//размер строки для перевода
		start_pos = 0;
		for (int j = 0; j < str_size; j++) {
			if (bin_array[i][j] == ' ') {						//находим пробел
				temp_number = bin_to_dec((bin_array[i]).substr(start_pos, j - start_pos));		//переводим число из подстроки
				M[i] += std::to_string(temp_number) + ' ';										//записываем переведенное и пробел после него
				start_pos = j + 1;
			}
			else if (j == str_size - 1) {						//или конец строки
				temp_number = bin_to_dec(bin_array[i].substr(start_pos, j - start_pos + 1));		//переводим число из подстроки
				M[i] += std::to_string(temp_number);			//если это конец строки, то записываем только переведенное число, без пробела после
			}
		}
	}
	return M;
}

int bin_to_dec(std::string s) {
	int dec_number = 0;
	int size = s.size();
	for (int i = 0; i < size; i++)
		dec_number += (int)pow(2, size - i - 1) * (s[i] - 48);			//переводим char в int (48 - '0' в ASCII)
	return dec_number;
}

void print_array(std::string* s, int size) {							//вывод массива строк
	for (int i = 0; i < size; i++)
		std::cout << s[i] << std::endl;
}

int** create_matrix(int size) {
	int** array = new int* [size];                                                          //создание внешнего массива
	for (int i = 0; i < size; i++)
		array[i] = new int[size];                                                           //создание вложенного массива
	return array;
}

void fill_matrix(int** matrix, int size, std::string* str_array) {
	srand(time(NULL));
	bool rand_initialized = false;																	//инициализированы ли начало и конец рандома
	int rand_start, rand_end, start_pos, found;
	for (int i = 0; i < size; i++) {
		str_array[i] += ' ';																		//для удобства добавляем пробел в конце строки
		start_pos = 0;
		for (int j = 0; j < size; j++) {
			found = str_array[i].find(' ', start_pos);												//ищем пробел-разделитель, начиная со стартовой позиции
			if (found != -1) {
				matrix[i][j] = stoi(str_array[i].substr(start_pos, found - start_pos + 1));			//stoi - стд.функция, конвертация из строки в число
				start_pos = found + 1;
			}
			else {
				if (!rand_initialized) {															//если начало и конец еще не инициализированы - инициализируем
					std::cout << "Ваших чисел не хватило для заполнения всей матрицы, поэтому оставшиеся будут сгенерированы случайным образом." << std::endl;
					do {
						std::cout << "Введите начало диапазона случайных чисел: ";
						std::cin >> rand_start;
						std::cin.clear();				//чистим поток
						std::cin.ignore(8192, '\n');    //пропускает до 8192 символов после введенного вплоть до перехода на новую строку
					} while (std::cin.fail());			//если введена не цифра
					do {
						std::cout << "Введите конец диапазона случайных чисел: ";
						std::cin >> rand_end;
						std::cin.clear();				//чистим поток
						std::cin.ignore(8192, '\n');    //пропускает до 8192 символов после введенного вплоть до перехода на новую строку
					} while (std::cin.fail() || rand_end < rand_start);		//если введена не цифра или конец меньше начала
					rand_initialized = true;
				}
				matrix[i][j] = rand() % (rand_end - rand_start + 1) + rand_start;		//сгенерировать рандом число из нужного промежутка
			}
		}
	}
}

void print_matrix(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << matrix[i][j] << "\t";                                        //вывод элементов матрицы
		}
		std::cout << std::endl;
	}
}

void sort_matrix(int** matrix, int size) {											//сортировка пузырьком
	for (int i = 0; i < size - 1; i++)												//проходы алгоритма
		for (int j = 0; j < size - i - 1; j++)										//цикл для перебора элементов массива
			if (find_min(matrix[j], size) < find_min(matrix[j + 1], size))			//сравниваем мин.элементы рядков (по модулю)
				swap_rows(matrix[j], matrix[j + 1], size);							//меняем рядки местами
}

int find_min(int* array, int size) {
	int min = array[0];
	for (int i = 1; i < size; i++)
		if (abs(array[i]) < abs(min))												//abs - стд.функция из библиотеки cmath, модуль числа
			min = array[i];															//находим минимальное по модулю
	return min;
}

void swap_rows(int* row1, int* row2, int size) {
	for (int i = 0; i < size; i++) {												//смена рядков местами
		row1[i] += row2[i];
		row2[i] = row1[i] - row2[i];
		row1[i] -= row2[i];
	}
}

void del_matrix(int** array, int size) {
	for (int i = 0; i < size; i++)                                                  //удаление матриц циклом - сначала вложенные, потом внешняя
		delete[] array[i];
	delete[] array;
}