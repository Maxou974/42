#include "Data.hpp"

Data::Data(): n(0) 
{}

Data::Data(const Data &ref){n = ref.n;}

Data&	Data::operator=(const Data &ref){n = ref.n; return*this;}

Data::~Data(){}