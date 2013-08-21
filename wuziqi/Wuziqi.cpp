#include "Wuziqi.h"

Wuziqi::Wuziqi(const int n)
{
 N = n;
 Init();
}
Wuziqi::~Wuziqi(void)
{
}
void Wuziqi::Init(void)
{
 vector<int>  temp(N, 0);
 for(int i = 0; i < N; i++)
 {
   Data.push_back(temp);
 }
 first  = true;
}

void Wuziqi::GetData(vector<vector<int> > & data)
{
 data.clear();
 data.resize(N);
 for(int i = 0; i < N; i++)
 {
  data[i].resize(N);
 
  for(int j = 0; j < N; j++)
  {
    data[i][j] = Data[i][j];
  }
 }
}
void  Wuziqi::Judge(int & Who)
{
if(Total == N*N)
{
 Who = 3;
 return;
}
int state =0;
for(int x = 0; x < N; x++)
{
 for(int y = 0; y < N; y++)
 {
	 if(Data[x][y] == 0)
	 {
	  continue;
	 }
	 for(int i =0 ; i < 4; i++)
	 {
	  int k, j;
	  switch (i)
	  {
	   case 0 :
		   k  = x + 1;
		   while ( k < N && Data[k][y] == Data[x][y])
		   {
		    state++;
			k++;
		   }
		   if(state >= 4)
		   {
		    Who = Data[x][y];
			return  ;
		   }
		   else 
		   {
		   state = 0;
		   }
		   break;
	   case 1:
              j = y+1;
			  while(j < N && Data[x][j] ==Data[x][y] )
			  {
			   state++;
			   j++;
			  }
			  if (state >= 4)
			  {
			   Who = Data[x][y];
			   return;
			  }
			  else 
			  {
			   state = 0;
			  }
              break;
	   case 2:
			   k = x+1;
			   j = y+1;
			   while(k < N && j < N
					   && Data[k][j] == Data[x][y])
			   {
			    state++;
				k++;
				j++;
			   }
			   if(state >= 4)
			   {
			    Who = Data[x][y];
				return ;
			   }
			   else
			   {
			    state = 0;	
			   }
			   break;

		 case 3:
			   k = x - 1;
			   j = y + 1;
			   while(k >= 0 && j < N &&Data[k][j] ==Data[
					   x][y])
			   {
			    state++;
				k--;
				j++;
			   }
			   if(state >= 4)
			   {
			    Who = Data[x][y];
				return ;
			   }
			   else
			   {
			    state = 0;
			   }
			   break;
		 default:
			   break;

	  }
	 } 
 }
}
 Who = 0;
 return ;
}

bool Wuziqi::ChangedPos(const POINT & srcPos,
		POINT & desPos,const int & beginPos,
		const int & endPos)
{
 if(srcPos.x < beginPos || srcPos.y <beginPos
		 || srcPos.x > endPos || srcPos.y >
		 endPos)
 {
  return false;
 }
 desPos.x = -1;
 desPos.y = -1;

 for (int i = 0; i < N; i++)
 {
  if(srcPos.x > beginPos + i*20 -10 &&
		  srcPos.x <= beginPos + i*20 + 10)
  {
   desPos.x = i;
   break;
  }
 }
 for (int i = 0; i < N; i++)
 {
   if(srcPos.y > beginPos + i*20 - 10 &&
		   srcPos.y <= beginPos + i*20 +10)
	   {
	    desPos.y = i;
		break;
	   }
 }

 return true;
}

bool  Wuziqi::Fall(const POINT & ps,const int &
		who, const int & beginPos, const int & endPos)
{
 POINT tempPos;
 if(ChangedPos(ps,tempPos,beginPos,endPos) == false)
 {
  return false;
 }
 if(tempPos.x < 0 || tempPos.y < 0)
 {
	 return false;
 }
 if(Data[tempPos.x][tempPos.y] == 0)
 {
  if (who == 1 || who ==2)
  {
    ps_Now.x = tempPos.x;
	ps_Now.y = tempPos.y;
  }
  Total++;
  return true;
 }
 else
 {
  return false;
 }
}


