#include <Dxlib.h>
#include "main.h"
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


    while (ProcessMessage() == 0)
    {
        vec2 center(0,0);
        GetMousePoint(&center.x, &center.y);

        //vec2 center = { 400,400 };
        point.emplace_back(vec2(center.x, center.y - 200));
        point.emplace_back(vec2(center.x - 200, center.y + 200));
        point.emplace_back(vec2(center.x + 200, center.y + 200));

        ClsDrawScreen();

        //DrawLine(point[0].x, point[0].y, point[1].y, point[1].y, 0xffffff);

        for (int i = 0; i < point.size(); i++)
        {
            if (i + 1 < point.size())
            {
                DrawLine(point[i].x, point[i].y, point[i + 1].x, point[i + 1].y,0xffffff);
            }
            else
            {
                DrawLine(point[i].x, point[i].y, point[0].x, point[0].y, 0xffffff);
            }
        }
        if (CheckHitKey(KEY_INPUT_SPACE))
        {

        }
        ScreenFlip();
        point.clear();
    }

    return 0;
}