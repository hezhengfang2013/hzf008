/*========================================================
#   FileName: dialog.h
#     Author: HaiLang
#      Email: hncskhkm@163.com
#   HomePage: 945488274@qq.com
#  CreatTime: 2013-08-16 22:06:02
=========================================================*/
#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H
#include <QtGui>

class QComboBox;
class QLayout;
class QSpinBox;
class Window;
class SelectDialog :public QDialog
{
	Q_OBJECT
	public:
	 SelectDialog(QWidget *parent  = 0 ,Qt::WindowFlags
			 f = Qt::Dialog);
     ~SelectDialog();
	 void getValue(int & bAlgo, int &wAlgo ,int &currentTimes );
	private slots:
	 void bAlgorithmChanged(int value);
	 void wAlgorithmChanged(int value);
	 void  OK();
	 void  currentTimesChanged(int value);

	private:
	 QComboBox *blackAlgorithm;
	 QComboBox *whiteAlgorithm;
	 QLabel *label1,*label2,*label3;
	 QSpinBox *currentTimesSlider;
	 QPushButton *okButton;

	 int bAlgorithm,wAlgorithm,times;

};


#endif

