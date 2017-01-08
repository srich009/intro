// main 

#include <iostream>
#include "arithmeticExpression.h"

using namespace std;

int main()
{ 
    do{
        string expr = "";
        cout << ">>> "; getline(cin, expr);
        arithmeticExpression aex(expr);
        aex.buildTree();
        
        cout << "expression: " << expr << endl;
        cout << "infix: ";   aex.infix();   cout << endl;
        cout << "prefix: ";  aex.prefix();  cout << endl;
        cout << "postfix: "; aex.postfix(); cout << endl;
        // aex.visualizeTree("expr.dot"); // graphviz
        cout << endl;
        
    }while(1);

    return 0;
}
