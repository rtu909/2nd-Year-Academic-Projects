## @file StdntAllocTypes.py
#  @title StdntAllocTypes
#  @author Raymond Tu
#  @date 11/02/2019
from SeqADT import *
from enum import Enum
from typing import NamedTuple


## @brief This class represents the gender type enum.
#  @details This class has num values for male and female.
class GenT(Enum):
    male = 0
    female = 1


## @brief This class represents the department type enum.
#  @details This class has num values for 7 engineering departments.
class DeptT(Enum):
    civil = 1
    chemical = 2
    electrical = 3
    mechanical = 3
    software = 4
    materials = 5
    engphys = 6


## @brief This class represents the student info of type named tuple.
#  @details This class has fields that denote information for a student
#  including first name, gender, GPA, program choices and free choice.
class SInfoT(NamedTuple):
    fname: str
    lname: str
    gender: GenT
    gpa: float
    choices: SeqADT
    freechoice: bool
