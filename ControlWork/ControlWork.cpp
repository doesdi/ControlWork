////Задание 2. Используя функцию fgetwc() посимвольно читать данные из файла и выводить в stdout, 
////разделяя символы пробелами(например, для содержимого файла "Hello, world!" должно получиться "H e l l o , w o r l d ! ").
////Убедиться, что, программа корректно работает с файлами UTF - 8. Имя файла для открытия получать из командной строки.
///C:\Users\samoi\source\repos\ControlWork\ControlWork\test.utf8
//C:\Users\samoi\source\repos\ControlWork\ControlWork\Text.txt
#include <iostream>
#include <Windows.h>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, ".1251");
    FILE* stream;
    wchar_t ch; 
    string path;
    cout << "Введите путь к файлу:";
    cin >> path;
    fopen_s(&stream, path.data(), "r, ccs=UTF-8"); 
    if (stream == NULL)
    {
        cout << "Ошибка открытия файла";
        exit(0);
    }

    ch = fgetwc(stream); 
    while (ch != WEOF)
    {
        wcout.put(ch);
        if (ch != '\n' && ch != ' ') 
            wcout.put(' '); 
        ch = fgetwc(stream);
    }
    fclose(stream);
}
