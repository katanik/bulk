#include "cmd_bulk.h"

namespace bulk{

bool CmdBulk::isEmpty() const
{
    return m_bulk.empty();
}

size_t CmdBulk::size() const
{
    return m_bulk.size();
}

const Cmd& CmdBulk::getCmd(size_t index) const
{
    return m_bulk[index];
}

void CmdBulk::addCmd(const Cmd& cmd)
{
    m_bulk.push_back(cmd);
}

void CmdBulk::clear()
{
    m_bulk.clear();
}

void printCmdBulk(std::ostream& out, const CmdBulk& cmdBulk)
{
    if (cmdBulk.isEmpty())
        return;

    out<< "bulk: ";
    for (size_t idx = 0; idx < cmdBulk.size(); ++idx)
    {
        out << cmdBulk.getCmd(idx);
        if (idx + 1 < cmdBulk.size())
            out << ", ";
    }
    out << std::endl;
}

} // bulk
