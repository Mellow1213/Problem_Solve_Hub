#include <iostream>
#include <string>

using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    string ra, rb;
    ra.resize(a.length());
    rb.resize(b.length());
    for(int i=0; i<a.length(); i++){
        ra[i] = a[a.length()-i-1];
    }
    for(int i=0; i<b.length(); i++){
        rb[i] = b[b.length()-i-1];
    }
    cout << (stoi(ra) > stoi(rb) ? ra : rb);
}