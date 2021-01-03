#include <iostream>
#include <string>
#include "Ticket2_Lib.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru-RU.UTF-8");
    cout << "Билет №2" << endl;
    int quantity;                                                                   //количество строк
    string* str_array = init(&quantity);                                            //вводим строки с числами в двоичной системе счисления
    string* M = get_dec_array(str_array, quantity);                                 //создаем массив M, в котором храним строки с переведенными в десятичную систему значениями
    delete[] str_array;                                                             //удаляем больше ненужный динамический массив
    cout << "Массив M (числа, переведенные в 10-чную систему счисления):" << endl;
    print_array(M, quantity);
    int** A = create_matrix(quantity);                                              //создаем матрицу A
    fill_matrix(A, quantity, M);                                                    //заполняем ее нашими и, если не хватает, случайными числами
    delete[] M;                                                                     //удаляем больше ненужный динамический массив
    cout << "Матрица A: " << endl;
    print_matrix(A, quantity);
    sort_matrix(A, quantity);                                                       //сортируем матрицу A
    cout << "Отсортированная матрица A: " << endl;
    print_matrix(A, quantity);
    del_matrix(A, quantity);                                                        //удаляем больше ненужный двумерный динамический массив
    system("pause");
}