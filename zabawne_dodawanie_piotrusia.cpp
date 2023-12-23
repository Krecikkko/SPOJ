#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int num_org=n,num_rev=0,how_many_iterations=0;

        while (num_org != num_rev) {
            num_rev=0;
            do {
                num_rev *= 10;
                num_rev += (n%10);
            } while (n /= 10);

            if (num_org == num_rev) {
                break;
            }
            num_org += num_rev;
            n = num_org;
            how_many_iterations++;
        }
        cout << num_org << " " << how_many_iterations << endl;
    }
    return 0;
}
