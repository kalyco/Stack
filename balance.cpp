// char::find
#include <iostream>
#include <cctype>
#include <cstring>
#include "stack.h"
#include <map>

using namespace std;

void checkLeftBracks(stack * stk, char s) {
  char *lstr = new char[3];
  strcpy(lstr, "([{");

  if (strchr(lstr, s)) {
    stk->push(s);
   }
  delete[] lstr;
}

char getLeftMatch(int i) {
  char *lstr = new char[3];
  strcpy(lstr, "([{");
  
  char l = lstr[i];
  delete[] lstr;
  return l;
}

bool rightBracksMatch(stack * stk, char s) {
  char *rstr = new char[3];
  strcpy(rstr, ")]}");
  string r = rstr;

  if (strchr(rstr, s)) {
    if (stk->isEmpty()) return false;
    size_t idx = r.find(s);
    char lVal = getLeftMatch(idx);
    char mCheck = stk->top();
    if (lVal == mCheck) stk->pop();  
  }
  delete[] rstr;
  return true;
}

bool isBalanced(string& s)
{
  stack * stk = new stack();
  for (int i=0; i < s.length(); i++) {
    checkLeftBracks(stk, s[i]);
    if (!rightBracksMatch(stk, s[i])) {
      return false;
    }  
  }  
  if (!stk->isEmpty()) {
    return false;
  } else {
    return true;
  }
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
