#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<ctype.h>
void randseat(char seat[9][9]){
    int c=0;
    //使用 rand 函數
    srand((unsigned) time(NULL));
    //隨機產生十個座位
    while(c<10){
        int x=rand()%9;//隨機行號
        int y=rand()%9;//隨機列號
        if (seat[x][y]!='*'){
            seat[x][y]='*';//標記座位
            c++;
        }
        int i,j;
        for(i=0;i<9;i++){
        	for(j=0;j<9;j++){
        		if(seat[i][j]=='@'){
            	seat[i][j]='*';
            	c++;
				}
        	}
    	}
    }
}
void step1(char seat[9][9]){
	printf("座位表：\n");
    printf("\\123456789\n");
    int i,j;
    for(i=8;i>=0;i--){
        printf("%d",i+1);
        for(j=0;j<9;j++){
            if(seat[i][j]=='*'){
                printf("*");
            }else if(seat[i][j]=='@'){
                printf("@");
            }else{
                printf("-");
            }
        }
        printf("\n");
    }
    system("pause"); //等待用戶按下任意鍵
}
void step2(char seat[9][9],int numseats){
    int i,j;
    // 如果需要的座位數大於4，或小於1，則提示錯誤並返回
    if (numseats>4||numseats<1){
        printf("請輸入正確的座位數量(1~4)。\n");
        return;
    }
    // 一般情況下，隨機選擇連續座位
    if(numseats<=3){
        while(1){
            int row=rand()%9;
            int col=rand()%(10-numseats);

            // 檢查連續的座位是否可用
            int usable=1;
            for(i=col;i<col+numseats;i++){
                if(seat[row][i]=='*'){
                    usable=0;
                    break;
                }
            }

            // 如果座位可用，則安排座位並標記為建議座位@
            if(usable){
                for(i=col;i<col+numseats;i++){
                    seat[row][i]='@';
                }
                break;
            }
        }
    }else{ // 如果需要的座位數為4
        int found=0;
        // 嘗試在同一行上找到4個連續的座位
        int at;
        for(at=0;at<100;at++){ // 限制嘗試次數，防止無限迴圈
            int row=rand()%9;
            int col=rand()%(9-numseats+1);
            // 檢查連續的座位是否可用
            int usable=1;
            for(i=col;i<col+numseats;i++){
                if(seat[row][i]=='*'){
                    usable=0;
                    break;
                }
            }
            // 如果座位可用，則安排座位並標記為建議座位@
            if(usable){
                for(i=col;i<col+numseats;i++){
                    seat[row][i]='@';
                }
                found=1;
                break;
            }
        }
        // 如果未找到4個連續的座位，則嘗試安排相鄰的兩行各2個座位
        if(!found){
            while(1){
                int row=rand()%8; 
                int col=rand()%8;
                // 檢查相鄰兩行的座位是否可用
                int usable=1;
                for(i=0;i<2;i++){
                    for(j=col;j<col+2;j++){
                        if(seat[row+i][j]=='*'){
                            usable=0;
                            break;
                        }
                    }
                    if(!usable)break;
                }
                // 如果座位可用，則安排座位並標記為建議座位@
                if(usable){
                    for(i=0;i<2;i++){
                        for(j=col;j<col+2;j++){
                            seat[row+i][j]='@';
                        }
                    }
                    break;
                }
            }
        }
    }
}
void step3(char seat[9][9]) {
    int row,col;
    char input[10];
    int valid=1;

    while(1){
        printf("請輸入座位（如1-2代表[列1,行2]）：");
        fflush(stdin);
        scanf("%s",input);

        if (sscanf(input,"%d-%d",&row,&col)!=2||row<1||row>9||col<1||col>9||seat[row-1][col-1]=='*'||seat[row-1][col-1]=='@') {
            printf("格式錯誤或座位已被佔用，請重新輸入。\n");
            continue;
        }

        seat[row-1][col-1]='@';

        // 確認
        printf("是否繼續選擇座位？（y/n）：");
        fflush(stdin);
        char cont;
        scanf("%c",&cont);
        if(cont=='n'||cont=='N')break;
    }

    // 顯示排位結果
    step1(seat);
    // 將@變為*
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(seat[i][j]=='@'){
                seat[i][j]='*';
            }
        }
    }
    // 回到主選單
    system("cls");
}
int main(void){
	char seat[9][9];
	char ans;
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
    		randseat(seat);
    		// 清除螢幕
    		
   	 	
    		while(1){
    			//主選單
    			printf("-------------------------------\n|a. Available|\n|b.Arrange |\n|c.Choose by yourself|\n|d.Exit |\n-----------------------------\n");
    			printf("輸入一字元\n");//輸入1個字元
    			fflush(stdin);
    			scanf("%c", &ch);
    			if(ch=='A'||ch=='a'){
    				step1(seat);
			}
			else if(ch=='b'||ch=='B'){
				getch();
    			system("cls");
    			printf("請問您需要幾個座位？(1~4)：");
                int num_seats;
                fflush(stdin);
                scanf("%d",&num_seats);
               
                    step2(seat,num_seats);
                    step1(seat); //顯示安排座位後的座位表
                    int i,j;
                    char con;
                    getch();
    				system("cls");
    				fflush(stdin);
                    printf("是否同意此座位安排(y/n):\n");
                    scanf("%c",&con);
                    if (con=='y'||con=='Y'){
            		int i,j;
                    for(i=0;i<9;i++){
        				for(j=0;j<9;j++){
            				if(seat[i][j]=='@'){
                				seat[i][j]='*';
           					}	
        				}
    				}
    				step1(seat); 
        		}    
				
			}
			else if(ch=='c'||ch=='C'){
				getch();
    			system("cls");
				step1(seat);
				step3(seat);
			
			}	

				else if(ch=='d'||ch=='D'){
				getch();
    			system("cls");
				char cr;
				do{
        			printf("Continue? (y/n): ");
        			scanf(" %c", &cr);
         			if (cr=='y'||cr=='Y'){
            			break;// 結束
        			}        
					else if(cr=='n'||cr=='N'){
            			printf("程式結束。\n");
            			return 0;
        			}
					else{
            			printf("錯誤的輸入！請重新輸入。\n");
        			}
    			}while(1);
			
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
這次的程式非常的麻煩又很困難，原本一開始打算用不用函數直接一步步寫 但要重複寫的東西太多了 所以就改成用函數 比較好去處理
*/

