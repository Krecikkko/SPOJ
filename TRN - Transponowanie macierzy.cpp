#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int** arr = new int*[m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int** transposed_arr = new int*[n];
    for (int i = 0; i < n; i++) {
        transposed_arr[i] = new int[m];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposed_arr[j][i] = arr[i][j];
        }
    }
    
    for (int i = 0; i < m; i++) delete [] arr[i];
    delete [] arr;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << transposed_arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) delete [] transposed_arr[i];
    delete [] transposed_arr;

    return 0;
}
