#ifndef SERVER_SOCKER_H
#define SERVER_SOCKER_H


#include <string>
#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;
using ip::tcp;

class server_socket
{
private:
    string ip;
    int port_num;
    boost::asio::io_service io_service;
    tcp::acceptor * acceptor_=nullptr;
    tcp::socket socket_;

public:
    server_socket(int port,string ip_address);
    void create_server();
    void send_data(stringstream & data);
    stringstream recieve_data(void);
    tcp::socket* listen_l();
    ~server_socket();
};
#endif // SERVER_SOCKER_H
