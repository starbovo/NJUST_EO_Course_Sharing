#include <graphics.h>//图形头文件
#include <stdio.h>
#include <math.h>
#include <mmsystem.h>//多媒体头文件
#include<string>
#include<iostream>
#include<stdlib.h>
#pragma comment(lib,"winmm.lib")//播放音乐的库文件

using namespace std;

//#define	MaxVal 1000;
//变量变为常量 
//暂时失败

class Chess 
{
public:
	void initGame();    //打印棋盘并且初始化函数
	void playChess();   //下棋操作，包含重来功能
	int judge(int a,int b);   //判断是否结束 ！！！而非输赢
	void rule();       //打印告知与规则
	void num();        //打印输赢次数

};

//记录玩家姓名
string name1, name2;

//标记黑棋白棋
int flag = 0;		

//标记是否平局
int flag2 = 0;

//0表示没有下棋的状态 奇数表示黑棋 偶数表示白棋
int board[20][20] = { 0 };	

//动态存储当次下棋的坐标
int stack[2] = { 0 };

//储存输赢次数
int n1 = 0, n2 = 0,n3=0;

Chess x1;
int main()
{
	//进行游戏
	x1.rule();
	cout << "请输入玩家一的姓名：";
	cin >> name1;
	cout << "请输入玩家二的姓名：";
	cin >> name2;
	system("cls");
	//打印棋盘和初始化游戏
	x1.initGame();	

	x1.playChess();

	//关闭界面
	closegraph();

	x1.num();

	return 0;
}
void Chess::rule()
{   
	cout << "玩家一使用黑棋"<<endl
		 << "玩家二使用白棋"<<endl
		 << "第一局黑棋先手，白棋后手"<<endl
	     << "下一句再进行交替" << endl
		 << "请不要在边缘处下棋"<<endl
		 << "祝你有一个愉快的体验！"<<endl
		 << "OvO" << endl;
	cout << "Written by 蒋航" << endl;
	cout << endl << endl;
	cout << "按<ENTER>继续";
	int n = getchar();
	system("cls");
}
void Chess::initGame()
{
	string name1, name2;
	initgraph(600, 500);						//绘图环境	
	//提供绘图环境,窗口宽高  库函数
	initgraph(600, 500);
	setbkcolor(LIGHTBLUE);//设置颜色
	cleardevice();//刷新颜色
	mciSendString("open quiteMusic.mp3", 0, 0, 0);	//打开音乐
	mciSendString("play quiteMusic.mp3", 0, 0, 0);	//播放音乐
	//绘制棋盘
	setlinecolor(RED);						//设置线条颜色为黑色
	for (int i = 1; i < 20; i++)
	{
		line(0, i * 25, 500, i * 25);	//绘制线条
		line(i * 25, 0, i * 25, 500);
	}
	setlinestyle(PS_SOLID, 2);			//设置线条为实线,宽度为2
	line(500, 0, 500, 500);				//边界线
	outtextxy(512, 60, "玩家1:黑棋");
	//outtextxy(512, 80, name1);
	outtextxy(512, 100, "玩家2:白棋");
	//outtextxy(512, 120, name2);
	outtextxy(512, 140, "右键悔棋！");
}

void push(int x, int y)
{
	stack[0] = x;
	stack[1] = y;
}

