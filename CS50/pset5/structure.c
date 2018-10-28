#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <structure.h>

int main(void)
{
    // allocate space for students
    int enrollment = get_ints("enrollment: ");
    student students[enrollment]; // creat an array name student

    // prompt for students' names and dorms
    for (int i = 0; i < enrollment; i++)
    {
        students[i].name = get_string("name: ");
        students[i].dorm = get_string("dorm: ");
    }

   // save students to disk
   FILE *file = fopen("students.csv", "w");
   if (file) //if file was successfully opened
   {
       for (int i = 0; i < student; i++)
       {
           fprintf(file, "%s,%s\n", students[i].name, student[i].dorm) // file printf using the comma between %s and %s to creat a csv file, comma separated value
       }
       fclose(file);
   }


}