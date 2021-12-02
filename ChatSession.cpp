//
// Created by Chris on 12/1/2021.
//

#include "ChatSession.h"

ChatSession::ChatSession(std::string userName, bool echo)
{}

void ChatSession::registerBot(std::shared_ptr<ChatBot> bot)
{
    bots.push_back(bot);
}

void ChatSession::removeBot(std::shared_ptr<ChatBot> bot)
{
    bots.remove(bot);
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
}