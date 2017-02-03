#pragma once
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <iostream>
// #include "echo.h"
 
using boost::asio::ip::tcp;
 
class ASession
{
public:
  ASession(boost::asio::io_service& ios) : socket_(ios), connected_(false) {}
  ~ASession() { std::cout << "Session dtor" << std::endl; }
 
  tcp::socket& socket() { return socket_; }
 
  void start();
  void handleRead(const boost::system::error_code& error, size_t length);
  void handleWrite(const boost::system::error_code& error);
private:
  tcp::socket socket_;
  boost::array<char, 128> data_;
  bool connected_;
};