bool  Wuziqi::UnFall(const POINT & ps,const int & who,
		const int & beginPos,const int & endPos)
{
 POINT  tempPos;
 if(ChangedPos(ps, tempPos, beginPos, endPos) == false)
 {
  return false;
 }
 if(tempPos.x < 0 || tempPos.y < 0)
 {
 return false;
 }
 if(Data[tempPos.x][tempPos.y] == who)
 {
  Data[tempPos.x][tempPos.y] = 0;
  Total--;
  return true;
 }
 else {
  return false;
 }

}
void Wuziqi::Clear(void)
{
 for(int x = 0; x <  N; x++)
 {
  for(int y = 0; y < N; y++)
  {
  Data[x][y] = 0;
  }
 }
 Total = 0;

}
void  Wuziqi::Run(POINT  & ps,const int & Which,
		const int & Who)
{
if(Which == 1)
{
 Way1(ps);
}
else if(Which == 2)
{
if(ps.x == -1  || ps.y == -1)
{
 return;
}
}
 else if(Which == 3)
{
  //Way3(ps);
}
 return;
}
//
void Wuziqi::Way1(POINT & ps)
{
 int x = 0;
 int y = 0;
 srand(time(NULL));
 x = rand()%N;
 y = rand()%N;
 while (Data[x][y] != 0)
 {
  x = rand()%N;
  y = rand()%N;
 }
 ps.x = x;
 ps.y = y;
 
}
void Wuziqi::Way2(POINT & ps)
{
 if(Total == 0)
 {
  ps.x = rand()%N;
  ps.y = rand()%N;
  return ;
  }
vector<vector<int> > HumanState,ComputerState;
vector<int> temp(N,0);
for(int i = 0; i < N; i++)
{
	HumanState.push_back(temp);
	ComputerState.push_back(temp);
}
POINT ps1,ps2;
for(int i = 0; i < N; i++)
{
for(int j = 0; j < N; j ++)
{
  if(Data[i][j] == 0)
  {
   SetScore(i, j, 1, HumanState);
   SetScore(i, j, 2, ComputerState);
  }
}
}
 int maxP = 0, maxC =0;
 for(int i =0; i < N; i++)
{
   for(int j =0; j < N ; j ++)
   {
     if(HumanState[i][j] > maxP)
	 {
	  maxP = HumanState[i][j];
	  ps1.x = i;
	  ps1.y = j;
	 }
	 if(ComputerState[i][j] > maxC)
	 {
	  maxC = ComputerState[i][j];
	  ps2.x = i;
	  ps2.y = j;
	 }
   }
}
if(maxP >= maxC)
{
 ps.x = ps1.x;
 ps.y = ps1.y;
}
else 
{
 ps.x = ps2.x;
 ps.y = ps2.y;
}
}
void Wuziqi::SetScore(const int i,const int j,
		const int Who,
		vector<vector<int> > & State)
{
 int Another;
 if(Who == 1)
 {
  Another = 2;
 }
 else if(Who == 2)
 {
  Another =1;
 }
 else 
 {
 return ;
 }

 int bp[2] , k, num, max=0, temp = 0;
 bp[0] = 1; bp[1]=1;
 num  = 0;
 for (k = 1; k < N; k++)
 {
 if(Data[i+k][j] == Who)
 {
  num++;
  continue;
 }
 if(Data[i+k][j] == 0)
 {
  bp[1] = 0;
  break;
 }
if(Data[i+k][j] == Another)
{
 bp[1] = 1;
 break;
}
 }
for(k = 1; k <=i; k++)
{
 if(Data[i - k][j] == Who)
 {
  num++;
  continue;
 }
 if(Data[i - k][j] == 0)
 {
  bp[0] = 0; 
  break;
 }
 if(Data[i - k][j] == Another)
  {
   bp[0] = 1;
   break;
 }
}
 temp = p_Score(num, bp);
 max += temp;
 bp[0] = 1;
 bp[1] = 1;
  num = 0;
for( k = 1; k < N - j; k++)
{
 if(Data[i][j + k] == Who)
 {
  num++;
  continue;
 }
  if(Data[i][j + k] == 0)
  {
   bp[1] = 0;
   break;
  }
  if(Data[i][j + k] == Another )
  {
   bp[1] = 1;
   break;
  }
}

for( k = 1; k < j; k++)
{
 if(Data[i][j - k] == Who)
 {
  num++;
  continue;
 }
  if(Data[i][j - k] == 0)
  {
   bp[0] = 0;
   break;
  }
  if(Data[i][j - k] == Another )
  {
   bp[0] = 1;
   break;
  }
}
temp = p_Score(num,bp);
max += temp;
bp[0] = 1;
bp[1] =1;
num = 0;

for( k = 1; k < N - i && k <N -j; k++)
{
 if(Data[i + k][j + k] == Who)
 {
  num++;
  continue;
 }
  if(Data[i + k][j + k] == 0)
  {
   bp[1] = 0;
   break;
  }
  if(Data[i + k][j + k] == Another )
  {
   bp[1] = 1;
   break;
  }
}

for( k = 1; k <= j && k <= i; k++)
{
 if(Data[i - k][j - k] == Who)
 {
  num++;
  continue;
 }
  if(Data[i - k][j - k] == 0)
  {
   bp[0] = 0;
   break;
  }
  if(Data[i - k][j - k] == Another )
  {
   bp[0] = 1;
   break;
  }
}

temp = p_Score(num, bp);
bp[0] = 1;
bp[1] = 1;
num = 0;

for( k = 1; k < N - j && k <= i; k++)
{
 if(Data[i - k][j + k] == Who)
 {
  num++;
  continue;
 }
  if(Data[i - k][j + k] == 0)
  {
   bp[1] = 0;
   break;
  }
  if(Data[i - k][j + k] == Another )
  {
   bp[1] = 1;
   break;
  }
}

for( k = 1; k < j && k < N -i; k++)
{
 if(Data[i + k][j - k] == Who)
 {
  num++;
  continue;
 }
  if(Data[i + k][j - k] == 0)
  {
   bp[0] = 0;
   break;
  }
  if(Data[i + k][j - k] == Another )
  {
   bp[0] = 1;
   break;
  }
}
temp = p_Score(num, bp);
max +=temp;
if(max > State[i][j])
{
 State[i][j] = max;
}
}

