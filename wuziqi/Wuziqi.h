/*========================================================
#   FileName: Wuziqi.h
#     Author: HaiLang
#      Email: hncskhkm@163.com
#   HomePage: 945488274@qq.com
#  CreatTime: 2013-08-17 02:06:43
=========================================================*/
#ifndef WUZIQI_H
#define WUZIQI_H
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;
class POINT
{
	public:
 int x;
 int y;
//	public:
 POINT(const int X = -1,const int Y = -1)
 {
  x = X; y =Y; 
 }
};
class Wuziqi
{
	private:
int N;
vector<vector<int> > Data;
POINT ps_Now;
int Total;

	public:
Wuziqi(const int n =15);
~Wuziqi(void);
void Init(void);
void Judge(int &Who);
void GetData(vector<vector<int> > &data);

bool Fall(const POINT & ps, const int & who,
		const int & beginPos, const int & endPos);
bool UnFall(const POINT & ps,const int & who,
		const int & beginPos,const int & endPos);
void Clear(void);
void Run(POINT & ps, const int & Which,const int & Who);
	private:
bool ChangedPos(const POINT & srcPos ,POINT & desPos,
	   const int & beginPos,const int & endPos	);

	private:
void Way1(POINT & ps);
void Way2(POINT & ps);
void SetScore(const int i, const int j, const int Who,
		vector<vector<int> >& state);
int p_Score(int num, int bp[]);
bool first;
/*
void Way3(POINT & ps);
void Way (POINT &ps);
int maxDepth;
int depth;
void setDepth(const int &dep);
void Search(const  int & i,const int & j);
vector<vector<int> > & bestStep;
*/
};


#endif

