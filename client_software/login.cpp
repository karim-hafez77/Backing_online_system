#include "login.h"

login::login(QWidget *parent) : QWidget{parent}
{
    l_account_id->setFixedSize(label_SIZE);
    t_account_id->setFixedSize(text_SIZE);
    hbox1->addWidget(l_account_id);
    hbox1->addWidget(t_account_id);
    hbox1->setAlignment(Qt::AlignLeft);
    vbox->addLayout(hbox1);
    t_password->setEchoMode(QLineEdit::Password);
    l_password->setFixedSize(label_SIZE);
    t_password->setFixedSize(text_SIZE);
    t_password->setPlaceholderText("Enter Password");
    t_account_id->setPlaceholderText("Enter account id");

    hbox2->addWidget(l_password);
    hbox2->addWidget(t_password);
    hbox2->setAlignment(Qt::AlignLeft);
    vbox->addLayout(hbox2);

    sign_in_button->setFixedSize(button_SIZE);
    hbox3->addWidget(sign_in_button);
    hbox3->addWidget(return_back);
    hbox3->setAlignment(Qt::AlignHCenter);
    vbox->addLayout(hbox3);

    hbox4->setAlignment(Qt::AlignCenter);
    hbox4->addWidget(l_test);
    vbox->addLayout(hbox4);


    login_groupbox->setLayout(vbox);
    main_layout->addWidget(login_groupbox, 0, 0, 1, 1 );
    setLayout(main_layout);


}

void login::connect_function(void)
{

}


void login::on_sign_in_button_clicked()
{
   QString x= t_account_id->toPlainText();
   t_password->setText(x);
}

