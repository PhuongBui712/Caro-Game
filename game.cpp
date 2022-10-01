#include "Function.h"

void startPlaying(SETTINGS stt) {
	bool validEnter = true;
	int q = 0;
	while (1)
	{
		if (_kbhit()) {
			_COMMAND = toupper(_getch());
			if (_COMMAND == 27)
			{
				ExitGame();
				break;
			}
			else {
				if (_COMMAND == 'A') MoveLeft();
				else if (_COMMAND == 'W') MoveUp();
				else if (_COMMAND == 'S') MoveDown();
				else if (_COMMAND == 'D') MoveRight();
				else if (_COMMAND == 'L') SaveGame();
				else if (_COMMAND == 'O') {
					bool pass = 0;
				Point0:
					char n = controlNote(stt);
					if (n == 'N') {
						deleteNote();
					}
					else if (n == 'Y') {
						ProcessFinish(0);
					Point1:
						char n = AskContinue(stt);
						if (n == 'N') {
							pass = 1;
							ExitGame();
							break;
						}
						else if (n == 'Y') {
							Score(TestBoard(stt));
							StartGame(stt);
							GotoXY(_X, _Y);
						}
						else
							goto Point1;
					}
					else
						goto Point0;
				}
				else if (_COMMAND == 13) {
					switch (CheckBoard()) {
					playerx: case -1:
						if (stt.music) PlaySound(TEXT("Cork.wav"), NULL, SND_FILENAME | SND_ASYNC);
						DrawX(_X, _Y);
						GotoXY(120, 9);
						Turn(-1);
						break;
					playero: case 1:
						if (stt.music) PlaySound(TEXT("Cork.wav"), NULL, SND_FILENAME | SND_ASYNC);
						DrawO(_X, _Y);
						GotoXY(120, 9);
						Turn(1);
						break;
					case 0: validEnter = false;
						if (stt.music) PlaySound(TEXT("door_lock.wav"), NULL, SND_FILENAME | SND_ASYNC);
						// Đánh vào ô đã đánh rồi
					}
					if (validEnter == true) {
						int m = ProcessFinish(TestBoard(stt));
						if (m == -1 || m == 1 || m == 0) {
						Point2:
							char n = AskContinue(stt);
							if (n == 'N') {
								ExitGame();
								break;
							}
							else if (n == 'Y') {
								Score(TestBoard(stt));
								StartGame(stt);
								GotoXY(_X, _Y);
							}
							else {
								goto Point2;
							}
						}
					}
					validEnter = true;
				}
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////
// BÀN CỜ 
void drawBoard(SETTINGS stt) {
	int c, r;

	r = ROW * 4;
	c = COLUMN * 8 - 1;

	unsigned char gtt = 218, gpt = 183, gtd = 212, gpd = 188,
		dn = 196, dnd = 207, dnt = 194, dnbs = 205, dntd = 197,
		dd = 179, ddt = 195, ddp = 182, ddbs = 186;

	GotoXY(20, 3);
	// VẼ hàng kí tự thứ 0
	drawRow(gtt, gpt, dn, dnt, c);

	for (int i = 1; i <= r; i++) {
		Sleep(3);
		GotoXY(20, 3 + i);
		// Hàng kí tự chia hết cho 4 thì gạch ngang
		if (i % 4 == 0) {
			cout << ddt; // Hàng kí tự thứ i cột 0
			for (int j = 1; j <= c; j++) {
				if (j % 8 == 0)
				{
					GotoXY(j + 20, i + 3);
					cout << '+';
				}
				if (j == c)
				{
					GotoXY(j + 21, i + 3);
					cout << ddp;  // Hàng i cột c + 2
				}
			}
		}

		// Hàng lẻ thì chừa ra để đánh
		else {
			GotoXY(20, i + 3);
			cout << dd;
			GotoXY(c + 21, i + 3);
			cout << ddbs;
		}
	}
	drawTable(stt); // vẽ bảng bên phải
	GotoXY(20, r + 3);
	// VẼ hàng kĩ tự thứ r + 1
	drawRow(gtd, gpd, dnbs, dnd, c);
}

// BẢNG BÊN PHẢI
void drawTable(SETTINGS stt) {
	unsigned char khung = 178;
	drawTable1(khung);
	if (stt.language == 1) {
		GotoXY(125, 5); cout << "'W' - UP";
		GotoXY(125, 6); cout << "'A' - LEFT";
		GotoXY(125, 7); cout << "'S' - DOWN";
		GotoXY(125, 8); cout << "'D' - RIGHT";
		GotoXY(125, 9); cout << "'O' - DRAW";
		GotoXY(125, 10); cout << "'L' - SAVE GAME";
		GotoXY(125, 11); cout << "'ESC' - EXIT GAME";
		GotoXY(149, 7); cout << " ~ ~ ~ TURN ~ ~ ~ ";
		textcolor(240);
		drawTable2(khung);
	}
	else {
		GotoXY(125, 5); cout << "'W' - LEN";
		GotoXY(125, 6); cout << "'A' - TRAI";
		GotoXY(125, 7); cout << "'S' - XUONG";
		GotoXY(125, 8); cout << "'D' - PHAI";
		GotoXY(125, 9); cout << "'O' - XIN HOA";
		GotoXY(125, 10); cout << "'ESC' - THOAT GAME";
		GotoXY(149, 7); cout << " ~ ~ ~ LUOT ~ ~ ~ ";
		textcolor(240);
		drawTable2(khung);
	}
	GotoXY(131, 16); cout << "Player X";
	GotoXY(152, 16); cout << "Player O";

	GotoXY(0, 47);
	for (int i = 0; i <= 203; i++) cout << ".";
}

// VẼ QUÂN CỜ X
void DrawX(int _X, int _Y) {
	textcolor(244);
	GotoXY(_X - 2, _Y - 2); cout << "\\\\ //";
	GotoXY(_X - 2, _Y - 1); cout << " >X< ";
	GotoXY(_X - 2, _Y); cout << "// \\\\";
	GotoXY(_X, _Y);
}

// VẼ QUÂN CỜ O
void DrawO(int _X, int _Y) {
	textcolor(241);
	GotoXY(_X - 2, _Y - 2); cout << ".OOO.";
	GotoXY(_X - 2, _Y - 1); cout << "O   O";
	GotoXY(_X - 2, _Y); cout << "*OOO*";
	GotoXY(_X, _Y);
}

// KIỂM TURN
void Turn(int turn) {
	if (turn == 1) DrawX(158, 10); 
	if (turn == -1) DrawO(158, 10);
}

// TÍNH ĐIỂM
void Score(int signal) {
	if (signal == 1) score2++;
	if (signal == -1) score1++;
	if (signal == -2) score1 = score2 = 0;
}

void OutputScore() {
	GotoXY(134, 19); cout << score1;
	GotoXY(155, 19); cout << score2;
}
////////////////////////////////////////////////////////////////////////////

// BẢNG 1
void drawTable1(char khung) {
	for (int i = 0; i <= 9; i++) {
		Sleep(3);
		GotoXY(120, i + 3);
		for (int j = 150; j <= 200; j++) {
			if ((i == 0) || (i == 9)) cout << khung;
			else if (((j == 150) || (j == 151) || (j == 199) || (j == 200)) || (j == 175) || (j == 176)) cout << khung;
			else cout << " ";
		}
	}
}

// BẢNG 2
void drawTable2(char khung) {
	unsigned char vien = 254;
	for (int i = 12; i <= 18; i++) {
		Sleep(3);
		GotoXY(123, i + 3);

		for (int j = 156; j <= 200; j++) {
			if (i == 14) {
				if (( (j == 156) || (j == 199) || (j == 200)) || (j == 157) || (j == 178)) cout << khung;
				else cout << vien;
			}
			else {
				if ((i == 12) || (i == 18)) cout << khung;
				else
					if (((j == 156) || (j == 199) || (j == 200)) || (j == 157) || (j == 178)) cout << khung;
					else cout << " ";
			}
		}
	}
}

// HÀNG TRÊN VÀ HÀNG DƯỚI CÙNG CỦA BÀN CỜ
void drawRow(char gt, char gp, char dn, char dnor, int c) {
	cout << gt; // Hàng 0 cột 0
	for (int j = 1; j <= c; j++) { // Hàng 0 cột i (0 -> c)
		if (j % 8 == 0) cout << dnor; // Nếu cột chia hết cho 8 thì gạch
		else
			cout << dn;  // Cột lẻ thì chừa ra để đánh
	}
	cout << gp;
}

// BẢNG THÔNG BÁO XIN HÒA
void drawNote(SETTINGS stt) {
	char khung = 178;
	textcolor(240);
	for (int i = 0; i < 6; i++) {
		GotoXY(118, 38 + i);
		for (int j = 0; j < 55; j++) {
			if ((i == 0) || (i == 5)) {
				cout << khung;
			}
			else {
				if ((j == 0) || (j == 1) || (j == 53) || (j == 54)) {
					cout << khung;
				}
				else {
					cout << " ";
				}
			}
		}
	}
	if (stt.language == 1) {
		GotoXY(121, 39); cout << "Your opponent wants to be draw. Do you agree?";
		GotoXY(133, 41); cout << "YES (Y)";
		GotoXY(155, 41); cout << "NO (N)";
	}
	else {
		GotoXY(121, 39); cout << "Doi thu cua ban muon cau hoa. Ban co dong y khong?";
		GotoXY(133, 41); cout << "CO (Y)";
		GotoXY(155, 41); cout << "KHONG (N)";
	}
	GotoXY(0, 47);
}

// XÓA BẢNG THÔNG BÁO XIN HÒA
void deleteNote() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 55; j++) {
			GotoXY(118 + j, 38 + i);
			cout << ' ';
		}
	}
}

// ĐIỀU KHIỂN BẢNG THÔNG BÁO
int controlNote(SETTINGS stt) {
	drawNote(stt);
	return toupper(_getch());
}





