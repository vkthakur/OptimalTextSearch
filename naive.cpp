#include "naive.h"
#include "ui_naive.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <set>
using namespace std;

set<string> s1;

naive::naive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::naive)
{
    ui->setupUi(this);
    this->setWindowTitle("NAIVE ALGORITHM");
    QString c1="CHAR";
    QString c2="COUNT";
    ui->table->setItem(0,0,new QTableWidgetItem(c1));
    ui->table->setItem(1,0,new QTableWidgetItem(c2));
    for(int i=1;i<=26;i++)
    {
        int temp=i+96;
        QChar t=temp;
        QString q=QString(t);
        ui->table->setItem(0,i,new QTableWidgetItem(q));
        ui->table->setItem(1,i,new QTableWidgetItem("0"));


    }
}

naive::~naive()
{
    delete ui;
}


void mysendtofile()
{
    fstream f1;
    f1.open("/home/vivek/QT/Text_search/permut.txt",fstream::in |fstream::out |fstream::app);
   // f1<<a<<endl;
    while(!s1.empty())
    {
        f1<<*s1.begin()<<endl;
        s1.erase(s1.begin());
    }
    f1.close();

}


void myswap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void mypermute(char *a, int i, int n)
{
   int j;
   if (i == n)
   {
     //printf("%s\n", a);
     //mysendtofile(a);
      s1.insert(a);

   }
   else
   {
        for (j = i; j <= n; j++)
       {
          myswap((a+i), (a+j));
          mypermute(a, i+1, n);
          myswap((a+i), (a+j)); //backtrack
       }
   }
}

int search(char *str)
{
    FILE *file1=fopen("/home/vivek/QT/Text_search/file1.txt","r");
    char line[128];
    int i;
    for(i=0;i<128;i++)
    {
        line[i]='\0';
    }
    int res=1;
    if(file1!=NULL)
    {
        i=0;
        while(fgets(line,sizeof line,file1)!=NULL)
        {


            int x=strlen(line);
            line[x-1]='\0';

            res=strcmp(line,str);
            if(res==0)
            {
               fclose(file1);
               return 1;
            }
        }
        fclose(file1);
    }

    return 0;
}

void naive::on_pushButton_clicked()
{

    int i,n,j,x;
    QString q,str;

    for(i=1;i<=26;i++)
    {
        q=ui->table->item(1,i)->text();
        n=q.toInt();
        x=i+96;
        char temp=x;

        for(j=0;j<n;j++)
        {

            str.append(temp);

        }

    }
    QByteArray arr=str.toUtf8();
    string str1=arr.constData();
    int l1=str1.size();
    char arr1[100];

    for(i=0;i<l1;i++)
    {
        arr1[i]=str1[i];
    }
    arr1[i]='\0';
    fstream f1;
    f1.open("/home/vivek/QT/Text_search/permut.txt",fstream::out |fstream::trunc);
    f1.close();
    mypermute(arr1,0,l1-1);
    mysendtofile();

}

void naive::on_pushButton_2_clicked()
{
    clock_t begin,end;
    double time_spent;

    begin=clock();
    FILE *file2=fopen("/home/vivek/QT/Text_search/permut.txt","r");
    char line[128];
    int i;
    for(i=0;i<128;i++)
    {
        line[i]='\0';
    }

    if(file2!=NULL)
    {
        i=0;
        while(fgets(line,sizeof line,file2)!=NULL)
        {


            int x=strlen(line);
            line[x-1]='\0';
            int res;
            res=search(line);

            if(res==1)
            {
                QString q;
                q.append(line);
                ui->result->appendPlainText(q);
            }
        }
        fclose(file2);
    }
    end=clock();
    time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    QString ans=QString::number(time_spent);
    ui->time->setPlainText(ans);

}
