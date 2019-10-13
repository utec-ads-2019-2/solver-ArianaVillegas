//
// Created by suro on 9/25/19.
//

#ifndef PROBLEMA_NODE_H
#define PROBLEMA_NODE_H

using namespace std;

class Node{
    Node* left;
    Node* right;
    string value;
    bool number;
    friend class SolverTree;
public:
    Node(string value,bool number):value(value),number(number),left(nullptr),right(nullptr){}
    virtual ~Node() = default;
};

#endif //PROBLEMA_NODE_H
