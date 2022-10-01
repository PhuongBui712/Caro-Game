#include "Function.h"

// VÔ HIỆU HÓA NÚT PHÓNG TO MÀN HÌNH
void fixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

// THAY ĐỔI KÍCH THƯỚC MÀN HÌNH CONSOLE
void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// TRỎ TỚI VỊ TRÍ X, Y
void GotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// TÔ MÀU
void textcolor(int x) {
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}

// KHỞI TẠO DỮ LIỆU GỐC
void ResetData() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            _A[i][j].x = LEFT * j + 20; // Trùng với hoành độ màn hình bàn cờ
            _A[i][j].y = TOP * i + 3; // Trùng với tung độ màn hình bàn cờ
            _A[i][j].c = 0; // 0 nghĩa là chưa ai đánh dấu, nếu đánh dấu phải theo quy
            //định như sau: -1 là lượt true đánh, 1 là lượt false đánh
        }
    }
    _TURN = true; _COMMAND = -1; // Gán lượt và phím mặc định
    _X = _A[5][5].x + 4; _Y = _A[5][5].y + 3; // Thiết lập lại tọa độ hiện hành ban đầu
}

// BẮT ĐẦU GAME
void StartGame(SETTINGS stt) {
    textcolor(240);
    system("cls");
    drawBoard(stt);
    OutputScore();
    ResetData();
    Turn(1);
    GotoXY(_X, _Y);
}

// THOÁT GAME
void ExitGame() {
    system("cls");
    Score(-2);
}

// DI CHUYỂN PHẢI
void MoveRight() {
    if (_X < _A[ROW - 1][COLUMN - 1].x) {
        _X += 8;
        GotoXY(_X, _Y);
    }
}
// DI CHUYỂN TRÁI
void MoveLeft() {
    if (_X > _A[0][0].x + 8) {
        _X -= 8;
        GotoXY(_X, _Y);
    }
}
// DI CHUYỂN XUỐNG
void MoveDown() {
    if (_Y < _A[ROW - 1][COLUMN - 1].y) {
        _Y += 4;
        GotoXY(_X, _Y);
    }
}
// DI CHUYỂN LÊN
void MoveUp() {
    if (_Y > _A[0][0].y + 4) {
        _Y -= 4;
        GotoXY(_X, _Y);
    }
}

