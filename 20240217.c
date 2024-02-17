


100K
定时关机
	30/60/90\120/OFF




KEY_RTC_UP	时间加
KEY_RTC_DOWN	时间减

KEY_RTC_SW 设置时间转换

KEY_RTC_SW_POS调整时间位置






app_task_put_key_msg(KEY_SOFT_POWER_OFF,0);



催眠入睡
 0 1 2
减压放松
 3 4 5 
睡眠调节
 6 7 8




void ShutDown_Time_Scan(void)
{
	printf("定时关机\n");
	//set_poweroff_ir_mode(IDLE_MODE_IN_AUTO);
	//app_task_switch_to(APP_IDLE_TASK/*APP_POWEROFF_TASK*/);
	app_task_put_key_msg(KEY_SOFT_POWER_OFF,0);
}

void user_set_timed_shutdown(u8 Time)
{
	static int ShutDown_ID = 0;
	if(ShutDown_ID){
		sys_s_hi_timer_del(ShutDown_ID);
		ShutDown_ID = 0;
	}
	switch(Time){
		case 0:
			sys_s_hi_timer_del(ShutDown_ID);
			ShutDown_ID = 0;	
			break;
		case 30:
			ShutDown_ID = sys_s_hi_timer_add(NULL, ShutDown_Time_Scan, 30*60*1000);
			break;
		case 60:
			ShutDown_ID = sys_s_hi_timer_add(NULL, ShutDown_Time_Scan, 60*60*1000);
			break;
		case 90:
			ShutDown_ID = sys_s_hi_timer_add(NULL, ShutDown_Time_Scan, 90*60*1000);
			break;
		case 120:
			ShutDown_ID = sys_s_hi_timer_add(NULL, ShutDown_Time_Scan, 120*60*1000);
			berak;
		default:
			sys_s_hi_timer_del(ShutDown_ID);
			ShutDown_ID = 0;	
			break;
	}
}



定时开机
	RTC模式下长按定时关机键可设置开机时间
	长按定时关机键设置定时开机时间
		优先设置小时再次短按则设置分钟时间
		再次短按显示ON表示开启定时开机




录音模式
	长安‘5’进入并且直接开启录音
	短按‘5’退出录音模式
	双击‘5’播放录音
	播放中短按‘5’退出录音模式



KEY_MUSIC_PLAYE_PREV_FOLDER		//上一个文件夹

KEY_MUSIC_PLAYE_NEXT_FOLDER		//下一个文件夹


//earphone_io_stop();





录音模式(只录音5分钟)
	长按5进入
	短按模式键退出

文件夹	
	模式与播放模式合成一起





耳机检测脚出低电平时
不是PC模式
	拉高
else
	拉低



int recorder_get_encoding_time()//获取录音时间




void start_record(void)	//开始录音
{
	if(recorder_is_encoding()){	//正在录音
		record_mic_stop();		//停止录音
		record_mic_start();		//开始录音
	}else{
		record_mic_start();		//开始录音
	}
}


void stop_record(void)
{
	if(recorder_is_encoding()){
		record_mic_stop();		//停止录音
	}
}


void play_record(void)		//播放录音
{
    if (recorder_is_encoding()) {
        record_mic_stop();
    }
    record_file_play();
}
KEY_START_RECORD
KEY_STOP_RECORD
KEY_PLAY_RECORD

