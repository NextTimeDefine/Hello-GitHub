上电检测到声音
	判断是否为声控开机
	是，开机ok



	关机后闹钟不会响


	调节时间时闪烁
		长安后不在闪烁

	双击问题


闪烁问题
	长按保持
	抬起后会发送抬起消息

	抬起消息处理
		if抬起



syscfg_write(VM_LOW_BATTER , &Low_Batter, 1);

	按键消息

	抬起按键消息

	if显示暂停
	break


void Mode_set(u8 mode,u16 start_duty)
{
    static u16 i = 0;
    
    static u8 Temp_data = 0;
    if(Temp_data != mode)
    {
        Temp_data = mode;
        i = start_duty;
    }
    i++;
    if(i > 8)
        i = 8;
    switch(mode){
        case 1:
            led_mode_set(mode_A_array[i]);
            break;
        case 2:
            led_mode_set(mode_B_array[i]);
            break;
        case 3:
            led_mode_set(mode_C_array[i]);
            break;
        case 4:
            led_mode_set(mode_D_array[i]);
            break;
    }
}




电量检测
设置最大亮度
从最大亮度按比例衰减


            Key_Power_Flag = 1; //按键开机，允许充电唤醒
            printf("KEY_POWER_ON:%d\n",Key_Power_Flag);
            syscfg_write(VM_LOW_BATTER , &Key_Power_Flag, 1);  

    int ret = syscfg_read(VM_LOW_BATTER , &Key_Power_Flag, 1);
    if((ret != 1 || Key_Power_Flag >=2))
        Key_Power_Flag = 0;



void User_Write_Current_Mode(u8 mode)
{
	u8 Temp_Data = 0;
	if(mode <= 4){
		Temp_Data = mode;
	}else{
		Temp_Data = 1; //优先A模式
	}
	syscfg_write(VM_SET_MODE , &Temp_Data, 1); //将当前模式写入VM
}
u8 Get_Current_Disp_Mode(void)
{
	u8 Temp_Data = 0;
	int ret = syscfg_read(VM_SET_MODE , &Temp_Data, 1);
    if(ret != 1 || Temp_Data >=5 || Temp_Data == 0)
        Temp_Data = 1;
    return Temp_Data;
}


u16 DisModeFlag[2] = {0};
void user_write_dis_mode_info(u8 data)
{   
    DisModeFlag[0] = data;
    DisModeFlag[1] = 0xaa;
    int size = syscfg_write(CFG_USER_DISMODE_BEGIN, (u16 *)&DisModeFlag, sizeof(DisModeFlag));
}
u8 user_read_dis_mode_info(void)
{
    int size = 0;
    size = syscfg_read(CFG_USER_DISMODE_BEGIN, (u16 *)&DisModeFlag, sizeof(DisModeFlag));
    if (size != sizeof(DisModeFlag) || (DisModeFlag[1] != 0xaa)) {
        //reset
        memset(&DisModeFlag, 0, sizeof(DisModeFlag));
    } else {
        //check 
        return DisModeFlag[0];
    } 
}


            u8 Temp_Mode = user_read_dis_mode_info();
            
	        if(Temp_Mode == 1)
	            app_task_put_key_msg(KEY_IR_A,0);
	        else if(Temp_Mode == 2)
	            app_task_put_key_msg(KEY_IR_B,0);
	        else if(Temp_Mode == 3)
	            app_task_put_key_msg(KEY_IR_C,0);
	        else if(Temp_Mode == 4)
	            app_task_put_key_msg(KEY_IR_D,0);

            AD_CH_PC5

            adc_get_value(AD_CH_PC5)




检测电压
    if正在充电
    {
        if(电池电压 > 375){ //快满电了
            开启计时
        }
        if(计时开启)
        {
            if(未到)
            {
                时间加
            }
            else 时间到了
            {
                计时清零
                关闭充电
                关闭计时
            }
        }
    }

