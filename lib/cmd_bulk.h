#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace bulk{

using Cmd = std::string;

class CmdBulk
{
public:
    CmdBulk() = default;
    ~CmdBulk() = default;

    bool isEmpty() const;
    size_t size() const;
    const Cmd& getCmd(size_t index) const;
    void addCmd(const Cmd& cmd);
    void clear();

private:
    std::vector<Cmd> m_bulk;
};
    
void printCmdBulk(std::ostream& out, const CmdBulk& cmdBulk);

} // bulk
