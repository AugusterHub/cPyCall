#include<stdio.h>
#include<stdlib.h>
#include "D:\\py38\\include\\python.h"
#pragma comment(lib, "D:\\py38\\libs\\python38.lib")
//若在编译器设置了include和lib路径以上两行可以转化为
//#include<Python.h>

void getCurrent()
{
    /*对于模块和程序不在同一个目录下，执行该Python语句将模块路径加进程序*/
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./Python')");
    return;
}

int runFalconAI()
{
    double Similarity = -0.066962;
    double PhaseAsymmetry = 0.749622;
    //Py_SetPythonHome(L"D:\\py38");//python解释器路径
    Py_Initialize();//初始化python
    getCurrent();

    PyObject* pModule = NULL;
    PyObject* pFunc = NULL;
    PyObject* pyResult = NULL; //返回调用结果

    /*调用py*/
    pModule = PyImport_ImportModule("falconAI");       //引入模块, 调用的py文件
    pFunc = PyObject_GetAttrString(pModule, "forward");//直接获取模块中的函数

    /*传参，c->py*/
    PyObject* args = PyTuple_New(2);  //初始化tuple，待传入参数*2
    PyObject* args0 = Py_BuildValue("d", Similarity); //参数类型转换，传递double类型
    PyObject* args1 = Py_BuildValue("d", PhaseAsymmetry);


    PyTuple_SetItem(args, 0, args0);
    PyTuple_SetItem(args, 1, args1);
    pyResult = PyEval_CallObject(pFunc, args); //调用直接获得的函数，并传递参数

    /*解析返回结果*/
    int result = PyLong_AsLong(pyResult); // 返回值转换成long型

    Py_Finalize(); //释放python
    return result;
}

int main(int argc, char* argv[])
{
    printf("%d", runFalconAI());
    return 0;
}