TCFG_RLED_CTRL
        if(val >355){   //满电3.6
            TCFG_LED_CTRL(IO_PORTA_04,1);       //红
            TCFG_LED_CTRL(IO_PORTA_03,0);       //绿
        }else{
            TCFG_LED_CTRL(IO_PORTA_04,0);   
            TCFG_LED_CTRL(IO_PORTA_03,1);   
        }


磷酸铁锂电池
    充电拉高判断3.7伏才算满电
    如如果电压高于3.7伏则再允许充电30分钟
    30分钟后断开充电
    断开充电后除非太阳能断开充电，否则不允许充电

    太阳能电压检测低于2.2才算断开充电


    // 572//2.3    596//2.4
    //718//2.9     748//3.0







    开机灯闪烁10S后熄灭
    上电直接开机灯开始闪烁
        计时10S
            关灯，不再开灯




void led_blink(void)    //半秒闪烁一次，闪烁10S自动关闭
{
    static u8 Time_Cnt = 0;
    static u8 Number_Cnt = 0;
    if(Number_Cnt < 20){
        Time_Cnt++;
        if(Timer_Cnt > 5){
            Number_Cnt++;
            Timer_Cnt = 0;
            if(TCFG_GETLED_STATE())
                LED_LED_CTRL(0);
            else
                LED_LED_CTRL(1);
        }
    }else{
        Number_Cnt = 0;
        Timer_Cnt = 0;
        LED_LED_CTRL(0);
        sys_s_hi_timer_del(Led_Scan_ID);
    }
}


u32 Led_Scan_ID = 0;
if(Led_Scan_ID == 0)
    Led_Scan_ID = sys_s_hi_timer_add(NULL,led_blink,100);   //100MS扫描一次






//华氏转摄氏
C = (F-32)*5/9
//摄氏转华氏
F = 9*C/5+32


    if充电
        if电压高于3.65
            继续充电30分钟
            断开充电
        else if电压低于3.50
            继续充电


敲击？
当做按键检测？
不会出现按键信号不对问题？
按理说应该不会，待测试


    4分钟扫描一次
        if满电{
            if第一次满电{
                继续充电
            }else{
                断开充电
            }
            if电量低于4.1
                开启充电
        }


开机进入music模式
    if案件按下
        切换模式
        进入蓝牙模式
            蓝牙未连接灯闪烁
            蓝牙已连接灯常亮
            播放音乐时灯闪烁

敲击从头开始播放
    KEY_MUSIC_PLAYER_PLAY_FIRST//从头开始播放
播放完成不自动下一曲
    ///结束消息处理(自动下一曲)
    case KEY_MUSIC_PLAYER_END:  //屏蔽此消息处理




///异常中断，asser打印开启
const int config_asser = 1;


VDDIO POR：是首次上电，即芯片从没电到有电，从头跑

VDDIO LVD：是电池电量不够或者VDDIO被扯，导致VDDIO 的电压低于设定的阈值，复位了

WDT：是看门狗超时，复位了

VCM：是芯片vcom引脚，默认的短按就会复位，就是通常板子上的reset键就是用这个脚做的。

PPINR：是设置的长按复位脚，长按引起的复位

SOFT RESET：是P33系统管理的复位，一般是程序里执行了复位函数
            如果代码异常了，异常中断里会执行复位函数来复位芯片
            例如一些非法操作，如除0异常，非法地址访问等等

DVDD NO OK：是供电方式没有配置对，样机是DCDC供电的，但是配置成了LDO供电方式了    

POWER RETURN 软关机唤醒

vcom 脚拉高的时候会复位,可以用VCOM复位来做复位功能

开关中断(成对使用)
extern void local_irq_disable();    //关闭中断
extern void local_irq_enable();     //开启中断

打印显示:cpu_in_irq 意思是当前在中断里
        因为VM的临界保护是使用了信号量，操作系统的信号不能在中断状态、
        或者中断关闭状态获取，所以不能在中断写入VM




垂直位置旋钮可设置所选通道的垂直显示位置
转动旋钮显示的波形会上下移动，，地也会上下移动
按下垂直旋钮垂直显示位置快速恢复到零点位置

