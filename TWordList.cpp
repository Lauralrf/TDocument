#include "TWordList.h"
#include <string.h>
#include <fstream>
using namespace std;

TWordList::TWordList(string f)
{
    word_num = 0;
    filename = f;

    string s;
    ifstream ifile (filename);
    while (ifile>>s)
        word_num++;

    pwords = new string[word_num];
    ifile.clear();
    ifile.seekg(0,ios::beg);
    int i=0;
    while (ifile>>s)
    {
        pwords[i] = s;
        i++;
    }
}
TWordList::~TWordList()
{
    delete []pwords;
}
string* TWordList::getList()
{
    return pwords;
}
int TWordList::getNum()
{
    return word_num;
}

