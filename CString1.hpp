#ifndef CSTRING1_HPP
#define CSTRING1_HPP

#include "CString.hpp"
#include <fstream>
#include <iostream>
using namespace std;

class CString1: public CString
{
public:
    CString1(): CString(){};
    CString1 (int dlina): CString(dlina){};
    CString1 (const char* pstr): CString (pstr){};
    CString1(const char* FileName, const char* new_str): CString(FileName, new_str){};
    CString1(const char* FileName, const CString& s): CString(FileName, s) {};
    CString1(const CString& s): CString(s){};
    virtual ~CString1(){
        std::cout<<" ~1 ";
    }

    const CString1 operator +(const CString &s);
    using CString::operator =;
    int output() override final;
};
#endif


