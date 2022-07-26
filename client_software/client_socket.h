#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H


#include <boost/asio.hpp>
#include <iostream>


using namespace std;
using namespace boost::asio;
using ip::tcp;
class client_socket
{
private:
    string ip;
    int port_num;
    boost::asio::io_service io_service;
    tcp::socket socket_;

public:

    client_socket(int port,string ip="127.0.0.1");
    void connect_to_socket();
    void send_data(stringstream & data);
    stringstream recieve_data(void);
    ~client_socket();
};

#endif // CLIENT_SOCKET_H
