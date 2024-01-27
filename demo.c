#include <stdio.h> 

int main()
{
    int n, i, data, count=0;

    scanf("%d", &n);

    int a[n];

    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i=0; i<n; i++)
    {
        data = a[i];

        if(i == n)
            break;

        if(data != a[i+1])
        {
            count++;
        }
    }

    if(count == 0)
    {
        printf("%d", 0);
    }

    else
    {
        printf("%d", count);
    }

    return 0;
}