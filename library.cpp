#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>    
#include <string>
#include <thread>
#include "Hlibrary.h"

bool stop = false;//����� ��� ������� ������ ���� ��� ���������� ����

void FindFile(const std::wstring& directory, std::wstring name) // ������� ��� ������ ����� ����� 
{

    std::wstring tmp = directory + L"\\*";
    WIN32_FIND_DATAW file;
    HANDLE search_handle = FindFirstFileW(tmp.c_str(), &file);
    if (search_handle != INVALID_HANDLE_VALUE)
    {
        if (stop == false)
        {
            std::vector<std::wstring> directories;
            do
            {
                if ((!lstrcmpW(file.cFileName, L".")) || (!lstrcmpW(file.cFileName, L"..")))
                      continue;
                tmp = directory + L"\\" + std::wstring(file.cFileName);
                //  std::wcout << tmp << std::endl;    
                    directories.push_back(tmp);// ��� ���������� ����������� � �������� �����
                if (file.cFileName == name) // �������� ����� ����� 
                {
                    std::wcout << "\nName  :   " << name << "\nDir   :   " << tmp << "\n";
                    stop = true;
                    break;
                }

            } while (FindNextFileW(search_handle, &file));

            FindClose(search_handle);
            for (std::vector<std::wstring>::iterator i = directories.begin(), end = directories.end(); i != end; i++) // ������� ��� ��� ���������� �������� �� ����� ��������
                FindFile(*i, name);
        }

    }
}