#include "stdafx.h"
#include "Win32Project1.h"
#include<stdio.h>
#include<time.h>
#include<string.h>
int inde;
HWND  listview1;
HWND dia, dia2, dia3;
int isSaved = 1;   //数据是否保存
int c=0; /***************类别总数**************/

union index{      /**排名标准**/
	double score;
	long t;
};

typedef struct player{          /**玩家信息**/
	char pname[15];
	char date[11];
	char gname[15];
	long t;
	double money;
	union index iindex;
	struct player *next;
}player;

typedef struct game{          /**游戏信息**/
	char code[4];
	char name[15];
	char address[30];
	char cmode;
	char smode;
	int p;
	struct player *phead;
	struct game *next;
}game;

typedef struct category{    /**分类信息**/
	char code[4];
	char description[15];
	int g;
	struct game *ghead;
	struct category *next;
}category;

struct category *chead;        /**数据头指针**/

void creat(void);
void creatdata()        /**********创建数据文件**********/
{
	FILE *fp;
	int c = 0;
	fopen_s(&fp, "game.dat", "wb");
	fwrite(&c,sizeof(int),1,fp);
	fclose(fp);
}

BOOL loaddata(void);
BOOL loaddata()   /**********加载数据文件****************/
{
	FILE *fp; //*****************文件指针****************************//
	if (fopen_s(&fp,"game.dat", "rb"))     /***文件是否存在*****/
	{
		return FALSE;  /*******文件不存在****/
	}
	fread(&c, sizeof(int), 1, fp); /***读取类别的数目***/
	int ci,o=0,o1=0,o2=0; /*******变量声明******/
	ci = c;
	category *cnow=NULL;
	game *gnow=NULL;
	player *pnow = NULL;     /****结束声明****/
	if (!c)                 /*******判断类别是否为空******/
	{
		chead = NULL;
	}
	while (ci--)       /********读取类别********/
	{
		o1 = 0;
		if (o)                 /*******判断是否为第一个类别，并申请内存*********/
		{
			cnow ->next= (category*)malloc(sizeof(category));
			cnow = cnow->next;
		}
		else
		{
			o = 1;
			chead = (category *)malloc(sizeof(category));
			cnow = chead;
		}
		fread(cnow, sizeof(category), 1, fp);   /*********读取类别**********/
		int gi = cnow->g;          /***获取类别的游戏数目**/
		if (!gi)         /***判断有没有游戏***/
		{
			cnow->ghead = NULL;
		}
		
		while (gi--) /**********读取游戏************/
		{
			o2 = 0;
			if (o1)          /**判断是否为第一个游戏，并申请内存**/
			{
				gnow->next = (game*)malloc(sizeof(game));
				gnow = gnow->next;
			}
			else
			{
				o1 = 1;
				cnow->ghead = (game *)malloc(sizeof(game));
				gnow = cnow->ghead;
			}
			fread(gnow, sizeof(game), 1, fp);              /********读取游戏**********/
			int pi = gnow->p;           /***获取游戏的玩家数目***/
			if ( !pi)              /***判断有没有玩家***/
			{
				gnow->phead = NULL;
			}
			while (pi--)   /***读取玩家***/
			{
				if (o2)   /*****判断是否为第一个玩家，并申请内存******/
				{
					pnow->next = (player*)malloc(sizeof(player));
					pnow = pnow->next;
				}
				else
				{
					o2 = 1;
					gnow->phead = (player*)malloc(sizeof(player));
					pnow = gnow->phead;
				}
				fread(pnow, sizeof(player), 1, fp); /*****读取玩家******/
				pnow->next = NULL;
			}
			gnow->next = NULL;
		}
		cnow->next = NULL;
	}	
	fclose(fp); /*************关闭数据文件*********/
	return TRUE;
}

void backup(void);                    //数据备份
void backup()
{
	FILE *fp; 
	time_t t;
	time(&t);       //获取当前系统时间  文件名称将以时间命名
	tm now;
	char strtime[64];
	localtime_s(&now, &t);
	strftime(strtime, sizeof(strtime), "%Y-%m-%d %X ",&now);      
	char path[25];
	strcpy(path, strtime);
	strcat(path,".rec");
	path[13] = 'h';
	path[16] = 'm';
	path[19] = 's';
	path[24] = '\0';
	fp = fopen(path, "wb");          //创建文件  并准备写入
	fwrite(&c, sizeof(int), 1, fp); //写入总类别
	int ci = c;
	category *cnow = chead;     //声明链表操作指针
	game *gnow;
	player *pnow;
	while (ci--)           //写入数据
	{
		fwrite(cnow, sizeof(category), 1, fp);
		int gi = cnow->g;
		gnow = cnow->ghead;
		while (gi--)
		{
			fwrite(gnow, sizeof(game), 1, fp);
			int pi = gnow->p;
			pnow = gnow->phead;
			while (pi--)
			{
				fwrite(pnow, sizeof(player), 1, fp);
				pnow = pnow->next;
			}
			gnow = gnow->next;
		}
		cnow = cnow->next;
	}
	fclose(fp);
}

void savedata(void);          //数据保存
void savedata()
{
	FILE *fp;
	fp = fopen("game.dat", "wb");
	fwrite(&c, sizeof(int), 1, fp);
	int ci = c;
	category *cnow = chead;
	game *gnow;
	player *pnow;
	while (ci--)
	{
		fwrite(cnow, sizeof(category), 1, fp);
		int gi = cnow->g;
		gnow = cnow->ghead;
		while (gi--)
		{
			fwrite(gnow, sizeof(game), 1, fp);
			int pi = gnow->p;
			pnow = gnow->phead;
			while (pi--)
			{
				fwrite(pnow, sizeof(player), 1, fp);
				pnow = pnow->next;
			}
			gnow = gnow->next;
		}
		cnow = cnow->next;
	}
	fclose(fp);
}

