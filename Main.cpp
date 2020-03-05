// command compilation
// g++ -std=c++11 Main.cpp -o Main

#include <algorithm>
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

	// vector<int> v;
	// vector<vector<int>> S(n);
	vector<vector<int>> C(m, vector<int>(n, 0));
	vector<vector<int>> Bound(n, vector<int>(2, 0));
	

	getline(entrada, line);
	for (int i = 0; i < n; ++i)
	{		
		getline(entrada, line);
		std::stringstream ss;
		ss.str (line);
		while(ss >> v1)
		{
			C[v1-1][i] = 1;
		}

			// S[i].push_back(v1);
	}

	entrada.close();

	for(auto i: C){
		for(auto j: i){
			cout << j << ' ';
		}
		cout << endl;
	}


//--------Simplificações--------------------
	// Simplificação 1

	for(auto i: C){
		int sum = 0;
		int s = 0
		for(auto j: i){
			if(C[j] == 1){
				if(sum > 0)
					break
				sum++;
				s = j;
			}

		}
		if(sum == 1){
			Bound[s][0] = 1;
			Bound[s][1] = 1;
		}

	}

	// Simplificação 2
	// for_each(begin(C), end(C))

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