int Wuziqi::p_Score(int num, int bp[])
{
 int max = 0;
 if(num >= 4)
 {
  max += 10000;
 }
 else if(num ==3)
 {
   if(bp[1] == 1 && bp[0] == 1)
   {
    max +=0;
   }
   else if(bp[1] == 0 && bp[0] ==0)
   {
    max +=3000;
   }
   else 
   {
	   max += 900;
   }
 }
 else if(num == 2)
 {
  if(bp[0] == 0 && bp[1] == 0)
  {
    max +=460;
  }
   else if(bp[0] == 1 && bp[1] == 1)
   {
     max +=0;
   }
  else
  {
   max +=30;
  }
 }
 else if(num == 1)
 {
  if(bp[0] == 0 && bp[1] ==0)
  {
    max +=45;
  }
  else if( bp[0] == 1 && bp[1] ==1)
  {
   max += 0;
  }
  else 
  {
   max += 5;
  }
 }
 else if(num == 0)
 {
  if(bp[0] == 0 && bp[1] == 0)
  {
   max += 3;
  }
  else if(bp[0] == 1 && bp[1] == 1)
  {
   max += 0;
  }
  else 
  {
   max +=1;
  }
 }
return max;
}

/*
void Wuziqi::Way3(POINT & ps)
{
 const int ChooseN = 100;
 int n;
 if(N*N -total <= ChooseN)
 {
  n = N*N -Total;
 }
 else
 {
  n = ChooseN;
 }
 srand(time(NULL));
 vector<POINT> Choose(2*n);
 vector<int>Value(2*n);

 vector<vector<int> > HumanState,ComputerState;
 vector<int> temp(N, 0);
 for(int i =0; i < N; i++)
 {
  HumanState.push_back(temp);
  ComputerState.push_back(temp);
 }
for(int i = 0 ; i < n; i++)
{
 POINT tempPs;
 do
 {
     tempPs.x = rand()%N;
	 tempPs.u = rand()%N;
 }
 while (Data[tempPs.x][tempPs.y] != 0);
 setScore(tempPs.x, tempPs.y, 1, HumanState);
 setScore(tempPs.x, tempPs.y, 2  ComputerState);
  
 Choose[i].x = tempPs.x;
 Choose[i].y = tempPs.y;
 Value[i] = HumanState[tempPs.x][tempPs.y];
 Choose[i + ChooseN].x = tempPs.x;
 Choose[i + ChooseN].y = tempPs.y;
 Value[i + ChooseN] = HumanState[tempPs.x][tempPs.y];
}
 int MaxP = 0;
 int MaxC = 0;
 for(int i ; i < ChooseN; i++)
{
 if(Value[i] > MaxP)
 {
  MaxP = i;
 }
 if(Value[i + ChooseN] > MaxC)
 {
  MaxC = i + ChooseN;
 }
}
if(Value[MaxP] >= Value[MaxC])
{
 ps.x = Choose[MaxP].x;
 ps.y = Choose[MaxP].y;
}
else 
{
 ps.x = Choose[MaxC].x;
 ps.y = Choose[MaxC].y;
}
}
*/
