#include <iostream>
#include <iomanip>  // For std::hex, std::setw, std::setfill
#include <termios.h>
#include <unistd.h> // For STDIN_FILENO
#include <cstdio>   // For NCCS
#include <cstdlib>

#include <thread>
#include <chrono>

#include <linux_terminal.h>

// Note: In C++, we prefer C++ headers like <cstdio> over C headers like <stdio.h>,
// but <termios.h> and <unistd.h> remain the standard C/POSIX headers.

void inspect_termios(struct termios& pTerm)
{
    std::cout << "\n[Terminal Flags (in Hexadecimal)]\n";
    std::cout << std::hex << std::uppercase << std::setfill('0');

    // Displaying the main flag groups
    std::cout << "  - Input Flags (c_iflag):  0x" << std::setw(8) << pTerm.c_iflag << "\n";
    std::cout << "  - Output Flags (c_oflag): 0x" << std::setw(8) << pTerm.c_oflag << "\n";
    std::cout << "  - Control Flags (c_cflag): 0x" << std::setw(8) << pTerm.c_cflag << "\n";
    std::cout << "  - Local Flags (c_lflag):  0x" << std::setw(8) << pTerm.c_lflag << "\n";
    
    // Displaying the NCCS size
    std::cout << std::dec << "\n[Control Characters]\n";
    std::cout << "  - NCCS Array Size: " << NCCS << "\n";

    // Displaying the c_cc array contents with labels
    std::cout << "  - c_cc Array Contents (Values):\n";
    
    // Reset formatting for the loop output
    std::cout << std::dec << std::setfill(' ');

    for (int i = 0; i < NCCS; ++i) {
        // Use a switch to label common control characters clearly
        std::string label;
        switch (i) {
            case VINTR: label = "VINTR (Interrupt)"; break;
            case VQUIT: label = "VQUIT (Quit)"; break;
            case VERASE: label = "VERASE (Erase)"; break;
            case VKILL: label = "VKILL (Kill)"; break;
            case VEOF: label = "VEOF (End-of-File)"; break;
            case VTIME: label = "VTIME (Timeout)"; break;
            case VMIN: label = "VMIN (Min Chars)"; break;
            // Add more standard labels here if needed (e.g., VSUSP, VSTART, VSTOP)
            default: label = "Index " + std::to_string(i); break;
        }

        std::cout << "    [" << std::setw(2) << i << "] "
                  << std::setw(20) << std::left << label
                  << " = " 
                  << std::setw(3) << std::right << (int)pTerm.c_cc[i] 
                  << "\n";
    }

    std::cout << "--- Inspection Complete ---\n" << std::endl;
}

int main() {
    std::cout << "--- Termios Flag Inspection Utility ---\n";
    
    struct termios old_stdin_settings;
    struct termios old_stdout_settings;
    
    // Attempt to retrieve the current terminal attributes
    if (tcgetattr(STDIN_FILENO, &old_stdin_settings) == -1) {
        std::cerr << "Error: Failed to get terminal attributes (tcgetattr failed).\n";
        return EXIT_FAILURE;
    }

    // Attempt to retrieve the current terminal attributes
    if (tcgetattr(STDOUT_FILENO, &old_stdout_settings) == -1) {
        std::cerr << "Error: Failed to get terminal attributes (tcgetattr failed).\n";
        return EXIT_FAILURE;
    }

    // std::cout << "--- STDIN --- \n";
    // inspect_termios(old_stdin_settings);

    // std::cout << "--- STDOUT --- \n";
    // inspect_termios(old_stdout_settings);


    struct termios new_stdin_settings = old_stdin_settings;
    new_stdin_settings.c_cc[VMIN] = 0;
    new_stdin_settings.c_cc[VTIME] = 0;
    new_stdin_settings.c_lflag &= ~(ECHO | ICANON);

    // tcsetattr(STDIN_FILENO, TCSANOW, &new_stdin_settings);

    term::LinuxTerminal term;
    term.Configure();

    std::this_thread::sleep_for(std::chrono::seconds(2));


    return 0;
}
