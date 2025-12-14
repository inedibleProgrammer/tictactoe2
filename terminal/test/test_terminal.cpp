#include <gtest/gtest.h>

#include <terminal.h>

class MockTerminal : public term::Terminal
{
public:
    ~MockTerminal() = default;
    term::TerminalResult Configure() override
    {
        return term::TerminalResult::Success;
    }
};

TEST(terminal, terminal_dummy)
{
    EXPECT_TRUE(0 == 0);
}

TEST(terminal, create_terminal)
{
    MockTerminal terminal;
}
