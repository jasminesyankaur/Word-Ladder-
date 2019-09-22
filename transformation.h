#include <iostream>
#include <fstream>
#include<cstdlib>
#include <string>                     //including all the necessary directories to make program work
#include <stack>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class transformation              //transformation class
{
  public:
    void openFile(ifstream& in_s, set<string>& wordlist);       //opens file
    void transformWords(string sourceWord, string destinationWord, set<string>& wordlist);    //transforms word A to word B
    void getWords(string& sourceWord, string& destinationWord, ifstream& in_s, set<string>& wordlist);      //asks user to input words
};
