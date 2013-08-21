#include "window.h"

Window::Window(QWidget * parent)
	:QMainWindow(parent)
{
 QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
 setWindowTitle(tr("五子棋游戏"));
 N = 15;
 MenuBarSize =  10;
 setFixedSize(320+MenuBarSize,320+MenuBarSize);
 bRun = true;
 Method = 2;
 vector<int> temp(N,0);
 for(int i = 0; i < N; i++)
 {
   gamedata.push_back(temp);
 }
 dealMenu();
}
Window::~Window()
{
}

void Window::paintEvent(QPaintEvent *event)
{
 QPainter painter(this);
 painter.setBrush(Qt::lightGray);
 painter.drawRect(0,0,size().width(),size().height());
 game.GetData(gamedata);
 for (int x = 20 + MenuBarSize; x <= N*20 + MenuBarSize; x +=20)
 {
  painter.drawLine(x,20 + MenuBarSize , x, N*20 + MenuBarSize);
 }


 for (int y = 20 + MenuBarSize; y <= N*20 + MenuBarSize; y +=20)
 {
  painter.drawLine(y,20 + MenuBarSize , y, N*20 + MenuBarSize);
 }
QPainter blackPainter(this);
QPainter whitePainter(this);
QPainter greenPainter(this);
blackPainter.setBrush(Qt::black);
whitePainter.setBrush(Qt::white);
greenPainter.setBrush(Qt::green);
for (int x = 0; x < N; x++)
{ 
 for(int y = 0; y <  N; y++)
 {
  if(gamedata[x][y] == 1)
  {
   blackPainter.drawEllipse((x + 1)*20 - 10 + MenuBarSize,
		   (y + 1)*20 - 10 + MenuBarSize,20 ,20);
  }
  else if (gamedata[x][y] == 2)
  {
   whitePainter.drawEllipse((x + 1)*20 - 10 + MenuBarSize,
		   (y + 1)*20 -10 +MenuBarSize, 20, 20);
   }
  }
 }
if(lastPs.x >=0 && lastPs.y >=0)
{
 greenPainter.drawEllipse((lastPs.x + 1)*20 -10 +MenuBarSize,
		 (lastPs.y + 1)*20 - 10 + MenuBarSize,20,20);
}
QMainWindow::paintEvent(event);
}
void Window::mousePressEvent(QMouseEvent *event)
{
 if(event->button() == Qt::LeftButton && bRun ==true)
 {
  int x = event->x();
  int y = event->y();
  POINT ps;
  ps.x = x;
  ps.y = y;
  if(ps.x < 10 +MenuBarSize || ps.y < 10 + MenuBarSize
		  ||ps.x > 300 + 20 + MenuBarSize)
  {
   return ;
  }
  if(!game.Fall(ps, 1, 20 + MenuBarSize, 300 + 20 + MenuBarSize))
  {
   return ;
  }
  game.Run(ps,Method,2);
  lastPs = ps;
  ps.x = 20 + MenuBarSize + ps.x*20;
  ps.y = 20 + MenuBarSize + ps.y*20;
  game.Fall(ps, 2 , 20 +MenuBarSize, 300 + 20 + MenuBarSize);
  game.GetData(gamedata);
  update();
  int who = 0;
  game.Judge(who);
  if(who == 1)
  {
    QMessageBox::information(this, tr("游戏结束"),tr(" 你赢了，游戏结束！"));
	bRun = false;
  }
  else if (who ==2)
  {
   QMessageBox::information(this,tr("游戏结束"),tr("你输了，游戏结束 "));
   bRun = false;
  }
 }
}
void Window::dealMenu(void)
{
QMenuBar *MenuBar = new QMenuBar(this);
QMenu   *GameMenu = new QMenu(tr("游戏"),MenuBar);
QMenu   *AlgorithmMenu = new QMenu (tr(" 算法"),MenuBar);
QMenu  *HelpMenu  = new QMenu (tr("帮助"),MenuBar);

QAction *StartGame = new QAction(tr("开始游戏"),GameMenu);
QAction *StopGame = new QAction (tr("结束游戏"),GameMenu);
QAction *QuitGame = new QAction (tr("推出游戏"),GameMenu);
GameMenu->addAction(StartGame);
GameMenu->addAction(StopGame);
GameMenu->addAction(QuitGame);
MenuBar->addMenu(GameMenu);
connect(StartGame,SIGNAL(triggered()),this,SLOT(startGame()));
connect(StopGame,SIGNAL(triggered()),this,SLOT(stopGame()));
connect(QuitGame,SIGNAL(triggered()),this,SLOT(close()));
QAction *Algorithm1 = new QAction(tr("算法1：完全随即下棋"),
		AlgorithmMenu);
QAction *Algorithm2 = new QAction(tr("算法2：贪心算法"),AlgorithmMenu);
QAction *Algorithm3 = new QAction(tr("改进的随机算法间 "),AlgorithmMenu);
QAction *Against = new QAction(tr("算法间的对战"),AlgorithmMenu);
AlgorithmMenu->addAction(Algorithm1);
AlgorithmMenu->addAction(Algorithm2);
AlgorithmMenu->addAction(Algorithm3);
AlgorithmMenu->addAction(Against);
MenuBar->addMenu(AlgorithmMenu);
connect(Algorithm1,SIGNAL(triggered()),this,SLOT(setAlgorithm1()));
connect(Algorithm2,SIGNAL(triggered()),this,SLOT(setAlgorithm2()));
connect(Algorithm3,SIGNAL(triggered()),this,SLOT(setAlgorithm3()));
connect(Against,SIGNAL(triggered()),this,SLOT(fightAgainst()));

QAction *About  = new QAction(tr("关于"),HelpMenu);
HelpMenu->addAction(About);
MenuBar->addMenu(HelpMenu);
connect(About,SIGNAL(triggered()),this,SLOT(showAbout()));
setMenuBar(MenuBar);
}

