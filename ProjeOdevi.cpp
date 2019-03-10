#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#define BLACK			0
#define GREEN			2
#define WHITE			15


using namespace std;

void SayiOlustur();
int SayiKontrol();
int SayiYazdir(int miktar);
int Toplam;
int artis;
int Sayi;
int xsayi;
int bilk, bson;
int ysayi;
int ilkdeger, sondeger;
int xvalue[20];
int yvalue[20];
int matris[24][24];


//Renk degistirme fonksiyonu
void SetColorAndBackground(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
	return;
}
int main()
{
	
	srand(time(0));
	SayiOlustur();
	int Miktar = SayiKontrol();
	SayiYazdir(Miktar);
	getchar();
	
}

void SayiOlustur()
{
	for (int x = 0; x < 24; x++)
	{
		for (int y = 0; y < 24; y++)
		{
			matris[x][y] = (rand() % 9) + 1;
		}
	}
}



int SayiKontrol()
{
	
	ilkdeger = matris[0][0];
	artis = 0;

	for (int x = 0; x < 24; x++)
	{
		for (int y = 0; y < 24; y++)
		{
			Sayi = matris[x][y];


			//sol ust kose
			if (x == 0 && y == 0)
			{

				Toplam = matris[x + 1][y] + matris[x + 1][y + 1] + matris[x][y + 1];
				if (Toplam % 10 == Sayi)
				{
					xvalue[artis] = x;
					yvalue[artis] = y;
					artis += 1;
					break;
				}
			}

			//ust kose
			else if (x==0 && y > 0 && y<23)
			{
				Toplam = matris[x][y - 1] + matris[x + 1][y - 1] + matris[x + 1][y] + matris[x + 1][y + 1] + matris[x][y + 1];
				if (Toplam % 10 == Sayi)
				{
					xvalue[artis] = x;
					yvalue[artis] = y;
					artis += 1;
					break;
				}
			}

			
			//sag ust kose
			else if (x==0 && y==23)
			{
				Toplam = matris[x][y - 1] + matris[x + 1][y - 1] + matris[x + 1][y];
				if (Toplam % 10 == Sayi)
				{
					xvalue[artis] = x;
					yvalue[artis] = y;
					artis += 1;
					break;
				}
			}

			//sol kenar
			else if (y == 0 && x > 0 && x < 23)
			{
				Toplam = matris[x - 1][y] + matris[x - 1][y + 1] + matris[x][y + 1] + matris[x + 1][y + 1] + matris[x + 1][y];
				if (Toplam % 10 == Sayi)
				{
					xvalue[artis] = x;
					yvalue[artis] = y;
					artis += 1;
					break;
				}
			}

			//orta sayilar
			else if (y>0 && x>0 && y<23 && x<23)
			{
				Toplam = matris[x - 1][y - 1] + matris[x - 1][y] + matris[x - 1][y + 1] + matris[x][y + 1] + matris[x + 1][y + 1] + matris[x + 1][y] + matris[x + 1][y - 1] + matris[x][y - 1];
				if (Toplam % 10 == Sayi)
				{
					xvalue[artis] = x;
					yvalue[artis] = y;
					artis += 1;
					break;
				}
			}
			//matris[][]
			
			//sag kenar
			else if (y==23 && x != 0 && x != 23)
			{
				Toplam = matris[x - 1][y] + matris[x - 1][y - 1] + matris[x][y - 1] + matris[x+1][y-1] + matris[x+1][y];
				if (Toplam % 10 == Sayi)
				{
					xvalue[artis] = x;
					yvalue[artis] = y;
					artis += 1;
					break;
				}
			} 
			

			//sol alt kose
			else if (x==23 && y==0)
			{
				Toplam = matris[x-1][y] + matris[x-1][y + 1] + matris[x][y + 1];
				if (Toplam % 10 == Sayi)
				{
					xvalue[artis] = x;
					yvalue[artis] = y;
					artis += 1;
					break;
				}
			}

			//alt kenar
			else if (y > 0 && y<23 && x == 23)
			{
				Toplam = matris[x][y - 1] + matris[x - 1][y - 1] + matris[x - 1][y] + matris[x - 1][y + 1] + matris[x][y + 1];
				if (Toplam % 10 == Sayi)
				{
					xvalue[artis] = x;
					yvalue[artis] = y;
					artis += 1;
					break;
				}
			}

			//sag alt kose
			else if (y==23 && x==23)
			{
				Toplam = matris[x - 1][y] + matris[x - 1][y - 1] + matris[x][y - 1];
				if (Toplam % 10 == Sayi)
				{
					xvalue[artis] = x;
					yvalue[artis] = y;
					artis += 1;
					break;
				}	
			}	
	
		}

	}
	return artis;
}


//Sayilari yazdirma
int SayiYazdir(int miktar)
{
	
	
	artis = 0;
	for (int a = 0; a < 24; a++)
	{
		for (int b = 0; b < 24; b++)
		{
			for (int i = 0; i < miktar; i++)
			{
				if (xvalue[artis] == a && yvalue[artis] == b)
				{
					SetColorAndBackground(GREEN, 0);
					cout << matris[a][b] << " ";
					artis += 1;
					break;
				}
				else
				{
					goto exitx;
				}
			}
			continue;
			

			exitx:
			SetColorAndBackground(WHITE, 0);
			cout << matris[a][b] << " ";
			
		}
		cout << endl;
	}
	return miktar;
}

