#include "Function.h"

bool CheckDraw() {
    bool Draw = true;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (_A[i][j].c == 0) Draw = false;
        }
    }
    return Draw;
}

bool CheckWin(SETTINGS stt) {
    bool Win = false;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (_A[i][j].c != 0) {
                if ((_A[i][j].c == _A[i + 1][j].c && _A[i][j].c == _A[i + 2][j].c && _A[i][j].c == _A[i + 3][j].c && _A[i][j].c == _A[i + 4][j].c)
                    || (_A[i][j].c == _A[i][j + 1].c && _A[i][j].c == _A[i][j + 2].c && _A[i][j].c == _A[i][j + 3].c && _A[i][j].c == _A[i][j + 4].c)
                    || (_A[i][j].c == _A[i + 1][j + 1].c && _A[i][j].c == _A[i + 2][j + 2].c && _A[i][j].c == _A[i + 3][j + 3].c && _A[i][j].c == _A[i + 4][j + 4].c)
                    || (_A[i][j].c == _A[i - 1][j + 1].c && _A[i][j].c == _A[i - 2][j + 2].c && _A[i][j].c == _A[i - 3][j + 3].c && _A[i][j].c == _A[i - 4][j + 4].c)) {
                    if (stt.music == 1) PlaySound(TEXT("applause2.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    Win = true;
                }
            }
        }
    }
    return Win;
}

int TestBoard(SETTINGS stt) {
    if (CheckDraw()) return 0; // Hòa
    else {
        if (CheckWin(stt))
            return (_TURN == true ? -1 : 1); // -1 nghĩa là lượt ‘true’ thắng
        else return 2; // 2 nghĩa là chưa ai thắng
    }
}

int CheckBoard() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (_A[i][j].x + 4 == _X && _A[i][j].y + 3 == _Y && _A[i][j].c == 0) {
                if (_TURN == true) _A[i][j].c = -1; // Nếu lượt hiện hành là true thì c = -1
                else _A[i][j].c = 1; // Nếu lượt hiện hành là false thì c = 1
                return _A[i][j].c;
            }
        }
    }
    return 0;
}

void DrawWinnerScreen1() {
    GotoXY(75, 12); cout << " .----------------.  .----------------. ";
    GotoXY(75, 13); cout << "| .--------------. || .--------------. |";
    GotoXY(75, 14); cout << "| |   ______     | || |     __       | |";
    GotoXY(75, 15); cout << "| |  |_   __ \\   | || |    /  |      | |";
    GotoXY(75, 16); cout << "| |    | |__) |  | || |    `| |      | |";
    GotoXY(75, 17); cout << "| |    |  ___/   | || |     | |      | |";
    GotoXY(75, 18); cout << "| |   _| |_      | || |    _| |_     | |";
    GotoXY(75, 19); cout << "| |  |_____|     | || |   |_____|    | |";
    GotoXY(75, 20); cout << "| |              | || |              | |";
    GotoXY(75, 21); cout << "| '--------------' || '--------------' |";
    GotoXY(75, 22); cout << " '----------------'  '----------------' ";
}
void DrawWinnerScreen2() {
    GotoXY(75, 12); cout << " .----------------.  .----------------. ";
    GotoXY(75, 13); cout << "| .--------------. || .--------------. |";
    GotoXY(75, 14); cout << "| |   ______     | || |    _____     | |";
    GotoXY(75, 15); cout << "| |  |_   __ \\   | || |   / ___ `.   | |";
    GotoXY(75, 16); cout << "| |    | |__) |  | || |  |_/___) |   | |";
    GotoXY(75, 17); cout << "| |    |  ___/   | || |   .'____.'   | |";
    GotoXY(75, 18); cout << "| |   _| |_      | || |  / /____     | |";
    GotoXY(75, 19); cout << "| |  |_____|     | || |  |_______|   | |";
    GotoXY(75, 20); cout << "| |              | || |              | |";
    GotoXY(75, 21); cout << "| '--------------' || '--------------' |";
    GotoXY(75, 22); cout << " '----------------'  '----------------' ";
}
void DrawTieScreen() {
    GotoXY(67, 14); cout << " .----------------.  .----------------.  .----------------. ";
    GotoXY(67, 15); cout << "| .--------------. || .--------------. || .--------------. |";
    GotoXY(67, 16); cout << "| |  _________   | || |     _____    | || |  _________   | |";
    GotoXY(67, 17); cout << "| | |  _   _  |  | || |    |_   _|   | || | |_   ___  |  | |";
    GotoXY(67, 18); cout << "| | |_/ | | \\_|  | || |      | |     | || |   | |_  \\_|  | |";
    GotoXY(67, 19); cout << "| |     | |      | || |      | |     | || |   |  _|  _   | |";
    GotoXY(67, 20); cout << "| |    _| |_     | || |     _| |_    | || |  _| |___/ |  | |";
    GotoXY(67, 21); cout << "| |   |_____|    | || |    |_____|   | || | |_________|  | |";
    GotoXY(67, 22); cout << "| |              | || |              | || |              | |";
    GotoXY(67, 23); cout << "| '--------------' || '--------------' || '--------------' |";
    GotoXY(67, 24); cout << " '----------------'  '----------------'  '----------------' ";
}
void DrawWinnerScreenSub() {
    GotoXY(89, 19); cout << "_";
    GotoXY(88, 20); cout << "|_|";
    GotoXY(79, 21); cout << "__      ___ _ __  _ __   ___ _ __ ";
    GotoXY(79, 22); cout << "\\ \\ /\\ / / | '_ \\| '_ \\ / _ \\ '__|";
    GotoXY(80, 23); cout << "\\ V  V /| | | | | | | |  __/ |";
    GotoXY(81, 24); cout << "\\_/\\_/ |_|_| |_|_| |_|\\___|_|";
}

