#include <iostream>

using namespace std;

char** creating_array(int n) {
    if (n == 1 || n == -1) {
        char** arr = new char*[2];
        for (int i = 0; i < 2; i++) {
            arr[i] = new char[2];
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                arr[i][j] = '*';
            }
        }
        return arr;
    }
    
    char** recived_arr;
    char sign1,sign2;
    if (n < 0) {
        sign1 = '*';
        sign2 = '.';
        recived_arr = creating_array(n+1);
    } else {
        sign1 = '.';
        sign2 = '*';
        recived_arr = creating_array(n-1);
    }
    if (n < 0) n = -n;
    char** new_arr = new char*[2*n];
    for (int i = 0; i < 2*n; i++) {
        new_arr[i] = new char[2*n];
    }
    for(int i = 0; i < 2*n; i++) {
        for (int j = 0; j < 2*n; j++) {
            if ((j == 0 || j == 2*n-1) && (i == 0 || i == 2*n-1)) {
                new_arr[i][j] = '*';
            } else if (!(i == 0 || i == 2*n-1) && !(j == 0 || j == 2*n-1)) {
                new_arr[i][j] = recived_arr[i-1][j-1];
            } else new_arr[i][j] = 'a';
        }
    }
    for (int i = 0; i < n-1; i++) delete [] recived_arr[i];
    delete [] recived_arr;

    int character_switch = 0;
    for (int i = 1; i < 2*n-1; i++) {
        if (character_switch < n-1) {
            new_arr[0][i] = sign1;
            character_switch++;
        } else if (character_switch < 2*(n-1)) {
            new_arr[0][i] = sign2;
            character_switch++;
        }
        if (character_switch == 2*(n-1)) character_switch = 0;
    }
    for (int i = 1; i < 2*n-1; i++) {
        if (character_switch < n-1) {
            new_arr[i][2*n-1] = sign1;
            character_switch++;
        } else if (character_switch < 2*(n-1)) {
            new_arr[i][2*n-1] = sign2;
            character_switch++;
        }
        if (character_switch == 2*(n-1)) character_switch = 0;
    }
    for (int i = 2*(n-1); i > 0; i--) {
        if (character_switch < n-1) {
            new_arr[2*n-1][i] = sign1;
            character_switch++;
        } else if (character_switch < 2*(n-1)) {
            new_arr[2*n-1][i] = sign2;
            character_switch++;
        }
        if (character_switch == 2*(n-1)) character_switch = 0;
    }
    for (int i = 2*(n-1); i > 0; i--) {
        if (character_switch < n-1) {
            new_arr[i][0] = sign1;
            character_switch++;
        } else if (character_switch < 2*(n-1)) {
            new_arr[i][0] = sign2;
            character_switch++;
        }
        if (character_switch == 2*(n-1)) character_switch = 0;
    }
    return new_arr;
}

string arr_to_str(char** arr, int n) {
    string text;
    if (n < 0) n = -n;
    for (int i = 0; i < 2*n; i++) {
        for (int j = 0; j < 2*n; j++) {
            text += arr[i][j];
        }
        text += '\n';
    }
    for (int i = 0; i < 2*n; i++) delete [] arr[i];
    delete [] arr;
    return text;
}

int main() {
    int r;
    while (cin >> r) {
        if (r == 0) break;
        char** arr = creating_array(r);
        string text = arr_to_str(arr, r);
        cout << text;
    }
    return 0;
}
