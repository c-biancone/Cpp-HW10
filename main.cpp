#include <iostream>
#include "ChatSession.h"
#include "ChatBot.h"

using namespace std;
const bool ECHO_INPUT = true;

int main()
{

    /*
     * Input to setup Chat Session
     * USERNAME
     * BOTNAME_1
     * BOTNAME_2
     * ....
     * START
     */

    /*
     * Example:
     * Neo
     * T800
     * START
     */

    string userName;
    string botName;

    // Read in username and create the chat session
    cin >> userName;
    bool echo = true;
    ChatSession session(userName, echo);

    shared_ptr<ChatBot> bot;

    // Register the chatbots
    while(botName != "START")
    {
        botName = std::to_string(cin.get());
        bot = make_shared<ChatBot>(botName);
        session.registerBot(bot);
    }

    // Run the chat session
    session.run();

    return 0;
}
