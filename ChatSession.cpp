#include "ChatSession.h"
#include <sstream>

using namespace std;

ChatSession::ChatSession(std::string userName, bool echo)
{
    this->userName = userName;
    // echo is set to true in header file
    // cout << "created session\n";
}

void ChatSession::registerBot(std::shared_ptr<ChatBot> bot)
{
    bots.push_back(bot);
    // cout << "registered bot\n";
}

void ChatSession::removeBot(std::shared_ptr<ChatBot> bot)
{
    bots.remove(bot);
    // cout << "removed bot\n";
}

void ChatSession::notifyBots(std::string message)
{
    for (auto bot : bots)
    {
        bot->newMessage(message);
    }
}

void ChatSession::run()
{
    // cout << "[" << userName << "]: ";
    string input, word;
    cout.flush();

    getline(cin >> ws, input);
    if (this->echo == true)
    {
        cout << "[" << userName << "]: " << input << "\n";
    }

    while (input != "QUIT")
    {
        string tmp = input;
        for (auto bot : bots)
        {
            std::string fileName = bot->name + ".txt";
            bot->loadResponses(fileName);
        }
        this->notifyBots(tmp);

        // cout << "[" << userName << "]: ";
        getline(cin >> ws, input);
        if (this->echo == true)
        {
            cout << "[" << userName << "]: " << input << "\n";
        }
    }

}