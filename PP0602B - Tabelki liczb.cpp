#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l,k;
        cin >> l >> k;

        int** arr = new int*[l];
        for (int i = 0; i < l; i++) arr[i] = new int[k];
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < k; j++) {
                cin >> arr[i][j];
            }
        }

        int temp = arr[0][0];
        for (int i = 0; i < k-1; i++) {
            arr[0][i] = arr[0][i+1];
        }
        for (int i = 0; i < l-1; i++) {
            arr[i][k-1] = arr[i+1][k-1];
        }
        for (int i = k-1; i > 0; i--) {
            arr[l-1][i] = arr[l-1][i-1];
        }
        for (int i = l-1; i > 0; i--) {
            arr[i][0] = arr[i-1][0];
        }
        arr[1][0] = temp;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < k; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        for(int i = 0; i < l; i++) delete [] arr[i];
        delete [] arr;
    }
    return 0;
}