static void set_alarm(void)
{
    T_ALARM alarm = {0};
    if ((!__this) || (!__this->dev_handle)) {
        return;
    }
    struct ui_rtc_display *rtc = rtc_ui_get_display_buf();
    if (!rtc) {
        return;
    }
    
    alarm_get_info(&alarm,0);   //获取闹钟设置的时间
    if((alarm.sw) && (Dis_Alarm_Time_Flag == 0)){	  
        Set_dia_alarm_dot(0);       //关闭闹钟指示灯
        __this->rtc_pos == RTC_POS_NULL;
    	__this->alm_enable = 0;
        rtc->rtc_menu = UI_RTC_ACTION_STRING_SET;
        rtc->str = " OFF ";
       	alarm.sw = __this->alm_enable;		
	    alarm_add(&alarm, 0);				//添加闹钟 
        UI_SHOW_MENU(MENU_RTC_SET, 1 * 1000, 0, ui_set_rtc_timeout);
        app_task_put_key_msg(KEY_EXIE_DELAY,0);
	}else{
	    Set_dia_alarm_dot(1);   //开启闹钟指示灯
		__this->alm_enable = 1;	
		__this->rtc_set_mode = ALM_SET_MODE;       
		__this->rtc_pos = ALM_POS_HOUR;
	    rtc->rtc_menu = UI_RTC_ACTION_HOUR_SET + (__this->rtc_pos - ALM_POS_HOUR);
        rtc->time.Hour = alarm.time.hour;
	    rtc->time.Min = alarm.time.min;
	    rtc->time.Sec = 0;
	    __this->set_time.hour = alarm.time.hour;
	    __this->set_time.min = alarm.time.min;
	    alarm.sw = __this->alm_enable;	
	    alarm_add(&alarm, 0);	
	    UI_SHOW_MENU(MENU_RTC_SET, 20 * 1000, 0, ui_set_rtc_timeout);
	}

上下曲改回去






    T_ALARM alarm = {0};
    alarm_get_info(&alarm,0);   //获取闹钟设置的时间
    if((alarm.sw)){
    	__this->alm_enable = 0;
       	alarm.sw = __this->alm_enable;		
	    alarm_add(&alarm, 0);				//添加闹钟 
        return;
    }

文件夹切换复位	WDT
播放录音文件复位 SOFT RESET 手动切换录音文件时会复位

蓝牙模式转到FM模式闪烁




闹钟设置
	短按定时开关机键进入闹钟设置 显示 open 表示打开闹钟

	短按播放键选择设置 时、分、铃声、关闭
	设置完成时间后短按定时开关机键保存设置的时间 



收音模式显示ok



切换显示闪烁问题
	退出当前模式时灭一下屏

蓝牙模式切换到其他模式的时候
	闪烁，蓝牙模式问题


TCFG_EARPHONE_OUT
TCFG_EARPHONE_VDD

问题点

    //蓝牙模式切换到收音模式会闪一下  //每次切换模式时都先关闭一下显示

 //   录音播放有问题		//每次播放都是从第一首开始播放

 //   文件夹切换有问题 		SOFT RESET系统复位  WDT

 //   录音文件切换有问题	SOFT RESET系统复位

    //耳机插入无声音硬件问题？

Check_Tone_State_ID = sys_s_hi_timer_add(NULL, Check_Tone_State, 2); //2ms
tone_get_status()//获取提示音播放状态
2毫秒扫描
	获取提示音播放状态
	播放完成
		开始录音
		关闭定时扫描

    // 1    2   3    4    5    6    7    8   9     0
    0x30,0x6d,0x79,0x72,0x5b,0x5f,0x31,0x7f,0x7b,0x3f


    红色
    0-5
    6-10
    11-15
    0-15白色



8 = 8000


42 = 8 / 








共用体
	任何时候只能有一个成员带值
	共用体使用 union定义
union Data
{
   int i;
   float f;
   char  str[20];
};

union Data data;  //定义一个共用体 data


位域定义的标准形式
struct 位域结构名 
{
 type [member_name] : width ;	
};
type:只能为int unsigned int(无符号整型) signed int(有符号整型) 三种类型
member_name：位域名称
width：位域中位的数量。宽度必须小于或等于指定类型的位宽度。最大不能超过32

struct
{
  unsigned int age : 3;
} Age;

Age.age = 7;// 二进制表示为 0111 有三位，未超出
   printf( "Age.age : %d\n", Age.age );//打印 7
Age.age = 8; // 二进制表示为 1000 有四位，超出
   printf( "Age.age : %d\n", Age.age );//打印 0

#include<stddio.h>
int main(void)
{
	printf("Hello World!\n")//打印 Hello World!
	return 0;
}



getchar() & putchar() 函数
int main(void)
{
   int c;
   printf( "Enter a value :");
   c = getchar( );	//等待输入数据，回车键结束
 
   printf( "\nYou entered: ");
   putchar( c );	//只输出输入数据的第一个字符
   printf( "\n");
   return 0;
}
gets() & puts() 函数
int main(void)
{
   char str[100];
 
   printf( "Enter a value :");
   gets( str );		//等待输入数据，回车键结束
 
   printf( "\nYou entered: ");
   puts( str );		//读取并输出一整行直到该行结束
   return 0;
}


请确保您有可用的 ‘tmp’ 目录，如果不存在该目录，则需要在您的计算机上先创建该目录。
FILE *fp = NULL;	//文件夹指针，指向文件夹
			//文件夹名称，mode：r,w,a,r+,w+,a+
FILE  *fopen( const char *filename, const char *mode );
	mode:
		r:打开已有的文本文件，允许读取文件
		w:打开文本文件允许写入，若文本不存在则创建一个新的文本文件，从头开始写入数据
		  若文件存在则会将原本的内容清除，重新写入
		a:打开一个文本文件，以追加模式写入文件，若文件不存在则新建一个再写入
		r+:打开一个文本文件，允许读写文件
		w+:打开一个文本文件，允许读取文件，若文件存在则会被截断为0，否则创建新的文件
		a+:打开新的文本文件，允许读写，若文件不存在则创建新的文件，否则以追加的方式写入数据
读取文件
int fgetc( FILE * fp );

int main(void)
{
   FILE *fp = NULL;	//文件夹指针，指向文件夹
 
   fp = fopen("/tmp/test.txt", "w+");//指向：/tmp/test.txt 文件，打开文本文档，允许读写
   fprintf(fp, "This is testing for fprintf...\n");	//将"This is testing for fprintf..."写入文本中
   fputs("This is testing for fputs...\n", fp);//将"This is testing for fputs..."写入文本中
   fclose(fp);//关闭文件夹
}
int main(void)
{
   FILE *fp = NULL;//文件指针
   char buff[255];
 
   fp = fopen("/tmp/test.txt", "r");	//打开文本文件，只读
   fscanf(fp, "%s", buff);		//只读取符串 空格键结束
   printf("1: %s\n", buff );	//打印 This
 
   fgets(buff, 255, (FILE*)fp);	//读取剩下的字符串 回车键结束
   printf("2: %s\n", buff );	//打印 is testing for fprintf...
   
   fgets(buff, 255, (FILE*)fp);	//读取剩余字符串，回车键结束
   printf("3: %s\n", buff );	//打印 This is testing for fputs...
   fclose(fp);	//关闭文本文档
 
}

递归
double factorial(unsigned int i)//获得传入值的阶乘
{
   if(i <= 1)
   {
      return 1;
   }
   return i * factorial(i - 1);
}


在内存中动态的分配长度为num个长度为size的连续空间，并将每一个字节都初始化为0
void *calloc(int num, int size);
释放address所指向的内存块，释放的是动态分配的内存空间
void free(void *address);
在堆区分配一块指定大小的内存空间，用来存放数据，这块内存空间在函数执行完成后不会被初始化，它的值未知
void *malloc(int num);
重新分配内存，把内存扩展到newsize
void *realloc(void *address, int newsize);


冒泡排序
#include <stdio.h>
void bubble_sort(int arr[], int len) //传入数组，长度
{	
    int i, j, temp;
    for (i = 0; i < len - 1; i++)			//遍历全部数据
        for (j = 0; j < len - 1 - i; j++)	//遍历未排序数据
            if (arr[j] > arr[j + 1]) {		//比较前后两位数据的大小
                temp = arr[j];				//零时存放数据
                arr[j] = arr[j + 1];		//数据较小的数据前移
                arr[j + 1] = temp;			//数据较大的后移
            }
}
int main(void) 
{
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}	


插入排序
void insertion_sort(int arr[], int len)
{
    int i,j,temp;
    for (i=1;i<len;i++){	//遍历数组
            temp = arr[i];	//暂存当前值
            for (j=i;j>0 && arr[j-1]>temp;j--)	
                    arr[j] = arr[j-1];
            arr[j] = temp;
    }
}

ASCII转码

%C输入
%D输出可获取输入字符对应的ASCII码

平闰年判断
// （四年一闰，百年不闰) || 四百年在闰年
if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)    


