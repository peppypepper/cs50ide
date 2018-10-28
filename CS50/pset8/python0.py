import cs50


x = 54

phrase = "this is a test"

if y < 2 or k == 23:
    # code goes here
elif:
    # more code
else:
    # more code

letters_only = True if input().isalpha() else False

# while and for loop, no more do while loop
counter = 0
while counter < 100:
    print(counter) # python automatically add new line \n
    counter += 1 # counter++ doesn't work

for x in range(0, 100, 2): # start point, end point, increment by 2, this counter from 0 to 98
    print(x)

# arrays are lists in python, lists are dynamic
nums = [] or nums = list() # an empty list
nums = [1,2,3,4]
nums = [x for x in range(100)] # a list comprehension, this creates a list of 100 numbers from 0 to 99
nums.append(5) #add 5 to the end of list nums
nums.insert(4, 5) #add 5 to the 4th position of list nums, remember to count from 0, so this line results in [1,2,3,4,5]
nums[len(nums):] = [5] #splicing, attaching one list to end of another list. in this case Im adding list [5] to the end of nums

#tuples are ordered, immutable sets of data, great for associating collections of data, similar to a struct in C
presidents = [     # a list of tuples
    ("GW", 1789),  # parantheses indicate tuples
    ("JA", 1797),
    ("TJ", 1801)
]

for prez, year in presidents:  #list is iterable, prez, year match up with how the tuples are formatted
    print("In {1}, {0} took office.".format(prez, year))


# dictionaries, similar to a hash table in C, key: value pairs
pizzas = {
    "cheese": 9,
    "pepperoni": 10,
    "buffalo chicken": 11
}

pizzas["cheese"] = 8 # change key value
if pizza["pepperoni"] < 12:  #use key in boolean expression
    # do something
pizzas["bacon"] = 14 # add a new key:value pair

#use for loop to iterate through a dictionary, even though the dictionary is not indexed
for pie in pizzas: # pie becomes all the keys
    print(pie) # print out all the keys

for pie, price in pizzas.items():  # .items() method turns pizzas into a list temporarily, so we can iterate over and print the "value" aka price
    print(price)

for pie, price in pizza.items():
    print("A whole {} pizza will cost ${}".format(pie, price)) # print both key and value

    print("A whole " + pie + " pizza will cost $" + str(price))  # does the same thing using concatination

# define a function
def square(x):
    return x**2

# objects have methods and properties, use class keyword to create a type of object
# classes require an initialization function which sets the starting values of the properties of the object
# in defining each method of an object, self should be its first parameter, which stipulates on what object the method is called
funtion(object) # can't do this
object.method() # call methods on objects

class Student():  #start a new class Student with 3 methods

    def __int__(self, name, id):  #constructor method/function, student will have 2 properties
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














