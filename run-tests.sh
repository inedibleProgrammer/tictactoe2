# Change directory to the script's directory
cd "$(dirname "$0")"

meson setup build --reconfigure --buildtype=debug && \
    ninja -C build && \
    cd build && \
    meson test --print-errorlogs

# /home/john/jup/cppprogramming/tictactoe2/build/terminal/example
