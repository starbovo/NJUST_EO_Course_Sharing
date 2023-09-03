// 项目名称 :  二叉树操作 
// 指导老师 :  徐新华 
// 作者     :  张悦熠 
// 学号     :  9211040G0637 
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<windows.h>
#define maxn 10000
using namespace std;
int opt,l,r,p,k,root;
char type;
struct node{
	int key,l,r,val,size,sum;
}tree[maxn];
class fhqtree
{
public:
	int add(int x)
	{
		tree[++k].key=rand();
		tree[k].size=1;
		tree[k].val=x;
		tree[k].sum=tree[k].val;
		return k;
	}
	void update(int id)
	{
		tree[id].size=tree[tree[id].l].size+tree[tree[id].r].size+1;
		tree[id].sum=tree[tree[id].l].sum+tree[tree[id].r].sum+tree[id].val;
	}
	void split(int u,int x,int &l,int &r)
	{
		if(!u)
		{
			l=r=0;
			return ;
		}
		if(x>=tree[u].val)
		{
			l=u;
			split(tree[u].r,x,tree[u].r,r);
		}
		else
		{
			r=u;
			split(tree[u].l,x,l,tree[u].l);
		}
		update(u);
	}
	int merge(int l,int r)
	{
		if(!l||!r) return l+r;
		if(tree[l].key<=tree[r].key)
		{
			tree[l].r=merge(tree[l].r,r);
			update(l);
			return l;
		}
		else
		{
			tree[r].l=merge(l,tree[r].l);
			update(r);
			return r;
		}
	}
	int kth(int u,int x)
	{
		if(tree[tree[u].l].size+1==x) return u;
		if(tree[tree[u].l].size>=x) return kth(tree[u].l,x);
		return kth(tree[u].r,x-tree[tree[u].l].size-1);
	}
	int find(int u,int x)
	{
		if(tree[u].val==x) return u;
		if(!tree[u].l && tree[u].val>x) return 0;
		if(!tree[u].r && tree[u].val<x) return 0;
		if(tree[u].val>x) return find(tree[u].l,x);
		if(tree[u].val<x) return find(tree[u].r,x);
	}
	void dfs(int u)
	{
		printf("%d ",tree[u].val);
		if(tree[u].l) dfs(tree[u].l);
		if(tree[u].r) dfs(tree[u].r);
	}
	void print(int u,int deep)
	{
		if(tree[u].r) print(tree[u].r,deep+1);
		for(int i=1;i<deep;i++) printf("      ");
		printf("| %d |\n",tree[u].val);
		if(tree[u].l) print(tree[u].l,deep+1);
	}
	void sort_min_to_max(int u){
		if(tree[u].l) sort_min_to_max(tree[u].l);
		printf("%d ",tree[u].val);
		if(tree[u].r) sort_min_to_max(tree[u].r);
	}
	void sort_max_to_min(int u){
		if(tree[u].r) sort_max_to_min(tree[u].r);
		printf("%d ",tree[u].val);
		if(tree[u].l) sort_max_to_min(tree[u].l);
	}
}fhq;
class UI
{
public:
	void menu()
	{
		printf("-----------------------------------------\n");
		printf("|项目 : 二叉树操作                      |\n");
		printf("|                                       |\n");
		printf("|指导老师 : 徐新华                      |\n");
		printf("|所使用数据结构 : fqh平衡树             |\n");
		printf("|作者 : 张悦熠    学号 : 9211040G0637   |\n");
		printf("-----------------------------------------\n");
	}
	void help()
	{
		printf("\n                  帮助:\n");
		printf("1  : 插入数据               9  : 输出平均值\n");
		printf("2  : 删除数据               10 : 按遍历顺序输出二叉树\n");
		printf("3  : 查找数据               11 : 从小到大排序输出\n");
		printf("4  : 找出前驱数据           12 : 从大到小排序输出\n");
		printf("5  : 找出后继数据           13 : 某一个节点及其子树的平均值\n");
		printf("6  : 找最小值               14 : 某一个节点及其子树的总和\n");
		printf("7  : 找最大值               15 : 保存数据并退出\n");
		printf("8  : 输出二叉树             16 : 载入数据\n");
		printf("------------------------------------------------------\n");
	}
	void cls(){
		system("cls");
		menu();
		help();
	}
	void set(){
		printf("----请选择模式-----\n");
		printf("a : 正常模式\n");
		printf("b : 演示模式\n");
		scanf("%c",&type);
		cls(); 
		while(type!='a' && type!='b'){
			printf("\n请重新选择\n");
			scanf("%c",&type); 
		}
	}
}UI;
signed main()
{
	UI.cls();
	srand(unsigned(time(0)));
	UI.set();
	if(type=='a'){
		while(scanf("%d",&opt)!=EOF)
		{
			if(opt==0){
				UI.cls();
				UI.help();
			}
			else if(opt==1)
			{ //插入数据 
				int x;
				scanf("%d",&x);
				fhq.split(root,x,l,r);
				root=fhq.merge(fhq.merge(l,fhq.add(x)),r);
				UI.cls(); 
				printf("上条指令结果 : 插入 %d\n",x);
			}
			else if(opt==2)
			{ //删除数据 
				int x;
				scanf("%d",&x);
				if(!fhq.find(root,x))
				{
					UI.cls(); 
					printf("上条指令结果 : 删除失败 , 二叉树中不存在 %d\n",x);
					continue;
				}
				fhq.split(root,x,l,r);
				fhq.split(l,x-1,l,p);
				p=fhq.merge(tree[p].l,tree[p].r);
				root=fhq.merge(fhq.merge(l,p),r);
				UI.cls();
				printf("上条指令结果 : 删除 %d 成功\n",x);
			}
			else if(opt==3)
			{
				int x;
				scanf("%d",&x);
				UI.cls();
				if(fhq.find(root,x)) printf("上条指令结果 : %d 存在于二叉树中\n",x);
				else printf("上条指令结果 : %d 不存在于二叉树中\n",x);
			}
			else if(opt==4)
			{ //前驱 
				int x;
				scanf("%d",&x);
				if(x<=tree[fhq.kth(root,1)].val)
				{
					UI.cls();
					printf("上条指令结果 : %d 没有前驱数据",x);
					printf(" , 当前的最小值是: %d\n",tree[fhq.kth(root,1)].val);
					continue;
				}
				fhq.split(root,x-1,l,r);
				UI.cls();
				printf("上条指令结果 : %d 的前驱数据是 %d\n",x,tree[fhq.kth(l,tree[l].size)].val);
				root=fhq.merge(l,r);
			}
			else if(opt==5)
			{ //后继 
				int x;
				scanf("%d",&x);
				if(x>=tree[fhq.kth(root,tree[root].size)].val)
				{
					UI.cls();
					printf("上条指令结果 : %d 没有后继数据",x);
					printf(" , 当前最大的值是: %d\n",tree[fhq.kth(root,tree[root].size)].val);
					continue;
				}
				fhq.split(root,x,l,r);
				UI.cls();
				printf("上条指令结果 : %d 的后继数据是 %d\n",x,tree[fhq.kth(r,1)].val);
				root=fhq.merge(l,r);
			}
			else if(opt==6)
			{ //最小值 
				UI.cls();
				printf("上条指令结果 : 二叉树最小值为 %d\n",tree[fhq.kth(root,1)].val);
			}
			else if(opt==7)
			{//最大值 
				UI.cls();
				printf("上条指令结果 : 二叉树最大值为 %d\n",tree[fhq.kth(root,tree[root].size)].val);
			}
			else if(opt==8)
			{//输出二叉树 
				UI.cls();
				printf("上条指令结果 : 二叉树的形状为\n");
				fhq.print(root,1);
				printf("\n");
			}
			else if(opt==9)
			{//输出二叉树的平均值 
				UI.cls();
				printf("上条指令结果 : 二叉树平均值为 %.3lf\n",1.0*tree[root].sum/tree[root].size);
			}
			else if(opt==10)
			{//按照遍历顺序输出二叉树 
				UI.cls();
				printf("上条指令结果 : 遍历顺序是\n"); 
				fhq.dfs(root);
				printf("\n");
			}
			else if(opt==11){//从小到大输出数据 
				UI.cls();
				printf("上条指令结果 : 从小到大输出数据为\n"); 
				fhq.sort_min_to_max(root);
				printf("\n");
			}
			else if(opt==12){//从大到小输出数据 
				UI.cls();
				printf("上条指令结果 : 从大到小输出数据为\n"); 
				fhq.sort_max_to_min(root);
				printf("\n");
			}
			else if(opt==13){
				int x;
				scanf("%d",&x);
				int treeid=fhq.find(root,x);
				UI.cls();
				if(treeid==0) printf("上条指令结果 : 节点 %d 不存在\n",x);
				else printf("上条指令结果 : 节点 %d 平均值为 %.2lf\n",x,1.0*tree[treeid].sum/tree[treeid].size);
			}
			else if(opt==14){
				UI.cls();
				int x;
				scanf("%d",&x);
				int treeid=fhq.find(root,x);
				if(treeid==0) printf("上条指令结果 : 节点 %d 不存在\n",x);
				else printf("上条指令结果 : 节点 %d 总和为 %d\n",x,tree[treeid].sum);
			}
			else if(opt==15){
				UI.cls();
				printf("上条指令结果 : 数据保存成功 数据文件名为\"data.out\"\n"); 
				freopen("data.out","w",stdout);
				printf("%d\n",k);
				for(int i=1;i<=k;i++){
					printf("%d %d %d %d %d %d\n",tree[i].key,tree[i].l,tree[i].r,tree[i].size,tree[i].sum,tree[i].val);
				}
				printf("%d\n",root);
				freopen("CON","w",stdout); 
				exit(0); 
			}
			else if(opt==16){
				UI.cls();
				printf("上条指令结果 : 数据载入成功 \n"); 
				freopen("data.out","r",stdin);
				scanf("%d",&k);
				memset(tree,0,sizeof tree);
				for(int i=1;i<=k;i++){
					scanf("%d %d %d %d %d %d",&tree[i].key,&tree[i].l,&tree[i].r,&tree[i].size,&tree[i].sum,&tree[i].val);
				}
				scanf("%d",&root);
				freopen("CON","r",stdin);
			}
			else {
				UI.cls();
				printf("上条指令结果 : input error\n");
			}
		}
	}
	
//-------------------------------------------------------------------------------------------------------------------------------	
	
	else if(type=='b'){
		while(scanf("%d",&opt)!=EOF)
		{
			if(opt==0){
				UI.cls();
				UI.help();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
			}
			else if(opt==1)
			{ //插入数据 
				int x;
				scanf("%d",&x);
				fhq.split(root,x,l,r);
				root=fhq.merge(fhq.merge(l,fhq.add(x)),r);
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : 插入 %d\n",x);
			}
			else if(opt==2)
			{ //删除数据 
				int x;
				scanf("%d",&x);
				if(!fhq.find(root,x))
				{
					UI.cls(); 
					printf("-------------------------\n");
					fhq.print(root,1);
					printf("-------------------------\n");
					printf("上条指令结果 : 删除失败 , 二叉树中不存在 %d\n",x);
					continue;
				}
				fhq.split(root,x,l,r);
				fhq.split(l,x-1,l,p);
				p=fhq.merge(tree[p].l,tree[p].r);
				root=fhq.merge(fhq.merge(l,p),r);
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : 删除 %d 成功\n",x);
			}
			else if(opt==3)
			{
				int x;
				scanf("%d",&x);
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				if(fhq.find(root,x)) printf("上条指令结果 : %d 存在于二叉树中\n",x);
				else printf("上条指令结果 : %d 不存在于二叉树中\n",x);
			}
			else if(opt==4)
			{ //前驱 
				int x;
				scanf("%d",&x);
				if(x<=tree[fhq.kth(root,1)].val)
				{
					UI.cls();
					printf("-------------------------\n");
					fhq.print(root,1);
					printf("-------------------------\n");
					printf("上条指令结果 : %d 没有前驱数据",x);
					printf(" , 当前的最小值是: %d\n",tree[fhq.kth(root,1)].val);
					continue;
				}
				fhq.split(root,x-1,l,r);
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : %d 的前驱数据是 %d\n",x,tree[fhq.kth(l,tree[l].size)].val);
				root=fhq.merge(l,r);
			}
			else if(opt==5)
			{ //后继 
				int x;
				scanf("%d",&x);
				if(x>=tree[fhq.kth(root,tree[root].size)].val)
				{
					UI.cls();
					printf("-------------------------\n");
					fhq.print(root,1);
					printf("-------------------------\n");
					printf("上条指令结果 : %d 没有后继数据",x);
					printf(" , 当前最大的值是: %d\n",tree[fhq.kth(root,tree[root].size)].val);
					continue;
				}
				fhq.split(root,x,l,r);
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : %d 的后继数据是 %d\n",x,tree[fhq.kth(r,1)].val);
				root=fhq.merge(l,r);
			}
			else if(opt==6)
			{ //最小值 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : 二叉树最小值为 %d\n",tree[fhq.kth(root,1)].val);
			}
			else if(opt==7)
			{//最大值 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : 二叉树最大值为 %d\n",tree[fhq.kth(root,tree[root].size)].val);
			}
			else if(opt==8)
			{//输出二叉树 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : 输出二叉树的形状\n");
				printf("\n");
			}
			else if(opt==9)
			{//输出二叉树的平均值 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : 二叉树平均值为 %.3lf\n",1.0*tree[root].sum/tree[root].size);
			}
			else if(opt==10)
			{//按照遍历顺序输出二叉树 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : 遍历顺序是\n"); 
				fhq.dfs(root);
				printf("\n");
			}
			else if(opt==11){//从小到大输出数据 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : 从小到大输出数据为\n"); 
				fhq.sort_min_to_max(root);
				printf("\n");
			}
			else if(opt==12){//从大到小输出数据 
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : 从大到小输出数据为\n"); 
				fhq.sort_max_to_min(root);
				printf("\n");
			}
			else if(opt==13){
				int x;
				scanf("%d",&x);
				int treeid=fhq.find(root,x);
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				if(treeid==0) printf("上条指令结果 : 节点 %d 不存在\n",x);
				else printf("上条指令结果 : 节点 %d 平均值为 %.2lf\n",x,1.0*tree[treeid].sum/tree[treeid].size); 
			}
			else if(opt==14){
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				int x;
				scanf("%d",&x);
				int treeid=fhq.find(root,x);
				if(treeid==0) printf("上条指令结果 : 节点 %d 不存在\n",x);
				else printf("上条指令结果 : 节点 %d 总和为 %d\n",x,tree[treeid].sum);
			}
			else if(opt==15){
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : 数据保存成功 数据文件名为\"data.out\"\n"); 
				freopen("data.out","w",stdout);
				printf("%d\n",k);
				for(int i=1;i<=k;i++){
					printf("%d %d %d %d %d %d",tree[i].key,tree[i].l,tree[i].r,tree[i].size,tree[i].sum,tree[i].val);
				}
				printf("%d\n",root);
				freopen("CON","w",stdout); 
				exit(0); 
			}
			else if(opt==16){
				UI.cls();
				freopen("data.out","r",stdin);
				scanf("%d",&k);
				memset(tree,0,sizeof tree);
				for(int i=1;i<=k;i++){
					scanf("%d %d %d %d %d %d",&tree[i].key,&tree[i].l,&tree[i].r,&tree[i].size,&tree[i].sum,&tree[i].val);
				}
				scanf("%d",&root);
				freopen("CON","r",stdin);
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : 数据载入成功 \n"); 
			}
			else{
				UI.cls();
				printf("-------------------------\n");
				fhq.print(root,1);
				printf("-------------------------\n");
				printf("上条指令结果 : input error\n");
			}
		}
	}
	return 0;
}
