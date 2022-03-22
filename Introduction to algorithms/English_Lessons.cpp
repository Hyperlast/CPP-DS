#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
//implementation of strlen
int my_strlen(std::string word)
{
    int i=0;
    while(word[i]!='\0')
    {
        ++i;
    }
    
    return i;
}
//algorithm for letter counting in a word
int CountLetterInWord(std::string word,char letter)
{
    int counter=0;
    for(int i=0;i<my_strlen(word);++i)
    {
        if(letter==word[i])
        {
            counter++;
        }
    }
    return counter;
}

int main() {
    
    std::string word;
    int NumberOfLetters;
    char letter;
    
    std::cin>>word;
    //validation
    if( (my_strlen(word)<1) || (my_strlen(word)>100))
    {
        return -1;
    }
    
    std::cin>>NumberOfLetters;
    //validation
    if(NumberOfLetters<1 || NumberOfLetters>pow(10,9))
    {
        return -1;
    }
    
    std::cin>>letter;
    
    //algorithm
    
    //SDA
    //11
    //D
    // S D A S D A S D A S  D  A  
    // 1 2 3 4 5 6 7 8 9 10 11 12 
    //COUNTER FOR LETTERS IN WORD  
    int Var_modulus = ( NumberOfLetters % ( my_strlen(word) ) ); //number of bonus letters after all are written
    int Var_divide = ( NumberOfLetters / ( my_strlen(word) ) ); //number of times you can replicate the word
    int Result = 0; // Number of letters in the whole thing
    
    Result+=(Var_divide*(CountLetterInWord(word,letter)));
    for(int i=0;i<Var_modulus;++i)
    {
        if(word[i]==letter)
        {
            Result++;
        }
    }
    
    std::cout<<Result;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}