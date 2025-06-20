// C program to create music playlist organiser:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct music_node
{
    char music_name[50];
    struct music_node *next;
};
typedef struct music_node MUSIC;
void create_music_node(MUSIC *start, MUSIC *music_node, int n)
{
    int i;
    for (i = 1; i < n; i++)
    {
        music_node = (MUSIC *)malloc(sizeof(MUSIC));
        printf("Enter the name of %d music\n", i + 1);
        scanf("%s", music_node->music_name);
        start->next = music_node;
        start = music_node;
    }
}
void play_music_node(MUSIC *start, int n)
{
    int i;
    printf("Play music playlist\n");
    for (i = 0; i < n; i++)
    {
        printf("%s->", start->music_name);
        start = start->next;
    }
}
void add_at_start(MUSIC *start, int n)
{
    printf("Enter the new music node\n");
    MUSIC *music_node;
    music_node = (MUSIC *)malloc(sizeof(MUSIC));
    printf("Enter the music name\n");
    scanf("%s", music_node->music_name);
    music_node->next = start;
    start = music_node;
    n++;
    printf("Play music playlist after adding one music node at starting\n");
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s->", start->music_name);
        start = start->next;
    }
}
void add_at_last(MUSIC *start, int n)
{
    MUSIC *temp, *music_node;
    temp = start;
    printf("Enter the music name\n");
    music_node = (MUSIC *)malloc(sizeof(MUSIC));
    scanf("%s", music_node->music_name);
    music_node->next = NULL;
    int i;
    for (i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    temp->next = music_node;
    n++;
    printf("Play music playlist after adding one music node at last\n");
    for (i = 0; i < n; i++)
    {
        printf("%s->", start->music_name);
        start = start->next;
    }
}
void del_from_first(MUSIC *start)
{
    MUSIC *temp;
    temp = start;
    start = temp->next;
    printf("Play music playlist after removing one music node from starting\n");
    while (start != NULL)
    {
        printf("%s->", start->music_name);
        start = start->next;
    }
}
void del_from_last(MUSIC *start)
{
    MUSIC *temp;
    temp = start;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    printf("Play music playlist after removing one music node from last\n");
    while (start != NULL)
    {
        printf("%s->", start->music_name);
        start = start->next;
    }
}
void search_music_node(MUSIC *start)
{
    char search_music_name[50];
    printf("Enter the music name which you want to search\n");
    scanf("%s", search_music_name);
    while (start != NULL)
    {
        if (strcmp(start->music_name, search_music_name) == 0)
        {
            printf("%s\nMusic is found im music node\n", search_music_name);
            printf("Play search music node\n");
            printf("%s->\n", start->music_name);
            break;
        }
        else
        {
            start = start->next;
        }
    }
}
int main()
{
    int n;
    printf("Enter the no of music node\n");
    scanf("%d", &n);
    MUSIC *start = NULL, *music_node;
    music_node = (MUSIC *)malloc(sizeof(MUSIC));
    printf("Enter the names of music\n");
    printf("Enter the name of 1 music\n");
    scanf("%s", music_node->music_name);
    if (start == NULL)
    {
        start = music_node;
        start->next = NULL;
    }
    while (1)
    {
        int choice;
        printf("\nWelcome to music playlist manager\n");
        printf("Press 1 for creation of music playlist\n");
        printf("Press 2 for play music play list\n");
        printf("Press 3 for add music node at starting of music playlist\n");
        printf("Press 4 for add music node at the end of music playlist\n");
        printf("Press 5 for delete music node from starting of music playlist\n");
        printf("Press 6 for delete music node from ending of music playlist\n");
        printf("Press 7 for search music name in music node\n");
        printf("Press 8 for exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 8)
        {
            switch (choice)
            {
            case 1:
                create_music_node(start, music_node, n);
                break;
            case 2:
                play_music_node(start, n);
                break;
            case 3:
                add_at_start(start, n);
                break;
            case 4:
                add_at_last(start, n);
                break;
            case 5:
                del_from_first(start);
                break;
            case 6:
                del_from_last(start);
                break;
            case 7:
                search_music_node(start);
                break;
            case 8:
                printf("All operations are completed successfully\n");
                exit(1);
                break;
            }
        }
        else
        {
            printf("You have entered invalid choice\n");
        }
    }
    return 0;
}
