typedef int u32;
typedef short u16;
typedef char u8;

#include<stdio.h>
//冒泡排序
void Bubble_Sort(void)
{
	int Array[10] = {0};
	int Temp;
	printf("请输入10个数，用回车间隔每个数\n");
	for(u8 i = 0;i < 10;i++){
		scanf("%d",&Array[i]);
	}
	printf("\n");
	for(u8 i = 0;i < 9;i++){	//循环遍历输入的数据
		for(u8 j = 0;j < 9-i;j++){	//每循环完成一次这里便少循环一次
			if(Array[j] > Array[j+1]){//前后数据对比
				Temp = Array[j];
				Array[j] = Array[j+1];
				Array[j+1] = Temp;
			}
		}
	}
	printf("从小到大依次为:\n");
	for(i = 0;i < 10;i++){
        printf("%d ",Array[i]);
    }
}


求斐波那契数列的前40个数，斐波那契函数的变化规律
F1=1,F2=1,Fn=Fn-1+Fn-2(n>=3)
int main()
{
	int f1=1,f2=1,i;
	for(i=1;i<=20;i++){	//i从1开始是为了防止打印换行 0%2==0
		printf("%12d %12d",f1,f2);
		if(i%2==0)printf("\n");//换行，每两次换行
		f1=f1+f2;	//n = 3;	单数
		f2=f2+f1;	//n = 4;	双数
	}
	return 0;
}
对数据的前两个赋初值1
for循环从第三个数开始实现依次累加


猴子吃桃
每天吃掉前一天一半多一个
int Monkeys_Eat_Peaches(u8 number)	//吃了几天传入几天 递归
{
	int Peaches_Number = 0;
	if(number == 1){
		Peaches_Number = 1;
	}else if(number > 1){
		Peaches_Number = ((Monkeys_Eat_Peaches(number - 1) + 1)*2);
	}
	return Peaches_Number;
}

int main(void)
{
	printf("Monkeys_Eat_Peaches:%d\n",Monkeys_Eat_Peaches(10));
}


int main()
{
	int i,m=1,sum;
	for(i=1;i<10;i++){
		m=2*(m+1);
	}
	printf("%d",m);
	return 0;
}

素数问题
求一定范围内的素数
素数：大于1的自然数，除了1与它本身不不再有其他因数的自然数
int main (void)
{
	int i,j;
	int Start_Data;
	int End_Data;
mark:
	printf("输入一个范围，输出其中的素数\n");
	scanf("%d",&Start_Data);
	scanf("%d",&End_Data);
	if(Start_Data > End_Data){
		printf("起始大于结束，请重新输入\n");
		goto mark;
	}
	printf("从%d到%d范围内的素数为:\n",Start_Data,End_Data);
	for(i = Start_Data;i <= End_Data;i++)
	{
		for(j = 2;j < i;j++){
			int temp = 0;
			temp = i % j;
			if(temp == 0 && i != j)	//除了1与它本身不不再有其他因数的自然数
				break;	//不是素数下一个
			else {
				printf("%4d",i);
				break;
			}

		}
	}
	return 0;
}


最大公约数最小公倍数
int main(void)
{
	int Number_1,Number_2,Temp_Number;
	int Max,Min;
	int i;
	printf("请输入两个数:\n");
	scanf("%d",&Number_1);
	scanf("%d",&Number_2);
	if(Number_1 > Number_2)
		Temp_Number = Number_2;
	else
		Temp_Number = Number_1;
	for(i = Temp_Number;i > 0;i--){//从小一点的那个数开始往下遍历
		if(Number_1%i == 0 && Number_2%i == 0){	//公约数判断
			Max = i;
			break;
		}
	}
	Min = (Number_1 * Number_2)/Max;
	printf("最大公约数:%d\n",Max);
	printf("最小公倍数:%d\n",Min); 
	return 0;
}

水仙花数:其每位数的立方和等于其本身
int main(void)
{
	int G_Data,S_Data,B_Data;
	int Temp_Number;
	int i;
	for(i = 100;i < 999;i++)
	{
		B_Data = i/100;       //百位
		S_Data = i/10%10;     //十位
		G_Data = i%10;        //个位
		Temp_Number = B_Data*B_Data*B_Data + S_Data*S_Data*S_Data+G_Data*G_Data*G_Data;
		if(Temp_Number  == i)
			printf("%d\n",Temp_Number);
	}
}