void Window::startGame(void)
{
	if(bRun == false)
	{
 bRun = true;
 game.Clear();
 game.Init();
 lastPs.x = -1 ;lastPs.y = -1;
 update();
}
}
void Window::stopGame(void)
{
	if(bRun == false)
	{
 bRun = true;
 game.Clear();
 //game.Init();
 lastPs.x = -1 ;lastPs.y = -1;
 update();
}
}
 void Window::showAbout(void)
{
 QMessageBox::information(this,tr("关于五子棋游戏"),
		 tr("Qt程序：五子棋游戏1.0"));
}
void Window::setAlgorithm1(void)
{
 if(Method == 1)
 { return ;}
 stopGame();
 Method = 1;
 startGame();
}

void Window::setAlgorithm2(void)
{
 if(Method == 2)
 { return ;}
 stopGame();
 Method = 2;
 startGame();
}
void Window::setAlgorithm3(void)
{
 if(Method == 3)
 { return ;}
 stopGame();
 Method = 3;
 startGame();
}

void Window::fightAgainst(void)
{
 stopGame();
 int Who =0;
 Wuziqi  *testGame;
 SelectDia.exec();
 int bAlgorithm,wAlgorithm,times,alltimes;
 SelectDia.getValue(bAlgorithm,wAlgorithm,times);
 bAlgorithm++;
 wAlgorithm++;
 POINT ps;
 int wTimes = 0 , bTimes = 0;
 alltimes = times;
  srand(time(NULL));
  for( int i = 0; i < times; i++)
  {
	  testGame = new Wuziqi(N);
	  int side = rand()%2;
	  while(Who == 0)
	  {
	   if( side == 0)
	   {
	  
   testGame->Run(ps,bAlgorithm,1);
   ps.x = ps.x*20 + 20 + MenuBarSize;
   ps.y = ps.y*20 + 20 + MenuBarSize;
   testGame->Fall(ps, 1, 20 + MenuBarSize, 300  + 20 + MenuBarSize);
   testGame->GetData(gamedata);
   testGame->Judge(Who);
	   
   testGame->Run(ps, wAlgorithm, 2);
   ps.x = ps.x*20 + 20 + MenuBarSize;
   ps.y = ps.y*20 + 20 + MenuBarSize;
   testGame->Fall(ps, 2, 20 + MenuBarSize, 300 + 20 + MenuBarSize);
   testGame->GetData(gamedata);
   testGame->Judge(Who);
  }
	   else if( side == 1)
	   {
	  
   testGame->Run(ps,bAlgorithm,2);
   ps.x = ps.x*20 + 20 + MenuBarSize;
   ps.y = ps.y*20 + 20 + MenuBarSize;
   testGame->Fall(ps, 2, 20 + MenuBarSize, 300  + 20 + MenuBarSize);
   testGame->GetData(gamedata);
   testGame->Judge(Who);
	   
   testGame->Run(ps, wAlgorithm, 1);
   ps.x = ps.x*20 + 20 + MenuBarSize;
   ps.y = ps.y*20 + 20 + MenuBarSize;
   testGame->Fall(ps, 1, 20 + MenuBarSize, 300 + 20 + MenuBarSize);
   testGame->GetData(gamedata);
   testGame->Judge(Who);
  }
	   if(Who == 1)
	   {
		   bTimes++;
	   }
	   else if (Who == 2)
	   {
	    wTimes++;
	   }
	   else if( Who == 3)
	   {
	    alltimes--;
	   }
	  }
	   Who = 0;
	    testGame->Clear();
		delete testGame;
}
if (alltimes == 0)
{
 alltimes = 1;
}
 double pbWin = (double) (bTimes)/(double)alltimes;
 double pwWin = (double) (wTimes)/(double)alltimes;
QString information ,numStr;
QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
information +="测试结束，（heiqi）算法" ;
numStr.setNum(bAlgorithm);
information +=numStr;
numStr.clear();

information +="胜利次数：" ;
numStr.setNum(bTimes);
information +=numStr;
numStr.clear();

information +=" 胜利平率" ;
numStr.setNum(pbWin);
information +=numStr;
numStr.clear();

information +="白棋 算法" ;
numStr.setNum(wAlgorithm);
information +=numStr;
numStr.clear();
information +="胜利次数" ;
numStr.setNum(wTimes);
information +=numStr;
numStr.clear();

information +="胜利频率" ;
numStr.setNum(pwWin);
information +=numStr;
numStr.clear();
QMessageBox::information(this,tr("算法对战结果:"),information);
information.clear();
}

