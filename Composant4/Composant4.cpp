#include "Composant4.h"
#include "sha512.h"
#include <iostream>

string Composant4::SHAOne(Bloc b)
{
	string toHash = bToString(b);
	if (toHash.size() == 0)
	{
		cout << "Incorrect length" << endl;
		return "";
	}
	return(SHAOne(toHash));
}

string charToString(unsigned char* tab, unsigned int size) {
	string str = "";

	for (unsigned int i = 0; i<size; i++) {
		str += tab[i];
	}
	return str;
}

string charToString(char tab[], unsigned int size) {
	string str = "";
	for (unsigned int i = 0; i<size; i++) {
		str += tab[i];
	}
	return str;
}

string Composant4::bToString(Bloc bloc) {
	return "previous_hash:" + charToString(bloc.previous_hash, 64) + "," +
		"nonce:" + to_string(bloc.nonce) + "," +
		"num:" + to_string(bloc.num) + "," +
		"tx1:{" +
		"txi[0]:{" +
		"nBloc:" + to_string(bloc.tx1.txi[0].nBloc) + "," +
		"nTx:" + to_string(bloc.tx1.txi[0].nTx) + "," +
		"nUtxo:" + to_string(bloc.tx1.txi[0].nUtxo) + "," +
		"signature:" + charToString(bloc.tx1.txi[0].signature, 64) + "}," +
		"txi[1]:{" +
		"nBloc:" + to_string(bloc.tx1.txi[1].nBloc) + "," +
		"nTx:" + to_string(bloc.tx1.txi[1].nTx) + "," +
		"nUtxo:" + to_string(bloc.tx1.txi[1].nUtxo) + "," +
		"signature:" + charToString(bloc.tx1.txi[1].signature, 64) + "}," +
		"txi[2]:{" +
		"nBloc:" + to_string(bloc.tx1.txi[2].nBloc) + "," +
		"nTx:" + to_string(bloc.tx1.txi[2].nTx) + "," +
		"nUtxo:" + to_string(bloc.tx1.txi[2].nUtxo) + "," +
		"signature:" + charToString(bloc.tx1.txi[2].signature, 64) + "}," +
		"txi[3]:{" +
		"nBloc:" + to_string(bloc.tx1.txi[3].nBloc) + "," +
		"nTx:" + to_string(bloc.tx1.txi[3].nTx) + "," +
		"nUtxo:" + to_string(bloc.tx1.txi[3].nUtxo) + "," +
		"signature:" + charToString(bloc.tx1.txi[3].signature, 64) + "}," +
		"utxo[0]:{" +
		"montant:" + to_string(bloc.tx1.utxo[0].montant) + "," +
		"dest:" + charToString(bloc.tx1.utxo[0].dest, 4) + "," +
		"hash:" + charToString(bloc.tx1.utxo[0].hash, 64) + "}," +
		"utxo[1]:{" +
		"montant:" + to_string(bloc.tx1.utxo[1].montant) + "," +
		"dest:" + charToString(bloc.tx1.utxo[1].dest, 4) + "," +
		"hash:" + charToString(bloc.tx1.utxo[1].hash, 64) + "}" +
		"}," +
		"tx0:{" +
		"utxo[0]:{" +
		"montant:" + to_string(bloc.tx0.utxo[0].montant) + "," +
		"dest:" + charToString(bloc.tx0.utxo[0].dest, 4) + "," +
		"hash:" + charToString(bloc.tx0.utxo[0].hash, 64) + "}" +
		"}" +
		"}";
}

Composant4::Composant4()
{
}

string Composant4::SHAOne(string s)
{
	if (s.size() == 0)
	{
		cout << "Incorrect length" << endl;
		return "";
	}
	return (sha512(s));
}

bool Composant4::VerificateurBloc(Bloc b, string d)
{
	string result = SHAOne(b);
	if (result.compare(d) == 0)
		return true;
	return false;
}

bool Composant4::VerificateurHash(string b, string d)
{
	string result = SHAOne(b);
	if (result.compare(d) == 0)
		return true;
	return false;
}


