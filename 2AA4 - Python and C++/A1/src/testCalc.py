## @file testCalc.py
#  @title testCalc
#  @author Raymond Tu
#  @date 2019-01-18

## @brief This module is for testing the functions in CalcModule.py.

import CalcModule

#Test case 1 for sort(S)

##First test case for sort(S) function
#First test case is a base case with regular GPA values and arbitrary macid
S_test1 = [{'macid': 'frank1', 'fname': 'frank', 'lname': 'jill', 'gender':
'male', 'gpa': 8.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'bob1', 'fname': 'bob', 'lname': 'jill', 'gender':
'male', 'gpa': 11.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'raymond', 'lname': 'tu', 'gender':
'male', 'gpa': 10.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'jill1', 'fname': 'jill', 'lname': 'jill', 'gender':
'male', 'gpa': 9.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'sally', 'fname': 'sally', 'lname': 'jill', 'gender':
'male', 'gpa': 7.0, 'choices': ['chemical', 'mechanical', 'software']}]

##First expected output for sort(S) function
#Students sorted by GPA in descended order
expected_output1 = [{'macid': 'bob1', 'fname': 'bob', 'lname': 'jill', 'gender': 
'male', 'gpa': 11.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'raymond', 'lname': 'tu', 'gender': 
'male', 'gpa': 10.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'jill1', 'fname': 'jill', 'lname': 'jill', 'gender': 
'male', 'gpa': 9.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'frank1', 'fname': 'frank', 'lname': 'jill', 'gender': 
'male', 'gpa': 8.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'sally', 'fname': 'sally', 'lname': 'jill', 'gender': 
'male', 'gpa': 7.0, 'choices': ['chemical', 'mechanical', 'software']}]
##Output of first test case
output = CalcModule.sort(S_test1)

#print(output)

if output == expected_output1:
	print("Test case 1 for sort(S) passed")
else:
	print("Test case 1 failed for sort(S)")

#Test case 2 for sort(S)
#Test case created to test how it sorts with multiple entries students with the same GPA, as well how it handles the boundary
#case with 0s and 1s
S_test2 = [{'macid': 'frank1', 'fname': 'frank', 'lname': 'jill', 'gender':
'male', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'bob1', 'fname': 'bob', 'lname': 'jill', 'gender':
'male', 'gpa': 1.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'raymond', 'lname': 'tu', 'gender':
'male', 'gpa': 1.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'jill1', 'fname': 'jill', 'lname': 'jill', 'gender':
'male', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'sally', 'fname': 'sally', 'lname': 'jill', 'gender':
'male', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}]

expected_output2 = [{'macid': 'bob1', 'fname': 'bob', 'lname': 'jill', 'gender': 
'male', 'gpa': 1.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'raymond', 'lname': 'tu', 'gender': 
'male', 'gpa': 1.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'frank1', 'fname': 'frank', 'lname': 'jill', 'gender': 
'male', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'jill1', 'fname': 'jill', 'lname': 'jill', 'gender': 
'male', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'sally', 'fname': 'sally', 'lname': 'jill', 'gender': 
'male', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}]


output2 = CalcModule.sort(S_test2)

#print(output2)

if output2 == expected_output2:
	print("Test case 2 for sort(S) passed")
else:
	print("Test case 2 failed for sort(S)")
	

#Test case 3 for sort(S)
#Test case created with empty list, boundary case
S_test12 = []

expected_output12 = []

output12 = CalcModule.sort(S_test12)

#print(output12)

if output12 == expected_output12:
	print("Test case 3 for sort(S) passed")
else:
	print("Test case 3 failed for sort(S)")
	
#Test case 1 for average(L, g) for male
#Regular base test case, with males, females, GPA within range of 12-0
A_test1 = [{'macid': 'tur1', 'fname': 'bob', 'lname': 'bobbert', 'gender':
'male', 'gpa': 12.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'jill', 'lname': 'jillian', 'gender':
'female', 'gpa': 10.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'bob', 'lname': 'jill', 'gender':
'male', 'gpa': 9.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'sally', 'lname': 'jill', 'gender':
'female', 'gpa': 2.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'rob', 'lname': 'jill', 'gender':
'male', 'gpa': 7.0, 'choices': ['chemical', 'mechanical', 'software']}]

