#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double mu_eb, mu_eg;
    double q, Q, h;
    int bit = 0, last_bit = 0, i = 0, one_count = 0, zero_count = 0, runs_1 = 0, runs_0 = 0;

    char buffer[32];
    while(fgets(buffer,32,stdin) != NULL){
      bit = atoi(buffer);
      if(bit == 0)
      {
            if(i==0 || last_bit==1)
            {
                ++runs_0;
            }
            ++zero_count;
      }
      else
      {
            if(i == 0 || last_bit==0)
            {
                ++runs_1;
            }
            ++one_count;
      }
      i++;
      last_bit = bit;
      printf("%d\n",bit);
    }
    mu_eb = (double)one_count/(double)runs_1;
    mu_eg = (double)zero_count/(double)runs_0;

    q = (mu_eb - 1)/mu_eb;
    Q = 1 + (1/mu_eb)/((1 - (mu_eg/mu_eb))*(1 - (1/mu_eb))*(mu_eb/(mu_eb-1)));
    h = (sqrt(( mu_eg*mu_eg + (2 - 4*q)*mu_eg + 1)*((1 - Q)*(1 - Q)) +
	      (4*q*q - 4*q)*mu_eg*(1 - Q) + ((2*q - 1)*mu_eg - 1)*(1 - Q))/
	 2*q*mu_eg*(1 - Q));

    printf("q = %f, Q = %f, h = %f, mu_eb = %f, mu_eg = %f\n",q,Q,h,mu_eb,mu_eg);

    return 0;
}
