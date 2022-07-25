#include "server_socket.h"


server_socket::server_socket(int port,string ip_address = "127.0.0.1")
 :port_num(port),ip(ip_address),io_service(),socket_(io_service) {}

server_socket::~server_socket()
{
    socket_.close();
}



void server_socket::create_server()
{
    try{
        acceptor_ = new tcp::acceptor(io_service, tcp::endpoint(tcp::v4(), port_num));
    }
    catch ( boost::system::system_error e)
    {
        std::cout<<"create server :" << e.what()<<endl;
        acceptor_ = new tcp::acceptor(io_service, tcp::endpoint(tcp::v4(), port_num));
    }
}

tcp::socket *server_socket::listen_l()
{
    tcp::socket *socket_ = new tcp::socket{io_service};
    try{
        acceptor_->accept(*socket_);
    }
    catch (boost::system::system_error e)
    {
        std::cout<<"listen for requests: " <<e.what()<<endl;
    }
    return socket_;
}

void server_socket::send_data(stringstream & data)
{

    try{
    boost::asio::write(socket_, boost::asio::buffer(data.str()));
    }
    catch ( boost::system::system_error e)
    {
        std::cout<<"send data: " <<e.what()<<endl;
    }
}
stringstream server_socket::recieve_data(void)
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
