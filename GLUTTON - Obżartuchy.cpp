#include <iostream>

using namespace std;

int main() {
    const int day_in_sec = 86400;
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin >> N >> M;
        // liczba obżartuchów >> liczba ciastek w pudełku
        int* eating_time = new int[N];
        for(int i = 0; i < N; i++) {
            cin >> eating_time[i];
        }

        int number_of_cookies = 0;
        for (int i = 0; i < N; i++) {
            number_of_cookies += (day_in_sec / eating_time[i]);
        }
        delete [] eating_time;

        int number_of_packages = number_of_cookies / M;
        if (number_of_packages * M < number_of_cookies) number_of_packages++;

        cout << number_of_packages << endl;
    }
    return 0;
}
