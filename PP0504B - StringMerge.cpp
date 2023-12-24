#include <iostream>
#include <cstring>

using namespace std;

#define T_SIZE 1001

char* string_merge(char* str1, char* str2);

int main() {
    int t,n;
    char S1[T_SIZE], S2[T_SIZE], *S;
    
    cin >> t; /* wczytaj liczbę testów */
    cin.getline(S1,T_SIZE);
    
    while(t) {
        cin.getline(S1,T_SIZE,' ');
        cin.getline(S2,T_SIZE);       
        S=string_merge(S1,S2);
        cout << S << endl;
        delete[] S;
        t--;
    }
    return 0;
}

char* string_merge(char* str1, char* str2) {
    int len_str1 = 0, len_str2 = 0;
    char* result_string;

    while (str1[len_str1]) {
        len_str1++;
    }
    while (str2[len_str2]) {
        len_str2++;
    }
    if (len_str1 >= len_str2) {
        result_string = new char[2*len_str2+1];
        for (int i = 0, j = 0; i < len_str2; i++, j = j + 2) {
            result_string[j] = str1[i];
            result_string[j+1] = str2[i];
        }
        result_string[2*len_str2] = '\0';
    } else {
        result_string = new char[2*len_str1+1];
        for (int i = 0, j = 0; i < len_str1; i++, j = j + 2) {
            result_string[j] = str1[i];
            result_string[j+1] = str2[i];
        }
        result_string[2*len_str1] = '\0';
    }
    return result_string;
}
