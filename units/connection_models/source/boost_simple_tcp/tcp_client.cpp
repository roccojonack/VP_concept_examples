#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

const int portNr = 8888;
const std::string host("127.0.0.1");
const std::string msg("Hello Rocco");
const int numberOfMsg = 100;
class tcp_client 
{
  boost::asio::ip::tcp::socket *socket;
  boost::system::error_code error;
  boost::array<char, 128> buf;
  bool debug;
  void connect(std::string host, int port);
  void send_something(std::string message);
  void disconnect();
public:
  tcp_client()
  {
    debug = true;
    connect(host, portNr);
    for (int i=0; i<numberOfMsg;++i) {
      send_something(msg);
    };
    disconnect();
  };
};

void tcp_client::connect(std::string host, int port)
{
  boost::asio::io_service ios;
  boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(host), port);
  socket =  new boost::asio::ip::tcp::socket(ios);
  socket->connect(endpoint);
};

void tcp_client::send_something(std::string message)
{
  std::copy(message.begin(),message.end(),buf.begin());
  socket->write_some(boost::asio::buffer(buf, message.size()), error);
  if (debug) std::cout << "Client wrote :" << message << " with length " << message.size() << std::endl; 
};

void tcp_client::disconnect()
{
  socket->close();
};

int main()
{
  tcp_client();
  return 0;
};
