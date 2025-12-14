#pragma once

#include <terminal.h>
#include <termios.h>

namespace term
{
    class LinuxTerminal : public Terminal
    {
    public:
        LinuxTerminal() = default;
        ~LinuxTerminal() override;
        TerminalResult Configure() override;
    private:
        termios originalSettings_;
        termios currentSettings_;
    };
}
