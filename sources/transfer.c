/*
** EPITECH PROJECT, 2019
** transfer
** File description:
** transfer
*/

#include "transfer.h"

int display_usage(char *filepath, int ret)
{
    int fd = open(filepath, O_RDONLY);
    char *str;

    if (fd < 0)
        return (EXIT_ERROR);
    str = get_next_line(fd);
    while (str) {
        printf("%s\n", str);
        free(str);
        str = get_next_line(fd);
    }
    return (ret);
}

bool check_arg(char *av)
{
    int lenght = strlen(av) - 1;
    int i = 0;

    if (av && strlen(av) == 0)
        return (false);
    if (av[i] ==  '*' || av[lenght] == '*')
        return (false);
    for (; av[i]; i++) {
        if (av[i] == '-' || av[i] == '+')
            i++;
        if (av[i] != '*' && av[i] != '-' && (av[i] < '0' || av[i] > '9'))
            return (false);
        if (av[i] == '*' && ((av[i + 1] && av[i + 1] == '*') || (av[i - 1] && av[i - 1] == '*')))
            return (false);
        if (av[i] == '-' && (av[i + 1] && (av[i + 1] < '0' || av[i + 1] > '9') || (av[i - 1] && av[i - 1] != '*')))
            return (false);
    }
    return (true);
}

bool parser(int ac, char **av)
{
    if (ac < 2 || ac % 2 != 1)
        return (false);
    for (int i = 1; av[i]; i++)
        if (!check_arg(av[i]))
            return (false);
    return (true);
}

int transfer(int ac, char **av)
{
    if (ac == 2)
        if (av[1] && strcmp(av[1], "-h") == 0)
            return (display_usage("README", EXIT_SUCCESS));
    if (!parser(ac, av))
        return (EXIT_ERROR);
    compute_simple(ac, av);
    return (EXIT_SUCCESS);
}
