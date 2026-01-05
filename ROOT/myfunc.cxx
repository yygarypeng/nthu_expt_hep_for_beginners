#include "myfunc.h"
#include <TH1F.h>
#include <TRandom3.h>
#include <TF1.h>

// practice func: add two numbers (stack)
double add(double a, double b) {
	return a + b;
}


// practice func: create and fit a Gaussian histogram (heap)
TH1F* make_histogram(int nEntries = 10000) {
	
	TH1F* h = new TH1F("h", "Gaussian Example", 100, -5, 5);
    TRandom3 rand(114); // random number generator

    for (int i = 0; i < nEntries; i++) {
        double x = rand.Gaus(0, 1); // mean=0, sigma=1
        h->Fill(x);
    }

    // fit histogram with a Gaussian
    h->Fit("gaus");

    return h; // return histogram pointer
}
