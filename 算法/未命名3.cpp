#include<stdio.h>
#include<stdlib.h>
int _Cut_Dynamic_DownToTop(int seg[], int pi[], int arr_len, int length, int dump[])
{
    int tmp;
    dump[0] = 0;
    for (int i = 1; i <= length; ++i)
    {
        tmp = -1;   
        for (int j = 0; j < arr_len; ++j)
        {
            if (i - seg[j] >= 0)
                tmp = max(tmp, pi[j] + dump[i - seg[j]]);               
        }
        dump[i] = tmp;
    }
    return dump[length];
}
 
int Cut_Dynamic_DownToTop(int seg[], int pi[], int arr_len, int length)
{
    int *dump = (int *)malloc(sizeof(int)*length + 1);
    int tmp = _Cut_Dynamic_DownToTop(seg, pi, arr_len, length, dump);
    free(dump);
    return tmp;
}
