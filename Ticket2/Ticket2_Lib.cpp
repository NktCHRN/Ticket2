#include "Ticket2_Lib.h"

std::string* init(int* quantity) {
	std::cout << "������� ���������� �����: ";
	do {
		std::cin >> *quantity;				//������ ���������� ����� �� ���������
		if (*quantity <= 0) {
			std::cout << "�� ����� �����, ������� ��� ������ ����. ����������� �����." << std::endl;
			std::cin.clear();
			std::cin.ignore(8192, '\n');    //���������� �� 8192 �������� ����� ���������� ������ �� �������� �� ����� ������
		}
	} while (*quantity <= 0);
	std::string* str_array = new std::string[*quantity];		//������� ������ �����
	std::cout << "������� ������: " << std::endl;
	std::cin.ignore(8192, '\n');			//���������� �� 8192 �������� ����� ���������� ������ �� �������� �� ����� ������
	for (int i = 0; i < *quantity; i++)
		getline(std::cin, str_array[i]);						//������ ������
	for (int i = 0; i < *quantity; i++) {
		if (str_array[i] != del_unnecessary(str_array[i])) {	//������� ��������/������������ ������� � ������������� �� ��� ������������
			std::cout << "��������! ���� ������ " << i + 1 << " ����� ����������� ���: " << std::endl;
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
		if (s[i] == '0' || s[i] == '1') {						//�������-����� �������� ������� ���������
			edited_string.push_back(s[i]);
			is_empty = false;
		}
		else if(s[i] == ' ' && edited_string != "" && i < s.size() - 1 && s[i + 1] != ' ')				//��� ��������: ���������, �� ����� �� ������ ������/��������� � ���� �� ����� ���� ���-�� (������� �������-������� �������)
			edited_string.push_back(s[i]);
	}
	if (is_empty)												//���� ����������������� ������ ������, ��������� '0'
		edited_string += '0';
	return edited_string;
}

std::string* get_dec_array(std::string* bin_array, int size) {
	std::string* M = new std::string[size];						//����� ������ ����� ��� ������������ � ���������� ������� ��������� �����
	int start_pos;
	int temp_number, str_size;
	for (int i = 0; i < size; i++) {
		M[i] = "";
		str_size = bin_array[i].size();							//������ ������ ��� ��������
		start_pos = 0;
		for (int j = 0; j < str_size; j++) {
			if (bin_array[i][j] == ' ') {						//������� ������
				temp_number = bin_to_dec((bin_array[i]).substr(start_pos, j - start_pos));		//��������� ����� �� ���������
				M[i] += std::to_string(temp_number) + ' ';										//���������� ������������ � ������ ����� ����
				start_pos = j + 1;
			}
			else if (j == str_size - 1) {						//��� ����� ������
				temp_number = bin_to_dec(bin_array[i].substr(start_pos, j - start_pos + 1));		//��������� ����� �� ���������
				M[i] += std::to_string(temp_number);			//���� ��� ����� ������, �� ���������� ������ ������������ �����, ��� ������� �����
			}
		}
	}
	return M;
}

int bin_to_dec(std::string s) {
	int dec_number = 0;
	int size = s.size();
	for (int i = 0; i < size; i++)
		dec_number += (int)pow(2, size - i - 1) * (s[i] - 48);			//��������� char � int (48 - '0' � ASCII)
	return dec_number;
}

void print_array(std::string* s, int size) {							//����� ������� �����
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < s[i].size(); j++)
			std::cout << s[i][j];
		std::cout << std::endl;
	}
}

int** create_matrix(int size) {
	int** array = new int* [size];                                                          //�������� �������� �������
	for (int i = 0; i < size; i++)
		array[i] = new int[size];                                                           //�������� ���������� �������
	return array;
}

void fill_matrix(int** matrix, int size, std::string* str_array) {
	srand(time(NULL));
	bool rand_initialized = false;																	//���������������� �� ������ � ����� �������
	int rand_start, rand_end, start_pos, found;
	for (int i = 0; i < size; i++) {
		str_array[i] += ' ';																		//��� �������� ��������� ������ � ����� ������
		start_pos = 0;
		for (int j = 0; j < size; j++) {
			found = str_array[i].find(' ', start_pos);												//���� ������-�����������, ������� �� ��������� �������
			if (found != -1) {
				matrix[i][j] = stoi(str_array[i].substr(start_pos, found - start_pos + 1));			//stoi - ���.�������, ����������� �� ������ � �����
				start_pos = found + 1;
			}
			else {
				if (!rand_initialized) {															//���� ������ � ����� ��� �� ���������������� - ��������������
					std::cout << "����� ����� �� ������� ��� ���������� ���� �������, ������� ���������� ����� ������������� ��������� �������." << std::endl;
					do {
						std::cout << "������� ������ ��������� ��������� �����: ";
						std::cin >> rand_start;
						std::cin.clear();				//������ �����
						std::cin.ignore(8192, '\n');    //���������� �� 8192 �������� ����� ���������� ������ �� �������� �� ����� ������
					} while (std::cin.fail());			//���� ������� �� �����
					do {
						std::cout << "������� ����� ��������� ��������� �����: ";
						std::cin >> rand_end;
						std::cin.clear();				//������ �����
						std::cin.ignore(8192, '\n');    //���������� �� 8192 �������� ����� ���������� ������ �� �������� �� ����� ������
					} while (std::cin.fail() || rand_end < rand_start);		//���� ������� �� ����� ��� ����� ������ ������
					rand_initialized = true;
				}
				matrix[i][j] = rand() % (rand_end - rand_start + 1) + rand_start;		//������������� ������ ����� �� ������� ����������
			}
		}
	}
}

void print_matrix(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << matrix[i][j] << "\t";                                        //����� ��������� �������
		}
		std::cout << std::endl;
	}
}

void sort_matrix(int** matrix, int size) {											//���������� ���������
	for (int i = 0; i < size - 1; i++)												//������� ���������
		for (int j = 0; j < size - i - 1; j++)										//���� ��� �������� ��������� �������
			if (find_min(matrix[j], size) < find_min(matrix[j + 1], size))			//���������� ���.�������� ������ (�� ������)
				swap_rows(matrix[j], matrix[j + 1], size);							//������ ����� �������
}

int find_min(int* array, int size) {
	int min = array[0];
	for (int i = 1; i < size; i++)
		if (abs(array[i]) < abs(min))												//abs - ���.������� �� ���������� cmath, ������ �����
			min = array[i];															//������� ����������� �� ������
	return min;
}

void swap_rows(int* row1, int* row2, int size) {
	for (int i = 0; i < size; i++) {												//����� ������ �������
		row1[i] += row2[i];
		row2[i] = row1[i] - row2[i];
		row1[i] -= row2[i];
	}
}

void del_matrix(int** array, int size) {
	for (int i = 0; i < size; i++)                                                  //�������� ������ ������ - ������� ���������, ����� �������
		delete[] array[i];
	delete[] array;
}