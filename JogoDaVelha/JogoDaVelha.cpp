#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>
#include <cctype>

using namespace std;
int rounds(int venceu, int busca){
	static int vencedor[4]={0};
	vencedor[venceu]++;
	return vencedor[busca];
}

int ganhou(int veia[3][3]){
	for (int j=0; j<3; j++){
	    if(veia[0][j]!=0 && veia[0][j] == veia[1][j] && veia[0][j] == veia[2][j]){
	 			return 1;
		 }
	}
	
	for (int j=0; j<3; j++){
	    if(veia[j][0]!=0 && veia[j][0] == veia[j][1] && veia[j][0] == veia[j][2]){
	 			return 1;
		 }
	}
	
	if(veia[0][0] != 0 && veia[0][0] == veia[1][1] && veia[0][0] == veia[2][2]){
		return 1;
	}else if(veia[0][2] != 0 && veia[0][2] == veia[1][1] && veia[2][0] == veia[0][2]){
		return 1;
	}
	return 0;
}

int velha(int velha[3][3], char ox[3], int crd[2], char nick[2][3], bool jog, int cor[2]){
		for(int i=0; i<3; i++){
			for (int j=0; j<3; j++){
				cout << "|" << "\033[" << 30+cor[(velha[i][j])-1] << "m"  <<  ox[velha[i][j]] << "\033[0m";
			}
		cout << "|" << endl;
	}
	cout << endl << "linha: " << crd[1]+1 << " coluna: " << crd[0] +1;
	cout << endl << "Vez de ";
	for (int i=0; i<3; i++){
		cout << "\033[" << 30+cor[jog] << "m" <<nick[jog][i] << "\033[0m";
	}
	cout << " (" << ox[jog+1] << ")"; 
}

int jogar(char nome[2][3], int cor[2]){
	system ("color");
int tab[3][3]={0}, cord[2]={0}, ganhador=2, ctd=0;
char xo[3]={' ', 'O', 'X'}, tec;
bool win=0, jogador=0;


velha(tab, xo, cord, nome, jogador, cor);
cout << "\033[H" << "\033[1C";

while (win==0 && ctd <9){
	tec= _getwch();
	
	if(tec == 'd'){
		cord[0]++;
			if(cord[0] == 3){
				cord[0]=0;
			}
			cout << "\033[H";
		velha(tab, xo, cord, nome, jogador, cor);
		cout << "\033[H"; 
		if (cord[1] != 0){
			cout << "\033[" << cord[1] << "B";
		}
		cout << "\033[" << 1+ cord[0]*2 << "C";
		
	} else if(tec == 's'){
		cord[1]++;
			if(cord[1] == 3){
				cord[1]=0;
			}
		cout << "\033[H";
		velha(tab, xo, cord, nome, jogador, cor);
		cout << "\033[H"; 
		if (cord[1] != 0){
			cout << "\033[" << cord[1] << "B";
		}
		cout << "\033[" << 1+ cord[0]*2 << "C";
		
	} else if(tec == 'a'){
		cord[0]--;
			if(cord[0] == -1){
				cord[0]=2;
			}
			cout << "\033[H";
		velha(tab, xo, cord, nome, jogador, cor);
		cout << "\033[H"; 
		if (cord[1] != 0){
			cout << "\033[" << cord[1] << "B";
		}
		cout << "\033[" << 1+ cord[0]*2 << "C";
		
	}else if(tec == 'w'){
		cord[1]--;
			if(cord[1] == -1){
				cord[1]=2;
			}
		cout << "\033[H";
		velha(tab, xo, cord, nome, jogador, cor);
		cout << "\033[H"; 
		if (cord[1] != 0){
			cout << "\033[" << cord[1] << "B";
		}
		cout << "\033[" << 1+ cord[0]*2 << "C";
		
	} else if(tec=='x' || tec=='o'){
		if (tab[cord[1]][cord[0]]==0){
			ctd++;
				if(jogador==0){
			tab[cord[1]][cord[0]]=1;
			jogador=1;
		}else if(jogador==1){
			tab[cord[1]][cord[0]]=2;
			jogador=0;
		}
		cout << "\033[H";
		velha(tab, xo, cord, nome, jogador, cor);;
		cout << "\033[H"; 
		if (cord[1] != 0){
			cout << "\033[" << cord[1] << "B";
		}
		cout << "\033[" << 1+ cord[0]*2 << "C";
		
		}
		win = ganhou(tab);
	}
}
cout << "\033[H";
int o=0, x=0;
for (int i=0; i<3; i++){
	
	for(int j=0; j<3; j++){
		cout << "|" << "\033[" << 30+cor[(tab[i][j])-1] << "m"  <<  xo[tab[i][j]] << "\033[0m";
		if(tab[i][j]==1 && win==1){
			o++;
		}else if(tab[i][j]==2 && win==1){
			x++;
		}
	}
	cout <<"|" << endl;
	if(o>x&& win == 1){
		ganhador=0;
	}else if(x>=o&& win==1){
		ganhador=1;
	}
}
	if(ganhador==0){
		cout << endl << " O vencedor foi ";
		for (int i=0; i<3 ; i++){
			cout << "\033[" << 30+cor[0] << "m" <<nome[0][i] << "\033[0m";
		}
		cout << " (" << "\033[" << 30+cor[0] << "m" << "O" << "\033[0m"<< ") !!! Parabens!!";
	}else if(ganhador==1){
		cout << endl << " O vencedor foi ";
		for (int i=0; i<3 ; i++){
		cout << "\033[" << 30+cor[1] << "m" <<nome[1][i] << "\033[0m";
		}
		cout << " (" << "\033[" << 30+cor[1] << "m" << "X" << "\033[0m"<< ") !!! Parabens!!";
	}else {
		cout << "Deu velha!!";
	}
rounds(ganhador, 0);

	return 0;
}

