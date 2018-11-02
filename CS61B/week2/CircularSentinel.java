//circular sentinel is a special sentinel
//it has 2 pointers
//when the list is empty, aka when the sentinel is by itself, the prev pointer points to the sentinel node itself,
//and the next pointer also points to the sentinel itself. AKA they contain the same memory address when the list is empty

//when the list is populated, the next pointer obviously points to the next node and the prev pointer points to the
//previous node.

//at last node however, the next pointer of the last node points back to the sentinel instead of carrying the usual null value.

//the prev pointer of sentinel points to the last node of the list