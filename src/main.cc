#include <QDebug>
#include <iostream>
#include <QByteArray>
#include <QDataStream>
#include <QFile>

using namespace std;

QByteArray TestSerialOut()
{
  int version = 1;
  double value = 2.33;
  QFile f("C:/Users/Nikola/Desktop/a.txt");
  f.open(QIODevice::Append);
  QString str_name = QObject::tr("This is an example");
  QByteArray b_result;
  QDataStream out(&b_result,QIODevice::WriteOnly);
  QDataStream out1(&f);
  out.setVersion(QDataStream::Qt_4_7);
  out1.setVersion(QDataStream::Qt_4_7);
  out<<version;
  out<<value;
  out<<str_name;

  out1<<version;
  out1<<value;
  out1<<str_name;

  qDebug()<<b_result.length()<<"\t"<<qstrlen(b_result.data());

  return b_result;
}


void TestSerialIn(QByteArray& b)
{
  QDataStream in(b);
  in.setVersion(QDataStream::Qt_4_7);
  int version;
  double value;
  QString s;
  in>>version;
  in>>value;
  in>>s;
  QFile f("C:/Users/Nikola/Desktop/a.txt");
  f.open(QIODevice::ReadOnly);
  QDataStream in1(&f);
  
  int version1;
  double value1;
  QString s1;

  in1>>version1;
  in1>>value1;
  in1>>s1;



  qDebug()<<version;
  qDebug()<<value;
  qDebug()<<s;
  cout<<endl;
  qDebug()<<version1;
  qDebug()<<value1;
  qDebug()<<s1;


}

int main()
{
  QByteArray b = TestSerialOut();
  TestSerialIn(b);


  cin.get();
  

  return 0;
}