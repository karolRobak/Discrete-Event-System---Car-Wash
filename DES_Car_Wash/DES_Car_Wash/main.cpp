#include<iostream>
#include<stdio.h>
#include<map>
#include<list>
#include"automata.h"
#include"transition.h"
#include"State.h"
#include<cstdio>
#include<string>

int main() {

	//state ID: first digit - numberOfAutomata two next digits - numberOfState e.g. 103 216
	const short automataNumber = 5;
	Automata automatons[automataNumber];
	std::string automataNames[automataNumber] = {
		"Myjnia",
		"WyborProgramu",
		"TestBezpieczenstwa",
		"Program1",
		"Program2"
	};
	State automataStates[NUMBER_OF_STATES] = {
		//Myjnia

			{"idle",				001 , 0},
			{"wyborProgramu",		002	, 0},
			{"testBezpieczenstwa",	003	, 0},
			{"zamkniecieBramy",		004	, 0},
			{"uruchomienieProgramu",005	, 0},
			{"wykonywaniePracy",	006	, 0},
			{"otwarcieStrefy",		007	, 0},
			{"wyjazdZMyjni"	,		  8	, 0},
		//wyborProgramu

			{"idle",				101	, 1},
			{"wyborProgramu",		102	, 1},
			{"wyliczKredyt",		103	, 1},
			{"wybranoProgram1",		104	, 1},
			{"wybranoProgram2",		105	, 1},
		//testBezpieczentwa

			{"idle",							201	, 2},
			{"wykonanoTest",					202	, 2},
			{"wMyjniZostalSamPojazd",			203	, 2},
			{"wykrytoObecnoscLudziWMyjni",		204	, 2},
		//Program1									
			{"idle",							301	, 3},
			{"zamkniecieBramy",					302	, 3},
			{"wybranyProgram1",					303	, 3},
			{"FAZAnakladaniePlynu",				304	, 3},
			{"ramieWysuniete",					305	, 3},
			{"spryskiwaniePojazduPlynem",		306	, 3},
			{"FAZAplukanie",					307	, 3},
			{"uruchomienieTasmociagu",			308	, 3},
			{"autoSplukane",					309	, 3},
			{"FAZAsuszenie",					310	, 3},
			{"dmuchawaAktywna",					311	, 3},
			{"osiagnietoPozycjeKoncowa",		312	, 3},
			{"brakWodyNaSamochodzie",			313	, 3},
			{"KONIECprogramu1",					314	, 3},
		//Program2

			{"idle",								401	, 4},
			{"zamkniecieBramy",						402	, 4},
			{"wybranoProgram",						403	, 4},
			{"FAZAnakladaniePlynu",					404	, 4},
			{"ramieWysuniete",						405	, 4},
			{"spryskiwaniePojazduPlynem",			406	, 4},
			{"FAZAplukanie",						407	, 4},
			{"uruchomienieTasmociagu",				408	, 4},
			{"autoSplukane",						409	, 4},
			{"FAZAsuszenie",						410	, 4},
			{"dmuchawaAktywna",						411	, 4},
			{"osiagnietoPozycjeKoncowa",			412	, 4},
			{"brakWodyNaSamochodzie",				413	, 4},
			{"FAZApolerowanieFelg",					414	, 4},
			{"ramionaZszczotkaObrotowaWysuniete",	415	, 4},
			{"polerowanieFelg",						416	, 4},
			{"kolaCzyste",							417	, 4},
			{"FAZAwoskowanie",						418	, 4},
			{"woskGotowy",							419	, 4},
			{"autoPokrywanieWoskiem",				420	, 4},
			{"koniecPodgrzewaniaWosku",				421	, 4},
			{"KONIECprogramu2",						422	, 4}

	};
	std::map<std::string, short> am = {
		{"Myjnia", 0},
		{"WyborProgramu",1},
		{"TestBezpieczenstwa",2},
		{"Program1",3},
		{"Program2",4}
	};
	Transition setOfTransitions[NUMBER_OF_TRANSITIONS] = {
		{am["Myjnia"],001,"przyjazdKlienta",1,002},
		{am["Myjnia"],002,"wybranyProgram1",3,003},
		{am["Myjnia"],002,"wybranyProgram2",4,003 },
		{am["Myjnia"],002,"wybranieZwrotuPieniedzy",2,001},
		{am["Myjnia"],003,"zagrozenie",6,003},
		{am["Myjnia"],003,"eSTOP",7,003},
		{am["Myjnia"],003,"wezwanieObslugi",5,001},
		{am["Myjnia"],003,"brakZagrozenia",8,004},
		{am["Myjnia"],004,"bramaZamknieta",9,005},
		{am["Myjnia"],004,"eSTOP",7,007},
		{am["Myjnia"],005,"eSTOP",7,007},
		{am["Myjnia"],005,"instalacjaGotowaDoPracy",10,006},
		{am["Myjnia"],006,"koniecProgramu",11,007},
		{am["Myjnia"],006,"eSTOP",7,007},
		{am["Myjnia"],007,"otwartaBrama",12,8},
		{am["Myjnia"],  8,"koniecObslugi",13,001},
		{am["WyborProgramu"],101,"przyjazdKlienta",1,102},
		{am["WyborProgramu"],102,"wrzuconoMonete",14,103},
		{am["WyborProgramu"],103,"wybranieZwrotuPieniedzy",2,101},
		{am["WyborProgramu"],103,"wrzuconoMonete",14,103},
		{am["WyborProgramu"],103,"wybranoProgram1IKredytJestWystarczajacy",15,104},
		{am["WyborProgramu"],103,"wybranoProgram2IKredytJestWyrtarczajacy",17,105},
		{am["WyborProgramu"],104,"wybranyProgram1",3,104},
		{am["WyborProgramu"],104,"wezwanieObslugi",5,101},
		{am["WyborProgramu"],104,"koniecObslugi",13,101},
		{am["WyborProgramu"],105,"wybranyProgram2",4,105},
		{am["WyborProgramu"],105,"koniecObslugi",13,101},
		{am["TestBezpieczenstwa"],201,"wybranyProgram1",3,202},
		{am["TestBezpieczenstwa"],201,"wybranyProgram2",4,202},
		{am["TestBezpieczenstwa"],202,"wezwanieObslugi",5,201},
		{am["TestBezpieczenstwa"],203,"koniecObslugi",13,201},
		{am["TestBezpieczenstwa"],202,"brakZagrozenia",8,203},
		{am["TestBezpieczenstwa"],202,"testNiezaliczony",19,204},
		{am["TestBezpieczenstwa"],204,"wybranyProgram1",3,202},
		{am["TestBezpieczenstwa"],204,"wybranyProgram2",4,202},
		{am["Program1"],301,"brakZagrozenia",8,302},
		{am["Program1"],302,"bramaZamknieta",9,303},
		{am["Program1"],303,"instalacjaGotowaDoPracy",10,304},
		{am["Program1"],304,"aktywacjaRamieniaZPlynem",21,305},
		{am["Program1"],305,"przygotowaniePorcjiPlynu",22,306},
		{am["Program1"],306,"pokrycieCalegoSamochodu",23,307},
		{am["Program1"],307,"otwarcieZaworowZWodaNaBramce",24,308},
		{am["Program1"],308,"przejazdAutaNaTasmociagu",25,309},
		{am["Program1"],309,"zamkniecieZaworowZWoda",26,310},
		{am["Program1"],310,"uruchomienieDmuchawy",27,311},
		{am["Program1"],311,"transportDoOsiagnieciaPozycjiKoncowej",28,312},
		{am["Program1"],312,"zatrzymanieTasmociagu",29,313},
		{am["Program1"],313,"wylaczenieDmuchawy",30,314},
		{am["Program1"],314,"koniecProgramu",11,314},
		{am["Program1"],314,"koniecObslugi",13,301},
		{am["Program2"],401,"brakZagrozenia",8,402 },
		{am["Program2"],402,"bramaZamknieta",9,403 },
		{am["Program2"],403,"instalacjaGotowaDoPracy",10,404 },
		{am["Program2"],404,"aktywacjaRamieniaZPlynem",21,405 },
		{am["Program2"],405,"przygotowaniePorcjiPlynu",22,406 },
		{am["Program2"],406,"pokrycieCalegoSamochodu",23,407 },
		{am["Program2"],407,"otwarcieZaworowZWodaNaBramce",24,408 },
		{am["Program2"],408,"przejazdAutaNaTasmociagu",25,409 },
		{am["Program2"],409,"zamkniecieZaworowZWoda",26,410 },
		{am["Program2"],410,"uruchomienieDmuchawy",27,411 },
		{am["Program2"],411,"transportDoOsiagnieciaPozycjiKoncowej",28,412 },
		{am["Program2"],412,"zatrzymanieTasmociagu",29,413 },
		{am["Program2"],413,"wylaczenieDmuchawy",30,414 },
		{am["Program2"],414,"koniecProgramu",11,422 },
		{am["Program2"],422,"koniecProgramu",11,422 },
		{am["Program2"],414,"wysuniecieRamionZSzczotkaObrotowa",31,415},
		{am["Program2"],415,"aktywacjaObrotowSzczotek",32,416},
		{am["Program2"],416,"uplynelo30s",33,417},
		{am["Program2"],417,"uplynelo30s",33,418},
		{am["Program2"],418,"podgrzewanieWosku",34,419},
		{am["Program2"],419,"aktywacjaRamieniaZDysza",35,420},
		{am["Program2"],420,"uplynelo30s",33,421},
		{am["Program2"],421,"deaktywacjaRamienia",36,422},
		{am["Program2"],422,"koniecObslugi",13,401 }
	};
	for (short i = 0; i < automataNumber; i++) {
		automatons[i].setName(automataNames[i]);
		automatons[i].setID(i);
		automatons[i].addStatesFrom(automataStates);
		automatons[i].addTransitionFrom(setOfTransitions);
		automatons[i].printNameAndCurrentState();
		automatons[i].showAvailableTransitions();

	}
	int transitionID = 0;
	while (transitionID != 999) {
		std::string temp;
		std::cout << "Enter selected transition ID: ";
		std::cin >> temp;
		sscanf_s(temp.c_str(), "%d", &transitionID);
		std::cout << "............................................." << std::endl;
		for (short i = 0; i < automataNumber; i++) {
			automatons[i].performTransition(transitionID);
			automatons[i].printNameAndCurrentState();
			automatons[i].showAvailableTransitions();
		}
	}
	system("PAUSE");
	return 0;
}