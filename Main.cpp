// writing on a text file
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main () {
//------------Entrada---------------------
	ifstream entrada ("entrada.txt");

	int v1, m, n;
	string line;
	string::size_type sz;   // alias of size_t
	
	entrada >> m;
	entrada >> n;

	vector<int> v;
	vector<vector<int>> S(n);

	getline(entrada, line);
	for (int i = 0; i < n; ++i)
	{		
		getline(entrada, line);
		std::stringstream ss;
		ss.str (line);
		while(ss >> v1)
			S[i].push_back(v1);
	}

	entrada.close();

//--------Simplificações--------------------


//--------Saída-------------------------
	ofstream saida ("saida.txt");
	saida << "Minimize\n";
	saida << "obj: ";
	for (int i = 1; i <= n; ++i)
	{
		if(i > 1) saida << " +";
		saida << " x"<<i;
	}
	saida << "\nSubject To\n";
	saida << "\nBounds\n";
	saida << "\nEnd";
	saida.close();
}