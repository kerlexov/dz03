#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>

constexpr auto REDAK = 20;
constexpr auto STUPAC = 40;

using namespace std;

struct tocka
{
	int x = 0;
	int y = 0;
};

void postavi(tocka& p, tocka& k) {
	cout << "Upisi x koordinate tocke A od 1 do 20: "; cin >> p.y;
	cout << "Upisi y koordinate tocke  A od 1 do 40: "; cin >> p.x;
	cout << "Upisi x koordinate tocke B od 1 do 20: "; cin >> k.y;
	cout << "Upisi y koordinate tocke  B od 1 do 40: "; cin >> k.x;
	p.x = p.x - 1;
	p.y = p.y - 1;
	k.x = k.x - 1;
	k.y = k.y - 1;
}

int main() {
	tocka pocetak, sada, kraj;
	bool gotovo = false;
	string ploha[REDAK][STUPAC];
	bool prikraju = 0;

	postavi(pocetak, kraj);

	if (pocetak.x < 0 && pocetak.x > STUPAC && pocetak.y < 0 && pocetak.y > REDAK && kraj.x < 0 && kraj.x > STUPAC && kraj.y < 0 && kraj.y > REDAK){
		system("cls");
		cout << "Raspon je kriv unesi ponovo! " << endl;
		postavi(pocetak, kraj);
	}
	sada = pocetak;
	
	/* for (unsigned i = 1; i < 10; i++)
	{
		ploha[i][REDAK] = "#";
	} */

	while (!gotovo){
		Sleep(100);
		if ((kraj.y - sada.y) > 0 && ploha[sada.y + 1][sada.x] != "#")
			sada.y++;
		else if ((kraj.y - sada.y) < 0 && ploha[sada.y + 1][sada.x] != "#")
			sada.y--;
		if ((kraj.x - sada.x) > 0 && ploha[sada.y][sada.x + 1] != "#")
			sada.x++;
		else if ((kraj.x - sada.x) < 0 && ploha[sada.y][sada.x + 1] != "#")
			sada.x--;
			{
			if (ploha[sada.y][sada.x - 1] == "#" || ploha[sada.y][sada.x + 1] == "#")
				if (ploha[sada.y + 1][sada.x] == "#")
					sada.y--;
				else if (ploha[sada.y - 1][sada.x] == "#")
					sada.y++;
			}
		if (prikraju) { system("pause"); gotovo = true; }
		system("cls");
		for (int i = 0; i < REDAK; i++){
			for (int j = 0; j < STUPAC; j++){
				if (pocetak.y == i && pocetak.x == j)
					ploha[i][j] = "A";
				else if (kraj.y == i && kraj.x == j) {
					if (!prikraju) {
						ploha[i][j] = "B";
					}
					else {
						ploha[i][j] = "X";
					}
				}
				else if (sada.y == kraj.y && sada.x == kraj.x) {
					prikraju = true;
					ploha[i][j] = "-";
				}
				else{
					if (ploha[i][j] != "A" && ploha[i][j] != "B" && ploha[i][j] != "#")
						ploha[i][j] = "-";
					ploha[sada.y][sada.x] = "X";

				}
				cout << ploha[i][j];
			}
			cout << endl;
		}
	}
	cout << endl;
	return 0;
}