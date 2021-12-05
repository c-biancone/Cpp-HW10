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
    // getline(cin >> ws, message);

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
    // need to use absolute path to file bc binaries in different location on my machine
    ifstream data ("D:\\Documents\\RIT\\Semester_4\\C++\\Homework-10\\" + fileName);
    string delimiter = ":";
    size_t position = 0;

    string key, response;
    string line;

    // data.open("fileName", ifstream::in);

    if (data.is_open())
    {
        while (getline(data, line))
        {
            position = line.find(delimiter);
            key = line.substr(0, position);
            line.erase(0, position + delimiter.length());
            response = line;
            pair<string, string> pair (key, response);
            responses.insert(pair);
        }

    } else {
        cout << "Unable to open file\n";
    }

    data.close();
}