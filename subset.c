#include <stdio.h>

    int count;
    int x[100], w[100], d, n;

    void sum(int s, int k, int r) 
    {
        x[k] = 1;
            if (s + w[k] == d) 
        {
             printf("\nsubset :%d", ++count);
    
             for (int i = 0; i<= k; i++)
                 if (x[i] == 1)
                 printf("%d",w[i]);
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
          if (r > d) 
          {
              sum(0, 0, r);
          } 
          else
          printf("no subset is possible\n");
    }
