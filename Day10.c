
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define N 100
#define NUM_TESTS 5

double mean(const double *arr, int n)
{
    double sum = 0.0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return (sum/n);
}

double stddev(const double *arr, int n, double m)
{
    double sum = 0.0;

    for(int i = 0; i < n; i++)
    {
        double temp = arr[i] - m;
        sum += temp * temp;
    }

    return (sqrt(sum/n));
}

double percentage(const double *a, const double *b, int n)
{
    double mean_a = mean(a,n);
    double stddev_a = stddev(a, n, mean_a);

    double mean_b = mean(b,n);
    double stddev_b = stddev(b, n, mean_b);

    double percent = 0.0;

    for(int i = 0; i < n; i++)
    {
        percent += (a[i] - mean_a) * (b[i] - mean_b);
    }

    return (percent / (n * stddev_a * stddev_b));
}


int main() 
{
    int T;
    scanf("%d\n", &T);

    int n;
    double gpa[N];
    double test[NUM_TESTS][N];

    for(int t = 0; t < T; t++)
    {
        scanf("%d\n", &n);

        for(int i = 0; i < n; i++)
        {
            scanf("%lf", &gpa[i]);
        }

        for(int i = 0; i < NUM_TESTS; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%lf", &test[i][j]);
            }
        }

        int max_id;
        double max_percent = -1.0;
        
        for(int i = 0; i < NUM_TESTS; i++)
        {
            if(stddev(test[i], n, mean(test[i], n)) == 0.0)
            {
                continue;
            }

            double p = percentage(gpa, test[i], n);

            if(p > max_percent)
            {
                max_percent = p;
                max_id = i + 1;
            }
        }

        printf("%d\n", max_id);
    }

    return 0;
}