输出九九乘法表
int main(void)
{  
    int i = 0;  
    int j = 0;   
    for(i=1;i<=9;i++){  	//外层循环变量,控制行 
        for(j=1;j<=i;j++){  //内层循环变量,控制列   
            printf("%dx%d=%d\t",j,i,i*j);  	//打印输出
            printf(" ");				//打印数据完成一次加一个空格隔开
        }  
        printf("\n"); //换行
    }  
}


斐波那契数列
for (i = 1; i <= n; ++i)
{
    printf("%d, ", t1);
    nextTerm = t1 + t2;		//下一个数据等于前两个数据之和
    t1 = t2;	//将后面的数据前移一位
    t2 = nextTerm;	//后一位数据灯与两数之和
}


Armstrong(阿姆斯壮数)
就是n位数的各位数的n次方之和等于该数
153=1^3+5^3+3^3


因数
	a * b = c
	a 和 b 是c的因数


Free RTOS
	1.1任务调度
		设置的数值越大优先级越高(0-31)可设置相同优先级
		抢占式调度
			优先级高的优先执行
			高优先级的任务不停止，低优先级的任务永远无法执行
			被抢占的任务会进入就绪状态，等待优先级高的任务阻塞或停止
		时间片调度
			同等级优先级轮流执行，时间片流转
			一个时间片的大小取决于系统滴答定时器中断周期
			没有用完的时间片不会再使用，下次任务得到执行时还是按照一个时间片的时钟周期执行
	2.1任务状态
		运行状态
			正在执行的任务，STM32同一时间仅执行一个任务
		就绪状态
			任务可以被执行，但还未执行
		阻塞状态
			延时或等待外部事件发生时处于阻塞状态
		挂起状态
			类似暂停，调用函数vTaskSuspend()进入挂起态需要调用解挂函数vTaskResume()才可以进入就绪态
		仅就绪状态可以转变为运行状态
		其他任务想运行就必须转变为就绪状态
	2.2状态列表与事件列表



