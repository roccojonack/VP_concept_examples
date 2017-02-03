#include "tcp_server.h"
 
void ASession::start()
{
  std::cout << "Starting session" << std::endl;
  connected_ = true; // 1
  socket_.async_read_some(boost::asio::buffer(data_), // 2
  boost::bind(&ASession::handleRead, this, _1, _2)); // 3
};


void ASession::handleRead(const boost::system::error_code& error, size_t bytes)
{
  if(data_[bytes-1] == '\0') // 1
  {
    std::cout << "Client sent a terminator" << std::endl;
    --bytes;
    connected_ = false; // 2
  }
 
  if(!error && bytes) // 3
  {
    std::cout << "Writing back " << bytes << " characters to the client" << std::endl;
    boost::asio::async_write(socket_, boost::asio::buffer(data_, bytes),
    boost::bind(&ASession::handleWrite, this, _1)); // 4
  }
  else
    delete this; // 5
};
void ASession::handleWrite(const boost::system::error_code& error)
{
  if(!error && connected_) // 1
  {
    std::cout << "Ready for a new read" << std::endl;
    socket_.async_read_some(boost::asio::buffer(data_),
    boost::bind(&ASession::handleRead, this, _1, _2)); // 2
  }
  else
    delete this; // 3
};

