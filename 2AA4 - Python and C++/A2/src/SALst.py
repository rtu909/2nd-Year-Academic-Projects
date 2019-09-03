## @file SALst.py
#  @title SALst
#  @author Raymond Tu
#  @date 11/02/2019
from StdntAllocTypes import *
from AALst import *
from DCapALst import *
import collections


## @brief This class represents the list of students and their information.
#  @details This class holds the list of all students to be allocated and their info.
class SALst:
    ## @brief Initializes the set of students.
    #  @details Initializes the set of students that will contain their information.
    @staticmethod
    def init():
        SALst.s = set()

    ## @brief Adds student to list of students.
    #  @details Takes in the macid and student information.
    #  @param m being the macid.
    #  @param i being the tuple of student information.
    @staticmethod
    def add(m, i):
        for tuple in SALst.s:
            if tuple.macid == m:
                raise KeyError
        StudentT = collections.namedtuple('StudentT', ['macid', 'info'])
        new_stdnt = StudentT(m, i)
        SALst.s.add(new_stdnt)
    ## @brief Removes student from list of students.
    #  @details Takes in the macid of the student to be removed.
    #  @param m being the macid.
    @staticmethod
    def remove(m):
        for tuple in SALst.s:
            if tuple.macid == m:
                SALst.s.remove(tuple)
                return
        raise KeyError

    ## @brief Checks if student is in the list of students.
    #  @details Takes in macid and checks if they've been added.
    #  @param m being the macid.
    #  @return True Returns boolean for whether student has been added.
    @staticmethod
    def elm(m):
        for tuple in SALst.s:
            if tuple.macid == m:
                return True
    ## @brief Gives the information for the passed in student.
    #  @details Returns information of student associated with macid.
    #  @param m being the macid.
    #  @return info Returns the information of the macid.
    @staticmethod
    def info(m):
        for tuple in SALst.s:
            if tuple.macid == m:
                return tuple.info
        raise ValueError

    # Worked with Lucia Cristiano and Charles Zhang
    ## @brief Sorts the list of students by GPA in descending order.
    #  @details Takes in parameters and sorts students in descending order.
    #  @param f Lambda function to determine which students are sorted.
    #  @return L Returns list of sorted students.
    @staticmethod
    def sort(f):
        li = []
        for tuple in SALst.s:
            if f(tuple.info):
                li.append(tuple.macid)

        macid = 0
        next_macid = 0
        for macid in range(len(li)):
            for next_macid in range(0, (len(li)) - next_macid - 1):
                if SALst.__get_gpa(li[next_macid], SALst.s) < SALst.__get_gpa(li[next_macid + 1], SALst.s):
                    tmp = li[next_macid]
                    li[next_macid] = li[next_macid + 1]
                    li[next_macid + 1] = tmp

        return li

    # Worked with Lucia Cristiano and Charles Zhang
    ## @brief Computes the average GPA of all students.
    #  @details Returns average GPA of all students in list.
    #  @param f Being the lambda function that determines which students to average.
    #  @return avg Returns the average of the students.
    @staticmethod
    def average(f):
        fset = [x[1] for x in SALst.s if f(x[1])]
        if fset == []:
            raise ValueError
        print(fset)
        fset_sum = 0
        for sinfo in fset:
            fset_sum = fset_sum + sinfo[3]
        return fset_sum / (len(fset))

    ## @brief Allocates the students into the AALst.
    #  @details Allocates the students into the AALst based on gpa and freechoice.
    @staticmethod
    def allocate():
        AALst.init()
        f = SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0)
        for m in f:
            ch = SALst.info(m).choices
            AALst.add_stdnt(ch.next(), m)
        s = SALst.sort(lambda t: (not t.freechoice) and t.gpa >= 4.0)
        for m in s:
            ch = SALst.info(m).choices
            alloc = False
            while (not alloc) and (not ch.end()):
                d = ch.next()
                if AALst.num_alloc(d) < DCapALst.capacity(d):
                    AALst.add_stdnt(d, m)
                    alloc = True
            if not alloc:
                raise RuntimeError

    @staticmethod
    def __get_gpa(m, s):
        for tuple in s:
            if tuple.macid == m:
                return tuple.info.gpa
