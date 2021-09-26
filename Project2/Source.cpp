#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void TextColor(int x)
{
	HANDLE mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void gotoxy(int x, int y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
struct Toado {
	int x, y;
};
struct Contro {
	Toado td;
};
struct Xoacontro {
	Toado td;
};
struct XO {
	Toado vtx[300], vto[300];
	int nx = 0, no = 0;
};


void khungngoai();
void khungtrong();
void khoitao(Contro& contro, Contro& contro1);
void hienthi(Contro contro, Contro contro1, int daux, int dau0, Xoacontro xoacontro, Xoacontro xoacontro1, XO A);
void dieukhien(Contro& contro, Contro& contro1, Xoacontro& xoacontro, Xoacontro& xoacontro1, int& daux, int& dau0, XO& A, int& dem, int& dem1, int& luotchoi, int& luuct);
void Xoacursor(Xoacontro xoacontro, Xoacontro xoacontro1, int daux, int dau0);
void Luotchoi(int luotchoi, XO A);
void playgame(int& thoat);
void khungplay();
void help(int& thoat);
void about(int& thoat);




int main()
{
	resizeConsole(700, 608);
	int thoat = 0;
	playgame(thoat);
	system("cls");
	if (thoat == 0)
	{
		khungtrong();
		khungngoai();
		do {
			int daux = 0, dau0 = 0, dem = 0, dem1 = 0, luotchoi = 0, luuct = 0, xoald = 0;
			Xoacontro xoacontro, xoacontro1;
			Contro contro, contro1;
			XO A;
			khoitao(contro, contro1);
			do {
				if (xoald != 0) Xoacursor(xoacontro, xoacontro1, daux, dau0); xoald = 1;
				hienthi(contro, contro1, daux, dau0, xoacontro, xoacontro1, A);
				dieukhien(contro, contro1, xoacontro, xoacontro1, daux, dau0, A, dem, dem1, luotchoi, luuct);
				Luotchoi(luotchoi, A);
			} while (1);
			playgame(thoat);
		} while (1);
		gotoxy(0, 0);
		_getch();
	}
}
void khungngoai()
{
	TextColor(11);
	for (int i = 0; i <= 78; i++)
	{
		gotoxy(i, 0); printf("%c", 205);
		Sleep(1);
	}
	for (int i = 0; i <= 78; i++)
	{
		gotoxy(i, 46); printf("%c", 205);
		Sleep(1);
	}
	for (int i = 0; i <= 45; i++)
	{
		gotoxy(0, i); printf("%c", 186);
		Sleep(1);
	}
	for (int i = 0; i <= 45; i++)
	{
		gotoxy(79, i); printf("%c", 186);
		Sleep(1);
	}
	gotoxy(0, 0); printf("%c", 201);
	gotoxy(0, 46); printf("%c", 200);
	gotoxy(79, 0); printf("%c", 187);
	gotoxy(79, 46); printf("%c", 188);

	TextColor(11);
	for (int i = 2; i <= 77; i++)
	{
		gotoxy(i, 1); printf("%c", 205);
		Sleep(1);
	}
	for (int i = 1; i <= 77; i++)
	{
		gotoxy(i, 45); printf("%c", 205);
		Sleep(1);
	}
	for (int i = 1; i <= 44; i++)
	{
		gotoxy(1, i); printf("%c", 186);
		Sleep(1);
	}
	for (int i = 1; i <= 44; i++)
	{
		gotoxy(78, i); printf("%c", 186);
		Sleep(1);
	}
	gotoxy(1, 1); printf("%c", 201);
	gotoxy(1, 45); printf("%c", 200);
	gotoxy(78, 1); printf("%c", 187);
	gotoxy(78, 45); printf("%c", 188);
	for (int i = 0; i < 15; i++)
	{
		gotoxy(63 + i, 4); printf("%c", 205);
	}
	for (int i = 0; i < 2; i++)
	{
		gotoxy(63, i + 2); printf("%c", 186);
	}
	gotoxy(63, 4); printf("%c", 200);
	gotoxy(67, 2); TextColor(12); printf("Luot Choi");
	TextColor(15); gotoxy(68, 3); printf("--   --");
	TextColor(13); gotoxy(71, 3); printf("%c", 2);
	TextColor(11);
	for (int i = 0; i < 15; i++)
	{
		gotoxy(2 + i, 4); printf("%c", 205);
	}
	for (int i = 0; i < 2; i++)
	{
		gotoxy(17, i + 2); printf("%c", 186);
	}
	for (int i = 0; i < 43; i++)
	{
		gotoxy(19 + i, 2); printf("_");
	}
	gotoxy(17, 4); printf("%c", 188);
	gotoxy(34, 0); TextColor(160); printf(" GAME CO CARO ");
	gotoxy(25, 2); TextColor(12); printf("TAN CU CHAN - CNTT K16D - ICTU");
	gotoxy(5, 2); TextColor(12); printf("So Quan Co");
	TextColor(15);
	gotoxy(3, 3); printf("  -   |   -   ");
	gotoxy(3, 3); TextColor(14); printf("X");
	gotoxy(11, 3); TextColor(14); printf("O");
	gotoxy(42, 40);
}
void khungtrong()
{
	TextColor(15);
	for (int i = 0; i <= 44; i++)
	{
		for (int j = 0; j <= 24; j++)
		{
			if (i < 4) printf(" ");
			else if (j < 3) printf(" ");
			else if (i % 2 == 0 && j > 4 && j < 23)  printf("%c%c%c%c", 197, 196, 196, 196);
			else if (i % 2 == 1 && j > 4 && j < 23) printf("%c   ", 179);
			else if (i % 2 == 0 && j == 23) printf("%c", 197);
			else if (i % 2 == 1 && j == 23) printf("%c", 179);
		}
		printf("\n");
	}
}
void khoitao(Contro& contro, Contro& contro1)
{
	contro.td.x = 32; contro.td.y = 21;
	contro1.td.x = 40; contro1.td.y = 21;
}

void hienthi(Contro contro, Contro contro1, int daux, int dau0, Xoacontro xoacontro, Xoacontro xoacontro1, XO A)
{
	//Contro 1----------------------------------------------------------------------------------------------
	if (daux == 1)
	{
		TextColor(14); gotoxy(xoacontro.td.x, xoacontro.td.y); printf(" X ");
		gotoxy(contro.td.x, contro.td.y); TextColor(224); printf("   ");
	}
	else if (daux == 2)
	{
		TextColor(235); gotoxy(contro.td.x, contro.td.y); printf(" X ");
	}
	else if (daux == 0)
	{
		gotoxy(contro.td.x, contro.td.y); TextColor(224); printf("   ");
	}
	//Con tro 2----------------------------------------------------------------------------------------------------
	if (dau0 == 1)
	{
		TextColor(12); gotoxy(xoacontro1.td.x, xoacontro1.td.y); printf(" O ");
		gotoxy(contro1.td.x, contro1.td.y); TextColor(207); printf("   ");
	}
	else if (dau0 == 2)
	{
		TextColor(207); gotoxy(contro1.td.x, contro1.td.y); printf(" O ");
	}
	else if (dau0 == 0)
	{
		gotoxy(contro1.td.x, contro1.td.y); TextColor(207); printf("   ");
	}
	//Khoi phuc cac quan co------------------------------------------------
	for (int i = 0; i < A.nx; i++)
	{
		gotoxy(A.vtx[i].x, A.vtx[i].y); TextColor(14); printf(" X ");
	}
	for (int i = 0; i < A.no; i++)
	{
		gotoxy(A.vto[i].x, A.vto[i].y); TextColor(12); printf(" O ");
	}

	for (int i = 0; i < A.nx; i++)
	{
		if (contro.td.x == A.vtx[i].x && contro.td.y == A.vtx[i].y)
		{
			gotoxy(contro.td.x, contro.td.y); TextColor(233); printf(" X ");
		}
		if (contro1.td.x == A.vtx[i].x && contro1.td.y == A.vtx[i].y)
		{
			gotoxy(contro1.td.x, contro1.td.y); TextColor(193); printf(" X ");
		}
	}
	for (int i = 0; i < A.no; i++)
	{
		if (contro.td.x == A.vto[i].x && contro.td.y == A.vto[i].y)
		{
			gotoxy(contro.td.x, contro.td.y); TextColor(233); printf(" O ");
		}
		if (contro1.td.x == A.vto[i].x && contro1.td.y == A.vto[i].y)
		{
			gotoxy(contro1.td.x, contro1.td.y); TextColor(193); printf(" O ");
		}
	}
}
void dieukhien(Contro& contro, Contro& contro1, Xoacontro& xoacontro, Xoacontro& xoacontro1, int& daux, int& dau0, XO& A, int& dem, int& dem1, int& luotchoi, int& luuct)
{
	int ct = 5;
	//	if(kbhit())
	{
		int a = _getch();
		if (a == 'a' || a == 'A') ct = 0;
		else if (a == 'd' || a == 'D') ct = 1;
		else if (a == 's' || a == 'S') ct = 2;
		else if (a == 'w' || a == 'W') ct = 3;
		else if (a == 'e' || a == 'E') ct = 4;
		else if (a == '4') ct = 10;
		else if (a == '6') ct = 11;
		else if (a == '2') ct = 12;
		else if (a == '8') ct = 13;
		else if (a == '5') ct = 14;
	}
	xoacontro.td = contro.td;
	xoacontro1.td = contro1.td;
	if (ct == 0 && contro.td.x > 5) contro.td.x = contro.td.x - 4;       // nhan phim a
	else if (ct == 1 && contro.td.x < 71) contro.td.x = contro.td.x + 4;  //Nhan phim d
	else if (ct == 2 && contro.td.y < 43) contro.td.y = contro.td.y + 2;   //Nhan phim S
	else if (ct == 3 && contro.td.y > 5) contro.td.y = contro.td.y - 2;   //Nhan phim W
	else if (ct == 4)
	{
		int n = 0;
		if (luotchoi == 0 || luotchoi % 2 == 1)
		{
			for (int i = 0; i < A.nx; i++) if (contro.td.x == A.vtx[i].x && contro.td.y == A.vtx[i].y) n++;
			for (int i = 0; i < A.no; i++) if (contro.td.x == A.vto[i].x && contro.td.y == A.vto[i].y) n++;
			if (luotchoi == 0) luotchoi = 1;
			if (n == 0)
			{
				if (luuct == ct) luotchoi++;
				daux = 2;
				A.vtx[dem] = contro.td;
				dem++;
				A.nx++;
			}
			else if (n >= 1 && luuct != ct) luotchoi--;
		}
	}  //Nhan phim E
	else if (ct == 10 && contro1.td.x > 5) contro1.td.x = contro1.td.x - 4;    // nhan phim 4
	else if (ct == 11 && contro1.td.x < 71) contro1.td.x = contro1.td.x + 4;  //Nhan phim 6
	else if (ct == 12 && contro1.td.y < 43) contro1.td.y = contro1.td.y + 2;   //Nhan phim 2
	else if (ct == 13 && contro1.td.y > 5) contro1.td.y = contro1.td.y - 2;   //Nhan phim 8
	else if (ct == 14)
	{
		int n = 0;
		if (luotchoi == 0 || luotchoi % 2 == 0)
		{
			for (int i = 0; i < A.no; i++) if (contro1.td.x == A.vto[i].x && contro1.td.y == A.vto[i].y) n++;
			for (int i = 0; i < A.nx; i++) if (contro1.td.x == A.vtx[i].x && contro1.td.y == A.vtx[i].y) n++;
			if (n == 0)
			{
				if (ct == luuct) luotchoi++;
				dau0 = 2;
				A.vto[dem1] = contro1.td;
				dem1++;
				A.no++;
			}
			else if (n >= 1 && luuct != ct) luotchoi--;
		}
	} //Nhan phim 5
	if ((ct == 10 || ct == 11 || ct == 12 || ct == 13) && dau0 >= 1) dau0--;
	if ((ct == 0 || ct == 1 || ct == 2 || ct == 3) && daux >= 1) daux--;
	if (ct == 4 || ct == 14)
	{
		if (ct != luuct) luotchoi++;
		luuct = ct;
	}
}
void Xoacursor(Xoacontro xoacontro, Xoacontro xoacontro1, int daux, int dau0)
{
	gotoxy(xoacontro.td.x, xoacontro.td.y);
	if (daux == 0) printf("   ");
	gotoxy(xoacontro1.td.x, xoacontro1.td.y);
	if (dau0 == 0) printf("   ");
}
void Luotchoi(int luotchoi, XO A)
{
	gotoxy(71, 3);
	TextColor(14);
	if (luotchoi > 0 && luotchoi % 2 == 1) printf("X");
	else if (luotchoi > 0 && luotchoi % 2 == 0)
	{
		TextColor(12);
		printf("O");
	}
	gotoxy(7, 3); TextColor(14); printf("%d", A.nx);
	gotoxy(15, 3); TextColor(14); printf("%d", A.no);
}

void playgame(int& thoat)
{
	khungplay();
	TextColor(14);
	TextColor(202);
	gotoxy(33, 15); printf("%c PLAY GAME  ", 175);
	TextColor(14);
	gotoxy(35, 16); printf("HELP");
	gotoxy(35, 17); printf("ABOUT");
	gotoxy(35, 18); printf("EXIT");
	int chon = 0;
	int toado = 15;
	do {
		char a = _getch();
		if (a == 80 || a == 's' || a == 'S' || a == '2') chon = 1;
		else if (a == 72 || a == 'w' || a == 'W' || a == '8') chon = 2;
		else if (a == 13 || a == 'e' || a == 'e' || a == '5') chon = 3;
		else chon = 0;
		if (chon == 1 && toado < 18) toado++;
		else if (chon == 2 && toado > 15) toado--;
		if (toado == 15)
		{
			TextColor(202);
			gotoxy(33, 15); printf("%c PLAY GAME  ", 175);
			TextColor(14);
			gotoxy(33, 16); printf("  HELP         ");
			gotoxy(33, 17); printf("  ABOUT        ");
			gotoxy(33, 18); printf("  EXIT         ");
			TextColor(0);
		}
		if (toado == 16)
		{
			TextColor(14);
			gotoxy(33, 15); printf("  PLAY GAME    ");
			TextColor(202);
			gotoxy(33, 16); printf("%c HELP       ", 175);
			TextColor(14);
			gotoxy(33, 17); printf("  ABOUT        ");
			gotoxy(33, 18); printf("  EXIT         ");
			TextColor(0);
		}
		if (toado == 17)
		{
			TextColor(14);
			gotoxy(33, 15); printf("  PLAY GAME  ", 175);
			gotoxy(33, 16); printf("  HELP       ");
			TextColor(202);
			gotoxy(33, 17); printf("%c ABOUT      ", 175);
			TextColor(14);
			gotoxy(33, 18); printf("  EXIT       ");
			TextColor(0);
		}
		if (toado == 18)
		{
			TextColor(14);
			gotoxy(33, 15); printf("  PLAY GAME    ", 175);
			gotoxy(33, 16); printf("  HELP         ");
			gotoxy(33, 17); printf("  ABOUT        ");
			TextColor(202);
			gotoxy(33, 18); printf("%c EXIT       ", 175);
		}
	} while (chon != 3);
	system("cls");
	if (toado == 16) help(thoat);
	else if (toado == 17) about(thoat);
	else if (toado == 18) thoat = 1;
}

void khungplay()
{
	TextColor(12);
	for (int i = 0; i < 78; i++)
	{
		gotoxy(1 + i, 0); printf("%c", 220);
	}
	for (int i = 0; i < 78; i++)
	{
		gotoxy(1 + i, 46); printf("%c", 205);
	}
	for (int j = 0; j < 45; j++)
	{
		gotoxy(0, j + 1); printf("%c", 186);
	}
	for (int j = 0; j < 45; j++)
	{
		gotoxy(79, j + 1); printf("%c", 186);
	}
	gotoxy(0, 0); printf("%c", 201);
	gotoxy(0, 46); printf("%c", 200);
	gotoxy(79, 0); printf("%c", 187);
	gotoxy(79, 46); printf("%c", 188);
	gotoxy(34, 0); TextColor(160); printf(" GAME CO CARO ");
	TextColor(1);
	for (int i = 0; i < 55; i++)
	{
		gotoxy(13 + i, 42); printf("%c", 205);
	}
	for (int i = 0; i < 55; i++)
	{
		gotoxy(13 + i, 44); printf("%c", 205);
	}
	gotoxy(32, 43); printf("Fb.con/tanchan679");
	TextColor(11);
	for (int i = 0; i < 45; i++)
	{
		gotoxy(18 + i, 11); printf("%c", 205);
	}
	for (int i = 0; i < 45; i++)
	{
		gotoxy(18 + i, 21); printf("%c", 205);
	}
	TextColor(2);
	gotoxy(3, 31); printf("$$$$$$$  $$$$$$$   $$$$   $$$   $$$$$$$$  $$$   $$$  $$$$$$$$  $$$$   $$$\n"); Sleep(40);
	gotoxy(3, 32); printf("  $$$   $$$   $$$  $$$$$  $$$   $$$  $$$  $$$   $$$ $$$    $$$ $$$$$  $$$\n"); Sleep(40); TextColor(3);
	gotoxy(3, 33); printf("  $$$   $$$   $$$  $$$$$$ $$$   $$$       $$$$$$$$$ $$$    $$$ $$$$$$ $$$\n"); Sleep(40);
	gotoxy(3, 34); printf("  $$$   $$$$$$$$$  $$$ $$$$$$   $$$       $$$   $$$ $$$$$$$$$$ $$$ $$$$$$\n"); Sleep(40);	TextColor(4);
	gotoxy(3, 35); printf("  $$$   $$$   $$$  $$$  $$$$$   $$$   $$$ $$$   $$$ $$$    $$$ $$$  $$$$$\n"); Sleep(40);
	gotoxy(3, 36); printf("  $$$   $$$   $$$  $$$   $$$$   $$$$$$$$$ $$$   $$$ $$$    $$$ $$$   $$$$\n");
}
void help(int& thoat)
{
	khungplay();
	for (int i = 0; i < 45; i++)
	{
		gotoxy(18 + i, 11); printf(" ");
	}
	for (int i = 0; i < 45; i++)
	{
		gotoxy(18 + i, 21); printf(" ");
	}
	gotoxy(33, 8); TextColor(12); printf("DIEU KHIEN");
	TextColor(14);
	gotoxy(12, 10);  printf("NGUOI CHOI 1");
	gotoxy(16, 12); printf("A: Sang Trai");
	gotoxy(16, 13); printf("D: Sang Phai");
	gotoxy(16, 14); printf("S: Len Tren");
	gotoxy(16, 15); printf("W: Xuong Duoi");
	gotoxy(16, 16); printf("E: OK");

	gotoxy(46, 10);  printf("NGUOI CHOI 2");
	gotoxy(50, 12); printf("4: Sang Trai");
	gotoxy(50, 13); printf("6: Sang Phai");
	gotoxy(50, 14); printf("8: Len Tren");
	gotoxy(50, 15); printf("2: Xuong Duoi");
	gotoxy(50, 16); printf("5: OK");
	gotoxy(37, 40); TextColor(47); printf("  EXIT  ");
	gotoxy(41, 40);
	TextColor(0);
	char a;
	do
	{
		a = _getch();
	} while (a != 13 && a != 'e' && a != 'E' && a != '5' && a != 8);
	system("cls");
	fflush(stdin);
	playgame(thoat);
}
void about(int& thoat)
{
	khungplay();
	for (int i = 0; i < 45; i++)
	{
		gotoxy(18 + i, 11); printf(" ");
	}
	for (int i = 0; i < 45; i++)
	{
		gotoxy(18 + i, 21); printf(" ");
	}
	gotoxy(22, 10); TextColor(11); printf("Name:");       gotoxy(34, 10); TextColor(15); printf("TAN CU CHAN");
	gotoxy(22, 11); TextColor(11); printf("Birthday:");   gotoxy(34, 11); TextColor(10); printf("16/07/1999");
	gotoxy(22, 12); TextColor(11); printf("Fcebook:");    gotoxy(34, 12); TextColor(10); printf("Fb.com/tanchan679");
	gotoxy(22, 13); TextColor(11); printf("Gmail:");      gotoxy(34, 13); TextColor(10); printf("tanchan679@gmail.com");
	gotoxy(22, 14); TextColor(11); printf("Address:");    gotoxy(34, 14); TextColor(10); printf("Sin Ho - Lai Chau");
	gotoxy(22, 15); TextColor(11); printf("Schools:");    gotoxy(34, 15); TextColor(10); printf("CNTT & TT Thai Nguyen");
	gotoxy(22, 16); TextColor(11); printf("Occupation:"); gotoxy(34, 16); TextColor(10); printf("Sinh Vien");
	gotoxy(22, 17); TextColor(11); printf("Hobby:");      gotoxy(34, 17); TextColor(10); printf("Play Game");

	gotoxy(37, 40); TextColor(47); printf("  EXIT  ");
	gotoxy(41, 40);
	TextColor(0);
	char a;
	do
	{
		a = _getch();
	} while (a != 13 && a != 'e' && a != 'E' && a != '5' && a != 8);
	system("cls");
	fflush(stdin);
	playgame(thoat);
}


