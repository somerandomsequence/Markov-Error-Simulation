#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

//The program is almost finished: right now, it calculates q, Q, and h;
//it just doesn't do anything with them, and I need to tweak it just a little
//to allow for data input.
int main()
{
    const size_t max_input;
    int data[maxinput];

    char in_file[40] = "data.txt";
    ifstream ins;

    double one_count, zero_count, runs_1, runs_o ;

    double mu_eb, mu_eg;

    double q, Q, h;

    ins.open(in_file);
    if (ins.fail())
    {
	cerr << "Could not open " << in_file << " !" << endl;
    }

    while(ins && (ins.peek( ) != EOF))
    {
	for(int i = 0; i < max_input; ++i)
	{
	    ins << data[i];
	}
    }

    for(int i = 0; i < max_input; ++i)
    {
	if(data[i] == 0)
	{
	    if(i==0 || data[i-1]==1)
	    {
		++runs_0;
	    }
	    ++zero_count;
	}

	if(data[i] == 1)
	{
	    if(i == 0 || data[i-1] == 0)
	    {
		++runs_1;
	    }
	    ++one_count;
	}
    }
    mu_eb = one_count/runs_1;
    mu_eg = zero_count/runs_0;

    q = (mu_eb - 1)/mu_eb;
    Q = 1 + (1/mu_eb)/((1 - (mu_eg/mu_eb))(1 - (1/mu_eb))(mu_eb/(mu_eb-1)));
    h = (sqrt(( mu_eg*mu_eg + (2 - 4*q)*mu_eg + 1)*((1 - Q)*(1 - Q)) +
	      (4*q*q - 4*q)*mu_eg*(1 - Q) + ((2*q - 1)*mu_eg - 1)*(1 - Q))/
	 2*q*mu_eg*(1 - Q));

    cout << "q =" << q << " Q =" << Q << " h =" << h;
    

    return EXIT_SUCCESS;
    

}
    

