//操作符重载、函数模版、

#include <iostream>

using namespace std;


class Complex{
private:
	double real;
	double imageinary;
	//静态变量为所有类的成员共享，只有一个
	//sizeof不计算静态成员变量
	static int count;
public:
	//静态成员函数类似于变量，静态函数中只能有静态变量，不能有其他变量
	//可以通过类名访问Complex::getCount()，也可以通过实例（指针、引用）访问c.getCount()
	static int getCount(){
		return count;
	}

	//带默认值的参数，必须从右往左依次有默认值，不能出现左边参数有默认值，而右边没有默认值的情况
	Complex(double r = 0.0, double i = 0.0){
		real = r;
		imageinary = i;
	}
	//赋值构造函数，函数尽量用常引用作为参数，减少构造实例时间
	Complex(const Complex &c){
		real = c.real;
		imageinary = c.imageinary;
	}
	//操作符重载为成员函数
	//如果需要改变参数时不加const，例如>>，否则就加上const
	//c+a相当于c.operator+(a)，a+c就必须调用a的成员函数
	//用引用作为返回值，可以进行诸如a=b=c之类的运算
	Complex & operator+ (const Complex &a){
		return Complex(real + a.real, imageinary + a.imageinary);
	}
	//为了访问类的私有成员，需要声明为友元函数
	friend Complex & operator+ (const Complex &a, const Complex &b);
	friend ostream & operator<< (ostream &os, const Complex &c);
	friend istream & operator>> (istream &is, Complex &c);
	//前置自加符，没有参数，普通函数时一个参数
	Complex & operator++ (){
		real++;
		return *this;
	}
	//后置自加符，比前置多一个参数，但是此参数没有意义
	Complex & operator++ (int k){
		//后置要先参与计算再加，因此返回的是修改前的数值
		Complex tmp(*this);
		real++;
		return tmp;
	}
	//友元函数和友元类
	//友元函数说明该函数不是类的成员函数（因此实现时前面不需要加类名），但可以访问类的私有成员
	//int类中可以创建Complex类实例，并访问Complex的私有成员
	friend class int;

	//构造类时的调用顺序：所有成员变量的构造函数（与类中的声明顺序有关，与参数列表中的顺序无关）、类的构造函数
	//构造时，基类的先于派生类
	//析构顺序与构造时相反
};

//操作符重载为普通函数
//是普通函数，但是是Complex类的友元函数，前面不加Complex::，但可以访问Complex类的私有成员
Complex & operator+ (const Complex &a, const Complex &b){
	return Complex(a.real + b.real, a.imageinary + b.imageinary);
}
ostream & operator<< (ostream &os, const Complex &c);{
	os << c.real << "+" << c.imageinary << "i";
	return os;
}
istream & operator>> (istream &is, Complex &c);{
	//根据输入的字符串给c赋值就行，分割字符串is，实部赋值给c.real，虚部赋值给c.imaginery，此处省略
	return is;
}

void exampleOfTemplate(){
	//模版声明必须紧跟着模版函数
	//引用作为参数能够改变需要交换的参数值
	//函数寻找的过程为：参数匹配的普通函数、参数匹配的模版函数、参数自动转换后匹配的普通函数
	template <class T>
	void Swap(T &x, T &y){
		T tmp = x;
		x = y;
		y = tmp;
	}
	//模版函数也可以重载
	template <class T1, class T2>
	void Swap(T1 &x, T2 &y){
		//交换两个不同类型的变量，省略实现
	}

	//模版类
	//T1，T2在整个类的定义范围内有效，如果成员函数在类外部实现，则需要在函数实现前加模版声明
	template <class T1, class T2>
	class Pair{
	public:
		T1 key;
		T2 value;
	};
	//string也是一个模版类
}

