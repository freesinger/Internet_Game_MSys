#include "stdafx.h"
#include "Win32Project1.h"
#include<stdio.h>
#include<time.h>
#include<string.h>
int inde;
HWND  listview1;
HWND dia, dia2, dia3;
int isSaved = 1;   //�����Ƿ񱣴�
int c=0; /***************�������**************/

union index{      /**������׼**/
	double score;
	long t;
};

typedef struct player{          /**�����Ϣ**/
	char pname[15];
	char date[11];
	char gname[15];
	long t;
	double money;
	union index iindex;
	struct player *next;
}player;

typedef struct game{          /**��Ϸ��Ϣ**/
	char code[4];
	char name[15];
	char address[30];
	char cmode;
	char smode;
	int p;
	struct player *phead;
	struct game *next;
}game;

typedef struct category{    /**������Ϣ**/
	char code[4];
	char description[15];
	int g;
	struct game *ghead;
	struct category *next;
}category;

struct category *chead;        /**����ͷָ��**/

void creat(void);
void creatdata()        /**********���������ļ�**********/
{
	FILE *fp;
	int c = 0;
	fopen_s(&fp, "game.dat", "wb");
	fwrite(&c,sizeof(int),1,fp);
	fclose(fp);
}

BOOL loaddata(void);
BOOL loaddata()   /**********���������ļ�****************/
{
	FILE *fp; //*****************�ļ�ָ��****************************//
	if (fopen_s(&fp,"game.dat", "rb"))     /***�ļ��Ƿ����*****/
	{
		return FALSE;  /*******�ļ�������****/
	}
	fread(&c, sizeof(int), 1, fp); /***��ȡ������Ŀ***/
	int ci,o=0,o1=0,o2=0; /*******��������******/
	ci = c;
	category *cnow=NULL;
	game *gnow=NULL;
	player *pnow = NULL;     /****��������****/
	if (!c)                 /*******�ж�����Ƿ�Ϊ��******/
	{
		chead = NULL;
	}
	while (ci--)       /********��ȡ���********/
	{
		o1 = 0;
		if (o)                 /*******�ж��Ƿ�Ϊ��һ����𣬲������ڴ�*********/
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
		fread(cnow, sizeof(category), 1, fp);   /*********��ȡ���**********/
		int gi = cnow->g;          /***��ȡ������Ϸ��Ŀ**/
		if (!gi)         /***�ж���û����Ϸ***/
		{
			cnow->ghead = NULL;
		}
		
		while (gi--) /**********��ȡ��Ϸ************/
		{
			o2 = 0;
			if (o1)          /**�ж��Ƿ�Ϊ��һ����Ϸ���������ڴ�**/
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
			fread(gnow, sizeof(game), 1, fp);              /********��ȡ��Ϸ**********/
			int pi = gnow->p;           /***��ȡ��Ϸ�������Ŀ***/
			if ( !pi)              /***�ж���û�����***/
			{
				gnow->phead = NULL;
			}
			while (pi--)   /***��ȡ���***/
			{
				if (o2)   /*****�ж��Ƿ�Ϊ��һ����ң��������ڴ�******/
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
				fread(pnow, sizeof(player), 1, fp); /*****��ȡ���******/
				pnow->next = NULL;
			}
			gnow->next = NULL;
		}
		cnow->next = NULL;
	}	
	fclose(fp); /*************�ر������ļ�*********/
	return TRUE;
}

void backup(void);                    //���ݱ���
void backup()
{
	FILE *fp; 
	time_t t;
	time(&t);       //��ȡ��ǰϵͳʱ��  �ļ����ƽ���ʱ������
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
	fp = fopen(path, "wb");          //�����ļ�  ��׼��д��
	fwrite(&c, sizeof(int), 1, fp); //д�������
	int ci = c;
	category *cnow = chead;     //�����������ָ��
	game *gnow;
	player *pnow;
	while (ci--)           //д������
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

void savedata(void);          //���ݱ���
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

