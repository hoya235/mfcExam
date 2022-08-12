// MainDLL.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include <Windows.h>
#include <iostream>

// [Implicit Linking]
//#include "../CreateDLL/MyMath.h"
//#pragma comment(lib, "../x64/Debug/CreateDLL.lib")

// [Explicit Linking]
typedef double(*DLL_SUM)(double a, double b);

int main()
{
	// [Implicit Linking]
	//std::cout << "Sum: " << Sum(5.0, 3.0) << std::endl;
	//std::cout << "Mul: " << Mul(5.0, 3.0) << std::endl;


	// [Explicit Linking]
	std::string path = "../x64/Debug/CreateDLL.dll";

	HMODULE hDll = ::LoadLibraryA(path.c_str());

	if (hDll != NULL) {
		DLL_SUM pFunc = (DLL_SUM)::GetProcAddress(hDll, "Sum");
		double ret = pFunc(5.0, 7.0);
		std::cout << "Result: " << ret << std::endl;

		::FreeLibrary(hDll);
	}

	getchar();

    return 0;
}

