// hash table conbines indexing of array and dynamic of linked list. This greatly speed up insertion, deletion and search
// use hash table when you don't need the data to be sorted or else you drop that speed down to linked link level
// hash table combines two things:
    //first, a hash function, which returns a nonnegative integer value called a hash code
    //second, an array capable of storing the data type we want
// run your data through the hash function, it returns a number, put that data in that array[number] location. If you need to insert, delete or search,
// run that data through the has function again to get its location, and you can do whatever you want with it

// what is a good hash function? it use only and all of the data being hashed, be deterministic (always get the same location number from the same data),
//uniformly distribute data and generate very different hash codes for very similar data

//example
unsigned int hash(char* str)
{
    int sum = 0;
    for (int j = 0; str[j] != '\0'; j++) //when hit end of string
    {
        sum += str[j]; //sum up all ascii values
    }
    return sum % HASH_MAX; //return the mod sum of some array
}

// usually no reason to write your own hash functions. Use one from the interweb, cite your source

// a collision occurs when two pieces of data, yield the same hash code. Solve with linear probing, we try to place the data in the next consecutive element in the array.
// this creates a problem called clustering. Where elements placements are further and further away from the hash value. This is where the linked list comes in. We use chaining.
// if each element of the array is a pointer to the head of a linked list, then multiple pieces of data can yield the same hash code and we can store it all.