#include "CString0.hpp"
#include <fstream>
#include<iostream>
#include <string.h>
using namespace std;

const CString0 CString0::operator + (const CString &s){
    CString *tmp = new CString0;
    delete[] tmp->str;
    tmp->str = new char[len+s.len];
    strcpy(tmp->str, str);
    strcat(tmp->str, s.str);
    tmp->len = len + s.len;
    //str = new char [len+1];
    //strcpy(str, tmp);
    //delete[] tmp; tmp = NULL;
    return *tmp;
}
/*
CString0& CString0::operator = (const CString0 &s){
    str = s.str;
    return *this;
}*/
int CString0::output() {
    ofstream myfile(this->f_name, ios_base::app);
    if( !myfile.is_open() ) {
        cout<<"Can't open your file"<<this->f_name<<endl;
        return 1;
    }
    else {
        for(int i=0;i<len;i++){ //arr[i].outp();
             myfile<<str[i];
        }
        myfile<<"\n\n";
        myfile.close();
    }
return 0;
}

/*CString0:: ~CString0(){

    delete[] str;
    str = NULL;    len = 0;
    cout<<" ~0 "<<endl;
}
*/
