#include "push_swap.h"

int count_words(char *str)
{
    int space;
    int count;
    int i;

    i = 0;
    count = 0;
    space = 1;
    while (str[i])
    {
        if (!is_space(str[i]))
        {
            if (space == 1)
            {
                count++;
                space = 0;
            }
        }
        else
            space = 1;
        i++;
    }
    return (count);
}

char *ft_word_dup(char *src, int word_len)
{
    char *word;
    int i;

    word = (char *)malloc((word_len + 1) * sizeof(char));
    if (!word)
        return (NULL);
    i = 0;
    while (i < word_len)
    {
        word[i] = src[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

char **ft_split(char **res, char *str)
{
    int word_index;
    int word_len;
    int i;

    i = 0;
    word_len = 0;
    word_index = 0;
    while (str[i])
    {
        if (is_space(str[i]))
        {
            res[word_index] = ft_word_dup(&str[i - word_len], word_len);
            word_index++;
            word_len = 0;
        }
        else
            word_len++;
        i++;
    }
    res[word_index++] = ft_word_dup(&str[i - word_len], word_len);
    res[word_index] = NULL;
    return (res);
}

char **allocate_and_split(char *str)
{
    char    **res;

    res = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
    if (!res)
        return (NULL);
    res = ft_split(res, str);
    return (res);
}