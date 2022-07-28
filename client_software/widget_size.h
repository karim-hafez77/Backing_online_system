#ifndef WIDGET_SIZE_H
#define WIDGET_SIZE_H

#include"QLabel"
#include"QVBoxLayout"
#include <QtWidgets>
#include "client_socket.h"
#include"../utility/serialization.hpp"
#include "QTextBrowser"
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>
const QSize label_SIZE = QSize(140, 28);
const QSize text_SIZE = QSize(350, 28);
const QSize button_SIZE = QSize(150, 28);
#include <sstream>
#include <iostream>
using namespace std;

struct message_type
        {
            string message_name;
            string message;
            message_type(){}
            message_type(string &input_message_name,string &input_message)
                :message_name(input_message_name){message=input_message;}
            private:
                template <typename Archive>
            void serialize(Archive &ar, const unsigned int version)
                {
                ar &message_name;
                ar &message;
                }
                friend class boost::serialization::access;

        };

struct AccountData
                    {
                     string name;
                     int age;
                     string national_id;
                     string address;
                     string password;

                     AccountData(){}

                     AccountData(string input_name,int input_age,string input_national_id,string input_address,string input_password)
                        {
                            name=input_name;
                            age=input_age;
                            national_id=input_national_id;
                            address=input_address;
                            password=input_password;
                        }
                    private:
                        template <typename Archive>
                    void serialize(Archive &ar, const unsigned int version)
                        {
                        ar &name;
                        ar &age;
                        ar &national_id;
                        ar &address;
                        ar &password;

                        }
                        friend class boost::serialization::access;
                    };
struct login_info
                    {
                     string account_id;
                     string password;

                     login_info(){}

                     login_info(string input_account_id,string input_password)
                        {
                            account_id=input_account_id;
                            password=input_password;
                        }
                    private:
                        template <typename Archive>
                    void serialize(Archive &ar, const unsigned int version)
                        {
                        ar &account_id;
                        ar &password;

                        }
                        friend class boost::serialization::access;
                    };
#endif // WIDGET_SIZE_H
