#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unistd.h>
#include <unordered_map>


using namespace std ;




char decoder(int nbr) {
	static const char table[28] = {
    '-','A','B','C','D','E','F','G','H','I','K','L','M','N','P','Q', 
    'R','S','T','V','W','X','Y','Z','U','*','O','J'};
	if (nbr<28) 
		return table[nbr];
	
	else 
		cout << "Erreur" << endl;
}	

	
/*	
static const unordered_map<int, char> table ;

table.insert(
	{0,"-"},
	{1,"A"},
	{2,"B"},
	{3,"C"},
	{4,"D"},
	{5,"E"},
	{6,"F"},
	{7,"G"},
	{8,"H"},
	{9,"I"},
	{10,"K"},
	{11,"L"},
	{12,"M"},
	{13,"N"},
	{14,"P"},
	{15,"Q"},
	{16,"R"},
	{17,"S"},
	{18,"T"},
	{19,"V"},
	{20,"W"},
	{21,"X"},
	{22,"Y"},
	{23,"Z"},
	{24,"U"},
	{25,"*"},
	{26,"O"},
	{27,"J"}
);
	
	char ret = table[nbr];
	return ret;
*/
	
	
	
		
	
	

