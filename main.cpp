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
    ChatSession session(userName, ECHO_INPUT);

    shared_ptr<ChatBot> bot;

    cin >> botName;
    // Register the chatbots
    while(botName != "START")
    {
        bot = make_shared<ChatBot>(botName);
        session.registerBot(bot);
        cin >> botName;
    }

    // Run the chat session
    session.run();

    return 0;
}
