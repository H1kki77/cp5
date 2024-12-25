
#ifndef FUNCTION_H
#define FUNCTION_H
void print_array(char **array, int size, char *prompt)
{
    printf("%s", prompt);
    for (int i = 0; i < size; i++)
    {
        printf("String #%d ->%s\n", i+1, array[i]);
    }
}
#endif //FUNCTION_H
