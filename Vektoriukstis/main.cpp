#include <iostream>
#include "Vektoriukstis.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include "studentas.h"


using std::cin;
using std::cout;
using std::string;


int main()
{
    Vector <studentas> x; // vektoriai su studentas class'e
    
    string kiekis="-1";
    string option="1";
    
    
    while(option=="1"){

    stoppointoption:
    cout<<std::endl;
    cout<<"Jei norite generuoti studentus įrašykite - 1, jei ne - 2 "<<std::endl;
    cin>>option;

    try{
        if(option!="1")
        {
            throw option;
        }
        
    }
    catch(string option){
        if(option=="2")
     {
      break;
    }
    else
    {
        cout<< "Iveskite tinkamus duomenis "<<std::endl;
        goto stoppointoption;
    }
    }

    stoppointkiekis:
    cout<<"Iveskite generuojamu studentu kiekį"<<std::endl;
    cin>>kiekis;
    try
    {
        if(number(kiekis)==false||std::stoi(kiekis)<=0||std::stoi(kiekis)>=RAND_MAX)
            throw kiekis;
        
    }
    catch(string kiekis){
        cout<<"Iveskite tinkamus kiekio duomenis"<<std::endl;
        goto stoppointkiekis;
    }

    int kiek=std::stoi(kiekis);
    cout<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
generate(kiek);
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; 
std::cout<<kiekis<< " studentu GENERAVIMAS uztruko: "<<std::fixed<<std::setprecision(7)<< diff.count() << " s\n";

  
start = std::chrono::high_resolution_clock::now();
skaityti(x,kiek);
 end = std::chrono::high_resolution_clock::now();
diff = end-start; 
std::cout<<kiekis<< " studentu NUSKAITYMAS uztruko: "<<std::fixed<<std::setprecision(7)<< diff.count() << " s\n";

  
     start = std::chrono::high_resolution_clock::now();
  sortas(x,kiek);
 end = std::chrono::high_resolution_clock::now();
 diff = end-start; 
std::cout<<kiekis<< " studentu RUSIAVIMAS IR SPAUSDINIMAS uztruko: "<<std::fixed<<std::setprecision(7)<< diff.count() << " s\n";

    x.clear();

     }


    x.clear();

    string optionas="1";

while (optionas=="1")  {

stoptaskas:
 std::cout<<"Jei norite įvesti studento duomenis ranka įrašykite - 1, jei ne - 2 "<<std::endl;
 
    cin>>optionas;
    try{
        if(optionas!="1")
        {
            throw optionas;
        }
        
    }
    catch(string optionas){
        if(optionas=="2")
        break;
        else
        {            
        cout<< "Iveskite tinkamus duomenis"<<std::endl;
        goto stoptaskas;

        }
    }

    studentas laikinas;
    string vardas,pavarde;
    int kiekis;
    string kiek;
    Vector <int> ND;
    int egzaminas;


    checkpoint1:
    cout<<"Iveskite studento varda"<<std::endl;
    cin>>vardas;
    try{
        if(number(vardas))
            throw vardas;
        }    
    catch(string vardas)
    {
      cout<< "Iveskite tinkamus duomenis"<<std::endl;
      goto checkpoint1;

    };
    laikinas.set_vardas(vardas);


      checkpoint2:
    cout<<"Iveskite studento pavarde"<<std::endl;
    cin>>pavarde;
    try{
        if(number(pavarde))
            throw pavarde;
        }   
    catch(string pavarde)
    {
      cout<< "Iveskite tinkamus duomenis"<<std::endl;
      goto checkpoint2;

    };
    laikinas.set_pavarde(pavarde);
    

    checkpoint3:
    cout<<"Iveskite studento nd kieki"<<std::endl;
    cin>>kiek;
    try{
        if(number(kiek)==false||std::stoi(kiek)<=0||std::stoi(kiek)>=RAND_MAX)
            throw kiek;

    }
    catch(string kiek)
    {
   cout<< "Iveskite tinkamus duomenis"<<std::endl;
      goto checkpoint3;
    }
kiekis=std::stoi(kiek);

string variantas="1";
stop:
cout<<"Iveskite 1 - generuoti atsitiktinai nd, iveskite  bet ką - jei norite ivesti nd ranka "<<std::endl;
cin>>variantas;
if(variantas=="1"){

    std::random_device rd;
    std::mt19937 generuoti(rd());
    std::uniform_int_distribution < int > random(1, 10);

    for(size_t i = 0;i<kiekis;i++){

    ND.push_back(random(generuoti));
    }

    laikinas.set_nd(ND);
string egz;
    egzaminas1:
    cout<<"Iveskite studento egzamino rezultatus"<<std::endl;
    cin>>egz;
     try{
        if(number(egz)==false||std::stoi(egz)<0||std::stoi(egz)>10)
            throw egz;
        }    
    catch(string egz)
    {
      cout<< "Iveskite tinkamus duomenis"<<std::endl;

      goto egzaminas1;

    };
    egzaminas=std::stoi(egz);
    laikinas.set_egzaminas(egzaminas);

    laikinas.finalinis();
    laikinas.median();

    x.push_back(laikinas);
   }

if(variantas!="1"){
int nd;
string namai;
for(size_t i = 0;i<kiekis;i++){
nd1:
cout<< "Įveskite nd rezultatą"<<std::endl;
cin>>namai;

    try{
        if(number(namai)==false||std::stoi(namai)<0||std::stoi(namai)>10)
            throw namai;
        }    
    catch(string namai)
    {
      cout<< "Iveskite tinkamus duomenis"<<std::endl;
      goto nd1;
      }
      nd=std::stoi(namai);
    ND.push_back(nd);

    }

string egz;
    egzaminas2:
    cout<<"Iveskite studento egzamino rezultatus"<<std::endl;
    cin>>egz;
    try{
        if(number(egz)==false||std::stoi(egz)<0||std::stoi(egz)>10)
            throw egz;
        }    
    catch(string egz)
    {
      cout<< "Iveskite tinkamus duomenis"<<std::endl;

      goto egzaminas2;

    };
    egzaminas=std::stoi(egz);

    laikinas.set_nd(ND);
    laikinas.set_egzaminas(egzaminas);
    laikinas.finalinis();
    laikinas.median();

    x.push_back(laikinas);
}
    ND.clear();
    kiekis=-1;
    egzaminas=-1;

};

if(x.size()==0){
return 0; 
}
else {
print2(x);

}
}
