#include "tpaper.h"
#include <fstream>
#include <strstream>
using namespace std;

TPaper::TPaper(string f,int word_num)
{
    filename = f;
    title = "";
    paper ="";
    vect = new int[word_num];
    for (int i=0;i<word_num;i++)
        vect[i]=0;

    titleVec = new int[word_num];
    for (int i=0;i<word_num;i++)
        titleVec[i]=0;
}
TPaper::~TPaper()
{
    delete []vect;
    delete []titleVec;
//	cout<<"~~~TPaper"<<endl;
}
int* TPaper::getTitleVec()
{
    return titleVec;
}
int* TPaper::getVect()
{
    return vect;
}
void TPaper::doc2vec(int word_num, string* pword)
{
    ifstream infile(filename);
    char t[80];
    infile.getline(t, 80);
    title = t;
    istrstream stitle(t);

    string s;
    while (stitle>>s)
    {
        int i = 0;
        while (i<word_num)
        {
            if (s==pword[i])
            {
                titleVec[i]++;
                break;
            }
            i++;
        }
    }

    while (infile>>s)
    {
        paper += ' ';
        paper += s;
        int i = 0;
        while (i<word_num)
        {
            if (s==pword[i])
            {
                vect[i]++;
                break;
            }
            i++;
        }
    }
}
string TPaper::getTitle()
{
    return title;
}
string TPaper::getPaper()
{
    return paper;
}
