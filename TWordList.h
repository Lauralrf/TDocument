#ifndef TWORDLIST_H
#define TWORDLIST_H

#include <string>
using namespace std;

class TWordList
{
private:
    string filename;
    int word_num;
    string* pwords;
public:
    TWordList(string f);
    ~TWordList();
    string* getList();
    int getNum();
};

#endif // TWORDLIST_H
