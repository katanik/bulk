#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using Cmd = std::string;
using CmdBulk = std::vector<Cmd>;

void printCmdBulk(std::ostream& out, const CmdBulk& cmdBulk)
{
    if (cmdBulk.empty())
        return;

    out<< "bulk: ";
    for (size_t idx = 0; idx < cmdBulk.size(); ++idx)
    {
        out << cmdBulk[idx];
        if (idx + 1 < cmdBulk.size())
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
        CmdBulk currentCmdBulk;

        int braceIt = 0;
        while(std::getline(std::cin, currentCmd))
        {
            if (currentCmd == "{")
            {
                if (braceIt == 0)
                {
                    printCmdBulk(std::cout, currentCmdBulk);
                    currentCmdBulk.clear();
                }
                braceIt++;
            }
            else if (currentCmd == "}")
            {
                braceIt = std::max(0, braceIt - 1);
                if (braceIt == 0)
                {
                    printCmdBulk(std::cout, currentCmdBulk);
                    currentCmdBulk.clear();
                }
                continue;
            }
            else
                currentCmdBulk.push_back(currentCmd);

            if (currentCmdBulk.size() == n && braceIt == 0)
            {                
                printCmdBulk(std::cout, currentCmdBulk);
                currentCmdBulk.clear();
            }
        }

        if (braceIt == 0)
            printCmdBulk(std::cout, currentCmdBulk);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
