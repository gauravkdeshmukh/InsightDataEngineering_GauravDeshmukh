#!/usr/bin/env bash

# example of the run script for running the word count

# first I'll load all my dependencies
apt-get install g++

# next I'll comiple the program and make excutable 
g++ -c ./src/wordcount.cpp 
g++ -o Wordcount ./src/wordcount.cpp  

# next I'll make sure that all my programs (written in Python in this example) have the proper permissions
chmod +x Wordcount

# finally I'll execute my programs, with the input directory wc_input and output the files in the directory wc_output
./Wordcount ./wc_input/test.txt ./wc_output/wc_result.txt
#python my_running_median.py ./wc_input ./wc_output/med_result.txt



