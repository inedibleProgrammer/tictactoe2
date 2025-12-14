#pragma once

#include <termios.h>

namespace term
{
    enum class TerminalResult : int
    {
        Success,
    };
    class Terminal
    {
    public:
        virtual ~Terminal() = default;
        virtual TerminalResult Configure() = 0;
    };
}



