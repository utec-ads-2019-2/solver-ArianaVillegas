#include <iostream>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include "SolverTree.h"

using namespace std;

int main(){
    SolverTree st;
    string formula; cin >> formula;
    st.buildTree(formula);
    st.solve();
    cout << st.getResult() <<'\n';
    st.printPreOrder();
    st.printInOrder();
    st.printPostOrder();

    return 0;
}