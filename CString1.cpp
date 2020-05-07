#include "CString1.hpp"
#include <fstream>
#include<iostream>
#include <string.h>
using namespace std;

const CString1 CString1::operator + (const CString &s){
    CString *tmp = new CString1;
    delete[] tmp->str;
    tmp->str = new char[len+s.len];
    strcpy(tmp->str, str);
    strcat(tmp->str, s.str);
    tmp->len = len + s.len;
    return *tmp;
}
int CString1::output() {
    ofstream myfile(this->f_name, ios_base::app);
    if( !myfile.is_open() ) {
        cout<<"Can't open your file"<<this->f_name<<"\n";
        return 1;
    }
    else {
        for(int i=0;i<len;i++){
             myfile<<str[i]<<"\n";
        }
        myfile<<"\n";
        myfile.close();
    }
    return 0;
}

/*
CString1:: ~CString1(){

    delete[] str; str = NULL;
        len = 0;
    cout<<" ~1 "<<endl;
}
*/
