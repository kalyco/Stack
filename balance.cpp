#include <iostream>
#include <cctype>
#include <cstring>
#include "stack.h"

using namespace std;

const string& RIGHTIES = "}])";

bool isBalanced(string& s)
{
  stack * stk = new stack();
  char *cstr = new char[3];
  strcpy(cstr, "{[(");

  for (int i=0; i < s.length(); i++) {
   if (strchr(cstr, s[i])) {
    stk->push(s[i]);
   }
   
  }

  delete[] cstr;
  return false;
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
