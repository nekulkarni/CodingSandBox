class Student(object):

    def __init__(self, name, age):
        self.name = name
        self.age = age
        self.cgpa = 0

    def setCGPA(cgpa):
        self.cgpa = cpga


class Teacher(object):

    def __init__(self, name, coursesTought):
        self.name = name
        self.coursesTought = coursesTought


class Class(object):

    def __init__(self, name):
        self.name = name
        self.students = []

    def addStudents(self, newStudent):
        self.students = self.students + newStudent;

    def setTeacher(self, teacher):
        self.teacher = teacher

    def printInfo(self):
        print '## Class ' + self.name + ' ##'
        print ' Class-Teacher: ' + self.teacher.name
        print ' Students: '
        print [x.name for x in self.students]

classKKHH = Class('FY BA')
classKKHH.addStudents([Student('Rahul', '21'), Student('Anjali', '20')])
classKKHH.setTeacher(Teacher('Ms. Brigenza', 'Romantic Literature'))
classKKHH.printInfo()

