from StdntAllocTypes import *
from SeqADT import *
from DCapALst import *
from AALst import *
from SALst import *

DCapALst.init()
DCapALst.add(DeptT.civil, 2)

print(DCapALst.s)

sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.civil, DeptT.chemical]), True)
sinfo2 = SInfoT("first", "last", GenT.male, 6.0, SeqADT([DeptT.civil, DeptT.chemical]), True)

SALst.init()
SALst.add("stdnt1", sinfo1)
SALst.add("stdnt2", sinfo2)

print(SALst.elm("stdnt1"))
print("\n")
print(SALst.s)
print("\n")

print(SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0))

print(SALst.average(lambda x: x.gender == GenT.male))

AALst.init()

print(AALst.s)
SALst.allocate()
print(AALst.lst_alloc(DeptT.civil))
