#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>    
#include <string>
#include <thread>
#include "Hlibrary.h"

int main()
{
    std::cout << "=====FILE SEARCH=====";
    std::cout << "\nExample : \nEnter the name of file : some_file.exe \n\nEnter the name of Folder : Windows";
    std::cout << "\n\nEnter the name of file(folder) : "; // Вводиться назва файлу(з розширинням) або папки 
    std::wstring name;
    std::getline(std::wcin, name);
    //створюю масив потоків 
    std::wstring folders[] = { L"C:" ,L"C:\\Microsoft" ,L"C:\\Windows" ,L"C:\\Program Files",L"C:\\Program Files (x86)", L"C:\\Users",L"D:"};
    std::thread myThreads[6];
    for (int i = 0; i < 6; i++)
    {
        myThreads[i] = std::thread(FindFile, folders[i], name);
        myThreads[i].join();
    }
    std::cin.get();// для того щоб при закінченні роботи не закривався ехе 
    return 0;
}