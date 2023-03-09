#include<iostream>
#include<string>
#include <exception>
using namespace std;


int main(){
    const int GRAVITY = 2;
    int altitude = 1000;
    int fuel = 500;
    int velocity = 70;
    int time = 0;

    cout << "%a" << altitude << "\n";
    cout << "%f" << fuel << "\n";
    cout << "%v" << velocity << "\n";
    cout << "%t" << time << "\n";

    string inputLine = "";

    do
    {
        getline(cin,inputLine);
      
        if((!inputLine.empty()) && (inputLine.length() > 0))
        {
            if(inputLine.at(0) == '#')
            {
                cout << inputLine << endl;
            }
            else if(inputLine.at(0) == '%')
            {
                inputLine.erase(inputLine.begin());
                int burnRate = stoi(inputLine);  //get an int from the string inputLine
                if(altitude <= 0)
                {
                    cout << "#Game is over\n";
                }
                else if(burnRate > fuel)
                {
                    cout << "#Sorry, you don't have that much fuel.\n";
                }
                else
                {
                    time++;
                    altitude = altitude - velocity;
                    velocity = ((velocity + GRAVITY) * 10 - burnRate * 2) / 10;
                    fuel = fuel - burnRate;
                    if(altitude <= 0)
                    {
                        altitude = 0;
                        if(velocity <=5)
                        {
                            cout << "#You have landed safely.\n";
                        }
                        else
                        {
                            cout << "#You have crashed.\n";
                        }
                    }
                }
                cout << "%a" <<  altitude << "\n";
                cout << "%f" <<  fuel << "\n";
                cout << "%v" <<  velocity << "\n";
                cout << "%t" <<  time << "\n";

            }
        }
    }while(!inputLine.empty() && altitude > 0);

}