# 一、c++基础

## 1 c++初识

### 1.1 编写helloworld

```c++
#include <iostream>
using namespace std;
int main() {
    cout << "Hello, World!" << endl;
    //任意键退出
    system("pause");
    return 0;
}
```

### 1.2 变量

作用：给一段指定空间命名，方便操作这段内存

语法：数据类型 变量名 = 初始值；

```c++
#include <iostream>
using namespace std;

int main(){
    //变量定义
    //语法：数据类型 变量名 = 初始值
    int a=10;
    cout <<"a="<<a<<endl;
    system("pause");
    return 0;
};

```

变量存在的意义：方便我们管理内存空间

### 1.3 常量

作用：用于记录程序中不可更改的数据

c++定义常量的两种方式

> 1.#define宏常量： #define 常量名 常量值
>
> ​	通常在文件上方定义：表示一个常量

> 2.const修饰的变量：const 数据类型 常量名=常量值
>
> ​	通常在变量定义前加上关键字const，修饰该变量为常量，不可以修改

```c++
#include <iostream>
using namespace std;
//常量的定义方式
//1.#define 宏常量
#define Day 7
//2.const修饰的变量

int main(){
    cout<<"一周共:"<<Day<<"天"<<endl;

    const int month=12;
    cout<<"一年共："<<month<<"个月"<<endl;
    system("pause");
    return 0;
}
```

### 1.4 关键字

作用：关键字是c++中预先保留的单词（标识符）

- 在定义变量或者常量的时候，不要用关键字

- c++关键字如下

  | **asm**    | **do**       | **if**           | **return**  | **typedef** |
  | ---------- | ------------ | ---------------- | ----------- | ----------- |
  | auto       | double       | inline           | short       | typeid      |
  | bool       | dynamic_cast | int              | signed      | typename    |
  | break      | else         | long             | sizeof      | union       |
  | case       | enum         | mutable          | static      | unsigned    |
  | catch      | explicit     | namespace        | static_cast | using       |
  | char       | export       | new              | struct      | virtual     |
  | class      | extern       | operator         | switch      | void        |
  | const      | false        | private          | template    | volatile    |
  | const_cast | float        | protected        | this        | wchar_t     |
  | continue   | for          | public           | throw       | while       |
  | default    | friend       | register         | true        |             |
  | delete     | goto         | reinterpret_cast | rey         |             |

  > 提示：在给变量或者常量起名称时候，不要用c++得关键字，否则会产生歧义

### 1.5 标识符命名规则

作用：c++规定给标识符（变量，常量）命名时，有一套自己的规则

- 标识符不能是关键字
- 标识符只能有字母，数字，下划线组成
- 第一个字符必须为字母或者下划线
- 标识符中字母区分大小写

> 建议：给标识符命名时，争取做到见名知意的效果，方便自己和他人阅读

## 2 数据类型

c++规定在创建一个变量或者常量时，必须要指定出相应的数据类型，否则无法给变量分配内存

### 2.1 整型

作用：整型变量表示的是整型类型的数据

c++中能够表示整型的类型有以下几种方式，**区别在于所占内存空间不同**

| **数据类型**        | 占用空间                                        | 取值范围         |
| ------------------- | ----------------------------------------------- | ---------------- |
| short(短整型)       | 2字节                                           | （-2^15~2^15-1） |
| int(整型)           | 4字节                                           | （-2^31~2^31-1） |
| long(长整型)        | windows为4字节，linux为4字节(32位)，8字节(64位) | （-2^31~2^31-1） |
| long long(长长整型) | 8字节                                           | （-2^63~2^63-1） |

```c++
#include <iostream>
using namespace std;

int main(){
    //整型
    //1.短整型 (-32768·32768)
    short num1=10;
    //2.整型
    int num2=10;
    //3.长整型
    long num3=10;
    //4.长长整型
    long long num4=10;
    cout <<"num1"<<num1<<endl;
    cout <<"num2"<<num2<<endl;
    cout <<"num3"<<num3<<endl;
    cout <<"num4"<<num4<<endl;
    system("pause");
    return 0;
}
```

### 2.2 sizeof关键字

作用：利用sizeof关键字可以统计数据类型所占内存的大小

语法:  **sizeof(数据类型/变量**)

实例:

```c++
#include <iostream>
using namespace std;

int main(){
    cout<<"short类型所占内存空间为:"<< sizeof(short)<<endl;
    cout<<"int类型所占内存空间为:"<< sizeof(int)<<endl;
    cout<<"long类型所占内存空间为:"<< sizeof(long)<<endl;
    cout<<"long long类型所占内存空间为:"<< sizeof(long long)<<endl;
    system("pause");
    return 0;
}
```

输出结果：

> short类型所占内存空间为:2
> int类型所占内存空间为:4
> long类型所占内存空间为:4
> long long类型所占内存空间为:8

> 结论是：short<int<=long<=long long

### 2.3 实型（浮点型）

作用：用于表示小数

浮点型变量分为两种：

- 单精度float
- 双精度double

两者的区别在于表示的有效数字范围不同

| **数据类型** | 占用空间 | 有效数字范围    |
| ------------ | -------- | --------------- |
| float        | 4字节    | 7位有效数字     |
| double       | 8字节    | 15~16位有效数字 |

```c++
#include <iostream>
using namespace std;

int main(){
    //1.单精度  float
    //2.双精度  double
    //默认情况下 输出一个小数，会显示出6位有效数字
    float f1=3.1415926f;
    double d1=3.1415926;
    cout <<"f1="<<f1<<endl;
    cout <<"d1="<<d1<<endl;

    //统计float和double占用内存空间
    cout <<"float 的占用内存空间为："<< sizeof(float)<<endl;
    cout <<"double 的占用内存空间为："<< sizeof(double)<<endl;

    //科学计算法
    float f2=3e2; //3*10^ 2
    cout<<"f2="<<f2<<endl;
    float f3 =3e-2; //3*0.1^2
    cout<<"f3="<<f3<<endl;
    system("pause");
    return 0;
}
```

输出结果：

> f1=3.14159
> d1=3.14159
> float 的占用内存空间为：4
> double 的占用内存空间为：8
> f2=300
> f3=0.03

### 2.4 字符型

作用：字符型变量用于显示单个字符

语法：**char ch='a'**

> 注意1：在显示字符型变量是，用单引号将字符括起来，不要用双引号

> 注意2：单引号内只能有一个字符，不可以是字符串

- c和c++中字符型变量只占用1个字节
- 字符型变量并不是把字符本身放到内存中存储，而是将对应的ASCII编码放入到存储单元

```c++
#include <iostream>
using namespace std;

int main(){
    //1.字符型变量创建方式
    char ch ='b';
    cout <<ch<<endl;

    //2.字符型变量所占内存大小
    cout<<"char 所占内存大小:"<< sizeof(char)<<endl;

    //3.字符型变量常见错误
//    char ch2="b"; //创建字符型变量时要用单引号。
//    char ch2="sfgsdfgb"; //创建字符型变量时，单引号内只能有一个字符

    //4.字符型变量对应ASCII编码
    // a->97
    // A->65
    cout << (int)ch<<endl;
    system("pause");
    return 0;
}
```

ASCII码对照表

| ASCII值 | 控制字符 | ASCII值 | 控制字符 | ASCII值 | 控制字符 | ASCII值 | 控制字符 |
| :------ | :------- | :------ | :------- | :------ | :------- | :------ | :------- |
| 0       | NUT      | 32      | (space)  | 64      | @        | 96      | 、       |
| 1       | SOH      | 33      | !        | 65      | A        | 97      | a        |
| 2       | STX      | 34      | "        | 66      | B        | 98      | b        |
| 3       | ETX      | 35      | #        | 67      | C        | 99      | c        |
| 4       | EOT      | 36      | $        | 68      | D        | 100     | d        |
| 5       | ENQ      | 37      | %        | 69      | E        | 101     | e        |
| 6       | ACK      | 38      | &        | 70      | F        | 102     | f        |
| 7       | BEL      | 39      | ,        | 71      | G        | 103     | g        |
| 8       | BS       | 40      | (        | 72      | H        | 104     | h        |
| 9       | HT       | 41      | )        | 73      | I        | 105     | i        |
| 10      | LF       | 42      | *        | 74      | J        | 106     | j        |
| 11      | VT       | 43      | +        | 75      | K        | 107     | k        |
| 12      | FF       | 44      | ,        | 76      | L        | 108     | l        |
| 13      | CR       | 45      | -        | 77      | M        | 109     | m        |
| 14      | SO       | 46      | .        | 78      | N        | 110     | n        |
| 15      | SI       | 47      | /        | 79      | O        | 111     | o        |
| 16      | DLE      | 48      | 0        | 80      | P        | 112     | p        |
| 17      | DCI      | 49      | 1        | 81      | Q        | 113     | q        |
| 18      | DC2      | 50      | 2        | 82      | R        | 114     | r        |
| 19      | DC3      | 51      | 3        | 83      | S        | 115     | s        |
| 20      | DC4      | 52      | 4        | 84      | T        | 116     | t        |
| 21      | NAK      | 53      | 5        | 85      | U        | 117     | u        |
| 22      | SYN      | 54      | 6        | 86      | V        | 118     | v        |
| 23      | TB       | 55      | 7        | 87      | W        | 119     | w        |
| 24      | CAN      | 56      | 8        | 88      | X        | 120     | x        |
| 25      | EM       | 57      | 9        | 89      | Y        | 121     | y        |
| 26      | SUB      | 58      | :        | 90      | Z        | 122     | z        |
| 27      | ESC      | 59      | ;        | 91      | [        | 123     | {        |
| 28      | FS       | 60      | <        | 92      | /        | 124     | \|       |
| 29      | GS       | 61      | =        | 93      | ]        | 125     | }        |
| 30      | RS       | 62      | >        | 94      | ^        | 126     | `        |
| 31      | US       | 63      | ?        | 95      | _        | 127     | DEL      |

特殊字符解释

| NUL空        | VT 垂直制表   | SYN 空转同步  |
| ------------ | ------------- | ------------- |
| STX 正文开始 | CR 回车       | CAN 作废      |
| ETX 正文结束 | SO 移位输出   | EM 纸尽       |
| EOY 传输结束 | SI 移位输入   | SUB 换置      |
| ENQ 询问字符 | DLE 空格      | ESC 换码      |
| ACK 承认     | DC1 设备控制1 | FS 文字分隔符 |
| BEL 报警     | DC2 设备控制2 | GS 组分隔符   |
| BS 退一格    | DC3 设备控制3 | RS 记录分隔符 |
| HT 横向列表  | DC4 设备控制4 | US 单元分隔符 |
| LF 换行      | NAK 否定      | DEL 删除      |

ASCII码大致有以下两个部分组成：

- ASCII非打印控制字符：ASCII表上数字0-31分配了控制字符，用于控制像打印机等一些外围设备
- ASCII打印字符：数字32-126分配给了能做键盘上找到的字符，当查看或打印文档是就会出现

### 2.5 转义字符

作用：用于表示一些不能显示的ASCII字符

现阶段我们常用的转义字符有：\n   \\ \   \t

| 转义字符 | 意义                                | ASCII码值（十进制） |
| -------- | ----------------------------------- | ------------------- |
| \a       | 响铃(BEL)                           | 007                 |
| \b       | 退格(BS) ，将当前位置移到前一列     | 008                 |
| \f       | 换页(FF)，将当前位置移到下页开头    | 012                 |
| \n       | 换行(LF) ，将当前位置移到下一行开头 | 010                 |
| \r       | 回车(CR) ，将当前位置移到本行开头   | 013                 |
| \t       | 水平制表(HT) （跳到下一个TAB位置）  | 009                 |
| \v       | 垂直制表(VT)                        | 011                 |
| \\       | 代表一个反斜线字符''\'              | 092                 |
| \'       | 代表一个单引号（撇号）字符          | 039                 |
| \"       | 代表一个双引号字符                  | 034                 |
| \?       | 代表一个问号                        | 063                 |
| \0       | 空字符(NUL)                         | 000                 |
| \ddd     | 1到3位八进制数所代表的任意字符      | 三位八进制          |
| \xhh     | 十六进制所代表的任意字符            | 十六进制            |

注意：

- 区分，斜杠："/" 与 反斜杠："\" ,此处不可互换
- \xhh 十六进制转义不限制字符个数 '\x000000000000F' == '\xF'

### 2.6 字符串型

作用：用于表示一串字符

两种风格：

- **c风格的字符串 ：**char 变量名[]="字符串值"

```c++
#include <iostream>
using namespace std;

int main(){
    //c风格字符串型
    char str1[]="abcd";
    cout<<str1<<endl;
    system("pause");
    return 0;
}

```

- **c++风格字符串：**string 变量名=“字符串值”

```c++
#include <iostream>
#include "string"
using namespace std;

int main(){
    //c风格字符串型
    string str1="abcdkd";
    cout<<str1<<endl;
    system("pause");
    return 0;
}


```

### 2.7 布尔类型 bool

作用：布尔数据类型代表真或假的值

bool类型只要两个值：

- true ···真（本质是1）
- false ···假（本质是0）

bool类型占用1个字节大小

```c++
#include <iostream>
using namespace std;

int main(){
   bool flag=true;//本质是1
   cout <<flag<<endl;
   flag=false;//本质是0
   cout<<flag<<endl;

   cout<<"size of bool="<< sizeof(bool)<<endl;
    system("pause");
    return 0;
}
```

### 2.8 数据输入

作用：用于从键盘获取数据

关键字：cin

语法：**cin>>变量；**

```c++
#include <iostream>
using namespace std;

#include "string"

int main(){
    //1.整型
    int a=0;
    cout<<"请输入整型变量a赋值："<<endl;
    cin>>a;
    cout<<"整型变量a="<<a<<endl;
    //2.浮点型
    float f=3.14f;
    cout<<"请给浮点型变量f赋值:"<<endl;
    cin>>f;
    cout<<"整型变量f="<<f<<endl;
    //3.字符型
    char ch='a';
    cout<<"请给浮点型变量ch赋值:"<<endl;
    cin>>ch;
    cout<<"整型变量ch="<<ch<<endl;
    //4.字符串型
   string str="";
   cout<<"请输入str："<<endl;
   cin>>str;
   cout<<"str的值为："<<str<<endl;
    //5.布尔类型
    bool flag=false;
    cout<<"请给flag赋值"<<endl;
    cin>>flag;
    cout<<"flag的值为："<<flag<<endl;
    system("pause");
    return 0;
}
```

## 3 运算符

作用：用于执行代码的运算

| **运算符类型** | 作用                                 |
| -------------- | ------------------------------------ |
| 算术运算符     | 用于处理四则运算                     |
| 赋值运算符     | 用于将表达式的值赋给变量             |
| 比较运算符     | 用于表达式比较，并返回一个真值或假值 |
| 逻辑运算符     | 用于根据表达是的值返回真值或假值     |

### 3.1 算术运算符

作用：用于处理四则运算

算术运算符包括以下符号：

| 运算符 | 术语         | 示例          | 结果    |
| ------ | ------------ | ------------- | ------- |
| +      | 正号         | +3            | 3       |
| =      | 负号         | -3            | -3      |
| +      | 加           | 10+5          | 15      |
| -      | 减           | 10-5          | 5       |
| *      | 乘           | 10*5          | 50      |
| /      | 除           | 10/5          | 2       |
| %      | 取模（取余） | 10%3          | 1       |
| ++     | 前置递增     | a=2；b=++a    | a=3;b=3 |
| ++     | 后置递增     | a=2；b=a++    | a=3;b=2 |
| --     | 前置递减     | a=2；b=--a    | a=1;b=1 |
| --     | 后置递减     | a=2;   b=a--; | a=1;b=2 |

> - 两个整数相除结果依然是整数
> - 除数不可以为0
> - 两个小数也可以相除
> - 两个小数是不可以做取模运算的
> - 只有整型变量才能进行运算

前置和后置的区别：

> 前置递增：先让变量+1 然后进行表达式运算

> 后置递增：先进行表达式运算 后然变量+1

示例：

```c++
#include <iostream>
using namespace std;

#include "string"

int main(){
    //前置递增
    int a2=10;
    int b2=++a2*10;
    cout<<"a2="<<a2<<endl; //a2=11
    cout<<"b2="<<b2<<endl; //b2=110

    //后置递增
    int a3=10;
    int b3=a3++ * 10;
    cout<<"a3="<<a3<<endl; //a3=11
    cout<<"b3="<<b3<<endl; //b3=100
    system("pause");
    return 0;
}
```

### 3.2 赋值运算符

作用：用于将表达式的值赋给变量

| 运算符 | 术语   | 示例      | 结果    |
| ------ | ------ | --------- | ------- |
| =      | 赋值   | a=2;b=3   | a=2;b=3 |
| +=     | 加等于 | a=0;a+=2; | a=2     |
| -=     | 减等于 | a=5;a-=3  | a=2     |
| *=     | 乘等于 | a=2;a*=2  | a=4     |
| /=     | 除等于 | a=4;a/=2  | a=2     |
| %=     | 模等于 | a=3;a%2;  | a=1;    |

示例：

``` c++
#include <iostream>
using namespace std;

int main(){
    // =
    int a=10;
    a=100;
    cout<<"a="<<a<<endl;

    //+=
    a=10;
    a+=2;
    cout<<"a="<<a<<endl; //a=a+2

    //-=
    a=10;
    a-=2;
    cout<<"a="<<a<<endl; //a=a-2

    //*=
    a=10;
    a*=2;
    cout<<"a="<<a<<endl; //a=a*2

    // /=
    a=10;
    a/=2;
    cout<<"a="<<a<<endl; //a=a/2

    // %=
    a=10;
    a%=2;
    cout<<"a="<<a<<endl; //a=a%2
    system("pause");
    return 0;
}
```

### 3.3 比较运算符

作用：用于表达式的比较，并返回一个真值或假值

比较运算符有以下符号

| 运算符 |   术语   | 示例 | 结果 |
| :----: | :------: | :--: | :--: |
|   ==   |  想等于  | 4==3 |  0   |
|   !=   |  不等于  | 4!=3 |  1   |
|   <    |   小于   | 4<3  |  0   |
|   >    |   大于   | 4>3  |  1   |
|   <=   | 小于等于 | 4<=3 |  0   |
|   >=   | 大于等于 | 4>=1 |  1   |

### 3.4 逻辑运算符

作用：用于根据表达式的值返回真值后假值

逻辑运算符有以下符号：

| 运算符 | 术语 | 示例   | 结果                                                   |
| ------ | ---- | ------ | ------------------------------------------------------ |
| ！     | 非   | !a     | 如果a为加，则!a为真；如果a为真，则!a为假               |
| &&     | 与   | a&&b   | 如果a和b都为真，则结果为真，否则为假                   |
| \|\|   | 或   | a\|\|b | 如果a和b有一个为真，则结果为真，二者都为假时，结果为假 |

> 在c++中 除了0 都为真
>
> ”与“条件中同真为真，其余都为假

## 4 程序流程结构

c/c++支持最基本的三种程序运行结构：顺序结构，选择结构，循环结构

- 顺序结构:程序按顺序执行，不发生跳转
- 选择结构：依据条件是否满足，有选择的执行相应功能
- 循环结构：依据条件是否满足，循环多次执行某段代码

### 4.1 选择结构

#### 4.1.1 if语句

作用：执行满足条件的语句

if语句的三种形式

- 单行格式if语句  if(条件){执行}
- 多行格式if语句  if(条件){执行}else{执行}
- 多条件的if语句  if(条件){执行}else if(条件){执行}...else{执行}

```c++
#include <iostream>
using namespace std;

int main(){
    //单行if语句
    int score=0;
    cout<<"请输入学生成绩："<<endl;
    cin>>score;
    if(score>550){
        cout<<"恭喜你考上了一本大学"<<endl;
    }else{
        cout<<"未考上一本大学"<<endl;
    }
    system("pause");
    return 0;
}

```

案例 1：三只小猪称体重

```c++
#include <iostream>
using namespace std;

int main(){
       //三只小猪称体重
       //创建三只小猪的变量
       int num1=0;
       int num2=0;
       int num3=0;
       //让用户输入
       cout<<"请输入第一只小猪的重量："<<endl;
       cin>>num1;

       cout<<"请输入第二只小猪的重量："<<endl;
       cin>>num2;

       cout<<"请输入第三只小猪的重量："<<endl;
       cin>>num3;
       cout<<"第一只小猪的体重为："<<num1<<endl;
       cout<<"第二只小猪的体重为："<<num2<<endl;
       cout<<"第三只小猪的体重为："<<num3<<endl;
       if(num1>num2) //小猪1大于小猪2
       {
           if(num1>num3) //小猪1大于小猪3
           {
               cout<<"小猪1最重"<<endl;
           }
           else
           {
               cout<<"小猪3最重"<<endl;
           }
       }
       else //小猪2大于小猪1
       {
           if(num2>num3) //小猪2大于小猪3
           {
               cout<<"小猪2最重"<<endl;
           }
           else
           {
               cout<<"小猪3最重"<<endl;
           }
       }
       system("pause");
       return 0;
}

```

#### 4.1.2 三目运算符

作用：通过三目运算符实现简单的判断

语法：表达式1 ？表达式2  ：表达式3

解释：

> 如果表达式1的值为真，执行表达式2，并返回表达式2的结果
>
> 如果表达式1的值为假，执行表达是3，并返回表达式3的结果

示例：

```c++
#include <iostream>
using namespace std;

int main(){
    int a=10;
    int b=20;
    int c=0;

    c=a>b ? a : b;
    cout<<"c="<<c<<endl; //20

      //c++中三目运算符返回的是变量，可以继续赋值
    (a>b?a:b)=100;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    
    system("pause");
    return 0;
}
```

#### 4.1.3 switch语句

作用：执行多条件分支语句

语法：

```c++
switch(表达式)
{
	case 结果1：执行语句;break;
	case 结果2：执行语句;break;
	...
	default:执行语句;break;
}
```

示例：

```c++
using namespace std;

int main(){
    //给电影评分
    //switch语句
    //10`9  经典
    //8`7   非常好
    //6`5   一般
    //5以下 烂片
    //提示用户给电影评分
    cout<<"请给电影打分:"<<endl;
    int score=0;
    cin>> score;
    cout<<"你打的分数为："<<score<<endl;
    switch (score)
    {
        case 10:
            cout<<"经典"<<endl;
            break;
        case 9:
            cout<<"经典"<<endl;
            break;
        case 8:
            cout<<"非常好"<<endl;
            break;
        case 7:
            cout<<"非常好"<<endl;
            break;
        case 6:
            cout<<"一般"<<endl;
            break;
        case 5:
            cout<<"一般"<<endl;
            break;
        default:
            cout<<"烂片"<<endl;
            break;
    }
    system("pause");
    return 0;
}
```

### 4.2 循环语句

#### 4.2.1 while循环语句

作用：满足循环条件，执行循环语句

语法：while(循环条件){循环语句}

解释：只要循环条件的结果为真，就执行循环语句

案例 2：猜数字

```c++
#include <iostream>
using namespace std;
//包含时间time的头文件
#include <ctime>
int main(){
    //添加随机数种子，作用利用当前系统时间生成随机数，防止每次随机数都一样
    srand((unsigned int)time(NULL));
    //系统生成随机数
    int num=rand()%100+1;  //rand（）%100 +1生成 0+1·99+1随机数
    //玩家进行猜测
    int val=0;
    while(true){
        cin >>val;
        //判断玩家猜测
        if(val>num)
        {
            cout<<"猜测过大"<<endl;
        }
        else if(val<num)
        {
            cout<<"猜测过小"<<endl;
        }
        else
        {
            cout<<"恭喜你猜对了"<<endl;
            //猜对  退出游戏，猜错 提示猜的结果，过大或者过小，重新返回第二部
            system("pause");
            return 0;
        }
    }
}
```

#### 4.2.2 do...while循环语句

作用：满足循环条件，执行循环语句

语法：do{循环语句}while(循环条件);

注意：与while的区别在与do...while会执行一次循环语句，再判断循环条件

示例：

```c++
#include <iostream>
using namespace std;

int main(){
    int num=0;
    do{
        cout<<num<<endl;
        num++;
    }while (num<10);
    system("pause");
    return 0;
}	
```

案例 3 ：水仙花数(指一个3位数中它的每一位上的3次方等于它得本身)

```c++
#include <iostream>
using namespace std;

int main(){
    int num=100;
    do{
        int a=0;
        int b=0;
        int c=0;
        a=num%10; //获取个位
        b=num/10%10;//获取十位
        c=num/100;//获取百位
        if(a*a*a+b*b*b+c*c*c==num){
            cout<<num<<endl;
        }
        num++;
    }while(num<1000);
    return 0;
}
```

#### 4.2.3 for循环语句

作用：满足循环条件，执行循环语句

语法：for(起始表达式；条件表达式；末尾循环体){循环语句；}

示例：

```c++
#include <iostream>
using namespace std;

int main(){
    for(int i=0;i<10;i++)
    {
        cout<<i<<endl;
    }
    system("pause");
    return 0;
}
```

案例 4：敲桌子（指缝7,7的倍数，个位有7，十位有7）

```c++
#include <iostream>
using namespace std;

int main(){
    for(int i=1;i<=100;i++){
        if(i%7==0||i%10==7||i/10==7){
            cout<<"敲桌子"<<endl;
        }else{
            cout<<i<<endl;
        }
    }
    return 0;
}

```

#### 4.2.4 嵌套循环

作用：在循环体中在嵌套一层循环，解决一些实际问题

例如：九九乘法表

```c++
#include <iostream>
using namespace std;

int main(){

    for(int i=1;i<=9;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<"x"<<i<<"="<<i*j<<"  ";
        }
        cout<<endl;
    }

    return 0;
}
```

### 4.3 跳转语句

#### 4.3.1 break语句

作用：用于跳出选择结构或者循环结构

break使用时机：

- 出现在switch条件语句中，作用是终止case并跳出switch
- 出现在循环语句中，作用是跳出当前的循环语句
- 出现在嵌套循环中，跳出最近的内层循环语句

#### 4.3.2 continue语句

作用：在循环语句中，跳过本次循环中剩余尚未执行的语句，继续执行下一次循环

```c++
int main(){
	for(int i=0;i<100;i++){
		if(i%2==0){
			continue;
		}
		cout<<i<<endl;
	}
	system("pause");
	return 0;
}
```

#### 4.3.3 goto语句

作用：可以无条件跳转语句

语法：goto 标记；

解释：如果标记的名称存在，执行goto语句，会跳转到标记的位置

示例：

```c++
int main(){
	cout<<"1"<<endl;
	goto FLAG;
	
	cout<<"2"<<endl;
	cout<<"3"<<endl;
	cout<<"4"<<endl;
	FLAG:
	cout<<"5"<<endl;
	
	system("pause");
    return 0;
}
```

## 5 数组

意义：所谓数组，就是一个集合，里面存放了相同类型的数据元素

特点1：数组中的每个数据元素都是相同的数据类型

特点2：数组是有连续的内存位置组成的

### 5.1 一维数组

#### 5.1.1 一维数组定义方式

1.数据类型  数组名[数组长度];

2.数据类型  数组名[数组长度]={值1，值2, ...};

3.数据类型  数组名[ ]={值1，值2 ...};

```c++
#include <iostream>
using namespace std;

