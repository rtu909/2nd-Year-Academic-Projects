#include "../catch/catch.h"

#include "../include/CardStack.h"
#include "../include/CardTypes.h"
#include "../include/GameBoard.h"
#include "../include/Stack.h"

#include <vector>
#include <stdexcept>
#include <iostream>

TEST_CASE("tests for BoardT", "[BoardT]"){

    std::vector<CardT> d;
    int i;
    for (RankT rank = KING; rank >= ACE; rank--) {
        for (unsigned int suit = 0; suit < 4; suit++) {
        CardT n = { static_cast<SuitT>(suit), rank };
        
        d.push_back(n);
        d.push_back(n);
        }
    }

    BoardT board(d);

    for (unsigned int i = 0; i < 10; i++){
    //std::cout << "Tableau Stack " << i << "\n";
    for (int j = 0; j < 4; j++){
      std::vector<CardT> mini_stack = board.get_tab(i).toSeq();
      //std::cout << mini_stack[j].s << " " << mini_stack[j].r << "\n";
    }
    }
    
    //std::random_shuffle(d.begin(), d.end());

    bool tab_size;
    bool found_size;
    bool deck_size;
    bool waste_size;
    bool correct_board;
    tab_size = board.get_tab(0).size() == 4;
    //std::cout << board.get_tab(1).size() << "\n";
    found_size = board.get_foundation(0).size() == 0;
    //std::cout << board.get_foundation(0).size() << "\n";
    deck_size = board.get_deck().size() == 64;
    //std::cout << board.get_deck().size() << "\n";
    waste_size = board.get_waste().size() == 0;
    //std::cout << board.get_waste().size() << "\n";
    CardStackT empty_crd_stck;

    correct_board = tab_size && found_size && deck_size && waste_size;

    //board.deck_mv();

    //std::cout << board.get_waste().top().s << " " << board.get_waste().top().r << "\n";

    /*int st = 0;
        int rk = 0;
        SuitT suit = (SuitT)st;
        RankT rank = (RankT)rk;
        */
    SECTION("constructor for BoardT"){
        REQUIRE(correct_board);
    }

    SECTION("checks if tableau to tableau move is valid when sizes equal"){
        CategoryT c = Tableau;
        //both initialized stacks in tableau should both be size 4
        bool tab_to_tab = board.is_valid_tab_mv(c, 0, 1);
        REQUIRE(!tab_to_tab);
    }

    SECTION("checks if tableau to tableau move is valid when sizes equal"){
        CategoryT c = Tableau;
        //both initialized stacks in tableau should both be size 4
        bool tab_to_tab = board.is_valid_tab_mv(c, 2, 0);
        REQUIRE(tab_to_tab);
    }

    SECTION("checks if exception throws for invalid tableau position"){
        CategoryT c = Tableau;
        
        REQUIRE_THROWS_AS(board.is_valid_tab_mv(c, 12, 12), std::out_of_range);
    }

    SECTION("checks if tableau to foundation move is valid when sizes equal"){
        CategoryT c = Foundation;
        //both initialized stacks in tableau should both be size 4
        bool tab_to_found = board.is_valid_tab_mv(c, 2, 0);
        REQUIRE(!tab_to_found);
    }

    SECTION("checks if tableau to deck move is invalid"){
        CategoryT c = Deck;
        //both initialized stacks in tableau should both be size 4
        bool tab_to_deck = board.is_valid_tab_mv(c, 2, 0);
        REQUIRE(!tab_to_deck);
    }

    SECTION("checks if tableau to waste move is invalid"){
        CategoryT c = Waste;
        //both initialized stacks in tableau should both be size 4
        bool tab_to_waste = board.is_valid_tab_mv(c, 2, 0);
        REQUIRE(!tab_to_waste);
    }


    SECTION("checks if the empty waste move is invalid"){
        CategoryT c = Tableau;
        REQUIRE(!board.is_valid_waste_mv(c, 0));
    }

    SECTION("checks if the foundation waste move is valid"){
        CategoryT c = Foundation;
        board.deck_mv();
        //should work because first card from deck to waste is an ACE
        REQUIRE(board.is_valid_waste_mv(c, 0));
    }

    SECTION("checks if the waste to deck waste move is invalid"){
        CategoryT c = Deck;
        REQUIRE(!board.is_valid_waste_mv(c, 0));
    }

    SECTION("checks if the waste to waste move is invalid"){
        CategoryT c = Waste;
        REQUIRE(!board.is_valid_waste_mv(c, 0));
    }

    SECTION("checks if the out of range move raises exception for tableau"){
        CategoryT c = Tableau;
        board.deck_mv();
        unsigned int n = 12;
        REQUIRE_THROWS_AS(board.is_valid_waste_mv(c, n), std::out_of_range);
    }

    SECTION("checks if the out of range move raises exception for foundation"){
        CategoryT c = Foundation;
        board.deck_mv();
        unsigned int n = 12;
        REQUIRE_THROWS_AS(board.is_valid_waste_mv(c, n), std::out_of_range);
    }

    
    SECTION("checks if the deck move is valid"){
        REQUIRE(board.is_valid_deck_mv());
    }

    SECTION("checks if the deck move is invalid when empty"){
        for (int i = 0; i < 64; i++){
            board.deck_mv();
        }
        REQUIRE(!board.is_valid_deck_mv());
    }

    
    SECTION("tab move tableau base case"){
        CategoryT c = Tableau;
        board.tab_mv(c, 2, 0);
        bool n_0size;
        bool n_1size;
        n_0size = (board.get_tab(2).size() == 3);
        n_1size = (board.get_tab(0).size() == 5);
        bool test = n_0size && n_1size;
        REQUIRE(test);
    }

    SECTION("tab move foundation base case"){
        std::vector<CardT> deck;
        int i;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
            CardT g = { static_cast<SuitT>(suit), rank };
            
            deck.push_back(g);
            deck.push_back(g);
            }
        }

        BoardT board1(deck);

        CategoryT c = Foundation;
        board1.tab_mv(c, 0, 0);
        bool n_0size;
        bool n_1size;
        n_0size = (board1.get_tab(0).size() == 3);
        n_1size = (board1.get_foundation(0).size() == 1);
        bool test = n_0size && n_1size;
        REQUIRE(test);
    }

    SECTION("tab move tableau base case"){
        CategoryT c = Tableau;
        REQUIRE_THROWS_AS(board.tab_mv(c, 0, 0), std::invalid_argument);
    }

    SECTION("waste move foundation base case"){
        CategoryT c = Foundation;
        board.deck_mv();
        board.waste_mv(c, 0);
        bool n_0size;
        bool n_1size;
        n_0size = (board.get_waste().size() == 0);
        n_1size = (board.get_foundation(0).size() == 1);
        bool test = n_0size && n_1size;
        REQUIRE(test);
    }

    SECTION("waste move exception case"){
        CategoryT c = Foundation;
        REQUIRE_THROWS_AS(board.waste_mv(c,0), std::invalid_argument);
    }

    
    SECTION("deck move base case"){
        board.deck_mv();
        bool d_size = board.get_deck().size() == 63;
        bool w_size = board.get_waste().size() == 1;
        bool test = d_size && w_size;
        REQUIRE(test);
    }

    SECTION("deck move exception case"){
        for (int i = 0; i < 64; i++){
            board.deck_mv();
        }
        REQUIRE_THROWS_AS(board.deck_mv(), std::invalid_argument);
    }

    
    SECTION("tableau getter base case"){
        bool test = (board.get_tab(0).top().s == 1) && (board.get_tab(0).top().r == 13);
        REQUIRE(test);
    }

    SECTION("tableau getter exception case"){
        REQUIRE_THROWS_AS(board.get_tab(13), std::out_of_range);
    }

    
    SECTION("foundation getter base case"){
        bool test = (board.get_foundation(0).size() == 0);
        REQUIRE(test);
    }

    SECTION("foundation getter exception case"){
        REQUIRE_THROWS_AS(board.get_foundation(13), std::out_of_range);
    }

    
    SECTION("deck getter"){
        bool test = board.get_deck().size() == 64;
        REQUIRE(test);
    }

    SECTION("waste getter"){
        bool test = board.get_waste().size() == 0;
        REQUIRE(test);
    }

    SECTION("check if a valid move exists"){
        REQUIRE(board.valid_mv_exists());
    }

    SECTION("check if the board has reached a win state"){
        REQUIRE(!board.is_win_state());
    }
}