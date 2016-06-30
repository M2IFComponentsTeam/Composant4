// BlockChain.cpp : définit le point d'entrée pour l'application console.
//
#include "stdafx.h"
#include <iostream>
#include "Composant4.h"
#include "Bloc.h"

using namespace std;

int main(int argc, char *argv[])
{
	unsigned char tab[64] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','1','2' };
	TXI txi[4];
	txi[0] = *new TXI(3, 5, 7, tab);
	txi[1] = *new TXI(4, 6, 8, tab);
	txi[2] = *new TXI(5, 7, 9, tab);
	txi[3] = *new TXI(6, 8, 0, tab);

	unsigned char tab3[64] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','1','2','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	unsigned char tab2[4] = { 'a','b','1','2' };
	UTXO utxo[2];
	utxo[0] = *new UTXO(100, tab2, tab3);
	utxo[1] = *new UTXO(230, tab2, tab3);
	TX tx = *new TX(txi, utxo);
	UTXO utxo2[1];
	utxo2[0] = *new UTXO(1000, tab2, tab3);
	TXM txm = *new TXM(utxo2);
	char tab4[64];

	char tab5[64] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','1','2','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	Bloc bloc = *new Bloc(tab4, tab5, 2, 1, tx, txm);


	Composant4 hasheur;
	string toHash = hasheur.bToString(bloc);
	string output1 = hasheur.SHAOne(toHash);

	cout << "shaOne('" << toHash << "'):" << output1 << endl;
	system("pause");

}