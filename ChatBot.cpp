//
// Created by Chris on 12/1/2021.
//

#include "ChatBot.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

ChatBot::ChatBot(std::string name)
{
    this->name = name;
}

void ChatBot::newMessage(std::string message)
{
    cout.flush();
    getline(cin >> ws, message);

    // convert to uppercase
    for_each(message.begin(), message.end(), [](char& c){c = ::toupper(c);});

    // iterate through words and check matches with keys
    string tmp;
    stringstream strStrm(message);
    map<string, string>::iterator it;
    while (strStrm >> tmp)
    {
        // search for word in keys
        it = responses.find(tmp);
        // if exists
        if (it != responses.end())
        {
            // print response
            cout << it->second << "\n";
        }
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