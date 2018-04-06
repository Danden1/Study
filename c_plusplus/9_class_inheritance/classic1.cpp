#include <iostream>
#include <cstring>
#include "classic1.h"
using namespace std;

Cd::Cd(const Cd &d){

  performers = new char[strlen(d.performers) +1];
  strcpy(performers, d.performers);
  
  label = new char[strlen(d.label) +1];
  strcpy(labe, d.label);
  
  selections = d.selections;
  playtime = d.playtime;
}

Cd::Cd(char *s1, char *s2, int n, double x){

  performers = new char[strlen(s1)+1];
  strcpy(performers, s1);
  
  label = new char[strlen(s2)+1];
  strcpy(label, s2);
  
  selections = n;
  playtime = x;
}

Cd::~Cd(){
  delete [] performers;
  delete [] label;
}

void Cd::Report() const{
  cout << "Performers: " << performers << endl;
  cout << "label : " << label << endl;
  cout << selections << selections << endl;
  cout << "playtime" << playtime << endl;
}

Cd &Cd::operator=(const Cd &d){
  if(this == &d)
    return *this;
  
  delete [] performers;
  delete [] label;
  
  performers = new char[strlen(d.performers)+1];
  label = new char[strlen(d.label)+1];
  
  strcpy(performers, d.performers);
  strcpy(label, d.label);
  
  selections = d.selections;
  playtime = d.playtime;
  
  return *this;
  
}



Classic::Classic(char *primary, char *s1, char *s2, int n, double x) : Cd(s1,s2,n,x){
  represent = new char[strlen(primary) +1];
  strcpy(represent, primary);
}

Classic::Classic(const Cd &d, char *primary) : Cd(d){
  represent = new char[strlen(primary)+1];
  strcpy(represent, primary);
}

Classic::Classic(const Classic &x) : Cd(x){
  represent = new char[strlen(x.represent+1];
  strpcy(represent, x.represent);
}

void Classic::Report() const{
  cout << "represent : " << represent << endl;
  Cd::Report();
}

Classic &Classic::operator=(const Classic &x){
  if(this == &x)
    return *this;
    
    delete [] represent;
    Cd::operator=(x);
    
    represent = new char[strlen(x.represent) +1];
    strcpy(represent, x.represent);
    
    return *this;
    
}
