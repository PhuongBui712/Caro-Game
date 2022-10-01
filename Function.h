#ifndef _MY_FUNCTION_H
#define _MY_FUNCTION_H
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <MMSystem.h>
#include <fstream>

using namespace std;
enum Status { UP, DOWN, OTHER };

struct WASD {
	Status wasd;
};

struct SETTINGS {
	bool music; // âm nhạc
	bool g_music; // nhạc game
	bool language; // ngôn ngữ
};

struct _POINT {
	int x, y, c;
	int getCheck() { return c; }
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	void setX(int pX)
	{
		x = pX;
	}
	void setY(int pY)
	{
		y = pY;
	}
	bool setCheck(int pCheck)
	{
		if (pCheck == -1 || pCheck == 1 || pCheck == 0)
		{
			c = pCheck;
			return true;
		}
		return false;
	}
};

// ĐỔI TÊN CONSOLE
BOOL WINAPI SetConsoleTitle(
	_In_ LPCTSTR lpConsoleTitle
);

////////////////// HẰNG + BIẾN //////////////////////////
const int COLUMN = 10; // Kích thức ma trận bàn cờ
const int ROW = 10;
const int LEFT = 8;
const int TOP = 4;
extern _POINT _A[ROW][COLUMN];
extern bool _TURN; // true là lượt người thứ nhất và false là lượt người thứ hai
extern int _X, _Y; // Tọa độ hiện hành trên màn hình bàn cờ
extern int _COMMAND; // Biến nhận giá trị phím người dùng nhập
extern int score1, score2;

////////////////////////////////////////////////////////////

////////////////// HÀM MẶC ĐỊNH //////////////////////////
void fixConsoleWindow();
void resizeConsole(int width, int height);
void textcolor(int color);
void GotoXY(int x, int y);
// KHỞI ĐỘNG KẾT THÚC GAME
void ResetData();
void StartGame(SETTINGS stt);
void ExitGame();
// DI CHUYỂN 
void MoveUp();
void MoveLeft();
void MoveDown();
void MoveRight();
////////////////////////////////////////////////////////////

// HÀM GIAO DIỆN + ĐIỀU KHIỂN MENU
void DrawMenuTitle(SETTINGS stt);
void DrawMenuSubtitle();
void startMenu(SETTINGS stt);
void Control(char key, WASD& replace_wasd, int& n, SETTINGS stt);

// HÀM TRONG MỤC CÀI ĐẶT
void SettingFrame();
void Settings(char key, WASD& replace_wasd, int& n, SETTINGS& stt, int& ignore);

////////////////// HÀM TRONG GAME //////////////////////////
// VẼ BẢNG TÍNH ĐIỂM
void drawTable1(char khung);
void drawTable2(char khung);
void drawTable(SETTINGS stt);
// VẼ BÀN CỜ
void drawRow(char gt, char gp, char dn, char dnor, int c);
void drawBoard(SETTINGS stt);
// VẼ QUÂN CỜ
void DrawX(int _X, int _Y);
void DrawO(int _X, int _Y);
void startPlaying(SETTINGS stt);////
// BẢNG XIN HÒA
void drawNote(SETTINGS stt);
int controlNote(SETTINGS stt);
void deleteNote();
// TÍNH ĐIỂM + TÍNH TURN
void Score(int signal);
void OutputScore();
void Turn(int turn);
////////////////////////////////////////////////////////////

// CHECK THẮNG THUA HÒA
int CheckBoard();
int ProcessFinish(int pWhoWin);
int AskContinue(SETTINGS stt);
int TestBoard(SETTINGS stt);

// HÀM LƯU/LOAD GAME
void ReadNameFile();
int getXAt(int i, int j);
int getYAt(int i, int j);
void loadData(_POINT& p, int i, int j, int& k);
void SaveGame();
void LoadGame(char data[30], SETTINGS stt, _POINT& p);

#endif