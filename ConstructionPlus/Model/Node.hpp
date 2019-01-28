//
//  Node.hpp
//  ConstructionPlus
//
//  Created by Salinas, Jesus on 1/28/19.
//  Copyright © 2019 Salinas, Jesus. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <assert.h>

template <class Type>
Class Node
{
private:
    Type data;
public:
    Node(type data);
    Type getData();
    void setData(Type data);
};

//Template definitions

template <class Type>
Node<Type> :: Node(Type data)
{
    this->data = data;
}

template<class Type>
Type Node<Type> :: getData()
{
    return data;
}

template <class Type>
void Node<Type> :: setData(Type data)
{
    this->data = data;
}
#endif /* Node_h */