垂直衰减旋钮调整波形幅度该旋钮改变“Volt/div”垂直档位变化
同时下状态栏对应通道显示的幅度值也会变化


右上角 控制显示器的波形在水平轴的方向变化
       水平位置旋钮(position)控制显示水平变化
       水平衰减(scale)改变水平时基档位设置，转动改变s/div水平档位
右下角 控制显示器的被测信号稳定




2.4伏 VDDIO给触摸供电
    触摸一直触发
        加大VDDIO 加大弱VDDIO

弱VDDIO驱动带载能力较弱，容易被拉扯
    例如使用VDDIO或者IO供电如果弱VDDIO为2.4伏
    从强档位到弱档位VDDIO会被拉扯导致供电异常

调好的eq文件添加到软件里需要把eq调试关闭才能试听


DAC输出前后有‘PO’的生声音(注意区分是功放引起的还是DAC引起的)
    if DAC输出的方式是隔直方式
        app_audio.c中
        函数内void app_audio_output_ch_mute(u8 ch,u8 mute)
            注释audio_dac_ch_mute(&dac_hdl,ch,mute);



4.2伏电池
4.2-3.9   满电
3.9-3.8   三格电量
3.8-3.72  两格电量
3.72-3.65 一格电量
低于3.65 低电报警
低于3.55低电关机
用检测电压来显示电量精度不高时可用

外挂Flash播放不了
    首先确定是否能读到ID号打印显示flash_read_id:显示id号


蓝牙提示音未播放完成被蓝牙连接打断
    播放完成之后再初始化蓝牙

拔出U盘/TF卡进入到指定模式
music.c中
    KEY_MUSIC_PLAYER_QUIT
        app_task_switch_to(需要跳转的模式)

static void dev_manager_task(void *p)
{   //传入0则不过滤隐藏文件和.开头文件
    hidden_file(1); //默认打开过滤隐藏文件和.开头文件
}

减压木鱼
{
    单曲循环(理论上可以不要)，敲击从头播放
    播放完成不自动下一曲

    音量调节一次+10(最大音量30)
    超过最大音量音量加按下不判断最大音量
    音量加判断最大音量
    超过最大音量则回到0
    音量4档调节，默认2档音量
}









检测到低电平
触发中断


检测到震动
    延时一段时间在允许继续检测


不要自动关机
充电开机唤醒

充电开机进入IDLE模式
充电开机不需要开机提示音




    1
        1.2
    2
        2.4
    3
        3.4
    4
        3.4
    0
        关
    gpio_set_pull_up(IO_PORTA_02, 0);   // PA2
    gpio_set_pull_down(IO_PORTA_02, 0);
    gpio_set_direction(IO_PORTA_02, 1);
        


void Charge_Display(void)   //2ms扫描一次
{
    static u8 i = 0;
    static u8 Time_Cnt = 0;
    static u8 Disp_Led_Num = 0;
    static u8 data = 0;
    static u8 Dis_Static = 0;

    static u8 Last_Bat_Data = 0;
    if(Last_Bat_Data != get_bat_disp_level();){
        data = get_bat_disp_level();   //电量等级
        switch(data){
            case 0x33:
                i = 4;
                Dis_Static = 4;
                break;
            case 0x44:
                i = 3;
                Dis_Static = 3;
                break;
            case 0x55:
                i = 2;
                Dis_Static = 2;
                break;
            case 0x66:
                i = 1;
                Dis_Static = 1;
                break;
            default:
                i = 0;//低电
                Dis_Static = 0;
                break;
        }
    }
    i++;
    if(i>Disp_Led_Num)
        i = Dis_Static;
    Display_Led(i);
    Time_Cnt++;
    if(Time_Cnt > 250){
        Time_Cnt = 0;
        Disp_Led_Num++;
        if(Disp_Led_Num > 4){
            Dis_Static = 0;
            Get_Bat_Flag = 0x55;
        }
    }
}      



充电灯效
    


    检测当前电量
        从当前电量开始显示电量往上加


例如当前电量2
    则
        2->3->4->2循环跑

