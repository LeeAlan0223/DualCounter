/*標頭檔*/ 
#include <stdio.h>
#include <stdlib.h>

/* 
全域(廣域)變數: 定義在程式碼最外層，不屬於任何函式（包括 main），但所有函式都可以存取和修改它。 
區域變數: 可定義在任何函式中，但不互相干擾。 
靜態變數: 變數的值在多次函式調用之間保持不變，即使函式執行結束後，該變數的值仍會保留。
*/ 

// 全域變數
int c;				// 分工計數器執行次數 (廣域變數) 
int newline;		// 計數器更換次數 (廣域變數)
int frequency1;		// 函式 counter1 計數起始值 (廣域變數) 
int frequency2;		// 函式 counter2 計數起始值 (廣域變數)
int Increasing1;	// 函式 counter1 增減變化量 (廣域變數) 
int Increasing2;	// 函式 counter2 增減變化量 (廣域變數)


// 函式宣告
void counter1(void);	// 計數器1 函式
void counter2(void);	// 計數器2 函式
int determine(int* i);	//判斷輸入(i)是否是我需要的數值(1 or 2) 
void choose(int* i);	// 根據 (*i) 選擇 counter1 或 counter2 開始 (指標函式)
void pause(void);		//結束 和 system("pause") 差不多功用 

//主程式 
int main(void) {
    int i;	// 建立選擇器變數，用來選擇啟動哪個計數器（1 或 2）
    
	// 提示使用者輸入計數次數
    printf("輸入執行次數: ");
    scanf("%d", &c); // 讀取計數次數並存入 c
    
    printf("---------------------\n");
    
    //設定計數器更換次數 
    printf("輸入執行多少次更換計數器: ");
    scanf("%d", &newline); 
    
    printf("\n---------------------\n");
    printf("設定counter1\n");
    
    // 提示使用者輸入計數器 1 的起始值
    printf("輸入counter1起始數: ");
    scanf("%d", &frequency1); // 讀取並設定計數器 1 起始數
    
    //設定計數器 1 數字增加量 
    printf("輸入counter1增加量: ");
    scanf("%d", &Increasing1);
    
    printf("---------------------\n");
    printf("設定counter2\n");
    
    // 提示使用者輸入計數器 2 的起始值
    printf("輸入counter2起始數: ");
    scanf("%d", &frequency2); // 讀取並設定計數器 2 起始數
    
    //設定計數器 2 數字增加量
    printf("輸入counter2增加量: ");
    scanf("%d", &Increasing2);
    
    printf("---------------------\n");
    
    // 提示使用者選擇計數器 1 或 2
    printf("輸入計數器起始(1 or 2): ");
    scanf("%d", &i); // 讀取並設定選擇的計數器
    
    printf("---------------------\n");
    
    if(determine(&i) == -1){
    	return 1; // 如果無效，退出程式
	}else{
		choose(&i); // 根據使用者選擇呼叫相應的計數器
	}
	
	printf("---------------------\n");
	
    // 提示使用者按鍵繼續
	pause();	//呼叫暫停函式
    return 0; // 程式成功結束
}

// 計數器 1 函式
void counter1(void) {
    static int a = 0;	// 計數器 1 的靜態變數，記錄當前值
    static int i = 0;	// 計數器 1 的靜態變數，記錄呼叫次數
    
    if (i == 0) a = frequency1;// 如果是第一次呼叫，初始化計數值為 frequency2
    
    printf("counter1:%d\n", a);// 顯示當前計數值
    a = a + Increasing1; // 每次執行後增加 1
    i++; // 呼叫次數增加
    
    // 如果達到計數次數，結束函式
    if (i == c) {
        return;//回傳
    }
    
    // 達到 newline 所設定的值就換行 
    if (i % newline == 0) {
        printf("-------------------\n");
        counter2();	// 切換到計數器 2
    } else {
        counter1();	// 繼續執行計數器 1
    }
}

// 計數器 2 函式
void counter2(void) {
    static int a = 0;	// 計數器 2 的靜態變數，記錄當前值
    static int i = 0;
    
	// 計數器 2 的靜態變數，記錄呼叫次數
    if (i == 0) a = frequency2;// 如果是第一次呼叫，初始化計數值為 frequency2
    
    
    printf("counter2:%d\n", a);// 顯示當前計數值
    
    a = a + Increasing2;// 每次執行後增加 10
    i++; // 呼叫次數增加
      
    // 如果達到計數次數，結束函式
    if (i == c) {
        return; //回傳
    }
    
    // 達到 newline 所設定的值就換行 
    if (i % newline == 0) {
        printf("-------------------\n");
        counter1();	// 切換到計數器 1
    } else {
        counter2();	// 繼續執行計數器 2
    }
}

// 函式功能:檢查輸入是否有效 (1 或 2)  
int determine(int* i){
	 if (*i != 1 && *i != 2) {
	 	printf("\n");	
        printf("輸入字元錯誤\n");	// 輸入錯誤提示
        printf("\n");
        pause();	//呼叫暫停函式
        *i=-1;
        return *i;	// 回報錯誤並返還程式
    }
    return 0;//回傳
}

// 函式功能:根據使用者的選擇選擇對應的計數器
void choose(int *i) {	
    switch (*i) {	// 根據 *i 的值來選擇計數器
        case 1:	// 當選擇為 1 時
            counter1();	// 呼叫 counter1()
            break;	// 跳出選擇
        case 2:	// 當選擇為 2 時
            counter2();	// 呼叫 counter2()
            break;	// 跳出選擇
    }
}

//函式功能:暫停
void pause(void){
	printf("按Enter繼續...\n");	// 提示使用者按鍵繼續
    while (getchar() != '\n');	// 清除緩衝區的字符
    getchar();	// 等待使用者按下 Enter 鍵
    return; //回傳 
}

/*
	可更改的點: 
	1.新增乘和除功能
	2.設定個別運行次數 
*/ 
