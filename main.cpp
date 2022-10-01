#include "Function.h"

_POINT _A[ROW][COLUMN];
bool _TURN;
int _X, _Y; //Tọa độ hiện hành trên màn hình bàn cờ
int _COMMAND; // Biến nhận giá trị phím người dùng nhập
int score1, score2;

int main() {
	fixConsoleWindow();
	resizeConsole(1500, 800);
	SetConsoleTitle(L"CARO PROJECT TEAM 9!!!");
	static int n;
	WASD wasd;
	SETTINGS stt;
	_POINT p;
	p.x = 0;
	p.y = 0;
	p.c = 0;
	stt.music = 1;
	stt.g_music = 1;
	stt.language = 1;
	n = 0;
	startMenu(stt);

MenuScreen:
	while (1) {
		if (_kbhit()) {
			_COMMAND = toupper(_getch());
			Control(_COMMAND, wasd, n, stt);
			if (_COMMAND == 13 || _COMMAND == 32 || _COMMAND == 'Z') {
				if (n == 0) {
					StartGame(stt);
					Score(TestBoard(stt));
					startPlaying(stt);
					startMenu(stt);
					goto MenuScreen;
				}
				if (n == 1) {
					int ignore = 0;
					char file_name[30];
					while (1)
					{
						GotoXY(0, 24);
						ReadNameFile();
						GotoXY(10, 40);
						cout << "Input the file name: ";
						cin >> file_name;
						LoadGame(file_name, stt, p);
						GotoXY(_X, _Y);
						startPlaying(stt);
						startMenu(stt);
						goto MenuScreen;
					}
					
				}
				if (n == 2) {
					int ignore = 0;
					n = 0;
					SettingFrame();
					Settings(_COMMAND, wasd, n, stt, ignore);
					while (1) {
						int c = toupper(_getch());
						Settings(c, wasd, n, stt, ignore);
						if (n == 3 && c == 13 || c == 32 || c == 'Z') {
							startMenu(stt);
							goto MenuScreen;
						}
					}
				}
				if (n == 3) {
					GotoXY(0, 100);
					break;
				}
			}
			if (_COMMAND == 27) {
				GotoXY(0, 26);
				break;
			}
		}
	}
	return 0;
}