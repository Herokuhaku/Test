#include <Dxlib.h>
#include <stdlib.h> // rand, srand�֐�
#include <time.h>   // time�֐�
#include <random>
#include "main.h"

void GACHA()
{
    ClsDrawScreen();

    int count = 0;  // �o����
    int getcount = 0; // �˔\�J��max�ɂȂ�����        
    for (int i = 0;i < 100000;i++)
    {
        for (int c = 0;c < 10;c++)
        {
            int tmp = rand() % 1000;
            if (0 < tmp && tmp <= 5)
            {
                count++;
                getcount++;
            }
            if (count == 200)
            {
                getcount++;
                count = 0;
            }
        }
    }
    int m = getcount / 6;
    int d = 1000000 * 150;

    int all = d / m;
    // ���W���}�b�N�C�[�����o��m�� 0.500%
    // ��3���琯5�܂łɕK�v�ȃs�[�X 500
    // �s�b�N �A�b�v���Ɉ����Ƃ��炦��s�[�X 90
    // ���s��

    DrawFormatString(0, 0, 0xffffff, "�˔\�J��MAX�ɕK�v�Ȑ΂̐� %d ��", all);
    DrawString(0,100,"�X�y�[�X�ł�����x�v�Z������",0xffffff);
    ScreenFlip();
}

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow) {

    ChangeWindowMode(TRUE);// Window���[�h�ŋN��
    SetMainWindowText("1916213_�����O�N");//�E�B���h�E�^�C�g����ύX
    SetGraphMode(640, 480, 16);// ��ʉ𑜓x�ƐF���̐ݒ�

    if (DxLib_Init() == -1)    // �c�w���C�u��������������
    {
        return -1;    // �G���[���N�����璼���ɏI��
    }
    SetDrawScreen(DX_SCREEN_BACK);

    int x, y;
    x = 0; y = 100;
    int needget = _need / _get;
    if (_need % _get != 0)
    {
        needget++;
    }
    srand((unsigned int)time(0));


    std::mt19937 mt;
    std::uniform_int_distribution<int> shotrand(0, 1000);

    GACHA();
    while (ProcessMessage() == 0)
    {
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            GACHA();
        }
    }

    return 0;
}