void DrawMediumSparkle(int x, int y) {
    GotoXY(x, y);     cout << "__/\\__";
    GotoXY(x, y + 1); cout << "\\    /";
    GotoXY(x, y + 2); cout << "/_  _\\";
    GotoXY(x + 2, y + 3); cout << "\\/";
}

void DrawSmallSparkle(int x, int y) {
    GotoXY(x, y);     cout << "/\\";
    GotoXY(x, y + 1); cout << "\\/";
}

int ProcessFinish(int pWhoWin) {
    GotoXY(0, _A[ROW - 1][COLUMN - 1].y + 2); // Nhảy tới vị trí
     // thích hợp để in chuỗi thắng/thua/hòa
    switch (pWhoWin) {
    case -1:
        Sleep(600);
        textcolor(247); DrawMediumSparkle(68, 20);
        textcolor(252); DrawWinnerScreen1();
        Sleep(600);
        textcolor(254); DrawMediumSparkle(68, 20);
        textcolor(247); DrawSmallSparkle(100, 28);
        textcolor(247); DrawMediumSparkle(115, 19);
        textcolor(244); DrawWinnerScreen1();
        Sleep(300);
        textcolor(254); DrawSmallSparkle(100, 28);
        textcolor(254); DrawMediumSparkle(115, 19);
        textcolor(247); DrawSmallSparkle(85, 12);
        textcolor(247); DrawSmallSparkle(108, 10);
        DrawWinnerScreenSub();
        Sleep(300);
        textcolor(254); DrawSmallSparkle(85, 12);
        textcolor(254); DrawSmallSparkle(108, 10);
        textcolor(246); DrawWinnerScreenSub();
        Sleep(300);
        break;
    case 1:
        Sleep(600);
        textcolor(247); DrawMediumSparkle(68, 20);
        textcolor(249); DrawWinnerScreen2();
        Sleep(600);
        textcolor(251); DrawMediumSparkle(68, 20);
        textcolor(247); DrawSmallSparkle(100, 28);
        textcolor(247); DrawMediumSparkle(115, 19);
        textcolor(241); DrawWinnerScreen2();
        Sleep(300);
        textcolor(251); DrawSmallSparkle(100, 28);
        textcolor(251); DrawMediumSparkle(115, 19);
        textcolor(247); DrawSmallSparkle(85, 12);
        textcolor(247); DrawSmallSparkle(108, 10);
        DrawWinnerScreenSub();
        Sleep(300);
        textcolor(251); DrawSmallSparkle(85, 12);
        textcolor(251); DrawSmallSparkle(108, 10);
        textcolor(243); DrawWinnerScreenSub();
        Sleep(300);
        break;
    case 0:
        Sleep(300);
        textcolor(250); DrawTieScreen();
        Sleep(300);
        textcolor(242); DrawTieScreen();
        break;
    case 2:
        _TURN = !_TURN; // Đổi lượt nếu không có gì xảy ra
    }
    GotoXY(_X, _Y); // Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
    Sleep(600);
    return pWhoWin;
}

int AskContinue(SETTINGS stt) {
    unsigned char vien = 178;
    _getch(); // Tại vì chưa thêm hiệu ứng chớp 5 chữ nên tạm thời nhấn 1 phím bất kỳ để nghỉ. Không hiểu tại sao thì xoá dòng này rồi thử làm sao hoà 2 bên
    textcolor(247);
    for (int i = 0; i < 6; i++) {
        GotoXY(65, 26 + i);
        cout << vien << vien;
        for (int j = 0; j < 56; j++)
            if (i == 0 || i == 5)
                cout << vien;
            else
                cout << ' ';
        GotoXY(123, 26 + i);
        cout << vien << vien;
    }
    textcolor(240);
    if (stt.language == 1) {
        GotoXY(77, 28); cout << "Do you want to continue the game?";
        GotoXY(77 + 8, 29); cout << " Yes (Y) ";
        GotoXY(77 + 16 + 3, 29); cout << " No (N) ";
    }
    else {
        GotoXY(77, 28); cout << "Ban co muon tiep tuc tro choi?";
        GotoXY(77 + 8, 29); cout << " Co (Y) ";
        GotoXY(77 + 16 + 3, 29); cout << " Khong (N) ";
    }
    return toupper(_getch());
}

