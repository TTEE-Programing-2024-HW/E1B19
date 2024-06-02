#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<ctype.h>
#include<string.h>
// 定義學生結構陣列 
struct student{
    char name[50];
    int num;
    int mat;
    int phy;
    int eng;
    float avg;
};
struct student students[10]; //10名學生
int main(void){
	int t=0,a;
	char ch;
	int stdcount=0; 
	printf("看到一篇複製文\n不要馬上就按複製\n可以嘗試著去跟樓主溝通\n闡述自己的理念\n雙方分享想法\n何必一看到就馬上按複製呢\n你看到不專心\n我看到也不專心呀\n最近的貼文都有幾個零星的複製文\n這讓我感到非常難過\n");   
    printf("\n你說得對，但是這就是卡桑帝\nHP 4700\n護甲 329\n魔抗201的英雄\n有不可阻擋\n有護盾\n還能過牆\n有控制，甚至冷卻時間只有1秒，只要15點藍\n轉換姿態時甚至可以刷新W的cd，還有真實傷害\n然後，護甲和魔抗提升後還能獲得技能加速，縮短Q的cd，還縮短釋放時間，然後還有攻擊力\nW就啊啊啊啊啊啊\n");
    //  顯示文字
    getch();
    system("cls");
    // 清除螢幕
   
    while(t<=3){
        printf("請輸入密碼:");
        scanf("%d",&a);
        fflush(stdin);
        if(a==2024){
        	getch();
    		system("cls");
			
    		// 清除螢幕
    		
   	 	
    		while(1){
    			//主選單
    			printf("-------------------------------\n|a. Enter student|\n|b.Display student |\n|c.Search for student grades|\n|d.Grade ranking|\n|e.Exit system|\n-----------------------------\n");
    			printf("輸入一字元\n");//輸入1個字元
    			fflush(stdin);
    			scanf("%c", &ch);
    			if(ch=='a'||ch=='A'){
    				int n;
    				printf("請輸入學生數量(5-10)：");
    				fflush(stdin);
    				scanf("%d",&n);
    				while(n<5||n>10){
        			printf("數量必須在5到10之間，請重新輸入：");
        			fflush(stdin);
        			scanf("%d",&n);
    				}
					int i;
    				for(i=0;i<n;i++){
        			printf("輸入第%d個學生的姓名：",i+1);
        			scanf("%s",students[i].name);
        			printf("輸入學號：");
        			scanf("%d",&students[i].num);
        			if(students[i].num<99999||students[i].num>1000000){
        				printf("輸入錯誤，請重新輸入。\n");
        				i--; 
        				continue;
					}
        			printf("輸入數學成績：");
        			scanf("%d",&students[i].mat);
        			if(students[i].mat<0||students[i].mat>100){
        				printf("輸入錯誤，請重新輸入。\n");
        				i--; 
        				continue;
					}
        			printf("輸入物理成績：");
        			scanf("%d",&students[i].phy);
        			if(students[i].phy<0||students[i].phy>100){
        				printf("輸入錯誤，請重新輸入。\n");
        				i--;
        				continue;
					}
        			printf("輸入英文成績：");
        			scanf("%d",&students[i].eng);
        			if(students[i].eng<0||students[i].eng>100){
        				printf("輸入錯誤，請重新輸入。\n");
        				i--;
        				continue;
					}
        			students[i].avg=(students[i].mat+students[i].phy+students[i].eng)/3.0;
    				}
    				stdcount=n;
    				printf("成績輸入完成，返回主選單。\n");
   					system("PAUSE");
    				system("cls");
				}
				else if(ch=='b'||ch=='B'){
					printf("學生成績：\n");
    				int i;
    				for(i=0;i<stdcount;i++){
        			printf("姓名:%s, 學號:%d, 數學:%d, 物理:%d, 英文:%d, 平均成績:%.1f\n",students[i].name,students[i].num,students[i].mat,students[i].phy,students[i].eng,students[i].avg);
					}
    			
    			system("PAUSE");
    			system("cls");
				}
				else if(ch=='c'||ch=='C'){
					char search[50];
    				printf("請輸入要搜尋的學生姓名：");
   					scanf("%s",search);
    				int i;
    				for(i=0;i<stdcount;i++){
        			if(strcmp(students[i].name,search)==0){//strcmp(a,b)比較兩個字串是否相等(用ASCII依序比較大小)，相等就回傳0
        				printf("姓名:%s, 學號:%d, 數學:%d, 物理:%d, 英文:%d, 平均成績:%.1f\n",students[i].name,students[i].num,students[i].mat,students[i].phy,students[i].eng,students[i].avg);
            			printf("按任意鍵返回主選單。\n");
            			system("PAUSE");
            			system("cls");
            			return;
        			}
        			printf("找不到資料。\n");
    				system("PAUSE");
    				system("cls");
					}
				}
				else if(ch=='d'||ch=='D'){
					    // 排序
    				int i,j;
    				for(i=0;i<stdcount-1;i++){
        				for(j=i+1;j<stdcount;j++){
            				if(students[i].avg<students[j].avg){//交換i跟j 
                				struct student temp=students[i];//設暫存 
               					students[i]=students[j];
                				students[j]=temp;
            				}
        				}			
    				}
    				printf("成績排名如下：\n");
    				for(i=0;i<stdcount;i++){
        			printf("姓名: %s, 學號: %d, 平均成績: %.1f\n",students[i].name,students[i].num,students[i].avg);
    				}
    			
    				system("PAUSE");
    				system("cls");
				}
				else if(ch=='e'||ch=='E'){
					char ch;
    				printf("確定離開？(y/n):");
    				while(1){
    				fflush(stdin);
        			scanf("%c",&ch);
        			if(ch=='y'||ch=='Y'){
            			exit(0);//直接結束程式 
        			}else if(ch=='n'||ch=='N'){
            			system("cls");
            			break;
        			}else{
            			printf("無效輸入，請重新輸入 (y/n): ");
        			}
    				}
				}
		}
					
}
			
			


    	else{
    		printf("輸入錯誤\n");
            t+=1;
            if(t==3)
            break;
        }

}
	



            
    return 0;
    }
/*

*/

