// main test harness lab 5

#include <iostream>
#include "arithmeticExpression.h"

using namespace std;

int main(){
    string expr3 = "";
    getline(cin, expr3);
    arithmeticExpression ex3(expr3);
    ex3.buildTree();
    cout<<"expression 3: "<<expr3<<endl;
    cout<<"infix: "; ex3.infix(); cout<<endl;
    cout<<"prefix: "; ex3.prefix(); cout<<endl;
    cout<<"postfix: "; ex3.postfix(); cout<<endl;
    ex3.visualizeTree("expr3.dot");
    cout<<endl;

    return 0;
}