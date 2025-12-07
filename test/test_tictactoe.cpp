#include <gtest/gtest.h>

#include <tictactoe.h>

TEST(ttt, init_ttt)
{
    ttt::TicTacToe ttt;

    EXPECT_TRUE(ttt.current_player_ == 0);
    EXPECT_EQ(ttt.board_[0], 0);
    EXPECT_EQ(ttt.turnCount(), 0);
}

TEST(ttt, first_turn)
{
    ttt::TicTacToe ttt;
    int p1_val = 1;
    int p2_val = 2;

    ttt.players_[0].value = p1_val;
    ttt.players_[1].value = p2_val;

    ttt::TttResult result = ttt.handleTurn(0);

    EXPECT_EQ(ttt.board_[0], p1_val);
    EXPECT_EQ(result, ttt::TttResult::SUCCESS);
    EXPECT_EQ(ttt.turnCount(), 1);
}

TEST(ttt, second_turn)
{
    ttt::TicTacToe ttt;
    int p1_val = 1;
    int p2_val = 2;

    ttt.players_[0].value = p1_val;
    ttt.players_[1].value = p2_val;

    EXPECT_EQ(ttt.current_player_, 0);

    ttt::TttResult result = ttt.handleTurn(1);

    EXPECT_EQ(ttt.current_player_, 1);
    EXPECT_EQ(ttt.board_[1], p1_val);
    EXPECT_EQ(result, ttt::TttResult::SUCCESS);

    result = ttt.handleTurn(2);

    EXPECT_EQ(ttt.current_player_, 0);
    EXPECT_EQ(ttt.board_[2], p2_val);
    EXPECT_EQ(result, ttt::TttResult::SUCCESS);
}

TEST(ttt, index_out_of_range)
{
    ttt::TicTacToe ttt;

    ttt.players_[0].value = 1;
    ttt.players_[1].value = 2;

    ttt::TttResult result = ttt.handleTurn(9);

    EXPECT_EQ(result, ttt::TttResult::INDEX_OUT_OF_RANGE);
}

TEST(ttt, third_turn)
{
    ttt::TicTacToe ttt;
    int p1_val = 1;
    int p2_val = 2;

    ttt.players_[0].value = p1_val;
    ttt.players_[1].value = p2_val;

    ttt::TttResult result = ttt.handleTurn(1);

    EXPECT_EQ(ttt.board_[1], p1_val);
    EXPECT_EQ(result, ttt::TttResult::SUCCESS);

    result = ttt.handleTurn(2);

    EXPECT_EQ(ttt.board_[2], p2_val);
    EXPECT_EQ(result, ttt::TttResult::SUCCESS);
}
