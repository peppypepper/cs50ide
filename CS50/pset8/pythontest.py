class Student():  #start a new class Student with 3 methods
    def __init__(self, name, id):  #constructor method/function, student will have 2 properties
        self.name = name
        self.id = id

    def changeID(self, id):
        self.id = id

    def print(self):  # self parameter is required for every method even though that method takes no parameter
        print("{} - {}".format(self.name, self.id))

jane = Student("Jane", 10)
jane.print()
jane.changeID(11)
jane.print()

kane = Student("Kane", 120)
kane.print()
kane.changeID(101)
kane.print()