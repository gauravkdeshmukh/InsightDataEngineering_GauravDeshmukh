/*Header includes*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <vector>
int wordscount (std::string sentence)
{
    int number_of_words = 1;
    for(unsigned int i = 0; i < sentence.length();i++)
    {
        if(sentence[i] == ' ')
            number_of_words++;
    }
    return number_of_words;
} 

int main( int argc , char** argv ) {
   int linecount = 0 ;
   float total = 0;
   float median = 0;
   std::string line;
   std::ifstream infile(argv[ 1 ]);
   if ( infile ) {
      while ( getline( infile , line)) {
	 linecount++ ;
	 total += wordscount(line);
	 median = total/linecount;
	 if(median < ((floorf(median)+ceil(median))/2))
	    median = floorf(median);
	 std::ofstream out;
	 out.open (argv[2], std::ofstream::out | std::ofstream::app);
     if (out.is_open())
     {
	  out<< median <<"\n";
	 }
	 out.close();
   }
   infile.close();
   return 0 ;
  }
}
