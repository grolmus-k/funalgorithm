#include "Rcpp.h"
using namespace Rcpp;

#include"fundamental_algorithm.h"
#include"other.h"

std::unordered_map<std::string,std::vector<std::string>> marshall_dataframe(const DataFrame& X)
{
    std::unordered_map<std::string,std::vector<std::string>> Y;
    std::vector<std::string> keys = X.names();

    for (int i = 0; i < keys.size();i++){
        std::vector<std::string> values = X[i];
        Y[keys[i]] = values;
    }
    return Y;
}

std::unordered_map<std::string,std::string> stable_marriage(const DataFrame& preference_table_1,const DataFrame& preference_table_2)
{
    std::unordered_map<std::string,std::vector<std::string>> preferences_1 = marshall_dataframe(preference_table_1);
    std::unordered_map<std::string,std::vector<std::string>> preferences_2 = marshall_dataframe(preference_table_2);

    std::unordered_map<std::string,std::string> matching = FUNDAMENTAL_ALGORITHM(preferences_1,preferences_2);
    return matching;

}



RCPP_MODULE(marshalling) 
{
function("rcpp_marshall_dataframe", &marshall_dataframe);
}

RCPP_MODULE(stable_marriage) 
{
function("rcpp_stable_marriage", &stable_marriage);
}