222222


12
13
21
31

23
32






    增加充电保护

    修改充电灯
    

    显示整体往后移动一位
    清除显示多清除一位
    
SYS RESET


APP-通讯协议
    0x01 + 0x01 表示播放
         + 0x00 表示暂停
    0x02 + 0x01 表示上一曲
         + 0x00 表示下一曲
    0x03 + 0x00-0x80 表示音量设置 0~16级
    0x04 + 0x00-0x02 表示修改EQ模式
    0x05 + 10个字节数据，每个字节数据表示一个EQ频点的增益，范围:-12~12;
    0x06    APP获取设备当前播放状态
        回复：0x06 + 0x00 表示暂停 + 0x01 表示正在播放
    0x07 获取音量数据
        回复：0x07+音量数据0x00~0x80;

 输出频率 = 时钟源频率 /【2*(上限寄存器设置的值+1)*预分频值*(分频+1)】
 (2 x(k+1) x(s2+1) = 6 or 7




    频率 = 时钟频率 / (CB +1)

    CB = 计数器上限
       = {计数上限高位寄存器[7:0],计数上限低位寄存器[7:6]}
https://docs.github.com/en/get-started/start-your-journey/finding-inspiration-on-github



I2S
    1、串行时钟SCLK：频率= 2 * 采样频率 * 采样位数。
    2、帧时钟LRCK(也称WS)：字段（声道）选择，用来切换左右声道数据。WS = 采样频率(fs)。
        a、1（左声道）
        b、0（右声道）
    3、串行数据SDATA：二进制补码表示的音频数据（MSB--->LSB：数据由最高位到最低位依次传输）

数据格式
    根据SDATA数据相对于LRCK和SCLK的位置不同分为
        左对齐(较少使用)
        I2S格式(即飞利浦规定的格式)
        右对齐(也叫日本格式、普通格式)。

数据存储
    如果是左右声道数据交替存储成一维数组，这种格式称为packed
        格式为L R L R L R …L R L R
    如果是分开存储成二维数组，这种格式称为planar
    格式为LLLLLLLLLLLLLL和RRRRRRRRRRRRR
    



T26
    电池图标需要常亮
    不受模式切换或者按键操作影响



// 内置收音初始化，会造成显示闪烁
fm_inside_on();  //fm analog init



pwd：显示当前所处目录


linux下一切皆为文件
linux系统文件
/bin文件：存放经常使用的命令，任何人都可使用
/boot文件：启动相关文件，用于启动Linux
/cdrom：挂载CD镜像，目前逐渐淘汰
/dev:存放Linux外部设备
/etc:存放所有的系统管理所需要的配置文件(系统和应用程序的配置文件)
/home:用户主目录，每个用户都有一个自己的目录
      一般该目录名称是以用户的账号命名
/lib:存放系统最根本的动态连接共享库，类似windows系统里的DLL文件
     几乎所有的应用程序都需要这些共享库
/lib32和/lib64:属于备用格式基本共享库(可选)，提供对32和64位不同程序的库
/media:挂载一些多媒体设备，linux系统会自动识别一些设备，如U盘，光驱等
       识别成功后，linux系统会把识别的设备挂载到此目录下
/mnt:临时挂载别的文件系统，例如将光驱挂载在/mnt/上，就可以进入该目录
     查看光驱里的内容，/mnt目录用法与/media类似，只能用来暂时挂载 
/opt:可做软件测试或安装额外的软件目录
/proc:存放程序的相关信息，是一种伪文件系统(虚拟文件系统)，存储的是当前内核的运行状态的一系列特殊文件
      是一个虚拟目录，它是系统内存的映射，可以通过直接访问这个目录来获取系统信息
/root:系统管理员主目录，存放系统管理员相关的东西，需要输入密码才能进入
/run:临时文件系统，存储系统启动以来的信息，系统重启时这个目录下的文件会被清理掉
/sbin:与/bin类似，只是这里的/sbin是给系统管理员使用的  
/snap:ubunt下面的软件管理工具，类似apt软件管理工具
/srv:存放网络服务相关信息，一些网路服务启动以后，这些服务所需取用的资料目录
/sys:存放一些硬件操作接口，此目录使的控制终端外设变得更简单
/tmp:存放一些零时文件，任何人都可进行存取，不建议将重要数据放在此文件夹下面
/usr:相当于根目录，用户很多的应用程序都存放在这个目录之下
/var:存放一些易变的文件，一些不断扩充着的东西。

Linux中比较重要的目录：
    /etc:系统中的配置文件，如果更改了该目录下的某个文件可能导致系统不能启动
    /bin,/sbin,/usr/bin,usr/sbin:系统预设的执行文件的放置目录
    /var:这是一个非常重要的目录，系统上炮了很多程序，每个程序产生的日志会被记录在此目录下
总结：
    做Linux开发，要记住一句话：Linux一切皆文件


Shell命令:
    ls -l:查看该目录下所有的文件详细信息
        文件详细信息:文件权限 + 连接数量 + 文件所有者 + 文件所属用户组 + 
                    文件大小 + 最后被修改时间 + 文件名
        文件权限：文件类型(第一个字母表示 d:目录 -:文件) +
                 用户权限(三个字母表示 r:可读 w:可写 x:可执行) + 
                 用户组权限(三个字母表示 r:可读 w:可写 x:可执行) + 
                 其他用户权限(三个字母表示 r:可读 w:可写 x:可执行) + 
                 例：drwxrwxr-x:表示目录文件，用户与用户组可读写执行，其他用户只能读和执行

在Linux中一共有七种文件类型:
    -:普通文件，包括文档图片音乐、纯文本(ASCII)、二进制文件、数据格式文件以及各种压缩文件
    d:目录文件，目录，可用cd命令进入
    c:字符设备管理，Linux驱动里的字符设备驱动，例:串行设备、音频设备、键盘、鼠等
    b:块设备文件，储存设备驱动，例如:硬盘、U盘等
    p:管道管理，FIFO也是一种特殊的文件类型，主要用于解决多个程序同时存取一个文件造成的错误
    l:链接文件，类似windows下的快捷方式
    s:套接字文件，这类文件通常用在网络数据连接，可以启动一个程序来监听客户的要求
      客户端就可以通过套接字来进行数据通信

在Linux 系统中，使用命令“chmod”修改一个文件的权限
chmod 777 xxxx(文件名字)：意思就是把这个文件的权限全面开放
但是要记住，系统本身的文件，千万不要瞎修改
权限不够时可以在命令前加上 sudo 
加上sudo零时获取管理员权限，需输入管理员密码

linux系统是通过UID来确认用户权限的，如果将用户的UID改为0那么系统登录会把用户视为管理员用户
每行的用户组的信息都以 “:” 作为分割符，划分为4个字段，每个字段所表示的含义如下：
    组名：密码：GID：该用户列表中的用户列表
    qzh :x   ：27 ：sudo


查询当前磁盘挂载的文件系统：df   -T –h 

Shell命令
    Shell是一个应用程序，是用户与linux内核沟通的桥梁
    负责接收用户输入的命令，根据用户输入的找到其他程序并运行
    Shell负责将应用层或用户输入的命令传递给系统内核
    由操作系统内核爱完成相应的工作，然后将结果反馈给应用层或者用户

    例如 输入：ls
            Shell程序找到“ls”程序并运行，把结果打印出来


绝对路径：
    在 Linux 中，从根目录下出发可以找到任意目录、任意文件，Linux下的根目录为“/”。





linux常用命令
    pwd:显示当前工作目录的绝对路径
    ls [选项] [路径]:显示指定目录下的内容
        ls -a:显示所有的文件以及子目录，包括‘.’开头的隐藏文件
        ls -l:显示文件的详细信息，比如文件的形态，权限，所有者，大小等信息
        ls -t:将文件按照创建时间排序
        ls -A:和-a一样，但是不列出‘.’(当前目录)和‘...’(父级目录)
        ls -R:递归列出所有文件，包括子目录中的文件
    其中命令里的参数可以混合使用，例如 ls -al:显示所有文件的详细信息，包括‘.’开头的隐藏文件
    
    cd:切换路径
        cd /:根目录
        cd ~:当前用户主目录
        cd .:当前路径
        cd ...:上一路径
        cd .../...:上上级目录
        在Linux中， “.” 表示当前路径，"…" 表示上一级路径，“…/…” 表示上上级目录：
    mkdir:创建目录
        mkdir -p [目录]
            -p:如果要创建的目录其上层目录还未创建，那么会一起创建上层目录
    touch:修改文件时间，如果文件不存在则创建空文件
        touch [参数] [文件名]
        主要参数：
            -a:只更改存取时间
            -c:不建立任何文件
            -d<日期>:使用指定的日期，而非当前日期
            -t<时间>:使用指定的时间，而非当前时间
    rmdir:删除目录
        rmdir -p [文件夹(目录)]
            -p:删除指定的文件夹(目录)以后，若上层文件夹(目录)为空的话就将其一起删除
    rm:删除文件或目录
        rm [参数] [目的文件或文件夹目录名]
        主要参数：
            -d:直接把要删除的目录的硬连接数据删成0，删除该目录
            -f:强制删除文件和文件夹(目录)
            -i:删除文件或文件夹(目录)之前先询问用户
            -r:递归删除，指定文件夹(目录)下的所有文件和子文件夹全部删除掉
            -v:显示删除过程
    cp:复制文件或目录
        cp [参数] [源地址] [目的地址]
        主要参数：
            -a:此参数和同时指定“-dpR”参数相同
            -d:在复制有符号连接的文件时，保留原始的连接
            -f:强行复制文件，不要关复制的文件是否存在于目标目录
            -l:覆盖现有文件之前先询问用户
            -p:保留源文件或者目录的属性
            -r或者-R:递归处理，将指定目录下的文件及子目录一并处理
    mv:文件移动命令
        mv [参数] [源地址] [目的地址]
        主要参数：
            -b:如果要覆盖文件的话先进行备份
            -f:若目标文件或目录于现在的文件重复，直接覆盖目的文件或目录
            -l:在覆盖前先询问用户
    cat:串联文件的内容并打印出来
        cat [选项] [文件]
        虽然cat也有选项可加，但是一般使用都不加选项，直接cat+文件名
        而且一般将cat当成文本查看器就行
    find:用于在目录结构查找文件
        find [路径] [参数] [查找条件]
        主要参数：
            -name “filename” 按照文件名称查找，查找与 filename匹配的文件，可使用通配符
            -depth 从指定目录下的最深层的子目录开始查找
            -gid<群组识别码> 查找符合指定的群组识别码的文件或目录
            -group<群组名称> 查找符合指定的群组名称的文件或目录
            -size<文件大小> 查找符合指定文件大小的文件
            -type<文件类型> 查找符合指定文件类型的文件
            -user<拥有者名称> 查找符合指定的拥有者名称的文件或目录
        如果没有指定查找目录，则为当前目录
    grep:查找文件中符合条件的字符串
        grep [选项] [查找模式] [文件名]
        主要参数有：
            -b 在显示符合关键字的那一列前，标记处该列第 1个字符的位编号
            -c 计算符合关键字的列数
            -d<进行动作> 当指定要查找的是目录而非文件时，必须使用此参数！否则 grep指令
            将回报信息并停止搜索
            -i 忽略字符大小写
            -v 反转查找，只显示不匹配的行
            -r 在指定目录中递归查找
            -n 显示所在的行号
        grep命令一次只能查一个关键字

文件权限和属性
    chmod:改变文件权限
        chmod [参数] [文件名/目录名]
            chmod 777 xxxx(文件名/目录名)：意思就是把这个文件的权限全面开放
    chown:改变文件所有者
        chown [参数] [用户名.<组名>] [文件名/目录]
    chgrp:改变文件所属组
        chgrp [参数] [所属群组] [文件名/目录]    