void exampleOfBitOperation(){
	int n = 0;
	//&：用于将特定位清0，亦可写做&＝，例如低8位清0，int型为32位
	n = n & 0xffffff00;
	//&：判断第n位是否为0，判断例如右起低7位
	if (n & 0x80 == 0x80){ cout<<"1"; }
	//|：用于将特定位置1，例如低8位置1
	n |= 0xff;
	//~：全部取反
	n = ~n;
	//^：用于将特定为取反，例如低8位取反
	n ^= 0xff;
	//不使用临时变量，交换两个变量的方法
	int a = 5, b = 7;
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
	//第二种，加法会溢出，使用异或不会溢出
	a = a + b;
	b = a - b;
	a = a - b;
	//<<左移1位即为乘以2，>>右移1位代表除以2，也可以缩写<<=，>>=
	n = n << 1;
	n >>= 1;
	//得到a的第n位
	(a >> n) & 1;
	(a & (1 << n)) >> n;
}

void exampleOfReferenceAndPointer(){
	int a = 1, b = 2;
	//引用必须初始化，且初始化后不能再引用其他变量
	int & r1 = a;
	//r2和r1引用同一个变量，变量改变会同时改变r1和r2的值
	int & r2 = r1;
	//对引用进行操作只会改变变量的值，不会使得r1引用b
	r1 = b;

	//const后面是谁，谁的值就不能改变
	//指针p的值不能改变，不能p++
	int * const p1 = &a;
	//指针p指向的值不能改变，不能改变*p（不能通过p改变a的值），但可以直接改变a的值
	const int *p = &a;
	//p和p指向的值都不能改变
	const int * const p ＝ &a;

	//函数指针，参数为int*，返回值为int
	int (*func)(int *p);
	//函数指针，参数为int*和函数指针，返回值为int
	int (*func)(int *p, int (*f)(int*));
	//func是长度为5的数组，元素均为int (*func)(int *p)形式的函数指针
	int (*func[5])(int *p);
	//func是一个指针，指向长度为5的数组，元素均为int (*func)(int *p)形式的函数指针
	int (*(*func)[5])(int *p);
	//func是一个函数指针，返回值是一个指向长度为5的数组的指针
	int (*(*func)(int *p))[5];

	//传引用和传指针的区别：
	//引用必须初始化不能为空，指针可以为NULL
	//引用不能改变引用对象，指针可以改变指向对象
	//指针可能会变成空指针，甚至是野指针（指向的对象被销毁）
	//千万不要在函数中返回局部变量的指针和引用
	//动态分配的对象好像不能引用？即可能导致引用错误的对象都不能引用？
}

void exampleOfDynamicMemoryAllocation(){
	//new一个大小为sizeof(int)的内存空间，并把地址赋值给p1
	int *p1 = new int;
	*p1 = 4;
	//分配一个数组，大小可以为表达式
	int *p2 = new int[(*p1) * 5];
	//new出的内存空间必须使用delete删除，且只能删除一次，删除数组加[]
	delete p1;
	delete []p2;

	//c中的动态内存分配方法
	//void * malloc (size_t nbytes); 要转换类型，自己规定大小，int使用 5 * sizeof(int)
	char * myStr = (char *) malloc (10);
	//calloc把大小参数分为2个
	int * myInt = (int *) calloc (5, sizeof(int));
	//void * realloc (void * pointer, size_t size); 用于重新调整分配内存的大小
	//在当前连续空间不足的情况下，需要新开辟一片空间，此时指针的地址可能会改变，因此需要返回指针的地址
	//如果新空间仍不能满足，就不做任何操作
	int * myInt = (int *) realloc (myInt, sizeof(int) * 100);
	//用free释放分配内存
	free(*myInt);
	free(*myStr);

	//动态分配的内存在堆heap，其他的在栈stack
	//只能在stack的类：重载new和delete操作符，并设为private
	//只能在heap的类：将构造函数和析构函数设为private
}

//继承方式：public，private，protected，virtual
//public继承，所有成员保持原样
//private继承，父类的public和protected作为子类的private（基类仍可以访问）
//protected继承，父类的public和protected作为子类的protected（基类仍可以访问）
//virtual继承，为了解决基类的方法在多重继承中出现二义性的问题(?)


