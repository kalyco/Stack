#include <iostream>
#include <cctype>
#include <cstring>
#include "stack.h"

using namespace std;
char lstr [4] = "([{";

bool rightBracksMatch(stack * stk, char s) {
  char rstr [4] = ")]}";
  string r = rstr;

  if (strchr(rstr, s)) {
    if (stk->isEmpty()) return false;
    size_t idx = r.find(s);
    char mCheck = stk->top();
    if (lstr[idx] == mCheck) stk->pop();  
  }
  return true;
}

bool isBalanced(string& s)
{
  bool result;
  stack * stk = new stack();
  for (int i=0; i < s.length(); i++) {
    if (strchr(lstr, s[i])) stk->push(s[i]);
    if (!rightBracksMatch(stk, s[i])) {
      delete stk;
      return false;
    }  
  } 
  result = stk->isEmpty();
  delete stk;
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
