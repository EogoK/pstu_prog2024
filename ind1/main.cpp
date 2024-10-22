#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    srand(time(0));
    int n, flagg;
    cout << "Введите размер матрицы: ";
    cin >> n;
    if(n < 4 && n < 9){
         cout << "Вне диапазона";
        return 0;
    }
    cout << "1- ручной ввод \n2- рандомный выбор\nВыберите вариант ввода: ";
    cin >> flagg; 
    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<int> linear_arr(n*n);
    linear_arr.clear();
    
    if(flagg == 1){
    for(auto &i: arr){
        for(auto &j: i){
            cin >> j;
            linear_arr.push_back(j);
        }
    }
    }else{
       for(auto &i: arr){
        for(auto &j: i){
	    j = rand() % 1000;
            linear_arr.push_back(j);
        }
    }

    }
    
    for(auto &i: arr){
        cout << "| ";
        for(auto &j: i){
            cout << j << " ";
        }
        cout << "|\n";
    }
    
    sort(linear_arr.begin(), linear_arr.end(), greater<>());
    
    int last = 0;
    bool flag = false;
    
    cout << "\n";
    for(int i = 0; i < n; i++){
        while(true){
            arr[last][i] = linear_arr.back();
            linear_arr.pop_back();
            
            if(flag) last--;
            else last++;
            
            if(last == n || last < 0){
                last = last < 0 ? 0 : n - 1;
                flag = !flag;
                break;
            }
            
            
        }
    }
        
    for(auto &i: arr){
        cout << "| ";
        for(auto &j: i){
            cout << j << " ";
        }
        cout << "|\n";
    }
    
    int even_count = 0;
    cout << "Проверка на одну пару четных чисел по диаголи!" << endl;

    for(int i = 0; i < n; i++){
    	if(arr[i][i] % 2 == 0){
	    even_count++;
	}
    }
    if(even_count == 2){
    	cout << "Главная диагональ содержит ровно одну пару четных чисел!" << endl;
    	return 0;
    }else{
    	cout << "Не соответсвует условию задачи: ищем по 2 диагонали" << endl;
    }
    
    even_count = 0;
    for(int i = 0; i < n; i++){
    	if(arr[i][(n-1)-i] % 2 == 0){
	    even_count++;
	}
    }
    
    if(even_count == 2){
    	cout << "Вторая диагональ содержит ровно одну пару четных чисел!" << endl;
    }else{
    	cout << "Не соответсвует условию задачи пар не найдено" << endl;
    }

}