class CBug{
private:
	int a;
public:
	int b;
	CBug(int a, int b){
		this->a = a;
		this->b = b;
	}
};
class FlyBug: public CBug{
private:
	int a;
public:
	//子类调用父类的构造函数
	FlyBug(int a, int b, int a2): CBug(a, b){
		this->a = a2;
	}
	void hello(){
		//同名成员，调用时使用 类名::成员
		cout << a << CBug::a << endl;
	}
};

//复合关系中，避免循环定义，采用指针
class CMaster;
class CDog{
	CMaster *master;
};
class CMaster{
	CDog *dogs[10]
};

//虚函数和多态
//基类的指针/引用可以指向派生类，调用同名函数时调用所指向的类的虚函数
//作用：能够增强程序的可扩展性，减少改动功能时所需的代码量
class CCreature{
protected:
	int life;
	int power;
public:
	//只需在声明时使用virtual，实现时不需要加
	virtual void Attack(CCreature *pCreature){}
	virtual void Hurted(int power){}
	virtual void FightBack(CCreature *pCreature){}
};
//如果新增加一个类似的类，不需要改变其他类的内容
class CDragon : public CCreature{
public:
	//攻击时只需要使用基类来代表各个派生类，而不需要将每一个都列出来
	virtual void Attack(CCreature * pCreature){
		pCreature->Hurted(power);
		pCreature->FightBack(this);
	}
	virtual void Hurted(int nPower){}
	virtual void FightBack(CCreature * pCreature){}
};

//虚函数相关的其他内容：
//析构函数可以为虚（可以通过基类指针删除派生类的对象），构造函数不能为虚
//纯虚函数：virtual void Print() = 0;
//包含纯虚函数的类是抽象类（可以理解为现实中不存在的类），不能实例化
//抽象类的派生类必须实现基类的纯虚函数，才能实例化



//struct、union、class所占的空间(?)
//对齐准则，跟最长的类型对齐。#pragma pack (n) 可以指定对齐大小
//所占字节数：char-1, short-2, int-4, long-4/8, double-8（有说法是以4对齐大小为8）, *-4/8
//联合体共用内存，取最长的，结构体和类都是相加，嵌套的结构遵循自身的对齐方式
//长度最小为1，防止空类实例和下面的实例共用一个地址

//不清楚时套用规则：
//1.结构体变量的首地址是其最长基本类型成员的整数倍
//2.每个成员相对于结构体首地址的偏移量（offset）都是成员大小的整数倍
//3.结构体的总大小为结构体最宽基本类型成员大小的整数倍
//4.类型相同的连续元素将在连续的空间内，和数组一样
//求offset的方法：
#define OFFSET(struct,member)  ((char *)&((struct *)0)->member - (char *)0)
union uu{		//size = 4
	int i;		//####
	char c;		//#...
};

struct ss{		//size = 32
	short s;	//##
	char a[9];	//..######	数组连续，找准开始位置
				//###.
	int i;		//    ####
	char *c 	//########	64位linux下*占8位	
	long l;		//########	64位linux下long占8位
};
struct s1{
	char c;
	int i;
};
struct s2{		//size = 32
	short s;	//##..
	int i;		//    ####
	char a;		//#...
	s1 ss;		//    #...	结构体开始地址必须为自身对齐宽度的整数倍
				//####....
	long l;		//########	64位linux下long占8位
};
//类里，成员函数不影响大小，静态变量也不影响大小
//继承时，父类元素在子类之前，都要计算大小
//每一个虚继承会多一个指针？

//虚函数的影响：
//所有虚函数都放在虚函数表中，因此一个虚函数表有一个sizeof(*)大小的指针
//自身类的多个虚函数和第一父类的虚函数都在一个表内，之后每多一个父类就会多一个虚函数表
//虚函数表放在类的开头




//argc至少为1，argv[0]为程序名，后面是参数列表
int main(int argc, char * argv[]){
	

	return 0;
}


