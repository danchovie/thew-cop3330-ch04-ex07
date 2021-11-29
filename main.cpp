/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Daniel Thew
 */
#include <iostream>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;
//function to convert a character to an int
//found online
#define charToInt(c) (c-'0')
//function to get digit from a string with a written digit
int getDigit(string dig);
//function to get the result from an operation of two digits
double getResult(char o, int dig1, int dig2);
//function to print the proper output of an operation
void printResult(char o, int dig1, int dig2, double res);

int main() {
  //ints to hold eventual digits after comversion from strings
  int dig1, dig2;
  //double to hold result of operations
  //integer division can't even yield a decimal so this is kinda pointless
  double result;
  //single char for the operation (+,-,*,/)
  char operation;
  //strings for user-inputted digits (numerical or written)
  string user_1, user_2;
  //get user input for digits and operator
  cin>>user_1;
  cin>>user_2;
  cin>>operation;
  //if the first character of the user's first string is a digit
  //then we just convert that char into a digit and store in dig1
  if(isdigit(user_1[0])){
    dig1 = charToInt(user_1[0]);
  }
  //else, we store the result of the getDigit function in dig1
  else{
    dig1 = getDigit(user_1);
    if(dig1==-1){
      cout<<"Error.\n";
      exit(0);
    }
  }
  //repeat above process for dig2
  if(isdigit(user_2[0])){
    dig2 = charToInt(user_2[0]);
  }
  else{
    dig2 = getDigit(user_2);
    if(dig2==-1){
      cout<<"Error.\n";
      exit(0);
    }
  }
  //result is the...result of getResult
  result = getResult(operation, dig1, dig2);
  //if operation is bogus char
  if(result==1000){
    cout<<"Error.\n";
    exit(0);
  }
  //print result's string
  printResult(operation, dig1, dig2, result);
}

int getDigit(string dig){
  //array for all 10 digits in string form
  //assumign lowercase, i guess
  char digits[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  //for the length of the digit array, check if the user string
  //matches any of the digits, return the int i where it does.
  //return -1 for an error.
  for(int i = 0; i < 10; i++){
    if(dig==digits[i]){
      return i;
    }
  }
  return -1;
}

double getResult(char o, int dig1, int dig2){
  //check operation, return result
  if(o=='+'){
    return dig1+dig2;
  }
  else if(o=='-'){
    return dig1-dig2;
  }
  else if(o=='*'){
    return dig1*dig2;
  }
  else if(o=='/'){
    return dig1/dig2;
  }
  //just in case the user char is bogus
  else{
    return 1000;
  }
}

void printResult(char o, int dig1, int dig2, double res){
  //similar to the getResult function, but prints the proper string
  //this could have probably been a part of getResult, but
  //the code is small enough that it shouldn't matter too much.
  if(o=='+'){
    cout<<"The sum of "<<dig1<<" and "<<dig2<<" is "<<res<<".\n";
  }
  else if(o=='-'){
    cout<<"The difference between "<<dig1<<" and "<<dig2<<" is "<<res<<".\n";
  }
  else if(o=='*'){
    cout<<"The product of "<<dig1<<" and "<<dig2<<" is "<<res<<".\n";
  }
  else if(o=='/'){
    cout<<"The quotient of "<<dig1<<" and "<<dig2<<" is "<<res<<".\n";
  }
  else{
    cout<<"Error.\n";
  }
}