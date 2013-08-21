/*========================================================
#   FileName: window.h
#     Author: HaiLang
#      Email: hncskhkm@163.com
#   HomePage: 945488274@qq.com
#  CreatTime: 2013-08-16 23:28:10
=========================================================*/
#ifndef WINDOW_H
#define WINDOW_H

#include <QtGui>
#include <iostream>
#include <vector>
#include "Wuziqi.h"
#include "dialog.h"

using namespace std;
class Window : public QMainWindow
{
	Q_OBJECT
    	public:
	 Window(QWidget *parent = 0);
	 ~Window();
	protected:
	 void paintEvent(QPaintEvent *event);
	 void mousePressEvent(QMouseEvent *event);
  
    protected slots:
	void startGame(void);
    void stopGame(void);
//	void qiutGame(void);
    void showAbout(void);
    void setAlgorithm1(void);
    void setAlgorithm2(void);
    void setAlgorithm3(void);
    void fightAgainst (void);
	private:
    void dealMenu(void);
    private:
    int MenuBarSize;
    Wuziqi  game;
   vector<vector<int> > gamedata;
   int N;
   POINT lastPs;
   bool bRun;
   int Method;
   SelectDialog SelectDia;
    

};
#endif

