#include<iostream>
#include<string>

using namespace std;

const int MAX = 2e6+7;
int ps[MAX];//tablica strzalek
int dop=0;
string w, s;
int kr, N, N1;
int wynik;

void KMP(string w){
    N = w.size();
    ps[1] = 0;
    for(int i = 2; i < N; i++){
        kr = ps[i-1]; //
        while(kr > 0 && w[i] != w[kr+1]) //
            kr=ps[kr];
        if(w[i] == w[kr+1])
            kr++;
        ps[i] = kr; //
    }
}

int znajdz(string s)
{
    dop = 0;
    for(int i = 1; i < s.size(); i++){
        while(dop>0 && s[i] != w[dop+1]){
            dop = ps[dop];
        }
        if(s[i] == w[dop+1])
            dop++;
        if(dop == w.size()-1){
            wynik++;
            dop = ps[dop];
        }
    }
    return wynik;
}

void read()
{
    cin >> w >> s;
    s="&"+s;
    w="$"+w;
}

void out()
{
    cout << znajdz(s);
}

int main()
{
    read();
    KMP(w);
    out();
    return 0;
}