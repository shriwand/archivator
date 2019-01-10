#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

typedef int dirent_handler(const struct dirent *current_dirent);

/*
    Just print the name of file which is represented
    by the input parameter
*/
int dump_dirent(const struct dirent *current_dirent)
{
    int result = 0;
    if (!(current_dirent->d_name))
    {
        printf("dump_dirent: the name is empty :(\n");
        result = !result;
    }
    else
    {
        printf("%s\n", current_dirent->d_name);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    if (!(argc == 2 || argc == 3))
    {
        printf("Invalid number of arguments: %d\n", argc);
        return -1;
    }

    const char *dirname = argv[1];

    DIR *dir;
    if ((dir = opendir(dirname)) == NULL)
    {
        printf("Cannot open directory %s\n", dirname);
        return -1;
    }

    dirent_handler *dh = dump_dirent;

    struct dirent *current_dirent;

    // iter over files
    while ((current_dirent = readdir(dir)) != NULL)
    {
        dh(current_dirent);
    }

    return 0;
}