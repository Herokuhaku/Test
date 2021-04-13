#include <Dxlib.h>

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow) {

    ChangeWindowMode(TRUE);// Windowモードで起動
    SetMainWindowText("1916213_佐藤弘哲");//ウィンドウタイトルを変更
    SetGraphMode(640, 480, 16);// 画面解像度と色数の設定

    if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
    {
        return -1;    // エラーが起きたら直ちに終了
    }
    SetDrawScreen(DX_SCREEN_BACK);

    int x, y;
    x = 0; y = 100;
    while (ProcessMessage() == 0)
    {
        ClsDrawScreen();
        

        // 四角を描画と上下左右
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