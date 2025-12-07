# Change directory to the script's directory
cd "$(dirname "$0")"

meson setup build --reconfigure --buildtype=debug && \
    ninja -C build && \
    cd build && \
    meson test --print-errorlogs
