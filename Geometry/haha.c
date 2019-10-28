#include<stdio.h>
#include<string.h>

char keyword[32][12] =
{
    "if","int","long","register","return","short","signed",
    "auto","break","case","char","const","continue","default",
    "do","double","else","enum","extern","float","for","goto",
    "sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"
};

char builtin_function[39][12]=
{
    "strcpy","strncpy","strcmp","strncmp","strlen","strcat","strncat",
    "strchr","strrchr","strstr","strtok","calloc","free","malloc","realloc",
    "memcpy","memcmp","memchr","memset","memmov",
    "isalnum","isalpha","iscntrl","isdigit","isgraphic","islower","isprint",
    "ispunct","isspace","isupper","isxdigit","tolower","toupper",
    "perror","*strerror","printf","scanf","main","iostream"
};

struct for_key
{
    char nam[12];
    int frequ;
} keys_list[32];

struct for_var
{
    char variable_list[100];
    int freq;
} var[505];


struct for_function
{
    char nam[100];
    int freq;
} fun[505];

int check_variable(char now_variable[])
{
    int length = strlen(now_variable);
    if(now_variable[0]>='0' && now_variable[0]<='9')
        return 0;
    else
        return 1;
}

FILE *file_input;
int operator_arr[205];
int tot_keyword, tot_variable, inx_variable,tot_function,inx_function;

int check_key(char now[])
{
    int i;
    for(i = 0; i<32; i++)
    {
        if(strcmp(keyword[i],now)==0)
            return 1;
    }
    return 0;
}

int check_fucntion(char now[])
{
    int i;
    for(i = 0; i<39; i++)
    {
        if(strcmp(builtin_function[i],now)==0)
            return 1;
    }
    return 0;
}
int neww(char character, int j)
{
    if((character==' ' || character=='\n' || character =='(') && j)
        return 1;
    else return 0;
}
int special(char now[])
{
    if(strcmp("stdio",now) == 0 ||strcmp("iostream",now) == 0 || strcmp("include",now) == 0)
        return 1;
    else
        return 0;
}
void analysis()
{
    tot_keyword = 0;
    tot_variable = 0;
    inx_variable = 0;
    tot_function = 0;
    inx_function = 0;

    char character, temporary[205];

    int j = 0;

    while((character=fgetc(file_input))!=EOF)
    {
        operator_arr[character]++;

        if(isalnum(character) || character=='_')
            temporary[j++] = character;

      else if(neww(character,j))
        {
            temporary[j] = '\0';
            j = 0;
            if(special(temporary))
                continue;
            if(check_key(temporary))
            {
                tot_keyword++;
                int id;
                for(id = 0; id < 32; id++)
                {
                    if(strcmp(keys_list[id].nam,temporary)==0)
                    {
                        keys_list[id].frequ++;
                        break;
                    }
                }
            }
            else if(character == '(' && check_fucntion(temporary))
            {
                tot_function++;
                int id,f = 0;
                for(id = 0; id < 39; id++)
                {
                    if(strcmp(fun[id].nam,temporary)==0)
                    {
                        fun[id].freq++;
                        f = 1;
                        break;
                    }
                }
            }
            else if(check_variable(temporary))
            {
                tot_variable++;
                int flag = 1;
                int id;
                for(id = 0; id < inx_variable; id++)
                {
                    if(strcmp(temporary,var[id].variable_list)==0)
                    {
                        var[id].freq++;
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                {
                    strcpy(var[inx_variable].variable_list,temporary);
                    var[id].freq++;
                    inx_variable++;
                }
            }
        }
    }
}

void output()
{
    int i, x = 0;
    printf("                                      Keywords\n");
    printf("                                  .................\n");
    printf("Keywords found: %d\n", tot_keyword);

    printf("   Times             Keywords\n");
    printf("............         ...........\n");
    for(i = 0; i < 32; i++)
    {
        if(keys_list[i].frequ > 0)
        {
            printf(" %d                    %s\n", keys_list[i].frequ,keys_list[i].nam);
        }
    }

    printf("                                     Builtin_Functions\n");
    printf("                                  .................\n");
    printf("Function found: %d\n", tot_function);

    printf("   Times             Keywords\n");
    printf("............         ...........\n");
    for(i = 0; i < 39; i++)
    {
        if(fun[i].freq > 0)
        {
            printf(" %d                    %s\n", fun[i].freq,fun[i].nam);
        }
    }

    printf("\n");
    printf("                                  Variables\n");
    printf("                               .................\n");

    printf("Total Variable : %d\n", tot_variable);

    printf("Variables list: \n");
    for(i = 0; i < inx_variable; i++)
    {
        printf(" %d                    %s\n", var[i].freq,var[i].variable_list);
    }
    printf("                                    operators\n");
    printf("                                .................\n");
    printf("   Times             operators\n");
    printf("............         ...........\n");
    printf("  %d                     +\n",operator_arr['+']);
    printf("  %d                     -\n",operator_arr['-']);
    printf("  %d                     *\n",operator_arr['*']);
    printf("  %d                     /\n",operator_arr['/']);
    printf("  %d                     %%\n",operator_arr['%']);
    printf("  %d                     =\n",operator_arr['=']);

}

int main()
{
    int i;
    for(i = 0; i < 32; i++)
    {
        strcpy(keys_list[i].nam,keyword[i]);
    }
    for(i = 0; i < 39; i++)
    {
        strcpy(fun[i].nam,builtin_function[i]);
    }
    file_input = fopen("input1.txt","r");

    analysis();
    output();

    getchar();

    return 0;
}
