#include "Function.h"

// VẼ KHUNG CÀI ĐẶT
void SettingFrame() {
    unsigned char khung = 178;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 49; j++) {
            GotoXY(85 + j, 29 + i);
            if (i == 0 || i == 7) cout << khung;
            else
                if (j == 0 || j == 1 || j == 47 || j == 48) cout << khung;
                else cout << ' ';
        }
    }
}



// THAO TÁC BẢNG CÀI ĐẶT 
void Settings(char key, WASD& replace_wasd, int& n, SETTINGS& stt, int& ignore) {
    if (key == 'W') {
        if (stt.g_music) PlaySound(TEXT("car_door.wav"), NULL, SND_FILENAME | SND_ASYNC);
        replace_wasd.wasd = UP; 
    }
    else if (key == 'S') {
        if (stt.g_music) PlaySound(TEXT("car_door.wav"), NULL, SND_FILENAME | SND_ASYNC);
        replace_wasd.wasd = DOWN; 
    }
    else if (key == 'A' || key == 'D' || key == 13 || key == 32 || key == 'Z') {
        if (stt.g_music) PlaySound(TEXT("Toaster2.wav"), NULL, SND_FILENAME | SND_ASYNC);
        replace_wasd.wasd = OTHER; // Thay đổi giá trị hiện tại
    }

    if (replace_wasd.wasd == UP) n--;
    if (replace_wasd.wasd == DOWN) n++;

    if (n < 0) n = 0;
    else if (n > 3) n = 3;

    // Thêm nhạc và ngôn ngữ
    if (stt.language == 1) {
        GotoXY(95, 31); cout << "Music Volume: ";
        GotoXY(115, 31);
        if (stt.music) cout << "ON ";
        else cout << "OFF";
        GotoXY(95, 32); cout << "Game Volume: ";
        GotoXY(115, 32);
        if (stt.g_music) cout << "ON ";
        else cout << "OFF";
        GotoXY(95, 33); cout << "Language: ";
        GotoXY(115, 33);
        if (stt.language) cout << "ENGLISH   ";
        else cout << "VIETNAMESE"; // dòng này vô d?ng
        GotoXY(105, 34);
        cout << "Go back ";
    }
    else {
        GotoXY(95, 31); cout << "Am luong nhac: ";
        GotoXY(115, 31);
        if (stt.music) cout << "BAT";
        else cout << "TAT";
        GotoXY(95, 32); cout << "Am luong game: ";
        GotoXY(115, 32);
        if (stt.g_music) cout << "BAT";
        else cout << "TAT";
        GotoXY(95, 33); cout << "Ngon ngu: ";
        GotoXY(115, 33);
        if (stt.language) cout << "TIENG ANH"; // dòng này vô d?ng
        else cout << "TIENG VIET";
        GotoXY(105, 34);
        cout << "Quay lai";
    }

    if (ignore == 0) {
        replace_wasd.wasd = UP;
        ignore = 1;
    } 

    GotoXY(115, 31 + n);
    textcolor(113);
    switch (n) {
    case 0:
        if (stt.music)
            if (stt.language == 1) cout << "ON ";
            else cout << "BAT";
        else
            if (stt.language == 1) cout << "OFF";
            else cout << "TAT";
        if (replace_wasd.wasd == OTHER) stt.music = 1 - stt.music; // 1 -> 0 và 0 -> 1
        break;
    case 1:
        if (stt.g_music)
            if (stt.language == 1) cout << "ON ";
            else cout << "BAT";
        else
            if (stt.language == 1) cout << "OFF";
            else cout << "TAT";
        if (replace_wasd.wasd == OTHER) stt.g_music = 1 - stt.g_music;
        break;
    case 2:
        if (stt.language == 1) cout << "ENGLISH   ";
        else cout << "TIENG VIET";
        if (replace_wasd.wasd == OTHER) stt.language = 1 - stt.language;
        break;
    case 3:
        GotoXY(105, 31 + n);
        if (stt.language == 1)
            cout << "Go back ";
        else
            cout << "Quay lai";
        break;
    }
    textcolor(240);

    GotoXY(0, 0);
}