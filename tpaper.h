#ifndef TPAPER_H
#define TPAPER_H

#include <string>
using namespace std;

class TPaper
{
private:
    string filename;
    string title;
    string paper;
    int* vect;
    int * titleVec;
public:
    TPaper(string f,int word_num);
    ~TPaper();
    void doc2vec(int word_num, string* pword);
    int* getTitleVec();
    int* getVect();
    string getTitle();
    string getPaper();
};


#endif // TPAPER_H
