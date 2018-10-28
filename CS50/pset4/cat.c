// using fgetc with loop, we can read all the characters from a file and print them to the terminal. This is the same as the command "cat" in linux

char ch;
while ((ch = fgetc(file)) != EOF) // EOF is end of file character, if it's not the end of file, keep going
    printf("%c", ch);

char ch;
while ((ch = fgetc(file0)) != EOF) // EOF is end of file character, if it's not the end of file, keep going
    fputc(ch, file1);  // instead of printing to the console. We read the character then write it to a different file. This is the "cp" linux command