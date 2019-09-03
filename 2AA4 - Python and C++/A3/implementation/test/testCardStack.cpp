#include "../catch/catch.h"

#include "../include/CardStack.h"
#include "../include/CardTypes.h"
#include "../include/Stack.h"

#include <vector>
#include <stdexcept>
#include <iostream>

TEST_CASE( "tests for CardStack", "[CardStack]"){

    std::vector<CardT> empty_vec;
    Stack<CardT> test_stack;

    std::vector<CardT> deck;
    int i;
    for (RankT rank = ACE; rank <= KING; rank++) {
        for (unsigned int suit = 0; suit < 4; suit++) {
        CardT n = { static_cast<SuitT>(suit), rank };
        
        deck.push_back(n);
        deck.push_back(n);
            }
    }

    CardT c;
    int st = 0;
    int rk = 9;
    SuitT suit = (SuitT)st;
    RankT rank = (RankT)rk;
    c.s = suit;
    c.r = rank;

    Stack<CardT> base_stack;
    Stack<CardT> push_stack = base_stack.push(c);

    std::vector<CardT> c_vec(2,c);

    Stack<CardT> new_stack(c_vec);
    Stack<CardT> pop_stack = new_stack.pop();
    CardT top_of_stack = new_stack.top();

    Stack<CardT> deck_stack(deck);

    SECTION("default constructor for Stack"){
        REQUIRE(test_stack.toSeq().size() == empty_vec.size());
    }

    SECTION("base constructor for Stack"){
        REQUIRE(deck_stack.toSeq().size() == deck.size());
    }

    SECTION("push for Stack"){
        REQUIRE(push_stack.size() == base_stack.size() + 1);
    }

    SECTION("pop for Stack"){
        REQUIRE(pop_stack.size() == new_stack.size() - 1);
    }

    SECTION("exception for pop for Stack"){
        REQUIRE_THROWS_AS(test_stack.pop(), std::out_of_range);
    }

    SECTION("top for Stack"){
        bool rank;
        rank = (top_of_stack.r == c.r);
        bool suit;
        suit = (top_of_stack.s == c.s);
        bool rank_and_suit;
        rank_and_suit = rank&&suit;
        REQUIRE(rank_and_suit);
    }

    SECTION("exception for top for Stack"){
        REQUIRE_THROWS_AS(test_stack.top(), std::out_of_range);
    }

    SECTION("size for Stack"){
        REQUIRE(new_stack.size() == 2);
    }

    SECTION("toSeq for Stack"){
        REQUIRE(test_stack.toSeq().size() == empty_vec.size());
    }

}