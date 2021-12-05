#include "ChatSession.h"
#include <sstream>

using namespace std;

ChatSession::ChatSession(std::string userName, bool echo)
{
    this->userName = userName;
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
    cout << "[" << userName << "]: ";
    string input, word;
    cout.flush();
    // WHY IS THIS NOT WORKING
    getline(cin >> ws, input);

    while (input != "QUIT")
    {
        for (auto bot : bots)
        {
            std::string fileName = "T800.txt";
            bot->loadResponses(fileName);
        }
        this->notifyBots(input);

        cout << "[" << userName << "]: ";
        cin >> input;
    }

}