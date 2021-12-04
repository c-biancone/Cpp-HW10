//
// Created by Chris on 12/1/2021.
//

#include "ChatBot.h"
#include <iostream>
#include <fstream>

using namespace std;

ChatBot::ChatBot(std::string name)
{
    this->name = name;
}

void ChatBot::newMessage(std::string message)
{
    cout.flush();
    getline(cin >> ws, message);

    for (char c : message)
    {
        [message, &c] () {return toupper(c);};
    }
}

void ChatBot::loadResponses(std::string fileName)
{
    ifstream data;
    char delimiter(':');

    data.open(fileName);

    string key;
    string response;

    while(getline(data, key, delimiter) && getline(data, response))
    {
        responses[key] = response;
    }

    data.close();
}