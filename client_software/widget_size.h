#ifndef WIDGET_SIZE_H
#define WIDGET_SIZE_H

#include"QLabel"
#include"QVBoxLayout"
#include <QtWidgets>
#include "client_socket.h"
#include"../utility/serialization.hpp"
const QSize label_SIZE = QSize(120, 28);
const QSize text_SIZE = QSize(350, 28);
const QSize button_SIZE = QSize(150, 28);

struct AccountData
                    {

                     string name;
                     int age;
                     string national_id;
                     string address;

                     AccountData(){}

                     AccountData(string input_name,int input_age,string input_national_id,string input_address)
                        {
                            name=input_name;
                            age=input_age;
                            national_id=input_national_id;
                            address=input_address;
                        }
                    private:
                        template <typename Archive>
                    void serialize(Archive &ar, const unsigned int version)
                        {
                        ar &name;
                        ar &age;
                        ar &national_id;
                        ar &address;

                        }
                        friend class boost::serialization::access;
                    };

#endif // WIDGET_SIZE_H
