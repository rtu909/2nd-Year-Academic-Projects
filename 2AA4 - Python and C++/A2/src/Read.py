## @file Read.py
#  @title Read
#  @author Raymond Tu
#  @date 11/02/2019
from StdntAllocTypes import *
from DCapALst import *
from SALst import *


## @brief Reads textfile of students and puts them into the list of students.
#  @details Takes formatted student list and converts them to list of student tuples.
#  @param s The passed in textfile.
def load_stdnt_data(s):
    SALst.init()
    file = open(s, 'r')
    lines = file.readlines()

    for line in lines:
        info_list = line.split(', ', 5)

        # get list of choices
        choice_split = info_list[-1].split('], ')
        choice_split1 = choice_split[0].split('[')
        choices_str = choice_split1[1]
        choices = choices_str.split(', ')

        f_c = True
        # convert true false to bool
        if choice_split[1] == 'True':
            f_c = True
        elif choice_split[1] == 'False':
            f_c = False

        for choice in choices:
            if choice == 'civil':
                choice = DeptT.civil
            elif choice == 'chemical':
                choice = DeptT.chemical
            elif choice == 'electrical':
                choice = DeptT.electrical
            elif choice == 'mechanical':
                choice = DeptT.mechanical
            elif choice == 'software':
                choice = DeptT.software
            elif choice == 'materials':
                choice = DeptT.materials
            elif choice == 'engphys':
                choice = DeptT.engphys

        choices = SeqADT(choices)

        if info_list[3] == 'male':
            info_list[3] = GenT.male
        if info_list[3] == 'female':
            info_list[3] == GenT.female
        info_list[4] = float(info_list[4])
        sinfo = SInfoT(info_list[1], info_list[2], info_list[3], info_list[4], choices, f_c)
        SALst.add(info_list[0], sinfo)


## @brief Reads textfile of departments and puts them into the list of departments.
#  @details Takes list of departments and converts them to list of department tuples.
#  @param s The passed in textfile.
def load_dcap_data(s):
    DCapALst.init()
    file = open(s, 'r')
    lines = file.readlines()
    for line in lines:
        dept_list = line.split(', ')

        if dept_list[0] == 'civil':
            dept_list[0] = DeptT.civil
        elif dept_list[0] == 'chemical':
            dept_list[0] = DeptT.chemical
        elif dept_list[0] == 'electrical':
            dept_list[0] = DeptT.electrical
        elif dept_list[0] == 'mechanical':
            dept_list[0] = DeptT.mechanical
        elif dept_list[0] == 'software':
            dept_list[0] = DeptT.software
        elif dept_list[0] == 'materials':
            dept_list[0] = DeptT.materials
        elif dept_list[0] == 'engphys':
            dept_list[0] = DeptT.engphys

        dept_list[1] = int(dept_list[1])
        DCapALst.add(dept_list[0], dept_list[1])
