#pragma once
#include <string>
#include "Bloc.h"
using namespace std;

#ifndef COMPOSANT4_H
#define COMPOSANT4_H


#ifdef COMPOSANT4_EXPORTS
#define COMPOSANT4_INTERFACE __declspec(dllexport)
#else
#define COMPOSANT4_INTERFACE __declspec(dllimport)
#endif





class Composant4 {

public:
	string	SHAOne(Bloc b);
	string	SHAOne(string s);
	bool VerificateurBloc(Bloc b, string d);
	bool VerificateurHash(string s, string d);
	string bToString(Bloc bloc);
	Composant4();

};

#endif