int main(){
    int arr[9]={10,20,30,40,50,60,70,80,90};
    for(int i=0;i<9;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
```

#### 5.1.2 一维数组数组名

一维数组名称的用途：

1.可以统计整个数组在内存中的长度

2.可以获取数组在内存中的首地址

```c++
#include <iostream>
using namespace std;

int main(){
    //数组名用途
    //1.可以通过数组名统计整个数组占用内存大小
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<"整个数组占用内存空间为："<< sizeof(arr)<<endl;
    cout<<"每个元素占用内存空间为："<< sizeof(arr[0])<<endl;
    cout<<"数组中元素个数："<< sizeof(arr)/ sizeof(arr[0])<<endl;

    //2.可以通过数组名查看数组的首地址
    cout<<"数组首地址为："<<arr<<endl;
    cout<<"数组中第一个元素地址为："<<& arr[0]<<endl;
    cout<<"数组中第二个元素地址为："<<& arr[1]<<endl;
    //数组名是常量，不可以进行复制操作
    system("pause");
    return 0;
}
```

案例 5：数组五只小猪称体重:

```c++
#include <iostream>
using namespace std;

int main(){
    //创建5只小猪体重数组
    int arr[5]={300,350,200,400,250};
    //从数组中找到最大值
    int max=0;
    for(int i=0;i<5;i++){
        //如果访问数组中的元素比我认定的最大值还要打，更新最大值
        if(arr[i]>max){
            max=arr[i];
        }
    }
    //打印出最大值
    cout<<"最重的小猪体重为："<<max<<endl;
    system("pause");
    return 0;
}
```

案例 6：数组元素逆置

```c++
#include <iostream>
using namespace std;

int main(){
    int arr[5]={1,3,5,2,4};
    //起始元素下标
    int start=0;
    //末尾元素下标
    int end= sizeof(arr)/ sizeof(arr[0])-1;
    cout<<"数组逆置前："<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    while(start<end){
        //实现逆置
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;

        //下标更新
        start++;
        end--;
    }
    //打印逆置后的数组
    cout<<"数组你只后"<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    system("pause");
    return 0;
}
```

#### 5.1.3 冒泡排序

作用：最常用的排序算法，对数组内元素进行排序

1.比较相邻的元素。如果第一个比第二个大，就交换他们两个

2.对每一对相邻的元素做同样的工作，执行完毕后，找到第一个最大值。

3.重复以上步骤，每次比较次数-1，知道不需要比较

示例：

```c++
#include <iostream>
using namespace std;

int main(){
    //创建需要排序的数组
    int arr[9]={4,2,8,0,5,7,1,3,9};
    //排序前
    cout<<"排序前"<<endl;
    for (int k = 0; k <9 ; ++k) {
        cout<<arr[k]<<endl;
    }
    cout<<endl;
    //升序排序
    //总共排序轮数为 元素个数 -1
    for (int i = 0; i <9-1 ; ++i) {
        //内层循环对比 次数=元素个数-当前轮数（i）-1
        for (int j = 0; j <9-1-i; ++j) {
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    //排序后
    cout<<"排序后"<<endl;
    for (int k = 0; k <9 ; ++k) {
        cout<<arr[k]<<endl;
    }
    system("pause");
    return 0;
}
```

### 5.2 二维数组

二维数组就是在一维数组上，多加一个维度

#### 5.2.1 二维数组定义方式

二维数组定义的四种方式

1.数据类型  数组名[行数] [列数]；

2.数据类型  数组名[行数] [列数]={{数据1，数据2}，{数据3，数据4}};

3.数据类型  数组名[行数] [列数]={数据1，数据2，数据3，数据4};

4.数据类型  数组名[ ] [列数]={数据1，数据2，数据3，数据4};

> 建议：以上4中定义方式，利用第二种更加直观，提高代码的可读性

```c++
#include <iostream>
using namespace std;

int main(){
    //方式1
    //数据类型 数组名[行][列]={数据1，数据2}
    int arr[2][3]={1,2,3,4,5,6};
    for (int i = 0; i <2; ++i) {
        for (int j = 0; j <3 ; ++j) {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}
```

#### 5.2.2 二维数组数组名

-  查看二维数组所占内存空间
- 获取二维数组首地址

示例：

```c++
#include <iostream>
using namespace std;

int main(){
    //二维数组数组名
    int arr[2][3]={{1,2,3},{4,5,6}};
    //可以查看二维数组占用内存空间大小
    cout<<"二维数组占用内存空间为："<< sizeof(arr)<<endl;
    cout<<"二维数组第一行占用内存为："<< sizeof(arr[0])<<endl;
    cout<<"二维数组第一个元素占用内存为："<<sizeof(arr[0][0])<<endl;
    cout<<"二维数组的行数为："<< sizeof(arr)/ sizeof(arr[0])<<endl;
    cout<<"二维数组列数为："<< sizeof(arr[0])/ sizeof(arr[0][0])<<endl;
    //可以查看二维数组首地址
    cout<<"二维数组首地址："<<arr<<endl;
    cout<<"二维数组第一行首地址为："<<arr[0]<<endl;
    cout<<"二维数组第二行首地址为："<<arr[1]<<endl;
    cout<<"二维数组第一个元素首地址："<<& arr[0][0]<<endl;
    cout<<"二维数组第二个元素首地址："<<& arr[0][1]<<endl;
    system("pause");
    return 0;
}
```

案例7 二维数组应用案例（考试成绩统计）

```c++
#include <iostream>
using namespace std;

#include "string"
int main(){
    //创建二维数组
    int scores[3][3]={{100,100,100},{90,50,100},{60,70,80}};

    string names[3]={"张三","李四","王五"};
    //统计每个人的总和分数
    for (int i = 0; i < 3; ++i) {
        int sum=0; //统计分数总和变量
        for (int j = 0; j <3; ++j) {
            sum+=scores[i][j];
            cout<<scores[i][j]<<"  ";
        }
        cout<<names[i]<<"的总分为："<<sum<<endl;
    }
    system("pause");
    return 0;
}
```

## 6 函数

### 6.1 概述

作用：将一段经常使用的代码封装起来，减少重复代码

一个较大的程序，一般分为若干个程序块，每个模块实现特定的功能

### 6.2 函数的定义

函数的定义一般主要有5个步骤

1.返回值类型

2.函数名

3.参数表列

4.函数体语句

5.return表达式

语法：

> 返回值类型  函数名(参数列表)
>
> {
>
> ​		函数体语句
>
> ​		return表达式
>
> }

```c++
#include <iostream>
using namespace std;
//函数的定义
//语法：
//返回值类型  函数名（参数列表）{函数体语句 return表达式}
//加法函数，实现两个整型相加，并且将相加的结果进行返回
//此中num1，num2，没有真实的数据，只是一个形式参数，简称形参
int add(int num1,int num2)
{
    int sum=num1+num2;
    return sum;
}
int main(){
    //函数的调用
    int a=10;
    int b=20;
    int sum=add(a,b);//当中的a，b是当函数调用是即为实参
    cout<<"sum的值为："<<sum<<endl;
    system("pause");
    return 0;
}

```

### 6.3 值传递

- 所谓值传递，就是函数调用是实参将数组传入给形参
- 值传递是，如果形参发生改变，并不会影响实参

```c++
#include <iostream>
using namespace std;
//交换数值
void swap(int num1,int num2){
    cout<<"交换前"<<endl;
    cout<<"num1="<<num1<<endl;
    cout<<"num2="<<num2<<endl;

    //交换
    int temp=num1;
    num1=num2;
    num2=temp;

    cout<<"交换后"<<endl;
    cout<<"num1="<<num1<<endl;
    cout<<"num2="<<num2<<endl;

}
int main(){
    int a=30;
    int b=40;
    swap(a,b);
    system("pause");
    return 0;
}
```

### 6.4 函数的常见样式

常见的函数样式有4中

1.无参无返

2.有参无返

3.无参有返

4.有参有返

### 6.5 函数的声明

作用：告诉编译器函数名称及如果调用函数。函数的实际主体可以单独定义。

- 函数的声明可以多次，但是函数定义只能有一次

示例：

```c++
#include <iostream>
using namespace std;
//声明是提前告诉编译器函数存在，可以利用函数的声明
//声明
int max(int a,int b);
int max(int a,int b);

//定义
int max(int a,int b)
{
    return a>b?a:b;
}
int main(){
    int a=10;
    int b=20;
    cout<<max(a,b)<<endl;
    system("pause");
    return 0;
}
```

### 6.6 函数的分文件编写

作用：让代码结果更加清晰

函数分文件编写一般有4个步骤

>1.创建后缀名为.h的头文件
>
>2.创建后缀名为.cpp的源文件
>
>3.在头文件中写函数的声明
>
>4.在源文件中写函数的定义

示例：

```c++
//.h文件
#include <iostream>
using namespace std;

//实现两个数字交换的函数声明
void swap(int a,int b);
```

```c++
//.cpp文件
#include "zhengxing.h"
//函数的定义
void swap(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;

    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
}
```

```c++
//测试结果.cpp文件
#include <iostream>
using namespace std;
//包含头文件
#include "zhengxing.h"
int main() {
    int a=10;
    int b=20;
    swap(a,b);
    //任意键退出
    system("pause");
    return 0;
}
```

## 7 指针

### 7.1 指针的基本概念

**指针的作用：**可以通过指针间接访问内存

- 内存编号是从0开始记录的，一般用十六进制数字表示
- 可以利用指针变量保存地址

### 7.2指针变量的定义和使用

指针变量的定义语法： 数据类型 * 变量名;

可以通过指针来保存一个地址

```c++
#include <iostream>
using namespace std;

int main() {
    //定义一个指针
    int a=10;
    //指针定义的语法：数据类型 * 指针变量名;
    int * p;
    //让指针记录变量a的地址
    p=&a;
    cout<<"a的地址为："<<&a<<endl;
    cout<<"指针p为："<<p<<endl;

    //使用指针
    //可以通过解引用的方式来找到指针指向的内存
    //指针前加 * 代表解引用，找到指针指向内存中的数据
    *p =1000;
    cout<<"a="<<a<<endl;
    cout<<"*p="<<*p<<endl;
    system("pause");
    return 0;
}
```

### 7.3 指针所占内存空间

指针也是有数据类型

示例：

```c++
#include <iostream>
using namespace std;

int main() {
    int a=10;
    int * p =&a;//指针指向数据a的地址
    cout<<*p<<endl;//解引用
    //在32位操作系统中指针占4个字节空间大小，不管什么类型
    //在64位操作系统中指针占8个字节空间大小
    cout<<"sizeof(p)="<< sizeof(p)<<endl;
    cout<<"sizeof(int *)="<< sizeof(int *)<<endl;
    cout<<"sizeof(char *)="<< sizeof(char *)<<endl;
    cout<<"sizeof(float *)="<< sizeof(float *)<<endl;
    cout<<"sizeof(double *)="<< sizeof(double *)<<endl;
    system("pause");
    return 0;
}
```

### 7.4 空指针和野指针

空指针：指针变量指向内存中编号为0的空间

用途：初始化指针变量

注意：空指针指向的内存是不可以访问的

示例 1：空指针

```c++
#include <iostream>
using namespace std;

int main() {
    //指针变量p指向内存地址编号为0的空间
    //空指针的用途可以给指针变量进行初始化

    int * p=NULL;
    //空指针是不可以进行访问的
    //0`255之间的内存编号是系统占用的，因此不可以访问
//    *p=100;
    system("pause");
    return 0;
}
```

野指针：指针变量指向非法的内存空间

示例 2：野指针

```c++
#include <iostream>
using namespace std;

int main() {
    //指针变量p指向内存地址编号为0x1100的空间
    int * p=(int *)0x1100;
    //访问野指针报错
    cout<<*p<<endl;
    system("pause");
    return 0;
}
```

### 7.5 const修饰指针

const修饰指针有三种情况：

1.const修饰指针  ---常量指针

2.const修饰常量  ---指针常量

3.const即修饰指针，又修饰常量

> const int * const p=&a;
>
> 特点：指针的指向和指针指向的值都不可以更改
>
> 指针指向的值不可以改，指针指向可以改

```c++
#include <iostream>
using namespace std;

int main() {
    //const修饰指针  常量指针
    int a=10;
    int b=10;
    const int * p=&a;
    //指针指向的值不可以改，指针的指向可以改
    p=&b;

    //const修饰常量  指针常量
    //指针的指向不可以改，指针指向的值可以改
    int * const p2=&a;
    *p2=20;

    //const修饰指针和常量
    const int * const p3=&a;
    //指针的指向和指针指向的值都不可以更改
    system("pause");
    return 0;
}
```

### 7.6 指针和数组

作用：利用指针访问数组中元素

示例：

```c++
#include <iostream>
using namespace std;

int main() {
    //利用指针访问数组中的元素
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<"第一个元素为："<<arr[0]<<endl;

    int * p=arr;//arr就是数组的首地址
    cout<<"利用指针访问第一个元素："<<*p<<endl; //1

    p++;//让指针向后偏移4个字节
    cout<<"利用指针访问第二个元素："<<*p<<endl;//2

    cout<<"利用指针遍历数组"<<endl;
    int * p2=arr;
    for (int i = 0; i <10 ; ++i) {
        cout<<*p2<<endl;
        p2++;
    }
    system("pause");
    return 0;
}
```

### 7.7 指针和函数

作用：利用指针作函数参数，可以修改实参的值

示例：

```c++
#include <iostream>
using namespace std;
//值传递
void swap1(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
    cout<<"in swap1 a="<<a<<endl;
    cout<<"in swap1 b="<<b<<endl;
}
//地址传递
void swap2(int * p1,int * p2)
{
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}
int main() {
    int a=10;
    int b=20;
    //值传递
    //如果是值传递是不可以改变实参的
    swap1(a,b);
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    //地址传递
    //如果是地址传递可以改变实参
    swap2(&a,&b);
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    system("pause");
    return 0;
}
```

### 7.8 指针  数组  函数

案例 8：封装一个函数，利用冒泡排序，实现对整型数组的升序排序

```c++
#include <iostream>
using namespace std;
//冒泡排序函数
void arrSort(int * arr,int len)
{
    for (int i = 0; i <len-1 ; ++i) {
        for (int j = 0; j <len-i-1 ; ++j) {
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
//打印函数
void printArray(int *arr,int len)
{
    for (int i = 0; i <len ; ++i) {
        cout<<arr[i]<<" ";
    }
}
int main() {
    int arr[10]={4,3,6,9,1,2,10,8,7,5};
    //函数调用
    int len= sizeof(arr)/ sizeof(arr[0]);//函数的长度
    arrSort(arr,len);//arr就是数组的首地址
    //打印排序后的数组
   printArray(arr,len);
    system("pause");
    return 0;
}
```

## 8 结构体

### 8.1 结构体基本概念

结构体属于用户自定义的数据类型，允许用户存储不同的数据类型

### 8.2 结构体定义和使用

语法：struct 结构体名 {结构体成员列表};

通过结构体创建变量的方式有三种：

- struct 结构体名 变量名
- struct 结构体名 变量名={成员1值，成员2值...}
- 定义结构体时顺便创建变量

示例：

```c++
#include <iostream>
using namespace std;

#include "string"
//创建学生数据类型 ：学生包括（姓名，年龄，分数）
struct Student
{
    //成员列表
    //姓名
    string name;
    //年龄
    int age;
    //分数
    int score;
} s3;//在创建结构体时顺便创建结构体变量
//通过学生类型创建具体学生

int main() {
    //struct关键字可以省略
    Student s1;
    //给s1赋值
    s1.name="张三";
    s1.age=18;
    s1.score=100;
    cout<<"姓名:"<<s1.name<<" "<<"年龄:"<<s1.age<<"  "<<"成绩:"<<s1.score<<endl;

    struct Student s2={"李四",18,90};
    cout<<"姓名:"<<s2.name<<" "<<"年龄:"<<s2.age<<"  "<<"成绩:"<<s2.score<<endl;

    //通过结构体变量赋值
    s3.name="王五";
    s3.age=18;
    s3.age=18;
    s3.score=95;
    cout<<"姓名:"<<s3.name<<" "<<"年龄:"<<s3.age<<"  "<<"成绩:"<<s3.score<<endl;
    system("pause");
    return 0;
}
```

> 总结1：定义结构体时的关键字是struct ，不可以省略
>
> 总结2：创建结构体变量时，关键字struct可以省略
>
> 总结3：结构体变量利用操作符“.”访问成员

### 8.3 结构体数组

作用：将自定义的结构体放入到数组中方便维护

语法：struct  结构体名  数据名[元素个数]={{}，{}，...{}}

示例：

```c++
#include <iostream>
using namespace std;

#include "string"
//创建学生数据类型 ：学生包括（姓名，年龄，分数）
struct Student
{
    //成员列表
    //姓名
    string name;
    //年龄
    int age;
    //分数
    int score;
};
int main() {
   //结构体数组
    Student arr[3]={
          {"张三",18,80},
          {"李四",19,90},
          {"王五",20,85}
    };
    //给结构体数组中的元素赋值
    arr[2].name="赵六";
    arr[2].age=21;
    arr[2].score=100;
    //遍历结构体数组
    for (int i = 0; i <3; ++i) {
        cout<<"姓名:"<<arr[i].name<<" "<<"年龄:"<<arr[i].age<<"  "<<"成绩:"<<arr[i].score<<endl;
    }
    system("pause");
    return 0;
}
```

### 8.4 结构体指针

作用：通过指针访问结构体中的成员

- 利用操作符 -> 可以通过结构体指针访问结构体属性

示例：

```c++
#include <iostream>
using namespace std;

#include "string"
//结构体定义
struct Student
{
    //成员列表
    string name;//姓名
    int age;//年龄
    int score;//分数
};
int main() {
    //创建学生结构体变量
    Student stu={"张三",18,100};
    //通过指针指向结构体变量
    Student * p=&stu;
    //通过指针访问结构体变量中的数据
    cout<<"姓名:"<<p->name<<" "<<"年龄:"<<p->age<<"  "<<"成绩:"<<p->score<<endl;
    system("pause");
    return 0;
}
```

### 8.5 结构体嵌套结构体

作用：结构体中的成员可以是另一个结构体

列如：每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体

示例：

```c++
#include <iostream>
using namespace std;

#include "string"
//结构体中嵌套结构体

//学生的结构体
struct Student
{
    string name;
    int age;
    int score;
};

//老师的结构体
struct Teacher
{
    int id;
    string name;
    int age;
    struct Student stu; //辅导的学生
};

int main() {
    //创建老师
    Teacher t;
    t.id=1000;
    t.name="老王";
    t.age=40;
    t.stu.name="小王";
    t.stu.age=20;
    t.stu.score=100;
    cout<<"老师编号:"<<t.id<<" "<<"老师姓名:"<<t.name<<" "<<"老师年龄:"<<t.age<<" "
        <<"老师辅导学生姓名:"<<t.stu.name<<" "<<"学生年龄:"<<t.stu.age<<" "<<"学生考试分数:"
        <<t.stu.score<<" "<<endl;
    system("pause");
    return 0;
}
```

> 在结构体中可以定义另一个结构体作为成员，用来解决实际问题

### 8.6 结构体做函数参数

作用：将结构体作为参数向函数中传递

传递方式有两种：

- 值传递
- 地址传递

示例：

```c++
#include <iostream>
using namespace std;
#include "string"
//学生的结构体
struct Student
{
    string name;
    int age;
    int score;
};
//值传递
void printStudent(Student stu)
{
    stu.age=20;
    cout<<"姓名:"<<stu.name<<" "<<"年龄:"<<stu.age<<"  "<<"成绩:"<<stu.score<<endl;
};
//地址传递
void printStudents(Student * p)
{
    cout<<"姓名:"<<p->name<<" "<<"年龄:"<<p->age<<"  "<<"成绩:"<<p->score<<endl;
}
int main() {
//    Student stu;
//    stu.name="张三";
//    stu.age=18;
//    stu.score=60;
    Student stu={"李四",18,100};
    //值传递
    printStudent(stu);
    //地址传递
    printStudents(&stu);
    system("pause");
    return 0;
}
```

> 总结：如果不想修改主函数中的数据，用值传递，反之用地址传递

### 8.7 结构体中const使用场景

作用：用const来防止误操作

示例：

```c++
#include <iostream>
using namespace std;
#include "string"
//学生的结构体
struct Student
{
    string name;
    int age;
    int score;
};
//将函数中的形参改为指针，可以减少内存空间
void printStu(const Student * stu)
{
    //stu->are=18;//不可以更改,使用const可以防止我们的误操作
    cout<<"姓名:"<<stu->name<<" "<<"年龄:"<<stu->age<<"  "<<"成绩:"<<stu->score<<endl;
}
int main() {
    //创建结构体变量
    Student stu={"张三",15,70};
    printStu(&stu);
    system("pause");
    return 0;
}
```

### 8.8 结构体案例

#### 8.8.1 案例1

学校的毕设项目，每名老师带5个同学，总共3名老师

案例：

```c++
#include <iostream>
using namespace std;
#include "string"
#include <ctime>
//学生的结构体
struct Student
{
    //学生姓名
    string sName;
    //学生成绩
    int score;
};
//老师的结构体
struct Teacher
{
    //老师姓名
    string tName;
    //学生数组
    Student stu[5];
};
//给老师和学生赋值函数
void allocateSpace(Teacher tArr[],int len)
{
    string nameSeed="ABCDE";
    //给老是赋值
    for (int i = 0; i <len ; ++i) {
        tArr[i].tName="Teacher_";
        tArr[i].tName+=nameSeed[i];

        //通过循环给每名老师所带的学生赋值
        for (int j = 0; j <5 ; ++j) {
            tArr[i].stu[j].sName="Student_";
            tArr[i].stu[j].sName+=nameSeed[j];
            //随机数
            int random=rand()%61+40;//范围在40`99
            tArr[i].stu[j].score=random;
        }
    }
}
//打印函数
void printInfo(Teacher tArr[],int len)
{
    for (int i = 0; i <len ; ++i) {
        cout<<"老师姓名："<<tArr[i].tName<<endl;
        for (int j = 0; j < 5; ++j) {
            cout<<"  学生姓名： "<<tArr[i].stu[j].sName<<
            "  考试分数："<<tArr[i].stu[j].score<<endl;
        }
    }

}
int main() {
    //随机数种子
    srand((unsigned)time(NULL));
    //创建3名老师的数组
    Teacher tArr[3];
    //通过函数给3名老师的信息赋值，并给老师带的学生信息赋值
    int len= sizeof(tArr)/ sizeof(tArr[0]);
    allocateSpace(tArr,len);
    //打印所有老师及所带的学生
    printInfo(tArr,len);
    system("pause");
    return 0;
}
```

#### 8.8.2 案例2

设计一个英雄结构体，包括成员姓名，年龄，性别，创建结构体数组，数组中存放5名英雄，通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最重打印结果。

案例：

```c++
#include <iostream>
using namespace std;
#include "string"
//英雄的结构体
struct Hero
{
    string name;
    int age;
    string sex;
};
//排序函数
void bubblesort(Hero hArr[],int len)
{
    for (int i = 0; i <len-1 ; i++) {
        for (int j = 0; j <len-i-1 ; j++) {
            if(hArr[j].age>hArr[j+1].age){
                Hero temp=hArr[j];
                hArr[j]=hArr[j+1];
                hArr[j+1]=temp;
            }
        }
    }
}
//打印函数
void printHero(Hero hArr[],int len)
{
    for (int i = 0; i <len ; i++) {
        cout<<" 姓名："<<hArr[i].name<<" 年龄："<<hArr[i].age<<" 性别："<<hArr[i].sex<<endl;
    }
}
int main() {
   //设计英雄结构体

   //创建数组存放5名英雄
    Hero hArr[5]={
            {"刘备",23,"男"},
            {"关羽",22,"男"},
            {"张飞",20,"男"},
            {"赵云",21,"男"},
            {"貂蝉",19,"女"}
    };
    int len= sizeof(hArr)/ sizeof(hArr[0]);
    cout<<"排序前"<<endl;
    printHero(hArr,len);
    //对数组进行排序，按照年龄进行升序排序
    bubblesort(hArr,len);
   //将排序后结构打印出来
    cout<<"排序后"<<endl;
    printHero(hArr,len);
    system("pause");
    return 0;
}
```

# 二、c++核心编程

## 1 内存分区模型

c++程序在执行是，将内存大方向划分为4个区域

- 代码区：存放函数体的二进制代码，由操作系统进行管理的
- 全局区：存放全局变量和静态变量以及常量
- 栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
- 堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收

内存四区意义：

不同区域存放的数据，赋予不同的声明周期，给我们更大的灵活编程

### 1.1 程序运行前

在程序编译后，生成exe可执行程序，未执行该程序钱分为两个区域

**代码区：**

> 存放cpu执行的机器指令
>
> 代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
>
> 代码区是只读的，使其只读的原因是防止程序意外地修改了他的指令

**全局区：**

> 全局变量和静态变量存放在此
>
> 全局区还包含了常量区，字符串常量和其他常量也存放在此
>
> 该区域的数据在程序结束后由操作系统释放

```c++
#include <iostream>
using namespace std;
#include "string"
//全局变量
int g_a=10;
int g_b=10;
//全局常量
const int c_g_a=10;
const int c_g_b=10;
int main() {
    //全局区
    //全局变量，静态变量，常量
    //创建普通局部变量
    int a=10;
    int b=10;
    cout<<"局部变量a的地址为："<<&a<<endl;
    cout<<"局部变量b的地址为："<<&b<<endl;

    cout<<"全局变量g_a的地址为："<<&g_a<<endl;
    cout<<"全局变量g_b的地址为："<<&g_b<<endl;

    //静态变量  在普通变量前加上static，属于静态变量
    static int s_a=10;
    static int s_b=10;
    cout<<"静态变量s_a的地址为："<<&s_a<<endl;
    cout<<"静态变量s_b的地址为："<<&s_b<<endl;

    //常量
    //字符串常量
    cout<<"字符串常量地址为："<<&"hello world"<<endl;
    //const修饰的变量,const修饰的全局变量，const修饰的局部变量
    cout<<"const修饰的全局常量c_g_a的地址为："<<&c_g_a<<endl;
    cout<<"const修饰的全局常量c_g_b的地址为："<<&c_g_b<<endl;

    const int c_a=10;
    const int c_b=10;
    cout<<"const修饰的局部常量c_a的地址为："<<&c_a<<endl;
    cout<<"const修饰的局部常量c_b的地址为："<<&c_b<<endl;
    system("pause");
    return 0;
}
```

总结：

- c++在程序运行前分全局区和代码区
- 代码区特点是共享和只读
- 全局区中存放全局变量，静态变量，常量
- 常量区中存放const修饰的全局常量和字符串常量

### 1.2 程序运行后

栈区：

> 由编译器自动分配释放，存放函数的参数值，局部变量等
>
> 注意事项：不要反回局部变量的地址，栈区开辟的数据有编译器自动释放

堆区：

> 由程序员分配释放，若程序员不释放，程序结束时有操作系统回收
>
> 在c++中主要利用new在堆区开辟内存

### 1.3 new操作符

c++中利用new操作符在堆区开辟数据

堆区开辟的数据，有程序员手动开辟，手动释放，释放利用操作符delete

语法： new 数据类型

利用new创建的数据，会返回该数据对应的类型的指针

## 2 引用

### 2.1 引用的基本使用

作用：给变量起别名

语法：数据类型 &别名=原名

示例：

```c++
int main(){
    int a=10;
    int &b=a;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    b=100;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    
    system("pasue");
    return 0
}
```

### 2.2 引用注意事项

- 引用必须初始化
- 引用在初始化后，不可以改变

示例：

```c++
int main(){
	int a=10;
    int b=20;
    int &c;//这是错误的，引用必须初始化
    int &c=a;//一旦初始化后，就不可以更改
    c=b;//这是赋值操作，不是更改引用，是把b的值赋给了a
    cout<<"a="<<a<<endl; //20
    cout<<"b="<<b<<endl; //20
    cout<<"c="<<c<<endl; //20
    
    system("pause");
    return 0;
}
```

### 2.3 引用做函数参数

作用：函数传参时，可以利用引用的技术让形参修饰实参

优点：可以简化指针修改实参

示例：

```c++
#include <iostream>
using namespace std;
//值传递
void mySwap01(int a,int b){
    int temp=a;
    a=b;
    b=temp;
    cout<<"swap01 a="<<a<<endl;
    cout<<"swap01 b="<<b<<endl;
}
//地址传递
void mySwap02(int * a,int * b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
//引用传递
void mySwap03(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main() {
    int a=10;
    int b=20;
    mySwap01(a,b); //值传递，形参不会修饰实参
    cout<<"值传递a="<<a<<endl;
    cout<<"直传递b="<<b<<endl;

    mySwap02(&a,&b);//地址传递，形参会修饰实参
    cout<<"指针传递a="<<a<<endl;
    cout<<"指针传递b="<<b<<endl;

    mySwap03(a,b);//引用传递，形参会修饰实参
    cout<<"引用传递a="<<a<<endl;
    cout<<"引用传递b="<<b<<endl;
    system("pause");
    return 0;
}
```

> 总结：通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单

### 2.4 引用做函数返回值

作用：引用是可以作为函数的返回值存在的

注意：不要返回局部变量引用，或者局部变量指针，但可以返回局部变量的值

用法：函数调用作为左值

示例：

```c++
#include <iostream>
using namespace std;

int test0() {
	int a = 10;//局部变量
	return a;
}
int& test01() {
	int a = 10;//局部变量
	return a;
}
int& test02() {
	static int a = 20;//静态变量，其生命周期为整个程序周期，但作用域只在该函数中
	cout << "&a:" << &a << endl;
	return a;
}
int main() {
	//可以返回局部变量的值
	int ref0 = test0();
	cout << "ref0=" << ref0 << endl;//第一次可以返回，编译器做了保留
	cout << "ref0=" << ref0 << endl << endl;//第二次结果错误，因为a的内存已经释放了

	//不能返回局部变量引用，或指针
    //区别于int ref = test01();若这样则和上一个例子等效，两次打印ref相等，无报错
	int& ref = test01();
	cout << "ref=" << ref << endl;//第一次可以返回，编译器做了保留
	cout << "ref=" << ref << endl << endl;//第二次结果错误，因为a的内存已经释放了
    
    //可以返回局部静态变量的引用或指针，因为其并不在栈上
	int& ref2 = test02();
	cout << "&ref2:" << &ref2 << endl;
	cout << "ref2=" << ref2 << endl;
	cout << "ref2=" << ref2 << endl << endl;

	test02() = 1000;//如果函数的返回值是引用，这个函数调用可以作为左值
	cout << "ref2=" << ref2 << endl;
	cout << "ref2=" << ref2 << endl;

	system("pause");
}

```

### 2.5 引用的本质

本质：**引用的本质在c++内部实现是一个指针常量**

示例：

```c++
//发现是引用，转换为int* const ref=&a;
void func(int& ref){
    ref=100;//ref引用，转换为*ref=100
}
int main(){
    int a=10;
    //自动转换成int* const ref=&a;指针常量是指针指向不可以更改，也说明为什么引用不可更改
    int& ref=a;
    ref=20;//内部发现ref是引用，自动帮我们转换为*ref=20;
    cout<<"a="<<a<<endl;
    cout<<"ref="ref<<endl;
    func(a);
    return 0;
}
```

### 2.6 常量引用

作用：常量引用主要用来修饰形参，防止误操作

在函数形参列表中，可以加const修饰形参，**防止形参改变实参**

示例：

```c++
void showValue(const int& v){
    //v = 30;//会报错
	cout<<v<<endl;
}
int main(){
    //int& ref=10;引用本身需要一个合法的内存空间，因此这个运行错误
    //加入const就可以了，编译器优化代码，int temp=10;const int& ref=temp;
    const int& ref=10; //若不加const则并不能用常数赋值
    //ref=100;//加入const后不可以修改变量
    cout<<ref<<endl;

    //函数中利用常量引用防止误操作修改实参
    int a=10;
    showValue(a);
    
    system("pause");
    return 0;
}
```

## 3 函数提高

### 3.1 函数默认参数

在c++中，函数的形参列表中的形参是**可以有默认值**的。

语法：返回值类型 函数名 （参数=默认值）{}

```c++
#include <iostream>
using namespace std;
//函数的默认参数
int func(int a,int b,int c)
{
    return a+b+c;
}
//如果自己输入数据，就用自己的数据，如果没有，那么就用默认值

int func1(int a,int b=20,int c=30)
{
    return a+b+c;
}
//注意事项
//如果某个位置已近有了默认值，那么从这个位置往后，从左到右都必须有默认值，函数中的形参只能是定义的最后一个有默认值，否则报错
//如果函数声明有默认参数，函数实现就不能有默认参数
//声明和实现只能有一个默认的参数
int main() {
    cout<<func(10,20,30)<<endl;
    cout<<func1(10)<<endl;
    system("pause");
    return 0;
}
```

### 3.2 函数的占位参数

c++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置

语法：返回值类型 函数名（数据类型）{}

在现阶段函数的占位参数存在意义不大，但是后面的课程会用到该技术

示例：

```c++
#include <iostream>
using namespace std;

void func(int a,int)
{
    cout<<"this is func"<<endl;
}
int main() {
    func(10,10);//占位参数必须填补
    system("pause");
    return 0;
}
```

### 3.3 函数重载

#### 3.3.1 函数重载概述

作用：函数名可以相同，提高复用性

函数重载满足条件：

- 同一个作用域下
- 函数名称相同
- 函数参数**类型不同**或者**个数不同**或者**顺序不同**

**注意：函数的返回值不可以作为函数重载的条件**

#### 3.3.2 函数重载注意事项

- 引用作为重载条件
- 函数重载碰到函数默认参数

示例：

```c++
#include <iostream>
using namespace std;

//函数重载注意事项
//引用作为重载条件
void func(int &a)
{
	cout << "func (int &a)被调用" << endl;
}
void func(const int &a)
{
	cout << "func(const int &a)调用" << endl;
}

int main() {
	int a=10;
	func(a);
    
	func(10);
	system("pause");
	return 0;
}
```

函数重载碰到函数默认参数编译报错！

```c++
#include <stdio.h>

int func(int a)
{
	 return (a);}

int func(int a, int b = 0)
{
	 return (a + b);
}
int main(int argc, char* argv[])
{
    printf("func(3)  = %d\n", func(3));
    printf("func(3,2)= %d\n", func(3, 2));
    printf("test for temp.cpp\n");
    return 0;
}
```



## 4 类和对象

c++面向对象三大特性：封装，继承，多态

c++认为万事万物皆对象，对象上有属性和行为

### 4.1 封装

#### 4.1.1 封装的意义

封装是c++面向对象三大特性之一

封装的意义：

- 将属性和行为作为一个整体，表现生活中的事物
- 将属性和行为加以权限控制

在设计类的时候，属性和行为写在一起，表现事物

语法: class 类名{访问权限：属性/行为}

示例 1：

```c++
#include <iostream>
using namespace std;

const double PI=3.14;
//设计一个圆类，请圆的周长
class Circle
{
    //访问权限
    //公共权限
public:
    //属性
    int m_R;//半径
    //行为
    //获取圆的周长
    double calclezc(){
        return 2*PI*m_R;
    }
};
int main() {
    //通过圆类，创建具体的圆（对象）
    Circle c1;
    //给圆的（半径）对象赋值
    c1.m_R=3;
    cout<<c1.calclezc()<<endl;
    system("pause");
    return 0;
}
```

示例 2：

```c++
#include <iostream>
using namespace std;

#include "string"
//设计一个圆类，请圆的周长
class Student
{
    //公共权限
public:
    //属性
    string name;
    int id;
    //行为：显示姓名和学号
    void showStudent(){
        cout<<"  学生姓名："<<name<<"  学生学号："<<id<<endl;
    }
};
int main() {
    Student stu;
    stu.name="张三";
    stu.id=10001;
    stu.showStudent();
    system("pause");
    return 0;
}
```

类在设计是，可以把属性和行为放在不同的权限下，加以控制

访问权限有三种

| 语法      | 权限     | 作用                         |
| --------- | -------- | ---------------------------- |
| public    | 公共权限 | 类内可以访问，类外可以访问   |
| protected | 保护权限 | 类内可以访问，类外不可以访问 |
| private   | 私有权限 | 类内可以访问，类外不可以访问 |

```c++
#include <iostream>
using namespace std;

#include "string"
class Person
{
    //公共权限
public:
    string name;
    //保护权限
protected:
    string car;
private:
    int password;
public:
    void func(){
        name="张三";
        car="本田";
        password=123456;
    }
};
int main() {
    //实例化居停对象
    Person p1;
    p1.name="李四";
//    p1.car="奔驰";//保护权限对象外面不能访问
//    p1.password=4587547;//私有的外面不能访问
    p1.func();
    system("pause");
    return 0;
}
```

#### 4.1.2 struct和class区别

在c++中struct和class**唯一区别**就在于***默认的访问权限不同***

区别：

- struct 默认权限为 **public**
- class 默认权限为 **private**

#### 4.1.3 成员属性设置为私有

优点1：将所有成员属性设置为私有，可以自己控制读写权限

优点2：对于写权限，我们可以检测数据的有效性

示例：

```c++
#include <iostream>
using namespace std;

#include "string"
//成员属性设置为私有
class Person
{
public:
    //设置情人->写
    void setLover(string lovers)
    {
        m_Lover=lovers;
    }
     //设置姓名->写
    void setName(string name)
    {
        m_Name=name;
    }
    //获取名字->读
    string getName()
    {
        return m_Name;
    }
    //获取年龄->读
    int getAge(){
        m_Age=0;  //初始化为0
        m_Age++;
        return m_Age;
    }
private:
    //姓名  可读可写
   string m_Name;
    //年龄  只读
   int m_Age;
   //情人  只写
   string m_Lover;
};
int main() {
    Person p;
    p.setName("张三");
    p.setLover("李四");
    cout<<"姓名为： "<< p.getName()<<endl;
    cout<<"年龄为："<<p.getAge()<<endl;
    system("pause");
    return 0;
}
```

> 设置只读或者只写或者可读可写的模式就是在定义类时加上get和set方法就可以了。
>
> 同时也可以加上判断方法，列如在年龄中只写的话可以用if语句判断年龄是否大于0小于150，如果是者输出，如果不是则打印错误信息

##### 练习案例1：设置立方体类

设置立方体类Cube

求出立方体的面积和体积

分布用全局函数和成员函数判断两个立方体是否相等

```c++
#include <iostream>
using namespace std;

#include "string"
//设置立方体类
class Cube
{
public:
    //设置长
    void setML(int l)
    {
        m_L=l;
    }
    //获取长
    int getML(){
        return m_L;
    }
    //设置宽
    void setMW(int w)
    {
        m_W=w;
    }
    //获取宽
    int getMW(){
        return m_W;
    }
    //设置高
    void setMH(int h){
        m_H=h;
    }
    //获取高
    int getMH(){
        return m_H;
    }
    //获取立方体的体积
    int cubetj(){
        return m_H*m_W*m_L;
    }
    //获取立方体的面积
    int cubemj(){
        return 2*m_L*m_W+2*m_L*m_H+2*m_W*m_H;
    }
    //利用成员函数判断两个立方体是否相等
    bool isSameByClass(Cube &c){
        if(m_L==c.getML()&&m_W==c.getMW()&&m_H==c.getMH()){
            return true;
        }
        return false;
    }
private:
    //长
    int m_L;
    //宽
    int m_W;
    //高
    int m_H;
};
//利用全局函数判断 两个立方体是否相等
bool isSame(Cube &c1,Cube &c2){
    if(c1.getML()==c2.getML()&&c1.getMW()==c2.getMW()&&c1.getMH()==c2.getMH()){
        return true;
    }
    return false;
}
int main() {
    //创建立方体对象
    Cube c1;
    c1.setML(10);
    c1.setMW(10);
    c1.setMH(20);
    cout<<"c1的面积为："<<c1.cubemj()<<endl;
    cout<<"c1的体积为："<<c1.cubetj()<<endl;

    //创建第二个立方体
    Cube c2;
    c2.setMW(10);
    c2.setML(15);
    c2.setMH(10);

    bool ret=isSame(c1,c2);
    if(ret)
    {
        cout<<"全局函数c1和c2相等"<<endl;
    }else{
        cout<<"全局函数c1和c2不相等"<<endl;
    }

    ret =c1.isSameByClass(c2);
    if(ret)
    {
        cout<<"成员函数c1和c2相等"<<endl;
    }else{
        cout<<"成员函数c1和c2不相等"<<endl;
    }
    system("pause");
    return 0;
}
```

##### 练习案例2：点和圆的关系

设计一个圆类，和一个点类，计算点和圆的关系

```c++
main.cpp打印页面
#include <iostream>
using namespace std;

#include "point.h" //导入点类的头文件
#include "circle.h" //导入圆类的头文件
//设置立方体类
//点和圆关系判断
//点到圆心的距离==半径  点在圆上
//点到圆心的距离>半径   点在圆外
//点到圆心的距离<半径     点在圆内

//判断点和圆的关系
void isInCircle(Circle &c,Point &p){
    //计算两点之间距离  平方
    int distance=
    (c.getCenter().getX()-p.getX())*(c.getCenter().getX()-p.getX())+
    (c.getCenter().getY()-p.getY())*(c.getCenter().getY()-p.getY());
    //计算半径的平方
    int rDistance =c.getR()*c.getR();
    //判断关系
    if(distance==rDistance)
    {
        cout<<"点在圆上"<<endl;
    }
    else if(distance>rDistance)
    {
        cout<<"点在圆外"<<endl;
    }
    else if(distance<rDistance)
    {
        cout<<"点在圆内"<<endl;
    }
}
int main() {
    //创建圆
    Circle c;
    c.setR(10);
    Point center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);
    //创建点
    Point p;
    p.setX(10);
    p.setY(10);
    //判断关系
    isInCircle(c,p);
    system("pause");
    return 0;
}
```

```c++
circle.cpp页面
#include "circle.h"
//圆类
//设置半径
void Circle::setR(int r){
    m_R=r;
}
//获取半径
int Circle::getR(){
    return m_R;
}
//设置圆心
void Circle::setCenter(Point center){
    m_Center=center;
}
//获取圆心
Point Circle::getCenter(){
    return m_Center;
}


circle.h页面
#pragma once

#include <iostream>
#include "point.h"
using namespace std;
//圆类
class Circle
{
public:
    //设置半径
    void setR(int r);
    //获取半径
    int getR();
    //设置圆心
    void setCenter(Point center);
    //获取圆心
    Point getCenter();
private:
    int m_R; //半径
    Point m_Center;//圆心
};
```

```c++
point.cpp页面
#include "point.h"
//设置x
void Point::setX(int x){
    m_X=x;
}
//获取x
int Point::getX(){
    return m_X;
}
//设置y
void Point::setY(int y){
    m_Y=y;
}
//获取y
int Point::getY(){
    return m_Y;
}

point.h页面
#pragma once

#include <iostream>
using namespace std;
//点类
class Point
{
public:
    //设置x
    void setX(int x);
    //获取x
    int getX();
    //设置y
    void setY(int y);
    //获取y
    int getY();
private:
    int m_X;
    int m_Y;
};
```

### 4.2 对象的初始化和清理

- 生活中我们买的电子产品都基本会有出厂设置，在某一天我们不用是后也会删除一些我们自己的信息数据保证安全
- c++中的面向对象来源于生活，每个对象也都会有初始设置以及对象销毁前的清理数据的设置

#### 4.2.1 构造函数和析构函数

对象的初始化和清理也是两个非常重要的安全问题

​        一般对象或者变量没有初始状态，对其使用后果是未知

​		同样的使用完一个对象或变量，没有及时清理，也会造成一定的安全问题

c++利用管理**构造函数**和**析构函数**解决上述问题，这两个函数将会被编译器自动调用，完成对象初始化和清理工作，

对象的初始化和清理工作是编译器强制要我们做的事情，因此如果我们不提供构造和析构，编译器会提供。编译器提供的构造函数和析构函数是空实现的。

- 构造函数：主要作用在与创建对象时为对象的成员属性赋值，构造函数有编译器自动调用，无须手动调用
- 析构函数：主要作用在于对象销毁前系统自动调用，执行一些清理工作

**构造函数语法：**类名(){}

1.构造函数，没有返回值也不写void

2.函数名称与类名相同

3.构造函数可以有参数，因此**可以发生重载**

4.程序在调用对象时候会自动调用构造，无须手动调用，而且只会调用一次

**析构函数语法：**~类名(){}

1.析构函数，没有返回值也不写void

2.函数名称与类名相同，在名称前加上符号~

3.析构行数不可以有参数，因此**不可以发生重载**

4.程序在对象销毁前会自动调用析构，无须手动调用，而且只会调用一次

```c++
//对象的初始化和清理
//1.构造函数  进行初始化操作
calss Person
{
public:
	//1.1 构造函数
	Person()
	{
		cout<<"Person构造函数的调用"<<endl;
	}
	//1.2 析构函数  进行清理的操作
	~Person()
	{
		cout<<"Person析构函数的调用"<<endl;
	}
}
//构造函数和析构函数都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
void test01()
{
    //在栈上的数据，test01执行完毕后，释放这个对象
	Person p;
}

int main(){
	test01();
    Person p;
	system("pause");
	return 0;//这里应该也会析构但因为已经执行完了我们也看不到
}
```

#### 4.2.2 构造函数的分类及调用

两种分类方式：

> 按参数分为：有参构造和无参构造
>
> 按类型分为：普通构造和拷贝构造

三种调用方式：

> 括号法
>
> 显示法
> 
> 隐式转换法

示例：

```c++
//构造函数的分类及调用
//分类
class Person {
public:
	//构造函数  无参
	Person() {
		cout << "无参Person的构造函数调用" << endl;
	}
	//构造函数  有参
	Person(int a) {
		age = a;
		cout << "有参Person的构造函数调用" << endl;
	}
	//拷贝构造函数
	Person(const Person &p) {
		//将转入的人身上的所有属性，拷贝到我身上
		age = p.age;
		cout << "拷贝Person的构造函数调用" << endl;
	}
	//析构函数
	~Person() {
		cout << "Person的析构函数调用" << endl;
	}
	int age;
};
//调用
void test01() {
	//括号法
	Person p1;//默认构造函数调用
	Person p2(10);//有参构造函数
	Person p3(p2);//拷贝构造函数

	//显示法
	Person p4;
	Person p5 = Person(10);//有参构造
	Person p6 = Person(p2);//拷贝构造
	Person(10);//匿名对象  特点：当前执行结束后，系统会立即回收掉匿名对象
			   //不要利用拷贝构造函数  初始化匿名对象

	//隐式转换法
	Person p7 = 10; //相当于写了 Person p4=Person(10)
	Person p8 = p7;//拷贝构造
}
int main() {
	test01();
	system("pause");
	return 0;
}
```

#### 4.2.3 拷贝构造函数调用时机

c++中拷贝构造调用时机通常有三种情况

- 使用一个已经创建完毕的对象来初始化一个新对象
- 值传递的方式给函数参数传值
- 以值方式返回局部对象

```c++
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

#include "string"
class Person {
public:
	Person() {
		cout << "无参构造函数" << endl;
		m_Age = 0;
	}
	Person(int age) {
		cout << "有参构造函数" << endl;
		m_Age = age;
	}
	Person(const Person &p)
	{
		cout << "拷贝构造函数" << endl;
		m_Age = p.m_Age;
	}
	~Person() {
		cout << "析构函数" << endl;
	}
	int m_Age;
};

//使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(20);//无参
	Person p2(p1);//有参
}//析构->析构

//值传递的方式给函数参数传值
void doWork(Person p) //若改为传引用，则内外打印&p一致
{
	cout << "in doWork():" << (int*)&p << endl;
}
void test02()
{
	Person p;
	cout << "before doWork():" << (int*)&p << endl;
	doWork(p);
}
//值方式返回局部对象
Person doWork2()
{
	const Person p1;
	cout << (int*)&p1 << endl;
	return p1; //若返回引用，外侧用引用接收(准确来说只能返回局部静态变量)，则内外&p一致，具体可参考2.4引用做函数...
}
void test03() {
	Person p = doWork2();//先局部变量拷贝到外层，再析构，因为返回局部变量所以内外打印&p不一样，不要返回局部变量的引用，更不要返回其指针
	cout << (int*)&p << endl;
}
int main() {
	test01();
	test02();
	cout << "before call test03():" << endl;
	test03();
	system("pause");
	return 0;
}

```

#### 4.2.4 构造函数调用规则

默认情况下，c++编译器至少给一个类添加3个函数

- 默认构造函数(无参，函数体为空)
- 默认析构函数(无参，函数体为空)
- 默认拷贝构造函数，对属性进行值拷贝

构造函数调用规则如下：

- 如果用户定义有参构造函数，c++不再提供默认无参构造，但是会提供默认拷贝构造
- 如果用户定义拷贝构造函数，c++不会再提供其他构造函数 

示例：

```c++
示例1: 用户提供拷贝构造，则编译器不再提供任何构造函数
class Person
{
public:

	//Person()
	//{
	//	cout << "Person 无参构造函数调用" << endl;
	//}
	//Person(int a)
	//{
	//	age = a;
	//	cout << "Person 有参构造函数调用" << endl;
	//}
	Person(const Person& p)
	{
		age = p.age;
		cout << "Person 拷贝构造函数调用" << endl;
	}
	~Person()
	{
		cout << "Person 析构函数调用" << endl;
	}

	int age;
};

// 构造函数的调用规则
// 1.如果用户定义有参构造函数，C++不再提供默认无参构造，但是会提供默认拷贝构造
// 2.如果用户定义拷贝构造函数，C++不会再提供其他构造函数
int main()
{
	Person p; // 因为编译器不再提供默认构造函数，所以这句和下句编译器会报错
	Person p1(20);	// 这句编译器会报错
	Person p2(p1);
	cout << "p2的年龄：" << p2.age << endl;
	system("pause");
}

示例2:用户提供有参构造，则编译器不再提供无参构造
class Person
{
public:

	//Person()
	//{
	//	cout << "Person 无参构造函数调用" << endl;
	//}
	Person(int a)
	{
		age = a;
		cout << "Person 有参构造函数调用" << endl;
	}
	//Person(const Person& p)
	//{
	//	age = p.age;
	//	cout << "Person 拷贝构造函数调用" << endl;
	//}
	~Person()
	{
		cout << "Person 析构函数调用" << endl;
	}

	int age;
};

// 构造函数的调用规则
// 1.如果用户定义有参构造函数，C++不再提供默认无参构造，但是会提供默认拷贝构造
// 2.如果用户定义拷贝构造函数，C++不会再提供其他构造函数
int main()
{
	Person p;		// 这句编译器会报错,用户提供了有参，系统就不会提供无参构造
	Person p1(20);	
	Person p2(p1);
	cout << "p2的年龄：" << p2.age << endl;
	system("pause");
}

```

**总结：**若用户定义了拷贝构造函数，则系统不再提供无参、有参构造；若用户定义了有参构造，则系统不再提供默认的无参构造，但会提供默认拷贝构造函数。

#### 4.2.5 深拷贝与浅拷贝

深拷贝是**面试经典问题**，也是常见的一个坑

浅拷贝：简单的赋值拷贝操作

深拷贝：在堆区重新申请空间，进行拷贝操作

```c++
//深拷贝与浅拷贝
class Person
{
public:
	Person(){
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age, int height)
	{
		m_Height = new int(height);
		m_Age = age;
		cout << "Person的有参构造函数调用" << endl;
	}
	//实现拷贝构造函数 解决浅拷贝带来的问题
	Person(const Person &p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
		//m_Height=p.m_Height;//编译器默认执行的拷贝构造函数里是执行这行代码，这样析构时程序会对同一块内存释放两次从而崩溃

		//深拷贝操作：先申请内存再拷贝值
		m_Height = new int(*p.m_Height);
	}
	~Person(){
		//析构函数将堆区开辟的数据做释放操作
		//浅拷贝带来的问题就是堆区的内存重复释放导致程序崩溃
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person的析构函数调用" << endl;
	}
	int m_Age;
	int *m_Height;
};
void test01(){
	Person p1(10, 170);
	cout << "p1的年龄为：" << p1.m_Age << "p1的身高为：" << *p1.m_Height << endl;

	Person p2(p1);
	//如果利用编译器提供的拷贝构造函数，会做浅拷贝操作(两个指针指向同一块内存)
	cout << "p2的年龄为：" << p2.m_Age << "p2的身高为：" << *p2.m_Height << endl;
}
int main() {
	test01();
	system("pause");

	return 0;
}
```

**总结：**如果属性有在**堆区**开辟的，一定要提供拷贝构造函数，防止浅拷贝带来的重复析构同一块内存导致程序崩溃。

#### 4.2.6 初始化列表

作用：c++提供了初始化列表语法，用来初始化属性

语法：构造函数():属性1(值1)，属性2(值2)...{}

示例：

```c++
#include <iostream>
using namespace std;

//初始化列表
class Person
{
public:
    //传统初始化操作
//    Person(int a,int b,int c){
//        m_A=a;
//        m_B=b;
//        m_C=c;
//    }
    //初始化列表初始化属性
    Person():m_A(10),m_B(20),m_C(30){};
    
    int m_A;
    int m_B;
    int m_C;
};
void test01(){
//    Person p(10,20,30);
    Person p;
    cout<<"m_A= "<<p.m_A<<endl;
    cout<<"m_B= "<<p.m_B<<endl;
    cout<<"m_C= "<<p.m_C<<endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 4.2.7 类对象作为类成员

c++类中的成员可以是另一个类的对象，我们称该成员为对象成员

列如：

```
class A{}
calss B
{
	A a;
}
```

B类中有A作为成员，A为对象成员

```c++
#include "string"
using namespace std;

class Phone
{
public:
	Phone(string Name)
	{
		cout << "Phone的构造函数调用" << endl;
		m_PhoneName = Name;
	}
	~Phone()
	{
		cout << "Phone的析构函数调用" << endl;
	}
	string m_PhoneName;
};
class Person
{
public:
 //Phone m_Phone=p.Name  隐式转换法
  //当其他类对象作为本类成员，构造是先构造类对象，再构造自身，析构的顺序与构造相反
	Person(string name, string phoneName) :p_Name(name), p_Phone(phoneName)
	{
		cout << "Person的构造函数调用" << endl;
	}
	~Person(){
		cout << "Person的析构函数调用" << endl;
	}
	string p_Name;
	Phone p_Phone;
};

void test01(){
	Person p("张三", "vivo xs");
	cout << p.p_Name << "拿着" << p.p_Phone.m_PhoneName << endl;
}
int main() 
{
	test01();
	system("pause");
	return 0;
}
```

#### 4.2.8  static静态成员

静态成员就是在成员变量和成员函数前加上关键static，称为静态成员

静态成员分为：

- 静态成员变量

  **所有对象共享类中成员静态成员数据(只存一份)**

  在编译阶段分配内存

  必须类内声明，类外初始化

  静态**成员属性**可不实例化就可以通过类名访问

  

- 静态成员函数

  静态成员函数**能且只能**访问静态成员变量

  静态**成员函数**可不实例化就可以通过类名访问
  
  

```c++
#include <iostream>
using namespace std;

#include "string"
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量
//静态成员函数也是有访问权限的
class Person
{
public:
    //静态成员函数，只能访问静态成员变量
    static void func(){
        m_A=100;//静态成员函数可以访问，静态成员变量
        //m_B=200;//静态成员函数 不可以访问非静态成员变量
        cout<<"static void func被调用"<<endl;
    }
    //static int m_A=0;//报错，静态变量类内声明，类外初始化
    static int m_A;//静态成员变量，既可以被静态成员函数访问也可以被非静态
    int m_B;//非静态成员变量，只能被非静态成员函数访问
};

//只有静态属性可以通过类名访问
int Person::m_A=0;//必须在类外，且必须初始化。

void test01(){
    //通过对象访问
    Person p;//static Person p也可以
    //普通对象访问静态成员函数
    p.func();

    //只有静态函数可以通过类名访问
    Person::func();
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

### 4.3 c++对象模型和this指针

#### 4.3.1 成员变量和成员函数分开存储

在c++中，类内的成员变量和成员函数分开存储

只有非静态成员变量才属于类的对象上，每个对象存一份

示例：

```c++
#include <iostream>
using namespace std;

#include "string"

class Person
{
public:
    int a;//非静态成员变量   属于类的对象上
    static int b;//静态成员变量  不属于类对象上
    void func(){}//非静态成员函数 不属于类对象上
    static void func2(){}  //静态成员函数
};
int Person::b=0;
void test01(){
    Person p;
    //空对象占用内存空间为：1
    //c++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存位置
    cout<<"size of p="<< sizeof(p)<<endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 4.3.2 this指针概念

​	c++中成员变量和成员函数是分开储存的

​	每一个非静态成员函数只会诞生一份实例，也就是说多个同类型的对象会共用一块代码，

​	c++通过提供特殊的对象指针(指向对象的指针)，this指针，来调用或区分自己

​	**this指针指向被调用的成员函数所属的对象**

​	this指针是隐含每一个非静态成员函数内的一种指针

​	this指针不需要定义，直接使用即可



​	this指针的**用途**：

​		(a) 当形参和成员变量同名时，可用this指针来区分

​		(b) 在类的非静态成员函数中返回对象本身，可使用return *this

```c++
#include <iostream>
using namespace std;

#include "string"

class Person
{
public:
    Person(int age)
    {
        //this指针指向  被调用的成员函数  所属的对象
        this->age=age;
    }
    Person& PersonsonAddAGe(Person &p)
    {
        this->age+=p.age;
        //this指向p2的指针，而*this指向的就是p2这对象的本体
        return *this;
    }
   int age;
};
//解决名称冲突
void test01(){
    Person p(18);
    cout<<"p的年龄为"<<p.age<<endl;
}
//返回对象本身用*this
void test02(){
    Person p1(10);
    Person p2(10);
    //链式编程，每次调用PersonsonAddAGe都返回p2这个实体自身
    p2.PersonsonAddAGe(p1).PersonsonAddAGe(p1).PersonsonAddAGe(p1);
    cout<<"p2的年龄为："<<p2.age<<endl;
}
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
```

#### 4.3.3 空指针访问成员函数

c++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针

如果用到this指针，需要加以判断保证代码的健壮性

```c++
#include "string"

class Person
{
public:
	Person()
	{
		cout << "构造函数" << endl;
	}
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}
	void showPersonAge()
	{
		//报错原因是因为传入的指针是为NULL
		if (this == NULL){
			return;
		}
		cout << "age=" << this->m_age << endl;
	}
	int m_age;
};
//解决名称冲突
void test01(){
	Person p1;//会进构造函数
	Person *p = NULL;//不会进构造，但不知道为什么？？
    Person *p2 = new Person;//会进构造，这个认为确定this的值
	p->showClassName();
	p->showPersonAge();
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

#### 4.3.4 const修饰成员函数

常函数：

- 成员函数后加const后我们称这个函数为常函数
- 常函数内不可以修改成员属性
- 成员属性声明时若加了关键字mutable后，在常函数中依然可以修改

常对象：

- 声明对象前加const称该对象为常对象
- **常对象只能调用常函数**

```c++
#include "string"

class Person
{
public:
	//this指针的本质  是指针常量  指针的指向是不可以修改的
	//const Person * const this
	//在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
	void showPerson() const
	{
		//m_A=100;//会报错，因为常成员函数中不能修改成员属性
		//this=NULL;//this指针不可以修改指针的指向的
		this->m_B = 100;//因为加了mutable，所以可以修改
	}
	void func(){
		m_A = 100;
	}
	int m_A;
	mutable int m_B;//特殊变量，即时在长韩仲，也可以修改这个值，加上关键字mutable
};

void test01(){
	Person p;
	p.showPerson();
}
//常对象
void test02(){
    const Person p1;//在对象前加const，变成常对象
	//p1.m_A=100;//会报错
    p1.m_B=100;//m_B是特殊值，在对象下也可以修改
    //常对象只能调用常函数
    p1.showPerson();
	//p1.func();//会报错，不能调用普通成员函数，因为不能修改
}
int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
```

> 注意：在test02函数中存在修饰const Person p1报错（为知道原因）??

### 4.4 友元

生活中你的家有客厅(public),有你的卧室(private)

客厅所有来的客人都可以进来，但是你的卧室是私有的，也就是说只有你能进去但是呢。你也可以允许你的好闺蜜好基友进去。

在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

**友元的目的就是让一个函数或者类 访问另一个类中私有成员**

友元的关键字为friend

友元的三种实现

- 全局函数做友元
- 类做友元
- 成员函数做友元

#### 4.4.1 全局函数做友元

```c++
#include <iostream>
using namespace std;

#include "string"

class Building
{
    //goodgay全局函数是 Building好朋友，可以访问Building中私有成员
    friend void goodGay(Building* building);
public:
    Building(){
        m_SittingRoom="客厅";
        m_BedRoom="卧室";
    }
public:
   string m_SittingRoom;
private:
    string m_BedRoom;
};
//全局函数
void goodGay(Building* building){
    cout<<"好基友全局函数 正在访问："<<building->m_SittingRoom<<endl;
    cout<<"好基友全局函数 正在访问："<<building->m_BedRoom<<endl;
}
void test01(){
    Building building;
    goodGay(&building);
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 4.4.2 类做友元

```c++
#include <iostream>
using namespace std;
#include "string"

//类做友元
class Building;

class GoodGay
{
public:
	GoodGay();
	void visit();//参观函数， 访问Building中的属性
	Building *building;
};

class Building{
	//GoodGay类是Building的好基友。可以访问本类(Building)中私有成员
	friend class GoodGay;
public:
	Building();
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

//类外写成员函数
Building::Building() {
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

//类外写成员函数
GoodGay::GoodGay() {
	//创建建筑物对象
	building = new Building;//会进构造函数
}

//类外写成员函数
void GoodGay::visit() {
	cout << "好基友类正在访问：" << building->m_SittingRoom << endl;
	cout << "好基友类正在访问：" << building->m_BedRoom << endl;
}
void test01(){
	GoodGay gg;
	gg.visit();
}
int main() {
	test01();
	system("pause");
	return 0;
}
```

#### 4.4.3 成员函数

```c++
#include <iostream>
using namespace std;

#include "string"
//类做友元
class Building;

class GoodGay
{
public:
    GoodGay();
    void visit();//让visit可以访问Building中私有成员变量
    void visit2();//让visit2不可以访问Building中私有成员变量
    Building * building;
};

class Building{
    //告诉编译器 goodGay类下的visit成员函数作为本来的好朋友， 可以访问私有成员
    friend void GoodGay::visit();
public:
    Building();
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};

//类外写成员函数
Building::Building() {
    m_SittingRoom="客厅";
    m_BedRoom="卧室";
}
GoodGay::GoodGay() {
    //创建建筑物对象
    building=new Building;
}
void GoodGay::visit() {
    cout<<"visit函数正在访问："<<building->m_SittingRoom<<endl;
    cout<<"visit函数正在访问："<<building->m_BedRoom<<endl;
}
void GoodGay::visit2() {
    cout<<"visit2函数正在访问："<<building->m_SittingRoom<<endl;
    //cout<<"visit2函数正在访问："<<building->m_BedRoom<<endl;
}
void test01(){
    GoodGay gg;
    gg.visit();
    gg.visit2();
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

### 4.5 运算符重载

运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

#### 4.5.1 加号运算符重载

作用：实现两个自定义数据类型相加的运算

```c++
#include <iostream>
using namespace std;

class Person
{
public:
    //成员函数重载+号
    Person operator+(Person &p){
        Person temp;
        temp.m_A=this->m_A+p.m_A;
        temp.m_B=this->m_B+p.m_B;
        return temp;
    }
    int m_A;
    int m_B;
};
//全局函数重载+号
//Person operator+(Person &p1,Person &p2)
//{
//    Person temp;
//    temp.m_A=p1.m_A+p2.m_A;
//    temp.m_B=p1.m_B+p2.m_B;
//    return temp;
//}
void test01(){
    Person p1;
    p1.m_A=10;
    p1.m_B=10;
    Person p2;
    p2.m_A=10;
    p2.m_B=10;
    //成员函数重载本质调用
    //Person p3=p1.operator+(p2);
    //全局函数重载本质调用
    //Person p3=operator+(p1,p2);
    Person p3=p1+p2;
    cout<<"p3.m_A="<<p3.m_A<<endl;
    cout<<"p3.m_B="<<p3.m_B<<endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 4.5.2 左移运算符重载

作用：可以输出自定义数据类型

```c++
#include <iostream>
using namespace std;

class Person{
    friend ostream& operator<<(ostream& out,Person &p);

public:
    Person(int a,int b)
    {
        this->m_A=a;
        this->m_B=b;
    }
private:
    //利用成员函数重载 左移运算符 p.operator<<(cout) 简化p<<cout
    //不会利用成员函数重载<<运算符，因为无法实现cout在左侧
    int m_A;
    int m_B;

};

//只能利用全局函数重载左移运算符
ostream & operator<<(ostream &out,Person &p)//本质operator<<（cout，p）简化cout<<p
{
    out<<"m_A="<<p.m_A<<"m_B="<<p.m_B<<endl;
    return out;
}
void test01()
{
    Person p(10,10);
//    p.m_A=10;
//    p.m_B=10;
    cout<<p;
    cout<<p<<"hello world"<<endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

> 总结：重载左移运算符配合友元可以实现输出自定义数据类型

#### 4.5.3 递增运算符重载

作用：通过重载递增运算符，实现自己的整型数据

```c++
#include <iostream>
using namespace std;

//重载递增运算符

//自定义整型
class MyInteger
{
    friend ostream& operator<<(ostream& cout,MyInteger myint);
public:
    MyInteger()
    {
        m_Num=0;
    }
    //重载前置++运算符
    MyInteger& operator++()
    {
        //先进行++运算
        m_Num++;
        //再将自身做返回
        return *this;
    }
    //重载后置++运算符
    //void operator++(int) int代表占位参数，可以用于区分前置和后置递增
    MyInteger operator++(int)
    {
        //先 记录当时结果
        MyInteger temp=*this;
        //后 递增
        m_Num++;
        //最后将记录结果做返回
        return temp;
    }
private:
    int m_Num;
};
//重载<<运算符 返回引用是为了对一个数据进行递增操作
ostream& operator<<(ostream& cout,MyInteger myint)
{
    cout<<myint.m_Num;
    return cout;
}
void test01(){
    MyInteger myint;
    cout<<++(++myint)<<endl;
}

void test02(){
    MyInteger mint;
    cout<<mint++<<endl;
    cout<<mint<<endl;
}
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
```

> 总结：前置递增返回引用，后置递增返回值

#### 4.5.4 赋值运算符重载

c++编译器至少给一个类添加4个函数

- 默认构造函数(无参，函数体为空)
- 默认析构函数(无参，函数体为空)
- 默认拷贝构造函数，对属性进行值拷贝
- 赋值运算符operator=，对属性进行值拷贝

如果类中有属性执行堆区，做赋值操作时也会出现深浅拷贝问题

示例：

```c++
#include <iostream>
using namespace std;

//赋值运算符重载
class Person
{
public:
    Person(int age)
    {
        //开辟年龄到堆区
        m_Age=new int(age);
    }
    ~Person(){
        if(m_Age!=NULL)
        {
            delete m_Age;
            m_Age=NULL;
        }
    }
    //重载 赋值运算符
    Person& operator=(Person &p) //为什么返回必须是引用
    {
        //编译器是提供了浅拷贝
        //m_Age=p.m_Age;
        //应该先判断是否有属性在堆区，如果有先释放干净，然后在深拷贝
        if(m_Age!=NULL)
        {
            delete m_Age;
            m_Age=NULL;
        }
        //深拷贝
        m_Age=new int(*p.m_Age);
        //返回对象本身
        return *this;
    }
    int *m_Age;
};
void test01(){
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p1=p2=p3; //执行顺序的从右向左
    cout<<"p1年龄为："<<*p1.m_Age<<endl;
    cout<<"p2年龄为："<<*p2.m_Age<<endl;
    cout<<"p3年龄为："<<*p3.m_Age<<endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 4.5.5 关系运算符重载

作用：重载关系运算符，可以让两个自定义类型对象进行对比操作

示例：

```c++
#include <iostream>
using namespace std;

#include "string"
//重载关系运算符
class Person
{
public:
    Person(string name,int age){
        m_Name=name;
        m_Age=age;
    }
    //重载==号
    bool operator==(Person &p){
        if(this->m_Name==p.m_Name&&this->m_Age==p.m_Age){
            return true;
        }
        return false;
    }
    //重载!=号
    bool operator!=(Person &p){
        if(this->m_Name==p.m_Name&&this->m_Age==p.m_Age){
            return false;
        }
        return true;
    }
   string m_Name;
   int  m_Age;
};
void test01(){
    Person p1("Tom",18);
    Person p2("jim",18);
    if(p1==p2)
    {
        cout<<"p1和p2相等"<<endl;
    }
    else
    {
        cout<<"p1和p2不相等"<<endl;
    }
    if(p1!=p2)
    {
        cout<<"p1和p2不相等"<<endl;
    }
    else
    {
        cout<<"p1和p2相等"<<endl;
    }
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 4.5.6 函数调用运算符重载

- 函数调用运算符()也可以重载
- 由于重载后使用的方式非常像函数的调用，因此称为防函数
- 仿函数没有固定写法，非常灵活

```c++
#include <iostream>
using namespace std;

#include "string"
//函数调用运算符重载

//打印输出类
class myPrint
{
public:
    //重载函数调用运算符
    void operator()(string test)
    {
        cout<<test<<endl;
    }
};
class MyAdd
{
public:
    int operator()(int v1,int v2){
        return v1+v2;
    }
};
void test01(){
    myPrint mypint;
    mypint("hello world");//由于使用起来非常像函数调用，因此称为仿函数
}
int main() {
    test01();
    cout<<MyAdd()(100,100)<<endl;
    system("pause");
    return 0;
}
```

### 4.6 继承

**继承是面向对象三大特性之一**

我们发现，定义这些类时，下级别的成员除了拥有上一级的共性，还有自己的特性，这个时候我们就可以考虑利用继承的技术，减少重复代码

#### 4.6.1 继承的基本语法

示例：

```c++
#include <iostream>
using namespace std;
#include "string"

//普通实现页面
//继承的好处：减少重复代码
//语法：class 子类：继承方式 父类
//子类   也称为  派生类
//父类   也称为  基类
//继承页面实现
//公共的页面
class BasePage
{
public:
    void header()
    {
        cout<<"首页、公开课、登录、注册...(公共头部)"<<endl;
    }
    void footer(){
        cout<<"帮助中心、交流合作、站内地图...(公共底部)"<<endl;
    }
    void left(){
        cout<<"Java、Python、C++...(公共分类列表)"<<endl;
    }
};
class Java:public BasePage
{
public:
    void content(){
        cout<<"java视频下载"<<endl;
    }
};
class Python:public BasePage
{
public:
    void content(){
        cout<<"Python视频下载"<<endl;
    }
};
class Cpp:public BasePage
{
public:
    void content(){
        cout<<"Cpp视频下载"<<endl;
    }
};
void test01(){
    cout<<"Java下载视频页面如下："<<endl;
    Java ja;
    ja.header();
    ja.left();
    ja.content();
    ja.footer();
    cout<<"---------------------------"<<endl;
    cout<<"Python下载视频页面如下："<<endl;
    Python py;
    py.header();
    py.left();
    py.content();
    py.footer();
    cout<<"---------------------------"<<endl;
    cout<<"C++下载视频页面如下："<<endl;
    Cpp cp;
    cp.header();
    cp.left();
    cp.content();
    cp.footer();
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：可以减少重复的代码

class A:public B;

A类称为子类或派生类

B类称为父类或基类

**派生类中的成员，包含两大部分**

一类是从基类继承过来的，一类是自己增加的成员

从基类继承过来的表现其共性，而新增的成员体现了其个性。

#### 4.6.2 继承方式

继承的语法：class  子类 ：继承方式  父类

继承方式一共有三种：

- 公共继承
- 保护继承
- 私有继承

| 继承方式\基类成员 | public成员 | protected成员 | private成员 |
| ----------------- | ---------- | ------------- | ----------- |
| public继承        | public     | protected     | 不可见      |
| protected继承     | protected  | protected     | 不可见      |
| private继承       | private    | private       | 不可见      |

#### 4.6.3  继承中的对象模型

问题：从父类继承过来的成员，哪些属于子类对象中？

示例：

```c++
#include <iostream>
using namespace std;
#include "string"

class Base
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;//私有成员只是被隐藏了，但是还是会继承下去；子类不可以访问，但可以调用父类成员函数访问
};

//公共继承
class Son :public Base
{
public:
    int m_D;
};
void test01(){
    //父类中所有非静态成员属性都会被子类继承下去
    //父类中私有成员属性 是被编译器给隐藏了，因此是访问不到的，但是确实被继承下去了
    cout<<"sizeof Son ="<< sizeof(Son)<<endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 4.6.4 继承中构造和析构顺序

子类继承父类后，当创建子类对象，也会调用父类的构造函数

问题：父类和子类的构造和析构顺序是谁先谁后？

示例：

```c++
#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout<<"Base构造函数"<<endl;
    }
    ~Base(){
        cout<<"Base析构函数"<<endl;
    }
};
class Son :public Base
{
public:
    Son()
    {
        cout<<"Son构造函数"<<endl;
    }
    ~Son(){
        cout<<"Son析构函数"<<endl;
    }
};


void test01()
{
    //继承中的构造和析构顺序如下：
    //先构造父类，在构造子类，析构的顺序与构造的顺序相反
    Son s;
}
int main() 
{
    test01();
    system("pause");
    return 0;
}
```

#### 4.6.5 继承中同名成员处理方式

问题：当子类与父类出现同名的成员，如何通过子类对象访问到子类或父类中同名的数据呢？

- 访问子类同名成员  直接访问即可
- 访问父类同名成员  需要加作用域

```c++
#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        m_A=100;
    }
    void func(){
        cout<<"base -func()调用"<<endl;
    }
    int m_A;
};
class Son:public  Base
{
public:
    Son()
    {
        m_A=300;
    }
    void func(){
        cout<<"son -func()调用"<<endl;
    }
    int m_A;
};
//同名成员属性处理
void test01(){
    Son s;
    cout<<"Son下m_A ="<<s.m_A<<endl; //300
    //如果通过子类对象  访问到父类中同名成员，需要加作用域
    cout<<"Base下m_A ="<<s.Base::m_A<<endl; //100
}
//同名成员函数处理
void test02(){
    Son s;
    s.func();//直接调用 调用是子类中的同名成员
    //如何调用父类中同名成员函数
    s.Base::func();
}
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
```

总结：

- 子类对象可以直接访问到子类中同名成员

- 子类对象**加作用域**才可以访问到父类同名成员

- 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，**加作用域**才可以访问到父类中同名函数

  

父类中的**static成员被继承**时处理方式一样，没有特殊之处



#### 4.6.6 继承中同名静态成员处理方式

问题：继承中同名的静态成员在子类对象上如何进行访问？

静态成员和非静态成员出现同名，处理方式一致；但与非静态成员不同的是静态成员可**通过类名访问**

- 访问子类同名成员  直接访问即可
- 访问父类同名成员 需要加作用域

```c++
#include <iostream>
using namespace std;

class Base
{
public:
    static int m_A;
    static void func(){
        cout<<"Base-func void func()"<<endl;
    }
};
int Base::m_A=100;

class Son:public  Base
{
public:
    static int m_A;

    static void func(){
        cout<<"Son-func void func()"<<endl;
    }
};
int Son::m_A=100;

//同名静态成员属性
void test01(){
    //通过对象访问
    Son s;
    cout<<"对象访问son下m_A="<<s.m_A<<endl;
    cout<<"对象访问Base下m_A="<<s.Base::m_A<<endl;
    //通过类名访问
    cout<<"类名访问son下m_A="<<Son::m_A<<endl;
    cout<<"对象访问Base下m_A="<<Son::Base::m_A<<endl;
}
//同名静态成员函数
void test02(){
    //通过对象访问
    Son s;
    s.func();
    s.Base::func();
    //通过类名访问
    Son::func();
    Son::Base::func();
}
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
```

#### 4.6.7 多继承语法

**c++允许一个类继承多个类**

语法:class 子类 ：继承方式 父类1，继承方式 父类2...

多继承可能会引发父类中有同名成员出现，需要加作用域区分

**c++实际开发中不建议用多继承**

```c++
#include <iostream>
using namespace std;

class Base1
{
public:
    Base1(){
        m_A=100;
    }
    int m_A;
};
class Base2
{
public:
    Base2()
    {
        m_A=200;
    }
    int m_A;
};
//子类  需继承base1和base2
class Son:public Base1,public Base2
{
public:
    Son()
    {
        m_C=300;
        m_D=400;
    }
    int m_C;
    int m_D;
};

void test02()
{
    Son s;
    cout<<"sizeof Son="<< sizeof(s)<<endl;
    cout<<"m_C="<< s.m_C<<endl;
    cout<<"m_D="<< s.m_D<<endl;
    cout<<"Base1::m_A="<<s.Base1::m_A<<endl;
    cout<<"Base2::m_A="<<s.Base2::m_A<<endl;
}
int main() {
    test02();
    system("pause");
    return 0;
}
```

> 总结：多继承中如果父类中出现了同名情况，子类使用需要加作用域

#### 4.6.8 菱形继承

菱形继承概念：

- 两个派生类继承同一个基类
- 又有某个类同时继承两个派生类
- 这种继承称为菱形继承，或者钻石继承

```c++
#include <iostream>
using namespace std;
//动物类
class Animal{
public:
    int m_Age;
};
//继承之前 加上关键字 virtual变为虚继承
//羊类
class Sheep:virtual public Animal{};
//驼类
class Tuo :virtual public Animal{};
//羊驼类
class SheepTuo :public Sheep,public Tuo{};
void test02(){
    SheepTuo st;
    st.Sheep::m_Age=18; //访问的是同一个变量，因此最终打印全是28
    st.Tuo::m_Age=28;   //访问的是同一个变量，因此最终打印全是28
    cout<<"st.Sheep::m_Age ="<<st.Sheep::m_Age<<endl;
    cout<<"st.Tuo::m_Age ="<<st.Tuo::m_Age<<endl;
    cout<<"st.m_Age ="<<st.m_Age<<endl;
}
int main() {
    test02();
    system("pause");
    return 0;
}
```

总结：

- 菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费毫无意义
- **利用虚继承可以解决菱形继承的问题**

### 4.7 多态

#### 4.7.1 多态的基本概念

**多态是c++面向对象三大特性之一**

多态分为两类：

- 静态多态：函数重载和运算符重载属于静态多态，复用函数名
- 动态多态：派生类和虚函数实现运行时多态

静态多态和动态多态区别：

- 静态多态是函数地址早绑定-编译阶段确定函数地址
- 动态多态的函数地址晚绑定-运行阶段确定函数地址

```c++
#include <iostream>
using namespace std;
//多态
//动物类
class Animal
{
public:
	//虚函数，父类中虚函数实现是毫无意义的，因此这里可改为纯虚函数
	virtual void speak()//若不加virtual则cat 和dog都是调用animal
	{
		cout << "动物在说话" << endl;
	}
};
//猫类
class Cat :public Animal
{
public:
	//重写  函数返回值类型  函数名  参数列表  完全相同-->函数要一模一样
	void speak() //可加virtual可不加，效果一样
	{
		cout << "小猫在说话" << endl;
	}
};
//狗类
class Dog :public Animal
{
	void speak() {
		cout << "小狗在说话" << endl;
	}
};
//执行说话的函数
//地址早绑定 在编译阶段确定函数地址
//如果想执行让猫说话，name这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定

//动态多态满足条件
//1.有继承关系
//2.子类重写父类的虚函数

//动态多态使用
//3.父类的指针或者引用 指向子类对象，通过父类对象调用到子类方法
void doSpeak(Animal &animal) //Animal &animal=cat;
{
    //通过animal可调用Cat Dog的方法，具体看该父类引用指向哪个子类 Cat or Dog
	animal.speak();
}
void test01() {
	Cat cat;
	doSpeak(cat);//小猫在说话

	Dog dog;
	doSpeak(dog);//小狗在说话
}
int main() {
	test01();
	system("pause");

	return 0;
}
```

动态多态满足条件：

- 有继承关系
- 子类重写父类的虚函数

动态多态使用

- 父类指针或引用指向子类对象

重写：函数返回值类型  函数名 参数列表  完全一致 除了virtual 其他一模一样才称为重写

#### 4.7.2 多态案例一，计算器类

案例描述：

分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类

多态的有点：

- 代码组织结构清晰
- 可读性强
- 利用前期和后期的扩展以及维护

```c++
#include <iostream>
using namespace std;
//普通写法
#include "string"
class Calculator
{
public:
    int getResult(string oper)
    {
        if(oper=="+")
        {
            return num1+num2;
        }
        else if(oper=="-")
        {
            return num1-num2;
        }
        else if(oper=="*")
        {
            return num1*num2;
        }
        else if(oper=="/")
        {
            return num1/num2;
        }
    }
    int num1;
    int num2;
};
//多态写法
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int num1;
    int num2;
};
//加法类
class AddCalulator :public AbstractCalculator
{
    int getResult(){
        return num1+num2;
    }
};
//减法类
class SubCalulator :public AbstractCalculator
{
    int getResult(){
        return num1-num2;
    }
};
//减法类
class MulCalulator :public AbstractCalculator
{
    int getResult(){
        return num1*num2;
    }
};
//除法类
class DivCalulator :public AbstractCalculator
{
    int getResult(){
        return num1/num2;
    }
};
void test01()
{
    Calculator c;
    c.num1=10;
    c.num2=10;
    cout<<"num1+num2 ="<<c.getResult("+")<<endl;
    cout<<"num1-num2 ="<<c.getResult("-")<<endl;
    cout<<"num1*num2 ="<<c.getResult("*")<<endl;
    cout<<"num1/num2 ="<<c.getResult("/")<<endl;
}
void test02(){
    //多态使用条件
    //父类指针或者引用指向子类对象
    //加法
    AbstractCalculator *abc=new AddCalulator;
    abc->num1=10;
    abc->num2=10;
    cout<<"num1+num2 ="<<abc->getResult()<<endl;
    delete abc;
    //减法
    abc=new SubCalulator;
    abc->num1=10;
    abc->num2=10;
    cout<<"num1-num2 ="<<abc->getResult()<<endl;
    delete abc;
    //乘法
    abc=new MulCalulator;
    abc->num1=10;
    abc->num2=10;
    cout<<"num1*num2 ="<<abc->getResult()<<endl;
    delete abc;
    //除法
    abc=new DivCalulator;
    abc->num1=10;
    abc->num2=10;
    cout<<"num1/num2 ="<<abc->getResult()<<endl;
    delete abc;

}
int main() {
//    test01();
    test02();
    system("pause");
    return 0;
}
```

#### 4.7.3 纯虚函数和抽象类

在多态中，通常**父类中虚函数的实现是毫无意义**的(父类虚析构函数除外)，主要都是调用子类重写的内容

因此可以将虚函数改为**纯虚函数**，含有纯虚函数的类称为**抽象类**！

纯虚函数语法：virtual  返回值类型  函数名  (参数列表)=0；

抽象类特点：

- **无法实例化对象**

- 子类必须重写抽象类中的纯虚函数，否则由于继承了纯虚函数，也属于抽象类

- 类中只要有一个纯虚函数就算抽象类

  

```c++
#include <iostream>
using namespace std;

class Base
{
public:
    //纯虚函数
    //只要有一个纯虚函数，这个类称为抽象类
    //抽象类的特点：
    //1、无法实例化对象
    //2、抽象类的子类 必须要重写父类中的纯虚函数，否则也属于抽象类
    virtual void func()=0;
};
class Son :public Base
{
public:
    virtual void func() //子类的virtual可有可无，无差异
    {
        cout<<"func函数调用"<<endl;
    };
};
void test01()
{
    //Son s;//子类必须重写父类中的纯虚函数，否则也属于抽象类
    Base *base=new Son;
    base->func();
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 4.7.4 多态案例二，制作饮品

案例描述：

制作饮品的大致流程为：煮水-冲泡-倒入杯中-加入辅料

利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶

```c++
#include <iostream>
using namespace std;

class AbstractDringking
{
public:
    //煮水
    virtual void boil()=0;
    //冲泡
    virtual void dBrew()=0;
    //倒入杯中
    virtual void PourInCup()=0;
    //加入辅料
    virtual void PutSomething()=0;
    //制作饮品
    void makeDrink()
    {
        boil();
        dBrew();
        PourInCup();
        PutSomething();
    }
};
//制作咖啡
class Coffee :public AbstractDringking
{
public:
    //煮水
    virtual void boil(){
        cout<<"煮农夫山泉"<<endl;
    };
    //冲泡
    virtual void dBrew(){
        cout<<"冲泡咖啡"<<endl;
    };
    //倒入杯中
    virtual void PourInCup(){
        cout<<"倒入杯中"<<endl;
    };
    //加入辅料
    virtual void PutSomething(){
        cout<<"加入糖，牛奶"<<endl;
    };
};
//制作咖啡
class Tea :public AbstractDringking
{
public:
    //煮水
    virtual void boil(){
        cout<<"煮矿泉水"<<endl;
    };
    //冲泡
    virtual void dBrew(){
        cout<<"冲泡茶叶"<<endl;
    };
    //倒入杯中
    virtual void PourInCup(){
        cout<<"倒入杯中"<<endl;
    };
    //加入辅料
    virtual void PutSomething(){
        cout<<"加入枸杞"<<endl;
    };
};
//制作函数
void doWork(AbstractDringking * abs)
{
    abs->makeDrink();
    delete abs;//释放
}
void test01(){
    cout<<"----------制作咖啡----------"<<endl;
    doWork(new Coffee);
    cout<<"----------制作茶叶----------"<<endl;
    doWork(new Tea);
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 4.7.5 虚析构和纯虚析构

多态使用是，如果子类中有属性开辟到堆区，name父类指针在释放时无法调用到子类的析构代码

解决方式：将父类中的析构函数改为虚析构或者纯虚析构

虚析构和纯虚析构共性：

- 可以解决父类指针释放子类对象
- 都需要有具体的函数实现

虚析构和纯虚析构的区别：

- 如果是纯虚析构，该类属于抽象类，无法实例化对象

虚析构语法：

**virtual ~类名(){}**

纯虚析构语法：

**virtual ~类名()=0;**

**类名::~类名(){}**

例子1：

```c++
#include <iostream>
using namespace std;

#include "string"

class Animal
{
public:
    Animal(){
        cout<<"animal构造函数调用"<<endl;

    }
    //利用虚析构可以解决 父类指针释放子类对象是不干净的问题
    //不加virtul delete animal只会析构父类，不会析构子类
    //加了virtual无论是虚还是纯虚，释放父类对象的操作都会自动先释放子类
    
// 1.虚析构  
//    virtual ~Animal(){
//        cout<<"animal析构函数调用"<<endl;
//    }
    
//2.纯虚析构 
    //纯虚析构-->基类纯虚函数必须要提供一个定义(实现)，否则编译器会报错
    //有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
    virtual ~Animal() =0;//这里写成虚函数也可以实现统一效果
    
    //纯虚函数
    virtual void speak()=0;
};

//纯虚析构必须有其函数实现
Animal::~Animal() {
    cout<<"animal纯虚析构函数调用"<<endl;
}

class Cat :public Animal
{
public:
    Cat(string name){
        cout<<"Cat构造函数"<<endl;
        m_name=new string(name);
    }
    virtual void speak(){
        cout<<*m_name<<"小猫在说话"<<endl;
    }
    ~Cat(){
        if(m_name!=NULL)
        {
            cout<<"Cat析构函数"<<endl;
            delete m_name;
            m_name=NULL;
        }
    }
    string *m_name;
};

void test01(){
    //先构造Animal再构造Cat，先父后子；构造Cat时申请了堆资源，必须释放。
    Cat *cat = new Cat("Tom"); //Animal * animal = new Cat("Tom")同理;
	Animal * animal = cat;
    animal->speak();//Tom小猫在说话
    
  //父类无虚析构时，父类指针在析构时候不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
    delete animal;//有父类虚析构存在时，先析构Cat 再析构Animal，否则只析构父类
    //注意若是delete cat，则无论负父类是否虚析构，都会先析构子类再析构父类
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

例子2：较难理解！

```c++

#include <vector>
#include<time.h>
#include <iostream>
#include <algorithm>
using namespace std;


class Base
{
public:
	Base() { mPtr = new int; cout << "Base::Construction" << endl;}
	virtual ~Base() = 0;//{ delete mPtr; cout << "Base::Destruction" << endl; }
private:
	int* mPtr;
};

Base::~Base() { cout << "Base virtual Destruction" << endl; };

class Derived : public Base
{
public:
	Derived() { mDerived = new long; cout << "Derived::Construction" << endl;
	}
	~Derived() { delete mDerived; cout << "Derived::Destruction" << endl; }
private:
	long* mDerived;
};

int main()
{
	Base* p = new Derived();
	delete p;
	return 0;
}
结果打印：
Base::Construction
Derived::Construction
Derived::Destruction
Base virtual Destruction
    
注意：若父类的析构不写成虚函数或纯虚函数，则析构使只执行父类的析构，不执行子类的析构，结果如下：
Base::Construction
Derived::Construction
Base virtual Destruction
```

**总结：**

**为什么父类析构函数需要为虚函数？**

1、如果父类的析构函数不是虚函数，则不会触发动态绑定（多态），结果就是只会调用父类的析构函数，而不会调用子类的析构函数，从而可能导致子类的内存泄漏（如果子类析构函数中存在free delete 等释放内存操作时）；

2、如果父类的析构函数是虚函数，则子类的析构函数一定是虚函数（即使是子类的析构函数不加virtual,这是C++的语法规则），则会在父类指针或引用指向一个子类时，触发动态绑定（多态），析构实例化对象时，若是子类则会执行子类的析构函数，同时，编译器会在子类的析构函数中插入父类的析构函数，最终实现了先调用子类析构函数再调用父类析构函数；

3.如果子类中没有堆区数据，父类可以不写为虚析构或纯虚析构；

4.拥有纯虚析构函数的类也属于抽象类；

4.父类的纯虚函数必须进行定义，只写成 virtual ~Base() = 0; 编译器会报错。



#### 4.7.6 多态案例三，电脑组装

案例描述：

电脑主要组成部件为CPU(用于计算),显卡(用于显示),内存条(用于存储)，将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，泪如intel厂商和Lenovo厂商。

创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口

测试时组装三台不同的电脑进行工作

```c++
#include <iostream>
using namespace std;

#include "string"
//抽象不同零件类
//抽象CPU类
class Cpu
{
public:
    //抽象的计算函数
    virtual void calculate()=0;
};
//抽象显卡类
class VideoCard
{
public:
    //抽象的显示函数
    virtual void display()=0;
};
//抽象内存条类
class Memory
{
public:
    //抽象的存储函数
    virtual void storage()=0;
};
//电脑类
class Computer
{
public:
    Computer(Cpu *cpu,VideoCard *vc,Memory *mem)
    {
        m_cpu=cpu;
        m_vc=vc;
        m_mem=mem;
    }
    //提供工作函数
    void work()
    {
        m_cpu->calculate();

        m_vc->display();

        m_mem->storage();
    }
    //提供析构函数  释放3个电脑零件
    ~Computer()
    {
        if(m_cpu!=NULL)
        {
            delete m_cpu;
            m_cpu=NULL;
        }
        if(m_vc!=NULL)
        {
            delete m_vc;
            m_vc=NULL;
        }
        if(m_mem!=NULL)
        {
            delete m_mem;
            m_mem=NULL;
        }
    }
private:
    Cpu *m_cpu;//CPU的零件指针
    VideoCard *m_vc;//显卡零件指针
    Memory *m_mem;//内存条零件指针
};
//具体厂商
class IntelCpu :public Cpu
{
public:
    virtual void calculate()
    {
        cout<<"Intel的CPU开始计算了！"<<endl;
    }
};
class IntelVideoCard :public VideoCard
{
public:
    virtual void display()
    {
        cout<<"Intel的显示屏开始显示了！"<<endl;
    }
};
class IntelMemory :public Memory
{
public:
    virtual void storage()
    {
        cout<<"Intel的内存条开始存储了！"<<endl;
    }
};

class LenovoCpu :public Cpu
{
public:
    virtual void calculate()
    {
        cout<<"Lenovo的CPU开始计算了！"<<endl;
    }
};
class LenovoVideoCard :public VideoCard
{
public:
    virtual void display()
    {
        cout<<"Lenovo的显示屏开始显示了！"<<endl;
    }
};
class LenovoMemory :public Memory
{
public:
    virtual void storage()
    {
        cout<<"Lenovo的内存条开始存储了！"<<endl;
    }
};

void test01(){
    //第一台电脑零件
    Cpu * intelCpu=new IntelCpu;
    VideoCard * intelCard=new IntelVideoCard;
    Memory * intelMemory=new IntelMemory;

    //创建第一台电脑
    Computer *c1=new Computer(intelCpu,intelCard,intelMemory);
    c1->work();
    delete c1;
    //创建第二台电脑
    Computer *c2=new Computer(new LenovoCpu,new LenovoVideoCard,new LenovoMemory);
    c2->work();
    delete c1;
}
int main() {
    test01();
    system("pause");
    return 0;
}
```



## 4.8 const类成员函数（对照4.3.4）

要声明一个const类型的类成员函数，只需要在成员函数参数列表后加上关键字const，该成员函数不能修改类的所有成员属性。

```c++
    class Screen {
    public:
       char get() const;
    };
```

若将成员成员函数声明为const，则该函数不允许修改类的数据成员。例如

```c++
class Screen {
public:
    int get_ok() const {return _cursor; } //正确
    int set_error(intival) const { _cursor = ival; }//错误！
};
```

const成员函数可以被具有相同参数列表的非const成员函数重载，例如

```c++
class Screen {
public:
    char get(int x,int y) {
        return 'v';
    }
    char get(int x,int y) const {
        return 'v';
    }
};
```

在这种情况下，类对象的常量性决定调用哪个函数

```c++
const Screen cs;//常量类对象必须调用const成员函数
Screen cc2; //一般类对象既可以调用常成员函数也可以调用const成员函数
char ch = cs.get(0, 0);  // 调用const成员函数
ch = cs2.get(0, 0);     // 调用非const成员函数和const都可，优先调用非const函数
```

作为一种良好的编程风格，在声明一个成员函数时，若该成员函数并不对数据成员进行修改操作，应尽可能将该成员函数声明为const 成员函数。

***！！注意对比记忆const成员函数/对象和static静态成员函数/变量***

## 5 文件操作

程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放

通过文件可以将数据持久化

c++中对文件操作需要包含头文件<fstream>

文件类型分为两种：

1.**文本文件**  文件以文本的ASCII码形式存储在计算机中

2.**二进制文件** 文件以文本的二进制形式村粗在计算机中，用户一般不能直接读懂他们

操作文件的三大类：

- ofstream:写操作
- ifstream：读操作
- fstream：读写操作

### 5.1 文本文件

#### 5.1.1 写文件

写文件步骤如下：

1.包含头文件

> #include  <fstream>

2.创建流对象

> ofstream ofs;

3.打开文件

> ofs.open("文件路径",打开方式)

4.写数据

> ofs<<"写入得数据"

5.关闭文件

> ofs.close();

文件打开方式：

|  打开方式   |            解释            |
| :---------: | :------------------------: |
|   ios::in   |     为读文件而打开文件     |
|  ios::out   |     为写文件而打开文件     |
| ios::binary |         二进制方式         |
|  ios::app   |       追加方式写文件       |
| ios::trunc  | 如果文件存在先删除，在创建 |
|  ios::ate   |     初始文职：文件末尾     |

注意：文件打开方式可以配合使用，利用 |操作符

列如：用二进制方式写文件 ios::binary | ios::out

```c++
#include <iostream>
using namespace std;

#include <fstream>
//文本文件  写文件
void test01()
{
    //1.包含头文件 fstream
    //2.创建流对象
    ofstream ofs;
    //3.指定打开方式
    ofs.open("test.txt",ios::out);
    //4.写内容
    ofs<<"姓名：张三"<<endl;
    ofs<<"性别：男"<<endl;
    ofs<<"年龄：18"<<endl;

    //5.关闭文件
    ofs.close();
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：

- 文件操作必须宝行头文件 fstream
- 读文件可以利用ofstream，或者fstream类
- 打开文件时候需要制定操作文件的路径，以及打开方式
- 利用<<可以向文件写数据
- 操作完毕，要关闭文件

#### 5.1.2 读文件

读文件与写文件步骤相似，但是读取方式相对于比较多

读文件步骤如下：

1.包含头文件

#incalude <fstream>

2.创建流对象

ifstream  ifs;

3.打开文件并判断文件是否打开成功

ifs.open("文件路径",打开方式)

4.读数据

四种方式读取

5.关闭文件

ifs.close();

```c++
#include <iostream>
using namespace std;

#include <fstream>
#include "string"
//文本文件  读文件
void test01()
{
   //包含头文件
   //创建流对象
   ifstream ifs;
   //打开文件  并且判断是否打开成功
   ifs.open("test.txt",ios::in);
   if(!ifs.is_open())
   {
       cout<<"文件打开失败"<<endl;
       return;
   }
   //读数据
    //第一种
//   char buf[1024]={0};
//   while (ifs>>buf)
//   {
//       cout<<buf<<endl;
//   }
    //第二种
//   char buf[1024]={0};
//   while(ifs.getline(buf, sizeof(buf)))
//   {
//       cout<<buf<<endl;
//   }
    //第三种
//   string buf;
//   while(getline(ifs,buf))
//   {
//       cout<<buf<<endl;
//   }
    //第四种
   char c;
   while((c=ifs.get())!=EOF) //EOF  end of file
   {
       cout<<c;
   }
   //关闭文件
   ifs.close();
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：

- 读文件可以利用ifstream，或者fstream类
- 利用is_open函数可以判断文件是否打开成功
- close关闭文件

### 5.2 二进制文件

以二进制的方式对文件进行读写操作

打开方式要指定为ios::binary

#### 5.2.1 写文件

二进制方式写文件主要利用流对象调用成员函数write

函数原型：ostream& write(const char * buffer,int len)

参数解释：字符指针buffer指向内存中一段存储空间，len是读写文件的字节数

```c++
#include <iostream>
using namespace std;

#include <fstream>
//二进制文件  写文件
class Person
{
public:
    char m_Name[64]; //姓名
    int m_Age;//年龄
};
void test01()
{
    //1.包含头文件
    //创建流对象
    ofstream ofs("person.txt",ios::out | ios::binary);
    //写文件
    Person p={"张三",18};
    ofs.write((const char *)&p, sizeof(Person));
    //关闭文件
    ofs.close();
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：

- 文件输出流对象 可以通过write函数，以二进制方式写数据

#### 5.2.2 读文件

二进制方式读文件主要利用流对象调用成员函数read

函数原型：istream& read(char *buffer,int len)

参数解释：字符指针buffer指向内存中一段存储空间，len是读写的字节数

```c++
#include <iostream>
using namespace std;

#include <fstream>
//二进制文件  读文件
class Person
{
public:
    char m_Name[64]; //姓名
    int m_Age;//年龄
};
void test01()
{
    //包含头文件
    //创建流对象
    ifstream ifs;
    //打开文件 判断文件是否打开成功
    ifs.open("person.txt",ios::in | ios::binary);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    //读文件
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout<<"姓名："<<p.m_Name<<" 年龄:"<<p.m_Age<<endl;
    //关闭文件
    ifs.close();
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

- 文件输入流对象 可以通过read函数，以二进制方式读数据

# 三、c++ 提高编程

- 本阶段主要针对c++泛型编程和STL技术做详细讲解，探讨c++更深层的使用

## 1 模板

### 1.1 模板的概念

模板就是建立通用的模具，大大提高复用性

模板的特点：

- 模板不可以直接使用，它只是一个框架
- 模板的通用并不是万能的

### 1.2 函数模板

- c++另一种编程思想称为泛型编程，主要利用的技术就是模板
- c++提供两种模板机制：函数模板和类模板

#### 1.2.1 函数模板语法

函数模板作用：

建立一个通用函数，其函数返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代表

语法：

> template<typename T>
>
> 函数声明或定义

解释：

template---声明创建模板

typename---表面其后面的符号是一种数据类型，可以用class代替

T ---通用的数据类型，名称可以替换，通常为大写字母

```c++
#include <iostream>
using namespace std;

template<typename T> //声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T &a,T &b)
{
    T temp =a;
    a=b;
    b=temp;
}
void test01()
{
    int a=10;
    int b=20;
    //自动类型推导
//    mySwap(a,b);
    //显示指定类型
    mySwap<int>(a,b);
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：

- 函数模板利用关键字template
- 使用函数模板有两种方式：自动类型推导、显示指定类型
- 模板的目的是为了提高复用性，将类型参数化

#### 1.2.2 函数模板注意事项

注意事项：

- 自动类型推导，必须推导出一致的数据类型T，才可以使用
- 模板必须要确定出T的数据类型，才可以使用

```c++
#include <iostream>
using namespace std;
//函数模板注意事项
template<class T> //typename可以特换成class
void mySwap(T&a,T&b)
{
    T temp =a;
    a=b;
    b=temp;
}
//1、自动类型推导，必须推导出一只的数据类型T才可以使用
void test01(){
    int a=10;
    int b=20;
    //char c='c'
    mySwap(a,b);//正确！
    //mySwap(a,c);//错误！推导不出一致的T类型
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
}
//2、模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()
{
    cout<<"func调用"<<endl;
}
void test02(){
    //func(); //错误!
    func<int>();
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
```

总结：

- 使用模板是必须确定出通用数据类型T,并且能够推导出一只的类型

#### 1.2.3 函数模板案例

案例描述：

- 利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
- 排序规则从大到小，排序算法为选择排序
- 分别利用插入数组和ing数组进行测试

示例：

```c++
#include<iostream>
using namespace std;
//实现通用 对数组进行排序的函数
//规则  从大到小
//算法 选择
//测试 char数组  int数组
//交换函数模板
template<class T>
void mySwap(T&a,T&b)
{
    T temp=a;
    a=b;
    b=temp;
}
//排序算法
template<class T>
void mySort(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        int max=i;
        for(int j=i+1;j<len;j++)
        {
            //认定最大值 比 遍历出的数值要打，说明j下标的元素才是真正的最大值
            if(arr[max]<arr[j])
            {
                max=j;//更新最大值下标
            }
        }
        if(max!=i)
        {
            //交换和i元素
            mySwap(arr[max],arr[i]);
        }
    }
}
//提供打印数组模板
template<class T>
void printArray(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void test01()
{
    //测试char数组
    char charArr[]="badcfe";
    int num=sizeof(charArr)/sizeof(char);
    mySort(charArr,num);
    printArray(charArr,num);
}
void test02(){
    //测试int数组
    int intArr[]={7,5,1,3,9,2,4,6,8};
    int num= sizeof(intArr)/ sizeof(int);
    mySort(intArr,num);
    printArray(intArr,num);
}
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
```

#### 1.2.4 普通函数与函数模板的区别

普通函数与函数模板区别：

- 普通函数调用时可以发生自动类型转换（隐式类型转换）
- 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
- 如果利用显示指定类型方式，可以发生隐式类型转换

示例：

```c++
#include<iostream>
using namespace std;

//普通函数
int myAdd01(int a,int b)
{
    return a+b;
}
//函数模板
template <class T>
T myAdd02(T a,T b)
{
    return a+b;
}
//使用函数模板是，如果用自动类型推导，不会发生自动类型转换，即隐式类型转换
void test01()
{
    int a=10;
    int b=20;
    char c='c';
    cout<<myAdd01(a,b)<<endl;
    //自动类型推导
    cout<<myAdd01(a,c)<<endl;
    //显示指定类型
    cout<<myAdd02<int>(a,c)<<endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：建议使用显示指定类型的方式，调用函数模板，因为可以自己确定调用类型T

#### 1.2.5 普通函数与函数模板的调用规则

调用规则如下：

- 如果函数模板和普通函数都可以实现，优先调用普通函数
- 可以通过空模板参数列表来强制调用函数模板
- 函数模板也可以发生重载
- 如果函数模板可以产生更好的匹配，优先调用函数模板

示例：

```c++
#include<iostream>
using namespace std;

//普通函数与函数模板调用规则
void myPrint(int a,int b)
{
    cout<<"调用普通函数"<<endl;
}
template <typename T>
void myPrint(T a,T b,T c)
{
    cout<<"调用的模板"<<endl;
}
void test01()
{
    int a=10;
    int b=10;
//    myPrint(a,b,100);
    //通过空模板参数列表，强制调用函数模板
//    myPrint<>(a,b);
    //如果函数模板产生更好的匹配，优先调用函数模板
    char c1='a';
    char c2='b';
    myPrint(c1,c2);
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 1.2.6 模板的局限性

局限性：

- 模板的通用性并不是万能的

例如：

```c++
template<class T>
void f(T a,T b)
{
	a=b;
}
```

在上述代码中提供的赋值操作，如果转入的a和b是一个数组，就无法实现

再例如：

```c++
template<class T>
void f(T a,T b)
{
	if(a>b){...}
}
```

在上述代码中，如果T的数据类型传入的是像Person这样的自定义数据类型，也无法正常运行

因此c++为了解决这种问题，提供模板的重载，可以为这些特定类型提供具体化的模板

```c++
#include<iostream>
using namespace std;

#include <string>
class Person
{
public:
    Person(string name,int age){
        this->m_Name=name;
        this->m_Age=age;
    }
    //姓名
    string m_Name;
    //年龄
    int m_Age;
};
template<class T>
bool myCompare(T &a,T &b)
{
    if(a==b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//利用具体化Person的版本实现代码，具体化优先调用
template<> bool myCompare(Person &p1,Person &p2)//前面加的有什么意义？
{
    if(p1.m_Name==p2.m_Name &&p1.m_Age==p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test01()
{
    int a=10;
    int b=20;
    bool ret=myCompare(a,b);
    if(ret)
    {
        cout<<"a==b"<<endl;
    }
    else
    {
        cout<<"a!=b"<<endl;
    }
}
void test02()
{
    Person p1("Tom",10);
    Person p2("Tom",11);
    bool ret=myCompare(p1,p2);
    if(ret)
    {
        cout<<"p1==p2"<<endl;
    }
    else
    {
        cout<<"p1!=p2"<<endl;
    }
}
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
```

总结：

- 利用具体化的模板，可以解决自定义类型的通用化
- 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板

### 1.3 类模板

#### 1.3.1 类模板语法

类模板作用：

- 建立一个通用类，类中的成员 数据类型可以不具体指定，用一个虚拟的类型来代表

语法：

> template<typename T>
>
> 类

解释：

template ---声明创建模板

typename ---表面其后面的符号一种数据类型，可以用class代替

T ---通用的数据类型，名称可以替换，通常为大写字母

```c++
#include<iostream>
using namespace std;

#include <string>
template <class NameType,class AgeType>
class Person
{
public:
    Person(NameType name,AgeType age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    void showPerson()
    {
        cout<<"name: "<<this->m_Name<<"  年龄： "<<this->m_Age<<endl;
    }
    //姓名
    NameType m_Name;
    //年龄
    AgeType m_Age;
};
void test01()
{
    Person<string,int> p1("孙悟空",999);//类模板，参数列表必须有，不能自动类型推导
    p1.showPerson();
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：类模板和函数模板语法相似，在声明模板template后面加类，此类称为类模板

#### 1.3.2 类模板与函数模板区别

类模板与函数模板区别主要有两点

- **类模板没有自动类型推导的使用方式**
- 类模板在模板参数列表中可以有默认参数

示例：

```c++
template <class NameType,class AgeType=int>
class Person
{
public:
    Person(NameType name,AgeType age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    void showPerson()
    {
        cout<<"name: "<<this->m_Name<<"  年龄： "<<this->m_Age<<endl;
    }
    //姓名
    NameType m_Name;
    //年龄
    AgeType m_Age;
};
void test01()
{
    Person<string int>p("孙悟空",1000);
    p.showPerson();
}
void test02()
{
    Person<string>p("猪八戒",1000);
    p.showPerson();
}
```

#### 1.3.3 类模板中成员函数创建时机

类模板中成员函数和普通类中成员函数创建时间是有区别的：

- 普通类中的成员函数一开始就可以创建
- 类模板中的成员函数在调用是才创建

示例：

```c++
class Person1()
{
public:
	void showPerson1()
	{
		cout<<"Person1 show"<<endl;
	}
};
class Person2()
{
public:
	void showPerson2()
	{
		cout<<"Person2 show"<<endl;
	}
};
template<class T>
class MyClass
{
public:
	T obj;
	//类模板中的成员函数
	void func1(){
		obj.showPerson1();
	}
	void func2(){
		obj.showPerson2();
	}
};
void test01()
{
	MyClass<Person1>m;
	m.func1();
	//m.func2();//编译器会出错，说明函数调用才会去创建成员函数
}
```

总结：类模板中的成员函数并不是一开始就创建的，在调用是才去创建

#### 1.3.4 类模板对象做函数参数

学习目标：

- 类模板实例化出的对象，向函数传参的方式

一共有三种传入方式

- 指定传入的类型  ---直接显示对象数据类型
- 参数模板化  ---将对象中的参数变为模板进行传递
- 整个类模板化  ---将这个对象类型 模板化进行传递

示例：

```c++
#include<iostream>
using namespace std;

#include<string>
//类模板对象做函数参数
template<class T1,class T2>
class Person
{
public:
    Person(T1 name,T2 age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    void showPerson()
    {
        cout<<"姓名："<<this->m_Name<<"年龄："<<this->m_Age<<endl;
    }
    T1 m_Name;
    T2 m_Age;
};   
//1、指定传入类型
void printPerson1(Person<string,int>&p)
{
    p.showPerson();
}
void test01()
{
   Person<string,int>p("孙悟空",100); 
   printPerson1(p);
}
//2、参数模板化
template<class T1,class T2>
void printPerson2(Person<T1,T2>&p)
{
    p.showPerson();
    cout<<"T1的类型为："<<typeid(T1).name()<<endl;
    cout<<"T1的类型为："<<typeid(T2).name()<<endl;
}
void test02()
{
    Person<string,int>p("猪八戒",90); 
    printPerson2(p);
}
//3、整个类模板化
template<class T>
void printPerson3(T &p)
{
    p.showPerson();
    cout<<"T的数据类型为："<<typeid(T).name()<<endl;
}
void test03()
{
    Person<string,int>p("唐僧",40);
    printPerson3(p)
}
int main(){
    test01();
    test02();
    test03();
    system("pause");
    return 0;
}
```

#### 1.3.5 类模板与继承

当类模板碰到继承时，需要注意一下几点：

- 当子类继承父类是一个类模板是，子类在声明的时候，要指定父类中T的类型
- 如果不指定，编译器无法给子类分配内存
- 如果想灵活指定出父类中T的类型，子类也需要变为类模板

示例：

```c++
#include<iostream>
using namespace std;

template<class T>
class Base
{
	T m;
};
class Son :public Base<int> //必须指定数据类型
{
	
};
void test01()
{
	Son s1;
}
//如果想灵活指定父类中T类型，子类也需要变类模板
template<class T1,class T2>
class Son2 :public Base<T2> //必须指定数据类型
{
public:
    Son2()
    {
    	cout<<"T1的类型为："<<typeid(T1).name()<<endl;
    	cout<<"T2的类型为："<<typeid(T2).name()<<endl;
    }
	T1 obj;
};
void test01()
{
	Son2<int,char> s2;
}
//....运行
```

总结：如果父类是类模板，子类需要指定出父类中T的数据类型

#### 1.3.6 类模板成员函数类外实现

学习目标：能够掌握类模板中的成员函数类外实现

示例：

```c++
#include<iostream>
using namespace std;
#include<string>
//类模板成员函数类外实现
template<class T1,class T2>
class Person
{
public:
    Person(T1 name,T2 age);
    void showPerson();
    T1 m_Name;
    T2 m_Age;
};  
//构造函数类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
     this->m_Name=name;
     this->m_Age=age;
}
//成员函数类外实现
template<class T1,class T2>
void Person<T1,T2>::showPerson()
{
   cout<<"姓名："<<this->m_Name<<"年龄："<<this->m_Age<<endl;
}
void test01()
{
    Person<string,int> p("Tom",20)
    p.showPerson();
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

#### 1.3.7 类模板分文件编写

学习目标：

- 掌握类模板成员函数分文件编写产生的问题以及解决方式

问题：

- 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

解决：

- 解决方式1：直接包含.cpp源文件
- 解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp,hpp是约定的名称，并不是强制

示例：

```c++
//第一种解决方式直接包含源文件
//person.h
#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T1,class T2>
class Person
{
public:
    Person(T1 name,T2 age);
    void showPerson();
    T1 m_Name;
    T2 m_Age;
};

//person.cpp	
#include "person.h"
template <class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age) {
    this->m_Name=name;
    this->m_Age=age;
}
template <class T1,class T2>
void Person<T1,T2>::showPerson() {
    cout<<"姓名："<<this->m_Name<<" 年龄："<<this->m_Age<<endl;
}

//main.cpp
#include<iostream>
using namespace std;

#include "person.cpp"
void test01(){
    Person<string,int >p("tom",17);
    p.showPerson();
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

```c++
//第二种解决方式，将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件
//person.hpp
#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T1,class T2>
class Person
{
public:
    Person(T1 name,T2 age);
    void showPerson();
    T1 m_Name;
    T2 m_Age;
};
template <class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age) {
    this->m_Name=name;
    this->m_Age=age;
}
template <class T1,class T2>
void Person<T1,T2>::showPerson() {
    cout<<"姓名："<<this->m_Name<<" 年龄："<<this->m_Age<<endl;
}

//main.cpp
#include<iostream>
using namespace std;
//第二种解决方式，将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件
#include "person.hpp"
void test01(){
    Person<string,int >p("tom",17);
    p.showPerson();
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：主流的解决方式是第二种，将类模板成员函数写到一起，并将后缀名改为.hpp

#### 1.3.8 类模板与友元

学习目标：

- 掌握类模板配合友元函数的类内和类外实现

全局函数类内实现-直接在类内声明友元即可

全局函数类外实现-需要提前让编译器知道全局函数的存在

示例：

```c++
#include<iostream>
using namespace std;

#include <string>

template <class T1,class T2>
class Person;
//类外实现
template<class T1,class T2>
void printPerson2(Person<T1,T2> p)
{
    cout<<"类外实现---姓名："<<p.m_Name<<" 类外实现---年龄："<<p.m_Age<<endl;
}

//通过全局函数 打印Person信息
template <class T1,class T2>
class Person
{
    friend void printPerson(Person<T1,T2> p)
    {
        cout<<"姓名："<<p.m_Name<<" 年龄："<<p.m_Age<<endl;
    }
    //全局函数  类外实现
    //加空模板参数列表
    //如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person<T1,T2> p);//实测必须要这个<>但不知有什么用？
public:
    Person(T1 name,T2 age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

//1、全局函数在类内实现
void test01(){
    Person<string,int>p("Tom",20);
    printPerson(p);
}
//2、全局函数在类外实现
void test02(){
    Person<string,int>p("Jim",20);
    printPerson2(p);
}
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
```

总结：建议全局函数做类内实现，用法简单，而且编译器可以直接识别

#### 1.3.9 类模板案例

案例描述：实现一个通用的数组类，要求如下：

- 可以对内值数据类型以及自定义数据类型的数据进行存储
- 将数组中的数据存储到堆区
- 构造函数中可以传入数组的容量
- 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
- 提供尾插法和尾删法对数组中的数据进行增加和删除
- 可以通过下标的方式访问数组中的元素
- 可以获取数组中当前元素个数和数组的容量

示例：

myArray.hpp中代码

```c++
//自己的通用的数组类
#pragma once

#include <iostream>
using namespace std;
template <class T>
class MyArray {
public:
    //有参构造  参数  容量
    MyArray(int capacity)
    {
        //cout<<"MyArray有参构造调用"<<endl;
        this->m_Capacity=capacity;
        this->m_Size=0;
        this->pAddress=new T[this->m_Capacity];
    }
    //拷贝构造
    MyArray(const MyArray& arr)
    {
        //cout<<"MyArray拷贝构造调用"<<endl;
        this->m_Capacity=arr.m_Capacity;
        this->m_Size=arr.m_Size;
       //this->pAddress=arr.pAddress;
       //深拷贝
        this->pAddress=new T[arr.m_Capacity];
        //将arr中的数据都拷贝过来
        for(int i=0;i<this->m_Size;i++)
        {
            this->pAddress[i]=arr.pAddress[i];
        }
    }
    //operator=防止浅拷贝问题
    MyArray& operator=(const MyArray& arr)
    {
        //cout<<"MyArray中operator的调用"<<endl;
        //先判断原来堆区是否有数据，如果有限释放
        if(this->pAddress!=NULL)
        {
            delete[] this->pAddress;
            this->pAddress=NULL;
            this->m_Capacity=0;
            this->m_Size=0;
        }
        //深拷贝
        this->m_Capacity=arr.m_Capacity;
        this->m_Size=arr.m_Size;
        this->pAddress=new T[arr.m_Capacity];
        for(int i=0;i<this->m_Size;i++)
        {
            this->pAddress[i]=arr.pAddress[i];
        }
        return * this;
    }
    //尾插法
    void Push_Back(const T & val)
    {
        //判断容量是否等于大小
        if(this->m_Capacity==this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size]=val;
        this->m_Size++;//更新数组大小
    }
    //尾删法
    void Pop_Back()
    {
        //让用户访问不到最后一个元素，即为尾删，逻辑删除
        if(this->m_Size==0)
        {
            return;
        }
        this->m_Size--;
    }
    //通过下标方式访问数组中的元素
    T operator[](int index)
    {
        return this->pAddress[index];
    }
    //返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }
    //返回数组大小
    int getSize()
    {
        return this->m_Size;
    }
    //析构函数
    ~MyArray()
    {
        //cout<<"MyArray析构函数调用"<<endl;
        if(this->pAddress!=NULL)
        {
            delete[] this->pAddress;
            this->pAddress=NULL;
        }
    }
private:
    T * pAddress;//指针指向堆区开辟的真实数组
    int m_Capacity;//数组容量
    int m_Size;//数组大小
};


```

测试main.cpp

```c++
#include<iostream>
using namespace std;

#include <string>
#include "MyArray.hpp"
void printIntArray(MyArray <int>& arr)
{
    for (int i = 0; i <arr.getSize(); ++i) {
        cout<<arr[i]<<endl;
    }
}
void test01()
{
    MyArray <int>arr1(5);
    for (int i = 0; i <5; ++i) {
        //利用尾插法向数组中插入数据
        arr1.Push_Back(i);
    }
    cout<<"arr1的打印输出为："<<endl;
    printIntArray(arr1);
    cout<<"arr1的容量为：" << arr1.getCapacity()<<endl;
    cout<<"arr1的大小为：" << arr1.getSize()<<endl;

    cout<<"arr2的打印输出为："<<endl;
    MyArray <int>arr2(arr1);
    printIntArray(arr2);

    //尾删
    arr2.Pop_Back();
    cout<<"arr2的容量为：" << arr2.getCapacity()<<endl;
    cout<<"arr2的大小为：" << arr2.getSize()<<endl;
}
//测试自定义数据类型
class Person
{
public:
    Person(){};
    Person(string name,int age)
    {
        this->m_Age=age;
        this->m_Name=name;
    }
    string m_Name;
    int m_Age;
};
void printPersonArray(MyArray<Person>& arr)
{
    for(int i=0;i<arr.getSize();i++)
    {
        cout<<"姓名："<<arr[i].m_Name<<" 年龄："<<arr[i].m_Age<<endl;
    }
}
void test02()
{
    MyArray<Person> arr(10);
    Person p1("张三",20);
    Person p2("李四",21);
    Person p3("王五",22);
    Person p4("赵六",23);
    Person p5("刘七",24);
    //将数据插入到数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);
    //打印数组
    printPersonArray(arr);

    //输出容量
    cout<<"arr容量为："<<arr.getCapacity()<<endl;
    //输出大小
    cout<<"arr大小为："<<arr.getSize()<<endl;

}
int main() {
//    test01();
    test02();
    system("pause");
    return 0;
}
```

总结：能够利用所学习知识点实现通用的数组

## 2 STL初识

### 2.1 STL的诞生

- 长久以来，软件界一直希望建立一种可重复利用的东西
- c++的面向对象和泛型编程思想，目的就是复用性的提升
- 大多情况下，数据结构和算法都未能有一套标准，导致被迫从事大量重复工作
- 为了建立数据结构和算法的一套标准，诞生了STL

### 2.2 STL基本概念

- STL(Standard Template Library,标准模板库)
- STL从广义上分为：容器(container)算法(algorithm)迭代器(iterator)
- 容器和算法之间通过迭代器进行无缝连接
- STL几乎所有的代码都采用了模板类或者模板函数

### 2.3 STL六大组件

STL大体分为六大组件，分别是：容器、算法、迭代器、仿函数、适配器(配接器)、空间配置器

- 容器：各种数据结构，如vector、list、deque、set、map等，用来存放数据
- 算法：各种常用的算法，如sort、find、copy、for_each等
- 迭代器：扮演了容器与算法之间的胶合剂
- 仿函数：行为类似函数，可以作为算法的某种策略
- 适配器：一种用来修饰修饰容器或者仿函数或迭代器接口的东西
- 空间配置器：负责空间的配置与管理

### 2.4 STL中容器、算法、迭代器

容器：置物之所也

STL容器就是将运用最广泛的一些数据结构实现出来

常用的数据结构：数组，链表，树，栈，队列，集合，映射表 等

这些容器分为序列式容器和关联式容器两种

- 序列式容器：强调值得排序，序列式容器中的每个元素均有固定的位置
- 关联式容器：二叉树结构，各元素之间没有严格的物理上的顺序关系



算法：问题之解法也

有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法

算法分为：质变算法和非质变算法。

质变算法：是指运算过程中会更改区间内的元素的内容，列如拷贝，替换，删除等等

非质变算法：是指运算过程中不会更改区间内的元素内容，列如查找，计算，遍历，寻找极值等等



迭代器：容器和算法之间粘合剂

提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无须暴露该容器的内部表达方式。

每个容器都有自己专属的迭代器

迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针

迭代器种类：

| 种类           | 功能                                                     | 支持运算                                |
| -------------- | -------------------------------------------------------- | --------------------------------------- |
| 输入迭代器     | 对数据的只读访问                                         | 只读，支持++、==、！、=                 |
| 输出迭代器     | 对数据的只写访问                                         | 只写，支持++                            |
| 前向迭代器     | 读写操作，并能向前推进迭代器                             | 读写，支持++、==、！、=                 |
| 双向迭代器     | 读写操作，并能向前和向后操作                             | 读写，支持++、--，                      |
| 随机访问迭代器 | 读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器 | 读写，支持++、--、[n]、-n、<、<=、>、>= |

常用的容器中迭代器种类为双向迭代器，和随机访问迭代器

### 2.5 容器算法迭代器初始

了解STL中容器、算法、迭代器概念之后，我们利用代码感受STL的魅力

STL中最常用的容器为Vector，可以理解为数组，下面我们将学习如何向这个容器中插入数据，并遍历这个容器

#### 2.5.1 vector存放内置数据类型

容器：vector

算法：for_each

迭代器：vector<int>::iterator

示例：

```c++
#include<iostream>
using namespace std;

#include <vector>
#include <algorithm>//标准算法头文件

//vector容器存放内置数据类型
//打印函数
void myPrint(int val)
{
    cout<<val<<endl;
}
void test01()
{
    //创建了一个vector容器，数组
    vector<int> v;
    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    //同过迭代器访问容器中的数据
//    vector<int>::iterator itBegin=v.begin();//起始迭代器  指向容器中第一个元素
//    vector<int>::iterator itEnd=v.end();//结束迭代器，指向容器中最后一个元素的下一个位置
    //第一种遍历方式
//    while (itBegin!=itEnd)
//    {
//        cout<<*itBegin<<endl;
//        itBegin++;
//    }
    //第二种遍历方式
//    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
//    {
//        cout<<*it<<endl;
//    }
    //第三种遍历方式  利用STL提供遍历算法
    for_each(v.begin(),v.end(),myPrint);
}
int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 2.5.2 Vector存放自定义数据类型

学习目标：vector中存放自定义数据类型，并打印输出

示例：

```c++
#include<iostream>
using namespace std;

#include <vector>
#include <string>
//vector容器中存放自定义数据类型
class Person
{
public:
    Person(string name,int age)
    {
        mName=name;
        mAge=age;
    }

public:
    string mName;
    int mAge;
};
void test01()
{
    vector<Person> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    //遍历容器中的数据
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
//        cout<<"姓名："<<(*it).mName<<" 年龄："<<(*it).mAge<<endl;
        cout<<"姓名："<<it->mName<<" 年龄："<<it->mAge<<endl;
    }
}
//存放自定义数据类型 指针
void test02()
{
    vector<Person*> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    //遍历容器
    for(vector<Person *>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"姓名："<<(*it)->mName<<" 年龄："<<(*it)->mAge<<endl;
    }
}
int main() {
//    test01();
    test02();
    system("pause");
    return 0;
}
```

#### 2.5.3 Vector容器嵌套容器

学习目标：容器中嵌套容器，我们将所有数据进行遍历输出

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>

//容器嵌套容器
void test01()
{
    vector<vector<int>> v;
    //创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    //向小容器中添加数据
    for (int i = 0; i <4;i++) {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }
    //将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    //通过大容器，吧所有数据遍历一遍
    for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++)
    {
        //(*it)---容器vector<int>
        for(vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++)
        {
            cout<<*vit<<" ";
        }
        cout<<endl;
    }
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

## 3 STL-常量容器

### 3.1 string容器

#### 3.1.1 string基本概念

本质：

- string是c++风格的字符串，而string本质上是一个类

string和char *区别

- char *是一个指针
- string是一个类，类内部封装了char*，管理这个字符串，是一个char * 型的容器，

特点：

string类内部封装了很多成员方法

例如：查找find，拷贝copy，删除delete，替换replace，插入insert

string管理char *所分配的内存，不用担心复制越界和取值越界等，有类内部进行负责

#### 3.1.2 string构造函数

构造函数原型：

- string()           //创建一个空的字符串 例如：string str；
- string(const char* s); //使用字符串s初始化
- string(string string& str); //使用一个string对象初始化另一个string对象
- string(int n,char c);     //使用n个字符c初始化

```c++
#include<iostream>
using namespace std;
#include<string>
void test01()
{
	string s1;//默认构造
	const char * str="hello world";
	string s2(str);
	cout<<"s2="<<s2<<endl;
    string s3(s2);
    cout<<"s3="<<s3<<endl;
    string s4(10,'a');
    cout<<"s4="s4<<endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
```

总结：string的多种构造方式没有可比性，灵活使用即可

#### 3.1.3 string赋值操作

功能描述：

- 给string字符串进行赋值

赋值的函数原型：

- string& operator=(const char* s); //char* 类型字符串 赋值给当前的字符串
- string& operator=(const string &s); //把字符串s赋给当前的字符串
- string& operator(char c);  //字符赋值给当前的字符串
- string& assign=(const char *s);  //把字符串s赋给当前的字符串
- string& assign=(const char *s,int n);//吧字符串s的前n个字符赋给当前的字符串
- string& assign=(const string &s); //把字符串s赋给当前字符串
- string& assign(int n,char c);//用n个字符c赋给当前字符串

```c++
#include<iostream>
using namespace std;
#include<string>

//string赋值操作
void test01()
{
   string str1;
   str1="hello world";
   cout<<"str1="<<str1<<endl;

   string str2;
   str2=str1;
   cout<<"str2="<<str2<<endl;

   string str3;
   str3='a';
   cout<<"str3="<<str3<<endl;

   string str4;
   str4.assign("hello C++");
   cout<<"str4="<<str4<<endl;

   string str5;
   str5.assign("hello C++",5);
   cout<<"str5="<<str5<<endl;

   string str6;
   str6.assign(str5);
   cout<<"str6="<<str6<<endl;

    string str7;
    str7.assign(10,'w');
    cout<<"str7="<<str7<<endl;
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 3.1.4 string字符串拼接

功能描述：

- 实现在字符串末尾拼接字符串

函数原型：

- string& operator+=(const char* str);     //重载+=操作符
- string& operator+=(const char c);    //重载+=操作符
- string& operator+=(const string& str);  //重载+=操作符
- string& append(const char *s); //把字符串s连接到当前字符串结尾
- string& append(const char *s,int n);//把字符串s的前n个字符串连接到当前字符串结尾
- string& append(const string &s);//同operator+=(const string & str)
- string &append(const string &s,int pos,int n);//字符串s中从pos开始的n个字符连接到字符串结尾

```c++
#include<iostream>
using namespace std;
#include<string>

//string赋值操作
void test01()
{
    string str1="我";
    str1+="爱玩游戏";
    cout<<str1<<endl;

    str1+=":";
    cout<<str1<<endl;
    string str2="LOL DNF";
    str1+=str2;
    cout<<str1<<endl;

    string str3="I";
    str3.append(" love ");
    cout<<str3<<endl;

    str3.append("game abcde",4);
    cout<<str3<<endl;

    str3.append(str2);
    cout<<str3<<endl;

    str3.append(str2,4,3);
    cout<<str3<<endl;
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 3.1.5 string查找和替换

功能描述：

- 查找：查找指定字符串是否存放
- 替换：在指定的位置替换字符串

函数原型：

- int find(const string& str,int pos=0) const;//查找str第一次出现文职，从pos开始查找
- int find(const char* s,int pos=0) const;//查找s第一次出现位置，从pos开始查找
- int find(const char*s,int pos,int n) const;//从pos位置查找s的前n个字符第一次位置
- int find(const char c,int pos=0) const;//查找字符c第一次出现位置
- int rfind(const string& str,int pos=npos) const;//查找str最后一次位置，从pos开始查找
- int rfind(const char* s,int pos=npos) const;//查找s最后一次出现位置，从pos开始查找
- int rfind(const char *s ,int pos,int n) const;//从pos查找s的前n个字符最后一次位置
- int rfind(const char c,int pos=0) const;//查找字符c最后一次出现位置
- string & replace(int pos,int n, const string& str);//替换从pos开始n个字符为字符串str
- string& replace(int pos,int n,const char*s);//替换从pos开始的n个字符为字符串s

示例：

```c++
#include<iostream>
using namespace std;
#include<string>

//字符串查找
void test01()
{
    string str1="abcdefg";
    int pos=str1.find("de");
    if(pos==-1)
    {
        cout<<"未找到字符串"<<endl;
    }else
    {
        cout<<"pos="<<pos<<endl;
    }
    //rfind
    //rfind从右往左查找  find从左往右查找
    pos=str1.rfind("de");
    cout<<"pos="<<pos<<endl;

}
void test02()
{
    string str1="abcdefg";
    //从1号位置起 3个字符 替换为“1111”
    str1.replace(1,3,"111");
    cout<<str1<<endl;
}
int main() {
    test02();
    system("pause");
    return 0;
}
```

总结：

- find查找是从左往后，rfind从右往左
- find找到字符串后返回查找的第一个字符位置，找不到返回-1
- replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串

#### 3.1.6 string字符串比较

功能描述：

- 字符串之间的比较

比较方式：

- 字符串比较是按字符的ASCII码进行对比

=返回  0

＞返回 1

< 返回 -1

函数原型：

- int compare(const string &s) const;//与字符串s比较
- int compare(const char *s) const;//与字符串s比较

```c++
#include<iostream>
using namespace std;
#include<string>
//字符串比较
void test01()
{
	string str1="hello";
	string str2="hello";
	if(str1.compare(str2)==0)
	{
		cout<<"str1等于str2"<<endl;
	}
	else if(str1.compare(str2)>0)
	{
		cout<<"str1大于str2"<<endl;
	}
	else
	{
		cout<<"str1小于str2"<<endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}
```

#### 3.1.7 string字符存取

string中单个字符存取方式有两种

- char& operator[](int n); //通过[]方式取字符
- char& at(int n);  //通过at方法获取字符

```c++
#include<iostream>
using namespace std;
#include<string>

//字符串查找
void test01()
{
    string str ="hello world";
    //通过[]访问单个字符
    for(int i=0;i<str.size();i++)
    {
        cout<<str[i]<<" ";
    }
    cout<<endl;
    //通过at方式访问单个字符
    for (int j = 0; j < str.size();j++) {
        cout<<str.at(j)<<" ";
    }
    cout<<endl;
    //修改单个字符
    str[0]='x';
    cout<<str<<endl;

    str.at(1)='x';
    cout<<str<<endl;
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 3.1.8 插入和删除

功能描述：

- 对string字符串进行插入和删除字符操作

函数原型：

- string& insert(int pos,const char* s);//插入字符串
- string& insert(int pos,const string& str)；//插入字符串
- string& insert(int pos,int n,char c);//在指定位置插入n个字符c
- string& erase(int pos,int n=nops);  //删除从pos开始的n个字符

```c++
#include<iostream>
using namespace std;
#include<string>

//string插入和删除
void test01()
{
    //插入
    string str="hello";
    str.insert(1,"111");
    cout<<str<<endl;
    //删除
    str.erase(1,3);
    cout<<str<<endl;
}

int main() {
    test01();
    system("pause");
    return 0;
} 
```

总结：插入和删除的起始下标都是从0开始

3.1.9 string子串

功能描述：

- 从字符串中获取想要的子串

函数原型：

- string substr(int pos=0;int n=npos) const; //返回由pos开始的n个字符组成的字符串

```c++
#include<iostream>
using namespace std;
#include<string>

//string求子串
void test01()
{
    string str="abcdef";
    string subStr=str.substr(1,3);
    cout<<"subStr="<<subStr<<endl;
}
//使用操作
void test02()
{
    string email="lishi@sina.com";
    //从邮件地址中获取用户名信息
    int pos=email.find("@");
    cout<<pos<<endl;
    string usrName=email.substr(0,pos);
    cout<<usrName<<endl;
}
int main() {
    test02();
    system("pause");
    return 0;
}
```

总结：灵活的运用求子串功能，可以在实际开发中获取有效的信息

### 3.2 vector容器

#### 3.2.1 vector基本概念

功能：

- vector数据结构和数组非常相似，也称为单端数组

vector与普通数组区别：

- 不同之处在与数组是静态空间，而vector可以动态扩展

动态扩展：

- 并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间
- vector容器的迭代器是支持随机访问的迭代器

#### 3.2.2 vector构造函数

功能描述：

- 创建vector容器

函数原理：

- vector< T >  v;  //采用模板实现类实现，默认构造函数
- vector(v.begin(),v.end()); //将v[begin(),end()]区间中的元素拷贝给本身
- vector(n,elem);   //构造函数将n个elem拷贝给本身
- vector(const vector &vec);  //拷贝构造函数

示例：

```c++
#include<iostream>
using namespace std;
#include<string>
#include <vector>
//vector容器构造

void printVactor(vector<int>&v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    vector<int>v1;//默认构造，无参构造
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    printVactor(v1);

    //通过区间方式进行构造
    vector<int>v2(v1.begin(),v1.end());
    printVactor(v2);

    //n个elem方式构造
    vector<int>v3(10,100);
    printVactor(v3);

    //拷贝构造
    vector<int>v4(v3);
    printVactor(v4);
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：vector的多种构造方式没有可比性，灵活使用即可

#### 3.2.3 vector赋值操作

功能描述：

- 给vector容器进行赋值

函数原型：

- vector& operator=(const vector &vec);//重载等号操作符
- assign(beg,end);  //将[beg,end]区间中的数据拷贝赋值给本身
- assign(n,elem);  //将n个elem拷贝赋值给本身

示例：

```c++
#include<iostream>
using namespace std;
#include<string>
#include <vector>
//vector赋值

void printVactor(vector<int>&v)
{
   for(vector<int>::iterator it=v.begin();it!=v.end();it++)
   {
       cout<<*it<<" ";
   }
   cout<<endl;
}
void test01()
{
   vector<int>v1;
   for(int i=0;i<10;i++)
   {
       v1.push_back(i);
   }
   printVactor(v1);

   //赋值 operator=
   vector <int>v2;
   v2=v1;
   printVactor(v2);
   // assign
   vector<int> v3;
   v3.assign(v1.begin(),v1.end());
   printVactor(v3);

   //n个elem方式赋值
   vector<int> v4;
   v4.assign(10,100);
   printVactor(v4);
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 3.2.4 vector容量和大小

功能描述：

- 对vector容器的容量和大小操作

函数原型：

- empty();  //判断容器是否为空
- capacity(); //容器容量
- size();//放回容器中元素的个数
- resize(int num);//重新制定容器的长度为num,若容器编程，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除
- resize(int num,elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除

示例：

```c++
#include<iostream>
using namespace std;
#include<string>
#include <vector>
//vector容量和大小

void printVactor(vector<int>&v)
{
   for(vector<int>::iterator it=v.begin();it!=v.end();it++)
   {
       cout<<*it<<" ";
   }
   cout<<endl;
}
void test01()
{
   vector<int>v1;
   for(int i=0;i<10;i++)
   {
       v1.push_back(i);
   }
   printVactor(v1);
   if(v1.empty()) //为真  代表容器为空
   {
       cout<<"v1为空"<<endl;
   }
   else
   {
       cout<<"v1不为空"<<endl;
       cout<<"v1的容量为："<<v1.capacity()<<endl;
       cout<<"v1的大小为："<<v1.size()<<endl;
   }
   //重新指定大小
//   v1.resize(15);
//   printVactor(v1);
   v1.resize(15,10);
   printVactor(v1);
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 3.2.5 vector插入和删除

功能描述：

- 对vector容器进行插入，删除操作

函数原理：

- push_back(ele);//尾部插入元素ele
- pop_back();//删除最后一个元素
- insert(const_iterator pos,ele);//迭代器指向位置pos插入count个元素ele
- insert(const_iterator pos,int count,ele);//迭代器指向位置pos插入count个元素ele
- erase(const_iterator pos);//删除迭代器指向元素
- erase(const_iterator start,const_iterator end);//删除迭代器从start到end之间的元素
- clear();//删除容器中所有元素

示例：

```c++
#include<iostream>
using namespace std;
#include<string>
#include <vector>
//vector插入和删除

void printVactor(vector<int>&v)
{
   for(vector<int>::iterator it=v.begin();it!=v.end();it++)
   {
       cout<<*it<<" ";
   }
   cout<<endl;
}
void test01()
{
   vector<int>v1;
   //尾插法
   v1.push_back(10);
   v1.push_back(20);
   v1.push_back(30);
   v1.push_back(40);
   printVactor(v1);
   //尾删
   v1.pop_back();
   printVactor(v1);
   //插入  第一个参数是迭代器
   v1.insert(v1.begin(),100);
   printVactor(v1);

   v1.insert(v1.begin(),2,1000);
   printVactor(v1);
   //删除 参数也是迭代器
   v1.erase(v1.begin());
   printVactor(v1);
   v1.erase(v1.begin(),v1.end());
   printVactor(v1);
   //清空
   v1.clear();
   printVactor(v1);
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：

- 尾插---push_back
- 尾删---pop_back
- 插入---insert （位置迭代器）
- 删除---erase （位置迭代器）
- 清空---clear

#### 3.2.6 vector数据存取

功能描述：

- 对vector中的数据的存取操作

函数原型：

- at(int idx);//返回索引idx所指的数据
- operator[];//返回容器中第一个数据元素
- front();//返回容器中第一个数据元素
- back();//返回容器中最后一个数据元素

示例：

```c++
#include<iostream>
using namespace std;
#include<string>
#include <vector>
//vector容器 数据存取
void test01()
{
   vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    //利用[]方式访问数组中的元素
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    //利用at方式访问元素
    for (int i = 0; i <v1.size() ; i++) {
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;
    //获取第一个元素
    cout<<"第一个元素为："<<v1.front()<<endl;

    //获取最后一个元素
    cout<<"最后一个元素为："<<v1.back()<<endl;
}

int main() {
    test01();
    system("pause");
    return 0;
}#include<iostream>
using namespace std;
#include<string>
#include <vector>
//vector容器 数据存取
void test01()
{
   vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    //利用[]方式访问数组中的元素
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    //利用at方式访问元素
    for (int i = 0; i <v1.size() ; i++) {
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;
    //获取第一个元素
    cout<<"第一个元素为："<<v1.front()<<endl;

    //获取最后一个元素
    cout<<"最后一个元素为："<<v1.back()<<endl;
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：

- 除了用迭代器获取vector容器中元素，[]和at也可以
- front返回容器第一个元素
- back返回容器最后一个元素

#### 3.2.7 vector互换容器

功能描述：

- 实现两个容器内元素进行互换

函数原型：

- swap(vec);//将vec与本身的元素互换

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
//vector容器 互换
void printVector(vector<int>& v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
   vector<int>v1;
    for (int i = 0; i <10 ; i++) {
        v1.push_back(i);
    }
    cout<<"交换前："<<endl;
    printVector(v1);
    vector<int> v2;
    for (int j = 10; j >0 ; j--) {
        v2.push_back(j);
    }
    printVector(v2);

    cout<<"交换后:"<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);

}
//实际用途
//巧用swap可以收缩内存空间
void test02()
{
    vector<int> v;
    for (int i = 0; i <100000; i++) {
        v.push_back(i);
    }
    cout<<"v的容量为："<<v.capacity()<<endl;
    cout<<"v的大小为："<<v.size()<<endl;
    v.resize(3);//重新指定大小
    cout<<"v的容量为："<<v.capacity()<<endl;
    cout<<"v的大小为："<<v.size()<<endl;

    //巧用swap收缩内存
    vector<int>(v).swap(v);
    cout<<"v的容量为："<<v.capacity()<<endl;
    cout<<"v的大小为："<<v.size()<<endl;
}
int main() {
    //test01();
    test02();
    system("pause");
    return 0;
}
```

总结：swap可以使用两个容器互换后，达到一种实用的收缩内存效果

#### 3.2.8 vector预留空间

功能描述：

- 减少vector在动态扩展容量时的扩展次数

函数原理：

- reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可以访问

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
//vector容器 预留空间
void printVector(vector<int>& v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
   vector<int>v1;
   //利用reserve预留空间
   v1.reserve(10000);
   int num=0;//统计开辟次数
   int * p=NULL;
    for (int i = 0; i <100000 ; i++) {
        v1.push_back(i);
        if(p!=&v1[0])
        {
            p=&v1[0];
            num++;
        }
    }
    cout<<"num="<<num<<endl;
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：如果数量较大 可以一开始利用reserve预留空间

### 3.3  deque容器

#### 3.3.1 deque容器基本概念

功能：

- 双端数组，可以对头端进行插入删除操作

deque与vector区别

- vector对于头部的插入删除效率低，数据量越大，效率越低
- deque相对而言，对头部的插入删除速度回比vector快
- vector访问元素时的速度会比deque快，这和两者内部实现有关

deque内部工作原理：

deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据

中控器维护的是每个缓冲区的地址，是的使用deque时像一片连续的内存空间

deque容器的迭代器也是支持随机访问的

#### 3.3.2 deque构造函数

功能描述：

- deque容器构造

函数原型：

- deque< T > deq; //默认构造形式
- deque(beg,end); //构造函数将[beg,end]区间中的元素拷贝给本身
- deque(n,elem);//构造函数将n个elem拷贝给本身
- deque(const deque &deq)； //拷贝构造函数

示例：

```c++
#include<iostream>
using namespace std;
#include <deque>
//deque容器 预留空间
void printDeque(deque<int>& d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    deque<int> d1;
    for (int i = 0; i <10; i++) {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int>d2(d1.begin(),d1.end());
    printDeque(d2);

    deque<int> d3(10,100);
    printDeque(d3);
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：deque容器和vector容器的构造方式几乎一致，灵活使用即可

#### 3.3.3 deque赋值操作

功能描述：

- 给deque容器进行赋值

函数原型：

- deque& operator=const deque &deq;//重载等号操作符
- assign(beg,end)；//将[beg,end]区间中的数据拷贝赋值给本身
- assign(n,elem); //将n个elem拷贝赋值给本身

示例：

```c++
#include<iostream>
using namespace std;
#include <deque>
//deque容器 赋值操作
void printDeque(const deque<int>& d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    deque<int> d1;
    for (int i = 0; i <10; i++) {
        d1.push_back(i);
    }
    printDeque(d1);
    //operator=赋值
    deque<int>d2;
    d2=d1;
    printDeque(d2);
    //assign赋值
    deque<int>d3;
    d3.assign(d1.begin(),d1.end());
    printDeque(d3);

    deque<int> d4;
    d4.assign(10,100);
    printDeque(d4);
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

#### 3.3.4 deque大小操作

功能描述：

- 对deque容器的大小进行操作

函数原型：

- deque.empty();  //判断容器是否为空
- deque.size();//返回容器中元素的个数
- deque.resize(num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除
- deque.resize(num,elem)；//重新指定容器的长度为num，r若容器变长，则以elem值填充新位置，如果容器变短，则末尾超出容器长度的元素被删除。

示例：

```c++
#include<iostream>
using namespace std;
#include <deque>
//deque容器 大小操作
void printDeque(const deque<int>& d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    deque<int> d1;
    for (int i = 0; i <10; i++) {
        d1.push_back(i);
    }
    printDeque(d1);
   if(d1.empty())
   {
       cout<<"d1为空"<<endl;
   }
   else
   {
       cout<<"d1不为空"<<endl;
       cout<<"d1的大小为："<<d1.size()<<endl;
       //deque容器没有容器概念
   }
   d1.resize(15);
   printDeque(d1);
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：

- deque没有容量的概念
- 判断是否为空 ---empty
- 返回元素个数 ---size
- 重新指定个数 ---resize

#### 3.3.5 deque插入和删除

功能描述：

- 向deque容器中插入和删除数据

函数原型：

两端插入操作：

- push_back(elem);//在容器尾部添加一个数据
- push_front(elem);//在容器头部插入一个数据
- pop_back();//删除容器最后一个数据
- pop_front();//删除容器第一个数据

指定位置操作：

- insert(pos,elem)；//在pos位置插入一个elem元素的拷贝，返回新数据的位置
- insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值
- insert(pos,beg,end);//在pos位置插入[beg，end]区间的数据，无返回值，
- clear();//清空容器的所有数据
- erase(beg,end);//删除[beg,end]区间的数据，返回下一个数据的位置。
- erase(pos)；//删除pos位置的数据，返回下一个数据的位置

```c++
#include<iostream>
using namespace std;
#include <deque>
//deque容器 大小操作
void printDeque(const deque<int>& d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    deque<int> d1;
    //尾插
    d1.push_back(10);
    d1.push_back(20);
    //头插
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    //尾删
    d1.pop_back();
    printDeque(d1);
    //头删
    d1.pop_front();
    printDeque(d1);
}
void test02()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);
    //insert插入
    d1.insert(d1.begin(),1000);
    printDeque(d1);

    d1.insert(d1.begin(),2,10000);
    printDeque(d1);
    //按照区间进行插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d1.insert(d1.begin(),d2.begin(),d2.end());
    printDeque(d1);
}
void test03()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    deque<int>::iterator it=d1.begin();
    it++;
    d1.erase(it);
    printDeque(d1);
    d1.erase(d1.begin());
    printDeque(d1);
    d1.erase(d1.begin(),d1.end());
    printDeque(d1);
}
int main() {
    test03();
    system("pause");
    return 0;
}
```

总结：

- 插入和删除提供位置是迭代器
- 尾插---push_back
- 尾删---pop_back
- 头插---push_front
- 头删---pop_front

#### 3.3.6 deque数据存取

功能描述：

- 对deque中的数据的存取操作

函数原型：

- at(int idx);//返回索引idx所指的数据
- operator[];//返回索引idx所指的数据
- front();//返回容器中第一个数据元素
- back();//返回容器中最后一个数据元素

```c++
#include<iostream>
using namespace std;
#include <deque>

void test01()
{
    deque<int> d1;
    //尾插
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    //头插
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
   //通过[]方式访问元素
    for (int i = 0; i <d1.size() ; i++) {
        cout<<d1[i]<<" ";
    }
    cout<<endl;
    //通过at方式访问元素
    for (int j = 0; j <d1.size() ; j++) {
        cout<<d1.at(j)<<" ";
    }
    cout<<endl;
    cout<<"第一个元素为："<<d1.front()<<endl;
    cout<<"最后一个元素："<<d1.back()<<endl;
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：

- 除了用迭代器获取deque容器中元素，[]和at也可以
- front返回容器第一个元素
- back返回容器最后一个元素

#### 3.3.7 deque排序

功能描述：

- 利用算法实现对deque容器进行排序

算法：

- sort(iterator beg,iterator end);//对beg和end区间内元素进行排序

示例：

```c++
#include<iostream>
using namespace std;
#include <deque>
#include <algorithm> //标准算法头文件

void printDeque(const deque<int>&d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    deque<int> d1;
    //尾插
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    //头插
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
    printDeque(d1);
    //排序 默认排序规则  从小到大  升序
    //对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
    //vector容器也可以利用sort进行排序
    sort(d1.begin(),d1.end());
    cout<<"排序后："<<endl;
    printDeque(d1);
}

int main() {
    test01();
    system("pause");
    return 0;
}
```

总结：sort算法非常实用，使用是包含头文件algorithm即可

### 3.4 案例-评委打分

#### 3.4.1 案例描述

有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

#### 3.4.2 实现步骤

1.创建五名选手，放到vector中

2.遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中

3.sort算法对deque容器找那个分数排序，去除最高分和最低分

4.deque容器遍历一遍，累加总分

5.获取平均分

**代码：**

```c++
#include<iostream>
using namespace std;
#include <deque>
#include <algorithm> //标准算法头文件
#include <vector>
#include <string>
#include <ctime>
class Person
{
public:
    Person(string name,int score)
    {
        this->m_Name=name;
        this->m_Score=score;
    }
    string m_Name;
    int m_Score;
};
void createPerson(vector<Person>&v)
{
    string nameSeed="ABCDE";
    for(int i=0;i<5;i++)
    {
        string name="选手";
        name+=nameSeed[i];
        int score=0;
        Person p(name,score);
        //将创建的person对象 放入到容器中
        v.push_back(p);
    }
}
//打分
void setScore(vector<Person>&v)
{
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        //将评委分数 防暑到deque容器中
        deque<int> d;
        for(int i=0;i<10;i++)
        {
            int score=rand()%41+60; //60~100
            d.push_back(score);
        }
        //排序
        sort(d.begin(),d.end());
        //去除最高和最低
        d.pop_back();
        d.pop_front();
        //取平均分
        int sum=0;
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
        {
            sum+=*dit;  //累加每个评委的分数
        }
        int avg=sum/d.size();
        //将平均分  赋值给选手身上
        it->m_Score=avg;
    }
}
void showScore(vector<Person>&v)
{
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"姓名："<<it->m_Name<<" 平均分："<<it->m_Score<<endl;
    }
}
int main() {
    //随机数种子
    srand((unsigned int)time(NULL));
    //1.创建5名选手
    vector<Person> v;
    createPerson(v);
    //2.给5名选手打分
    setScore(v);
    //3.显示最后得分
    showScore(v);
    system("pause");
    return 0;
}
```

### 3.5 stack容器

#### 3.5.1 stack基本概念

概念：stack是一种先进后出(First In Last Out,FILO)的数据结构，他只有一个出口

![img](https://img-blog.csdnimg.cn/20201003113402497.png?type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxMzYzNDU5,size_16,color_FFFFFF,t_70#pic_center)

栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为

栈中进入数据称为---入栈push

栈中弹出数据称为---出栈pop

#### 3.5.2 stack常用接口

功能描述：栈容器常用的对外接口

构造函数：

- stack< T > stk;  //stack采用模板类实现，stack对象的默认构造形式
- stack(const stack &stk);  //拷贝构造函数

赋值操作：

- stack& operator=(const stack &stk); //重载等号操作符

数据存取：

- push(elem); //向栈顶添加元素
- pop();  //从栈顶移除第一个元素
- top();   //返回栈顶元素

大小操作：

- empty()  //判断堆栈是否为空
- size();   //返回栈的大小

```c++
#include<iostream>
using namespace std;
#include <stack>
//栈stack容器
void test01()
{
    //特点：符合先进后出数据结构
    stack<int> s;
    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<"栈的大小："<<s.size()<<endl;
    //只要栈不为空，查看栈顶，并且执行出栈操作
    while(!s.empty())
    {
        //查看栈顶元素
        cout<<"栈顶元素为："<<s.top()<<endl;
        //出栈
        s.pop();
    }
    cout<<"栈的大小："<<s.size()<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
```

总结：

- 入栈 ---push
- 出栈 ---pop
- 返回栈顶 ---top
- 判断栈是否为空 ---empty
- 返回栈大小  ---size

### 3.6 queue容器

#### 3.6.1 queue基本概念

概念：Queue是一种先进先出(First In First Out,FIFO)的数据结构，它有两个出口

![在这里插入图片描述](https://www.pianshen.com/images/584/be4ca349da8abde1396f0b4d67b81a30.png)

队列容器允许从一端新增元素，从另一端移除元素

队列中只有对头和队尾才可以被外界使用，因此队列不允许有遍历行为

队列中进数据称为---入队 push

队列中出数据称为---出队 pop

#### 3.6.2 queue常用接口

功能描述：栈容器常用的对外接口

构造函数：

- queue< T > que;  //queue采用模板类实现，queue对象的默认构造形式
- queue(const queue &que);  //拷贝构造函数

赋值操作：

- queue& operator=(const queue &que); //重载等号操作符

数据存取：

- push(elem);  //往队尾添加元素
- pop();   //从对头移除第一个元素
- back();  //返回最后一个元素
- front();  //返回第一个元素

大小操作：

- empty();  //判断堆栈是否为空
- size();  //返回栈的大小

```c++
#include<iostream>
using namespace std;
#include <queue>
#include <string>
//队列 queue
class Person
{
public:
    Person(string name,int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    string m_Name;
    int m_Age;
};
void test01()
{
    //创建队列
   queue<Person> q;
    //准备数据
    Person p1("张三",23);
    Person p2("李四",24);
    Person p3("王五",25);
    Person p4("赵六",26);
    //入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    cout<<"队列大小为："<<q.size()<<endl;
    //判断只要队列不为空，查看队头，查看队尾，出队
    while(!q.empty())
    {
        //查看队头
        cout<<"对头元素：---姓名："<<q.front().m_Name<<" 年龄："<<q.front().m_Age<<endl;
        //查看队尾
        cout<<"对尾元素：---姓名："<<q.back().m_Name<<" 年龄："<<q.back().m_Age<<endl;
        
        q.pop();
    }

    cout<<"队列大小为："<<q.size()<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
```

总结：

- 入队 ---push
- 出队 ---pop
- 返回对头元素 ---front
- 返回队尾元素 ---back
- 判断队是否为空 ---empty
- 返回队列大小  ---size

### 3.7 list容器

#### 3.7.1 list基本概念

功能：将数据进行链式存储

链表：list是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表实现的

链表的组成：链表由一系列结点组成

结点的组成：一个时存储数据元素的数据域，另一个是存储下一个结点地址的指针域

STL中的链表是一个双向循环链表

![img](https://img2018.cnblogs.com/blog/1503449/201812/1503449-20181209153509704-404225537.png)

由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器

list优点：

- 采用动态存储分配，不会造成内存浪费和溢出
- 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素

list的缺点：

- 链表灵活，但是空间(指针域)和时间(变量)额外耗费较大

list有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的

总结：STL中List和vector是两个最常被使用的容器，各有优缺点

#### 3.7.2 list构造函数

功能描述：

- 创建list容器

函数原型：

- list< T > lst; //list采用模板类实现，对象的默认构造形式
- list(beg,end);//构造函数将[beg,end]区间中的元素拷贝给本身
- list(n,elem);//构造函数将n个elem拷贝给本身
- list(const list &lst); //拷贝构造函数。

示例：

```c++
#include<iostream>
using namespace std;
#include<list>

void printList(const list<int>& l)
{
	for(list<int>::const_iterator it=l.begin();it!=l.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
//list容器构造函数
void test01()
{
	//创建list容器
	list<int> l1;//默认构造
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);
	//区间方式构造
	list<int> l2(l1.begin(),l1.end());
	printList(l2);
	//拷贝构造
	list<int>l3(l2);
	printList(l3);
	//n个elem
	list<int> l4(10,1000);
	printList(l4);
}
int main(){
	test01();
	system("pause");
	return 0;
}
```

总结：list构造方式同其他几个STL常用容器，熟悉掌握即可

#### 3.7.3 list赋值交换

功能描述：

- 给list容器进行赋值，以及交换list容器

函数原型：

- assign(beg,end);  //将[beg,end]区间中的数据拷贝赋值给本身
- assign(n,elem);//将n个elem拷贝赋值给本身
- list& operator=(const list &lst);  //重载符号操作符
- swap(lst);  //将lst与本身的元素互换

示例：

```c++
#include<iostream>
using namespace std;
#include<list>

void printList(const list<int>& l)
{
    for(list<int>::const_iterator it=l.begin();it!=l.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    //创建list容器
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);

    list<int> l2;
    l2=l1;
    printList(l2);

    list<int> l3;
    l3.assign(l2.begin(),l2.end());
    printList(l3);

    list<int> l4;
    l4.assign(10,100);
    printList(l4);

}
//交换
void test02()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    list<int> l2;
    l2.assign(10,100);
    cout<<"交换前："<<endl;
    printList(l1);
    printList(l2);

    l1.swap(l2);
    cout<<"交换后"<<endl;
    printList(l1);
    printList(l2);

}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
```

总结：list赋值和交换操作能够灵活运用即可

#### 3.7.4 list大小操作

功能描述：

- 对list容器的大小进行操作

函数原型：

- size();  //返回容器中元素的个数
- empty();  //判断容器是否为空
- resize(num)；//重新指定容器的长度为num,若容器变成，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除
- resize(num,elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾查出容器长度的元素被删除

```c++
#include<iostream>
using namespace std;
#include<list>

void printList(const list<int>& l)
{
    for(list<int>::const_iterator it=l.begin();it!=l.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    //创建list容器
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);
    //判断容器是否为空
    if(l1.empty())
    {
        cout<<"l1为空"<<endl;
    }
    else
    {
        cout<<"l1不为空"<<endl;
        cout<<"l1元素个数为："<<l1.size()<<endl;
    }
    //重新指定大小
//    l1.resize(10);
//    printList(l1);

    l1.resize(10,100);
    printList(l1);

}

int main(){
    test01();
    system("pause");
    return 0;
}
```

#### 3.7.5 list插入和删除

功能描述：

- 对list容器进行数据的插入和删除

函数原型：

- push_back(elem);//在容器尾部加入一个元素
- pop_back();//删除容器中最后一个元素
- push_front(elem);//在容器开头插入一个元素
- pop_front();//从容器开头移除第一个元素
- insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置
- insert(pos,beg,end);//在pos位置插入[beg,end]区间的数据，无返回值。
- clear();//移除容器的所有数据
- erase(beg,end)；//删除[beg,end]区间的数据，返回下一个数据的位置
- erase(pos);//删除pos位置的数据，返回一亿个数据的位置
- remove(elem);//删除容器中所有与elem值匹配的元素

```c++
#include<iostream>
using namespace std;
#include <list>
//deque容器 大小操作
void printDeque(const list<int>& d)
{
    for(list<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    list<int> l1;
    //尾插
    l1.push_back(10);
    l1.push_back(20);
    //头插
    l1.push_front(100);
    l1.push_front(200);
    printDeque(l1);

    //尾删
    l1.pop_back();
    printDeque(l1);
    //头删
    l1.pop_front();
    printDeque(l1);
}
void test02()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_front(100);
    l1.push_front(200);
    printDeque(l1);
    //insert插入
    l1.insert(l1.begin(),1000);
    printDeque(l1);

    l1.insert(l1.begin(),2,10000);
    printDeque(l1);
    //按照区间进行插入
    list<int> l2;
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
    l1.insert(l1.begin(),l2.begin(),l2.end());
    printDeque(l1);
}
void test03()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_front(100);
    l1.push_front(200);
    list<int>::iterator it=l1.begin();
    it++;
    l1.erase(it);
    printDeque(l1);
    l1.erase(l1.begin());
    printDeque(l1);
    l1.erase(l1.begin(),l1.end());
    printDeque(l1);
}
int main() {
    test03();
    system("pause");
    return 0;
}
```

总结：

- 尾插 ---push_back
- 尾删 ---pop_back
- 头插 ---push_front
- 头删 ---pop_front
- 插入 ---insert
- 删除 ---erase
- 移除 ---remove
- 清空 ---clear

#### 3.7.6 list数据存取

功能描述：

- 对list容器中数据进行存取

函数原型：

- front();   //返回第一个元素
- back();    //返回最后一个元素

```c++
#include<iostream>
using namespace std;
#include<list>

void printList(const list<int>& l)
{
    for(list<int>::const_iterator it=l.begin();it!=l.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    //创建list容器
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    //l1[0] 不可以用[]访问list容器中的元素
    //l1.at(0)  不可以用at方式访问list容器中的元素
    //原因是list本质链表，不是用连续性空间存储数据，迭代器也是不支持随机访问的
    cout<<"第一个元素为："<<l1.front()<<endl;
    cout<<"最后一个元素为："<<l1.back()<<endl;
//    printList(l1);
    //验证迭代器是不支持随机访问的
    list<int>::iterator it =l1.begin();
    it++;//支持双向
    it--;
//    it=it+1; //不支持随机访问

}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：

- list容器中**不可以通过[]或者at方式**访问数据
- 返回第一个元素  ---front
- 返回最后一个元素  ---back

#### 3.7.7 list反转和排序

功能描述：

- 将容器中的元素反转，以及将容器中的数据进行排序

函数原型：

- reverse();//反转链表
- sort();  //链表排序

示例：

```c++
#include<iostream>
using namespace std;
#include<list>

void printList(const list<int>& l)
{
    for(list<int>::const_iterator it=l.begin();it!=l.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
bool myCompare(int v1,int v2)
{
    return v1>v2;
}
void test01()
{
    //创建list容器
    list<int> l1;
    l1.push_back(30);
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(50);
    l1.push_back(40);
    cout<<"反转前："<<endl;
    printList(l1);
    //反转
    l1.reverse();
    cout<<"反转后："<<endl;
    printList(l1);

    //排序
    cout<<"排序前："<<endl;
    printList(l1);
    //反转
    //所有不支持随机访问迭代器的容器，不可以用标准算法
    //不支持随机访问迭代器的容器，内部会提供对应一些算法
//    sort(l1.begin(),l1.end());
    l1.sort();
    cout<<"排序后："<<endl;
    printList(l1);

    l1.sort(myCompare);
    printList(l1);
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

#### 3.7.8 排序案例

案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高。

排序规则：按照年龄进行升序排序，如果年龄相同按照身高进行降序

代码：

```c++
#include<iostream>
using namespace std;
#include<list>
#include <string>
class Person{
public:
    Person(string name,int age,int height)
    {
        this->m_Name=name;
        this->m_Age=age;
        this->m_Height=height;
    }
    string m_Name;
    int m_Age;
    int m_Height;
};
bool comparePerson(Person &p1,Person &p2)
{
    //如果年龄相同 按身高排序
    if(p1.m_Age==p2.m_Age)
    {
        return p1.m_Height>p2.m_Height;
    }
    //按年龄 升序
    return p1.m_Age<p2.m_Age;
}
void test01()
{
    list<Person> list1;
    Person p1("刘备",35,175);
    Person p2("孙权",30,165);
    Person p3("曹操",35,170);
    Person p4("关羽",34,195);
    Person p5("刘备",33,185);
    //插入数据
    list1.push_back(p1);
    list1.push_back(p2);
    list1.push_back(p3);
    list1.push_back(p4);
    list1.push_back(p5);
    cout<<"排序前："<<endl;
    for(list<Person>::iterator it=list1.begin();it!=list1.end();it++)
    {
        cout<<"姓名："<<(*it).m_Name<<" 年龄："<<it->m_Age<<" 身高："<<it->m_Height<<endl;
    }
    //排序
    cout<<"---------------------------------"<<endl;
    cout<<"排序后："<<endl;
    list1.sort(comparePerson);
    for(list<Person>::iterator it=list1.begin();it!=list1.end();it++)
    {
        cout<<"姓名："<<(*it).m_Name<<" 年龄："<<it->m_Age<<" 身高："<<it->m_Height<<endl;
    }
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：

- 对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
- 高级排序只是在排序规则上在进行一次逻辑规则制定，并不复杂

### 3.8 set/multiset容器

#### 3.8.1 set基本概念

简介：

- 所有元素都会在插入时自动被排序

本质：

- set/multiset属于关联式容器，底层结构是用二叉树实现

set和multiset区别：

- set不允许容器中有重复的元素
- multiset允许容器中有重复的元素

#### 3.8.2 set构造和赋值

功能描述：创建set容器以及赋值

构造：

- set< T > st;   //默认构造函数；
- set(const set &st);  //拷贝构造函数

赋值：

- set& operator=(const set &st);  //重载等号操作符

示例：

```c++
#include<iostream>
using namespace std;
#include<set>
#include <string>

void printSet(set<int> & st)
{
    for(set<int>::iterator it=st.begin();it!=st.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    set<int> st1;
    //插入数据 只有insert方式
    st1.insert(10);
    st1.insert(20);
    st1.insert(30);
    st1.insert(40);
    //set容器特点：所有元素插入时候自动被排序
    //set容器不允许插入重复值
    printSet(st1);
    //拷贝构造
    set<int> st2(st1);
    printSet(st2);
    //赋值
    set<int>st3;
    st3=st2;
    printSet(st3);

}

int main(){
    test01();
    system("pause");
    return 0;
}
```

#### 3.8.3 set大小和交换

功能描述：

- 统计set容器大小以及交换set容器

函数原型：

- size();  //返回容器中元素的数目
- empty(); //判断容器是否为空
- swap(st);  //交换两个集合容器

```c++
#include<iostream>
using namespace std;
#include<set>
#include <string>

void printSet(set<int> & st)
{
    for(set<int>::iterator it=st.begin();it!=st.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    set<int> st1;
    //插入数据 只有insert方式
    st1.insert(10);
    st1.insert(20);
    st1.insert(30);
    st1.insert(40);

    //判断是否为空
    if(st1.empty())
    {
        cout<<"st1为空"<<endl;
    }
    else
    {
        cout<<"st1不为空"<<endl;
        cout<<"st1的大小为："<<st1.size()<<endl;
    }
    set<int> st2;
    //插入数据 只有insert方式
    st2.insert(100);
    st2.insert(200);
    st2.insert(300);
    st2.insert(400);
    cout<<"交换前："<<endl;
    printSet(st2);
    cout<<"交换后："<<endl;
    st1.swap(st2);
    printSet(st2);
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：

- 统计大小 --- size
- 判断是否为空 ---empty
- 交换容器 ---swap

#### 3.8.4 set插入和删除

功能描述：

- set容器进行插入数据和删除数据

函数原型：

- insert(elem);  //在容器中插入元素
- clear();  //清除所有元素
- erase(pos);  //删除pos迭代器所指的元素，返回下一个元素的迭代器
- earse(beg,end);//删除区间[beg,end]的所有元素，返回下一个元素的迭代器，
- erase(elem);  //删除容器中值为elem的元素

示例：

```c++
#include<iostream>
using namespace std;
#include<set>
#include <string>

void printSet(set<int> & st)
{
    for(set<int>::iterator it=st.begin();it!=st.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    set<int> st1;
    //插入数据 只有insert方式
    st1.insert(20);
    st1.insert(10);
    st1.insert(30);
    st1.insert(40);

    printSet(st1);

    //删除
    st1.erase(st1.begin());
    printSet(st1);
    //删除重载版本
    st1.erase(30);
    printSet(st1);
    //清空
    st1.erase(st1.begin(),st1.end());
    st1.clear();
    printSet(st1);
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：

- 插入  ---insert
- 删除  ---erase
- 清空  ---clear

#### 3.8.5 set查找和统计

功能描述：

- 对set容器进行查找数据以及统计数据

函数原型：

- find(key);  //查找key是否存在，若存在，返回该键的元素的迭代器；若不存在返回set.end();
- count(key);   //统计key的元素个数

示例：

```c++
#include<iostream>
using namespace std;
#include<set>
#include <string>

void printSet(set<int> & st)
{
    for(set<int>::iterator it=st.begin();it!=st.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    set<int> st1;
    //插入数据 只有insert方式
    st1.insert(10);
    st1.insert(20);
    st1.insert(30);
    st1.insert(40);

    set<int>::iterator pos=st1.find(30);
    if(pos!=st1.end())
    {
        cout<<"找到元素："<<*pos<<endl;
    }
    else
    {
        cout<<"未找到元素"<<endl;
    }

}
void test02()
{
    set<int> st1;
    //插入数据 只有insert方式
    st1.insert(10);
    st1.insert(20);
    st1.insert(30);
    st1.insert(40);
    st1.insert(30);
    st1.insert(30);
    int num=st1.count(30);
    //对于set而言 统计结果 要么是0 要么为1
    cout<<"num="<<num<<endl;
}
int main(){
    test02();
    system("pause");
    return 0;
}
```

3.8.6 set和multiset区别

学习mubiao：

- 掌握set和multiset的区别

区别：

- set不可以插入重复数据，而multiset可以
- set插入数据的同时会返回插入结果，表示插入是否成功
- multiset不会检测数据，因此可以插入重复数据

示例：

```c++
#include<iostream>
using namespace std;
#include<set>
#include <string>

void test01()
{
    set<int> s;
    pair<set<int>::iterator,bool> ret=s.insert(10);
    if(ret.second)
    {
        cout<<"第一次插入成功"<<endl;
    }
    else
    {
        cout<<"第一次插入失败"<<endl;
    }
    ret=s.insert(10);
    if(ret.second)
    {
        cout<<"第二次插入成功"<<endl;
    }
    else
    {
        cout<<"第二次插入失败"<<endl;
    }
    multiset<int> ms;
    //允许插入重复值
    ms.insert(10);
    ms.insert(10);
    for (multiset<int>::iterator it=ms.begin();it!=ms.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：

- 如果不允许插入重复数据可以利用set
- 如果需要插入重复数据利用multiset

#### 3.8.7 pair对组创建

功能描述：

- 成对出现的数据，利用对组可以返回两个数据

两种创建方式：

- pair< type ,type> p(value1,value2);
- pair< type,type > p=make_pair(value1,value2);

示例：

```c++
#include<iostream>
using namespace std;
#include<set>
#include <string>

void test01()
{
    pair<string,int> p(string("Tom"),20);
    cout<<"姓名："<<p.first<<" 年龄："<<p.second<<endl;

    pair<string,int> p2=make_pair("Jerry",10);
    cout<<"姓名："<<p.first<<" 年龄："<<p.second<<endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

#### 3.8.8 set容器排序

学习目标：

- set容器默认排序规则为从小到大，掌握如何改变排序规则

主要技术点：

- 利用仿函数，可以改变排序规则

示例一  set存放内置数据类型

```c++
#include<iostream>
using namespace std;
#include<set>
#include <string>

class MyCompare
{
public:
    bool operator()(int v1,int v2){
        return v1>v2;//指定按照降序
    }
};
void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(50);
    s1.insert(30);
    for(set<int>::iterator it=s1.begin();it!=s1.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //指定排序规则为从到小
    set<int,MyCompare> s2;
    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(50);
    s2.insert(30);
    for(set<int,MyCompare>::iterator it=s2.begin();it!=s2.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

示例二 set存放自定义数据类型

```c++
#include<iostream>
using namespace std;
#include<set>
#include <string>

class Person
{
public:
    Person(string name,int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    string m_Name;
    int m_Age;
};
class comparePerson
{
public:
    bool operator()(const Person& p1,const Person&p2){
        //按照年龄 降序
        return p1.m_Age>p2.m_Age;
    }
};
void test01()
{
    set<Person,comparePerson> s;
    //创建数据
    Person p1("刘备",22);
    Person p2("关羽",21);
    Person p3("张飞",20);
    Person p4("曹操",25);
    Person p5("孙权",19);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    s.insert(p5);
    for(set<Person,comparePerson>::const_iterator it=s.begin();it!=s.end();it++)
    {
        cout<<"姓名："<<it->m_Name<<" 年龄："<<it->m_Age<<endl;
    }
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：

对于自定义数据类型，set必须指定排序规则才可以插入数据

### 3.9 map/multimap容器

#### 3.9.1 map基本概念

简介：

- map中所有元素都是pair
- pair中第一个元素为key(键值),起到索引作用，第二个元素为value(实值)
- 所有元素都会根据元素的键值自动排序

本质：

- map/multimap属于关联式容器，底层结构是用二叉树实现

优点：

- 可以根据key值快速找到value值

map和multimap区别：

- map不允许容器中有重复key值元素
- multimap允许容器中有重复的key值元素

#### 3.9.2 map构造函数赋值

功能描述：

- 对map容器进行构造和赋值操作

函数原型：

构造：

- map< T1, T2 > mp;    //map默认构造函数
- map(const map &mp);  //拷贝构造函数

赋值：

- map& operator=(const map &mp);//重载等号操作符

示例：

```c++
#include<iostream>
using namespace std;
#include<map>

void printMap(map<int,int>&m)
{
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<"key="<<(*it).first<<"value="<<(*it).second<<endl;
    }
}
void test01()
{
   //创建map容器
    map<int,int> mp1;
    mp1.insert(pair<int,int>(1,10));
    mp1.insert(pair<int,int>(2,20));
    mp1.insert(pair<int,int>(3,30));
    mp1.insert(pair<int,int>(4,40));
    printMap(mp1);
    //拷贝构造
    map<int,int>mp2(mp1);
    printMap(mp2);
    //赋值
    map<int,int>mp3;
    mp3=mp2;
    printMap(mp3);
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：map中所有元素都是成对出现，插入数据时候要使用对组pair

#### 3.9.3 map大小和交换

功能描述：

- 统计map容器大小以及交换map容器

函数原型：

- size();//返回容器中元素的数目
- empty();//判断容器是否为空
- swap(st);//交换两个集合容器

示例：

```c++
#include<iostream>
using namespace std;
#include<map>

void printMap(map<int,int>&m)
{
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<"key="<<it->first<<"value="<<it->second<<endl;
    }
    cout<<endl;
}
void test01()
{
   //创建map容器
    map<int,int> mp1;
    mp1.insert(pair<int,int>(1,10));
    mp1.insert(pair<int,int>(2,20));
    mp1.insert(pair<int,int>(3,30));
    mp1.insert(pair<int,int>(4,40));
    if(mp1.empty())
    {
        cout<<"mp1为空"<<endl;
    }
    else
    {
        cout<<"mp1不为空"<<endl;
        cout<<"mp1的大小为："<<mp1.size()<<endl;
    }
}
//交换
void test02()
{
    map<int,int> mp1;
    mp1.insert(pair<int,int>(1,10));
    mp1.insert(pair<int,int>(2,20));
    mp1.insert(pair<int,int>(3,30));
    mp1.insert(pair<int,int>(4,40));
    map<int,int> mp2;
    mp2.insert(pair<int,int>(4,100));
    mp2.insert(pair<int,int>(5,200));
    mp2.insert(pair<int,int>(6,300));
    mp2.insert(pair<int,int>(7,400));
    cout<<"交换前："<<endl;
    printMap(mp1);
    printMap(mp2);
    cout<<"交换后"<<endl;
    mp1.swap(mp2);
    printMap(mp1);
    printMap(mp2);

}
int main(){
    test02();
    system("pause");
    return 0;
}
```

总结：

- 统计大小 --size
- 判断是否为空 --empty
- 交换容器 --swap

#### 3.9.4 map插入和删除

功能描述：

- map容器进行插入数据和删除数据

函数原型：

- insert(elem)；//在容器中插入元素
- clear(); //清除所有元素
- erase(pos)；//删除pos迭代器所指的元素，返回写一个元素的迭代器
- erase(beg,end);//删除区间[beg，end]的所有元素，返回下一个元素的迭代器
- erase(key);//删除容器中值为key的元素

```c++
#include<iostream>
using namespace std;
#include<map>

void printMap(map<int,int>&m)
{
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<"key="<<it->first<<"value="<<it->second<<endl;
    }
    cout<<endl;
}
void test01()
{
   //创建map容器
    map<int,int> mp1;
    //插入
    //第一种
    mp1.insert(pair<int,int>(1,10));
    //第二种
    mp1.insert(make_pair(2,20));
    //第三种
    mp1.insert(map<int,int>::value_type(3,30));
    //第四种
    mp1[4]=40;
    //[]不建议插入，用途 可以利用key访问到value值，为什么不建议？
    //cout<<mp1[4]<<endl;
    printMap(mp1);
    //删除
    mp1.erase(mp1.begin());
    printMap(mp1);
    //按照key删除
    mp1.erase(3);
    printMap(mp1);

    mp1.erase(mp1.begin(),mp1.end());
    printMap(mp1);

    mp1.clear();
    printMap(mp1);
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：

- map插入方式很多，**记住其一**即可
- 插入---insert
- 删除---erase
- 清空---clear

#### 3.9.5 map查找和统计

功能描述：

- 对map容器进行查找数据以及统计数据

函数原型：

- find(key)；//查找key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回set.end();
- count(key);  //统计key的元素个数

示例：

```c++
#include<iostream>
using namespace std;
#include<map>

void printMap(map<int,int>&m)
{
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<"key="<<it->first<<"value="<<it->second<<endl;
    }
    cout<<endl;
}
void test01()
{
    map<int,int>m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(3,40));
    //查找
    map<int,int>::iterator pos=m.find(3);
    if(pos!=m.end())
    {
        cout<<"查找到了元素key="<<pos->first<<"value="<<pos->second<<endl;
    }
    else
    {
        cout<<"未找到元素"<<endl;
    }
    //统计
    //map不允许插入重复key 元素，count统计而言结果要么是0.要么是1
    //multmap的count统计可能大于1
    int num=m.count(3);
    cout<<"num="<<num<<endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：

- 查找 ---find（返回的是迭代器）
- 统计 ---count（对于map，结果为0或者1）

#### 3.9.6 map容器排序

学习目标：

- map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则

主要技术点：

- 利用仿函数，可以改变排序规则

示例：

```c++
#include<iostream>
using namespace std;
#include<map>

class MyCompare{
public:
    bool operator()(int v1,int v2){
        return v1>v2;
    }
};


void test01()
{
    map<int,int,MyCompare>m;
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(5,50));
    m.insert(pair<int,int>(4,40));
    m.insert(pair<int,int>(3,30));
    for(map<int,int,MyCompare>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<"key="<<it->first<<"value="<<it->second<<endl;
    }
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：

- 利用仿函数可以指定map容器的排序规则
- **对于自定义数据类型，map必须要指定排序规则，同set容器**

### 3.10案例 -员工分组

#### 3.10.1 案例描述

- 公司今天招聘了10个员工(ABCDEFGHIJ),10名员工进入公司之后，需要指派员工在哪个部门工作
- 员工信息有：姓名 工资组成；部门分为策划、美术、研发
- 随机给10名员工分配部分和工资
- 通过multimap进行信息的插入 key(部分编号) value(员工)
- 分部分显示员工信息

#### 3.10.2 实现步骤

- 创建10名员工，放到vector中
- 遍历vector容器，取出每个员工，进行随机分组
- 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
- 分部门显示员工信息

代码：

```c++
#include<iostream>
using namespace std;
#include<map>
#include <vector>
#include <string>
#include <ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2
//员工类
class Worker
{
public:
    string m_Name;
    int m_Salary;
};
//创建员工
void createWorker(vector<Worker>&v)
{
    string namespeed="ABCDEFGHIJ";
    for(int i=0;i<10;i++)
    {
        Worker worker;
        worker.m_Name="员工";
        worker.m_Name+=namespeed[i];

        worker.m_Salary=rand()%10000+10000;
        //将员工放入到vector容器中
        v.push_back(worker);
    }
}
//员工分组
void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
    for(vector<Worker>::iterator it=v.begin();it!=v.end();it++)
    {
        //产生随机部门编号
        int deptId=rand()%3;
        //将员工插入到分组中
        //key部门编号，value具体员工
        m.insert(make_pair(deptId,*it));
    }
}
//分组显示员工
void showWorkerByGroup(multimap<int,Worker>&m)
{
    cout<<"策划部门："<<endl;
    multimap<int,Worker>::iterator pos=m.find(CEHUA);
    int count=m.count(CEHUA);//统计具体人数
    int index=0;
    for(;pos!=m.end() && index<count;pos++,index++)
    {
        cout<<"姓名："<<pos->second.m_Name<<"工资："<<pos->second.m_Salary<<endl;
    }
    cout<<"美术部门："<<endl;
    pos=m.find(MEISHU);
    count=m.count(MEISHU);//统计具体人数
    index=0;
    for(;pos!=m.end() && index<count;pos++,index++)
    {
        cout<<"姓名："<<pos->second.m_Name<<"工资："<<pos->second.m_Salary<<endl;
    }
    cout<<"研发部门："<<endl;
    pos=m.find(YANFA);
    count=m.count(YANFA);//统计具体人数
    index=0;
    for(;pos!=m.end() && index<count;pos++,index++)
    {
        cout<<"姓名："<<pos->second.m_Name<<"工资："<<pos->second.m_Salary<<endl;
    }
}
int main(){
    //随机数种子
    srand((unsigned int)time(NULL));
    //创建员工
    vector<Worker>vWorker;
    createWorker(vWorker);
    //员工分组
    multimap<int,Worker>mWorker;
    setGroup(vWorker,mWorker);
    //分组显示员工
    showWorkerByGroup(mWorker);
    //测试
    //for(vector<Worker>::iterator it=vWorker.begin();it!=vWorker.end();it++)
	//{
	//   cout<<"姓名："<<it->m_Name<<"工资："<<it->m_Salary<<endl;
	//}
    system("pause");
    return 0;
}
```

## 4 STL-函数对象

### 4.1 函数对象

#### 4.1.1 函数对象概念

概念：

- 重载函数调用操作符的类，其对象称为函数对象
- 函数对象使用重载的()时，行为类似函数调用，也叫仿函数

本质：

函数对象(仿函数)是一个类，不是一个函数

#### 4.1.2 函数对象使用

特点：

- 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
- 函数对象超出普通函数的概念，函数对象可以有自己的状态
- 函数对象可以作为参数传递

```c++
#include<iostream>
using namespace std;

#include <string>

class MyAdd
{
public:
    int operator()(int v1,int v2)
    {
        return v1+v2;
    }
};
class MyPrint
{
public:
    MyPrint()
    {
        this->count=0;
    }
    void operator()(string test)
    {
        cout<<test<<endl;
        this->count++;
    }
    int count; //内部自己状态
};
//函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01()
{
    MyAdd myAdd;
    cout<<myAdd(10,10)<<endl;
}
//函数对象超出普通函数的概念，函数对象可以有自己的状态
void test02(){
    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    cout<<"MyPring调用次数为："<<myPrint.count<<endl;
}
//函数对象可以作为参数传递
void doPrint(MyPrint & mp,string test)
{
    mp(test);
}
void test03(){
    MyPrint myPrint;
    doPrint(myPrint,"Hello tfl");
}
int main(){
//    test01();
//    test02();
    test03();
    system("pause");
    return 0;
}
```

总结：

- 仿函数写法非常灵活，可以作为参数进行传递

### 4.2 谓词

#### 4.2.1 谓词概念

概念：

- 返回bool类型的仿函数称为谓词
- 如果operator()接受一个参数，那么叫做一元谓词
- 如果operator()接受两个参数，那么叫做二元谓词

#### 4.2.2 一元谓词

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
//仿函数 返回值类型是bool数据类型，称为谓词
//一元谓词
class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val>5;
    }
};
void test01()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    //查找容器中 有没有大于5的数字
    //greaterfive（）匿名函数对象
    vector<int>::iterator it=find_if(v.begin(),v.end(),GreaterFive());
    if(it==v.end())
    {
        cout<<"未找到"<<endl;
    }
    else
    {
        cout<<"找到了大于5的数字为："<<*it<<endl;
    }
}
int main()
{
    test01();
    system("pause");
    return 0;
}
```

总结：参数只有一个的谓词，称为一元谓词

#### 4.2.3 二元谓词

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
//二元谓词
class MyCompare
{
    public:
    bool operator()(int val1,int val2)
    {
        return val1>val2;
    }
};
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    sort(v.begin(),v.end());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //使用函数对象  改变算法策略，变为排序规则为从大到小
    sort(v.begin(),v.end(),MyCompare());
    cout<<"------------------------"<<endl;
     for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：参数只有两个的谓词，称为二元谓词

### 4.3 内建函数对象

#### 4.3.1 内建函数对象的意义

概念：

- STL内建了一些函数对象

分类：

- 算术仿函数
- 关系仿函数
- 逻辑仿函数

用法：

- 这些仿函数所产生的的对象，用法和一般函数完全相同
- 使用内建函数对象，需要引入头文件#include< functional >

#### 4.3.2 算术仿函数

功能描述：

- 实现四则运算
- 其中negate是一元运算，其他都是二元运算

仿函数原型：

- template< class T > T plus< T >  //加法仿函数
- template< class T > T minus< T > //减法仿函数
- template< class T > T multiplies< T > //乘法仿函数
- template< class T > T divides< T >  //除法仿函数
- template< class T > T  modulus< T > //取模仿函数
- template< class T > T  negate< T >  //取反仿函数

示例：

```c++
#include<iostream>
using namespace std;

#include <functional>
//内建函数对象 算术仿函数

//negate 一元仿函数 取反仿函数
void test01()
{
    negate<int>n;
    cout<<n(50)<<endl;
}
//plus 二元仿函数  加法
void test02(){
    plus<int>p;
    cout<<"和为："<<p(10,20)<<endl;
}
//minus 二元仿函数  减法
void test03(){
    minus<int>m;
    cout<<"差为："<<m(30,20)<<endl;
}
//multiplies 二元仿函数  乘法
void test04(){
    multiplies<int>m;
    cout<<"积为："<<m(30,20)<<endl;
}
//divides 二元仿函数  除法
void test05(){
    divides<int>d;
    cout<<"商为："<<d(30,6)<<endl;
}
//modulus 二元仿函数  取模
void test06(){
    modulus<int>m;
    cout<<"模为："<<m(40,6)<<endl;
}
int main(){
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    system("pause");
    return 0;
}
```

#### 4.3.3 关系仿函数

功能描述：

- 实现关系对比

仿函数原型：

| 函数表达式                                  | 关系     |
| ------------------------------------------- | -------- |
| template< class T>  bool equal_to< T >      | 等于     |
| template< class T>  bool not_equal_to< T >  | 不等于   |
| template< class T>  bool greater< T >       | 大于     |
| template< class T>  bool greater_equal< T > | 大于等于 |
| template< class T>  bool less< T >          | 小于     |
| template< class T>  bool less_equal< T >    | 小于等于 |

示例：

```c++
#include<iostream>
using namespace std;
#include <functional>
#include <vector>
#include <algorithm>
//内建函数对象 关系仿函数

//大于
class MyCompare
{
public:
    bool operator()(int val1,int val2)
    {
        return val1>val2;
    }
};
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(50);
    for (vector<int>::iterator it=v.begin();it!=v.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    //降序
    //sort(v.begin(),v.end(),MyCompare());
    //大于
    sort(v.begin(),v.end(),greater<int>());
    cout<<"------------------------"<<endl;
    for (vector<int>::iterator it=v.begin();it!=v.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    sort(v.begin(),v.end(),less<int>());
    cout<<"------------------------"<<endl;
    for (vector<int>::iterator it=v.begin();it!=v.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：关系仿函数中最常用的就是greater<>大于

#### 4.3.4 逻辑仿函数

功能描述：

- 实现逻辑运算

函数原型：

| 函数原型                                   | 关系   |
| ------------------------------------------ | ------ |
| template< class T > bool  logical_and< T > | 逻辑与 |
| template< class T > bool  logical_or< T >  | 逻辑或 |
| template< class T > bool  logical_not< T > | 逻辑非 |

示例：

```c++
#include<iostream>
using namespace std;
#include <functional>
#include <vector>
#include <algorithm>
//内建函数对象 逻辑仿函数

void test01()
{
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    for (vector<bool>::iterator it=v.begin();it!=v.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    //利用逻辑非 将容器v搬运到容器v2中，并执行取反操作
    vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());
    for (vector<bool>::iterator it=v2.begin();it!=v2.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：逻辑仿函数实际应用较少，了解即可

## 5 STL-常用算法

概述：

- 算法主要是由头文件< algorithm >< functional >< numberic >组成
- < algorithm >是所有STL头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改等等
- < numberic >体积很小，只包括几个在序列上面进行简短数学运算的模板函数
- < functional >定义了一些模板类，用以声明函数对象

### 5.1 常用遍历算法

学习目标：

- 掌握常用的遍历算法

算法简介：

- for_each    //遍历容器
- transform  //搬运容器到另一个容器中

#### 5.1.1 for_each

功能描述：

- 实现遍历容器

函数原型：

- for_each(iterator beg,iterator end,_func);

  //遍历算法，遍历容器元素

  //beg开始迭代器

  //end结束迭代器

  //_func函数或者函数对象

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件

//常用遍历算法  for_each
//普通函数
void print01(int val)
{
    cout<<val<<" ";
}
//仿函数
class print02
{
public:
    void operator()(int val)
    {
        cout<<val<<" ";
    }
};
void test01()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),print01);
    cout<<endl;
    for_each(v.begin(),v.end(),print02());
    cout<<endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：for_each在实际开发中是最常用遍历算法，需要熟练掌握

#### 5.1.2 transform

功能描述：

- 搬运函数容器到另一个容器中

函数原型：

- transform<iterator beg1,iterator end1,iterator beg2,_func>

  //beg1源容器开始迭代器

  //end1源容器结束迭代器

  //beg2目标容器开始迭代器

  //_func函数或者函数对象

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件

//常用遍历算法  transform
class Transform
{
public:
    int operator()(int v)
    {
        return v+100;
    }
};
//仿函数  打印
class print{
public:
    void operator()(int val)
    {
        cout<<val<<" ";
    }
};
void test01()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    //目标容器
    vector<int> v2;
    v2.resize(v.size());//目标容器需要提前开辟空间
    transform(v.begin(),v.end(),v2.begin(),Transform());
    for_each(v2.begin(),v2.end(),print());
    cout<<endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

### 5.2 常用查找算法

学习目标：

- 掌握常用的查找算法

算法简介：

- find    //查找元素
- find_if    //按条件查找元素
- adjacent_find   //查找相邻重复元素
- binary_search   //二分查找法
- count   //统计元素个数
- count_if  //按条件统计元素个数

#### 5.2.1 find

功能描述：

- 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

函数原型：

- find(iterator beg,iterator end,value);

  //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

  //beg开始迭代器

  //end结束迭代器

  //value查找元素

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件
#include <string>
//常用的查找算法   find
//查找  内置数据类型
void test01()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    //查找容器中是否有5这个元素
    vector<int>::iterator it=find(v.begin(),v.end(),5);
    if(it==v.end())
    {
        cout<<"没有找到该元素"<<endl;
    }
    else
    {
        cout<<"找到了元素为："<<*it<<endl;
    }
}
//查找 自定义数据类型
class Person
{
public:
    Person(string name,int age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    //重载 ==  底层find知道如何对比person数据类型
    bool operator==(const Person&p)
    {
        if(this->m_name==p.m_name&&this->m_age==p.m_age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_name;
    int m_age;
};
void test02()
{
    vector<Person>v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    //放入容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    Person pp("bbb",20);
    vector<Person>::iterator it=find(v.begin(),v.end(),pp);
    if(it==v.end())
    {
        cout<<"没有找到p2"<<endl;
    }
    else
    {
        cout<<"找到了 姓名："<<it->m_name<<"年龄："<<it->m_age<<endl;
    }
}
int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}
```

总结：利用find可以在容器中找指定的元素，返回值是迭代器

#### 5.2.2 find_if

功能描述：

- 按条件查找元素

函数原型：

- find_if(iterator beg,iterator end,_Pred);

  //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器

  //beg开始迭代器

  //end结束迭代器

  //_Pred函数或者谓词(返回bool类型的仿函数)

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件
#include <string>
//常用的查找算法   find_if
//查找  内置数据类型
class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val>5;//val==5;等于5的
    }
};
void test01()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    //查找容器中是否有5这个元素
    vector<int>::iterator it=find_if(v.begin(),v.end(),GreaterFive());
    if(it==v.end())
    {
        cout<<"没有找到该元素"<<endl;
    }
    else
    {
        cout<<"找到了>5的数字为："<<*it<<endl;//找到一个即返回
    }
}


//查找 自定义数据类型
class Person
{
public:
    Person(string name,int age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    //重载 ==  底层find知道如何对比person数据类型
    bool operator==(const Person&p)
    {
        if(this->m_name==p.m_name&&this->m_age==p.m_age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_name;
    int m_age;
};
class Greater20
{
public:
    bool operator()(Person &p)
    {
        return p.m_age>20;
    }
};
void test02()
{
    vector<Person>v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    //放入容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    //找出年龄大于20的人
    vector<Person>::iterator it=find_if(v.begin(),v.end(),Greater20());
    if(it==v.end())
    {
        cout<<"没有找到p2"<<endl;
    }
    else
    {
        cout<<"找到了 姓名："<<it->m_name<<"年龄："<<it->m_age<<endl;
    }
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
```

#### 5.2.3 adjacent_find

功能描述：

- 查找相邻重复元素

函数原型：

- adjacent_find(iterator beg,iterator end);

  //查找相邻重复元素，返回相邻元素的第一个位置的迭代器

  //beg开始迭代器

  //end结束迭代器

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件
#include <string>
//常用的查找算法   adjacent_find

void test01()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    //相邻的两个相同的数
    v.push_back(3);
    v.push_back(3);
    vector<int>::iterator it=adjacent_find(v.begin(),v.end());
    if(it==v.end())
    {
        cout<<"未找到相邻重复的元素"<<endl;
    }
    else
    {
        cout<<"找到相邻重复的元素:"<<*it<<endl;
    }
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：面试题中如果出现查找相邻重复元素，记得用STL中的adjacent_find算法

#### 5.2.4 binary_search

功能描述：

- 查找指定元素是否存在

函数原型：

- bool binary_search(iterator beg,iterator end,value);

  //查找指定元素，查到 返回true 否则false

  //注意：在无序序列中不可用

  //beg开始迭代器

  //end结束迭代器

  //value查找的元素

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件
#include <string>
//常用的查找算法   binary_search
void test01()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    //v.push_back(2); 如果是无序序列，结果未知！
    //查找容器中是否有9 元素
    //注意：容器必须是有序的序列
    //二分查找
    bool ret=binary_search(v.begin(),v.end(),9);
    if(ret)
    {
        cout<<"找到了元素"<<endl;
    }
    else
    {
        cout<<"未找到"<<endl;
    }
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：二分查找法查找效率很高，值得注意的是查找的容器中元素必须是有序序列

#### 5.2.5 count

功能描述：

- 统计元素个数

函数原型：

- count(iterator beg,iterator end, value);

  //统计元素出现次数

  //beg开始迭代器

  //end结束迭代器

  //value要统计个数的元素

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件
#include <string>
//常用的查找算法   count

//统计内置数据类型
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);
    int num=count(v.begin(),v.end(),40);
    cout<<"40的元素个数为："<<num<<endl;
}
//统计自定义数据类型
class Person
{
public:
    Person(string name,int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    bool operator==(const Person &p)
    {
        if(this->m_Age==p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_Name;
    int m_Age;
};
void test02()
{
    vector<Person> v;
    Person p1("aaa",30);
    Person p2("bbb",40);
    Person p3("ccc",30);
    Person p4("ddd",35);
    Person p5("eee",25);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    Person p("fff",30);
    int num=count(v.begin(),v.end(),p);
    cout<<"和fff同岁的人员个数为："<<num<<endl;
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
```

总结：统计自定义数据类型时候，**需要配置重载operator==**

#### 5.2.6 count_if

功能描述：

- 按条件统计元素个数

函数原型：

- count_if(iterator beg,iterator end,_Pred);

  //按条件统计元素出现次数

  //beg开始迭代器

  //end结束迭代器

  //_Pred谓词

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件
#include <string>
//常用的查找算法   count_if

//统计内置数据类型
class Greater20
{
public:
    bool operator()(int val)
    {
        return val>20;
    }
};
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);
    v.push_back(30);
    int num=count_if(v.begin(),v.end(),Greater20());
    cout<<"大于20的元素个数为："<<num<<endl;
}
//统计自定义数据类型
class Person
{
public:
    Person(string name,int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    string m_Name;
    int m_Age;
};
class AgeGreater20
{
public:
    bool operator()(const Person &p)
    {
        return p.m_Age>30;
    }
};
void test02()
{
    vector<Person> v;
    Person p1("刘备",35);
    Person p2("关羽",35);
    Person p3("张飞",35);
    Person p4("赵云",30);
    Person p5("曹操",40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    //统计 大于20人员个数
    int num=count_if(v.begin(),v.end(),AgeGreater20());
    cout<<"大于20岁的人员个数为："<<num<<endl;
}
int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}
```

### 5.3 常用排序算法

学习目标：

- 掌握常用的排序算法

算法简介：

- sort  //对容器内元素进行排序
- random_shuffle //洗牌  指定范围内的元素随机调整次序
- merge  //容器元素合并，并存储到另一容器中
- reverse  //反转指定范围的元素

#### 5.3.1 sort

功能描述：

- 对容器内元素进行排序

函数原型：

- sort(iterator beg,iterator end,_Pred)

  //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

  //beg  开始迭代器

  //end 结束迭代器

  //_Pred  谓词

示例：

```c++
#include<iostream>
using namespace std;
#include <algorithm>
#include<vector>
#include<functional>
//常用的排序算法 sort
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(40);
    v.push_back(20);
    //利用sort
    sort(v.begin(),v.end());
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
    //改变为降序
    sort(v.begin(),v.end(),greater<int>());
}
int main()
{
    test01();
    system("pause");
    return 0;
}
```

#### 5.3.2 random_shuffle

功能描述：

- 洗牌  指定范围内的元素随机调整次序

函数原型：

- random_shuffle(iterator beg,iterator end);

  //指定范围内的元素随机调整次序

  //beg开始迭代器

  //end结束迭代器

示例：

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<ctime>
#include<functional>
//常用的排序算法 random_shuffle
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    srand((unsigned int)time(NULL))
	vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    //利用洗牌 算法 打乱顺序
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
```

#### 5.3.3 merge

功能描述：

- 两个容器元素合并，并存储到另一容器中

函数原型：

- merge(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);

  //容器元素合并，并存储到另一容器中

  //注意：两个容器必须是有序的

  //beg1 容器1开始迭代器

  //end1 容器1结束迭代器

  //beg2 容器2开始迭代器

  //end2 容器2结束迭代器

  //dest 目标容器开始迭代器

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件
#include <string>
//常用的排序算法   merge
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i <10 ; i++) {
        v1.push_back(i);
        v2.push_back(i+1);
    }
    //目标容器
    vector<int> vTarget;
    //提前给目标容器分配空间
    vTarget.resize(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
    for_each(vTarget.begin(),vTarget.end(),myPrint);
    cout<<endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

#### 5.3.4  reverse

功能描述：

- 将容器内元素进行反转

函数原型：

- reverse(iterator beg,iterator end)

  //反转指定范围的元素

  //beg开始迭代器

  //end结束迭代器

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件
#include <string>
//常用的排序算法   reverse
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    cout<<"反转前："<<endl;
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
    cout<<"反转后："<<endl;
    reverse(v.begin(),v.end());
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;

}

int main(){
    test01();
    system("pause");
    return 0;
}
```

### 5.4 常用拷贝和替换算法

学习目标：

- 掌握常用的拷贝和替换算法

算法简介：

- copy  //容器内指定范围的元素拷贝到另一容器中
- replace //将容器内指定范围的旧元素修改为新元素
- replace_if  //容器内指定范围满足条件的元素替换为新元素
- swap  //互换两个容器的元素

#### 5.4.1 copy

功能描述：

- 容器内指定范围的元素拷贝到另一容器中

函数原型：

- copy(iterator beg,iterator end, iterator dest);

​	    //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

​	    //beg 开始迭代器

​	    //end 结束迭代器

​	    //dest 目标起始迭代器

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件
//常用的拷贝和替换算法   copy
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    vector<int> v2;
    v2.resize(v.size());
    copy(v.begin(),v.end(),v2.begin());
    for_each(v2.begin(),v2.end(),myPrint);
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

#### 5.4.2 replace

功能描述：

- 将容器内指定范围的旧元素修改为新元素

函数原型：

- replace(iterator beg,iterator end,oldvalue,newvalue);

  //将区间内旧元素替换成新元素

  //beg开始迭代器

  //end结束迭代器

  //oldvalue 旧元素

  //newvalue 新元素

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件
//常用的拷贝和替换算法   replace
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    replace(v.begin(),v.end(),0,100);
    for_each(v.begin(),v.end(),myPrint);
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

#### 5.4.3 replace_if

功能描述：

- 将区间内满足条件的元素，替换成指定元素

函数原型：

- replace_if(iterator beg,iterator end,_pred,newvalue); 

  //按条件替换元素，满足条件的替换成指定元素

  //beg开始迭代器

  //end结束迭代器

  //_pred谓词

  //newvalue 替换的新元素

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件
//常用的拷贝和替换算法   replace_if
class Greater5
{
public:
    bool operator()(int val)
    {
        return val>=5;
    }
};
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    cout<<"替换前："<<endl;
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
    cout<<"替换后："<<endl;
    replace_if(v.begin(),v.end(),Greater5(),20);
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}
```

#### 5.4.4 swap

功能描述：

- 互换两个容器的元素

函数原型：

- swap(container c1,container c2);

  //互换两个容器的元素

  //c1容器1

  //c2容器2

示例：

```c++
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm> //标准算法的头文件
//常用的拷贝和替换算法   swap

void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i <10 ; i++) {
        v1.push_back(i);
        v2.push_back(i+100);
    }
    cout<<"交换前："<<endl;
    for_each(v1.begin(),v1.end(),myPrint);
    cout<<endl;
    for_each(v2.begin(),v2.end(),myPrint);
    cout<<endl;
    cout<<"交换后："<<endl;
    swap(v1,v2);
    for_each(v1.begin(),v1.end(),myPrint);
    cout<<endl;
    for_each(v2.begin(),v2.end(),myPrint);
    cout<<endl;


}

int main(){
    test01();
    system("pause");
    return 0;
}
```

### 5.5 常用的算术生成器

学习目标：

- 掌握常用的算术生成算法

注意：

- 算术生成算法属于小型算法，使用是包含的头文件为#include< numeric >

算法简介：

- accumulate   //计算容器元素累计总和
- fill  //向容器中添加元素

#### 5.5.1 accumulate

功能描述：

- 计算区间内容器元素累计总和

函数原型：

- accumulate(iterator beg,iterator end,value)

  //计算容器元素累计总和

  //beg开始迭代器

  //end结束迭代器

  //value起始值

示例：

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<numeric>

//常用算术生成算法
void test01(){
    vector<int>v;
    for(int i=0;i<=100;i++)
    {
        v.push_back(i);
    }
    int total=accumulate(v.begin(),v.end(),0);
    cout<<"total="<<total<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：accumulate使用是头文件注意是numeric,这个算法很实用

#### 5.5.2 fill

功能描述：

- 向容器中填充指定的元素

函数原型：

- fill(iterator beg,iterator end,value);

  //向容器中填充元素

  //beg开始迭代器

  //end结束迭代器

  //value填充的值

示例：

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include <algorithm>

//常用算术生成算法
void myPrint(int val){
    cout<<val<<" ";
}
void test01(){
    vector<int>v;
  	v.resize(10);
    //后期重新填充
    fill(v.begin(),v.end(),100);
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：利用fill可以将容器区间内元素填充为指定的值

### 5.6 常用集合算法

学习目标：

- 掌握常用的集合算法

算法简介：

- set_intersection  //求两个容器的交集
- set_union   //求两个容器的并集
- set_difference   //求两个容器的差集

#### 5.6.1 set_intersection

功能描述：

- 求两个容器的交集

函数原型：

- set_intersection(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest)；

  //求两个集合的交集

  //beg1，第一个容器的开始迭代器

  //end1，第一个容器的结束迭代器

  //beg2，第二个容器的开始迭代器

  //end2，第二个元素的结束迭代器

  //dest,    目标容器的开始迭代器
  
  //返回末尾元素迭代器

示例：

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include <algorithm>

//常用算术生成算法
void myPrint(int val){
    cout<<val<<" ";
}
void test01(){
   vector<int>v1;
   vector<int>v2;
   for(int i=0;i<10;i++){
       v1.push_back(i);
       v2.push_back(i+5);
   }
   vector<int>vTarget;
   //目标容器需要提前开辟空间
   //最特殊情况，大容器包含小容器，开辟空间取小容器的size即可
   vTarget.resize(min(v1.size(),v2.size()));
   vector<int>::iterator itEnd=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
   for_each(vTarget.begin(),itEnd,myPrint);
   cout<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}	
```

总结：

- 求交集的两个集合必须的有序序列
- 目标容器开辟空间需要从两个容器中取最小值
- set_intersection返回值即是交集中最后一个元素的迭代器

#### 5.6.2 set_union

功能描述：

- 求两个集合的并集

函数原型：

- set_union(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest)

  //求两个容器集合的并集

  //**注意：两个集合必须是有序序列**

  //beg1，第一个容器的开始迭代器

  //end1，第一个容器的结束迭代器

  //beg2，第二个容器的开始迭代器

  //end2，第二个元素的结束迭代器

  //dest,    目标容器的开始迭代器

示例：

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include <algorithm>

//常用算术生成算法
void myPrint(int val){
    cout<<val<<" ";
}
void test01(){
   vector<int>v1;
   vector<int>v2;
   for(int i=0;i<10;i++){
       v1.push_back(i);
       v2.push_back(i+5);
   }
   vector<int>vTarget;
   //目标容器需要提前开辟空间
   //最特殊情况，两个容器没有交集，并集是两个容器size相加
   vTarget.resize(v1.size()+v2.size());
   vector<int>::iterator itEnd=set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
   for_each(vTarget.begin(),itEnd,myPrint);
   cout<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：

- 求并集的两个集合必须是有序序列
- 目标容器开辟空间需要两个容器相加
- set_union返回值即是并集中最后一个元素的位置

#### 5.6.3 set_difference

功能描述：

- 求两个集合的差集

函数原型：

- set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest)

  //求两个容器集合的并集

  //**注意：两个集合必须是有序序列**

  //beg1，第一个容器的开始迭代器

  //end1，第一个容器的结束迭代器

  //beg2，第二个容器的开始迭代器

  //end2，第二个元素的结束迭代器

  //dest,    目标容器的开始迭代器

示例：

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include <algorithm>

//常用算术生成算法
void myPrint(int val){
    cout<<val<<" ";
}
void test01(){
   vector<int>v1;
   vector<int>v2;
   for(int i=0;i<10;i++){
       v1.push_back(i);
       v2.push_back(i+5);
   }
   vector<int>vTarget;
   //目标容器需要提前开辟空间
   //最特殊情况，两个容器没有交集，并集是两个容器size相加
   vTarget.resize(max(v1.size(),v2.size()));
   vector<int>::iterator itEnd=set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
   for_each(vTarget.begin(),itEnd,myPrint);
   cout<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：

- 求差集的两个集合必须是有序序列
- 目标容器开辟空间需要从两个容器取较大值
- set_difference返回值即是差集中最后一个元素的位置

# 四、总结

## 1  运算符重载

4.5节运算符重载有哪些是返回引用，为什么必须是引用？还有哪些情况下需要返回引用？

## 2 this指针

同一个类的不同对象this指针地址相同吗？

​		实测不是同一个，每个对象对应一个this指针，每实例化一个对象，会生成一个对应该对象的this指针

## 3.多态

形成多态时父类函数前必须加virtual，子类同名函数到底加不加virtual，有什么讲究？

**基类中定义的virtual虚函数，在继承子类中同名函数自动都属于虚函数，可以不需要virtual关键字。**

**如果基类中定义的函数不是virtual，而子类中又将相同函数定义为virtual，则称之为越位，函数行为依赖于指针/引用的类型，而不是实际对象的类型。下面是例子：**

```c++
#include<iostream>
using namespace std;

class Base
{
public:
    void f(){ cout << "Base::f() " << endl; }
    virtual void g(){ cout << "Base::g() " << endl; }
};

class Derived : public Base
{
public:
    virtual void f(){ cout << "Derived::f() " << endl; }
    void g(){ cout << "Derived::g() " << endl; }
};

class VirtualDerived : virtual public Base
{
public:
    void f(){ cout << "VirtualDerived::f() " << endl; }
    void g(){ cout << "VirtualDerived::g() " << endl; }
};

int main()
{
    Base *d = new Derived;
    Base *vd = new VirtualDerived;

    d->f(); // Base::f() Bad behavior
    vd->f(); // Base::f() Bad behavior
    
    d->g(); // Derived::g()
    vd->g(); // VirtualDerived::g()

    delete d;
    delete vd;

    return 0;
}
```

实现多态，有二种方式，覆盖，重载。

-   覆盖，当子类重新定义了父类的虚函数后，父类指针根据赋给它的不同的子类指针，动态（记住：是动态！）的调用属于子类的该函数，这样的函数调用在编译期间是无法确定的（调用的子类的虚函数的地址无法给出）。因此，这样的函数地址是在运行期绑定的（晚邦定）。
-   重载，是指允许存在多个同名函数，而这些函数的参数表不同（或许参数个数不同，或许参数类型不同，或许两者都不同）。-- 早绑定，其实严格来说不算多态

例子1：

```c++
#include <iostream>
 
using namespace std;
 
class Vehicle {
public:
    virtual void run() const= 0;
};
 
class Car:public Vehicle {
public:
    void run() const{
        cout << "run a car" << endl;
    }
};
 
class Airplane :public Vehicle {
public:
    void run() const {
        cout << "run a airplane" << endl;
    }
};
 
void run_vehicle(const Vehicle *test) {
    test->run();
}
 
int main(void) {
    Car car;
    Airplane airplane;
    run_vehicle(&car);
    run_vehicle(&airplane);
    return 0;
}
```

客户程序可以通过指向基类的指针或引用来使用派生类对象的方法



例子2：

```c++
/*括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合*/


#include <stdio.h>
#include <stdlib.h>
#include <string>
//#include <stddef.h>

#include <vector>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <algorithm>
#include <iostream>
#include "string"
using namespace std;

#include <iostream>

using namespace std;

class Vehicle {
public:
	virtual void run() const = 0;
	virtual void func1(int a) //无virtural会调用基类；有virtual 但参数类型不同也会调用基类；有virtual 参数个数不同会报错；有virtual 参数类型(包含个数)也相同才会有多态
	{
		cout << "Vehicle func1" << endl;
	}
};

class Car :public Vehicle {
public:
	void run() const{
		cout << "run a car" << endl;
	}

	void func1(int val)
	{
		cout << "Car func1" << endl;
	}
};

class Airplane :public Vehicle {
public:
	void run() const {
		cout << "run a airplane" << endl;
	}

	void func1(int val)
	{
		cout << "Airplane func1" << endl;
	}
};

void run_vehicle(const Vehicle *test) {
	test->run();
}

void run_vehicle(const Vehicle &test) {
	test.run();
}

int main(void) {
	Car car;
	Airplane airplane;
	run_vehicle(&car);
	run_vehicle(&airplane);

	run_vehicle(car);
	run_vehicle(airplane);

	Vehicle* vehicleOne = new Car;
	Vehicle* vehicleTwo = new Airplane;
    
    //若基类func1无virtual，则下面两句都是调用基类func1
	vehicleOne->func1(5);//Car func1
	vehicleTwo->func1(6);//Airplane func1
    vehicleTwo->Vehicle::func1(4);//Vehicle func1
	return 0;
}
```



## 4.类模板

1.38友元函数声明处的<>是什么用？

## 5 遍历算法

5.11中仿函数和普通函数使用起来有什么差别？

​	(a) 仿函数可以记录自己的状态

​	(b) 反函数可以作为参数传递



## 6 谓词和仿函数的区别

### 仿函数(也叫函数对象)

- 函数对象在使用时，**可以像普通函数那样**调用, 可以有参数，可以有返回值
- 函数对象超出普通函数的概念，函数对象**可以有自己的状态**
- 函数对象**可以作为参数传递**

### 谓词

返回bool类型的函数或仿函数称为谓词

- 如果operator()接受一个参数，称为一元谓词
- 如果operator()接受两个参数，称为二元谓词



## 7 什么时候用到虚函数？

  (a)  需要用基类指针指向派生类成员函数

（b）基类的析构函数需要是虚函数，不然析构基类时不会自动析构派生类，可能导致申请的内存无法释放从而导致内存泄漏

## 8 哪些函数不可以被声明为虚函数

构造函数、内联函数、友元函数、静态成员函数、普通函数



## 9 什么时候用到拷贝构造函数

- 当类的一个对象去初始化该类的另一个对象时；

- 如果函数的形参是类的对象，调用函数进行形参和实参结合时；

- 如果函数的返回值是类对象，函数调用完成返回时。

示例：如下函数过程有哪些地方需要拷贝构造函数

```c++

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class Student
{
public:	
	Student()
	{
		cout << "默认构造函数" << endl;
	}

	Student(int age)
	{
		this->age = age;
		cout << "有参构造函数" << endl;
	}
	Student(Student &s)
	{
		cout << "拷贝构造函数" << endl;
		this->age = s.age;
	}
	~Student()
	{
		cout << "析构函数" << endl;

	}
	void showAge()
	{
		cout << "age:"<< this->age << endl;
	}
public:
	int age;
};

Student test(Student s)//实参是s1传给形参s时需要拷贝构造，
{
	Student a1(18);//有参
	return a1;//函数返回a1需要拷贝构造
}

void main01()
{
	Student s1;//默认构造
	s1= test(s1);//无论是否用s1接收，函数返回时都要拷贝构造
	s1.showAge();
	
}//该函数结束时才会析构test返回时拷贝构造的对象

int main()
{
	main01();
	return 0;
}
```

## 10 什么时候返回引用





## 11.左值引用于右值引用

## 12 overload(重载) override(覆盖) overwrite(改写)

参考：

https://www.cnblogs.com/kuliuheng/p/4107012.html

### 1.overload

函数重载是指在同一作用域内，可以有一组具有相同函数名，不同参数列表的函数，这组函数被称为重载函数。重载函数通常用来命名一组功能相似的函数，这样做减少了函数名的数量，避免了名字空间的污染，对于程序的可读性有很大的好处。

**（1）**可以是全局函数的重载也可以是类中不同同名的不同成员函数

  **(2)**  产生重载的条件是函数名相同、参数列表类型或(和)数目不同，注意返回仅仅返回值不同不构成重载，函数编译会报错

典型用处： 构造函数重载；操作符重载，本质上就是函数重载

例子：

```c++
略
```

### 2.override

重写(推翻原有，但原有还在)的概念其实是用来实现C++多态性的，即子类重新改写父类声明为virtual的函数

**（1）**不同的范围（分别位于派生类与基类）；
**（2）**函数名字相同；
**（3）**参数列表完全相同；就是说函数忽略是否加virtual要一模一样。
**（4）**基类函数必须有virtual 关键字，派生类的virtual可有可无。

例子：

```c++
//参见4.7中正常多态情形的例子
```

**同名的普通函数与const函数本质上是两个不同的函数，应该等价理解为这两个同名函数的参数是不同的**-->属于重载

### 3.overwrite

改写(原有被屏蔽)是指派生类的函数屏蔽（或者称之为“隐藏”）了与其同名的基类函数，正是这个C++的隐藏规则使得问题的复杂性陡然增加，这里面分为两种情况讨论：

**（1）**如果派生类的函数与基类的函数同名，但是参数不同。那么此时，**不论有无virtual关键字**，基类的函数将被隐藏（注意别与重载混淆）。
**（2）**如果派生类的函数与基类的函数同名，并且参数也相同，但是**基类函数没有virtual关键字**。那么此时，基类的函数被隐藏（注意别与override混淆）。--> 参考4.6.5继承时同名成员函数的处理

例子：

```c++
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void f(float x){ cout << "Base::f(float) " << x << endl; }
    virtual void g(float x){ cout << "Base::g(float) " << x << endl; }
    void h(float x){ cout << "Base::h(float) " << x << endl; }
};

class Derived : public Base
{
public:
    virtual void f(float x){ cout << "Derived::f(float) " << x << endl; }
    virtual void g(int x){ cout << "Derived::g(int) " << x << endl; }
    void h(float x){ cout << "Derived::h(float) " << x << endl; }
};

int main()
{
    Derived  d;
    Base *pb = &d;
    Derived *pd = &d;

    // Good : behavior depends solely on type of the object
    pb->f(3.14f); // Derived::f(float) 3.14
    pd->f(3.14f); // Derived::f(float) 3.14

    // Bad : behavior depends on type of the pointer
    pb->g(3.14f); // Base::g(float) 3.14 (surprise!)
    pd->g(3.14f); // Derived::g(int) 3

    // Bad : behavior depends on type of the pointer
    pb->h(3.14f); // Base::h(float) 3.14  (surprise!)
    pd->h(3.14f); // Derived::h(float) 3.14

    return 0;
}
```

看两种申请指针方式的对比：

```c++

#include <vector>
#include<time.h>
#include <iostream>
#include <algorithm>
using namespace std;

#include <iostream>
using namespace std;

class Base
{
public:
	virtual void f(float x) { cout << "Base::f(float) " << x << endl; }
	virtual void g(float x) { cout << "Base::g(float) " << x << endl; }
	void h(float x) { cout << "Base::h(float) " << x << endl; }
};

class Derived : public Base
{
public:
	virtual void f(float x) { cout << "Derived::f(float) " << x << endl; }
	virtual void g(int x) { cout << "Derived::g(int) " << x << endl; }
	void h(float x) { cout << "Derived::h(float) " << x << endl; }
};

int main()
{
	Derived  d;//子类对象
	Base *pb = &d;//父类指针指向子类对象-->有可能产生多态
	Derived *pd = &d;

	Base *tb = new Base;
	Base *td = new Derived; //父类指针指向子类对象-->有可能产生多态
    	
    //Derived *xb = new Base;//会报错，注意基类的值不能用于初始化派生类的实体。
	Derived *xd = new Derived;
    
/*1正常产生多态的情形：父类加了virtual 父类和子类函数名字、参数类型和数目都相同构成多态*/
	// Good : behavior depends solely on type of the object
	pb->f(3.14f); // Derived::f(float) 3.14 --->产生多态
	pd->f(3.14f); // Derived::f(float) 3.14

	tb->f(3.14f); //Base::f(float) 3.14
	td->f(3.14f); //Derived::f(float) 3.14--->产生了多态

/*2父类加了virtual 但只要父类和子类函数参数类型或个数有差异都不能构成多态*/
				  // Bad : behavior depends on type of the pointer
	pb->g(3.14f); // Base::g(float) 3.14 (surprise!)--->未产生多态
	pd->g(3.14f); // Derived::g(int) 3

	tb->g(3.14f);//Base::g(float) 3.14
	td->g(3.14f); //Base::g(float) 3.14 --->未产生多态

/*3因为父类h函数未加virtual 无论子类同名(且类型相同的函数)加不加都不能构成多态*/
				  // Bad : behavior depends on type of the pointer
	pb->h(3.14f); // Base::h(float) 3.14  (surprise!) --->未产生多态
	pd->h(3.14f); // Derived::h(float) 3.14

	tb->h(3.14f); //Base::h(float) 3.14
	td->h(3.14f); //Base::h(float) 3.14   --->未产生多态

	return 0;
}
```

## 13 左值引用和右值引用

**先看一下传统的左值引用**

```c++
int a = 10;
int &b = a;//定义一个左值引用变量b = 20;
b = 20; //通过左值引用修改引用内存的值
```

左值引用在汇编层面其实和普通的指针是一样的；定义引用变量必须初始化，因为引用其实就是一个别名，需要告诉编译器定义的是谁的引用。

```c++
int &var = 10;
```

上述代码是无法编译通过的，因为10无法进行取地址操作，无法对一个立即数取地址，因为立即数并没有在内存中存储，而是存储在寄存器中，可以通过下述方法解决:

```c++
const int &var = 10;
```

使用常引用来引用常量数字10，因为此刻内存上产生了临时变量保存了10，这个临时变量是可以进行取地址操作的，因此var引用的其实是这个临时变量，相当于下面的操作:

```c++
const int temp = 10;
const int &var = temp;
```


根据上述分析，得出如下结论:


左值引用要求右边的值必须能够取地址，如果无法取地址，可以用常引用；但使用常引用后，我们只能通过引用来读取数据，无法去修改数据，因为其被const修饰成常量引用了。


那么C++11引入了右值引用的概念，使用右值引用能够很好的解决这个问题.

**右值引用**

参考：https://www.jianshu.com/p/d19fc8447eaa/


C++对于左值和右值没有标准定义，但是有一个被广泛认同的说法：

可以取地址的，有名字的，非临时的就是左值；不能取地址的，没有名字的，临时的就是右值；可见立即数，函数返回的值等都是右值；而非匿名对象(包括变量)，函数返回的引用，const对象等都是左值。

从本质上理解，创建和销毁由编译器幕后控制，程序员只能确保在本行代码有效的，就是右值(包括立即数)；而用户创建的，通过作用域规则可知其生存期的，就是左值(包括函数返回的局部变量的引用以及const对象)。


定义右值引用的格式如下：

类型& &引用名=右值表达式;


右值引用是C++11新增的特性，所以C++98的引用为左值引用。右值引用用来绑定到右值，绑定到右值以后本来会被销毁的右值的生存期会延长至

与绑定到它的右值引用的生存期相同。
int & &var = 10;
在汇编层面右值引用做的事情和常引用是相同的，即产生临时量来存储常量。但是，唯一一点的区别是，右值引用可以进行读写操作，而常引用只能进行读操作。

move可以将左值转换成右值

```c++
	int &&a = 10;
	int	b = a;
	//int &&c = b;//报错无法将右值引用绑定到左值
	int &&c = std::move(b);
```



## 14 四种强制类型转换

##  1）static_cast

C语言所采用的类型转换方式：

```c
int a = 10;
int b = 3;
double result = (double)a / (double)b;
```

C++中采用static_cast：

```c++
int a = 10;
int b = 3;
double result = static_cast<double>(a) / static_cast<double>(b);
```

**用法：static_cast <类型说明符> （变量或表达式）**

**它主要有如下几种用法：**
  （1）用于类层次结构中基类和派生类之间指针或引用的转换
   进行上行转换（把派生类的指针或引用转换成基类表示）是安全的
   进行下行转换（把基类的指针或引用转换为派生类表示），由于没有动态类型检查，所以是不安全的
  （2）用于基本数据类型之间的转换，如把int转换成char。这种转换的安全也要开发人员来保证
  （3）把空指针转换成目标类型的空指针
  （4）把任何类型的表达式转换为void类型
  注意：static_cast不能转换掉expression的const、volitale或者__unaligned属性。

**static_cast:可以实现C++中内置基本数据类型之间的相互转换。**

如果涉及到类的话，static_cast只能在**有相互联系的类型中进行相互转换,**不一定包含虚函数。

更多例子：

```c++
char a = 'a';
int b = static_cast<char>(a);//正确，将char型数据转换成int型数据

double *c = new double;
void *d = static_cast<void*>(c);//正确，将double指针转换成void指针

int e = 10;
const int f = static_cast<const int>(e);//正确，将int型数据转换成const int型数据

const int g = 20;
int *h = static_cast<int*>(&g);//编译错误，static_cast不能转换掉g的const属性

//类上行和下行的转换
class Base
{};

class Derived : public Base
{}

Base* pB = new Base();
if(Derived* pD = static_cast<Derived*>(pB))
{}//下行转换是不安全的(坚决抵制这种方法)

Derived* pD = new Derived();
if(Base* pB = static_cast<Base*>(pD))
{}//上行转换是安全的

```



## 2) const_cast

在C语言中，const限定符通常被用来限定变量，用于表示该变量的值不能被修改。

**而const_cast则正是用于强制去掉这种不能被修改的常数特性，但需要特别注意的是const_cast不是用于去除变量的常量性，而是去除指向常数对象的指针或引用的常量性，其去除常量性的对象必须为指针或引用。**

一个错误的例子：

```c++
const int a = 10;
const int * p = &a;
*p = 20;                  //compile error
int b = const_cast<int>(a);  //compile error
```

**在本例中出现了两个编译错误，第一个编译错误是\*p因为具有常量性，其值是不能被修改的；另一处错误是const_cast强制转换对象必须为指针或引用，而例3中为一个变量，这是不允许的！**

正确的例子：

```c++

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	const int a = 10;

	const int * p = &a;//常量必须用指向常量的指针，否则编译报错

	int *q;
	q = const_cast<int *>(p);
	//*p = 22;//报错，指向常量的指针不可指向所指变量的值
	*q = 20;    //fine
	cout << a << " " << *p << " " << *q << endl;
	cout << &a << " " << p << " " << q << endl;
	return 0;

}
打印结果：
10 20 20
00B9FC5C 00B9FC5C 00B9FC5C
```

可以看出a的值不会被改变，这是一件好事！但p、q也确实是指向了a。这里我们称“*q=20”语句为未定义行为语句，所谓的未定义行为是指在标准的C++规范中并没有明确规定这种语句的具体行为，该语句的具体行为由编译器来自行决定如何处理。对于这种未定义行为的语句我们应该尽量予以避免！

再看个正经点的例子：

```c++
#include<iostream>
using namespace std;
 
const int * Search(const int * a, int n, int val);
 
int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int val = 5;
    int *p;
    p = const_cast<int *>(Search(a, 10, val));
    if(p == NULL)
        cout<<"Not found the val in array a"<<endl;
    else
        cout<<"hvae found the val in array a and the val = "<<*p<<endl;
    return 0;
}
 
const int * Search(const int * a, int n, int val)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(a[i] == val)
            return &a[i];
    }
    return  NULL;
}
```

我们定义了一个函数，用于在a数组中寻找val值，如果找到了就返回该值的地址，如果没有找到则返回NULL。函数Search返回值是const指针，当我们在a数组中找到了val值的时候，我们会返回val的地址，最关键的是a数组在main函数中并不是const，因此即使我们去掉返回值的常量性有可能会造成a数组被修改，但是这也依然是安全的。

类似的指针可以改为引用：

```c++
#include<iostream>
using namespace std;
 
const int & Search(const int * a, int n, int val);
 
int main()
{
int a[10] = {0,1,2,3,4,5,6,7,8,9};
int val = 5;
int &p = const_cast<int &>(Search(a, 10, val));
if(p == NULL)
cout<<"Not found the val in array a"<<endl;
else
cout<<"hvae found the val in array a and the val = "<<p<<endl;
return 0;
}
 
const int & Search(const int * a, int n, int val)
{
int i;
for(i=0; i<n; i++)
{
if(a[i] == val)
return a[i];
}
return NULL;
}
```



**了解了const_cast的使用场景后，可以知道使用const_cast通常是一种无奈之举，同时也建议大家在今后的C++程序设计过程中一定不要利用const_cast去掉指针或引用的常量性并且去修改原始变量的数值，这是一种非常不好的行为。**



## 3) reinterpret_cast

在C++语言中，reinterpret_cast主要有三种强制转换用途：***改变指针或引用的类型、将指针或引用转换为一个足够长度的整形、将整型转换为指针或引用类型***。

**用法：reinterpret_cast<type_id> (expression)**
  type-id必须是一个指针、引用、算术类型、函数指针或者成员指针。
  它可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针（先把一个指针转换成一个整数，在把该整数转换成原类型的指针，还可以得到原先的指针值）。
  **在使用reinterpret_cast强制转换过程仅仅只是比特位的拷贝，因此在使用过程中需要特别谨慎！**

例7：

```c++
#include <iostream>
#include <algorithm>
using namespace std;


int main(int argc, char **argv)
{
	double d = 12.1;
	char* p = reinterpret_cast<char*>(&d); // 将d以二进制（位模式）方式解释为char，并赋给*p 
	void *ptr = reinterpret_cast<void*>(p);
	double* q = reinterpret_cast<double*>(ptr);
	std::cout << *q; // 12.1 ，值不会变
	return 0;
}

```

c语言我们直接强制转：

```c
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	double d = 12.1;
	char* p = (char *)(&d); // 将d以二进制（位模式）方式解释为char，并赋给*p 
	void *ptr = (void *)(p);
	double* q = (double *)(ptr);
	std::cout << *q; // 12.1
	return 0;
}
```

## 4) dynamic_cast

**用法：dynamic_cast<type_id> (expression)**

**（1）其他三种都是编译时完成的，dynamic_cast是运行时处理的，运行时要进行类型检查。**

**（2）不能用于内置的基本数据类型的强制转换。**

**（3）dynamic_cast转换如果成功的话返回的是指向类的指针或引用，转换失败的话则会返回NULL。**

**（4）使用dynamic_cast进行转换的，基类中一定要有虚函数，否则编译不通过。**

​     **类中需要检测有虚函数的原因：类中存在虚函数，就说明它有想要让基类指针或引用指向派生类对象的情况，此时转换才有意义。**

​    **这是由于运行时类型检查需要运行时类型信息，而这个信息存储在类的虚函数表（关于[虚函数表](http://baike.baidu.com/view/3750123.htm)的概念，详细可见<Inside c++ object model>）中，**

​     **只有定义了虚函数的类才有虚函数表。**

 **（5）在类的转换时，在类层次间进行上行转换时，dynamic_cast和[static_cast](http://baike.baidu.com/view/1745207.htm)的效果是一样的。在进行下行转换时，dynamic_cast具有类型检查的功能，比static_cast更安全。**

​    **向上转换，即为子类指针指向父类指针（一般不会出问题）；向下转换，即将父类指针转化子类指针，子类除了继承父类的属性和方法还会有可能定义自己的属性和方法，因此向下转化时子类自己的方法和属性丢失。**

例子：

```c++
if(Derived *dp = dynamic_cast<Derived *>(bp)){
  //使用dp指向的Derived对象  
}
else{
  //使用bp指向的Base对象  
}
```

！！！**尽量少使用转型操作，尤其是dynamic_cast，耗时较高，会导致性能的下降，尽量使用其他方法替代。**

## 15 智能指针

shared_ptr可以自动管理堆上分别的内存，当某一块内存的引用计数为0后内存就会自动被释放，很智能，但会带来循环引用，多个指针指向同一块内存可能影响程序的阅读；auto_ptr无引用计数。

```c++
#include <iostream>
#include <memory>   //使用shared_ptr需要include它

#include <iostream>
#include <memory>   //使用shared_ptr需要include它

int main() {
	//通过make_shared创建shared_ptr
	std::shared_ptr<int> p1 = std::make_shared<int>();
	*p1 = 78;
	std::cout << "p1 = " << *p1 << std::endl;

	//查看引用计数
	std::cout << "p1 Reference count = " << p1.use_count() << std::endl;

	//第二个shared_ptr也将在内部指向相同的指针
	//这将会使引用计数变为2
	std::shared_ptr<int> p2(p1);

	//查看引用计数
	std::cout << "p2 Reference count = " << p2.use_count() << std::endl;
	std::cout << "p1 Reference count = " << p1.use_count() << std::endl;

	//比较智能指针
	
	std::cout << "000 p1 and p2 addr:" << static_cast<const void *> (p1.get()) <<"  and  "<< static_cast<const void *> (p2.get()) << std::endl;


	std::cout << "Reset p1" << std::endl;

	//重置shared_ptr，在这种情况下，其内部不会指向内部的任何指针
	//因此其引用计数将会变为0
	p1.reset();
	std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;
	std::cout << "p2 Reference Count = " << p2.use_count() << std::endl;
	std::cout << "111p1 and p2 addr:" << static_cast<const void *> (p1.get()) << "  and  " << static_cast<const void *> (p2.get()) << std::endl;
	//重置shared_ptr，在这种情况下，其内部将会指向一个新的指针
	//因此其引用计数将会变为1
	p1.reset(new int(11));
	std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;
	std::cout << "p2 Reference Count = " << p2.use_count() << std::endl;
	std::cout << "222 p1 and p2 addr:" << static_cast<const void *> (p1.get()) << "  and  " << static_cast<const void *> (p2.get()) << std::endl;
	//分配nullptr将取消关联指针并使其指向空值
	p1 = nullptr;
	std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;
	std::cout << "p2 Reference Count = " << p2.use_count() << std::endl;
	std::cout << "333 p1 and p2 addr:" << static_cast<const void *> (p1.get()) << "  and  " << static_cast<const void *> (p2.get()) << std::endl;
	if (!p1) {
		std::cout << "p1 is NULL" << std::endl;
	}
	getchar();
	return 0;
}

//程序输出结果：
p1 = 78
p1 Reference count = 1
p2 Reference count = 2
p1 Reference count = 2
000 p1 and p2 addr:000EC544  and  000EC544
Reset p1
p1 Reference Count = 0
p2 Reference Count = 1
111p1 and p2 addr:00000000  and  000EC544
p1 Reference Count = 1
p2 Reference Count = 1
222 p1 and p2 addr:000EC010  and  000EC544
p1 Reference Count = 0
p2 Reference Count = 1
333 p1 and p2 addr:00000000  and  000EC544
p1 is NULL
```

**auto_ptr用法示例：**
```c++
	auto sp = std::auto_ptr<int>(new int(55));
	std::auto_ptr<int> ptr(sp);
	//cout << *sp << endl;//fail,sp不再有效
	cout << *ptr << endl;//ok
```
**unique_ptr用法示例：**
```c++
 	auto sp = std::unique_ptr<int>(new int(55));
	std::unique_ptr<int> ptr(std::move(sp));
	//cout << *sp << endl;//fail,sp不再有效
	cout << *ptr << endl;//ok
```
unique_ptr无法进行传统的复制构造和拷贝构造

```c++
//比如:
    auto_ptr<int> ap(new int(88 );

    auto_ptr<int> one (ap) ; // ok

    auto_ptr<int> two = one; //ok

//但unique_ptr不支持上述操作

    unique_ptr<int> ap(new int(88 );

    unique_ptr<int> one (ap) ; // 会出错

    unique_ptr<int> two = one; //会出错

```

但unique_ptr可以进行移动构造和移动赋值操作
```c++
unique_ptr<int> GetVal( ){

unique_ptr<int> up(new int(88 );

return up;

}
```

实际上上面的的操作有点类似于如下操作
```c++
unique_ptr<int> up(new int(88 );

unique_ptr<int> uPtr2 = std:move( up) ; //这里是显式的所有权转移. 把up所指的内存转给uPtr2了,而up不再拥有该内存
```
**综上：**
unique_ptr和auto_ptr真的非常类似。其实你可以这样简单的理解，auto_ptr是可以说你随便赋值，但赋值完了之后原来的对象就不知不觉的报废。搞得你莫名其妙. 而unique_ptr就干脆不让你可以随便去复制, 赋值. 如果实在想传个值就哪里,显式的说明内存转移std:move一下. 然后这样传值完了之后, 之前的对象也同样报废了. 只不过整个move让你明显的知道这样操作后会导致之前的unique_ptr对象失效，更有利于代码的理解.

## 16 const成员函数/变量 static成员函数/变量

const 和non-const成员函数可以构成重载

static成员变量只能类内声明，类外定义，它属于类而不属于任何一个类对象，const成员函数可修改其值

## 17模板的代码只能写在头文件中，被include包含后才能在编译解决实例化

# 五、嵌入式基础知识总结

## 1 同步与异步，互斥

同步

同步就是A和B存在因果(依赖关系)，同步是有方向的，A的执行依赖于B执行的结果，则A相对于B是同步的，但B不一定依赖于A，比如和app调试PS转RTP功能时，APP写缓存时要判断缓存的空间够不够写入一个数据包的数据，若不够则等待，知道空间够了再写，但dsp读数据就一直读，只要writeIndex不等于readIndex就可以直接读。

为了同步A调用某接口后所在线程**可能**被挂起也即接口阻塞。

异步 

某个调用发出后，无论是否得到结果该调用直接返回。

互斥

是指散步在不同任务之间的若干程序片断，当某个任务运行其中一个程序片段时，其它任务就不能运行它们之中的任一程序片段，只能等到该任务运行完这个程序片段后才可以运行。最基本的场景就是：一个公共资源同一时刻只能被一个进程或线程使用，多个进程或线程不能同时使用公共资源。

## 2 并发、并行、串行

并发

当有多个线程在操作时,如果系统只有一个CPU,把CPU运行时间划分成若干个时间段,分配给各个线程执行，在一个时间段的线程代码运行时，其它线程处于挂起状态。这种方式我们称之为并发(Concurrent)。同时接收到多个任务，同时执行多个任务，但是具体到某个时刻~只是在执行一个任 务，只是在很短时间内在多个任务之间切换，模拟形成了多个任务同时执行的现象。并发=间隔发生

并行

当系统有一个以上CPU时,则线程的操作有可能非并发。当一个CPU执行一个线程时，另一个CPU可以执行另一个线程，两个线程互不抢占CPU资源，可以同时进行，这种方式我们称之为并行(Parallel)。 并行=同时进行

串行

就是传统意义上的同步、顺序的意思，按照一定的执行步骤顺序执行每个环节

## 3 互斥锁、信号量、条件变量

互斥锁用来保证某线程访问共享资源时不被其他线程影响。pthread_mutex_lock和pthread_mutex_unlock

条件变量pthread_cond_signal和pthread_cond_wait用来保证线程间正确的衔接关系。通常放在一对互斥锁中，注意pthread_cond_wait将线程放到等待队列后会同时解锁，保证了pthread_cond_signal所在线程可以拿到锁从而调用pthread_cond_signal发信号。

信号量代码中几乎没怎么用，两年没用已经没什么印象了。

## 4 死锁产生条件与调试方法

gdb a.out->卡主->ctrl +c杀掉进程->info thread查看所有的线程，大概观察下哪些是在等锁的--> thread <thread_id> 跳转到你怀疑的线程代码中并且会显示线程号 -->frame <thread_id>看是否能查到线程阻塞的位置，从而查看阻塞的锁名字，若看不到->where可以看到该A线程阻塞在代码中的位置及锁名字->p <锁名>可查看该A线程获取阻塞的锁的owner是谁，即目前被哪个thread_id的B线程占有-->再thread到占据锁的B线程，用同样的where方法查看B线程阻塞在哪个名字的锁上，从而p <锁名> 打印该锁名字查看其owner是谁，若刚好是A，则可断定是A和B死锁。

若不想杀掉程序可使用gdb attach <process_id> 然后info thread 紧接着用同样的方式调试。

## 5 段错误产生条件与调试方法

段错误直接bt查看崩溃前堆栈信息，从而大概定位到奔溃在那一区间的代码上，再一步步通过打印各个变量的值查看是那个变量使用或函数调用错误导致的崩溃。

若bt无堆栈信息，我遇到的情况程序多次重启后，系统直接崩掉，无堆栈信息；对比两次重启前free查看到的空余内存，即可查看是否有内存泄漏，若确认是内存泄漏，可以直接valgrind分析，也可通过svn找到最近一版本没有问题的程序然后和本地近期新增代码作对比，找到新增代码中哪里导致的程序泄漏，两个方法哪个快先用哪个。

## 6 内存越界产生条件与调试方法

内存越界，比如数组使用超了，或者字符串拷贝时超了等，或者是用来野指针等等。方法如果gdb不行就使用valgrind了

