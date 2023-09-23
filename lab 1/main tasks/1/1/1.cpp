#include <iostream>
#include <string>
using namespace std;

/*
C - C++
strlen - strlen
strcpy - strcpy
strcmp - strcmp
strcat - strcat
someString[index] - someString[index]
NONE - push_back
NONE - pop_back

Основная разница строк между С и С++ заключается в том, что в С строка - это массив символов(char[]), пока как в С++ - это отдельный элемент (std::string)
*/


int main() {
    string str;
    char temp;
    cout << "Input your string: ";
    getline(cin, str);
    short len = str.length();
    remove_if(str.begin(), str.end(), isspace);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    cout << "\nResult: " << str;

    return 0;
}