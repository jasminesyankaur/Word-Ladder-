#include "transformation.h"

using namespace std;

void transformation::openFile(ifstream& in_s, set<string>& wordlist)    //opening file function
{
  char input_file[30];
  string words;

	cout << "Enter the name of the input file: ";
	cin >> input_file;							//storing file name

	in_s.open(input_file);							//opeing input file

	if(in_s.fail())								//if file does not exist a fail message will appear
	{
		cout << "Unable to open input file " << input_file << endl;
		exit(EXIT_FAILURE);
	}

      while (in_s >> words)                 //while fstream variable can read in words from file
      {
        wordlist.insert(words);     //store words into wordList set using insert
      }
}

void transformation::transformWords(string sourceWord, string destinationWord, set<string>& wordlist)   //transform words
{
    queue<string> q;      //cretaing queue of strings
    vector<string> transformation;      //holds final transformation
    set<string> visitedNodes;   //represents visited nodes

    q.push(sourceWord);     //pushing source word into queue

    while(!(q.empty()))     //while q is empty
    {
      string currentWord = q.front();     //set currentWord to the first word in queue
      transformation.push_back(currentWord);    //push current word into the vector

      q.pop();    //pop q

      if(currentWord == destinationWord)    //if words are equal, then output the transformation
      {
        cout << "It is possible to transform " << sourceWord << " to " << destinationWord << ". The transformation is: " << endl;

        for(int i = 0; i < transformation.size(); i++)
        {
          cout << transformation[i] << endl;
        }
      }
      else    //else
      {
        string temp;      //holds temp compare word
        int count = 0;      //set counter = 0
        int size = currentWord.length();    //size = word length

        set<string>::iterator it;
        for(it = wordlist.begin(); it != wordlist.end(); ++it)      //itertate through dictionary
        {
          temp = *it;       //assign temp to current word
          if(temp.length() == currentWord.length())       //if the words match
          {
            for (int i = 0; i < size; i++)      //run for size
            {
              if(currentWord[i] != temp[i])       //incrament counter if the letters dont match
              {
                count++;
              }
             }
            if(count == (size -1))    //if count is == to 1 then push word into q and visited nodes set
            {
              if(!visitedNodes.count(temp))
              {
                q.push(temp);
              }
            }
          }
          visitedNodes.insert(temp);
          int count = 0;
        }
      }
    }
}


void transformation::getWords(string& sourceWord, string& destinationWord, ifstream& in_s, set<string>& wordlist)
{
  cout << "Enter source word: ";            //asking user to enter source word
  cin >> sourceWord;

  cout << "Enter destination word (same length): ";     //asking user to enter destination word
  cin >> destinationWord;

  if(sourceWord.length() == destinationWord.length())     //if lengths are the same
  {
    transformWords(sourceWord, destinationWord, wordlist);    //then call transform function
  }
  else
  {
    cout << "Words are of different in length, it is not possible to transform " << sourceWord << " to " << destinationWord << endl;    //else output cant transform
  }
}
