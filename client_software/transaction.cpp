#include "transaction.h"

transaction::transaction(QWidget *parent)
    : QWidget{parent}
{
    l_account_number->setFixedSize(label_SIZE);
    l_account_id->setFixedSize(label_SIZE);
    hbox1->addWidget(l_account_number);
    hbox1->addWidget(l_account_id);
    hbox1->setAlignment(Qt::AlignLeft);
    vbox->addLayout(hbox1);


    l_deposit_amount->setFixedSize(label_SIZE);
    t_deposit->setFixedSize(text_SIZE);
    deposit_button->setFixedSize(button_SIZE);
    hbox2->addWidget(l_deposit_amount);
    hbox2->addWidget(t_deposit);
    hbox2->addWidget(deposit_button);
    hbox2->setAlignment(Qt::AlignLeft);
    vbox->addLayout(hbox2);


    l_withdraw_amount->setFixedSize(label_SIZE);
    t_withdraw->setFixedSize(text_SIZE);
    withdraw_button->setFixedSize(button_SIZE);
    hbox3->addWidget(l_withdraw_amount);
    hbox3->addWidget(t_withdraw);
    hbox3->addWidget(withdraw_button);
    hbox3->setAlignment(Qt::AlignLeft);
    vbox->addLayout(hbox3);


    l_total->setFixedSize(label_SIZE);
    l_total_amount_of_money->setFixedSize(label_SIZE);
    show_button->setFixedSize(button_SIZE);
    hbox4->addWidget(l_total);
    hbox4->addWidget(l_total_amount_of_money);
    hbox4->addWidget(show_button);
    hbox4->setAlignment(Qt::AlignLeft);
    vbox->addLayout(hbox4);


    hbox5->addWidget(logout);
    hbox5->setAlignment(Qt::AlignRight);
    vbox->addLayout(hbox5);

    transactions->setLayout(vbox);

    main_layout->addWidget(transactions, 0, 0, 1, 1 );


    setLayout(main_layout);

}


void transaction::on_deposit_button_clicked()
{

}
void transaction::on_withdraw_button_clicked()
{

}
void transaction::on_show_button_clicked()
{

}
void transaction::on_redo_button_clicked()
{

}
void transaction::on_undo_button_clicked()
{

}
