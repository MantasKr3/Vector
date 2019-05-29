#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include "Vektoriukstis.h"
#include <algorithm>

using std::string;
class person
{
protected:
  std::string vardas_;
  std::string pavarde_;

public:
  virtual void set_vardas(std::string vardas) { vardas_ = vardas; }
  virtual void set_pavarde(std::string pavarde) { pavarde_ = pavarde; }
  std::string vardas() const { return vardas_; }
  std::string pavarde() const { return pavarde_; }
};
class studentas : public person
{
private:
Vector <int> nd_;
int egzaminas_;
double mediana_;
double galb_;

public:
//***rule of three
studentas(){};//construtor'ius
~studentas(){};//destructor'ius
studentas(const studentas &stud) //obj copy asg
  {
    vardas_ = stud.vardas_;
    pavarde_ = stud.pavarde_;
    nd_ = stud.nd_;
    egzaminas_=stud.egzaminas_;
    mediana_ = stud.mediana_;
    galb_ = stud.galb_;
  }
  //***rule of three
//getters
Vector<int> nd() const {return nd_;}
double mediana() const {return mediana_;}
double galb() const {return galb_;}
//setters
void set_nd(Vector<int> nd) {nd_ = nd;}
void set_egzaminas(int egzaminas) {egzaminas_ = egzaminas;}
void set_mediana(double mediana) {mediana_ = mediana;}
void set_galb(double galb) {galb_ = galb;}

void median();
void finalinis();

studentas operator=(studentas other)
  {
    std::swap(vardas_, other.vardas_);
    std::swap(pavarde_, other.pavarde_);
    std::swap(nd_, other.nd_);
    std::swap(egzaminas_, other.egzaminas_);
    std::swap(mediana_, other.mediana_);
    std::swap(galb_, other.galb_);
    return *this;

  }

  friend std::ostream& operator<<(std::ostream& out, const studentas &stud) {
      out << stud.vardas_ << " " << stud.pavarde_ << " " << stud.galb_ << "\n";
      return out;
    };
    friend std::istream& operator>>(std::istream& in, studentas &stud) {
      in >> stud.vardas_ >> stud.pavarde_ >> stud.galb_;
    }

  friend bool operator!=(studentas a, studentas b)
  {
    return !(a == b);
  }
  friend bool operator==(studentas a,studentas b)
  {
    return a == b;
  }
};
  

void generate(int &kiekis);
void skaityti (Vector <studentas> &x,int &kiekis);
void sortas(Vector <studentas> &x,int &kiekis);
void print2(Vector <studentas> &printable);
bool number(string const& c);



#endif
