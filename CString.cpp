#include "CString.hpp"
#include<string.h>
#include<iostream>
#include<fstream>

using namespace std;

CString::CString(){
   SetZero();
}
CString::CString(int dlina) {
    str = new char[dlina+1];
    len = dlina;
    strcpy(f_name, "test.txt");
    fstream clear_file(f_name, ios::out);
    clear_file.close();
}
/*CString::CString(const char* FileName, int dlina){
    str = new char[dlina]; int k = strlen(FileName);
    len = dlina;
    for (int i=0; i<k ;i++)
        f_name[i] = FileName[i];
}*/
CString::CString(const char* FileName, const char* new_str){
   // delete str; delete f_name;
    len = strlen(new_str);
    //int k = strlen(FileName);
    str = new char[len+1];
    //f_name = new char[k];
    strcpy(f_name, FileName);
    fstream clear_file(f_name, ios::out);
    clear_file.close();

    strcpy(str, new_str);
}
CString::CString(const CString& s) {
   // delete[] str;
    str = new char[s.len+1];
   // f_name = new char[strlen(s.f_name)];
    len=s.len;
    strcpy(str, s.str);
    strcpy(f_name, s.f_name);
    fstream clear_file(f_name, ios::out);
    clear_file.close();
   // return *this;
}
CString::CString (const char* pstr){
   // f_name = new char[20];
    len = strlen(pstr);
    //delete[] str;
    str = new char[len+1];
    strcpy (str, pstr);
    strcpy(f_name, "test.txt");
    fstream clear_file(f_name, ios::out);
    clear_file.close();
}

void CString::SetZero() {
    len = 0;
    str = new char[1];
    strcpy(f_name, "test.txt");// = new char[20];
    fstream clear_file(f_name, ios::out);
    clear_file.close();
}
CString::CString(const char* FileName, const CString& s) {
    len = s.len;
    str = new char[len+1];
    strcpy(str, s.str);
   // f_name = new char[strlen(FileName)];
    strcpy(f_name, FileName);
    fstream clear_file(f_name, ios::out);
    clear_file.close();
}
CString&  CString::operator = (const CString& s){
    delete[] str;// delete[] f_name;
    len=s.len;
    str = new char[s.len+1];
   // f_name = new char[strlen(s.f_name)];
    strcpy(str, s.str);
    strcpy(f_name, s.f_name);
    return *this;
}

CString::~CString() {
    delete[] str;
    str = NULL;
    len = 0;
    cout<<" ~str"<<endl;
}
