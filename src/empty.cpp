
//#include <Rcpp.h>
//#include <RcppArmadillo.h>
#include <R.h>
#include <Rinternals.h>


//using namespace Rcpp;
using namespace std;


// // [[Rcpp::export]]
// arma::vec emptyNumArma(int i) {
// //  cout << i;
//   arma::vec x(i);
// //  cout << x;
//   return x;
// }
//
// //[[Rcpp::export]]
// void toplusto (double k) {
//   cout << k << "\n";
//   cout << "2+2 = 4";
// }
//
//
//
// // [[Rcpp::export]]
// SEXP create100(int i) {
//   SEXP ans;
//   ans =
//     PROTECT(Rf_allocVector(REALSXP, 100));
//   UNPROTECT(1);
//   return ans;
// }

//' emptyNumeric
//'
//' Creates an uninitialized numeric vector (that is, assigns values according to what was allocated in the memory)
//'
//' @param n Number of elements
//'
//'@details The calculation time is O(1) + time(memory allocation), which is handled internally by R.
//'For small values of n, \code{numeric} is faster, but for large values of n, \code{emptyNumeric} is much faster.
//'
//'@return A numeric vector of length n
//'
//'@examples
//'vals <- numeric(100)
//'
//' microbenchmark(numeric(1000000))
//' microbenchmark(emptyNumeric(1000000))
//'
// [[Rcpp::export]]
SEXP emptyNumeric(int n) {
  SEXP ans;
  ans =
    PROTECT(Rf_allocVector(REALSXP, n));
  UNPROTECT(1);
  return ans;
}

//' emptyMatrix
//'
//' Creates an uninitialized matrix (that is, assigns values according to what was allocated in the memory)
//'
//' @param nrow,ncol number of rows and columns
//'
//'@return A numeric matrix of dim nrow x ncol.
//'
//'@examples
//'mat <- emptyMatrix(10, 10)
//'
//'# Initialize matrix with 1000000 entries
//'require(microbenchmark)
//'microbenchmark(matrix(, 100, 10000))
//'microbenchmark(emptyMatrix(100, 10000))
// [[Rcpp::export]]
SEXP emptyMatrix(int nrow, int ncol) {
  SEXP ans;
  ans =
    PROTECT(Rf_allocMatrix(REALSXP, nrow, ncol));
  UNPROTECT(1);
  return ans;
}


/**
SEXP newNumeric(SEXP n) {
  PROTECT(newSexp = AS_NUMERIC(n));
  SEXP ans;
  ans =
    PROTECT(Rf_allocVector(REALSXP, n));
  UNPROTECT(1);
  return ans;
}

*/
