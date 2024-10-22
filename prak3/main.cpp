#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;


int main(int argc, char* argv[]){
    setlocale(LC_ALL, "Russian");
    string t;
    vector<string> words;
    cout << "Введите строку: " << endl;
    getline(cin, t);
    istringstream iss(t);
    
    string word;
    while(iss >> word) {
	words.push_back(word);
	if(word.length() % 2 == 0){
	    string left_part_str = word.substr(0, word.length() / 2);
	    string right_part_str =  word.substr(word.length() / 2);

	    set<char> left_part_set(left_part_str.begin(), left_part_str.end());
	    set<char> right_part_set(right_part_str.begin(), right_part_str.end());
	    set<int> difference;

    	    set_difference(
                left_part_set.begin(), left_part_set.end(), right_part_set.begin(), right_part_set.end(),
                inserter(difference, difference.begin()));
	    if(difference.size() == 0){
	    	cout << "Слово: " << word << endl;
		int pair_count = 0;
		set<char> symbols(word.begin(), word.end());
		for(auto &i: symbols){
		    int sym_count = count(word.begin(), word.end(), i);
		    if(sym_count > 1){
		    	pair_count += sym_count / 2;
		    }
		}
		cout << "Кол-во пар: " << pair_count << endl;		
	    	cout << endl;
	    }
	}
    }
    cout << "Вывод текста: " << endl;
    for(auto &i: words){
        cout << i << " ";
    }
    cout << endl;
	
    return 0;
}
