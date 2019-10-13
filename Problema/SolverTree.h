//
// Created by suro on 9/25/19.
//

#ifndef PROBLEMA_SOLVETREE_H
#define PROBLEMA_SOLVETREE_H

#include "Node.h"

class SolverTree{
    Node* root;
public:
    SolverTree():root(nullptr){};
    void buildTree(std::string equation){
        std::vector<Node> nodes;
        std::stack<char> signs;
        std::string number="";
        Node* node;
        for(int a=0;equation[a]!='\n';++a){

            switch (equation[a]){
                case '(': signs.push('(');
                    break;
                case ')':
                    if(!number.empty()){
                        node = new NodeNumber(std::stof(number));
                        nodes.push_back(*node);
                        number="";
                    }
                    while(signs.top()!='('){
                        node = new NodeOperator(signs.top());
                        nodes.emplace_back(*node);
                        signs.pop();
                    }
                    signs.pop();
                    break;
                case '+':
                    if(!number.empty()){
                        node = new NodeNumber(std::stof(number));
                        nodes.push_back(*node);
                        number="";
                    }
                    while(signs.size()){
                        node = new NodeOperator(signs.top());
                        nodes.emplace_back(*node);
                        signs.pop();
                    }
                    signs.push('+');
                    break;
                case '-':
                    if(!number.empty()){
                        node = new NodeNumber(std::stof(number));
                        nodes.push_back(*node);
                        number="";
                    }
                    while (signs.size()){
                        node = new NodeOperator(signs.top());
                        nodes.emplace_back(*node);
                        signs.pop();
                    }
                    signs.push('-');
                    break;
                case '*':
                    if(!number.empty()){
                        node = new NodeNumber(std::stof(number));
                        nodes.push_back(*node);
                        number="";
                    }
                    while(signs.size()){
                        char c=signs.top();
                        if(c=='(' || c=='+' || c=='-') break;
                        signs.pop();
                        node = new NodeOperator(c);
                        nodes.emplace_back(*node);
                        if(c=='*' || c=='/') break;
                    }
                    signs.push('*');
                    break;
                case '/':
                    if(!number.empty()){
                        node = new NodeNumber(std::stof(number));
                        nodes.push_back(*node);
                        number="";
                    }
                    while(signs.size()){
                        char c=signs.top();
                        if(c=='(' || c=='+' || c=='-') break;
                        signs.pop();
                        node = new NodeOperator(c);
                        nodes.emplace_back(*node);
                        if(c=='*' || c=='/') break;
                    }
                    signs.push('/');
                    break;
                case '^':
                    if(!number.empty()){
                        node = new NodeNumber(std::stof(number));
                        nodes.push_back(*node);
                        number="";
                    }
                    if(signs.size() && signs.top()=='^'){
                        node = new NodeOperator('^');
                       nodes.emplace_back(*node);
                    } else {
                        signs.push('^');
                    }
                    break;
                default:
                    number+=equation[a];
                    break;
            }
        }
    };
};

#endif //PROBLEMA_SOLVETREE_H