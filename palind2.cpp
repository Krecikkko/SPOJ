#include <iostream>

using namespace std;

int str_len(string text);
bool is_palindrome(string text);

int main() {
    string text;
    int num;

    cin >> num;
    while(num != 0) {
    	cin >> text;
    	
    	if(is_palindrome(text)) {
    		cout << "tak" << endl;
    	} else {
    		cout << "nie" << endl;
    	}
    	num--;
    }
    
    return 0;
}

int str_len(string text) {
    int i;
    while (text[i]) {
        i++;
    }
    return i;
}

bool is_palindrome(string text) {
    int text_len = str_len(text);

    for (int i = 0; i < text_len/2; i++) {
        if (text[i] != text[text_len-i-1]) {
            return false;
        }
    }

    return true;
}
