## @file SALst.py
#  @author janzej2
#  @brief A module which defines the behvaiour of the Student Association List.
#  @date 02/11/19
#  shared ideas with Ahmed Al Koasmh and David Thompson

from StdntAllocTypes import *
from AALst import *
from DCapALst import *


## @brief A class representing the data type SALst.
#  @details This module contains function for initialising a new list,
#  adding a student to the list (given their MacID and student information),
#  removing a student from the list, determining if a student is in the list
#  by MacID, returning a student's student information by MacID, sorting a
#  group of students by a given f, taking the average of a set of students
#  based on a condition f, and a function to allocate students to their programs.
class SALst:

    s = []

    ## @brief Initialises the empty student allocation list.
    def init():
        SALst.s = []

    ## @brief Adds a student to the student allocation list.
    #  @param m A string representing the student's MacID.
    #  @param i A SInfoT object representing a student's info.
    @staticmethod
    def add(m, i):
        for element in SALst.s:
            if element[0] == m:
                raise KeyError
        SALst.s.append([m, i])

    ## @brief Removes a student from the student allocation list.
    #  @param m A string representing a student's MacID.
    @staticmethod
    def remove(m):
        removed = False
        for element in SALst.s:
            if element[0] == m:
                SALst.s.remove(element)
                removed = True
        if not removed:
            raise KeyError

    ## @brief Determines if a student is an element of the list.
    #  @param m A string representing a student's MacID.
    #  @return True if the student is in the list, and false otherwise.
    @staticmethod
    def elm(m):
        for element in SALst.s:
            if element[0] == m:
                return True
        return False

    ## @brief Checks a student's MacID and returns their student information.
    #  @param m A string representing a student's MacID.
    #  @return The student's information as type SInfoT.
    @staticmethod
    def info(m):
        for element in SALst.s:
            if element[0] == m:
                return element[1]
        raise KeyError

    ## @brief Sorts the SALst based on parameters given through f.
    #  @param f Represents a function to determine the method of sorting
    #  @return Returns a list of MacIDs ordered based on the input condition.
    @staticmethod
    def sort(f):
        sorted_list = sorted(SALst.s, key=lambda i: i[1].gpa, reverse=True)
        return [item[0] for item in sorted_list if f(item[1])]

    ## @brief Returns the average of a group of students based on the input criteria.
    #  @param f Represents a function to filter based on.
    #  @return Returns the average of the students that match the given criteria.
    @staticmethod
    def average(f):
        avg_list = [item[1].gpa for item in SALst.s if f(item[1])]
        if len(avg_list) == 0:
            raise ValueError
        sum = 0
        for item in avg_list:
            sum += item
        return sum / len(avg_list)

    ## @brief Allocates students based on their student information.
    #  @details Creates a list of freechoice students first, allocating
    #  them to their first choice program. Then, the function sorts the student
    #  list by GPAs >= 4.0, and allocates them to their first, second or third
    #  choice programs based on remaining space.
    @staticmethod
    def allocate():
        AALst.init()
        f = SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0)
        for m in f:
            ch = SALst.info(m).choices
            AALst.add_stdnt(ch.next(), m)

        s = SALst.sort(lambda l: not l.freechoice and l.gpa >= 4.0)
        for m in s:
            ch = SALst.info(m).choices
            alloc = False
            while not alloc and not ch.end():
                d = ch.next()
                if AALst.num_alloc(d) < DCapALst.capacity(d):
                    AALst.add_stdnt(d, m)
                    alloc = True
            if not alloc:
                raise RuntimeError
