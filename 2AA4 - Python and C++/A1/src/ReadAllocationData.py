## @file ReadAllocationData.py
#  @brief Module that contains the functions readStdnts(s), readFreeChoice(s), and readDeptCapacity(s). All 3 take in a given .txt file to generate the desired output into a list or a dictionary.
#  @author Raymond Tu	 
#  @date 2019-01-18

## @brief Takes in a text file to create a list of student dictionaries.
#  @details Creates a list of student dictionaries where each entry in the list is one student, with all their details such as macid, first and last name, gpa as well as their first, second and third choice of program.
#  @param s A string for the name of the text file that contains student information on every line, in order of macid, name, gender, gpa and program choice respectively.
#  @return A list of student dictionaries generated from the passed in text file.
def readStdnts(s):

	file = open(s, 'r')
	lines = file.readlines()

	std_list = []

	for line in lines:
		
		print(line)
		print(line.split())
		split_list = line.split()

		std_dict = {'macid': 's', 'fname': 's', 'lname': 's', 'gender': 's', 'gpa': 's', 'choices': 's'}
		std_dict['macid'] = split_list[0]
		std_dict['fname'] = split_list[1]
		std_dict['lname'] = split_list[2]
		std_dict['gender'] = split_list[3]
		std_dict['gpa'] = split_list[4]
		choice_list = []
		choice_list.append(split_list[5])
		choice_list.append(split_list[6])
		choice_list.append(split_list[7])
		std_dict['choices'] = choice_list
		
		std_list.append(std_dict)
		
	for std in std_list:
		print(std)
	
	print(std_list)
			
	file.close()
	
	return std_list

#test.txt used to test readStdnts

#readStdnts("test.txt")

## @brief Takes in a text file to create a list of macids for students with free choice.
#  @details Takes in a text file where every line is a macid of a student with free choice and creates a list out of them where each entry is a macid.
#  @param s A string for the name of the text file that the macids for students with free choice.
#  @return A list of mac ids of students with free choice.
def readFreeChoice(s):


	file = open(s, 'r')
	content = open(s, 'r').read()


	print(content)

	free_choice = content.split()

	print(free_choice)

	file.close()

	return free_choice

#test1.txt used to test readFreeChoice
#readFreeChoice("test1.txt")

## @brief Takes in a text file to create a dictionary of department capacities.
#  @details Creates a list of student dictionaries from a text file where every line is the department followed by the number of spots in their respective department. The function takes this file and creates a dictionary out of this, where each key corresponds to a department.
#  @param s A string for the name of a text file that contains a department followed by it's capacity on every line.
#  @return A dictionary of department capacities generated from text file of string s.
def readDeptCapacity(s):

	file = open(r'C:\Users\Raymond\Documents\2AA4\tur1\A1\src\test2.txt', 'r')
	lines = file.readlines()

	dept_dict = {'civil': 'i', 'chemical': 'i', 'electrical': 'i', 'mechanical': 'i', 'software': 'i', 'materials': 'i', 'engphys': 'i'}

	counter = 0 

	for line in lines:
		dept = line.split()
		
		if counter == 0:
			dept_dict['civil'] = dept[1]
		elif counter == 1:
			dept_dict['chemical'] = dept[1]
		elif counter == 2:
			dept_dict['electrical'] = dept[1]
		elif counter == 3:
			dept_dict['mechanical'] = dept[1]
		elif counter == 4:
			dept_dict['software'] = dept[1]
		elif counter == 5:
			dept_dict['materials'] = dept[1]
		elif counter == 6:
			dept_dict['engphys'] = dept[1]
		
		counter = counter + 1
		
	print(dept_dict)
			
	return dept_dict

#test2.txt used to test readDeptCapacity
#readDeptCapacity("test2.txt")


		
	


