#include "push_swap.h"

int main()
{
    int i = 0;

    // "deneme"yi doğrudan sabit bir string olarak tanımla
    char *deneme = "s      s    a         v c";

    // "ft_split" ile bölünmüş stringleri al
    char **deneme_split = ft_split(deneme, ' ');

    // "deneme_split"teki her stringi yazdır
    while (deneme_split[i])
    {
        ft_printf("%s\n", deneme_split[i]);
        i++;
    }

    // Belleği serbest bırak
    i = 0;
    while (deneme_split[i])
    {
        free(deneme_split[i]);
        i++;
    }
    free(deneme_split);

    return 0;
}
