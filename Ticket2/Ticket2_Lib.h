#pragma once
#include <iostream>
#include <cmath>
#include <string>

std::string* init(int*);							//���� �����
std::string del_unnecessary(std::string);			//�������� �������� �������� � ������� (����, ����� 0 � 1)
std::string* get_dec_array(std::string*, int);		//��������� ������� ���������� �����
int bin_to_dec(std::string);						//������� �� �������� � ����������
void print_array(std::string*, int);				//����� �������
int** create_matrix(int);							//�������� �������
void print_matrix(int**, int);						//����� �������
void fill_matrix(int**, int, std::string*);			//���������� �������
void sort_matrix(int**, int);						//���������� �������
int find_min(int*, int);							//����� ����������� ����� � ������ (�� ������)
void swap_rows(int*, int*, int);					//�������� ������� �����
void del_matrix(int**, int);						//�������� ���������� ������������� �������