#include <QDebug>
#include <iostream>
#include <QByteArray>
#include <QDataStream>


using namespace std;

QByteArray TestSerialOut()
{
  int version = 1;
  double value = 2.33;
  QString str_name = QObject::tr("This is an example");
  QByteArray b_result;
  QDataStream out(&b_result,QIODevice::WriteOnly);

  out.setVersion(QDataStream::Qt_4_7);

  out<<version;
  out<<value;
  out<<str_name;

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

  qDebug()<<version;
  qDebug()<<value;
  qDebug()<<s;



}

int main()
{
  QByteArray b = TestSerialOut();
  TestSerialIn(b);

  cin.get();
  

  return 0;
}