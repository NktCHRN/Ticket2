#pragma once
#include <iostream>
#include <cmath>
#include <string>

std::string* init(int*);							//ввод строк
std::string del_unnecessary(std::string);			//удаление ненужных символов в строках (всех, кроме 0 и 1)
std::string* get_dec_array(std::string*, int);		//получение массива десятичных чисел
int bin_to_dec(std::string);						//перевод из двоичной в десятичную
void print_array(std::string*, int);				//вывод массива
int** create_matrix(int);							//создание матрицы
void print_matrix(int**, int);						//вывод матрицы
void fill_matrix(int**, int, std::string*);			//заполнение матрицы
void sort_matrix(int**, int);						//сортировка матрицы
int find_min(int*, int);							//найти минимальное число в строке (по модулю)
void swap_rows(int*, int*, int);					//поменять местами рядки
void del_matrix(int**, int);						//удаление двумерного динамического массива