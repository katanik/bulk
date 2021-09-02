#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "lib/cmd_bulk.h" 

void bulkProcessor(std::istream& in, std::ostream& out, int n)
{
    bulk::Cmd currentCmd;
    bulk::CmdBulk currentCmdBulk;

    int braceIt = 0;
    
    while(std::getline(in, currentCmd))
    {
        if (currentCmd == "{")
        {
            if (braceIt == 0)
            {
                bulk::printCmdBulk(out, currentCmdBulk);
                currentCmdBulk.clear();
            }
            braceIt++;
        }
        else if (currentCmd == "}")
        {
            braceIt = std::max(0, braceIt - 1);
            if (braceIt == 0)
            {
                bulk::printCmdBulk(out, currentCmdBulk);
                currentCmdBulk.clear();
            }
            continue;
        }
        else
            currentCmdBulk.addCmd(currentCmd);

        if (currentCmdBulk.size() == n && braceIt == 0)
        {                
            bulk::printCmdBulk(out, currentCmdBulk);
            currentCmdBulk.clear();
        }
    }

    if (braceIt == 0)
        bulk::printCmdBulk(out, currentCmdBulk);
}

int main(int argc, char const *argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cout<<"Bad format of output data";
            return 0;
        }

        int n = std::stoi(argv[1]);
        if (n < 1)
        {
            std::cout<<"Bad number";
            return 0;
        }

        bulkProcessor(std::cin, std::cout, n);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
