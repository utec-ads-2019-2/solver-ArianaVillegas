//
// Created by suro on 9/25/19.
//

#ifndef PROBLEMA_SOLVERTREE_H
#define PROBLEMA_SOLVERTREE_H

#include "Node.h"

using namespace std;

class SolverTree{
    Node* root;
    float solution;
    stack<char> signs;
    queue<Node*> nodes;
    stack<Node*> solver;
    map<char,int> sign;
    map<char,float> var;

    float solve(Node* node){
        if(!node->left && !node->right){
            string value=node->value;
            if(value[0]>='A' && value[0]<='Z'){
                if(var.find(value[0])==var.end()) {
                    float v;
                    std::cout << "Ingresa el valor de " << value << ": " ; std::cin >> v;
                    var[value[0]]=v;
                }
                return var[value[0]];
            }
            return stof(value);
        }else{
            switch (node->value[0]){
                case '+': return solve(node->left)+solve(node->right);
                case '-': return solve(node->left)-solve(node->right);
                case '*': return solve(node->left)*solve(node->right);
                case '/': return solve(node->left)/solve(node->right);
                case '^': return pow(solve(node->left),solve(node->right));
            }
        }
    }
    void printPreOrder(Node* node){
        if(!node->left && !node->right){
            cout << node->value << ' ';
        } else {
            cout << node->value << ' ';
            if(node->left) printPreOrder(node->left);
            if(node->right) printPreOrder(node->right);
        }
    }
    void printInOrder(Node* node) {
        if(!node->left && !node->right){
            cout << node->value << ' ';
        } else {
            cout << "( ";
            if(node->left) printInOrder(node->left);
            cout << node->value << ' ';
            if(node->right) printInOrder(node->right);
            cout << ") ";
        }
    }
    void printPostOrder(Node* node) {
        if(!node->left && !node->right){
            cout << node->value << ' ';
        } else {
            if(node->left) printPostOrder(node->left);
            if(node->right) printPostOrder(node->right);
            cout << node->value << ' ';
        }
    }
    void addNumber(string &number){
        if(number!=""){
            Node* nu=new Node(number,1);
            nodes.push(nu);
            number.clear();
        }
    }
    void addOperator(string newString){
        Node *op = new Node(signs.top() + newString, 0);
        nodes.push(op);
        signs.pop();
    }
public:
    SolverTree(){
        sign={{')',-1},{'(',0},{'+',1},{'-',1},{'*',2},{'/',2},{'^',3}};
    }
    void buildTree(std::string equation){
        int size=equation.size();
        map<char,int>::iterator end=sign.end();
        string number,newString;
        for(int a=0;a<size;++a) {
            if (sign.find(equation[a]) == end) {
                number += equation[a];
            }else {
                addNumber(number);
                if(sign[equation[a]]) {
                    while (signs.size() && sign[signs.top()] && (sign[signs.top()] >= sign[equation[a]]))
                        addOperator(newString);
                    if(sign[equation[a]]>0) signs.push(equation[a]);
                    else signs.pop();
                } else signs.push(equation[a]);
            }
        }
        addNumber(number);
        while(signs.size()) addOperator(newString);
        //--------------------------------------------------------------------------------------------------------------
        while(nodes.size()){
            if(!nodes.front()->number) {
                nodes.front()->right=solver.top();solver.pop();
                nodes.front()->left=solver.top();solver.pop();
                nodes.front()->number=1;
            }
            solver.push(nodes.front());
            nodes.pop();
        }
        root=solver.top();
    };
    void solve(){
        solution=solve(root);
    }
    void printPreOrder(){
        printPreOrder(root);
        cout << '\n';
    }
    void printInOrder(){
        printInOrder(root);
        cout << '\n';
    }
    void printPostOrder(){
        printPostOrder(root);
        cout << '\n';
    }
    float getResult(){
        return solution;
    }
};

#endif //PROBLEMA_SOLVERTREE_H
