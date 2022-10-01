#include "Function.h"

void ReadNameFile()
{
    GotoXY(10, 15);
    cout << "LIST FILE NAME";
    int i = 19;
    ifstream f;
    f.open("Name.txt", ios::in);
    while (!f.eof())
    {
        char s[30];
        f >> s;
        GotoXY(10, i);
        cout << s;
        i++;
    }
    f.close();
}
void SaveGame() {
    char data[30];
    ofstream f1;
    ofstream f2;
    GotoXY(120, 40);
    cout << "ENTER FILE NAME: ";
    cin.getline(data, 30);
    f1.open(data, ios::out);
    f2.open("Name.txt", ios::app);
    f2 << data << " " << endl;
    //thong tin
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            f1 << _A[i][j].c << " ";
        }
        f1 << endl;
    }
    f1 << score1 << endl;
    f1 << score2 << endl;
    f1.close();
    f2.close();
    GotoXY(120, 41);
    cout << "ESC TO BACK";
}

void loadData(_POINT& p, int i, int j, int& k)
{
    p.setX(4 * j + 4 + 2);
    p.setY(2 * i + 4 + 1);
    p.setCheck(k);
    if (k == -1) {
        textcolor(20);
        GotoXY(i, j);
        DrawX(i, j);
    }
    if (k == 1) {
        GotoXY(i, j);
        DrawO(i, j);
    }
}

int getXAt(int i, int j) { return _A[i][j].getX(); }
int getYAt(int i, int j) { return _A[i][j].getY(); }


void LoadGame(char data[30], SETTINGS stt, _POINT& p) {
    fstream f;
    f.open(data, ios::in);
    if (!f) {
        GotoXY(35, 46);
        cout << "THE FILE WAS NOT HERE. PLEASE ESC TO GO BACK TO MENU";
    }
    else {
        system("cls");
        _X = _A[5][5].x + 4; _Y = _A[5][5].y + 3;
        StartGame(stt);
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COLUMN; j++)
            {
                _X = LEFT * j + 24;
                _Y = TOP * i + 6;
                f >> _A[i][j].c;
                loadData(p, _X, _Y, _A[i][j].c);
            }
        }
        f >> score1;
        f >> score2;
        GotoXY(134, 19); cout << score1;
        GotoXY(155, 19); cout << score2;
        f.close();
    }
}