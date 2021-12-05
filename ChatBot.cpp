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

    // convert to uppercase
    for_each(message.begin(), message.end(), [](char& c){c = ::toupper(c);});

    string tmp;
    stringstream strStrm(message);
    map<string, string>::iterator it;

    // iterate words in string
    while (strStrm >> tmp)
    {
        // search for word in keys
        it = responses.find(tmp);
        // if exists
        if (it != responses.end())
        {
            // print corresponding response
            cout << it->second << "\n";
            break;
        }
    }
}

void ChatBot::loadResponses(std::string fileName)
{
    // need to use absolute path to file bc binaries in different location on my machine
    ifstream data ("D:\\Documents\\RIT\\Semester_4\\C++\\Homework-10\\" + fileName);
    string delimiter = ":";
    size_t position = 0;

    string key, response;
    string line;

    if (data.is_open())
    {
        while (getline(data, line))
        {
            // determine position of colon delimiter
            position = line.find(delimiter);
            // key is substring before colon
            key = line.substr(0, position);
            // remove key and delimiter from string
            line.erase(0, position + delimiter.length());
            // response is what is left
            response = line;
            // create pair for easy insertion to map
            pair<string, string> pair (key, response);
            responses.insert(pair);
        }
    } else {
        cout << "Unable to open file\n";
    }

    data.close();
}