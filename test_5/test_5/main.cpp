#include <Dxlib.h>

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
    while (ProcessMessage() == 0)
    {
        ClsDrawScreen();
        

        // �l�p��`��Ə㉺���E
        {
            DrawBox(x, y, x + 100, y + 100, 0xffffff, true);
            if (CheckHitKey(KEY_INPUT_A))
            {
                x -= 5;
            }
            if (CheckHitKey(KEY_INPUT_W))
            {
                y -= 5;
            }
            if (CheckHitKey(KEY_INPUT_S))
            {
                y += 5;
            }
            if (CheckHitKey(KEY_INPUT_D))
            {
                x += 5;
            }
        }
        ScreenFlip();
    }

    return 0;
}