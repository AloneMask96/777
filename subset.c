#include <stdio.h>

    int flag, count;
    int x[100], w[100], d, n;

    void sum(int s, int k, int r) 
    {
        x[k] = 1;
            if (s + w[k] == d) 
        {
             printf("\nsubset :%d", ++count);
             flag = 1;
             for (int i = 0; i <= k; i++)
                 if (x[i] == 1)
                 printf("%d ", w[i]);
            } 
        else if (s + w[k] + w[k + 1] <= d)
            sum(s + w[k], k + 1, r - w[k]);
        if ((s + r - w[k]) >= d && (s + w[k + 1] <= d)) 
        {
                x[k] = 0;
                sum(s, k + 1, r - w[k]);
        }
    }

    int main()
    {
      int r = 0;
          flag = 0;
          printf("enter the total no of elements:");
          scanf("%d", &n);
          for (int i = 0; i < n; i++)
          scanf("%d", &w[i]);
          printf("enter the value of sum:");
          scanf("%d", &d);
          for (int i = 0; i < n; i++)
          x[i] = 0;
          for (int i = 0; i < n; i++)
           r += w[i];
          if (r < d) 
          {
          printf("no subset is possible\n");
          flag = 1;
          } 
          else
          sum(0, 0, r);
          if (flag == 0)
           printf("no more subset is possible\n");
          return 0;
       }
