#pragma once

#include <real_player.h>
#include <array>


// 0 1 2
// 3 4 5
// 6 7 8

namespace ttt {

    static constexpr int kBoardSize = 9;
    static constexpr int kNumPlayers = 2;

    enum class TttResult : int
    {
        SUCCESS,
        SPACE_OCCUPIED,
        INDEX_OUT_OF_RANGE,
    };

    class TicTacToe
    {
    public:
        TicTacToe();
        TttResult handleTurn(int board_index);
        int turnCount();

    public:
        std::array<Player, kNumPlayers> players_;
        int current_player_;
        std::array<int, kBoardSize> board_;

    private:
        int num_turns_;


    };

} // end of namespace ttt
