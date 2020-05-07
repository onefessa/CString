#ifndef CSTRING0_HPP
#define CSTRING0_HPP

#include "CString.hpp"
#include<iostream>
#include"fstream"
#include <iostream>

class CString0: public CString
{
public:
    CString0(): CString(){};
    CString0 (int dlina): CString(dlina){};
    CString0 (const char* pstr): CString (pstr){};
    CString0(const char* FileName, const char* new_str): CString(FileName, new_str){};
    CString0(const char* FileName, const CString& s): CString(FileName, s) {};
    CString0(const CString& s):CString(s){};
    //CString0(const char* FileName, int k): CString(FileName, k){};
     virtual ~CString0(){
        std::cout<<" ~0 ";
    }
    const CString0 operator +(const CString &s);
    using CString::operator =;
    int output() override final;
};
#endif


