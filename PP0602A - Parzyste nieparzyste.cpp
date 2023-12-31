#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int* arr = new int[n];
        for (int i = 0; i < n; i++) cin >> arr[i];

        int k=0;
        for (int i = 1; i < n; i=i+2) {
            for (int j = i; j > k; j--) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
            k++;
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        delete [] arr;
    }
    return 0;
}
