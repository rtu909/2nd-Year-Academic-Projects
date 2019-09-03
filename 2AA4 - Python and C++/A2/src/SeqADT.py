## @file SeqADT.py
#  @title SeqADT
#  @author Raymond Tu
#  @date 11/02/2019

## @brief This class represents a generic abstract object.
#  @details This class iterates through a sequence of generic type T.


class SeqADT:

    ## @brief Constructor for SeqADT.
    #  @details Constructor accepts x, making it equal to sequence s,
    #  initializes integer i.
    #  @param x being the object passed into SeqADT, of any generic type.
    def __init__(self, x):
        self.s = x
        self.i = 0

    ## @brief Initializes integer i to 0.
    def start(self):
        self.i = 0

    ## @brief Iterates sequences SeqADT.
    #  @details Iterates the index i to the next value in the sequence.
    #  @return Returns the value at s[i].
    def next(self):
        if (self.i > len(self.s)) or (self.i == len(self.s)):
            raise StopIteration

        self.i = self.i + 1
        return self.s[self.i - 1]

    ## @brief Checks if at end of sequence s.
    #  @details Checks whether index has reached end of sequence.
    #  @return Returns boolean for whether the end of the list is reached.
    def end(self):
        return (self.i >= len(self.s) - 1)
