#include <stdio.h>

void fun();

/**************************************************\
                静态局部变量

       1. 在代码块中定义, static int num
       2. 作用于最近的代码块中
       3. 生命周期是整个进程, 程序结束时才被释放
       4. 只会被初始化一次, 如果再次遇到初始化, 将会跳过
       5. 存放在全局区
       6. 若不初始化, 内容为 0
\***************************************************/

/**************************************************\
                静态全局变量

       1. 在代码块外定义, static int num
       2. 只在当前源文件使用, 不能在其他文件中使用
       3. 生命周期是整个进程, 程序结束时才被释放
       5. 存放在全局区
       6. 若不初始化, 内容为 0
\***************************************************/

extern void my_fun();
extern void my_static_fun();

extern int num;

extern int va;
extern int getG();
extern int getO();

int main(int argc, char *argv[]) {
    printf("va=%d\n", va);
    printf("getO=%d\n", getO());
    printf("getG=%d\n", getG());
    printf("%d\n", va * getG() * getO());

//    printf("num = %d\n", num); // 不识别其他源文件的静态全局变量
//    my_fun();
//    my_static_fun();
//    fun();
//    fun();
//    fun();
//    fun();
    return 0;
}

static int data = 10; // 静态全局变量

void fun() {
    // 静态局部变量只能被初始化一次, 当再一次遇到初始化语句时, 将会直接跳过
    // 静态局部变量在代码块执行完成后不会被释放, 不需要再次初始化初始化, 因此静态局部变量只会被初始化一次
    // 这条语句在第二次调用时, 不会被执行, 因为已经这个变量已经初始化, 已经开辟了内存空间
    static int num = 10;
    num++;

    printf("num = %d\n", num);
    printf("%p\n", &num);
    return;
}
