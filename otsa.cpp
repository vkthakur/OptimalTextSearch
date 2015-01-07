#include "otsa.h"
#include "ui_otsa.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <set>
using namespace std;

set<string> s2;



otsa::otsa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otsa)
{
    ui->setupUi(this);
    this->setWindowTitle("OPTIMAL TEXT SEARCH ALGORITHM");
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

otsa::~otsa()
{
    delete ui;
}




typedef struct trie_node
{
    int value;
    int checksum;
    struct trie_node *child[27];
}my_trie_node;

//typedef trie_node my_trie_node;


typedef struct trie
{
    my_trie_node *root;
    int count;
}my_trie;

trie mytrie;

//typedef trie my_trie;


my_trie_node* getnode()
{
    int i;
    my_trie_node *node=NULL;

    node=(my_trie_node *)malloc(sizeof(my_trie_node));

    if(node)
    {
        node->value=0;
        node->checksum=0;

        for(i=0;i<=26;i++)
            {
                node->child[i]=NULL;
            }
    }

    return node;
}

void initialize(my_trie *ptrie)
{
    ptrie->root=getnode();
    ptrie->count=0;
}

void insert(my_trie *ptrie,char key[])
{
    int level,len,index;
    len=strlen(key);
    my_trie_node *pcrawl;
    ptrie->count++;

    pcrawl=ptrie->root;

    for(level=0;level<len;level++)
    {
        index=key[level]-96;

        if(pcrawl->child[index]==NULL)
        {
            pcrawl->child[index]=getnode();
        }

        pcrawl=pcrawl->child[index];
    }

    pcrawl->value=ptrie->count;
}

int search(my_trie *ptrie,char key[])
{
    int level,len,index;
    len=strlen(key);
    my_trie_node *pcrawl;
    pcrawl=ptrie->root;

    for(level=0;level<len;level++)
        {
            index=key[level]-96;

            if(pcrawl->child[index]==NULL)
            {
                return 0;
            }

            pcrawl=pcrawl->child[index];
        }

    if(pcrawl->value > 0)
    {
        if(pcrawl->checksum==0)
        {
            pcrawl->checksum=1;
            return 1;
        }
        else
            return 0;
    }
    else	return 0;
}

void sendtofile()
{
    fstream f1;
    f1.open("/home/vivek/QT/Text_search/permut.txt",fstream::in |fstream::out |fstream::app);
    //f1<<a<<endl;
    while(!s2.empty())
    {
        f1<<*s2.begin()<<endl;
        s2.erase(s2.begin());

    }
    f1.close();

}


void swap (char *x, char *y)
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
void permute(char *a, int i, int n)
{
   int j;
   if (i == n)
   {
     //printf("%s\n", a);
    // sendtofile(a);
       s2.insert(a);

   }
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
}



void otsa::on_pushButton_clicked()
{


       initialize(&mytrie);
       FILE *file=fopen("/home/vivek/QT/Text_search/file1.txt","r");
       char line[128];
       int i;
       for(i=0;i<128;i++)
       {
           line[i]='\0';
       }

       if(file!=NULL)
       {
           i=0;
           while(fgets(line,sizeof line,file)!=NULL)
           {


               int x=strlen(line);
               line[x-1]='\0';
               insert(&mytrie,line);

           }
           fclose(file);
       }

       ui->status->setText("TRIE INITIALISED");


}

void otsa::on_pushButton_2_clicked()
{

    int i,n,j,x;
    QString q,str;
    otsa ot;

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
    permute(arr1,0,l1-1);
    sendtofile();

}

void otsa::on_pushButton_3_clicked()
{

    clock_t begin,end;
    double time_spent;

    begin=clock();
    FILE *file=fopen("/home/vivek/QT/Text_search/permut.txt","r");
    char line[128];
    int i;
    for(i=0;i<128;i++)
    {
        line[i]='\0';
    }

    if(file!=NULL)
    {
        i=0;
        while(fgets(line,sizeof line,file)!=NULL)
        {


            int x=strlen(line);
            line[x-1]='\0';
            int y=search(&mytrie,line);
            if(y==1)
            {
                QString q;
                q.append(line);
                ui->result->appendPlainText(q);

            }

        }
        fclose(file);
    }

    end=clock();
    time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    QString ans=QString::number(time_spent);
    ui->time->setPlainText(ans);

}
