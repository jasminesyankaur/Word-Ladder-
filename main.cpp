#include "transformation.h"                 //including header

using namespace std;

int main()
{
  transformation object;            //variables needed for function calls
  ifstream in_s;
  set<string> wordlist;
  string worda, wordb;

  object.openFile(in_s, wordlist);    //calling openFile
  object.getWords(worda, wordb, in_s, wordlist); //calling getWords

  cout << endl;
  return 0;
}
