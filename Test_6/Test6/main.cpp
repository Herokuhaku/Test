#include <Dxlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "main.h"

void Hanoi(int n,char from,char work,char dest)
{
    if (n >= 2) Hanoi(n - 1, from, dest, work);
    std::string str;
    str += std::to_string(n);
    str += "��";
    str += from;
    str += "����";
    str += work;
    str += "��";
    all.emplace_back(str);

    if (n >= 2) Hanoi(n - 1, work, from, dest);
}


int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow) {

    ChangeWindowMode(TRUE);// Window���[�h�ŋN��
    SetMainWindowText("1916213_�����O�N");//�E�B���h�E�^�C�g����ύX
    SetGraphMode(800, 800, 16);// ��ʉ𑜓x�ƐF���̐ݒ�

    if (DxLib_Init() == -1)    // �c�w���C�u��������������
    {
        return -1;    // �G���[���N�����璼���ɏI��
    }
    SetDrawScreen(DX_SCREEN_BACK);

    Hanoi(4, 'A', 'B', 'C');

    while (ProcessMessage() == 0)
    {
        int mouse = GetMouseInput();
        trg.two = trg.one;
        trg.one = mouse & MOUSE_INPUT_LEFT;

        ClsDrawScreen();

        if (count < all.size() && trg.one && !trg.two)
        {
            count++;
        }
        for (int i = 0; i < count && i < all.size(); i++) {
            DrawFormatString(0, i * 16, 0xffffff, "%s", all[i].c_str());
        }
        if (count >= all.size())
        {
            DrawString(0,(count+1)*16,"�I��",0xffffff);
        }
        ScreenFlip();
    }
    return 0;
}