/*
 *  Copyright (С) since 2019 Andrei Guluaev (Winfidonarleyan/Kargatum) https://github.com/Winfidonarleyan 
*/

#include "ScriptMgr.h"
#include "Log.h"
#include "Chat.h"

class TestCrash_CS : public CommandScript
{
public:
    TestCrash_CS() : CommandScript("TestCrash_CS") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> crashCommandTable =
        {
            { "crash",      SEC_CONSOLE,    true,  &HandleTestCrashCommand,     "" }
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "test",       SEC_CONSOLE,    true,  nullptr,                     "", crashCommandTable }
        };

        return commandTable;
    }

    // .test crash
    static bool HandleTestCrashCommand(ChatHandler* handler, const char* /*args*/)
    {
        sLog->outString("Go crash test...");
        Player* player = nullptr;
        player->SetAcceptWhispers(true);
        return true;
    }
};

void AddSC_TestCrash()
{
    new TestCrash_CS();
}
