#include <iostream>
#include "Vektoriukstis.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include "studentas.h"
#include <algorithm>

 using std::cin;
using std::cout;
using std::string;

int Default_ND=5;

bool compare_m(studentas & a, studentas & b) {
   return a.galb() > b.galb();

};


void generate (int &kiekis){

string nr = std::to_string(kiekis);
int ND[Default_ND];
std::ofstream out ("kursiokai"+nr+".txt");
std::random_device rd;
std::mt19937 generuoti(rd());
std::uniform_int_distribution < int > random(1, 10);
out<<"Vardas"<<std::setw(20)<<"Pavarde"<<std::setw(17);
for (size_t i = 0; i < Default_ND; i++){
out<<"ND"<<i+1<<std::setw(6);
if(Default_ND-i==1)
out<<"   "<<"Egazminas";
}
out<<std::endl;
for(size_t x = 0; x < kiekis; x++){
out<<"Vardas"<<x<<std::setw(20)<<"Pavarde"<<x<<std::setw(15);

for(size_t y = 0; y < Default_ND + 1; y++){

ND[y]=random(generuoti);
out<<ND[y]<<std::setw(7);
}
out<<std::endl;
}
out.close();

};
void skaityti (Vector <studentas> &x,int &kiekis)
{  
    studentas laikinas_stud;
    auto nr= std::to_string(kiekis);
    string vardas,pavarde;
    Vector <int> ND ;
    int sk;
    int egzaminas;
    std::ifstream in ("kursiokai"+nr+".txt");

    in.ignore(256, '\n');

    while (! in.eof()){
    in>>vardas>>std::ws>>pavarde>>std::ws;
    laikinas_stud.set_vardas(vardas);
    laikinas_stud.set_pavarde(pavarde);

    for(size_t i = 0;i<Default_ND;i++)
    {
        in>>sk;
        ND.push_back(sk);
        laikinas_stud.set_nd(ND);

   }

   in>>egzaminas;
laikinas_stud.set_egzaminas(egzaminas);
laikinas_stud.median();
laikinas_stud.finalinis();
x.push_back(laikinas_stud);
ND.clear();
}

}
void print (Vector <studentas> &printable, string &filename){
    std::ofstream out (filename);
    for(size_t i=0;i<printable.size();i++)
    {
        out<<printable[i].vardas()<<std::setw(20)<<printable[i].pavarde()<<std::setw(20);
        out<<std::fixed<<std::setprecision(2)<<printable[i].galb()<<std::setw(5)<<std::fixed<<std::setprecision(2)<<printable[i].mediana()<<std::endl;
    }
out.close();
}
void print2 (Vector <studentas> &printable){
    cout<<"********************************************************"<<std::endl;
    cout<<"Vardas"<<std::setw(20)<<"Pavardė"<<std::setw(15)<<"Galutinis"<<"    "<<"Mediana"<<std::endl;
    for(size_t i=0;i<printable.size();i++)
    {
        cout<<printable[i].vardas()<<std::setw(20)<<printable[i].pavarde()<<std::setw(20);
        cout<<std::fixed<<std::setprecision(2)<<printable[i].galb()<<std::setw(7)<<std::fixed<<std::setprecision(2)<<printable[i].mediana()<<std::endl;
    }
}
void sortas (Vector <studentas> &x,int &kiekis)
{
    string goodout ="Geriukai.txt";
    string badout  ="Nenaudeliai.txt";


    Vector<studentas> nenaudeliai, geriukai, studentai;
    studentas laikinas;
    string vardas,pavarde;
    double galb,median;
   
    for(size_t i=0;i<kiekis;i++){
    vardas=x[i].vardas();
    pavarde=x[i].pavarde();
    galb=x[i].galb();
    median=x[i].mediana();
    laikinas.set_vardas(vardas);
    laikinas.set_pavarde(pavarde);
    laikinas.set_galb(galb);
    laikinas.set_mediana(median);
    studentai.push_back(laikinas);
    }
    //  sort(studentai.begin(), studentai.end(), compare_m);


       for(size_t i=0;i<kiekis;i++){
           if(studentai[i].galb()<5.0)
           {
               nenaudeliai.push_back(studentai[i]);

           }
           else{
                        geriukai.push_back(studentai[i]);
           }
       }

print(geriukai,goodout);
print(nenaudeliai,badout);
 
}


bool number(const std::string &c)
{
    if (c.find('0') != std::string::npos ||
        c.find('1') != std::string::npos ||
        c.find('2') != std::string::npos ||
        c.find('3') != std::string::npos ||
        c.find('4') != std::string::npos ||
        c.find('5') != std::string::npos ||
        c.find('6') != std::string::npos ||
        c.find('7') != std::string::npos ||
        c.find('8') != std::string::npos ||
        c.find('9') != std::string::npos)
    {
        return true;
    }

    return false;
}
