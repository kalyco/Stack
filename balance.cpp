#include <iostream>
#include <cctype>
#include <cstring>
#include "stack.h"
#include <unordered_map>
#include "sll.h"

using namespace std;

SLinkedList pushLeftBracesOnStack(stack * stk, string& str) {
  char *lstr = new char[3];
  strcpy(lstr, "{[(");
  SLinkedList * bList = new SLinkedList();
  for (int i=0; i < str.length(); i++) {
   if (strchr(lstr, str[i])) {
    stk->push(str[i]);
    bList->addFront(str[i]);
   }
  }
  delete[] lstr;
  return *bList;
}

bool balanceCheck(stack * stk, string& str, SLinkedList bList) {
  // Create a key-val map to check matches
  unordered_map<char, char> mMatch;
  mMatch.insert("}", "{");
  mMatch.insert("]", "[");
  mMatch.insert(")", "(");
  char *rstr = new char[3];
  strcpy(rstr, ")]}");

  for(int i=0; i < str.length(); i++) {
    if (strchr(rstr, str[i])) {
      char mCheck = stk->top();
      if (str[i] == mCheck) {
        stk->pop();
      }
      else {
        return false;
      } 
    }
  }
  delete[] rstr;
  return true;
}  

bool isBalanced(string& s)
{
  bool result;
  stack * stk = new stack();

  SLinkedList bList = pushLeftBracesOnStack(stk, s);
  if (!stk->isEmpty()) {
    result = balanceCheck(stk, s, bList);
  } else {
    result = true;
  }
  return result;
}

int main()
{
  string expr;
  while (true) {
    getline(cin, expr);
    if (expr == ".") break;
    if (isBalanced(expr)) {
      cout << "BALANCED" << endl;
    } else {	
      cout << "NOT BALANCED" << endl;
    }
  }
  return 0;
}
