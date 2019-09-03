## @file DCapALst.py
#  @author janzej2
#  @brief A module which defines the abstract data type for various departments
#  @date 02/10/19

# from StdntAllocTypes import *


## @brief This class represents an abstract data type of department capacities.
#  @details Initialising this object creates a new tuple used to store departments
#  and their relevant capacities.
class DCapALst:
    s = []
    ## @brief Initialises an empty tuple.
    @staticmethod
    def init():
        DCapALst.s = []

    ## @brief Adds a department and its capacity to the DCapALst.
    #  @param d Represents a department of type DeptT.
    #  @param n Represents the capacity of that department.
    @staticmethod
    def add(d, n):
        for dept in DCapALst.s:
            if dept[0] == d:
                raise KeyError
        DCapALst.s.append([d, n])

    ## @brief Removes a given department from the DCapALst.
    #  @param d Represents the DeptT to remove from the list.
    @staticmethod
    def remove(d):
        removed = False
        for dept in DCapALst.s:
            if dept[0] == d:
                DCapALst.s.remove(dept)
                removed = True
        if not removed:
            raise KeyError

    ## @brief Checks if a given department is already in the list.
    #  @param d Represents the DeptT to check for in the list.
    #  @return Returns a boolean value representing whether the
    #   department is in the list.
    @staticmethod
    def elm(d):
        for dept in DCapALst.s:
            if dept[0] == d:
                return True
        return False

    ## @brief Checks the capacity of a given department.
    #  @param d Represents the DeptT to check.
    #  @return Returns the capacity of the given department if
    #   it is in the list.
    @staticmethod
    def capacity(d):
        for dept in DCapALst.s:
            if dept[0] == d:
                return dept[1]
        raise KeyError
