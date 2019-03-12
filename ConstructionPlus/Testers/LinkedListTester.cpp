//
//  LinkedListTester.cpp
//  ConstructionPlus
//
//  Created by Salinas, Jesus on 3/8/19.
//  Copyright © 2019 Salinas, Jesus. All rights reserved.
//

#include "LinkedListTester.hpp"

using namespace std;

void LinkedListTester :: testListBasics()
{
    
    LinkedList<int> myInt;
    myInt.add(3);
    myInt.add(4);
    myInt.add(5);
    myInt.add(6);
    
    for(int i = 0; i < myInt.getSize(); i++)
    {
        cout<< myInt.getFromIndex(i) << endl;
    }
    
    LinkedList<string> myString;
    myString.add("Emi");
    myString.add("Jacob");
    myString.add("Luis");
    myString.add("Alex");
    
    for(int i = 0; i < myString.getSize(); i++)
    {
        cout<< myString.getFromIndex(i) << endl;
    }
    
    
    LinkedList<int> numbers;
    numbers.add(9);
    
    cout << numbers.getFront() -> getData() << " Is is at the front of the list and should be 9" <<endl;
    cout << numbers.getEnd() ->getData() << " Is at the end of the list and should be 9" << endl;
    
    numbers.add(0);
    cout << numbers.getFront()->getData() << " Is is at the front of the list and should be 9"<< endl;
    cout << numbers.getEnd()->getData() << " Is at the end of the list and should be 0"<< endl;
    
    numbers.addAtIndex(1,2);
    numbers.add(324);
    
    cout << numbers.getFront()->getData() << " It is at the front of the list and should be 9"<<endl;
    cout << numbers.getEnd()->getData() << " Is at the end of the list and should be 324"<< endl;
    
    cout << "This loop should print 4 lines" << endl;
    
    for(int index = 0; index < numbers.getSize(); index++)
    {
        cout << numbers.getFromIndex(index) << endl;
        
    }
    
    numbers.remove(0);
    numbers.add(32567);
    numbers.addAtIndex(0, 2312);
    
    cout<< numbers.getFront()-> getData() << " Is is at the front of the liust and should be 2312" << endl;
    cout << numbers.getEnd()->getData()<< " Is is at the ebd of the list and should be 32567" << endl;
    
}

void LinkedListTester :: testListWithData()
{
    Timer listTimer;
    
    listTimer.startTimer();
    LinkedList<CrimeData> crimes = FileController :: readDataToList("/Users/epla8915/Documents/C++ projects/DataConstruction/DataConstruction/Resources/crime.csv");
    
    
    listTimer.stopTimer();
    cout << "This is how long it took to read the structure into our custom data structure" << endl;
    listTimer.displayInformation();
    
    listTimer.resetTimer();
    cout << "Here is how long it takes to access a random data value" << endl;
    listTimer.startTimer();
    int randomLocation = (rand() * rand()) % crimes.getSize();
    cout << "The random index is " << randomLocation << endl;
    double totalViolentRate = crimes.getFromIndex(randomLocation).getAllViolentRates();
    listTimer.stopTimer();
    cout << "The random crime stat is: " << totalViolentRate << " , and here is the time" << endl;
    listTimer.displayInformation();
    
}
