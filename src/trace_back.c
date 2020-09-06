#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>

extern SEXP winch_trace_back_unwind();
extern SEXP winch_trace_back_backtrace();


SEXP winch_trace_back(SEXP method) {
  if (TYPEOF(method) != INTSXP) {
    Rf_error("winch_trace_back: method must be integer");
  }

  if (Rf_length(method) != 1) {
    Rf_error("winch_trace_back: method must be scalar");
  }

  if (INTEGER(method)[0] == 1) {
    return winch_trace_back_unwind();
  } else if (INTEGER(method)[0] == 2) {
    return winch_trace_back_backtrace();
  } else {
    Rf_error("winch_trace_back: method invalid");
  }
}
