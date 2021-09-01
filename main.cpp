#include <iostream>
#include <vector>
#include <string>

using Cmd = std::string;
using CmdBlock = std::vector<Cmd>;

void printCmdBlock(std::ostream& out, const CmdBlock& cmdBlock)
{
    if (cmdBlock.empty())
        return;

    out<< "bulk:";
    for (size_t idx = 0; idx < cmdBlock.size(); ++idx)
    {
        out << cmdBlock[idx];
        if (idx + 1 < cmdBlock.size())
            out << ", ";
    }
}

int main(int argc, char const *argv[])
{
    try
    {
        Cmd currentCmd;
        CmdBlock currentCmdBlock;

        unsigned int braceIt = 0;
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
                braceIt--;
                if (braceIt == 0)
                {
                    printCmdBlock(std::cout, currentCmdBlock);
                    currentCmdBlock.clear();
                }
            }
            else
            {
                currentCmdBlock.push_back(currentCmd);
            }
        }

        printCmdBlock(std::cout, currentCmdBlock);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
