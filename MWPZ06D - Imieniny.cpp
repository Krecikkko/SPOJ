#include <iostream>

using namespace std;

int main()
{
    long long int D,L,C;
    cin>>D;
    while (D--) {
        cin>>L>>C;
        if (C==0||L==0) cout<<"NIE"<<endl;
        else if (L==1) cout<<"TAK"<<endl;
        else if(C%(L-1)==0) cout<<"NIE"<<endl;
        else cout<< "TAK"<<endl;
    }
    return 0;
}
