#include<stdio.h>

int main(void){
	printf("看到一篇複製文\n不要馬上就按複製\n可以嘗試著去跟樓主溝通\n闡述自己的理念\n雙方分享想法\n何必一看到就馬上按複製呢\n你看到不專心\n我看到也不專心呀\n最近的貼文都有幾個零星的複製文\n這讓我感到非常難過\n");   
    printf("\n你說得對，但是這就是卡桑帝\nHP 4700\n護甲 329\n魔抗201的英雄\n有不可阻擋\n有護盾\n還能過牆\n有控制，甚至冷卻時間只有1秒，只要15點藍\n轉換姿態時甚至可以刷新W的cd，還有真實傷害\n然後，護甲和魔抗提升後還能獲得技能加速，縮短Q的cd，還縮短釋放時間，然後還有攻擊力\nW就啊啊啊啊啊啊\n");
    //  顯示文字
    getch();
    system("cls");
    // 清除螢幕
    int a,t=0;
    char ch;
    while(t<=3){
        printf("請輸入密碼:");
        scanf("%d",&a);
        fflush(stdin);
        if(a==2024){
        	getch();
    		system("cls");
    		// 清除螢幕
    		printf("-------------------------------\n|a. 畫出直角三角形|\n|b. 顯示乘法表 |\n|c. 結束|\n-----------------------------\n");
   	 		//主選單
    		printf("輸入一字元\n");//輸入1個字元
    		scanf("%c", &ch);
    		while(1){
    			if(ch>='A'||ch=='a'){
    			char ip;
    			printf("請輸入一個字元（a到n之間）：");
    			fflush(stdin);
    			scanf("%c",&ip);
    
    			if (ip<'a'||ip>'n') {
        			printf("錯誤的輸入！請重新輸入。\n");
    			}
    			system("cls"); // 清除螢幕

    			int b=ip-'a'+1; // 計算打印的行數
    
    			int i=1;
    			for (i;i<=b;i++) {
        			char ch=ip-i+1;
					int j=1;
					// 打印空格
        			for (j;j<=b-i;j++){
            			printf("  ");
        			}
					// 打印字母
        			for (ch;ch<=ip;ch++){
            			printf("%c ",ch);
        			}
        			printf("\n");
    			}
    			break;
				}	
				else if(ch=='B'&&ch=='b'){
    			printf("Lowecase\n");
				}
				else if(ch=='C'&&ch=='c'){
					printf("Digit\n");
				}
				else{
					printf("重新輸入\n");
					
    				scanf("%c",&ch);
				} 
			}
            break;
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