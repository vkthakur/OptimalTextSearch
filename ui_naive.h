/********************************************************************************
** Form generated from reading UI file 'naive.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAIVE_H
#define UI_NAIVE_H

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

class Ui_naive
{
public:
    QTableWidget *table;
    QPushButton *pushButton;
    QPlainTextEdit *result;
    QPlainTextEdit *time;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *naive)
    {
        if (naive->objectName().isEmpty())
            naive->setObjectName(QStringLiteral("naive"));
        naive->resize(682, 484);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Mono"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        naive->setFont(font);
        table = new QTableWidget(naive);
        if (table->columnCount() < 27)
            table->setColumnCount(27);
        if (table->rowCount() < 2)
            table->setRowCount(2);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(30, 60, 311, 71));
        table->setRowCount(2);
        table->setColumnCount(27);
        table->horizontalHeader()->setVisible(false);
        table->horizontalHeader()->setHighlightSections(false);
        table->verticalHeader()->setVisible(false);
        pushButton = new QPushButton(naive);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 60, 101, 41));
        result = new QPlainTextEdit(naive);
        result->setObjectName(QStringLiteral("result"));
        result->setGeometry(QRect(43, 230, 271, 211));
        time = new QPlainTextEdit(naive);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(390, 350, 151, 91));
        label = new QLabel(naive);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 200, 57, 15));
        label_2 = new QLabel(naive);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(450, 320, 57, 15));
        label_3 = new QLabel(naive);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 30, 181, 16));
        pushButton_2 = new QPushButton(naive);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 110, 101, 41));

        retranslateUi(naive);

        QMetaObject::connectSlotsByName(naive);
    } // setupUi

    void retranslateUi(QDialog *naive)
    {
        naive->setWindowTitle(QApplication::translate("naive", "Dialog", 0));
        pushButton->setText(QApplication::translate("naive", "SUBMIT", 0));
        label->setText(QApplication::translate("naive", "RESULT", 0));
        label_2->setText(QApplication::translate("naive", "TIME", 0));
        label_3->setText(QApplication::translate("naive", "ENTER CHARACTER VALUES", 0));
        pushButton_2->setText(QApplication::translate("naive", "GETRESULT", 0));
    } // retranslateUi

};

namespace Ui {
    class naive: public Ui_naive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAIVE_H
