

//structures in C are similar to objects in other languages

struct car //define a new car structure. put this at the top of the program or a seperate file using .h and #include
{
    int year;  // these are fields or members
    char model[10];
    char plate[10];
    int odometer;
    double engine_size;
};

struct car mycar; //variable declaration, similar to int x. this is static, on the stack

// field accessing by using dot operator
mycar.year = 2011;
mycar.plate = "CS50";
mycar.odometer = 50505;


struct car *mycar = malloc(sizeof(struct car)); //this is dynamic, on the heap

// field accessing by dereferencing first * then dot operator
(*mycar).year = 2011;
(*mycar).plate =  "CS50";

// field accessing using arrow operator. the arrow combines dereferencing and dot operator
mycar->year = 2011;
mycar->plate = "CS50";

// using typedef to make your code more readable and succint

typedef oldname newname;

typedef struct car car_t; // after you define struct car up top, from now on you can use car_t instead of struct car whenever you need to refer to it

typedef char* string; // cs50.h do this to hide the fact that a string is a char pointer to make it easier to use

typedef struct car //can even typedef as you define a new structure
{
    int year;  // these are fields or members
    char model[10];
    char plate[10];
    int odometer;
    double engine_size;
}
car_t; //give it the name you want

car_t mycar; //variable declaration, using the new name instead of struct car, more readable and succint

// field accessing by using dot operator
mycar.year = 2011;
mycar.plate = "CS50";






































