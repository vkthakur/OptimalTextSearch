/********************************************************************************
** Form generated from reading UI file 'otsa.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTSA_H
#define UI_OTSA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_otsa
{
public:
    QPushButton *pushButton;
    QTableWidget *table;
    QLabel *label;
    QPushButton *pushButton_2;
    QPlainTextEdit *result;
    QPlainTextEdit *time;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *status;
    QPushButton *pushButton_3;

    void setupUi(QDialog *otsa)
    {
        if (otsa->objectName().isEmpty())
            otsa->setObjectName(QStringLiteral("otsa"));
        otsa->resize(714, 549);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Mono"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        otsa->setFont(font);
        pushButton = new QPushButton(otsa);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 30, 181, 51));
        table = new QTableWidget(otsa);
        if (table->columnCount() < 27)
            table->setColumnCount(27);
        if (table->rowCount() < 2)
            table->setRowCount(2);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(70, 130, 401, 71));
        table->setRowCount(2);
        table->setColumnCount(27);
        table->horizontalHeader()->setVisible(false);
        table->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        table->verticalHeader()->setVisible(false);
        label = new QLabel(otsa);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 90, 301, 31));
        pushButton_2 = new QPushButton(otsa);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 130, 111, 41));
        result = new QPlainTextEdit(otsa);
        result->setObjectName(QStringLiteral("result"));
        result->setGeometry(QRect(70, 310, 261, 181));
        time = new QPlainTextEdit(otsa);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(430, 410, 191, 81));
        label_2 = new QLabel(otsa);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 270, 57, 20));
        label_3 = new QLabel(otsa);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(450, 360, 131, 20));
        status = new QLabel(otsa);
        status->setObjectName(QStringLiteral("status"));
        status->setGeometry(QRect(360, 40, 241, 41));
        pushButton_3 = new QPushButton(otsa);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(510, 180, 111, 41));

        retranslateUi(otsa);

        QMetaObject::connectSlotsByName(otsa);
    } // setupUi

    void retranslateUi(QDialog *otsa)
    {
        otsa->setWindowTitle(QApplication::translate("otsa", "Dialog", 0));
        pushButton->setText(QApplication::translate("otsa", "INITIALIZE TRIE", 0));
        label->setText(QApplication::translate("otsa", "INPUT SEARCH CHARACTERS", 0));
        pushButton_2->setText(QApplication::translate("otsa", "SUBMIT", 0));
        label_2->setText(QApplication::translate("otsa", "RESULTS", 0));
        label_3->setText(QApplication::translate("otsa", "COMPUTATION TIME", 0));
        status->setText(QString());
        pushButton_3->setText(QApplication::translate("otsa", "GETRESULT", 0));
    } // retranslateUi

};

namespace Ui {
    class otsa: public Ui_otsa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTSA_H
