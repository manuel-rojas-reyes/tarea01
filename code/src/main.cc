#include <global.hh>
#include <timing.hpp>

/////////////////////////////////////////////////////////////////////////////////
//   Usage:
//           ./program_name -nt T -nx S
//           T:   number of iterations to run for (default = 1000)
//           S:   problem size (default = 15000)
//
//   Description:
//           Computes a[0:nx-1] = a[0:nx-1]*b[0:nx-1] + c[0:nx-1] T times, for array length nx
//           Reports time
//
/////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
  uint64_t niter = 1000;
  uint64_t nx = 15000;

  std::string mystr;
  double *a, *b, *c;
  timing timer;

  ///////////////////////////////////////
  //  Read command-line parameters -nt
  for (size_t i = 0; i < argc; i++)
  {
    mystr = argv[i];
    if (mystr == "-nt")
    {
      niter = atoi(argv[i + 1]);
    }
    if (mystr == "-nx")
    {
      nx = atoi(argv[i + 1]);
    }
  }

  std::cout << "Looping " << niter << " times."
            << " Problem size nx is: " << nx << std::endl;

  //////////////////////////////////////////
  // Initialize
  a = new double[nx];
  b = new double[nx];
  c = new double[nx];
  for (size_t i = 0; i < nx; i++)
  {
    a[i] = 1.0;
    b[i] = 2.0;
    c[i] = 5.0;
  }

  /////////////////////////////
  //  Compute Loop
  timer.start();
  for (size_t j = 0; j < niter; j++)
  {
    for (size_t i = 0; i < nx; i++)
    {
      a[i] = a[i] * b[i] + c[i];
    }
  }
  timer.stop();
  delete[] a;
  delete[] b;
  delete[] c;

  std::cout << "Ttotal: " << timer.elapsed() 
            << " Titer: " << timer.elapsed() / niter 
            << " Telem: " << timer.elapsed() / niter / nx << std::endl;
}