#Calculated average by hand
expected_output3 = 9.3

output3 = CalcModule.average(A_test1, 'male')


if output3 == expected_output3:
	print("Test case 1 for average(L, g) for male passed")
else:
	print("Test case 1 for average(L, g) for male failed")

#Test case 1 for average(L, g) for female
#Same test case but with g as female instead
A_test2 = [{'macid': 'tur1', 'fname': 'bob', 'lname': 'bobbert', 'gender':
'male', 'gpa': 12.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'jill', 'lname': 'jillian', 'gender':
'female', 'gpa': 10.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'bob', 'lname': 'jill', 'gender':
'male', 'gpa': 9.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'sally', 'lname': 'jill', 'gender':
'female', 'gpa': 2.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'rob', 'lname': 'jill', 'gender':
'male', 'gpa': 7.0, 'choices': ['chemical', 'mechanical', 'software']}]

expected_output4 = 6.0

output4 = CalcModule.average(A_test2, 'female')


if output4 == expected_output4:
	print("Test case 1 for average(L, g) for female passed")
else:
	print("Test case 1 for average(L, g) for female failed")

#Test case 2 for average(L, g) for male
#boundary test case with duplicates and 1s and 0s to see if there are any discrepancy in handling lower boundary inputs
A_test3 = [{'macid': 'tur1', 'fname': 'bob', 'lname': 'bobbert', 'gender':
'male', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'jill', 'lname': 'jillian', 'gender':
'female', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'bob', 'lname': 'jill', 'gender':
'male', 'gpa': 1.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'sally', 'lname': 'jill', 'gender':
'female', 'gpa': 1.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'rob', 'lname': 'jill', 'gender':
'male', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}]

#Calculated average
expected_output5 = 0.3

output5 = CalcModule.average(A_test3, 'male')


if output5 == expected_output5:
	print("Test case 2 for average(L, g) for male passed")
else:
	print("Test case 2 for average(L, g) for male failed")

#Test case 2 for average(L, g) for female
#Same test base but with g as female instead
A_test4 = [{'macid': 'tur1', 'fname': 'bob', 'lname': 'bobbert', 'gender':
'male', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'jill', 'lname': 'jillian', 'gender':
'female', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'bob', 'lname': 'jill', 'gender':
'male', 'gpa': 1.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'sally', 'lname': 'jill', 'gender':
'female', 'gpa': 1.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'rob', 'lname': 'jill', 'gender':
'male', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}]

expected_output6 = 0.5

output6 = CalcModule.average(A_test4, 'female')


if output6 == expected_output6:
	print("Test case 2 for average(L, g) for female passed")
else:
	print("Test case 2 for average(L, g) for female failed")

#Test case 3 for average(L, g) for male
#boundary test case with empty list
A_test5 = []

#Calculated average
expected_output10 = 0

output10 = CalcModule.average(A_test5, 'male')

#print(output10)


if output10 == expected_output10:
	print("Test case 3 for average(L, g) for male passed")
else:
	print("Test case 3 for average(L, g) for male failed")
	

#Test case 4 for average(L, g) for female
#Boundary test case where all GPA is 0
A_test6 = [{'macid': 'tur1', 'fname': 'bob', 'lname': 'bobbert', 'gender':
'male', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'jill', 'lname': 'jillian', 'gender':
'female', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'bob', 'lname': 'jill', 'gender':
'male', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'sally', 'lname': 'jill', 'gender':
'female', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'tur1', 'fname': 'rob', 'lname': 'jill', 'gender':
'male', 'gpa': 0.0, 'choices': ['chemical', 'mechanical', 'software']}]

expected_output16 = 0.0

output16 = CalcModule.average(A_test6, 'female')


