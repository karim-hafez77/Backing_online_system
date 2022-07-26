#include "client_socket.h"

client_socket::client_socket(int port,string ip ):port_num(port),ip(ip),io_service(),socket_(io_service){}

client_socket::~client_socket()
{
    socket_.close();
}

void client_socket::connect_to_socket()
{
    try {
        socket_.connect(tcp::endpoint(boost::asio::ip::address::from_string(ip), port_num));
        std::cout<<"connect to socket : " <<endl;

    }
    catch ( boost::system::system_error e)
    {
        std::cout<<"connect to socket : " <<e.what()<<endl;
    }
}

void client_socket::send_data(stringstream & data)
{

    try{
    boost::asio::write(socket_, boost::asio::buffer(data.str()));
    }
    catch ( boost::system::system_error e)
    {
        std::cout<<"send data: " <<e.what()<<endl;
    }
}
stringstream client_socket::recieve_data(void)
{
    char buf [512];
    try{
    socket_.read_some(boost::asio::buffer(buf));
    }
    catch ( boost::system::system_error e)
    {
        std::cout<<"send data: " <<e.what()<<endl;
    }
    stringstream recive_data(buf);
return recive_data;

}

