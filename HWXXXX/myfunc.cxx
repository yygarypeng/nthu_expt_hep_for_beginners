#include "myfunc.h" // user defined header files (for function declaration)
#include <TH1F.h>  // system, library header files
#include <TRandom3.h>
#include <TF1.h>

// Review of cpp pointers: https://www.howardsnotes.tw/cpp-pointer/
// stack vs heap: https://courses.grainger.illinois.edu/cs225/sp2023/resources/stack-heap/
// stack vs heap vs static: https://stackoverflow.com/questions/408670/stack-static-and-heap-in-c

// practice func: add two numbers (stack)
double add(double a, double b) {
	return a + b;
}


// practice func: create and fit a Gaussian histogram (heap)
TH1F* make_histogram(int nEntries = 10000) {
	
	TH1F* h = new TH1F("h", "Gaussian Example", 100, -5, 5);
    TRandom3 rand(114); // random number generator (recommended to use TRandom3 <- better statistics ability)

    for (int i = 0; i < nEntries; i++) {
        double x = rand.Gaus(0, 1); // mean=0, sigma=1
        h->Fill(x);
    }

    // fit histogram with a Gaussian
    h->Fit("gaus");

    return h; // return histogram pointer
}