if output16 == expected_output16:
	print("Test case 4 for average(L, g) for female passed")
else:
	print("Test case 4 for average(L, g) for female failed")	




#Test case 1 for allocate
#Base test case, with free choice students, reasonable department capacity
Allocate_test1 = [{'macid': 'bob1', 'fname': 'bob', 'lname': 'bobbert', 'gender':
'male', 'gpa': 12.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'jill1', 'fname': 'jill', 'lname': 'jillian', 'gender':
'female', 'gpa': 10.0, 'choices': ['civil', 'engphys', 'software']}, {'macid': 'bob2', 'fname': 'bob', 'lname': 'jill', 'gender':
'male', 'gpa': 9.0, 'choices': ['engphys', 'mechanical', 'software']}, {'macid': 'sally1', 'fname': 'sally', 'lname': 'jill', 'gender':
'female', 'gpa': 2.0, 'choices': ['chemical', 'mechanical', 'civil']}, {'macid': 'rob1', 'fname': 'rob', 'lname': 'jill', 'gender':
'male', 'gpa': 7.0, 'choices': ['civil', 'mechanical', 'software']}]

free_choice = ['bob1', 'bob2', 'rob1']

dept_cap = { 'civil': 1, 'chemical': 2, 'electrical': 0, 'mechanical': 3,  'software': 3, 'materials': 1,  'engphys': 2} 

allocated_list = CalcModule.allocate(Allocate_test1, free_choice, dept_cap)

#print(allocated_list)

expected_output7 = {'civil': [{'macid': 'rob1', 'fname': 'rob', 'lname': 'jill', 'gender':
 'male', 'gpa': 7.0, 'choices': ['civil', 'mechanical', 'software']}], 'chemical': [{'macid': 'bob1', 'fname': 'bob', 'lname': 'bobbert', 'gender':
 'male', 'gpa': 12.0, 'choices': ['chemical', 'mechanical', 'software']}], 'electrical': [],
 'mechanical': [], 'software': [], 'materials': [], 'engphys': [{'macid': 'bob2', 'fname': 'bob', 'lname': 'jill', 'gender':
 'male','gpa': 9.0, 'choices': ['engphys', 'mechanical', 'software']}, {'macid': 'jill1', 'fname': 'jill', 'lname': 'jillian', 'gender':
 'female', 'gpa': 10.0, 'choices': ['civil', 'engphys', 'software']}]}

output7 = CalcModule.allocate(Allocate_test1, free_choice, dept_cap)

if output7 == expected_output7:
	print("Test case 1 for allocate(S, F, C) passed")
else:
	print("Test case 1 for allocate(S, F, C) failed")
	

#Test case 2 for allocate
#Empty list boundary case
	
Allocate_test2 = []

free_choice1 = []

dept_cap1 = { 'civil': 1, 'chemical': 2, 'electrical': 0, 'mechanical': 3,  'software': 3, 'materials': 1,  'engphys': 2} 

allocated_list1 = CalcModule.allocate(Allocate_test2, free_choice1, dept_cap1)

#print(allocated_list1)

expected_output8 = {'civil': [], 'chemical': [], 'electrical': [], 'mechanical': [], 'software': [], 'materials': [], 'engphys': []}

output8 = CalcModule.allocate(Allocate_test2, free_choice1, dept_cap1)

if output8 == expected_output8:
	print("Test case 2 for allocate(S, F, C) passed")
else:
	print("Test case 2 for allocate(S, F, C) failed")

