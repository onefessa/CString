#ifndef FUNCTIONS
#define FUNCTIONS

#include <string.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"
#include "functions.hpp"
using namespace std;

void scan(const char *input_file){
    int mode; int sizemass = 2; int i=0; //CString** tmp;
    char out_name[80]; string CURR;

    CString** mass = new CString* [sizemass];

    ifstream in; in.open(input_file);
    if( !in.is_open() )
        cout<<"Can't open your file "<<input_file;
    else{
        cout<<"\nopen "<<input_file<<"\t\n_________________________\n"<<endl;
        while(in>>mode){
            in>>out_name;
            in>>CURR; char *curr = (char*)CURR.c_str();
            if(mode==0){
                cout<<i<<" Read 0 ";
                CString* tmp = new CString0(out_name, curr);
                mass[i] = tmp;
                cout<<mass[i]->f_name<<": "<<mass[i]->str<<"\t"<<mass[i]->len<<endl; i++;
            }
            else if (mode==1){
                cout<<i<<" Read 1 ";
                CString* tmp = new CString1(out_name, curr);
                mass[i] = tmp;
                cout<<mass[i]->f_name<<": "<<mass[i]->str<<"\t"<<mass[i]->len<<endl; i++;
            }
            if(i==sizemass){
               CString** tmp_ = new CString* [sizemass];
               for(int k=0;k<sizemass;k++){
                   tmp_[k] = mass[k];
               }
               delete[] mass;
               mass = new CString* [sizemass*2];
               for(int k=0;k<sizemass;k++){
                   mass[k]=tmp_[k];
               }
               delete[] tmp_;
               tmp_ = NULL;
               sizemass *= 2;
            }
        }
        in.close();
        cout<<"\n-----------WRITE---------"<<endl;
        for(int j=0;j<i;j++){
            cout<<"\nj: "<<j<<"\t"<<mass[j]->f_name<<" "<<mass[j]->len<<" "<<mass[j]->str<<"\t";
            mass[j]->output();
            //delete mass[j];
        }
        cout<<"\n_________________________i: "<<i<<" sizemass: "<<sizemass<<endl;
        for(int j=0; j<i;j++){
            cout<<j<<" "<<mass[j]->str;
            delete mass[j];
        }
        cout<<"\nVOID";
        delete[] mass; cout<<" ~ptr"<<endl;
        //for (int j=i; j<sizemass; j++){ delete mass[j]; cout<<j <<" ~ptr"<<endl; }
        //delete[] mass;
        mass=NULL;
    }

cout<<"\nPlease, check your files"<<endl;
}
#endif
