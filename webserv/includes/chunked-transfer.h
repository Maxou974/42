#ifndef CHUNKED_TRANSFER_H_
#define CHUNKED_TRANSFER_H_

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <algorithm>
#include "webserv_utility.h"

void	chunk_the_vector(std::vector<unsigned char>& msg, size_t chunk_size);
void write_vector_to_vector(const std::vector<unsigned char> &from,  std::vector<unsigned char> &to);

#endif