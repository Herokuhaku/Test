#include <Dxlib.h>
#include <stdlib.h> // rand, srand�֐�
#include <time.h>   // time�֐�
#include <random>
#include "main.h"

void GACHA()
{
    ClsDrawScreen();

    DrawString(0, 100, "�v�Z��", 0xffffff);

    ScreenFlip();
    ClsDrawScreen();
    int count = 0;  // ��������
    int get = 0;    // �o����
    int getcount = 0; // �˔\�J��max�ɂȂ�����
    long long int allstone = 0;
    while (getcount <= _trials)
    {
        allstone += 150;
        int tmp = rand() % 200;
        if (0 == tmp)
        {
            get++;
            if (get == 6)
            {
                getcount++;
                count = 0;
                get = 0;
            }
        }

        if (count == 200)
        {
            get++;
            count = 0;
            if (get == 6)
            {
                getcount++;
                get = 0;
            }
        }
        count ++;
    }

    int all = allstone / _trials;
    // ���W���}�b�N�C�[�����o��m�� 0.500%
    // ��3���琯5�܂łɕK�v�ȃs�[�X 500
    // �s�b�N �A�b�v���Ɉ����Ƃ��炦��s�[�X 90
    // ���s��

    DrawFormatString(0, 0, 0xffffff, "�˔\�J��MAX�ɕK�v�Ȑ΂̐� ���� %d ��",all);
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
    std::uniform_int_distribution<int> shotrand(1, 200);

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