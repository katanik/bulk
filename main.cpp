#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using Cmd = std::string;
using CmdBlock = std::vector<Cmd>;

void printCmdBlock(std::ostream& out, const CmdBlock& cmdBlock)
{
    if (cmdBlock.empty())
        return;

    out<< "bulk: ";
    for (size_t idx = 0; idx < cmdBlock.size(); ++idx)
    {
        out << cmdBlock[idx];
        if (idx + 1 < cmdBlock.size())
            out << ", ";
    }
    out << std::endl;
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

        Cmd currentCmd;
        CmdBlock currentCmdBlock;

        int braceIt = 0;
        while(std::getline(std::cin, currentCmd))
        {
            if (currentCmd == "{")
            {
                if (braceIt == 0)
                {
                    printCmdBlock(std::cout, currentCmdBlock);
                    currentCmdBlock.clear();
                }
                braceIt++;
            }
            else if (currentCmd == "}")
            {
                braceIt = std::max(0, braceIt - 1);
                if (braceIt == 0)
                {
                    printCmdBlock(std::cout, currentCmdBlock);
                    currentCmdBlock.clear();
                }
                continue;
            }
            else
                currentCmdBlock.push_back(currentCmd);

            if (currentCmdBlock.size() == n && braceIt == 0)
            {                
                printCmdBlock(std::cout, currentCmdBlock);
                currentCmdBlock.clear();
            }
        }

        if (braceIt == 0)
            printCmdBlock(std::cout, currentCmdBlock);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
