//
//  LinkedListTester.hpp
//  ConstructionPlus
//
//  Created by Salinas, Jesus on 3/8/19.
//  Copyright © 2019 Salinas, Jesus. All rights reserved.
//

#include "../Model/Linear/LinkedList.hpp"
#include "../Controller/FileController.hpp"
#include "../Controller/Tools/Timer.hpp"
#include "../Resources/CrimeData.hpp"
#include <iostream>

class LinkedListTester
{
public:
    void testListBasics();  //Makes sure the functionality of a LinkedList compiles and operates appropriately
    void testListWithData();    //Loads and see times with file data
};

#endif /* LinkedListTester_hpp */
