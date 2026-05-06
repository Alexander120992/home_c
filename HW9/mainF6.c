/*#include <stdio.h>
void InputArr(int size, int a[]);
void OutputArr(int size, int a[]);
int is_two_same(int size, int a[]);

int main(void)
{
    int N = 0;
    scanf("%d",&N);
    int a[N];
    InputArr(N,a);
    printf("%d ",is_two_same(N,a));
    //OutputArr(N,a);
    getchar();
    getchar();
    return 0;
}

void InputArr(int size, int a[])
{
    for(int i = 0; i < size; i++)
        scanf("%d", &a[i]);
}

void OutputArr(int size, int a[])
{
    for(int i = 0; i < size; i++)
        printf("%d ",a[i]);
}
*/
int is_two_same(int size, int a[])
{
    for(int i = 0; i < size-1; i++)
        for(int j = i+1; j < size; j++)
            if(a[i] == a[j])
                return 1;
    return 0;
}