void Chess::playChess()
{
	int x = 0, y = 0;
	int a = 0, b = 0;
	MOUSEMSG m;		//定义鼠标消息
	HWND hwnd;
		//窗口句柄，窗口置前
	hwnd = GetHWnd();
	while (1)		//实现不断下棋
	{
		m = GetMouseMsg();			//获取一个鼠标消息

		//求距离绝对值
		for (int i = 1; i < 20; i++)
		{
			for (int j = 1; j < 20; j++)
			{
				if (abs(m.x - i * 25) < 12 && abs(m.y - j * 25) < 12)
				{
					a = i;
					b = j;
					x = i * 25;
					y = j * 25;
				}
			}
		}

		if (m.uMsg == WM_LBUTTONDOWN)	//判断当前鼠标消息是不是鼠标左键按下
		{
			if (board[a][b] != 0)
			{
				MessageBox(hwnd, "这里已经有棋子了,请重新选择.", "五子棋", MB_OK);
				continue;
			}
			push(a, b);
			if (flag % 2 == 0)
			{
				setfillcolor(BLACK);
				solidcircle(x, y, 10);
				board[a][b] = 1;
			}
			else
			{
				setfillcolor(WHITE);
				solidcircle(x, y, 10);
				board[a][b] = 2;
			}
			flag++;
		}
		else if (m.uMsg == WM_RBUTTONDOWN)//检测是不是右键按下 悔棋操作
		{
			board[stack[0]][stack[1]] = 0;
			flag--;
			x1.initGame();
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 20; j++) {
					if (board[i][j] == 1) {
						setfillcolor(BLACK);
						solidcircle(i * 25, j * 25, 10);
					}
					else if (board[i][j] == 2) {
						setfillcolor(WHITE);
						solidcircle(i * 25, j * 25, 10);
					}
				}
			}
		}
		//此处才来判断谁输谁赢
		if (x1.judge(a, b))
		{
			if (1 == flag % 2)
			{
				n1++;
				if (MessageBox(hwnd, "玩家1胜利，是否重新开始游戏", "游戏结束", MB_OKCANCEL) == IDOK)
				{
					x1.initGame();
					memset(board, 0, sizeof(board));
					continue;
				}
				return;	
			}
			else if(0 == flag % 2)
			{
				n2++;
				if (MessageBox(hwnd, "玩家2胜利，是否重新开始游戏", "游戏结束", MB_OKCANCEL) == IDOK)
				{
					x1.initGame();
					memset(board, 0, sizeof(board));
					continue;
				}
				return;	
			}
			else if (flag2 == -1)
			{
				n3++;
				if (MessageBox(hwnd, "平局，是否重新开始游戏", "游戏结束", MB_OKCANCEL) == IDOK)
				{
					x1.initGame();
					memset(board, 0, sizeof(board));
					continue;
				}
				return;
			}
		}
	}
}

//判断是否结束 a，b为数组的值
int Chess::judge(int a, int b)
{
	int i, j;
	int t = 2 - flag % 2;
	for (i = a - 4, j = b; i <= a; i++)
	{
		if (i >= 1 && i < 16 && t == board[i][j] && t == board[i + 1][j] && t == board[i + 2][j]
			&& t == board[i + 3][j] && t == board[i + 4][j])
			return 1;
	}
	for (i = a, j = b - 4; j <= b; j++)
	{
		if (j >= 1 && j < 16 && t == board[i][j] && t == board[i][j + 1]
			&& t == board[i][j + 2] && t == board[i][j + 3] && t == board[i][j + 4])
			return 1;
	}
	for (i = a - 4, j = b - 4; i <= a, j <= b; i++, j++)
	{
		if (i >= 1 && i < 16 && j >= 1 && j < 16 && t == board[i][j] && t == board[i + 1][j + 1] &&
			t == board[i + 2][j + 2] && t == board[i + 3][j + 3] && t == board[i + 4][j + 4])
			return 1;
	}
	for (i = a - 4, j = b + 4; i <= a, j >= b; i++, j--)
	{
		if (i >= 1 && i < 16 && j >= 1 && j < 16 && t == board[i][j] && t == board[i + 1][j - 1] &&
			t == board[i + 2][j - 2] && t == board[i + 3][j - 3] && t == board[i + 4][j - 4])
			return 1;
	}
	for (int x = 0; x < 20; x++)
	{
		for(int y = 0; y < 20; y++)
		{
			if (board[x][y] == 0) flag2 = -1;
		}
	}
	return 0;

}
void Chess::num()
{
	cout << name1 << "使用黑棋赢了" << n1 << "次"<<endl;
	cout << name2 << "使用白棋赢了" << n2 << "次"<<endl;
	cout<<name1<<"和" << name2<<"平局了"<<n3<<"次" <<endl;
	cout << endl << endl;
	if (n1 > n2) cout << name1 << "更胜一筹。"<<endl;
	if (n1 < n2) cout << name2 << "更胜一筹。"<<endl;
	if (n1 == n2) cout << name1 << "和" <<name2<<"打了个平手" << endl;

}