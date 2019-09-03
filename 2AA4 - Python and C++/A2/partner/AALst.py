## @file AALst.py
#  @title AALst
#  @author Raymond Tu
#  @date 11/02/2019
from StdntAllocTypes import *

## @brief This class represents the allocated list of students.
#  @details This class holds the list of students who are allocated for second year.


class AALst:

    s = []

    ## @brief Constructor for AALst.
    #  @details Constructor initializes the sequence with all departments,
    #  the set is of AllocAssocListT.
    @staticmethod
    def init():
        AALst.s = [{d: []} for d in DeptT]

    ## @brief Adds student to sequence of AllocAssocListT.
    #  @details Takes in the deptT as well as the string for student.
    #  @param dep being the department of the student.
    #  @param m being the string that represents the student.
    @staticmethod
    def add_stdnt(dep, m):
        for tuple in AALst.s:
            for d in tuple:
                if d == dep:
                    tuple[d].append(m)
    ## @brief Goes through list of allocated students and returns their macid.
    #  @details Takes in the department and returns sequence of students enrolled.
    #  @param d represents the department name.
    #  @return Returns list of students macids enrolled in that department.
    @staticmethod
    def lst_alloc(d):
        for tuple in AALst.s:
            for key in tuple:
                if key == d:
                    return tuple[key]
    ## @brief Goes through list of allocated students and returns number of students enrolled.
    #  @details Takes in the department and returns number of students enrolled.
    #  @param d represents the department name.
    #  @return Returns number of students macids enrolled in that department.
    @staticmethod
    def num_alloc(d):
        for tuple in AALst.s:
            for key in tuple:
                if key == d:
                    return len(tuple[key])
