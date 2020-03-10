#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	ifstream entrada ("entrada.txt");
	int m, n, value;
	string line;

	entrada >> m;
	entrada >> n;

	vector<vector<int>> Rest(m, vector<int>(n, 0));
	vector<int> Bounds(n, 0);
	vector<bool> Ativo(m, true);
	vector<int> Quantidade(m, 0);

	getline(entrada, line); //bug
	for (int i = 0; i < n; ++i)
	{		
		getline(entrada, line);
		stringstream ss;
		ss.str (line);
		while(ss >> value)
		{
			Rest[value-1][i] = 1;

		}
	}

	entrada.close();

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << Rest[i][j] << ' ';
		}
		cout << endl;
	}

	// Simplificação 1
	int soma = 0, indice;
	for (int i = 0; i < m; ++i){
		soma = 0;
		// SOMAR OS VALORES DA RESTRIÇÃO
		for (int j = 0; j < n; ++j){
			soma += Rest[i][j];
			// cout << i << " soma="<<soma<<endl;
		}
		Quantidade[i] = soma;
		if (soma == 1){
			// cout << "Entrou"<<endl;
			int j = 0;
			
			while(Rest[i][j] == 0){
				j++;
			}
			//Sujeito a erros
			Bounds[j] = 1;

			for (int k = 0; k < m; ++k)
			{
				if(Rest[k][j] == 1){
					Ativo[k] = false;
				}
			}
		}
	}

	// Simplificação 2
	int count = 0;
	for (int i = 0; i < m; ++i){
		if (Ativo[i]){
			for (int j = i+1; j < m; ++j){
				if (Ativo[j] && Ativo[i]){
					count = 0;
					for (int k = 0; k < n; ++k){
						if(Rest[i][k] == Rest[j][k]){
							count++;
						}
					}
					if(count == Quantidade[i]){
						Ativo[j] = false;
					}else if(count == Quantidade[j]){
						Ativo[i] = false;
						break;
					}
				}
			}
		}
	}

	//--------Saída-------------------------
	ofstream saida ("saida.txt");
	saida << "Minimize\n";
	saida << " obj: ";
	for (int i = 1; i <= n; ++i)
	{
		if(i > 1) saida << " + ";
		saida << "x"<<i;
	}
	saida << "\nSubject To\n";
	for (int i = 0; i < m; ++i)
	{
		int flag= 0; // Bug
		if(Ativo[i]){
			saida << " c" << i+1 << ": ";
			for (int j = 0; j < n; ++j){
				if(Rest[i][j] == 1){
					if(flag == 1){
						saida << " + ";
					}else{
						flag = 1;
					}
					saida << "x"<<j+1;
				}
			}
			saida << " >= 1\n";
		}
	}
	saida << "Bounds\n";
	for (int i = 0; i < n; ++i)
	{
		saida << " "<<Bounds[i] << " <= x"<< i+1 <<" <= 1\n";
	}
	saida << "General\n";
	for (int i = 0; i < n; ++i)
	{
		saida << " x"<<i+1;
	}
	saida << "\nEnd\n";
	saida.close();
}