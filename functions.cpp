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
               mass=(CString**)realloc(mass, 2*i*sizeof(CString*));
               /*tmp = mass;
               mass=new CString* [sizemass*2];
               for(int k=0;k<sizemass;k++){
                   mass[k]=tmp[k];
               }*/
               sizemass *= 2;
            }
        }
        in.close();
        cout<<"\n-----------WRITE---------"<<endl;
        //fstream clear_file1("file1", ios::out);
        //clear_file1.close();
        //fstream clear_file2("file2", ios::out);
        //clear_file2.close();

        for(int j=0;j<i;j++){
            cout<<"\nj: "<<j<<"\t"<<mass[j]->f_name<<" "<<mass[j]->len<<" "<<mass[j]->str<<"\t";
            mass[j]->output();
            //delete mass[j];
        }
        cout<<"\n_________________________i: "<<i<<" sizemass: "<<sizemass<<endl;
        for(int j=0; j<i;j++){
            cout<<j<<" "<<mass[j]->str;
            //flush (cout);
            delete mass[j];
            cout<<endl;
        }
        cout<<"\nVOID"<<endl;
        for (int j=i; j<sizemass; j++){
            delete mass[j];
            cout<<j <<" ~ptr"<<endl;
        }
        delete[] mass;
        mass=NULL;
    }

cout<<"\nPlease, check your files"<<endl;
}
#endif
