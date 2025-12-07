#include <tictactoe.h>

namespace ttt {

    TicTacToe::TicTacToe()
        : players_{},
          current_player_(0),
          board_{},
          num_turns_(0)
    {
    }

    TttResult TicTacToe::handleTurn(int board_index)
    {
        if(board_index >= kBoardSize)
        {
            return TttResult::INDEX_OUT_OF_RANGE;
        }

        bool space_occupied = board_[board_index] != 0;
        if(space_occupied)
        {
            return TttResult::SPACE_OCCUPIED;
        }

        board_[board_index] = players_[current_player_].value;

        num_turns_++;
        current_player_++;
        current_player_ %= kNumPlayers;
        return TttResult::SUCCESS;
    }

    int TicTacToe::turnCount()
    {
        return num_turns_;
    }

} // end of namespace ttt

