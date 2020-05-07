#ifndef CSTRING_H
#define CSTRING_H

class CString
{
public:
    char* str;
    int len;
    char f_name[80];

    CString();
    CString(int dlina);
    CString (const char* pstr);
    //CString(const char* FileName, int dlina = 1);
    CString(const char* FileName, const char* new_str);
    CString(const CString& s);
    CString(const char* FileName, const CString& s);
    virtual ~CString();

    void SetZero();
    CString&  operator = (const CString& s);
    virtual int output() = 0;
};
#endif


