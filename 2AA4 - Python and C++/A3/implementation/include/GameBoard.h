/**
 * \file GameBoard.h
 * \author Raymond Tu <tur1@mcmaster.ca>
 * \brief Provides an ADT representing a model for the game of FreeCell
 *   including board state and its transitions. Contains
 *   the state variables for the gameboard as well as
 *   the transitions that contain the moves on the gameboard,
 *   accessors and functions to maintain the state invariants.
 */
//Collaborated with Lucia Cristiano and Jonathan Janzen
#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include "CardTypes.h"
#include "CardStack.h"
#include <vector>

typedef std::vector<CardStackT> SeqCrdStckT;

/**
 * \brief Represents the state of a 40 Thieves game.
 * \details The piles of cards are represented with Stack data type
 *    CardStackT. The state variables tableau and foundation are a
 *    sequence of CardStackT, while the deck and waste are a single 
 *    CardStackT object. Does not provide a UI but manages
 *    the state of the game, including card moves and whether they are
 *    valid, as well to ensure the state invariants of the game
 *    are not broken.
 */
class BoardT {
  private:
    SeqCrdStckT T;
    SeqCrdStckT F;
    CardStackT D;
    CardStackT W;

    SeqCrdStckT init_seq(unsigned int n);
    SeqCrdStckT tab_deck(std::vector<CardT> deck);
    bool two_decks(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W);
    unsigned int cnt_cards_seq(SeqCrdStckT S, CardT c2);
    unsigned int cnt_cards_stack(CardStackT s, CardT c2);
    unsigned int cnt_cards(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W, CardT c2);
    bool is_valid_pos(CategoryT c, unsigned n);
    bool valid_tab_tab(unsigned int n_0, unsigned int n_1);
    bool valid_tab_foundation(unsigned int n_0, unsigned int n_1);
    bool valid_waste_tab(unsigned int n);
    bool valid_waste_foundation(unsigned int n);
    bool tab_placeable(CardT c, CardT d);
    bool foundation_placeable(CardT c, CardT d);
  
  public:
    /**
     * \brief Constructs the board.
     * \param deck Vector of 104 cards to initialize the state variables.
     * \throws invalid_argument when the constructor is given
     *    an invalid deck to intialize the game with. This is when
     *    there are not 2 deck of cards in the deck parameter.
     */
    BoardT(std::vector<CardT> deck);

    /**
     * \brief Checks if a move from the tableau is valid.
     * \param c The type of state variable the card is moving to.
     * \param n_0 The index of the source tableau stack for the card.
     * \param n_1 The index of the destination foundation stack.
     * \throws out_of_range when when either the source or destination index
     *    are out of range and violate state invariant ([0..9] for tableau and
     *    [0..7] for foundation).
     * \return False if c is of type deck or waste. True if it is a valid move.
     */
    bool is_valid_tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1);

    /**
     * \brief Checks if a move from the waste is valid.
     * \param c The type of state variable the card is moving to.
     * \param n The index of the tableau/foundation stack destination.
     * \throws invalid_argument when the waste is empty because you can't move from
     *    an empty stack.
     * \throws out_of_range if index n is out of range of the state invariant
     *    for foundation or tableau.
     * \return False if c is of type deck or waste. True if it is a valid move.
     */
    bool is_valid_waste_mv(CategoryT c, unsigned int n);
    
    /**
     * \brief Checks if a move from the deck is valid.
     * \return False if the deck is empty. True if the size of the deck
     *    is greater than 0.
     */
    bool is_valid_deck_mv();

    /**
     * \brief Moves a card from the tableau to foundation.
     * \param c The type of state variable the card is moving to.
     * \param n_0 The index of the source tableau stack for the card.
     * \param n_1 The index of the destination foundation stack.
     * \throws invalid_argument if the requested move is not valid 
     *    (destination is deck or waste).
     */
    void tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1);

    /**
     * \brief Moves a card from the waste to tableau or foundation.
     * \param c The type of state variable the card is moving to.
     * \param n_1 The index of the destination tableau/foundation stack.
     * \throws invalid_argument if the requested move is not valid 
     *    (destination is deck or waste).
     */
    void waste_mv(CategoryT c, unsigned int n);
    
    /**
     * \brief Moves a card from deck to waste.
     * \throws invalid_argument if the requested move is not valid
     *    (the deck is empty).
     */
    void deck_mv();

    /**
     * \brief Getter for the tableau state variable.
     * \param i The index of tableau stack to access.
     * \throws out_of_range if the index is not within the range of 0..9
     * \return the CardStackT at the given index of the tableau.
     */
    CardStackT get_tab(unsigned int i);

    /**
     * \brief Getter for the foundation state variable.
     * \param i The index of foundation stack to access.
     * \throws out_of_range if the index is not within the range of 0..7
     * \return the CardStackT at the given index of the foundation.
     */
    CardStackT get_foundation(unsigned int i);

    /**
     * \brief Getter for the deck state variable.
     * \return the CardStackT of the deck.
     */
    CardStackT get_deck();

    /**
     * \brief Getter for the waste state variable.
     * \return the CardStackT of the waste.
     */
    CardStackT get_waste();

    /**
     * \brief Checks if a valid move exists in the state of the gameboard,
     *    by checking if there is a valid deck, waste or tableau move to make.
     * \return False if no valid move exists, true if there is a move that can be made.
     */
    bool valid_mv_exists();

    /**
     * \brief Checks if the gameboard has reached a winstate, when all the foundation stacks are properly filled.
     * \return False if the gameboard has not reached a winstate, True if the gameboard
     *    has reached a win state.
     */
    bool is_win_state();
};

#endif
