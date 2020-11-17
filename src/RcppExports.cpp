// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

// localZScoreMat
SEXP localZScoreMat(const SEXP adj_mat, const SEXP count_mat, const std::vector<bool> is_control, bool verbose, int return_type, double min_z);
RcppExport SEXP _cacoa_localZScoreMat(SEXP adj_matSEXP, SEXP count_matSEXP, SEXP is_controlSEXP, SEXP verboseSEXP, SEXP return_typeSEXP, SEXP min_zSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const SEXP >::type adj_mat(adj_matSEXP);
    Rcpp::traits::input_parameter< const SEXP >::type count_mat(count_matSEXP);
    Rcpp::traits::input_parameter< const std::vector<bool> >::type is_control(is_controlSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    Rcpp::traits::input_parameter< int >::type return_type(return_typeSEXP);
    Rcpp::traits::input_parameter< double >::type min_z(min_zSEXP);
    rcpp_result_gen = Rcpp::wrap(localZScoreMat(adj_mat, count_mat, is_control, verbose, return_type, min_z));
    return rcpp_result_gen;
END_RCPP
}
// projdiff
arma::rowvec projdiff(const arma::mat& mat, const arma::ivec& g1, const arma::ivec& g2);
RcppExport SEXP _cacoa_projdiff(SEXP matSEXP, SEXP g1SEXP, SEXP g2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type mat(matSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type g1(g1SEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type g2(g2SEXP);
    rcpp_result_gen = Rcpp::wrap(projdiff(mat, g1, g2));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_cacoa_localZScoreMat", (DL_FUNC) &_cacoa_localZScoreMat, 6},
    {"_cacoa_projdiff", (DL_FUNC) &_cacoa_projdiff, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_cacoa(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