//求数组最大数的下标并输出其最大直
int Test(int *Array,int Len,int *p)//传入数组，数组的长度，指向最大值的指针
{
	u8 i;
	*p = 0;	//从第0号元素开始判断
	for(i = 0;i < Len;i++){	//遍历数组元素
		if(Array[*p] < Array[i])	//比较大小
			*p = i;
	}
	return Array[*p];
}
int main(void)
{
    int Array_Data[3];
    int *p_data;
    int Data = 0;
    int i;
    for(i = 0;i < 3;i++){
        Array_Data[i] = i+10;
    }
    Data = Test(&Array_Data,3,p_data);
    printf("数组最大值:%d\n",Data);
    printf("下标:%d\n",*p_data);
}


完数：= 因子之和 例 6=1*2*3； 6=1+2+3；

int main(void)
{
	int Max_Flag,Number = 0;
	int i,j,m;
	int Sum = 0;
	int TempArray[15] = {0};
	printf("请输入一个最大范围\n");
	scanf("%d",&Max_Flag);
	printf("小于%d的所有完数为：\n",Max_Flag);
	for(i = 2;i < Max_Flag;i++)//遍历所有数
	{
		for(j=1;j<i;j++)//遍历当前数
		{
			if(i%j==0)//因子判断
			{
				printf("  因子:%2d",j);
				TempArray[Number] = j;
				Number++;
			}
		}
		printf("\n");
		for(m=0;m<Number;m++){
			Sum+=TempArray[m];	//校验和
		}
		Number = 0;
		if(Sum = i){	//完数判断
			printf("%2d\n",i);	//输出完数
		}
		Sum = 0;
	}
	return 0;
}




模电简要知识
模拟电路:
	1.二极管
		特性:正向导通，方向截止,反向过压击穿，电压电流非线性，从P(+)流向N(-)
		分类:稳压、续流、发光二极管
	2.三极管(晶体管)	 箭头朝内PNP
		分类:NPN  PNP
		特性:放大电路(电流控制)
			开关，NPN型B极高导通、PNP型B极低导通
	3.MOS管(场效应管)  箭头朝内 PNP
		分类:只需要掌握 绝缘栅型场效应管的N沟道增强型和P沟道增强型。
		特性:P沟道(NPN)增强型，栅极高导通，低截止
			N沟道(PNP)增强型，栅极低导通，高截止
数字电路
	1.二进制数据表达
		1.表示图片:将图片切分成许多像素点，拆的越多显示越清晰，所占空间越大
			每个像素点每个颜色占32位?rgb三色共占32*3 = 12byte;
		2.表示声音:采样(分隔曲线)、量化(分隔高度)
		3......
	2.七个门电路
		与、或、非、异或、与非、或非、异或非。
	3.运算器
		......
	4.锁存器和触发器
		锁存器通过EN选择数据和锁定数据(S'R'锁存器没有使能开关)
		触发器通过时钟控制存储数据，一个时钟周期存储一次数据
	5.中文编码
		GBK中文一般2Byte、UTF8动态的，中文一般1到4Byte



	电路
		电阻：同一电压下，电阻值越大电流越小
	一般概念
		通路：正常链接的电路
		短路：断开的电路
		短路：到线上没用负载的电路，短路的支路上电流无限大
			与它并联的电路则分不到电流。
		直流点：方向不发生改变的电流
		交流电：随周期变换方向改变的电流(正负交替流动)
		弱电：交流36V以下，直流24V以下，一般用于信号传递
		强电：大于弱电的电压，一般用于能量传递
		插头：左零右火上接地 	
	串联分压阻值相加
	并联电路中，电流和电阻成反比。两电阻并联，如果阻值比为2：1，则电流比为1：2


