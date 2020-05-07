#ifndef AUTOTEST
#define AUTOTEST

#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"
#include <string.h>
#include <iostream>
#include <fstream>
//using namespace std;

void autotest(){
std::cout<<"Test 0: ";

    int c=0;
    char r[4]; char R[4];// strcpy(r, "one"); cout<<r<<endl;
    char a[2]; strcpy(a, "o"); //cout<<a<<endl; //cout << sizeof(a) << " ?= " << strlen(a) << endl;
    char b[3]; strcpy(b, "ne"); //cout<<b<<endl;
    CString0 m (a);  //cout<< m.str<<" is_A "<<a<<endl;
    CString0 n (b);  //cout<< n.str<<" is_B "<<b<<endl;
    CString0 k; //cout<< k.str<<" is_K"<<endl;
    strcpy(r, "one"); //cout<<r<<endl;
    k = m + n;  //cout<< k.str<<" is_K+ "<<r<<endl;
    for(int i=0;i<4;i++){
        if(!(k.str[i]==r[i])){
            std::cout << "\n"<<k.str[i]<< " != "<<r[i]<<std::endl;
            c++;
        }
    }
    //delete[] r; //r = NULL;
    if(c==0) std::cout<<"Ok"<<std::endl;
    else std::cout<<"Failed"<<std::endl;

std::cout<<"Test 1: ";
    CString1 q (a);
    CString1 w (b);
    CString1 z;
    z = q+w;
    c=0;
    strcpy(R, "one");
    for(int i=0;i<4;i++){
        if(!(z.str[i]==R[i])){
            std::cout << z.str[i]<< " != "<<R[i]<<std::endl;
            c++;
        }
    }
    if(c==0) std::cout<<"Ok"<<std::endl;
    else std::cout<<"Failed"<<std::endl;

std::cout<<"Test 2: ";
    CString0 e(2); CString1 E(8);
    if ((e.len == 2)&&(E.len == 8)) std::cout<<"Ok"<<std::endl;
    else std::cout<<"Failed"<<std::endl;

std::cout<<"Test 3: ";
    fstream clear_file("test.txt", ios::out);
    clear_file.close();
    string CURR = "test.txt"; char *Filename = (char*)CURR.c_str();
    strcpy(a, "o");
    CString0 x_(a); strcpy(x_.f_name, "test.txt");
                    //cout<<"\nx_\t"<<strlen(x_.f_name)<<" "<<x_.f_name<<strlen(x_.str)<<" "<<x_.str<<endl;
    CString1 X_(a); strcpy(X_.f_name, Filename);
                    //cout<<"X_\t"<<strlen(X_.f_name)<<" "<<X_.f_name<<strlen(X_.str)<<" "<<X_.str<<endl;
    CString0 x(Filename, b);
                    //cout<<"x\t"<<strlen(x.f_name)<<" "<<x.f_name<<strlen(x.str)<<" "<<x.str<<endl;
    CString1 X(Filename, "two");
                    //cout<<"X\t"<<strlen(X.f_name)<<" "<<X.f_name<<strlen(X.str)<<" "<<X.str<<endl;
    CString0 x1("test.txt", a);
                    //cout<<"x1\t"<<strlen(x1.f_name)<<" "<<x1.f_name<<strlen(x1.str)<<" "<<x1.str<<endl;
    if ((strcmp(x_.f_name, "test.txt")==0)&&(strcmp(x_.str, "o")==0)
        &&(strcmp(X_.f_name, "test.txt")==0)&&(strcmp(X_.str, "o")==0)
        &&(strcmp(x.f_name, "test.txt")==0)&&(strcmp(x.str, "ne")==0)
        &&(strcmp(X.f_name, "test.txt")==0)&&(strcmp(X.str, "two")==0)
        &&(strcmp(x1.f_name, "test.txt")==0)&&(strcmp(x1.str, "o")==0))
            std::cout<<"Ok"<<std::endl;
    else std::cout<<"Failed"<<std::endl;

std::cout<<"Test 4: ";
  //  cout<<"x\t"<<strlen(x.f_name)<<" "<<x.f_name<<" "<<strlen(x.str)<<" "<<x.str<<endl;
    CString0 f1(x);// cout<<f1.f_name<<" (=test.txt) :  "<<f1.str<<" (=ne)"<<endl;
    if ((strcmp(f1.f_name, "test.txt")==0)&&(strcmp(f1.str, "ne")==0))
         std::cout<<"Ok"<<std::endl;
    else std::cout<<"Failed"<<std::endl;

std::cout<<"Test 5: ";
    CString1 k1("three");
    CString1 K("t1.txt", k1); //cout<<"\n"<<K.f_name<<" (=t1.txt) :  "<<K.str<<" (=three)"<<endl;
    if ((strcmp(K.f_name, "t1.txt")==0)&&(strcmp(K.str, "three")==0))
         std::cout<<"Ok"<<std::endl;
    else std::cout<<"Failed"<<std::endl;

    k.output();
    z.output();

    x_.output();
    x.output();
    X_.output();
    X.output();
    x.output();

std::cout<<"Tests FINISHED !"<<std::endl;
}
#endif
