#include "../catch/catch.h"

#include "../include/CellType.h"
#include "../include/GameBoard.h"

#include <vector>
#include <stdexcept>
#include <iostream>

TEST_CASE( "tests for GameBoard", "[Board]"){
    Board board("./data/input.txt");

    SECTION("constructor for Board"){
        REQUIRE(board.get_board().size() == 30);
    }

    SECTION("next generation"){
        board.next_gen();
        REQUIRE(board.get_board()[6][13].live_state);
    }

}