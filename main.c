#include<stdio.h>
#include<stdlib.h>
#include "D:\\py38\\include\\python.h"
#pragma comment(lib, "D:\\py38\\libs\\python38.lib")
//���ڱ�����������include��lib·���������п���ת��Ϊ
//#include<Python.h>

void getCurrent()
{
    /*����ģ��ͳ�����ͬһ��Ŀ¼�£�ִ�и�Python��佫ģ��·���ӽ�����*/
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./Python')");
    return;
}

int runFalconAI()
{
    double Similarity = -0.066962;
    double PhaseAsymmetry = 0.749622;
    //Py_SetPythonHome(L"D:\\py38");//python������·��
    Py_Initialize();//��ʼ��python
    getCurrent();

    PyObject* pModule = NULL;
    PyObject* pFunc = NULL;
    PyObject* pyResult = NULL; //���ص��ý��

    /*����py*/
    pModule = PyImport_ImportModule("falconAI");       //����ģ��, ���õ�py�ļ�
    pFunc = PyObject_GetAttrString(pModule, "forward");//ֱ�ӻ�ȡģ���еĺ���

    /*���Σ�c->py*/
    PyObject* args = PyTuple_New(2);  //��ʼ��tuple�����������*2
    PyObject* args0 = Py_BuildValue("d", Similarity); //��������ת��������double����
    PyObject* args1 = Py_BuildValue("d", PhaseAsymmetry);


    PyTuple_SetItem(args, 0, args0);
    PyTuple_SetItem(args, 1, args1);
    pyResult = PyEval_CallObject(pFunc, args); //����ֱ�ӻ�õĺ����������ݲ���

    /*�������ؽ��*/
    int result = PyLong_AsLong(pyResult); // ����ֵת����long��

    Py_Finalize(); //�ͷ�python
    return result;
}

int main(int argc, char* argv[])
{
    printf("%d", runFalconAI());
    return 0;
}