#include <bits/stdc++.h>
using namespace std;

class Kandungan{
    protected:
        string makanan;
        string jenis;
        int gula;
        int karbo;
        int kalori;
    public:
        Kandungan(){
            makanan = jenis = "";
            gula = karbo = kalori = 0;
        }
        void setKandungan(string m, string j, int g, int k){
            makanan = m;
            jenis = j;
            gula = g;
            karbo = k;
        }
        int getKalo(){
            return kalori;
        }
        string getJenis(){
            return jenis;
        }
        void cekKal(int total){
            if(total > 1000) cout << makanan << endl;
        }
        void print(){
            cout << makanan << endl;
        }
};

class Kalori: public Kandungan{
    private:
        int A = 50;
        int B = 20;
    public:
        void cekKal(){
            kalori = A * gula + B * karbo;
        }
};

class Nutrisi: public Kandungan{
    private:
        int A = 20;
        int B = 10;
    public:
        void cekNut(){
            kalori = A * gula + B * karbo;
        }
};

int main(){
    string m, j;
    int n, g, k, total = 0;
    cin >> n;
    Kalori* kandungan = new Kalori[n];
    Nutrisi* kandunganN = new Nutrisi[n];
    for(int i=0; i<n; i++){
        cin >> m >> j >> g >> k;
        if(j == "Kalori"){
            kandungan[i].setKandungan(m, j, g, k);
            kandungan[i].cekKal();
            total+=kandungan[i].getKalo();
        } else{
            kandunganN[i].setKandungan(m, j, g, k);
            kandunganN[i].cekNut();
            total+=kandunganN[i].getKalo();
        }
    }

    cout << total << endl;
    for(int i=0; i<n; i++){
        if(kandungan[i].getKalo() > 1000)
            kandungan[i].print();
        else if(kandunganN[i].getKalo() > 1000)
            kandunganN[i].print();
    }
}