电子元器件
	1.电阻：
		上拉电阻：并联一个接5V电源的电阻，得到一个稳定的高电平输出。
		下拉电阻：一个连接地线的电阻和后面的电路并联，来保证后面的电路收到一个0V的电压（低电平）。
		限流电阻
		零欧电阻(阻值无限等于0)
	2.电容：
		特点：通直隔交，以充电的反向放电
		三要素：容量、耐压值、容差。
		分类：有极性、无极性
		用法：滤波，旁路电容，耦合电容。
	3.电感：
		隔交通直，以充电的方向放电，电感以磁场的方式储存电能
		参数：
			电感量：电感的感量与线圈的面积、圈数、有无磁心有关
	4.继电器：
		特点：小电流控制大电流，自动调节、安全保护、转换电路，开关作用等
		参数：
			额定电压：正常工作状态下所能承受的最大电压
			最大切换电流：额定电压下，通过触电最大负载值
			最大切换电压：可经过触电的最大电压
			触电形式：常开型、常闭型、转换型。		
	5.保险丝：
		作用：保护后继电路中的元器件
		参数：
			额定电压：最高工作电压
			额定电流：最高工作电流
			熔断速度：TT(特曼)、T(慢速)、M(中速)、F(快速)、FF(特快)
		分类：一次性保险丝、自我恢复保险丝
	6.蜂鸣器：
		作用：报警、提示
		分类：有源、无源蜂鸣器
	7.电池
		18650：直径18mm、长度65mm、圆形
	8.稳压芯片：
		作用：稳定电压输出
		参数：输入电压、输出电压、输出电流
		常见：7805稳压电源芯片、AMS1117-303稳压电源芯片




快速排序
#include <staio.h>
#include <stdlib.h>
#include <time.h>

void Recursion(int *arr,int start,int end)
void Quick_Sort(int *arr,int len)	//快排
{
	Recursion(arr,0,len-1);
}

//快排的递归逻辑
void Recursion(int *arr,int start,int end)
{
	int Com_Element = arr[start];//第一个作为比较的元素
	int Start_Temp = Start;	//记录首元素下标
	int End_Temp = end;		//记录末尾元素下标
	int Temp_Data = start;
	if(Start_Temp <= End_Temp){	//判断位置是否重叠
		while(1){
			while(Temp_Data <= End_Temp && Com_Element)
		}
	}

}








stm32时钟系统
	有5个时钟源
		外部高速时钟
		内部高速时钟	rc振荡器，精度不高
		外部低速时钟
		内部低速时钟	提供低功耗时钟，主要供独立看门狗和自动唤醒单元使用
		PLL锁相环倍频输出，提供2-16倍的倍频输出

堆、栈的区别
	栈：系统自动分配与释放
	堆：malloc() 函数申请	delete 运算符释放

#define GET_ONE_YEAR_SIC()    (365*24*60*60)UL //UL：无符号长整型类型

#define MIN(a,b)    (a > b ? a:b)

预处理器标识#error目的
	停止编译，显示错误
	保证程序是按照设想的进行编译
static关键字作用
	函数内被声明为静态变量，在函数调用过程中不变
	函数外可以被模块内的所有函数访问，本地全局变量
const关键字作用
	修饰的变量只读
volatile关键字的作用
	告诉编译器所修饰的变量是容易改变的
	每次使用时都从内存中重新获取
	告诉编译器变量容变，不应该使用寄存器来储存值
	确保每次读取到的值都是最新的值

设置一绝对地址为0x67a9的整型变量的值为0xaa66。
	int *p = Null;
	p = (int *)0x67a9;	//指向地址
	*p = 0xaa66;	   //指向数据

__interrupt定义的中断服务子函数(ISR)
	不能传参，不能有返回值

表达式中存在有符号与无符号类型时自动转换为无符号类型
隐式转换
	算数运算中低类型能转换为高类型数据
	赋值运算右边的表达式自动转换为左边的类型并赋值给它
	函数调用时传参时，自动将实参转换为形参后赋给行参数
	等同赋值运算转换
typedef int u32;
typedef short u16;
typedef char  u8;

static 
	修饰变量叫静态变量
	只初始化一次
	修饰的全局变量只能在当前文件调用

	修饰函数可以与其他文件函数名相同，不会冲突
	只能被当前文件调用

基于ROM运行与基于RAM运行的区别
	基于ROM
		速度慢，掉电不丢失
	基于RAM
		速度快，掉电丢失
	芯片复位一定是从ROM开始的


RAM(内存)与ROM(外部存储器)的区别
	SRAM：静态RAM
		执行速度非常快，价格贵，一般只在要求很苛刻的地方使用
		例如cpu的一级缓存，二级缓存
		上电直接使用不需要程序初始化
	DRAM：动态RAM
		保留数据时间短速度一般上电后需初始化才能使用

	PROM:可编程只读存储器
	EROM:可擦除可编程只读存储器，掉电不丢失
	EEPROM:带电可擦可编程只读存储器，掉电不丢失，写入时间较长，较慢
	Flash存储器(闪存):电子可擦可编程，掉电不丢失，可快速读取