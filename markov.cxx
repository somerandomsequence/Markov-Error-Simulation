//Directives
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

//Prototypes
double prob();
//Post condition: returns random value between 0 and 1
void print(int state);
//precondition: state is either 0 or 1
//postcondition: prints either G or B

//------------------------------------------------------------------------------
int main(const int argc, const char *argv[])
{
    if(argc != 5)
    {
	fprintf(stderr, "usage: markov <q> <Q> <h> <n>");

	return 1;
    }

    else
    {
    
	srand(time(NULL));
	float q = atof(argv[1]);
	float Q = atof(argv[2]);
	float h = atof(argv[3]);
	float n = atof(argv[4]);
	int count;
	int state;

	state = 0;

//	cout << n << endl;
	for(count = 0; count < n; ++count)
	{
	    double probvalue = prob();

	    if(state == 0 && probvalue < Q)
	    {
		cout << state <<endl;

		state = 1;
		
		
	    }

	    else if(state == 1)
	    {
		if(probvalue < q && probvalue > h)
		{
		    cout<< 0 << endl;

		}

		else if (probvalue > q)
		{
		    cout<<state<<endl;

		    state = 0;

		}
	    }
	}
	return EXIT_SUCCESS;
    }

}
//------------------------------------------------------------------------------

double prob()
{
    double max = RAND_MAX;

    double random = rand();
    return random/max;
}

void print(int value)
{
    if (value == 0)
    {
	cout << "G" << endl;
    }

    else
    {
	cout << "B" << endl;
    }
}
