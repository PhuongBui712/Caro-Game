#include "Function.h"

// VẼ CHỮ CARO
void DrawMenuTitle(SETTINGS stt) {
    string bigTitle[22];
    for (int i = 0; i < 11; i++) {
        bigTitle[i] = "                                                                        ";
    }
    bigTitle[11] = "    ,o888888o.           .8.          8 888888888o.      ,o888888o.     ";
    bigTitle[12] = "   8888     `88.        .888.         8 8888    `88.  . 8888     `88.   ";
    bigTitle[13] = ",8 8888       `8.      :88888.        8 8888     `88 ,8 8888       `8b  ";
    bigTitle[14] = "88 8888               . `88888.       8 8888     ,88 88 8888        `8b ";
    bigTitle[15] = "88 8888              .8. `88888.      8 8888.   ,88' 88 8888         88 ";
    bigTitle[16] = "88 8888             .8`8. `88888.     8 888888888P'  88 8888         88 ";
    bigTitle[17] = "88 8888             .8`8. `88888.     8 888888888P'  88 8888         88 ";
    bigTitle[18] = "88 8888            .8' `8. `88888.    8 8888`8b      88 8888        ,8P ";
    bigTitle[19] = "`8 8888       .8' .8'   `8. `88888.   8 8888 `8b.    `8 8888       ,8P  ";
    bigTitle[20] = "   8888     ,88' .888888888. `88888.  8 8888   `8b.   ` 8888     ,88'   ";
    bigTitle[21] = "    `8888888P'  .8'       `8. `88888. 8 8888     `88.    `8888888P'     ";

    if (stt.music)
        PlaySound(TEXT("strings3.wav"), NULL, SND_FILENAME | SND_ASYNC);

    for (int i = 21; i >= 0; i--) {
        for (int j = 0; j <= 21 - i; j++) {
            GotoXY(75, j);
            cout << bigTitle[i + j];
        }
        Sleep(30);
    }
}

// VẼ CHỮ PROJECT
void DrawMenuSubtitle() {
    GotoXY(110, 20);  cout << "_"; GotoXY(122, 20);  cout << "_";
    GotoXY(109, 21);  cout << "(_)"; GotoXY(121, 21);  cout << "| |";
    GotoXY(90, 22);  cout << "|   _ __  _ __ ___  _  ___  ___| |_   |";
    GotoXY(90, 23);  cout << "|  | '_ \\| '__/ _ \\| |/ _ \\/ __| __|  |";
    GotoXY(90, 24);  cout << "|  | |_) | | | (_) | |  __/ (__| |_   |";
    GotoXY(90, 25);  cout << "|  | .__/|_|  \\___/| |\\___|\\___|\\__|  |";
    GotoXY(90, 26);  cout << "|  | |            _/ |                |";
    GotoXY(90, 27);  cout << "|  |_|           |__/                 |";
}

// TỔNG HỢP GIAO DIỆN MENU
void startMenu(SETTINGS stt) {
    textcolor(252);
    system("cls");
    DrawMenuTitle(stt);
    Sleep(150);
    textcolor(247);
    DrawMenuSubtitle();
    Sleep(150);
    textcolor(248);
    DrawMenuSubtitle();
    Sleep(150);
    textcolor(240);
    DrawMenuSubtitle();
    Sleep(150);

    GotoXY(105, 31); textcolor(113);
    if (stt.language == 1)
        cout << " START! ";
    else
        cout << "BAT DAU!";
    textcolor(240);
    GotoXY(105, 32);
    if (stt.language == 1)
        cout << "  LOAD  ";
    else
        cout << "TIEP TUC";
    GotoXY(105, 33);
    if (stt.language == 1)
        cout << " OPTION ";
    else
        cout << "CAI DAT ";
    GotoXY(105, 34);
    if (stt.language == 1)
        cout << "  QUIT  ";
    else
        cout << " THOAT  ";
    GotoXY(0, 0);
}

// THAO TÁC LỰA CHỌN TRÊN MENU 
void Control(char key, WASD& replace_wasd, int& n, SETTINGS stt) {
    if (key == 'A' || key == 'W') {
        if (stt.g_music) PlaySound(TEXT("car_door.wav"), NULL, SND_FILENAME | SND_ASYNC);
        replace_wasd.wasd = UP; 
    }
    else if (key == 'S' || key == 'D') {
        if (stt.g_music) PlaySound(TEXT("car_door.wav"), NULL, SND_FILENAME | SND_ASYNC);
        replace_wasd.wasd = DOWN; 
    }
    else if (key == 13 || key == 32 || key == 'Z') {
        if (stt.g_music) PlaySound(TEXT("Toaster2.wav"), NULL, SND_FILENAME | SND_ASYNC);
        replace_wasd.wasd = OTHER;
    }

    if (replace_wasd.wasd == UP) n--;
    if (replace_wasd.wasd == DOWN) n++;

    if (n < 0) n = 3;
    else if (n > 3) n = 0;

    string menuplay[4] = { " START! ", "  LOAD  ", " OPTION ", "  QUIT  " };
    string menuplay2[4] = { "BAT DAU!", "TIEP TUC",  "CAI DAT ", " THOAT  " };
    for (int i = 0; i < 4; i++) {
        GotoXY(105, 31 + i);
        if (i == n) {
            textcolor(113);
            if (stt.language)
                cout << menuplay[i];
            else
                cout << menuplay2[i];
            textcolor(240);
        }
        else {
           
            if (stt.language)
                cout << menuplay[i];
            else
                cout << menuplay2[i];
        }
    }
    GotoXY(0, 0);
}