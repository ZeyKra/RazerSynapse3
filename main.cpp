#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <thread>
#include <unordered_map>

using namespace std;

void thread_click(LPCSTR &WindowName)  
{
	std::cout << "Thread 2 started" << std::endl;
	HWND hwnd = FindWindowA(NULL, WindowName);
	hwnd = GetForegroundWindow();
	while (true == true)
	{
		std::cout << "clickin" << "\n";
		Sleep(2000);
	}
}

int main()
{
	srand(time(NULL));
	bool toggle_state = true;
	bool loopd = true;
	bool sus = true;
	int state;
	double cps = 0;
	bool cont = true;
	string translate = "";
	LPCSTR WindowName = NULL;
	POINT pt;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
	cout << "RazerSynapse3 by ZeyKra_ lol" << endl;
	cout << "" << endl;
	while (cont)
	{
		cout << "Entrez le nombre de cps que vous voulez faire ! (ex: 10) : ";
		getline(cin, translate);
		stringstream trs(translate);
		if (trs >> cps && cps >= 0 && cps <= 100)
		{
			cont = false;
		}
	}
	if (cps)
	{
		WindowName = "Razer Synapse3";
	}
	HWND hwnd = FindWindowA(NULL, WindowName);
	/*
	if (hwnd == NULL)
	{
		cout << "Programme non trouvé" << endl;
		Sleep(2000);
		exit(-2);
	}
	*/
	{
		hwnd = GetForegroundWindow();
		//Sleep(1000);
		cout << "Lancement de RazerSynapse3..." << endl;
		//Sleep(1000);
		cout << "RazerSynapse3 operationnel !" << endl;
		cout << " " << endl;
		cout << " " << endl;
		cout << "RazerSynapse3 | By ZeyKra_" << endl;
		// SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "F7 = Inactif ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "|";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << " F8 = Actif";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	}

	std::thread t1([&toggle_state]()
				   {
		std::unordered_map<int, bool> pressed;
		std::cout << "thread 1 started" << std::endl;
		while (true == true) {
			if(GetAsyncKeyState(VK_F9)) {
				if(!pressed[VK_F9]) {
					pressed[VK_F9] = true;
					toggle_state = !toggle_state; 
					std::cout << (toggle_state ? "toggle_state : true" : "toggle_state : false") << std::endl;
				}
			} else { pressed[VK_F9] = false; }
		} });
		
	//std::thread t2(thread_click, std::ref(WindowName));

	while (sus == true)
	{
		hwnd = GetForegroundWindow();
		if (GetAsyncKeyState(VK_END))
		{
			state = 0;
		}

		if (GetAsyncKeyState(VK_LBUTTON))
		{
			state = 1;
		}

		// Si l'autoclique n'est pas activé on skip l'iteration
		if (!toggle_state) {
			continue;
		}

		if (GetAsyncKeyState(VK_LBUTTON))
		{
			//std::cout << "click" << std::endl;
			/* Futur rand implementaiton
			int min = -20;
			//int max = 50;
			int delay = (cps + min + (rand() % (int)(max - min + 1)));
			*/
			int delay = (1000 / cps) - 1;
			
			GetCursorPos(&pt);
			// SetConsoleTextAttribute(hStdOut, 15);
			SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pt.x, pt.y));
			Sleep(1);
			SendMessage(hwnd, WM_LBUTTONUP, 0, MAKELPARAM(pt.x, pt.y));
			Sleep(delay);
		}
			
	}
}