#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>

const int portNr = 8888;
const std::string host("127.0.0.1");
const int numberOfMsg = 100;

std::string make_string(boost::asio::streambuf& streambuf)
{
  return {boost::asio::buffers_begin(streambuf.data()), 
          boost::asio::buffers_end(streambuf.data())};
};
 
class tcp_server
{
  boost::asio::ip::tcp::socket *socket;
  boost::system::error_code     error;
  unsigned int                  length;
  boost::asio::streambuf        buf;
  bool                          debug;
  
  void connect(int port) {
    boost::asio::io_service        io_service;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);
    boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint);
    socket = new boost::asio::ip::tcp::socket (io_service);
    std::cout << "Server ready to receive" << std::endl; 
    acceptor.accept(*socket); 
  };
  void receive(int counter) {
    boost::asio::read(*socket, buf, error); 
    if (debug) std::cout << "Server received :" << make_string(buf) << " number " << counter << std::endl; 
  };
  void disconnect() {
    socket->close(); 
  };
public:
  tcp_server()
  {
    try
      {
	debug = true;
	connect (portNr);
	for (int i=0; i<numberOfMsg;++i) {
	  receive(i);
	};
	// disconnect();
      }
    catch(std::exception& e)
      {
        std::cerr << "Exception: " << e.what() << std::endl;
      };
  };
};

int main()
{
  tcp_server();
  return 0;
};
