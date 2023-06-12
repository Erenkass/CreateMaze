#include <iostream>
#include <time.h>
#include <vector>
#include <stack> 

using namespace std;

struct yol1 {
	int x;
	int y;
	char chr;
};

int yon[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

bool boslukkoy(vector <string>& labirent, vector < yol1 >& st, int yons[4])
{
	bool t = true;
	yol1 temp;
	temp.x = st.back().x;
	temp.y = st.back().y;
	for (int i = 0; i < 4; i++)
	{
		temp.x += yon[yons[i]][0];
		temp.y += yon[yons[i]][1];
		if (temp.x < labirent.size() - 1 && temp.y < labirent[0].size() - 1 && temp.x > 0 && temp.y > 0 && labirent[temp.x][temp.y] != ' ')
		{
			t = true;
			for (int j = 0; j < 4; j++)
			{
				if (yons[i] + yons[j] == 3)
				{
					continue;
				}
				if (labirent[temp.x + yon[yons[j]][0]][temp.y + yon[yons[j]][1]] == ' ')
				{
					t = false;
					break;
				}
			}
			if (t)
			{
				labirent[temp.x][temp.y] = ' ';
				st.push_back(temp);
				return true;
			}
		}
		temp.x -= yon[yons[i]][0];
		temp.y -= yon[yons[i]][1];
		if (rand() % 100 < 10) {
			return false;
		}
	}
	st.pop_back();
	return false;
}

void labirentciz(vector <string>& labirent)
{

	int  i, j, yons[4], g;
	bool t = true;
	yol1 temp;
	vector < yol1> st;
	temp.x = rand() % (labirent.size() - 2) + 1;
	temp.y = 1;
	st.push_back(temp);
	labirent[temp.x][0] = ' ';
	labirent[temp.x][1] = ' ';

	while (1) {
		t = true;
		while (t) {

			for (i = 0; i < 4; i++) {
				yons[i] = i;
			}

			for (i = 0; i < 4; i++) {
				j = rand() % 4;
				swap(yons[i], yons[j]);
			}

			t = boslukkoy(labirent, st, yons);
		}
		if (st.size() < 3) {
			break;
		}
		swap(st[st.size() - 1], st[rand() % (st.size() - 1)]);
	}

	while (1) {
		i = rand() % (labirent.size() - 2) + 1;
		if (labirent[i][labirent[0].size() - 2] == ' ') {
			labirent[i][labirent[0].size() - 1] = 'y';
			return;
		}
	}
}

void labirentcoz(vector <string>& labirent, stack < yol1>& yol) {

	int i,j;
	bool t;
	yol1 temp;

	for (i = 0; i < labirent.size() - 1; i++) {
		if (labirent[i][0] == ' ') {
			labirent[i][0] = 205;
			temp.x = i;
			temp.y = 0;
			yol.push(temp);
			break;
		}
	}
	while (1) {
		temp.x = yol.top().x;
		temp.y = yol.top().y;
		t = true;
		for (int i = 0; i < 4; i++) {
			temp.x += yon[i][0];
			temp.y += yon[i][1];
			if (labirent[temp.x][temp.y] == 'y') {
				yol.push(temp);
				for (i = 0; i < labirent.size(); i++) {
					for (j = 0; j < labirent[0].size(); j++) {
						if (labirent[i][j] == '*') {
							labirent[i][j] = ' ';
						}
					}
				}
				return;
			}
			else if (labirent[temp.x][temp.y] == ' ') {
				labirent[temp.x][temp.y] = 205;
				yol.push(temp);
				t = false;
				break;
			}
			temp.x -= yon[i][0];
			temp.y -= yon[i][1];
		}
		if (t) {
			labirent[temp.x][temp.y] = '*';
			yol.pop();
		}
	}
}

void yazdir1(vector <string>& labirent) {
	cout << endl << endl << endl;
	for (int i = 0; i < labirent.size(); i++) {
		for (int j = 0; j < labirent[0].size(); j++) {
			cout << labirent[i][j];
			if (!(j == 0 || j == labirent[0].size() - 1)) {
				cout << labirent[i][j];
			}
			
		}
		cout << endl;
	}
}

void yazdir(vector <string>& labirent) {
	cout << endl<<endl<<endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	for (int i = 0; i < labirent.size(); i++) {
		for (int j = 0; j < labirent[i].size(); j++) {
			cout << labirent[i][j] ;
		}
		cout << endl;
	}

}

void duzenle(vector <string>& A, vector <string>& labirent ) {
	vector <yol1> duzen;
	yol1 temp;
	string temp1;
	for (int i = 0; i < A.size(); i++) {
		labirent.push_back(temp1);
		labirent[i].push_back(A[i][0]);
	}

	for (int i = 1; i < A[0].size()-1; i++) {
		labirent[0].push_back(A[0][i]);
		labirent[0].push_back(A[0][i]);
	}
	
	for (int i = 1; i < A.size()-1; i++)
	{
		for (int j = 1; j < A[0].size()-1; j++)
		{

			if (A[i][j] == 'Í')
			{
				char üst = A[i - 1][j];
				char alt = A[i + 1][j];
				char sag = A[i][j + 1];
				char sol = A[i][j - 1];

				if (sol == 'Í' && üst == 'Í')
				{
					labirent[i].push_back(202);
					labirent[i].push_back(188);
					temp.x = i;
					temp.y = j;
					temp.chr = 188;
					duzen.push_back(temp);
				}
				else if ((sag == 'Í' || sag == 'y') && üst == 'Í')
				{
					labirent[i].push_back(200);
					labirent[i].push_back(202);
					temp.x = i;
					temp.y = j;
					temp.chr = 200;
					duzen.push_back(temp);
				}
				else if ((sag == 'Í' || sag == 'y') && alt == 'Í')
				{
					labirent[i].push_back(201);
					labirent[i].push_back(203);
					temp.x = i;
					temp.y = j;
					temp.chr = 201;
					duzen.push_back(temp);
				}
				else if (sol == 'Í' && alt == 'Í')
				{
					labirent[i].push_back(203);
					labirent[i].push_back(187);
					temp.x = i;
					temp.y = j;
					temp.chr = 187;
					duzen.push_back(temp);
				}
				else if (alt == 'Í' && üst == 'Í')
				{
					labirent[i].push_back(186);
					labirent[i].push_back(186);
					temp.x = i;
					temp.y = j;
					temp.chr = 186;
					duzen.push_back(temp);
				}
				else {
					labirent[i].push_back(205);
					labirent[i].push_back(205);
				}
			}
			else if (A[i][j] == ' ') {
					labirent[i].push_back(32);
					labirent[i].push_back(32);
			}
			else  {
				labirent[i].push_back(219);
				labirent[i].push_back(219);
			}
			
			
		}
	}

	for (int i = 1; i < A[0].size()-1; i++) {
		labirent[labirent.size() - 1].push_back(A[A.size() - 1][i]);
		labirent[labirent.size() - 1].push_back(A[A.size() - 1][i]);
	}
	
	for (int i = 0; i < A.size(); i++) {
		labirent[i].push_back(A[i][A[0].size()-1]);
	}
}

int main() {

	srand(time(0));
	int i, j, satirsay, sutunsay,x;
	cout << "Labirentin boyutlarini girin:";
	cin >> satirsay >> sutunsay;
	string deneme;
	vector <string> labirent;
	vector <string> labirent2;
	stack <yol1> yol;
	for (i = 0; i < satirsay; i++) {
		labirent.push_back(deneme);
		for (j = 0; j < sutunsay; j++) {
			labirent[i].push_back(219);
		}
	}

	labirentciz(labirent);

	yazdir1(labirent);

	labirentcoz(labirent, yol);
	
	duzenle(labirent,labirent2);

	yazdir(labirent2);
	

	
	return 0;
}