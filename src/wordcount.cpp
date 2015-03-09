/*
 *  Word count program for Insight Data Engineering submission
 *  
 */

/*Header includes*/
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef std::map<string, int> lookuptable; // structure to store words

/*Function to change case of every word*/
char change_case (char c) 
{
    if (std::isupper(c)) 
        return std::tolower(c);
    else  
		return std::tolower(c);
}

/*Function to count number of words*/
void countWords(std::istream &in, lookuptable& words)
{
	std::string str;
	while (in >> str)
	{
		/*List of unwanted characters*/
		char chars[] = "()-,.#";

		for (unsigned int i = 0; i < strlen(chars); ++i)
		{
			/*call to erase unwanted characters*/
			str.erase (std::remove(str.begin(), str.end(), chars[i]), str.end());
			/*call to change case function*/
			std::transform(str.begin(), str.end(), str.begin(), change_case);
		}
		/*increment count for every unique string in Wordmap*/
		++words[str];
	}
} 


int main(int argc, char **argv)
{
    if (argc < 3)
		return (EXIT_FAILURE);
    
    /*Read file from ifstream, input file is given as argument*/
    std::ifstream in(argv[1]);
    
    if (!in)  
		exit(EXIT_FAILURE);
     
     lookuptable wordmap;
     countWords(in, wordmap);
     
     /*open a output file using ofstream*/
     std::ofstream out(argv[2]);
     if (out.is_open())
     {
     /*iterate through word map and print the count*/
     for (lookuptable::iterator i = wordmap.begin();
			i != wordmap.end(); ++i) {
        out << i->first << "\t\t " << i->second << "\n";
      }
     }
     else
        {
		 cout << "Unable to open outputfile";	
         exit(EXIT_FAILURE);
		}
	return 0;
}
