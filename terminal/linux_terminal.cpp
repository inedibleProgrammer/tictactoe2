#include <linux_terminal.h>

#include <unistd.h>

namespace term
{
    LinuxTerminal::~LinuxTerminal()
    {
        tcsetattr(STDIN_FILENO, TCSANOW, &originalSettings_);
    }

    TerminalResult LinuxTerminal::Configure()
    {
        tcgetattr(STDIN_FILENO, &originalSettings_);
        currentSettings_ = originalSettings_;
        currentSettings_.c_cc[VMIN] = 0;
        currentSettings_.c_cc[VTIME] = 0;
        currentSettings_.c_lflag &= ~(ECHO | ICANON);
        tcsetattr(STDIN_FILENO, TCSANOW, &currentSettings_);
        return TerminalResult::Success;
    }
}



