#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
    string iname, oname, line, word;
    ifstream ifile;
    ofstream ofile;
    cout << "Введите входной файл: " << endl;
    cin >> iname;
       
    cout << "Введите выходной файл: " << endl;
    cin >> oname; 

    ifile.open(iname);
    ofile.open(oname);
    int sum_len = 0;
    while (getline(ifile, line)) {
    	istringstream iss(line);
 	int max_len = 0;
	while(iss >> word){
	    max_len = max(max_len, static_cast<int>(word.length()));
	}
	ofile << line << " " << max_len << "\n";
	sum_len += max_len;
    }
    ofile << sum_len;
    ofile.close();
    ifile.close();
    return 0;
}
