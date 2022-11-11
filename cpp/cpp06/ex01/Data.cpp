#include "Data.hpp"

Data::Data(){}

Data::Data(const Data &ref){(void)ref;}

Data&	Data::operator=(const Data &ref){(void)ref; return*this;}

Data::~Data(){}