链表：
	void *malloc(unsigned int size);
		动态分配size大小的内存空间
		申请成功返回申请的内存地址

	void *calloc(unsigned n, unsigned size);
		在内存中分配n个长为size的连续数组空间地址
		成功返回指向该地址的指针，失败返回NULL

	void free(void *ptr);
		释放prt指向的内存区域
		prt：malloc或calloc申请的地址空间
链表插入操作



struct student{
	char Name[20];	//姓名
	int iNumber;	//学号
	struct Student *pNext;	//z指向下一节点
}

int iCount;	//全局变量，表示链表长度

/******************
* Create函数的功能是创建链表，动态分配内存空间的方式创建链表
* 该函数将会返回链表的头指针
*（在链表的尾结点插入）
*******************/
struct Student *Create(void){
	struct Student *pHead = NULL;	//初始化链表头指针
	struct Student *pNew, *pEnd;	//指向新的节点，，指向原来的尾部节点
	iCount = 0;
	pEnd = pNew = (struct Student *)malloc(sizeof(struct Student));//申请动态内存空间

	while(pNew->iNumber != 0){
		iCount++;
		if(iCount == 1){
			pNew->pNext = pHead;	//首次加入节点初始化
			pEnd = pNew;			//跟踪新加入的节点
			pHead = pNew;			//头指针指向头节点
		}else{
			pNew->pNext = NULL;		//初始化指向新加入的节点的指针
			pEnd->pNext = pNew;		//原来的尾节点指向新的节点
			pEnd = pNew;			//pEnd指向新节点
		}
		pNew = (struct Student*)malloc(sizeof(struct Student));	//分配节点内存空间
        scanf("%s",&pNew->cName);           // 再次输入新的节点进入循环判断，如果满足新节点要求则执行循环继续添加，如果不满足则跳出循环
        scanf("%d",&pNew->iNumber);
	}
	free(pNew);		//释放未使用的内存空间
	return pHead;	//返回链表的头指针
}

// 链表的插入操作（在链表的头结点插入）
// 该函数将会返回链表的头指针
struct Student *Insert(struct Student *pHead)
{
    struct Student *pNew;                   // 指向新分配的空间
    pNew = (struct Student*)malloc(sizeof(struct Student));  // 分配内存空间，并返回指向该内存空间的指针
 
    scanf("%s",&pNew->cName);               // 输入新加入的学生姓名
    scanf("%d",&pNew->iNumber);             // 输入新加入的学生学号
 
    // 两步操作：1.将原来的头节点地址给到新节点指向的下一级节点；2.将新节点的地址给到头节点。
    pNew->pNext = pHead;                    // 新节点指针指向原来的首节点（将原来的头结点地址给到新加入的节点指向的地址）
    pHead = pNew;                           // 链表头指针指向新节点（新节点变成了头节点）
    iCount++;                               // 增加链表的节点数
    return pHead;                           // 返回链表头指针
}

// 删除链表节点
// 输入：链表头结点pHead，要删除的节点下标iIndex;dd
void Delete(struct Student *pHead,int iIndex)
{
	int i;

	struct Student *pTemp;	//零时指针变量
	struct Student *pPre;	//要删除节点之前的节点

	pTemp = pHead;	//获取链表头节点
	pPre = pTemp;	//将零时指针的值赋值给pPre;

	for(i = 1;i < iIndex;i++){	//循环遍历，找到要删除的节点
		//将pTemp赋值给pPre,再将pTemp指向下一个节点，重复进行，直到找到需要定位的iIndex节点
		//此时pTemp指向的节点就是所要删除的节点
		pPre = pTemp;			// 定位到要删除的节点pTemp
		pTemp = pTemp->pNext;	// 再将pTemp指向下一个节点
	}
	pPre->pNext = pTemp->pNext;	//连接待删除节点的两边节点地址
	free(pTemp);	//释放要删除节点空间
	iCount--；		//减少链表中的元素个数
}

