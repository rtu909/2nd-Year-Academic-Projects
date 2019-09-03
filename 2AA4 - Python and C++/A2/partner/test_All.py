import pytest
from SeqADT import *
from DCapALst import *
from SALst import *
from AALst import *


class TestAll:

    # SeqADT tests
    def test_seqadt_init(self):
        new_seq = SeqADT([0, 1, 2, 3])
        assert new_seq.s == [0, 1, 2, 3]

    def test_seqadt_start(self):
        new_seq = SeqADT([])
        new_seq.start()
        assert new_seq.i == 0

    def test_seqadt_next_base(self):
        new_seq = SeqADT([0, 1, 2, 3])
        index = new_seq.next()
        assert index == 0

    def test_seqadt_next_excep(self):
        new_seq = SeqADT([])
        with pytest.raises(StopIteration):
            index = new_seq.next()

    def test_seqadt_end(self):
        new_seq = SeqADT([0, 1, 2, 3])
        new_seq.next()
        new_seq.next()
        new_seq.next()
        end_bool = new_seq.end()
        assert end_bool is True

    # DCapALst tests
    def test_dcapalst_init(self):
        DCapALst.init()
        empty_set = set()
        assert DCapALst.s == empty_set

    def test_dcapalst_add_base(self):
        DCapALst.init()
        DCapALst.add(DeptT.civil, 2)
        print(DCapALst.s)
        for tuple in DCapALst.s:
            dep = tuple.deptT
            cap = tuple.cap
        assert (dep == DeptT.civil) and (cap == 2)

    def test_dcapalst_add_excep(self):
        DCapALst.init()
        DCapALst.add(DeptT.civil, 2)
        with pytest.raises(KeyError):
            DCapALst.add(DeptT.civil, 2)

    def test_dcapalst_remove_base(self):
        DCapALst.init()
        DCapALst.add(DeptT.civil, 2)
        DCapALst.remove(DeptT.civil)
        empty_set = set()
        assert DCapALst.s == empty_set

    def test_dcapalst_remove_excep(self):
        DCapALst.init()
        print(DCapALst.s)
        with pytest.raises(KeyError):
            DCapALst.remove(DeptT.civil)

    def test_dcapalst_elm(self):
        DCapALst.init()
        DCapALst.add(DeptT.civil, 2)
        assert DCapALst.elm(DeptT.civil) is True

    def test_dcapalst_capacity_base(self):
        DCapALst.init()
        DCapALst.add(DeptT.civil, 2)
        assert DCapALst.capacity(DeptT.civil) == 2

    def test_dcapalst_capacity_excep(self):
        DCapALst.init()
        with pytest.raises(KeyError):
            DCapALst.capacity(DeptT.civil)

    # SALst test cases

    def test_salst_init(self):
        SALst.init()
        empty_set = set()
        assert SALst.s == empty_set

    def test_salst_add_base(self):
        SALst.init()
        sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.chemical]), True)
        SALst.add("stdnt1", sinfo1)
        for stdnt in SALst.s:
            gender = stdnt[1].gender
            gpa = stdnt[1].gpa
        assert (gender == GenT.male) and (gpa == 12.0)

    def test_salst_add_excep(self):
        SALst.init()
        sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.chemical]), True)
        SALst.add("stdnt1", sinfo1)
        with pytest.raises(KeyError):
            SALst.add("stdnt1", sinfo1)

    def test_salst_remove_base(self):
        SALst.init()
        sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.chemical]), True)
        SALst.add("stdnt1", sinfo1)
        SALst.remove("stdnt1")
        empty_set = set()
        assert SALst.s == empty_set

    def test_salst_remove_excep(self):
        SALst.init()
        with pytest.raises(KeyError):
            SALst.remove("stdnt1")

    def test_salst_elm(self):
        SALst.init()
        sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.chemical]), True)
        SALst.add("stdnt1", sinfo1)
        assert SALst.elm("stdnt1") is True

    def test_salst_info_base(self):
        SALst.init()
        sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.chemical]), True)
        SALst.add("stdnt1", sinfo1)
        assert SALst.info("stdnt1") == sinfo1

    def test_salst_info_excep(self):
        SALst.init()
        with pytest.raises(ValueError):
            SALst.info("stdnt1")

    def test_salst_average_base(self):
        SALst.init()
        sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.civil]), True)
        SALst.add("stdnt1", sinfo1)
        avg = SALst.average(lambda x: x.gender == GenT.male)
        assert avg == 12.0

    def test_salst_average_excep(self):
        SALst.init()
        with pytest.raises(ValueError):
            SALst.average(lambda x: x.gender == GenT.male)

    def test_salst_sort(self):
        SALst.init()
        sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.chemical]), True)
        SALst.add("stdnt1", sinfo1)
        sort_list = SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0)
        assert sort_list == ['stdnt1']

    def test_salst_allocate(self):
        SALst.init()
        sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.civil]), True)
        SALst.add("stdnt1", sinfo1)
        AALst.init()
        SALst.allocate()
        alloc = AALst.lst_alloc(DeptT.civil)
        assert alloc == ['stdnt1']
