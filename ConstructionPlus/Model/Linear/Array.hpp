//
//  Array.hpp
//  ConstructionPlus
//
//  Created by Salinas, Jesus on 1/30/19.
//  Copyright © 2019 Salinas, Jesus. All rights reserved.
//

#ifndef Array_h
#define Array_h


#endif /* Array_h */

#include <assert.h> //Used for validdating user supplied data.
#include <iostream> //Used for tracing and debug statements.

using namespace std; //Used for ketyword access.

template <class Type>
class Array
{
private:
    Type * internalArray;
    int size;
public:
    //Constructor
    Array<Type>(int size);
    
    //Copy Constructor
    Array<Type>(const Array<Type> & toCopy);
    //Destructor
    ~Array<Type>();
    
    //Operatore
    Array<Type> & operator = (const Array<Type> & toReplace);
    Type& operator [] (int index);
    Type operator [] (int index) const;
    
    //Methods
    int getSizre() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type data);
    
}
template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    this->size = size;
    
    internalArray = new Type[size];
}

template <class Type>
Array<Type> :: Array(const Array<Type> & toCopy)
{
    this->size = toCopy.getSize();
    
    //Build Data Structure
    internalArray[index] = toCopy[index];  
}

}
