/*!
\file
\brief Основной файл

Данный файл содержит в себе весь исходный код калькулятора
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Простой калькулятор, считывающий строку из файла input.txt и выводящий результат на консоль
 * 
 * @return Если вернул 0, значит программа завершилась успешно
 */
int main()
{
    string input; ///< Объявление переменной, в которой будут храниться входные данные
    ifstream in("input.txt"); ///< Открытие файла input.txt
    getline(in, input); ///< Чтение из открытого файла в строку input
    int res = 0; ///< Объявление переменной, в которой будет храниться результат вычислений
    /// Объявление переменной, в которой будет храниться индекс первого символа, который является цифрой
    int firstNumberPos = input.length() - 1; 
    /**
     * @brief цикл бегущий с конца строки, производящий все вычисления
     * 
     * @param i - итератор цикла
     */
    for(int i = input.length() - 1; i >= 0; i--) {
        auto c = input[i]; ///< Объявление переменной, в которой храниться текущий символ
        if (c == '+' ) {
            /// Добавляем к результату чило, стоящее за символом +
            res += stoi(input.substr(i + 1, firstNumberPos - i));
            firstNumberPos = i + 1; ///< Обновляем индекс первого символа, который является цифрой
        }
        else if (c == '-') {
            /// Вычитаем из результата чило, стоящее за символом -
            res -= stoi(input.substr(i + 1, firstNumberPos - i));
            firstNumberPos = i + 1; ///< Обновляем индекс первого символа, который является цифрой
        }
    }  
    /// Добавляем к результату первое чило, если ещё не сделали этого
    if (firstNumberPos != 1)
        res += stoi(input.substr(0, firstNumberPos)); 
    cout << res << endl; /// Выводим результат на консоль
    return 0;
}