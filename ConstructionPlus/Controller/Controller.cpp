//
//  Controller.cpp
//  ConstructionPlus
//
//  Created by Salinas, Jesus on 1/28/19.
//  Copyright © 2019 Salinas, Jesus. All rights reserved.
//

#include "Controller.hpp"

void Controller :: start()
{
    cout << "Welcome to the Data Structure App." << endl;
    usingNodes();
}

void Controller :: usingNodes()
{
    Node<int> mine(5);
    Node<string> wordHolder("words can be stored too");
    cout << mine.getData() << endl;
    cout << wordHolder.getData() << endl;
    wordHolder.setData("replaced text");
    cout << wordHolder.getData() << endl;
    
}
