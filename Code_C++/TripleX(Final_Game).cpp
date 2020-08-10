//
//  main.cpp
//  TripleX
//
//  Created by Jay Advani on 06/08/20.
//  Copyright © 2020 Jay Advani. All rights reserved.
//

#include <iostream>
#include<ctime>
using namespace std;

void PrintIntroduction(int Difficulty)
{
 // Begin statements....
    cout<<endl;
    cout << "Building you are in is falling make a run for the safety vault!!!\n"<<endl;
    cout<<"Get through the barrage of passcode protected locks to make it to the safety vault!!!\n";
    cout<<endl;
    cout<<"######################################";
    cout<<endl;
    cout<<endl;
    cout<<"        Current Level: "<<Difficulty - 4;
    cout<<endl;
    cout<<endl;
    cout<<"######################################";
    
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    // Variables declaration.....
    //rand() guarantees any number in range 0 and a value that is guaranteed to be atleast 32,767
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    // Printing hint statements
    cout<<endl;
    cout<<" /-/ There are 3 numbers of your code /-/"<<endl;
    cout<<endl;
    cout<<" /-/ Sum of the three numbers is: "<<CodeSum<<endl;
    cout<<endl;
    cout<<" /-/ The product of the three numbers is: "<<CodeProduct<<endl;
    cout<<endl;
    
    // Player guess input
    int GuessA,GuessB,GuessC;
    cout<<"Enter your numbers: ";
    cin>>GuessA>>GuessB>>GuessC;
    cout<<endl;
    
    // Guess answers
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    //Win - Lose Block
    if(CodeSum  == GuessSum && CodeProduct == GuessProduct)
    {
        cout<<endl;
        cout<<"Door: "<<Difficulty - 4;
        cout<<"...Unlocked.";
        cout<<endl;
        return true;
    }
    
    else
        {
            cout<<endl;
            cout<<"|-----------------------------|"<<endl;
            cout<<"   ERROR CODE! Try Again!!!"<<endl;
            cout<<"|-----------------------------|"<<endl;
            cout<<endl;
            return false;
        }
        
}

int main()
{
    srand(time(NULL));
    
    const int MaxDifficulty = 14;
    
    int LevelDifficulty = 5;
    
    while(LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear(); // Clears any errors
        cin.ignore(); // Discards the buffer
        
        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    
    cout<<endl;
    cout<<"|--------------|"<<endl;
    cout<<"   YOU WON!!!"<<endl;
    cout<<"|--------------|"<<endl;
    cout<<endl;

    return 0;
}
