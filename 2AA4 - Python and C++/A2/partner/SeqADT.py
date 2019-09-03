## @file SeqADT.py
#  @author janzej2
#  @brief Implementation of an abstract data type for a sequence.
#  @date 02/11/19


## @brief This class represents an abstract data type of type sequence.
#  @details This class represents a sequence initialised with a list s and a count
#  variable i.
class SeqADT:

    ## @brief Constructor for SeqADT
    #  @details Constructor accepts one parameter consisting of a list of a type T
    #   and initialises its parameter i to 0.
    #  @param s List containing a specific data type.
    def __init__(self, s):
        self.__s = s
        self.__i = 0

    ## @brief Initialiser for i variable, resetting it to its original 0 value.
    def start(self):
        self.__i = 0

    ## @brief Function to iterate through the sequence and return the most recent value.
    #  @return Returns the i-th element before it is incremented.
    def next(self):
        if self.end():
            raise StopIteration
        self.__i += 1
        return self.__s[self.__i - 1]

    ## @brief Function to determine if the end of the sequence has been reached.
    #  @return Returns True if the function has reached the end, or False otherwise.
    def end(self):
        if self.__i >= len(self.__s):
            return True
        return False
