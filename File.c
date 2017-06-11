#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <ctype.h>



struct termios saved_attributes;

void reset_input_mode (void)
{
    tcsetattr (STDIN_FILENO, TCSANOW, &saved_attributes);
}

void set_input_mode (void)
{
    struct termios tattr;
    char *name;
    
    
    if (!isatty (STDIN_FILENO))
    {
        fprintf (stderr, "Not a terminal.\n");
        exit (EXIT_FAILURE);
    }
    
   
    tcgetattr (STDIN_FILENO, &saved_attributes);
    atexit (reset_input_mode);
    
 
    tcgetattr (STDIN_FILENO, &tattr);
    tattr.c_lflag &= ~(ICANON | ECHO);
    tattr.c_cc[VMIN] = 1;
    tattr.c_cc[VTIME] = 0;
    tcsetattr (STDIN_FILENO, TCSAFLUSH, &tattr);
}

void setEchoOn(void) {
    struct termios tattr;
    char *name;
    
    
    if (!isatty (STDIN_FILENO))
    {
        fprintf (stderr, "Not a terminal.\n");
        exit (EXIT_FAILURE);
    }
    
    
    tcgetattr (STDIN_FILENO, &saved_attributes);
    //atexit (reset_input_mode);
    
    fprintf(stdout, "%lu",saved_attributes.c_lflag);
    tcgetattr (STDIN_FILENO, &tattr);
    tattr.c_lflag &= (ICANON | ECHO);
    tattr.c_cc[VMIN] = 1;
    tattr.c_cc[VTIME] = 0;
    tcsetattr (STDIN_FILENO, TCSANOW, &tattr);
}

void setEchoOff(void) {
    
    struct termios tattr;
    char *name;
    
    
    if (!isatty (STDIN_FILENO))
    {
        fprintf (stderr, "Not a terminal.\n");
        exit (EXIT_FAILURE);
    }
    
    
    tcgetattr (STDIN_FILENO, &saved_attributes);
    fprintf(stdout, "%lu",saved_attributes.c_lflag);
    
    
    tcgetattr (STDIN_FILENO, &tattr);
    tattr.c_lflag &= ~(ICANON | ECHO);
    tattr.c_cc[VMIN] = 1;
    tattr.c_cc[VTIME] = 0;
    tcsetattr (STDIN_FILENO, TCSAFLUSH, &tattr);
}

int isEchoOn(void) {
    return 1;
}

int main ()
{
    int i = 0;
    char c, password[100], asterisk = '*';
    
    
    setEchoOn();
    
    while (read (STDIN_FILENO, &c, 1) && (isalnum (c) || ispunct (c))
           && i < sizeof (password) - 2)
    {
        password[i++] = c;
        //write (STDOUT_FILENO, &asterisk, 1);
    }
    
    password[i] = 0;
    
    printf ("\nPassword was: [%s]\n", password);
    
    return EXIT_SUCCESS;
}