#Test case 3 for allocate
#Boundary test case, no free choice students and no department capacity
Allocate_test3 = [{'macid': 'bob1', 'fname': 'bob', 'lname': 'bobbert', 'gender':
'male', 'gpa': 12.0, 'choices': ['chemical', 'mechanical', 'software']}, {'macid': 'jill1', 'fname': 'jill', 'lname': 'jillian', 'gender':
'female', 'gpa': 10.0, 'choices': ['civil', 'engphys', 'software']}, {'macid': 'bob2', 'fname': 'bob', 'lname': 'jill', 'gender':
'male', 'gpa': 9.0, 'choices': ['engphys', 'mechanical', 'software']}, {'macid': 'sally1', 'fname': 'sally', 'lname': 'jill', 'gender':
'female', 'gpa': 2.0, 'choices': ['chemical', 'mechanical', 'civil']}, {'macid': 'rob1', 'fname': 'rob', 'lname': 'jill', 'gender':
'male', 'gpa': 7.0, 'choices': ['civil', 'mechanical', 'software']}]

free_choice3 = []

dept_cap3 = { 'civil': 0, 'chemical': 0, 'electrical': 0, 'mechanical': 0,  'software': 0, 'materials': 0,  'engphys': 0} 

allocated_list3 = CalcModule.allocate(Allocate_test3, free_choice3, dept_cap3)

#print(allocated_list3)


#all depts full and no free choice, shouldn't allocate anyone
expected_output9 = {'civil': [], 'chemical': [], 'electrical': [], 'mechanical': [], 'software': [], 'materials': [], 'engphys': []}

output9 = CalcModule.allocate(Allocate_test3, free_choice3, dept_cap3)

if output9 == expected_output9:
	print("Test case 3 for allocate(S, F, C) passed")
else:
	print("Test case 3 for allocate(S, F, C) failed")

#Test case 4 for allocate
#Test case with assumption that if students with free choice have first choice that exceeds dept capacity, they all are enrolled regardless
Allocate_test4 = [{'macid': 'bob1', 'fname': 'bob', 'lname': 'bobbert', 'gender':
'male', 'gpa': 12.0, 'choices': ['civil', 'mechanical', 'software']}, {'macid': 'jill1', 'fname': 'jill', 'lname': 'jillian', 'gender':
'female', 'gpa': 10.0, 'choices': ['civil', 'engphys', 'software']}, {'macid': 'bob2', 'fname': 'bob', 'lname': 'jill', 'gender':
'male', 'gpa': 9.0, 'choices': ['civil', 'mechanical', 'software']}, {'macid': 'sally1', 'fname': 'sally', 'lname': 'jill', 'gender':
'female', 'gpa': 2.0, 'choices': ['chemical', 'mechanical', 'civil']}, {'macid': 'rob1', 'fname': 'rob', 'lname': 'jill', 'gender':
'male', 'gpa': 7.0, 'choices': ['civil', 'mechanical', 'software']}]

free_choice4 = ['bob1', 'jill1', 'bob2', 'rob1']

#4 free choice students with civil as first choice but only 2 spots
dept_cap4 = { 'civil': 2, 'chemical': 0, 'electrical': 0, 'mechanical': 0,  'software': 0, 'materials': 0,  'engphys': 0} 

expected_output19 = {'civil': [{'macid': 'bob1', 'fname': 'bob', 'lname': 'bobbert', 'gender':
'male', 'gpa': 12.0, 'choices': ['civil', 'mechanical', 'software']}, {'macid': 'jill1', 'fname': 'jill', 'lname': 'jillian', 'gender':
'female', 'gpa': 10.0, 'choices': ['civil', 'engphys', 'software']}, {'macid': 'bob2', 'fname': 'bob', 'lname': 'jill', 'gender':
'male', 'gpa': 9.0, 'choices': ['civil', 'mechanical', 'software']}, {'macid': 'rob1', 'fname': 'rob', 'lname': 'jill', 'gender':
'male', 'gpa': 7.0, 'choices': ['civil', 'mechanical', 'software']}], 'chemical': [], 'electrical': [], 'mechanical': [], 'software': [], 'materials': [], 'engphys': []}

output19 = CalcModule.allocate(Allocate_test4, free_choice4, dept_cap4)

#print(output19)

if output19 == expected_output19:
	print("Test case 4 for allocate(S, F, C) passed")
else:
	print("Test case 4 for allocate(S, F, C) failed")

	
	


