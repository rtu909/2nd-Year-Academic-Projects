## @file DCapALst.py
#  @title DCapALst
#  @author Raymond Tu
#  @date 11/02/2019
import collections


## @brief This class represents the list of department capacities.
#  @details This class holds the departments in engineering and their capacities.
class DCapALst:

    s = set()

    ## @brief Constructor for DCapALst.
    #  @details Constructor initializes the set.
    @staticmethod
    def init():
        DCapALst.s = set()
    ## @brief Adds department to set of department capacities.
    #  @details Takes in the department as well as it's capacity.
    #  @param d being the engineering department.
    #  @param n being the capacity of the department.
    @staticmethod
    def add(d, n):
        for tuple in DCapALst.s:
            if tuple.deptT == d:
                raise KeyError

        newTuple = collections.namedtuple('newTuple', ['deptT', 'cap'])
        addtuple = newTuple(d, n)

        DCapALst.s.add(addtuple)

    ## @brief Removes department from set of department capacities.
    #  @details Takes in the department to remove.
    #  @param d being the engineering department.
    @staticmethod
    def remove(d):
        for tuple in DCapALst.s:
            if tuple.deptT == d:
                DCapALst.s.remove(tuple)
                return
        raise KeyError

    ## @brief Checks if the department is in the set.
    #  @details Takes in the department.
    #  @param d being the engineering department.
    #  @return Returns a boolean, True if the department is in the set, false otherwise.
    @staticmethod
    def elm(d):
        for tuple in DCapALst.s:
            if tuple.deptT == d:
                return True
    ## @brief Checks the department capacity.
    #  @details Takes in the department and checks capacity.
    #  @param d being the engineering department.
    #  @return Returns the capacity of the passed in department.
    @staticmethod
    def capacity(d):
        for tuple in DCapALst.s:
            if tuple.deptT == d:
                return tuple.cap
        raise KeyError
