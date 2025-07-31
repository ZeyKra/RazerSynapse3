#include <iostream> 
#include <vector> 
#include <string> 
#include <fstream> 
#include <windows.h> 
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

int main() {
	srand(time(NULL));
	bool loopd = true;
	bool sus = true;
	int state;
	double cps = 0;
	bool cont = true;
	string translate = "";
	LPCTSTR WindowName = NULL;
	POINT pt;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
	cout << "Zlads Clicker Made by ZeyKra_ lol" << endl;
	cout << "" << endl;
	while (cont) {
		cout << "Entrez le nombre de cps que vous voulez faire ! (ex: 10) : ";
		getline(cin, translate);
		stringstream trs(translate);
		if (trs >> cps && cps >= 0 && cps <= 100 ) {
			cont = false;
		}
	}	
	if (cps) {
		LPCTSTR WindowName = "Zlads CLicker By ZeyKra_ lol";
	}
	HWND hwnd = FindWindowA(NULL, WindowName);
	if (hwnd == NULL) {
		cout << "Je ne trouve pas le program :x" << endl;
		Sleep(2000);
		exit(-2);
	}
	else {
		hwnd = GetForegroundWindow();
		Sleep(1000);
		cout << "Lancement de l'autoclick'..." << endl;
		Sleep(1000);
		cout << "Autoclick operationnel !" << endl;
		cout << " " << endl;
		cout << " " << endl;
		cout << "Zlads Clicker Made by ZeyKra_" << endl;
		//SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "F7 = Inactif ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "|";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << " F8 = Actif";
	}

	while (sus = true) {
		loopd = true;
		hwnd = GetForegroundWindow();
		if (GetAsyncKeyState(VK_END)) {
			state = 0;
		}

		if (GetAsyncKeyState(VK_LBUTTON)) {
			state = 1;
		}

		while (GetAsyncKeyState(VK_LBUTTON)) {
			int min = -20;
			int max = 50;
			//int delay = (cps + min + (rand() % (int)(max - min + 1)));
			int add = (cps / 10);
			int finalcps = (cps + add);
			int cc = (1000 / finalcps);
			int delay = (cc / 2); //+ (rand() % (int)(max - min)));
			//SetConsoleTextAttribute(hStdOut, 15);
			GetCursorPos(&pt);
			SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pt.x, pt.y));
			Sleep(delay);
			SendMessage(hwnd, WM_LBUTTONUP, 0, MAKELPARAM(pt.x, pt.y));
			Sleep(delay);
		}

		
		if (GetAsyncKeyState(0x76)) {
			if (sus == true) {
				while (loopd) {
					sus = false;
					if (GetAsyncKeyState(0x76)) {
						loopd = false;
						sus = true;								
					}
			    }
	 	    }
	    }
	}
}
