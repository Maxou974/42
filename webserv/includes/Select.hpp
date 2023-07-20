#ifndef SELECT_HPP__
#define SELECT_HPP__

#include <time.h>
#include <signal.h>
#include <fcntl.h>

#include "Socket.hpp"
#include "Server.hpp"
#include "Parsing.hpp"
#include "Client.hpp"
#include "Location.hpp"
#include "FdSet.hpp"
#include "Color.hpp"
#include "ErrorPages.hpp"
#include "ServerResolver.hpp"

#define TIMEOUT_CLIENT 15

void	call_select(arr_Server &server_v, arr_Socket &socket_v);


#endif