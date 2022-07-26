#include "create_new_account.h"
#include "widget_size.h"
create_new_account::create_new_account(QWidget *parent)
    : QWidget{parent}
{
        t_name->setFixedSize(text_SIZE);
        l_name->setFixedSize(label_SIZE);
        t_age->setFixedSize(text_SIZE);
        l_age->setFixedSize(label_SIZE);
        t_address->setFixedSize(text_SIZE);
        l_address->setFixedSize(label_SIZE);
        t_id->setFixedSize(text_SIZE);
        l_id->setFixedSize(label_SIZE);
        submit_button->setFixedSize(button_SIZE);
        return_to_main_window->setFixedSize(button_SIZE);


        inner_horizontal_layout_control_name->addWidget(l_name);
        inner_horizontal_layout_control_name->addWidget(t_name);

        inner_horizontal_layout_control_age->addWidget(l_age);
        inner_horizontal_layout_control_age->addWidget(t_age);


        inner_horizontal_layout_control_address->addWidget(l_address);
        inner_horizontal_layout_control_address->addWidget(t_address);


        inner_horizontal_layout_control_id->addWidget(l_id);
        inner_horizontal_layout_control_id->addWidget(t_id);

        inner_horizontal_layout_control_buttons->addWidget(submit_button);
        inner_horizontal_layout_control_buttons->addWidget(return_to_main_window);
        inner_horizontal_layout_control_buttons->setAlignment(Qt::AlignRight);

        create_account_inner_mainlayout->addLayout(inner_horizontal_layout_control_name);
        create_account_inner_mainlayout->addLayout(inner_horizontal_layout_control_age);
        create_account_inner_mainlayout->addLayout(inner_horizontal_layout_control_id);
        create_account_inner_mainlayout->addLayout(inner_horizontal_layout_control_address);
        create_account_inner_mainlayout->addLayout(inner_horizontal_layout_control_buttons);


        //create new account groupbox layout control
        create_new_account_groupbox->setLayout(create_account_inner_mainlayout);

        main_layout->addWidget(create_new_account_groupbox,0,0,1,1);
        setLayout(main_layout);

        //outer window layout control
}

void create_new_account::read_data()
{



}

