#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono_literals;
using namespace std::this_thread;


	

void imprime(int hastes[][3], int disco){
	system("cls");
	for (int i=0; i<disco; i++){
		for(int j=0; j<3; j++){
			
			int cor=0;
			if(hastes[i][j]>7){
				cor=53;
			}
			
			if(hastes[i][j]>0){
				for(int m=0; m<disco- (hastes[i][j] ); m++){
					cout << "\033[0m " << "\033[0m";
				}
				cout << "\033[" <<30+hastes[i][j]+cor<<"m[" << "\033[0m";
				for(int n=0; n< hastes[i][j]; n++){
					cout << "\033[" <<40+hastes[i][j]+cor<<"m " << "\033[0m";
				}
				cout << "||";
				for(int n=0; n< hastes[i][j]; n++){
					cout << "\033[" <<40+hastes[i][j]+cor<<"m " << "\033[0m";
				}
				cout << "\033[" <<30+hastes[i][j]+cor<<"m]";
				for(int m=0; m< disco- (hastes[i][j] ); m++){
					cout << "\033[0m " << "\033[0m";
				}
			}else{
				for(int m=0; m<disco- (hastes[i][j] ); m++){
					cout << "\033[0m " << "\033[0m";
				}
				cout << " ";
				for(int n=0; n< hastes[i][j]; n++){
					cout << "\033[0m " << "\033[0m";
				}
				cout << "||";
				for(int n=0; n< hastes[i][j]; n++){
					cout << "\033[0m " << "\033[0m";
				}
				cout << " ";
				for(int m=0; m< disco- (hastes[i][j] ); m++){
					cout << "\033[0m " << "\033[0m";
				}
		}
		}
		cout << endl;
	}
	sleep_for(1000ms);
}

void invalid(int d);

void hanoi(int hastes[][3], int disc, int origem, int destino, int aux, int *cima, int ttl){
	if(disc==1){
		cima[destino]--;
		hastes[  cima[destino] ][destino] = hastes[  cima[origem]  ][origem];
		hastes[  cima[origem]  ][origem] = 0;
		cima[origem]++;
		imprime(hastes, ttl);
	}else{
	hanoi (hastes, disc-1, origem, aux, destino, cima, ttl);
	
	cima[destino]--;
    hastes[ cima[destino] ][destino] = hastes[ cima[origem] ][origem];
    hastes[ cima[origem] ][origem] = 0;
    cima[origem]++;
    
	imprime(hastes, ttl);
	hanoi (hastes, disc-1, aux, destino, origem, cima, ttl);
	

	}
}

int main(){
	int discos, total=0;
	cin >> discos;
	if(discos >15){
		invalid(discos);
		return 0;
	}
	int torre[discos][3]={0};
	int topo[3]={0, discos, discos};
	for(int i=discos; i>0; i--){
		torre[i-1][0] = i;
	}
	total = discos;
	imprime(torre, total);
	hanoi (torre, discos, 0, 2, 1, topo, total);
	
	int passos=2;
	for (int t=0; t<total-1; t++){
		passos*=2;
	}
	passos--;
	cout << endl << "\033[95mtorre de hanoi completa em " << passos << " passos";
	
	return 0;
}




























void invalid(int d){
	if(d==20000){
		cout << "VINTE MIL DISCOS??? TA DOIDA?????????????";
		return;
			}
	cout <<endl << "TA QUERENDO QUEIMAR SEU PC??????";
}