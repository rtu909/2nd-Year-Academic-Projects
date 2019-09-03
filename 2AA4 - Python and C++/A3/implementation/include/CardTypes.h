/**
 * \file CardTypes.h
 * \author Raymond Tu <tur1@mcmaster.ca>
 * \brief File that contains the exported types of the module
 *    including the the ranks of the cards, suits and structures 
 *    that define the cards with these state variables
 */
#ifndef A3_CARD_TYPES_H_
#define A3_CARD_TYPES_H_

/**
 * \brief Describes the rank of a card.
 */
typedef unsigned short int RankT;

/**
 * \brief RankT for an Ace.
 */
#define ACE    1

/**
 * \brief RankT for an Jack.
 */
#define JACK   11

/**
 * \brief RankT for a Queen.
 */
#define QUEEN  12

/**
 * \brief RankT for a King.
 */
#define KING   13

/**
* Variable for total number of cards
*/
#define TOTAL_CARDS 104

/**
* Exported Types
*/
enum SuitT {Heart, Diamond, Club, Spade};
enum CategoryT {Tableau, Foundation, Deck, Waste};

struct CardT {
  SuitT s;
  RankT r;
};

#endif
