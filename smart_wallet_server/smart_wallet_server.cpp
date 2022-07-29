#include "smart_wallet_server.h"

smart_wallet_server::smart_wallet_server(QWidget *parent)
    : QWidget{parent}
{
    l_account_no->setFixedSize(label_SIZE);
    l_account_no_value->setFixedSize(label_SIZE);
    hbox1->addWidget(l_account_no);
    hbox1->addWidget(l_account_no_value);
    hbox1->setAlignment(Qt::AlignLeft);
    vbox_account_info->addLayout(hbox1);
    Transactions_log->setReadOnly(1);
    Transactions_log->setOverwriteMode(1);

    l_name->setFixedSize(label_SIZE);
    l_name_value->setFixedSize(label_SIZE);
    hbox2->addWidget(l_name);
    hbox2->addWidget(l_name_value);
    hbox2->setAlignment(Qt::AlignLeft);
    vbox_account_info->addLayout(hbox2);

    l_age->setFixedSize(label_SIZE);
    l_age_value->setFixedSize(label_SIZE);
    hbox3->addWidget(l_age);
    hbox3->addWidget(l_age_value);
    hbox3->setAlignment(Qt::AlignLeft);
    vbox_account_info->addLayout(hbox3);

    l_national_id->setFixedSize(label_SIZE);
    l_national_id_value->setFixedSize(label_SIZE);
    hbox4->addWidget(l_national_id);
    hbox4->addWidget(l_national_id_value);
    hbox4->setAlignment(Qt::AlignLeft);
    vbox_account_info->addLayout(hbox4);

    l_address->setFixedSize(label_SIZE);
    l_address_value->setFixedSize(label_SIZE);
    hbox5->addWidget(l_address);
    hbox5->addWidget(l_address_value);
    hbox5->setAlignment(Qt::AlignLeft);
    vbox_account_info->addLayout(hbox5);

//    l_total_amount_of_money->setFixedSize(label_SIZE);
    l_total_amount_of_money_value->setFixedSize(label_SIZE);
    hbox6->addWidget(l_total_amount_of_money);
    hbox6->addWidget(l_total_amount_of_money_value);
    hbox6->setAlignment(Qt::AlignLeft);
    vbox_account_info->addLayout(hbox6);


    vbox_tracsaction->addWidget(Transactions_log);

    transactions->setLayout(vbox_tracsaction);
    account_info->setLayout(vbox_account_info);
    main_layout->addWidget(account_info, 0, 0, 1, 1 );
    main_layout->addWidget(transactions, 0, 1, 1, 1 );


    setLayout(main_layout);
}
