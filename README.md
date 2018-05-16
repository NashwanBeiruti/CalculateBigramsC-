# CalcBigrams


A program to calculate bigram probabilities from a corpus.


file called calc bigrams.cpp main function takes the name of a file as a command
line argument. Then calls a function to calculate bigram probabilities for every pair of words in the file.



two maps: one to keep track of how many times each pair of words occurs (for the numerator
in (1)) and one to keep track of how many times each word occurs (for the denominator).
The map has been populated with probabilities for every pair of words in the input file, the program
prompts the user to input a pair of words. Program should than output the probability of that
pair of words. It should continue prompting until the user enters “q”.