int main(){
	srand(time(0));
	char nomes[2][3], denovo=' ';
	int cores[2], vitorias[2], xis=0, bola=0, velha=0;
	cout << "insira o nome\ndo jogador O\ndepois do jogador X\n(3 letras cada)\n";
for (int i=0; i<2; i++){
	for (int j=0; j<3; j++){
		nomes[i][j] = _getwch();
		cout << nomes[i][j];
	}
	cout << endl;
}
	system ("cls");
	cout << "\033[31m 1 " << "\033[32m 2 " <<"\033[33m 3 " <<"\033[34m 4 " <<"\033[35m 5 " <<"\033[36m 6 " <<"\033[37m 7 " << "\033[0m\nEscolha uma cor para ";
	for (int i=0; i<3 ; i++){
		cout << nomes[0][i];
	}
	cout << endl;
	cin >> cores[0];
	if (cores[0]==20000){
		cores[0]=65;
	}else if(cores[0] > 7 && cores[0] < 20000 && cores[0] != 65){
		cores[0]=1+rand()%6;
		bool se=rand()%2;
		if(se==0){
			cores[0]+=60;
		}
	}

	cout << endl << "Escolha uma cor para ";
for (int i=0; i<3 ; i++){
		cout << nomes[1][i];
	}
	cout << endl;
	cin >> cores[1];
	if (cores[1]==20000){
		cores[1]=65;
	}else if(cores[1] > 7 && cores[1] < 20000 && cores[1] != 65){
		cores[1]=1+rand()%6;
		bool se=rand()%2;
		if(se==1){
			cores[1]+=60;
		}
	}
	
	system ("cls");
	while(denovo!='n'){
		
	jogar(nomes, cores);
	cout << endl << "\njogar denovo?\n";
	
		do{
			denovo = _getwch();
		}while(denovo !='s' && denovo !='n');
		system ("cls");
	}
	bola= rounds(3, 0);
	xis= rounds(3, 1);
	velha= rounds(3, 2);
	cout <<  "o placar final foi:" << endl;
		for (int i=0; i<3; i++){
		cout << "\033[" << 30+cores[0] << "m" <<nomes[0][i] << "\033[0m";
	}
	cout << " " << bola << " vitorias" << endl;
	
		for (int i=0; i<3; i++){
		cout << "\033[" << 30+cores[1] << "m" <<nomes[1][i] << "\033[0m";
	}
	cout << " " << xis << " vitorias" << endl;
	
		
	cout << "Velha " << velha << " empates" << endl;
	return 0;
}